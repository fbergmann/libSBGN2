/**
 * @file SbgnWriter.cpp
 * @brief Implementation of the SbgnWriter class.
 * @author DEVISER
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML. Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2019 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 * 3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 * Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 * 1. California Institute of Technology, Pasadena, CA, USA
 * 2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation. A copy of the license agreement is provided in the
 * file named "LICENSE.txt" included with this software distribution and also
 * available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 */


#include <ios>
#include <iostream>
#include <fstream>
#include <sstream>

#include <sbgn/common/common.h>
#include <sbml/xml/XMLOutputStream.h>

#include <sbgn/SbgnError.h>
#include <sbgn/SbgnErrorLog.h>
#include <sbgn/SbgnDocument.h>
#include <sbgn/SbgnWriter.h>

#include <sbml/compress/CompressCommon.h>
#include <sbml/compress/OutputCompressor.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/*
 * Creates a new SbgnWriter.
 */
SbgnWriter::SbgnWriter ()
{
}


/*
 * Destroys this SbgnWriter.
 */
SbgnWriter::~SbgnWriter ()
{
}


/*
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * SbgnDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbgn version <libsbgn version>. -->
 */
int
SbgnWriter::setProgramName (const std::string& name)
{
  mProgramName = name;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SbgnDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libsbgn version <libsbgn version>. -->
 */
int
SbgnWriter::setProgramVersion (const std::string& version)
{
  mProgramVersion = version;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Writes the given SbgnDocument to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 *
 * @note To create a gzip/zip file, underlying libSBGN needs to be linked with zlib at 
 * compile time. Also, underlying libSBGN needs to be linked with bzip2 to create a 
 * bzip2 file.
 * File unwritable error will be logged and @c false will be returned if a compressed 
 * file name is given and underlying libSBGN is not linked with the corresponding 
 * required library.
 * SbgnWriter::hasZlib() and SbgnWriter::hasBzip2() can be used to check whether
 * underlying libSBGN is linked with the library.
 *
 * @return true on success and false if the filename could not be opened
 * for writing.
 */
bool
SbgnWriter::writeSBGN (const SbgnDocument* d, const std::string& filename)
{
  std::ostream* stream = NULL;

  try
  {
    // open an uncompressed XML file.
    if ( string::npos != filename.find(".xml", filename.length() - 4) )
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
    // open a gzip file
    else if ( string::npos != filename.find(".gz", filename.length() - 3) )
    {
     stream = OutputCompressor::openGzipOStream(filename);
    }
    // open a bz2 file
    else if ( string::npos != filename.find(".bz2", filename.length() - 4) )
    {
      stream = OutputCompressor::openBzip2OStream(filename);
    }
    // open a zip file
    else if ( string::npos != filename.find(".zip", filename.length() - 4) )
    {
      std::string filenameinzip = filename.substr(0, filename.length() - 4);
  
      if ( ( string::npos == filenameinzip.find(".xml",  filenameinzip.length() - 4) ) &&
           ( string::npos == filenameinzip.find(".sbgn", filenameinzip.length() - 5) )
         )
      {
        filenameinzip += ".xml";
      }


#if defined(WIN32) && !defined(CYGWIN)
      char sepr = '\\';
#else
      char sepr = '/';
#endif
      size_t spos = filenameinzip.rfind(sepr, filenameinzip.length() - 1);
      if( spos != string::npos )
      {
        filenameinzip = filenameinzip.substr(spos + 1, filenameinzip.length() - 1);
      }

      
      stream = OutputCompressor::openZipOStream(filename, filenameinzip);
    }
    else
    {
      stream = new(std::nothrow) std::ofstream(filename.c_str());
    }
  }
  catch ( ZlibNotLinked& )
  {
    // libSBGN is not linked with zlib.
    XMLErrorLog *log = (const_cast<SbgnDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a gzip/zip file is not enabled because "
        << "underlying libSBGN is not linked with zlib."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 
  catch ( Bzip2NotLinked& )
  {
    // libSBGN is not linked with bzip2.
    XMLErrorLog *log = (const_cast<SbgnDocument *>(d))->getErrorLog();
    std::ostringstream oss;
    oss << "Tried to write " << filename << ". Writing a bzip2 file is not enabled because "
        << "underlying libSBGN is not linked with bzip2."; 
    log->add(XMLError( XMLFileUnwritable, oss.str(), 0, 0) );
    return false;
  } 


  if ( stream == NULL || stream->fail() || stream->bad())
  {
    SbgnErrorLog *log = (const_cast<SbgnDocument *>(d))->getErrorLog();
    log->logError(XMLFileUnwritable);
    delete stream;
    return false;
  }

   bool result = writeSBGN(d, *stream);
   delete stream;

   return result;

}


/*
 * Writes the given SbgnDocument to the output stream.
 *
 * @return true on success and false if one of the underlying parser
 * components fail (rare).
 */
bool
SbgnWriter::writeSBGN (const SbgnDocument* d, std::ostream& stream)
{
  bool result = false;

  try
  {
    stream.exceptions(ios_base::badbit | ios_base::failbit | ios_base::eofbit);
    XMLOutputStream xos(stream, "UTF-8", true, mProgramName, 
                                               mProgramVersion);
    d->write(xos);
    stream << endl;

    result = true;
  }
  catch (ios_base::failure&)
  {
    SbgnErrorLog *log = (const_cast<SbgnDocument *>(d))->getErrorLog();
    log->logError(XMLFileOperationError);
  }

  return result;
}


/** @cond doxygenLibsbgnInternal */
/*
 * Writes the given SbgnDocument to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and 0 if one of the underlying parser
 * components fail (rare).
 */
LIBSBGN_EXTERN
char*
SbgnWriter::writeToString (const SbgnDocument* d)
{
  ostringstream stream;
  writeSBGN(d, stream);

  return safe_strdup( stream.str().c_str() );
}

std::string 
SbgnWriter::writeSBGNToStdString(const SbgnDocument* d)
{
  if (d == NULL) return "";
  
  ostringstream stream;
  writeSBGN(d, stream);
  return stream.str();
}

LIBSBGN_EXTERN
char*
SbgnWriter::writeSBGNToString (const SbgnDocument* d)
{
  return writeToString(d);
}
/** @endcond */


LIBSBGN_EXTERN
bool
SbgnWriter::writeSBGNToFile (const SbgnDocument* d, const std::string& filename)
{
  return writeSBGN(d, filename);
}


/*
 * Predicate returning @c true if
 * underlying libSBGN is linked with zlib.
 *
 * @return @c true if libSBGN is linked with zlib, @c false otherwise.
 */
bool 
SbgnWriter::hasZlib() 
{
  return LIBSBGN_CPP_NAMESPACE ::hasZlib();
}


/*
 * Predicate returning @c true if
 * underlying libSBGN is linked with bzip2.
 *
 * @return @c true if libSBGN is linked with bzip2, @c false otherwise.
 */
bool 
SbgnWriter::hasBzip2() 
{
  return LIBSBGN_CPP_NAMESPACE ::hasBzip2();
}


#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBSBGN_EXTERN
SbgnWriter_t *
SbgnWriter_create ()
{
  return new(nothrow) SbgnWriter;
}


LIBSBGN_EXTERN
void
SbgnWriter_free (SbgnWriter_t *sw)
{
  delete sw;
}


LIBSBGN_EXTERN
int
SbgnWriter_setProgramName (SbgnWriter_t *sw, const char *name)
{
  if (sw != NULL)
    return (name == NULL) ? sw->setProgramName("") : sw->setProgramName(name);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnWriter_setProgramVersion (SbgnWriter_t *sw, const char *version)
{
  if (sw != NULL)
    return (version == NULL) ? sw->setProgramVersion("") :
                             sw->setProgramVersion(version);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnWriter_writeSBGN ( SbgnWriter_t         *sw,
                       const SbgnDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeSBGN(d, filename) ) : 0;
}


LIBSBGN_EXTERN
int
SbgnWriter_writeSBGNToFile ( SbgnWriter_t         *sw,
                       const SbgnDocument_t *d,
                       const char           *filename )
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return (filename != NULL) ? 
      static_cast<int>( sw->writeSBGN(d, filename) ) : 0;
}


LIBSBGN_EXTERN
char *
SbgnWriter_writeSBGNToString (SbgnWriter_t *sw, const SbgnDocument_t *d)
{
  if (sw == NULL || d == NULL) 
    return 0;
  else
    return sw->writeToString(d);
}


LIBSBGN_EXTERN
int
SbgnWriter_hasZlib ()
{
  return static_cast<int>( SbgnWriter::hasZlib() );
}


LIBSBGN_EXTERN
int
SbgnWriter_hasBzip2 ()
{
   return static_cast<int>( SbgnWriter::hasBzip2() );
}


LIBSBGN_EXTERN
int
writeSBGN (const SbgnDocument_t *d, const char *filename)
{
  SbgnWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeSBGN(d, filename) );
}


LIBSBGN_EXTERN
int
writeSBGNToFile (const SbgnDocument_t *d, const char *filename)
{
  SbgnWriter sw;
  if (d == NULL || filename == NULL)
    return 0;
  else
    return static_cast<int>( sw.writeSBGN(d, filename) );
}


LIBSBGN_EXTERN
char *
writeSBGNToString (const SbgnDocument_t *d)
{
  SbgnWriter sw;
  if (d == NULL)
    return NULL;
  else
    return sw.writeToString(d);
}

LIBSBGN_EXTERN
std::string writeSBGNToStdString(const SbgnDocument* d)
{
  SbgnWriter sw;
  if (d == NULL)
    return "";
  else
    return sw.writeSBGNToStdString(d);
}
/** @endcond */

LIBSBGN_CPP_NAMESPACE_END


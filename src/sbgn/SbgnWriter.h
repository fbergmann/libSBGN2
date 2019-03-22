/**
 * @file SbgnWriter.h
 * @brief Definition of the SbgnWriter class.
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
 *
 * @class SbgnWriter
 * @sbmlbrief{} TODO:Definition of the SbgnWriter class.
 */


#ifndef SbgnWriter_h
#define SbgnWriter_h


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <iosfwd>
#include <string>

LIBSBGN_CPP_NAMESPACE_BEGIN

class SbgnDocument;


class LIBSBGN_EXTERN SbgnWriter
{
public:

  /**
   * Creates a new SbgnWriter.
   *
   * The libSBGN SbgnWriter objects offer methods for writing SBGN in
   * XML form to files and text strings.
   */
  SbgnWriter  ();


  /**
   * Destroys this SbgnWriter.
   */
  ~SbgnWriter ();


  /**
   * Sets the name of this program, i.e., the program that is about to
   * write out the SbgnDocument.
   *
   * If the program name and version are set (see
   * SbgnWriter::setProgramVersion(@if java String@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the XML document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSBGN version <libsbgn version>. -->
 @endverbatim
   *
   * If the program name and version are not set at some point before
   * calling the writeSBGN() methods, no such comment is written out.
   *
   * @param name the name of this program (where "this program" refers to
   * program in which libSBGN is embedded, not libSBGN itself!)
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * 
   * @see setProgramVersion(const std::string& version)
   */
  int setProgramName (const std::string& name);


  /**
   * Sets the version of this program, i.e., the program that is about to
   * write out the SbgnDocument.
   *
   * If the program version and name are set (see
   * SbgnWriter::setProgramName(@if java String@endif)), the
   * following XML comment, intended for human consumption, will be written
   * at the beginning of the document:
   * @verbatim
 <!-- Created by <program name> version <program version>
 on yyyy-MM-dd HH:mm with libSBGN version <libsbgn version>. -->
 @endverbatim
   *
   * If the program version and name are not set at some point before
   * calling the writeSBGN() methods, no such comment is written out.
   *
   * @param version the version of this program (where "this program"
   * refers to program in which libSBGN is embedded, not libSBGN itself!)
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @see setProgramName(const std::string& name)
   */
  int setProgramVersion (const std::string& version);


  /**
   * Writes the given SbgnDocument to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the SbgnDocument to be written
   *
   * @param filename the name or full pathname of the file where the SBGN
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSBGN (const SbgnDocument* d, const std::string& filename);


  /**
   * Writes the given SbgnDocument to the output stream.
   *
   * @param d the SbgnDocument to be written
   *
   * @param stream the stream object where the SBGN is to be written.
   *
   * @return @c true on success and @c false if one of the underlying
   * parser components fail (rare).
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSBGN (const SbgnDocument* d, std::ostream& stream);


  /** @cond doxygenLibsbgnInternal */

  /**
   * Writes the given SbgnDocument to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the SbgnDocument to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeToString (const SbgnDocument* d);

  /** @endcond */

  /**
   * Writes the given SbgnDocument to filename.
   *
   * @htmlinclude assuming-compressed-file.html
   *
   * @param d the SbgnDocument to be written
   *
   * @param filename the name or full pathname of the file where the SBGN
   * is to be written. 
   *
   * @return @c true on success and @c false if the filename could not be
   * opened for writing.
   *
   * @note @htmlinclude note-writing-zipped-files.html
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  bool writeSBGNToFile (const SbgnDocument* d, const std::string& filename);


  /**
   * Writes the given SbgnDocument to an in-memory string and returns a
   * pointer to it.
   *
   * The string is owned by the caller and should be freed (with @c free())
   * when no longer needed.
   *
   * @param d the SbgnDocument to be written
   *
   * @return the string on success and @c 0 if one of the underlying parser
   * components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  char* writeSBGNToString (const SbgnDocument* d);

#ifndef SWIG
  /**
   * Writes the given SbgnDocument to an in-memory string and returns it.
   *
   * @param d the SbgnDocument to be written
   *
   * @return the string on success or an empty string, 
   *         if one of the underlying parser
   *         components fail.
   * 
   * @see setProgramVersion(const std::string& version)
   * @see setProgramName(const std::string& name)
   */
  std::string writeSBGNToStdString(const SbgnDocument* d);
#endif
  

  /**
   * Predicate returning @c true if this copy of libSBGN has been linked
   * with the <em>zlib</em> library.
   *
   * LibSBGN supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSBGN having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSBGN it is using.
   *
   * @return @c true if libSBGN is linked with zlib, @c false otherwise.
   *
   * @copydetails doc_note_static_methods
   *
   * @see @if clike hasBzip2() @else SbgnWriter::hasBzip2() @endif@~
   */
  static bool hasZlib();


  /**
   * Predicate returning @c true if this copy of libSBGN has been linked
   * with the <em>bzip2</em> library.
   *
   * LibSBGN supports reading and writing files compressed with either
   * bzip2 or zip/gzip compression.  The facility depends on libSBGN having
   * been compiled with the necessary support libraries.  This method
   * allows a calling program to inquire whether that is the case for the
   * copy of libSBGN it is using.
   *
   * @return @c true if libSBGN is linked with bzip2, @c false otherwise.
   *
   * @copydetails doc_note_static_methods
   *
   * @see @if clike hasZlib() @else SbgnWriter::hasZlib() @endif@~
   */
  static bool hasBzip2();


 protected:
  /** @cond doxygenLibsbgnInternal */
  std::string mProgramName;
  std::string mProgramVersion;

  /** @endcond */
};

#ifndef SWIG

/**
 * Writes the given SbgnDocument to an in-memory string that is returned.
 *
 * @param d the SbgnDocument to be written
 *
 * @return the string on success or an empty string, 
 *         if one of the underlying parser
 *         components fail.
 * 
 */
LIBSBGN_EXTERN
std::string writeSBGNToStdString(const SbgnDocument* d);

#endif

LIBSBGN_CPP_NAMESPACE_END

#endif  /* __cplusplus */


LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SbgnWriter and returns a pointer to it.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
SbgnWriter_t *
SbgnWriter_create (void);

/**
 * Frees the given SbgnWriter.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
void
SbgnWriter_free (SbgnWriter_t *sw);

/**
 * Sets the name of this program. i.\ e.\ the one about to write out the
 * SbgnDocument.  If the program name and version are set
 * (setProgramVersion()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSBGN version <libsbgn version>. -->
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_setProgramName (SbgnWriter_t *sw, const char *name);

/**
 * Sets the version of this program. i.\ e.\ the one about to write out the
 * SbgnDocument.  If the program version and name are set
 * (setProgramName()), the following XML comment, intended for human
 * consumption, will be written at the beginning of the document:
 *
 *   <!-- Created by <program name> version <program version>
 *   on yyyy-MM-dd HH:mm with libSBGN version <libsbgn version>. -->
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_setProgramVersion (SbgnWriter_t *sw, const char *version);

/**
 * Writes the given SbgnDocument to filename.
 *
 * @htmlinclude assuming-compressed-file.html
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 * If the filename ends with @em .zip, a filename that will be added to the
 * zip archive file will end with @em .xml or @em .sbgn. For example, the filename
 * in the zip archive will be @em test.xml if the given filename is @em test.xml.zip
 * or @em test.zip. Also, the filename in the archive will be @em test.sbgn if the
 * given filename is @em test.sbgn.zip.
 *
 * @note To write a gzip/zip file, libSBGN needs to be configured and
 * linked with the <a target="_blank" href="http://www.zlib.net/">zlib</a> library at
 * compile time.  It also needs to be linked with the <a target="_blank"
 * href="">bzip2</a> library to write files in @em bzip2 format.  (Both
 * of these are the default configurations for libSBGN.)  Errors about
 * unreadable files will be logged and this method will return @c false
 * if a compressed filename is given and libSBGN was @em not linked with
 * the corresponding required library.
 *
 * @note SbgnWriter_hasZlib() and SbgnWriter_hasBzip2() can be used to
 * check whether libSBGN has been linked with each library.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_writeSBGN ( SbgnWriter_t         *sw,
                       const SbgnDocument_t *d,
                       const char           *filename );

/**
 * Writes the given SbgnDocument to filename.
 *
 * If the filename ends with @em .gz, the file will be compressed by @em gzip.
 * Similary, if the filename ends with @em .zip or @em .bz2, the file will be
 * compressed by @em zip or @em bzip2, respectively. Otherwise, the fill will be
 * uncompressed.
 *
 * @note To create a gzip/zip file, libSBGN needs to be linked with zlib at 
 * compile time. Also, libSBGN needs to be linked with bzip2 to create a bzip2 file.
 * File unwritable error will be logged and @c zero will be returned if a compressed 
 * file name is given and libSBGN is not linked with the required library.
 * SbgnWriter_hasZlib() and SbgnWriter_hasBzip2() can be used to check whether
 * libSBGN was linked with the library at compile time.
 *
 * @return non-zero on success and zero if the filename could not be opened
 * for writing.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_writeSBGNToFile ( SbgnWriter_t         *sw,
                       const SbgnDocument_t *d,
                       const char           *filename );


/**
 * Writes the given SbgnDocument to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail (rare).
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
char *
SbgnWriter_writeSBGNToString (SbgnWriter_t *sw, const SbgnDocument_t *d);


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSBGN is linked with zlib at compile time.
 *
 * @return @c non-zero if zlib is linked, @c zero otherwise.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_hasZlib ();


/**
 * Predicate returning @c non-zero or @c zero depending on whether
 * libSBGN is linked with bzip2 at compile time.
 *
 * @return @c non-zero if bzip2 is linked, @c zero otherwise.
 *
 * @memberof SbgnWriter_t
 */
LIBSBGN_EXTERN
int
SbgnWriter_hasBzip2 ();

#endif  /* !SWIG */


/**
 * Writes the given SbgnDocument @p d to the file named by @p filename.
 * This convenience function is functionally equivalent to:
 *
 *   SbgnWriter_writeSBGN(SbgnWriter_create(), d, filename);
 *
 * @htmlinclude assuming-compressed-file.html
 *
 * @param d the SbgnDocument object to be written out in XML format
 * 
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed SBGN
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSBGN.
 *
 * @see SbgnWriter::hasZlib()
 * @see SbgnWriter::hasBzip2()
 *
 * @if conly
 * @memberof SbgnWriter_t
 * @endif
 */
LIBSBGN_EXTERN
int
writeSBGN (const SbgnDocument_t *d, const char *filename);


/**
 * Writes the given SbgnDocument @p d to an in-memory string and returns a
 * pointer to it.  The string is owned by the caller and should be freed
 * (with free()) when no longer needed.  This convenience function is
 * functionally equivalent to:
 *
 *   SbgnWriter_writeSBGNToString(SbgnWriter_create(), d);
 *
 * but does not require the caller to create an SbgnWriter object first.
 *
 * @param d an SbgnDocument object to be written out in XML format
 *
 * @return the string on success and @c NULL if one of the underlying parser
 * components fail.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed after it is no longer needed.@endif@~
 *
 * @if conly
 * @memberof SbgnWriter_t
 * @endif
 */
LIBSBGN_EXTERN
char *
writeSBGNToString (const SbgnDocument_t *d);


/**
 * Writes the given SbgnDocument @p d to the file @p filename.
 * This convenience function is functionally equivalent to:
 *
 *   SbgnWriter_writeSBGNToFile(SbgnWriter_create(), d, filename);
 *
 * but that does not require the caller to create an SbgnWriter object first.
 *
 * @htmlinclude assuming-compressed-file.html
 * 
 * @param d an SbgnDocument object to be written out in XML format
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be written.
 *
 * @return @c 1 on success and @c 0 (zero) if @p filename could not be
 * written.  Some possible reasons for failure include (a) being unable to
 * open the file, and (b) using a filename that indicates a compressed Sbgn
 * file (i.e., a filename ending in <code>&quot;.zip&quot;</code> or
 * similar) when the compression functionality has not been enabled in
 * the underlying copy of libSBGN.
 *
 * @if clike @warning Note that the string is owned by the caller and
 * should be freed (with the normal string <code>free()</code> C++
 * function) after it is no longer needed.@endif@~
 *
 * @see SbgnWriter::hasZlib()
 * @see SbgnWriter::hasBzip2()
 *
 * @if conly
 * @memberof SbgnWriter_t
 * @endif
 */
LIBSBGN_EXTERN
int
writeSBGNToFile (const SbgnDocument_t *d, const char *filename);


END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#endif  /* SbgnWriter_h */

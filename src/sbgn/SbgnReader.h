/**
 * @file SbgnReader.h
 * @brief Definition of the SbgnReader class.
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
 * @class SbgnReader
 * @sbmlbrief{} TODO:Definition of the SbgnReader class.
 */


#ifndef SbgnReader_h
#define SbgnReader_h


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>
#include <sbml/util/util.h>

#ifdef __cplusplus


#include <string>

LIBSBGN_CPP_NAMESPACE_BEGIN

class SbgnDocument;


class LIBSBGN_EXTERN SbgnReader
{
public:

  /**
   * Creates a new SbgnReader object and returns it.
   *
   * The libSBGN SbgnReader object offers methods for reading SBGN in
   * XML form from files and text strings.
   */
  SbgnReader ();


  /**
   * Destroys this SbgnReader.
   */
  virtual ~SbgnReader ();


  /**
   * This method is identical to
   * @if python @link SbgnReader::readSBGNFromFile() SbgnReader.readSBGNFromFile()@endlink@endif@if java @link SbgnReader::readSBGNFromFile(String) SbgnReader.readSBGNFromFile(String)@endlink@endif@if cpp SbgnReader::readSBGNFromFile()@endif@if csharp SbgnReader.readSBGNFromFile()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SbgnDocument object created from the SBGN
   * content in @p filename.
   *
   * @see readSBGNFromString(@if java String@endif)
   * @see SbgnError
   * @see SbgnDocument
   */
  SbgnDocument* readSBGN (const std::string& filename);


  /**
   * This method is identical to
   * @if python @link SbgnReader::readSBGN() SbgnReader.readSBGN()@endlink@endif@if java @link SbgnReader::readSBGN(String) SbgnReader.readSBGN(String)@endlink@endif@if cpp SbgnReader::readSBGN()@endif@if csharp SbgnReader.readSBGN()@endif.
   *
   * @param filename the name or full pathname of the file to be read.
   *
   * @return a pointer to the SbgnDocument object created from the Sbgn
   * content in @p filename.
   *
   * @see readSBGNFromString(@if java String@endif)
   * @see SbgnError
   * @see SbgnDocument
   */
  SbgnDocument* readSBGNFromFile (const std::string& filename);


  /**
   * @param xml a string containing a full Sbgn model
   *
   * @return a pointer to the SbgnDocument created from the Sbgn content,
   * or a null pointer if @p xml is null.
   *
   * @see SbgnReader::readSBGN(@if java String@endif)
   */
  SbgnDocument* readSBGNFromString (const std::string& xml);


  /**
   * Static method; returns @c true if this copy of libSBGN supports
   * <i>gzip</I> and <i>zip</i> format compression.
   *
   * @return @c true if libSBGN has been linked with the <i>zlib</i>
   * library, @c false otherwise.
   *
   * @see @if clike hasBzip2() @else SbgnReader::hasBzip2()@endif@~
   */
  static bool hasZlib();


  /**
   * Static method; returns @c true if this copy of libSBGN supports
   * <i>bzip2</i> format compression.
   *
   * @return @c true if libSBGN is linked with the <i>bzip2</i>
   * libraries, @c false otherwise.
   *
   * @see @if clike hasZlib() @else SbgnReader::hasZlib()@endif@~
   */
  static bool hasBzip2();


protected:
  /** @cond doxygenLibsbgnInternal */
  /**
   * Used by readSBGN() and readSBGNFromString().
   */
  SbgnDocument* readInternal (const char* content, bool isFile = true);

  /** @endcond */
};

LIBSBGN_CPP_NAMESPACE_END

#endif /* __cplusplus */


LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


#ifndef SWIG


/**
 * Creates a new SbgnReader_t and returns it.
 *
 * By default, XML Schema validation is off.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnReader_t *
SbgnReader_create (void);


/**
 * Frees the given SbgnReader_t.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
void
SbgnReader_free (SbgnReader_t *sr);


/**
 * This function is identical to SbgnReader_readSBGNFromFile().
 *
 * @param sr The SbgnReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SbgnDocument structure created from the Sbgn
 * content read from @p filename.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
SbgnReader_readSBGN (SbgnReader_t *sr, const char *filename);


/**
 * This function is identical to SbgnReader_readSBGN().
 *
 * @param sr The SbgnReader_t structure to use.
 *
 * @param filename a string giving the path to a file where the XML
 * content is to be found.
 *
 * @return a pointer to the SbgnDocument structure created from the Sbgn
 * content read from @p filename.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
SbgnReader_readSBGNFromFile (SbgnReader_t *sr, const char *filename);


/**
 * @param sr the SbgnReader_t structure to use
 *
 * @param xml the input xml string.
 *
 * @return a pointer to the SbgnDocument read.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
SbgnReader_readSBGNFromString (SbgnReader_t *sr, const char *xml);


/**
 * Returns @c true if the underlying libSBGN supports @em gzip and @em zlib
 * format compression.
 *
 * This predicate tests whether the underlying copy of the libSBGN library
 * has been linked with the necessary libraries to support @em zlib
 * compression.
 *
 * @return @c non-zero if libSBGN is linked with zlib, @c zero otherwise.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
int
SbgnReader_hasZlib ();


/**
 * Returns @c true if the underlying libSBGN supports @em bzip2 format
 * compression.
 *
 * This predicate tests whether the underlying copy of the libSBGN library
 * has been linked with the necessary libraries to support @em bzip2
 * compression.
 *
 * @return @c non-zero if libSBGN is linked with bzip2, @c zero otherwise.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
int
SbgnReader_hasBzip2 ();

#endif  /* !SWIG */


/**
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
readSBGN (const char *filename);


/**
 * @param filename the name or full pathname of the file to be read.
 *
 * @return a pointer to the SbgnDocument structure created from the Sbgn
 * content in @p filename.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
readSBGNFromFile (const char *filename);


/**
 * @param xml a string containing a full Sbgn model
 *
 * @return a pointer to the SbgnDocument structure created from the Sbgn
 * content in @p xml.
 *
 * @if conly
 * @memberof SbgnReader_t
 * @endif
 */
LIBSBGN_EXTERN
SbgnDocument_t *
readSBGNFromString (const char *xml);


END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#endif  /* SbgnReader_h */

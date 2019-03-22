/**
 * @file SbgnTypeCodes.h
 * @brief Definition of the SbgnTypeCodes class.
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
 * @class SbgnTypeCodes
 * @sbmlbrief{} TODO:Definition of the SbgnTypeCodes class.
 */



#ifndef SbgnTypeCodes_h
#define SbgnTypeCodes_h


#include <sbgn/common/libsbgn-config.h>
#include <sbgn/common/extern.h>

LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * @enum  SbgnTypeCode_t
 * @brief The enumeration of possible SBGN core object types.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 *
 */
typedef enum
{
    SBGN_UNKNOWN                    =  0
  , SBGN_SBGNML_POINT
  , SBGN_SBGNML_BBOX
  , SBGN_SBGNML_LABEL
  , SBGN_SBGNML_MAP
  , SBGN_DOCUMENT
  , SBGN_SBGNML_GLYPH
  , SBGN_SBGNML_PORT
  , SBGN_SBGNML_ARC
  , SBGN_SBGNML_STATE
  , SBGN_SBGNML_CALLOUT
  , SBGN_SBGNML_ENTITY
  , SBGN_SBGNML_ARCGROUP
  , SBGN_LIST_OF
} SbgnTypeCode_t;



/**
 * This method takes an SBGN type code and returns a string representing
 * the code.
 *
 * @if clike LibSBGN attaches an identifying code to every kind of SBGN
 * object.  These are known as <em>SBGN type codes</em>.  The set of
 * possible type codes is defined in the enumeration #SbgnTypeCode_t.
 * The names of the type codes all begin with the characters @c
 * SBGN_. @endif@if java LibSBGN attaches an identifying code to every
 * kind of SBGN object.  These are known as <em>SBGN type codes</em>.  In
 * other languages, the set of type codes is stored in an enumeration; in
 * the Java language interface for libSBGN, the type codes are defined as
 * static integer constants in the interface class {@link
 * libsbgnConstants}.  The names of the type codes all begin with the
 * characters @c SBGN_. @endif@if python LibSBGN attaches an identifying
 * code to every kind of SBGN object.  These are known as <em>SBGN type
 * codes</em>.  In the Python language interface for libSBGN, the type
 * codes are defined as static integer constants in the interface class
 * @link libsbgn@endlink.  The names of the type codes all begin with the
 * characters @c SBGN_. @endif@if csharp LibSBGN attaches an identifying
 * code to every kind of SBGN object.  These are known as <em>SBGN type
 * codes</em>.  In the C# language interface for libSBGN, the type codes
 * are defined as static integer constants in the interface class @link
 * libsbgn@endlink.  The names of the type codes all begin with
 * the characters @c SBGN_. @endif@~
 *
 * @return a human readable name for the given
 * @if clike #SbgnTypeCode_t value@else SBGN type code@endif.
 *
 * @note The caller does not own the returned string and is therefore not
 * allowed to modify it.
 */
LIBSBGN_EXTERN
const char *
SbgnTypeCode_toString (int tc);


END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#endif  /* SbgnTypeCodes_h */

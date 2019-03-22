/**
 * @file local.cpp
 * @brief Implementation of the local class.
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



#include <cstddef>
#include "sbgn/SbgnBase.h"

/**
* @return the most specific Swig type for the given SbgnBase object.
*/
struct swig_type_info*
GetDowncastSwigType (SbgnBase* sb)
{
  if (sb == 0) return SWIGTYPE_p_SbgnBase;

  std::string name;

  switch (sb->getTypeCode())
  {
  case SBGN_DOCUMENT:
    return SWIGTYPE_p_SbgnDocument;

    case SBGN_SBGNML_POINT:
      return SWIGTYPE_p_SbgnPoint;

    case SBGN_SBGNML_BBOX:
      return SWIGTYPE_p_SbgnBBox;

    case SBGN_SBGNML_LABEL:
      return SWIGTYPE_p_SbgnLabel;

    case SBGN_SBGNML_MAP:
      return SWIGTYPE_p_SbgnMap;

    case SBGN_SBGNML_GLYPH:
      return SWIGTYPE_p_SbgnGlyph;

    case SBGN_SBGNML_PORT:
      return SWIGTYPE_p_SbgnPort;

    case SBGN_SBGNML_ARC:
      return SWIGTYPE_p_SbgnArc;

    case SBGN_SBGNML_STATE:
      return SWIGTYPE_p_SbgnState;

    case SBGN_SBGNML_CALLOUT:
      return SWIGTYPE_p_SbgnCallout;

    case SBGN_SBGNML_ENTITY:
      return SWIGTYPE_p_SbgnEntity;

    case SBGN_SBGNML_ARCGROUP:
      return SWIGTYPE_p_SbgnArcGroup;

    case SBGN_LIST_OF:
      name = sb->getElementName();
      if(name == "listOf")
      {
        return SWIGTYPE_p_SbgnListOf;
      }
      else if (name == "listOfPoints")
      {
         return SWIGTYPE_p_SbgnListOfPoints;
      }
      else if (name == "listOfMaps")
      {
         return SWIGTYPE_p_SbgnListOfMaps;
      }
      else if (name == "listOfGlyphs")
      {
         return SWIGTYPE_p_SbgnListOfGlyphs;
      }
      else if (name == "listOfPorts")
      {
         return SWIGTYPE_p_SbgnListOfPorts;
      }
      else if (name == "listOfArcs")
      {
         return SWIGTYPE_p_SbgnListOfArcs;
      }
      else if (name == "listOfArcGroups")
      {
         return SWIGTYPE_p_SbgnListOfArcGroups;
      }
    
    return SWIGTYPE_p_SbgnListOf;
    
  default:
    return SWIGTYPE_p_SbgnBase;
  }

  return SWIGTYPE_p_SbgnBase;
}

/* Compatibility bug fix for swig 2.0.7 and Python 3. 
* See http://patch-tracker.debian.org/patch/series/view/swig2.0/2.0.7-3/pyint_fromsize_t.diff
*/
#if (PY_MAJOR_VERSION >= 3)
#define PyInt_FromSize_t(x) PyLong_FromSize_t(x)
#endif

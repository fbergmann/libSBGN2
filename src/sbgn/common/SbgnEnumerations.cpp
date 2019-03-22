/**
 * @file SbgnmlEnumerations.cpp
 * @brief Implementation of SbgnmlEnumerations.
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
#include <string>
#include <sbgn/common/SbgnEnumerations.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


static
const char* SBGN_LANGUAGE_STRINGS[] =
{
  "process description"
, "entity relationship"
, "activity flow"
, "invalid Language value"
};


/*
 * Returns the string version of the provided #Language_t enumeration.
 */
LIBSBGN_EXTERN
const char*
Language_toString(Language_t l)
{
  int min = SBGNML_LANGUAGE_PROCESS_DESCRIPTION;
  int max = SBGNML_LANGUAGE_INVALID;

  if (l < min || l > max)
  {
    return "(Unknown Language value)";
  }

  return SBGN_LANGUAGE_STRINGS[l - min];
}


/*
 * Returns the #Language_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t} if there is no such
 * match.
 */
LIBSBGN_EXTERN
Language_t
Language_fromString(const char* code)
{
  static int size =
    sizeof(SBGN_LANGUAGE_STRINGS)/sizeof(SBGN_LANGUAGE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_LANGUAGE_STRINGS[i])
    {
      return (Language_t)(i);
    }
  }

  return SBGNML_LANGUAGE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Language_t is valid.
 */
LIBSBGN_EXTERN
int
Language_isValid(Language_t l)
{
  int min = SBGNML_LANGUAGE_PROCESS_DESCRIPTION;
  int max = SBGNML_LANGUAGE_INVALID;

  if (l < min || l >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Language_t.
 */
LIBSBGN_EXTERN
int
Language_isValidString(const char* code)
{
  return Language_isValid(Language_fromString(code));
}


static
const char* SBGN_CLASS_STRINGS[] =
{
  "unspecified entity"
, "simple chemical"
, "macromolecule"
, "nucleic acid feature"
, "simple chemical multimer"
, "macromolecule multimer"
, "nucleic acid feature multimer"
, "complex"
, "complex multimer"
, "source and sink"
, "perturbation"
, "biological activity"
, "perturbing agent"
, "compartment"
, "submap"
, "tag"
, "terminal"
, "process"
, "omitted process"
, "uncertain process"
, "association"
, "dissociation"
, "phenotype"
, "and"
, "or"
, "not"
, "state variable"
, "unit of information"
, "entity"
, "outcome"
, "interaction"
, "influence target"
, "annotation"
, "variable value"
, "implicit xor"
, "delay"
, "existence"
, "location"
, "cardinality"
, "observable"
, "invalid Class value"
};


/*
 * Returns the string version of the provided #Class_t enumeration.
 */
LIBSBGN_EXTERN
const char*
Class_toString(Class_t c)
{
  int min = SBGNML_CLASS_UNSPECIFIED_ENTITY;
  int max = SBGNML_CLASS_INVALID;

  if (c < min || c > max)
  {
    return "(Unknown Class value)";
  }

  return SBGN_CLASS_STRINGS[c - min];
}


/*
 * Returns the #Class_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_CLASS_INVALID, Class_t} if there is no such match.
 */
LIBSBGN_EXTERN
Class_t
Class_fromString(const char* code)
{
  static int size = sizeof(SBGN_CLASS_STRINGS)/sizeof(SBGN_CLASS_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_CLASS_STRINGS[i])
    {
      return (Class_t)(i);
    }
  }

  return SBGNML_CLASS_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Class_t is valid.
 */
LIBSBGN_EXTERN
int
Class_isValid(Class_t c)
{
  int min = SBGNML_CLASS_UNSPECIFIED_ENTITY;
  int max = SBGNML_CLASS_INVALID;

  if (c < min || c >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Class_t.
 */
LIBSBGN_EXTERN
int
Class_isValidString(const char* code)
{
  return Class_isValid(Class_fromString(code));
}


static
const char* SBGN_ORIENTATION_STRINGS[] =
{
  "horizontal"
, "vertical"
, "left"
, "right"
, "up"
, "down"
, "invalid Orientation value"
};


/*
 * Returns the string version of the provided #Orientation_t enumeration.
 */
LIBSBGN_EXTERN
const char*
Orientation_toString(Orientation_t o)
{
  int min = SBGNML_ORIENTATION_HORIZONTAL;
  int max = SBGNML_ORIENTATION_INVALID;

  if (o < min || o > max)
  {
    return "(Unknown Orientation value)";
  }

  return SBGN_ORIENTATION_STRINGS[o - min];
}


/*
 * Returns the #Orientation_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ORIENTATION_INVALID, Orientation_t} if there is no such
 * match.
 */
LIBSBGN_EXTERN
Orientation_t
Orientation_fromString(const char* code)
{
  static int size =
    sizeof(SBGN_ORIENTATION_STRINGS)/sizeof(SBGN_ORIENTATION_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_ORIENTATION_STRINGS[i])
    {
      return (Orientation_t)(i);
    }
  }

  return SBGNML_ORIENTATION_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Orientation_t is valid.
 */
LIBSBGN_EXTERN
int
Orientation_isValid(Orientation_t o)
{
  int min = SBGNML_ORIENTATION_HORIZONTAL;
  int max = SBGNML_ORIENTATION_INVALID;

  if (o < min || o >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Orientation_t.
 */
LIBSBGN_EXTERN
int
Orientation_isValidString(const char* code)
{
  return Orientation_isValid(Orientation_fromString(code));
}


static
const char* SBGN_ENTITY_TYPE_STRINGS[] =
{
  "unspecified entity"
, "simple chemical"
, "macromolecule"
, "nucleic acid feature"
, "complex"
, "perturbation"
, "invalid EntityType value"
};


/*
 * Returns the string version of the provided #EntityType_t enumeration.
 */
LIBSBGN_EXTERN
const char*
EntityType_toString(EntityType_t et)
{
  int min = SBGNML_ENTITYTYPE_UNSPECIFIED_ENTITY;
  int max = SBGNML_ENTITYTYPE_INVALID;

  if (et < min || et > max)
  {
    return "(Unknown EntityType value)";
  }

  return SBGN_ENTITY_TYPE_STRINGS[et - min];
}


/*
 * Returns the #EntityType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ENTITYTYPE_INVALID, EntityType_t} if there is no such
 * match.
 */
LIBSBGN_EXTERN
EntityType_t
EntityType_fromString(const char* code)
{
  static int size =
    sizeof(SBGN_ENTITY_TYPE_STRINGS)/sizeof(SBGN_ENTITY_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_ENTITY_TYPE_STRINGS[i])
    {
      return (EntityType_t)(i);
    }
  }

  return SBGNML_ENTITYTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #EntityType_t is valid.
 */
LIBSBGN_EXTERN
int
EntityType_isValid(EntityType_t et)
{
  int min = SBGNML_ENTITYTYPE_UNSPECIFIED_ENTITY;
  int max = SBGNML_ENTITYTYPE_INVALID;

  if (et < min || et >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #EntityType_t.
 */
LIBSBGN_EXTERN
int
EntityType_isValidString(const char* code)
{
  return EntityType_isValid(EntityType_fromString(code));
}


static
const char* SBGN_ARC_GROUP_TYPE_STRINGS[] =
{
  "interaction"
, "invalid ArcGroupType value"
};


/*
 * Returns the string version of the provided #ArcGroupType_t enumeration.
 */
LIBSBGN_EXTERN
const char*
ArcGroupType_toString(ArcGroupType_t agt)
{
  int min = SBGNML_ARCGROUPTYPE_INTERACTION;
  int max = SBGNML_ARCGROUPTYPE_INVALID;

  if (agt < min || agt > max)
  {
    return "(Unknown ArcGroupType value)";
  }

  return SBGN_ARC_GROUP_TYPE_STRINGS[agt - min];
}


/*
 * Returns the #ArcGroupType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID, ArcGroupType_t} if there is no
 * such match.
 */
LIBSBGN_EXTERN
ArcGroupType_t
ArcGroupType_fromString(const char* code)
{
  static int size = sizeof(SBGN_ARC_GROUP_TYPE_STRINGS)/sizeof(SBGN_ARC_GROUP_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_ARC_GROUP_TYPE_STRINGS[i])
    {
      return (ArcGroupType_t)(i);
    }
  }

  return SBGNML_ARCGROUPTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ArcGroupType_t is valid.
 */
LIBSBGN_EXTERN
int
ArcGroupType_isValid(ArcGroupType_t agt)
{
  int min = SBGNML_ARCGROUPTYPE_INTERACTION;
  int max = SBGNML_ARCGROUPTYPE_INVALID;

  if (agt < min || agt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ArcGroupType_t.
 */
LIBSBGN_EXTERN
int
ArcGroupType_isValidString(const char* code)
{
  return ArcGroupType_isValid(ArcGroupType_fromString(code));
}


static
const char* SBGN_MAP_TYPE_STRINGS[] =
{
  "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
, "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2"
, "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1"
, "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0"
, "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1"
, "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2"
, "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2"
, "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1"
, "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0"
, "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1"
, "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2"
, "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0"
, "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1"
, "invalid MapType value"
};


/*
 * Returns the string version of the provided #MapType_t enumeration.
 */
LIBSBGN_EXTERN
const char*
MapType_toString(MapType_t mt)
{
  int min = SBGNML_MAPTYPE_PD_L1_V1_3;
  int max = SBGNML_MAPTYPE_INVALID;

  if (mt < min || mt > max)
  {
    return "(Unknown MapType value)";
  }

  return SBGN_MAP_TYPE_STRINGS[mt - min];
}


/*
 * Returns the #MapType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t} if there is no such match.
 */
LIBSBGN_EXTERN
MapType_t
MapType_fromString(const char* code)
{
  static int size =
    sizeof(SBGN_MAP_TYPE_STRINGS)/sizeof(SBGN_MAP_TYPE_STRINGS[0]);
  std::string type(code);

  for (int i = 0; i < size; i++)
  {
    if (type == SBGN_MAP_TYPE_STRINGS[i])
    {
      return (MapType_t)(i);
    }
  }

  return SBGNML_MAPTYPE_INVALID;
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MapType_t is valid.
 */
LIBSBGN_EXTERN
int
MapType_isValid(MapType_t mt)
{
  int min = SBGNML_MAPTYPE_PD_L1_V1_3;
  int max = SBGNML_MAPTYPE_INVALID;

  if (mt < min || mt >= max)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}


/*
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MapType_t.
 */
LIBSBGN_EXTERN
int
MapType_isValidString(const char* code)
{
  return MapType_isValid(MapType_fromString(code));
}




LIBSBGN_CPP_NAMESPACE_END



/**
 * @file SbgnmlEnumerations.h
 * @brief Definition of SbgnmlEnumerations.
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
 * @class SbgnmlEnumerations
 * @sbmlbrief{sbgnml} TODO:Definition of SbgnmlEnumerations.
 */


#ifndef SbgnmlEnumerations_H__
#define SbgnmlEnumerations_H__


#include <sbgn/common/extern.h>
#include <sbgn/SbgnTypeCodes.h>


LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * @enum Language_t
 * @brief Enumeration of values permitted as the value of "Language_t".
 */
typedef enum
{
  SBGNML_LANGUAGE_PROCESS_DESCRIPTION       /*!< The sbgnml language is @c "process description". */
, SBGNML_LANGUAGE_ENTITY_RELATIONSHIP       /*!< The sbgnml language is @c "entity relationship". */
, SBGNML_LANGUAGE_ACTIVITY_FLOW             /*!< The sbgnml language is @c "activity flow". */
, SBGNML_LANGUAGE_INVALID                   /*!< Invalid Language value. */
} Language_t;


/**
 * Returns the string version of the provided #Language_t enumeration.
 *
 * @param l the #Language_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "process description",
 * "entity relationship",
 * "activity flow",
 * "invalid Language value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_LANGUAGE_INVALID,
 * Language_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
Language_toString(Language_t l);


/**
 * Returns the #Language_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #Language_t.
 *
 * @return the corresponding #Language_t or
 * @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t} if no match is found.
 *
 * @note The matching is case-sensitive: "process description" will return
 * @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t}, but "Process "
 * "description" will return @sbmlconstant{SBGNML_LANGUAGE_INVALID,
 * Language_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
Language_t
Language_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Language_t is valid.
 *
 * @param l the #Language_t enumeration to query.
 *
 * @return @c 1 (true) if the #Language_t is
 * @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t},
 * @sbmlconstant{SBGNML_LANGUAGE_ENTITY_RELATIONSHIP, Language_t}, or
 * @sbmlconstant{SBGNML_LANGUAGE_ACTIVITY_FLOW, Language_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_LANGUAGE_INVALID,
 * Language_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Language_isValid(Language_t l);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Language_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "process description",
 * "entity relationship",
 * "activity flow", or
 * "invalid Language value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "process description" will return @c 1
 * (true), but "Process description" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Language_isValidString(const char* code);


/**
 * @enum Class_t
 * @brief Enumeration of values permitted as the value of "Class_t".
 */
typedef enum
{
  SBGNML_CLASS_UNSPECIFIED_ENTITY                  /*!< The sbgnml class is @c "unspecified entity". */
, SBGNML_CLASS_SIMPLE_CHEMICAL                     /*!< The sbgnml class is @c "simple chemical". */
, SBGNML_CLASS_MACROMOLECULE                       /*!< The sbgnml class is @c "macromolecule". */
, SBGNML_CLASS_NUCLEIC_ACID_FEATURE                /*!< The sbgnml class is @c "nucleic acid feature". */
, SBGNML_CLASS_SIMPLE_CHEMICAL_MULTIMER            /*!< The sbgnml class is @c "simple chemical multimer". */
, SBGNML_CLASS_MACROMOLECULE_MULTIMER              /*!< The sbgnml class is @c "macromolecule multimer". */
, SBGNML_CLASS_NUCLEIC_ACID_FEATURE_MULTIMER       /*!< The sbgnml class is @c "nucleic acid feature multimer". */
, SBGNML_CLASS_COMPLEX                             /*!< The sbgnml class is @c "complex". */
, SBGNML_CLASS_COMPLEX_MULTIMER                    /*!< The sbgnml class is @c "complex multimer". */
, SBGNML_CLASS_SOURCE_AND_SINK                     /*!< The sbgnml class is @c "source and sink". */
, SBGNML_CLASS_PERTURBATION                        /*!< The sbgnml class is @c "perturbation". */
, SBGNML_CLASS_BIOLOGICAL_ACTIVITY                 /*!< The sbgnml class is @c "biological activity". */
, SBGNML_CLASS_PERTURBING_AGENT                    /*!< The sbgnml class is @c "perturbing agent". */
, SBGNML_CLASS_COMPARTMENT                         /*!< The sbgnml class is @c "compartment". */
, SBGNML_CLASS_SUBMAP                              /*!< The sbgnml class is @c "submap". */
, SBGNML_CLASS_TAG                                 /*!< The sbgnml class is @c "tag". */
, SBGNML_CLASS_TERMINAL                            /*!< The sbgnml class is @c "terminal". */
, SBGNML_CLASS_PROCESS                             /*!< The sbgnml class is @c "process". */
, SBGNML_CLASS_OMITTED_PROCESS                     /*!< The sbgnml class is @c "omitted process". */
, SBGNML_CLASS_UNCERTAIN_PROCESS                   /*!< The sbgnml class is @c "uncertain process". */
, SBGNML_CLASS_ASSOCIATION                         /*!< The sbgnml class is @c "association". */
, SBGNML_CLASS_DISSOCIATION                        /*!< The sbgnml class is @c "dissociation". */
, SBGNML_CLASS_PHENOTYPE                           /*!< The sbgnml class is @c "phenotype". */
, SBGNML_CLASS_AND                                 /*!< The sbgnml class is @c "and". */
, SBGNML_CLASS_OR                                  /*!< The sbgnml class is @c "or". */
, SBGNML_CLASS_NOT                                 /*!< The sbgnml class is @c "not". */
, SBGNML_CLASS_STATE_VARIABLE                      /*!< The sbgnml class is @c "state variable". */
, SBGNML_CLASS_UNIT_OF_INFORMATION                 /*!< The sbgnml class is @c "unit of information". */
, SBGNML_CLASS_ENTITY                              /*!< The sbgnml class is @c "entity". */
, SBGNML_CLASS_OUTCOME                             /*!< The sbgnml class is @c "outcome". */
, SBGNML_CLASS_INTERACTION                         /*!< The sbgnml class is @c "interaction". */
, SBGNML_CLASS_INFLUENCE_TARGET                    /*!< The sbgnml class is @c "influence target". */
, SBGNML_CLASS_ANNOTATION                          /*!< The sbgnml class is @c "annotation". */
, SBGNML_CLASS_VARIABLE_VALUE                      /*!< The sbgnml class is @c "variable value". */
, SBGNML_CLASS_IMPLICIT_XOR                        /*!< The sbgnml class is @c "implicit xor". */
, SBGNML_CLASS_DELAY                               /*!< The sbgnml class is @c "delay". */
, SBGNML_CLASS_EXISTENCE                           /*!< The sbgnml class is @c "existence". */
, SBGNML_CLASS_LOCATION                            /*!< The sbgnml class is @c "location". */
, SBGNML_CLASS_CARDINALITY                         /*!< The sbgnml class is @c "cardinality". */
, SBGNML_CLASS_OBSERVABLE                          /*!< The sbgnml class is @c "observable". */
, SBGNML_CLASS_INVALID                             /*!< Invalid Class value. */
} Class_t;


/**
 * Returns the string version of the provided #Class_t enumeration.
 *
 * @param c the #Class_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "unspecified entity",
 * "simple chemical",
 * "macromolecule",
 * "nucleic acid feature",
 * "simple chemical multimer",
 * "macromolecule multimer",
 * "nucleic acid feature multimer",
 * "complex",
 * "complex multimer",
 * "source and sink",
 * "perturbation",
 * "biological activity",
 * "perturbing agent",
 * "compartment",
 * "submap",
 * "tag",
 * "terminal",
 * "process",
 * "omitted process",
 * "uncertain process",
 * "association",
 * "dissociation",
 * "phenotype",
 * "and",
 * "or",
 * "not",
 * "state variable",
 * "unit of information",
 * "entity",
 * "outcome",
 * "interaction",
 * "influence target",
 * "annotation",
 * "variable value",
 * "implicit xor",
 * "delay",
 * "existence",
 * "location",
 * "cardinality",
 * "observable",
 * "invalid Class value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_CLASS_INVALID, Class_t} or
 * another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
Class_toString(Class_t c);


/**
 * Returns the #Class_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_CLASS_INVALID, Class_t} if there is no such match.
 *
 * @param code the string to convert to a #Class_t.
 *
 * @return the corresponding #Class_t or @sbmlconstant{SBGNML_CLASS_INVALID,
 * Class_t} if no match is found.
 *
 * @note The matching is case-sensitive: "unspecified entity" will return
 * @sbmlconstant{SBGNML_CLASS_UNSPECIFIED_ENTITY, Class_t}, but "Unspecified "
 * "entity" will return @sbmlconstant{SBGNML_CLASS_INVALID, Class_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
Class_t
Class_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Class_t is valid.
 *
 * @param c the #Class_t enumeration to query.
 *
 * @return @c 1 (true) if the #Class_t is
 * @sbmlconstant{SBGNML_CLASS_UNSPECIFIED_ENTITY, Class_t},
 * @sbmlconstant{SBGNML_CLASS_SIMPLE_CHEMICAL, Class_t},
 * @sbmlconstant{SBGNML_CLASS_MACROMOLECULE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_NUCLEIC_ACID_FEATURE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_SIMPLE_CHEMICAL_MULTIMER, Class_t},
 * @sbmlconstant{SBGNML_CLASS_MACROMOLECULE_MULTIMER, Class_t},
 * @sbmlconstant{SBGNML_CLASS_NUCLEIC_ACID_FEATURE_MULTIMER, Class_t},
 * @sbmlconstant{SBGNML_CLASS_COMPLEX, Class_t},
 * @sbmlconstant{SBGNML_CLASS_COMPLEX_MULTIMER, Class_t},
 * @sbmlconstant{SBGNML_CLASS_SOURCE_AND_SINK, Class_t},
 * @sbmlconstant{SBGNML_CLASS_PERTURBATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_BIOLOGICAL_ACTIVITY, Class_t},
 * @sbmlconstant{SBGNML_CLASS_PERTURBING_AGENT, Class_t},
 * @sbmlconstant{SBGNML_CLASS_COMPARTMENT, Class_t},
 * @sbmlconstant{SBGNML_CLASS_SUBMAP, Class_t},
 * @sbmlconstant{SBGNML_CLASS_TAG, Class_t},
 * @sbmlconstant{SBGNML_CLASS_TERMINAL, Class_t},
 * @sbmlconstant{SBGNML_CLASS_PROCESS, Class_t},
 * @sbmlconstant{SBGNML_CLASS_OMITTED_PROCESS, Class_t},
 * @sbmlconstant{SBGNML_CLASS_UNCERTAIN_PROCESS, Class_t},
 * @sbmlconstant{SBGNML_CLASS_ASSOCIATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_DISSOCIATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_PHENOTYPE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_AND, Class_t},
 * @sbmlconstant{SBGNML_CLASS_OR, Class_t},
 * @sbmlconstant{SBGNML_CLASS_NOT, Class_t},
 * @sbmlconstant{SBGNML_CLASS_STATE_VARIABLE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_UNIT_OF_INFORMATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_ENTITY, Class_t},
 * @sbmlconstant{SBGNML_CLASS_OUTCOME, Class_t},
 * @sbmlconstant{SBGNML_CLASS_INTERACTION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_INFLUENCE_TARGET, Class_t},
 * @sbmlconstant{SBGNML_CLASS_ANNOTATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_VARIABLE_VALUE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_IMPLICIT_XOR, Class_t},
 * @sbmlconstant{SBGNML_CLASS_DELAY, Class_t},
 * @sbmlconstant{SBGNML_CLASS_EXISTENCE, Class_t},
 * @sbmlconstant{SBGNML_CLASS_LOCATION, Class_t},
 * @sbmlconstant{SBGNML_CLASS_CARDINALITY, Class_t}, or
 * @sbmlconstant{SBGNML_CLASS_OBSERVABLE, Class_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_CLASS_INVALID,
 * Class_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Class_isValid(Class_t c);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Class_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "unspecified entity",
 * "simple chemical",
 * "macromolecule",
 * "nucleic acid feature",
 * "simple chemical multimer",
 * "macromolecule multimer",
 * "nucleic acid feature multimer",
 * "complex",
 * "complex multimer",
 * "source and sink",
 * "perturbation",
 * "biological activity",
 * "perturbing agent",
 * "compartment",
 * "submap",
 * "tag",
 * "terminal",
 * "process",
 * "omitted process",
 * "uncertain process",
 * "association",
 * "dissociation",
 * "phenotype",
 * "and",
 * "or",
 * "not",
 * "state variable",
 * "unit of information",
 * "entity",
 * "outcome",
 * "interaction",
 * "influence target",
 * "annotation",
 * "variable value",
 * "implicit xor",
 * "delay",
 * "existence",
 * "location",
 * "cardinality",
 * "observable", or
 * "invalid Class value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "unspecified entity" will return @c 1
 * (true), but "Unspecified entity" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Class_isValidString(const char* code);


/**
 * @enum Orientation_t
 * @brief Enumeration of values permitted as the value of "Orientation_t".
 */
typedef enum
{
  SBGNML_ORIENTATION_HORIZONTAL       /*!< The sbgnml orientation is @c "horizontal". */
, SBGNML_ORIENTATION_VERTICAL         /*!< The sbgnml orientation is @c "vertical". */
, SBGNML_ORIENTATION_LEFT             /*!< The sbgnml orientation is @c "left". */
, SBGNML_ORIENTATION_RIGHT            /*!< The sbgnml orientation is @c "right". */
, SBGNML_ORIENTATION_UP               /*!< The sbgnml orientation is @c "up". */
, SBGNML_ORIENTATION_DOWN             /*!< The sbgnml orientation is @c "down". */
, SBGNML_ORIENTATION_INVALID          /*!< Invalid Orientation value. */
} Orientation_t;


/**
 * Returns the string version of the provided #Orientation_t enumeration.
 *
 * @param o the #Orientation_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "horizontal",
 * "vertical",
 * "left",
 * "right",
 * "up",
 * "down",
 * "invalid Orientation value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_ORIENTATION_INVALID,
 * Orientation_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
Orientation_toString(Orientation_t o);


/**
 * Returns the #Orientation_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ORIENTATION_INVALID, Orientation_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #Orientation_t.
 *
 * @return the corresponding #Orientation_t or
 * @sbmlconstant{SBGNML_ORIENTATION_INVALID, Orientation_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "horizontal" will return
 * @sbmlconstant{SBGNML_ORIENTATION_HORIZONTAL, Orientation_t}, but
 * "Horizontal" will return @sbmlconstant{SBGNML_ORIENTATION_INVALID,
 * Orientation_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
Orientation_t
Orientation_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #Orientation_t is valid.
 *
 * @param o the #Orientation_t enumeration to query.
 *
 * @return @c 1 (true) if the #Orientation_t is
 * @sbmlconstant{SBGNML_ORIENTATION_HORIZONTAL, Orientation_t},
 * @sbmlconstant{SBGNML_ORIENTATION_VERTICAL, Orientation_t},
 * @sbmlconstant{SBGNML_ORIENTATION_LEFT, Orientation_t},
 * @sbmlconstant{SBGNML_ORIENTATION_RIGHT, Orientation_t},
 * @sbmlconstant{SBGNML_ORIENTATION_UP, Orientation_t}, or
 * @sbmlconstant{SBGNML_ORIENTATION_DOWN, Orientation_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_ORIENTATION_INVALID,
 * Orientation_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Orientation_isValid(Orientation_t o);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #Orientation_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "horizontal",
 * "vertical",
 * "left",
 * "right",
 * "up",
 * "down", or
 * "invalid Orientation value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "horizontal" will return @c 1 (true),
 * but "Horizontal" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
Orientation_isValidString(const char* code);


/**
 * @enum EntityType_t
 * @brief Enumeration of values permitted as the value of "EntityType_t".
 */
typedef enum
{
  SBGNML_ENTITYTYPE_UNSPECIFIED_ENTITY         /*!< The sbgnml entitytype is @c "unspecified entity". */
, SBGNML_ENTITYTYPE_SIMPLE_CHEMICAL            /*!< The sbgnml entitytype is @c "simple chemical". */
, SBGNML_ENTITYTYPE_MACROMOLECULE              /*!< The sbgnml entitytype is @c "macromolecule". */
, SBGNML_ENTITYTYPE_NUCLEIC_ACID_FEATURE       /*!< The sbgnml entitytype is @c "nucleic acid feature". */
, SBGNML_ENTITYTYPE_COMPLEX                    /*!< The sbgnml entitytype is @c "complex". */
, SBGNML_ENTITYTYPE_PERTURBATION               /*!< The sbgnml entitytype is @c "perturbation". */
, SBGNML_ENTITYTYPE_INVALID                    /*!< Invalid EntityType value. */
} EntityType_t;


/**
 * Returns the string version of the provided #EntityType_t enumeration.
 *
 * @param et the #EntityType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "unspecified entity",
 * "simple chemical",
 * "macromolecule",
 * "nucleic acid feature",
 * "complex",
 * "perturbation",
 * "invalid EntityType value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_ENTITYTYPE_INVALID,
 * EntityType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
EntityType_toString(EntityType_t et);


/**
 * Returns the #EntityType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ENTITYTYPE_INVALID, EntityType_t} if there is no such
 * match.
 *
 * @param code the string to convert to a #EntityType_t.
 *
 * @return the corresponding #EntityType_t or
 * @sbmlconstant{SBGNML_ENTITYTYPE_INVALID, EntityType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "unspecified entity" will return
 * @sbmlconstant{SBGNML_ENTITYTYPE_UNSPECIFIED_ENTITY, EntityType_t}, but
 * "Unspecified entity" will return @sbmlconstant{SBGNML_ENTITYTYPE_INVALID,
 * EntityType_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
EntityType_t
EntityType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #EntityType_t is valid.
 *
 * @param et the #EntityType_t enumeration to query.
 *
 * @return @c 1 (true) if the #EntityType_t is
 * @sbmlconstant{SBGNML_ENTITYTYPE_UNSPECIFIED_ENTITY, EntityType_t},
 * @sbmlconstant{SBGNML_ENTITYTYPE_SIMPLE_CHEMICAL, EntityType_t},
 * @sbmlconstant{SBGNML_ENTITYTYPE_MACROMOLECULE, EntityType_t},
 * @sbmlconstant{SBGNML_ENTITYTYPE_NUCLEIC_ACID_FEATURE, EntityType_t},
 * @sbmlconstant{SBGNML_ENTITYTYPE_COMPLEX, EntityType_t}, or
 * @sbmlconstant{SBGNML_ENTITYTYPE_PERTURBATION, EntityType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_ENTITYTYPE_INVALID,
 * EntityType_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
EntityType_isValid(EntityType_t et);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #EntityType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "unspecified entity",
 * "simple chemical",
 * "macromolecule",
 * "nucleic acid feature",
 * "complex",
 * "perturbation", or
 * "invalid EntityType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "unspecified entity" will return @c 1
 * (true), but "Unspecified entity" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
EntityType_isValidString(const char* code);


/**
 * @enum ArcGroupType_t
 * @brief Enumeration of values permitted as the value of "ArcGroupType_t".
 */
typedef enum
{
  SBGNML_ARCGROUPTYPE_INTERACTION       /*!< The sbgnml arcgrouptype is @c "interaction". */
, SBGNML_ARCGROUPTYPE_INVALID           /*!< Invalid ArcGroupType value. */
} ArcGroupType_t;


/**
 * Returns the string version of the provided #ArcGroupType_t enumeration.
 *
 * @param agt the #ArcGroupType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "interaction",
 * "invalid ArcGroupType value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID,
 * ArcGroupType_t} or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
ArcGroupType_toString(ArcGroupType_t agt);


/**
 * Returns the #ArcGroupType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID, ArcGroupType_t} if there is no
 * such match.
 *
 * @param code the string to convert to a #ArcGroupType_t.
 *
 * @return the corresponding #ArcGroupType_t or
 * @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID, ArcGroupType_t} if no match is
 * found.
 *
 * @note The matching is case-sensitive: "interaction" will return
 * @sbmlconstant{SBGNML_ARCGROUPTYPE_INTERACTION, ArcGroupType_t}, but
 * "Interaction" will return @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID,
 * ArcGroupType_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
ArcGroupType_t
ArcGroupType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #ArcGroupType_t is valid.
 *
 * @param agt the #ArcGroupType_t enumeration to query.
 *
 * @return @c 1 (true) if the #ArcGroupType_t is
 * @sbmlconstant{SBGNML_ARCGROUPTYPE_INTERACTION, ArcGroupType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_ARCGROUPTYPE_INVALID,
 * ArcGroupType_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
ArcGroupType_isValid(ArcGroupType_t agt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #ArcGroupType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "interaction", or
 * "invalid ArcGroupType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "interaction" will return @c 1 (true),
 * but "Interaction" will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
ArcGroupType_isValidString(const char* code);


/**
 * @enum MapType_t
 * @brief Enumeration of values permitted as the value of "MapType_t".
 */
typedef enum
{
  SBGNML_MAPTYPE_PD_L1_V1_3       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3". */
, SBGNML_MAPTYPE_PD_L1_V1_2       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2". */
, SBGNML_MAPTYPE_PD_L1_V1_1       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1". */
, SBGNML_MAPTYPE_PD_L1_V1_0       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0". */
, SBGNML_MAPTYPE_PD_L1_V1         /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1". */
, SBGNML_MAPTYPE_ER_L1_V2         /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2". */
, SBGNML_MAPTYPE_ER_L1_V1_2       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2". */
, SBGNML_MAPTYPE_ER_L1_V1_1       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1". */
, SBGNML_MAPTYPE_ER_L1_V1_0       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0". */
, SBGNML_MAPTYPE_ER_L1_V1         /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1". */
, SBGNML_MAPTYPE_AF_L1_V1_2       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2". */
, SBGNML_MAPTYPE_AF_L1_V1_0       /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0". */
, SBGNML_MAPTYPE_AF_L1_V1         /*!< The sbgnml maptype is @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1". */
, SBGNML_MAPTYPE_INVALID          /*!< Invalid MapType value. */
} MapType_t;


/**
 * Returns the string version of the provided #MapType_t enumeration.
 *
 * @param mt the #MapType_t enumeration value to convert.
 *
 * @return A string corresponding to the given type:
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1",
 * "invalid MapType value",
 * or @c NULL if the value is @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t}
 * or another invalid enumeration value.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
const char*
MapType_toString(MapType_t mt);


/**
 * Returns the #MapType_t enumeration corresponding to the given string or
 * @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t} if there is no such match.
 *
 * @param code the string to convert to a #MapType_t.
 *
 * @return the corresponding #MapType_t or
 * @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t} if no match is found.
 *
 * @note The matching is case-sensitive: "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * will return @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_3, MapType_t}, but "Http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * will return @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t}.
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
MapType_t
MapType_fromString(const char* code);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given #MapType_t is valid.
 *
 * @param mt the #MapType_t enumeration to query.
 *
 * @return @c 1 (true) if the #MapType_t is
 * @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_3, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_2, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_1, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_0, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V2, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_2, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_1, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_0, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_2, MapType_t},
 * @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_0, MapType_t}, or
 * @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1, MapType_t};
 * @c 0 (false) otherwise (including @sbmlconstant{SBGNML_MAPTYPE_INVALID,
 * MapType_t}).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
MapType_isValid(MapType_t mt);


/**
 * Predicate returning @c 1 (true) or @c 0 (false) depending on whether the
 * given string is a valid #MapType_t.
 *
 * @param code the string to query.
 *
 * @return @c 1 (true) if the string is
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0",
 * "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1", "
 * "or
 * "invalid MapType value";
 * @c 0 (false) otherwise.
 *
 * @note The matching is case-sensitive: "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * will return @c 1 (true), but "Http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * will return @c 0 (false).
 *
 * @if conly
 * @memberof Sbgnml_t
 * @endif
 */
LIBSBGN_EXTERN
int
MapType_isValidString(const char* code);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SbgnmlEnumerations_H__ */



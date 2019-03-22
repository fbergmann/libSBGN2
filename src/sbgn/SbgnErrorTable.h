/**
 * @file SbgnErrorTable.h
 * @brief Definition of the SbgnErrorTable class.
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


#ifndef SbgnErrorTable_H__
#define SbgnErrorTable_H__

#include <sbgn/SbgnError.h>


LIBSBGN_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibsbgnInternal */
typedef struct {
  const char * ref_l1v1;
} referenceEntry;


typedef struct {
  unsigned int code;
  const char * shortMessage;
  unsigned int category;
  unsigned int l1v1_severity;
  const char * message;
  referenceEntry reference;
} sbgnErrorTableEntry;


static const sbgnErrorTableEntry sbgnErrorTable[] =
{
  // 10000
  { SbgnUnknown,
    "Encountered unknown internal libSBGN error",
    LIBSBGN_CAT_INTERNAL, 
    LIBSBGN_SEV_FATAL,
    "Unrecognized error encountered by libSBGN",
    {"",
    }
  },

  //10001
  {
    SbgnNotUTF8,
    "File does not use UTF-8 encoding",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "An SBGN XML file must use UTF-8 as the character encoding. More "
    "precisely, the 'encoding' attribute of the XML declaration at the "
    "beginning of the XML data stream cannot have a value other than "
    "'UTF-8'. An example valid declaration is "
    "'<?xml version=\"1.0\" encoding=\"UTF-8\"?>'.",
    {""
    }
  },

  //10002
  {
    SbgnUnrecognizedElement,
    "Encountered unrecognized element",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "An SBGN XML document must not contain undefined elements or attributes "
    "in the SBGN namespace. Documents containing unknown elements or "
    "attributes placed in the SBGN namespace do not conform to the SBGN "
    "specification.",  
    {""
    }
  },

  //10003
  {
    SbgnNotSchemaConformant,
    "Document does not conform to the SBGN XML schema",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "An SBGN XML document must conform to the XML Schema for the corresponding "
    "SBGN Level, Version and Release. The XML Schema for SBGN defines the "
    "basic SBGN object structure, the data types used by those objects, and the "
    "order in which the objects may appear in an SBGN document.",
    {""
    }
  },

  //10201
  {
    SbgnInvalidMathElement,
    "Invalid MathML",
    LIBSBGN_CAT_MATHML_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "All MathML content in SBGN must appear within a <math> element, and the "
    "<math> element must be either explicitly or implicitly in the XML "
    "namespace \"http://www.w3.org/1998/Math/MathML\".",
    {""
    }
  },

  //10401
  {
    SbgnMissingExtensionNamespace,
    "Missing declaration of the XML namespace for the annotation",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "Every top-level element within an annotation element must "
    "have a namespace declared.",
    {""
    }
  },

  //10402
  {
    SbgnDuplicateExtensionNamespaces,
    "Multiple annotations using the same XML namespace",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "There cannot be more than one top-level element using a "
    "given namespace inside a given annotation element. ", 
    {""
    }
  },

  //10403
  {
    SbgnNamespaceInExtension,
    "The SBGN XML namespace cannot be used in an Extension object",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "Top-level elements within an annotation element cannot use any SBGN "
    "namespace, whether explicitly or implicitly (by failing "
    "to declare any namespace).",
    {""
    }
  },

  //10404
  {
    SbgnMultipleExtensions,
    "Only one Extension object is permitted under a given SBGN object",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "A given SBGN object may contain at most one <annotation> element.",
    {""
    }
  },

  //10801
  {
    SbgnNotesNotInXHTMLNamespace,
    "Notes must be placed in the XHTML XML namespace",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "The contents of the <notes> element must be explicitly placed in the "
    "XHTML XML namespace.", 
    {""
    }
  },

  //10802
  {
    SbgnNotesContainsXMLDecl,
    "XML declarations are not permitted in Notes objects",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML declaration "
    "(i.e., a string of the form \"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\" "
    "or similar).",
    {""
    }
  },

  //10803
  {
    SbgnNotesContainsDOCTYPE,
    "XML DOCTYPE elements are not permitted in Notes objects",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "The contents of the <notes> element must not contain an XML DOCTYPE "
    "declaration (i.e., a string beginning with the characters \"<!DOCTYPE\". ",
    {""
    }
  },

  //10804
  {
    SbgnInvalidNotesContent,
    "Invalid notes content",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "Invalid contents in a <notes> element. ",
    {""
    }
  },

  //10805
  {
    SbgnOnlyOneNotesElementAllowed,
    "Only one Notes subobject is permitted on a given SBGN object",
    LIBSBGN_CAT_SBGN,
    LIBSBGN_SEV_ERROR,
    "A given SBGN object may contain at most one <notes> element. ",
    {""
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  SBGN specific errors.
   * ----------------------------------------------------------------------- */

  // 10101
  { SbgnmlNSUndeclared,
    "The Sbgnml namespace is not correctly declared.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "To conform to the Package specification for SBML Level 0 Version 2, an "
    "SBML document must declare "
    "'http://www.sbml.org/sbml/level0/version2/sbgnml/version0' as the "
    "XMLNamespace to use for elements of this package.",
    { "L3V1 Sbgnml V1 Section 3.1"
    }
  },

  // 10102
  { SbgnmlElementNotInNs,
    "Element not in Sbgnml namespace",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "Wherever they appear in an SBML document, elements and attributes from the "
    "Package must use the "
    "'http://www.sbml.org/sbml/level0/version2/sbgnml/version0' namespace, "
    "declaring so either explicitly or implicitly.",
    { "L3V1 Sbgnml V1 Section 3.1"
    }
  },

  // 10301
  { SbgnmlDuplicateComponentId,
    "Duplicate 'id' attribute value",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "(Extends validation rule #10301 in the SBML Level 3 Core specification. TO "
    "DO list scope of ids)",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 10302
  { SbgnmlIdSyntaxRule,
    "Invalid SId syntax",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of a 'sbgnml:id' must conform to the syntax of the <sbml> data "
    "type 'SId'",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 10303
  { SbgnInvalidMetaidSyntax,
    "Invalid SId syntax",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of a 'sbgnml:metaid' must conform to the syntax of the XML Type "
    "ID",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20101
  { InvalidNamespaceOnSbgn,
    "Invalid namespace",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "Invalid namespace declared.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20102
  { AllowedAttributes,
    "Allowed attributes",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "Allowed attributes",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20103
  { SbgnEmptyListElement,
    "No empty listOf",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "No empty lists",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20201
  { SbgnmlPointAllowedCoreAttributes,
    "Core attributes allowed on <point>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <point> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <point>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20202
  { SbgnmlPointAllowedCoreElements,
    "Core elements allowed on <point>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <point> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <point>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20203
  { SbgnmlPointAllowedAttributes,
    "Attributes allowed on <point>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <point> object must have the required attributes 'sbgnml:x' and "
    "'sbgnml:y'. No other attributes from the SBML Level 3 Systems Biology "
    "Graphical Notation - Markup Language namespaces are permitted on a <point> "
    "object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20204
  { SbgnmlPointAllowedElements,
    "Elements allowed on <point>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <point> object may contain one and only one instance of the "
    "<listOfPoints> element. No other elements from the SBML Level 3 Systems "
    "Biology Graphical Notation - Markup Language namespaces are permitted on a "
    "<point> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20205
  { SbgnmlPointXMustBeDouble,
    "The 'x' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:x' on a <point> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20206
  { SbgnmlPointYMustBeDouble,
    "The 'y' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:y' on a <point> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20301
  { SbgnmlBBoxAllowedCoreAttributes,
    "Core attributes allowed on <bBox>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <bBox> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <bBox>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20302
  { SbgnmlBBoxAllowedCoreElements,
    "Core elements allowed on <bBox>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <bBox> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <bBox>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20303
  { SbgnmlBBoxAllowedAttributes,
    "Attributes allowed on <bBox>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <bBox> object must have the required attributes 'sbgnml:x', 'sbgnml:y', "
    "'sbgnml:width' and 'sbgnml:height'. No other attributes from the SBML "
    "Level 3 Systems Biology Graphical Notation - Markup Language namespaces "
    "are permitted on a <bBox> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20304
  { SbgnmlBBoxXMustBeDouble,
    "The 'x' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:x' on a <bBox> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20305
  { SbgnmlBBoxYMustBeDouble,
    "The 'y' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:y' on a <bBox> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20306
  { SbgnmlBBoxWidthMustBeDouble,
    "The 'width' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:width' on a <bBox> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20307
  { SbgnmlBBoxHeightMustBeDouble,
    "The 'height' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:height' on a <bBox> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20401
  { SbgnmlLabelAllowedCoreAttributes,
    "Core attributes allowed on <label>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <label> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <label>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20402
  { SbgnmlLabelAllowedCoreElements,
    "Core elements allowed on <label>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <label> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <label>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20403
  { SbgnmlLabelAllowedAttributes,
    "Attributes allowed on <label>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <label> object must have the required attribute 'sbgnml:text', and may "
    "have the optional attribute 'sbgnml:id'. No other attributes from the SBML "
    "Level 3 Systems Biology Graphical Notation - Markup Language namespaces "
    "are permitted on a <label> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20404
  { SbgnmlLabelAllowedElements,
    "Elements allowed on <label>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <label> object may contain one and only one instance of the SbgnBBox "
    "element. No other elements from the SBML Level 3 Systems Biology Graphical "
    "Notation - Markup Language namespaces are permitted on a <label> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20405
  { SbgnmlLabelTextMustBeString,
    "The 'text' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:text' on a <label> must have a value of data type "
    "'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20501
  { SbgnmlMapAllowedCoreAttributes,
    "Core attributes allowed on <map>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <map> object may have the optional SBML Level 3 Core attributes 'metaid' "
    "and 'sboTerm'. No other attributes from the SBML Level 3 Core namespaces "
    "are permitted on a <map>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20502
  { SbgnmlMapAllowedCoreElements,
    "Core elements allowed on <map>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <map> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <map>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20503
  { SbgnmlMapAllowedAttributes,
    "Attributes allowed on <map>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <map> object must have the required attribute 'sbgnml:id', and may have "
    "the optional attributes 'sbgnml:language' and 'sbgnml:mapVersion'. No "
    "other attributes from the SBML Level 3 Systems Biology Graphical Notation "
    "- Markup Language namespaces are permitted on a <map> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20504
  { SbgnmlMapAllowedElements,
    "Elements allowed on <map>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <map> object may contain one and only one instance of each of the "
    "SbgnBBox, <listOfGlyphs,> <listOfArcs> and <listOfArcGroups> elements. No "
    "other elements from the SBML Level 3 Systems Biology Graphical Notation - "
    "Markup Language namespaces are permitted on a <map> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20505
  { SbgnmlMapIdMustBeString,
    "The 'id' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:id' on a <map> must have a value of XML data type "
    "'ID'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20506
  { SbgnmlMapLanguageMustBeLanguageEnum,
    "The 'language' attribute must be LanguageEnum.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:language' of a <map> object must "
    "conform to the syntax of SBML data type 'Language' and may only take on "
    "the allowed values of 'Language' defined in SBML; that is, the value must "
    "be one of the following: 'process description', 'entity relationship' or "
    "'activity flow'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20507
  { SbgnmlMapMapVersionMustBeMapTypeEnum,
    "The 'mapVersion' attribute must be MapTypeEnum.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:mapVersion' of a <map> object must "
    "conform to the syntax of SBML data type 'MapType' and may only take on the "
    "allowed values of 'MapType' defined in SBML; that is, the value must be "
    "one of the following: 'http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3', "
    "'http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2', "
    "'http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1', "
    "'http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0', "
    "'http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1', 'http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2', "
    "'http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2', "
    "'http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1', "
    "'http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0', "
    "'http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1', 'http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2', "
    "'http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0' "
    "or 'http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20601
  { SbgnmlDocumentAllowedCoreAttributes,
    "Core attributes allowed on <document>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20602
  { SbgnmlDocumentAllowedCoreElements,
    "Core elements allowed on <document>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <document> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <document>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20603
  { SbgnmlDocumentAllowedElements,
    "Elements allowed on <document>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <document> object must contain one and only one instance of the "
    "<listOfMaps> element. No other elements from the SBML Level 3 Systems "
    "Biology Graphical Notation - Markup Language namespaces are permitted on a "
    "<document> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20604
  { SbgnmlDocumentEmptyReqdLOElements,
    "No Empty ListOf elements allowed on <document>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The <sbgnListOfMaps> subobject on a <document> object must not be empty.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20605
  { SbgnmlDocumentLOMapsAllowedCoreElements,
    "Core elements allowed on <listOfMaps>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "Apart from the general notes and annotations subobjects permitted on all "
    "SBML objects, a <listOfMaps> container object may only contain <map> "
    "objects.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20606
  { SbgnmlDocumentLOMapsAllowedCoreAttributes,
    "Core attributes allowed on <listOfMaps>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <listOfMaps> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <listOfMaps> object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20701
  { SbgnmlGlyphAllowedCoreAttributes,
    "Core attributes allowed on <glyph>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <glyph> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <glyph>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20702
  { SbgnmlGlyphAllowedCoreElements,
    "Core elements allowed on <glyph>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <glyph> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <glyph>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20703
  { SbgnmlGlyphAllowedAttributes,
    "Attributes allowed on <glyph>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <glyph> object must have the required attributes 'sbgnml:id' and "
    "'sbgnml:clazz', and may have the optional attributes "
    "'sbgnml:compartmentRef', 'sbgnml:compartmentOrder', 'sbgnml:orientation', "
    "'sbgnml:mapRef' and 'sbgnml:tagRef'. No other attributes from the SBML "
    "Level 3 Systems Biology Graphical Notation - Markup Language namespaces "
    "are permitted on a <glyph> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20704
  { SbgnmlGlyphAllowedElements,
    "Elements allowed on <glyph>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <glyph> object must contain one and only one instance of the SbgnBBox "
    "element, and may contain one and only one instance of each of the "
    "SbgnLabel, SbgnState, SbgnGlyph, SbgnCallout, SbgnEntity, <listOfGlyphs> "
    "and <listOfPorts> elements. No other elements from the SBML Level 3 "
    "Systems Biology Graphical Notation - Markup Language namespaces are "
    "permitted on a <glyph> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20705
  { SbgnmlGlyphClazzMustBeString,
    "The 'clazz' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:clazz' on a <glyph> must have a value of data type "
    "'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20706
  { SbgnmlGlyphCompartmentRefMustBeGlyph,
    "The attribute 'compartmentRef' must point to Glyph object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:compartmentRef' of a <glyph> object "
    "must be the identifier of an existing <glyph> object defined in the "
    "enclosing <model> object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20707
  { SbgnmlGlyphCompartmentOrderMustBeDouble,
    "The 'compartmentOrder' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:compartmentOrder' on a <glyph> must have a value of "
    "data type 'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20708
  { SbgnmlGlyphOrientationMustBeOrientationEnum,
    "The 'orientation' attribute must be OrientationEnum.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:orientation' of a <glyph> object must "
    "conform to the syntax of SBML data type 'Orientation' and may only take on "
    "the allowed values of 'Orientation' defined in SBML; that is, the value "
    "must be one of the following: 'horizontal', 'vertical', 'left', 'right', "
    "'up' or 'down'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20709
  { SbgnmlGlyphMapRefMustBeMap,
    "The attribute 'mapRef' must point to Map object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:mapRef' of a <glyph> object must be the "
    "identifier of an existing <map> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20710
  { SbgnmlGlyphTagRefMustBeGlyph,
    "The attribute 'tagRef' must point to Glyph object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:tagRef' of a <glyph> object must be the "
    "identifier of an existing <glyph> object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20801
  { SbgnmlPortAllowedCoreAttributes,
    "Core attributes allowed on <port>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <port> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <port>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20802
  { SbgnmlPortAllowedCoreElements,
    "Core elements allowed on <port>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <port> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <port>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20803
  { SbgnmlPortAllowedAttributes,
    "Attributes allowed on <port>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <port> object must have the required attributes 'sbgnml:id', 'sbgnml:x' "
    "and 'sbgnml:y'. No other attributes from the SBML Level 3 Systems Biology "
    "Graphical Notation - Markup Language namespaces are permitted on a <port> "
    "object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20804
  { SbgnmlPortIdMustBeString,
    "The 'id' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:id' on a <port> must have a value of XML data type "
    "'ID'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20805
  { SbgnmlPortXMustBeDouble,
    "The 'x' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:x' on a <port> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20806
  { SbgnmlPortYMustBeDouble,
    "The 'y' attribute must be Double.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:y' on a <port> must have a value of data type "
    "'double'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20901
  { SbgnmlArcAllowedCoreAttributes,
    "Core attributes allowed on <arc>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arc> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <arc>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20902
  { SbgnmlArcAllowedCoreElements,
    "Core elements allowed on <arc>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arc> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <arc>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20903
  { SbgnmlArcAllowedAttributes,
    "Attributes allowed on <arc>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arc> object must have the required attributes 'sbgnml:id', "
    "'sbgnml:clazz', 'sbgnml:source' and 'sbgnml:target'. No other attributes "
    "from the SBML Level 3 Systems Biology Graphical Notation - Markup Language "
    "namespaces are permitted on an <arc> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20904
  { SbgnmlArcAllowedElements,
    "Elements allowed on <arc>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arc> object must contain one and only one instance of each of the "
    "SbgnPoint and <sbgnPoint> elements, and may contain one and only one "
    "instance of each of the <listOfGlyphs,> <listOfPoints> and <listOfPorts> "
    "elements. No other elements from the SBML Level 3 Systems Biology "
    "Graphical Notation - Markup Language namespaces are permitted on an <arc> "
    "object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20905
  { SbgnmlArcIdMustBeString,
    "The 'id' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:id' on an <arc> must have a value of XML data type "
    "'ID'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20906
  { SbgnmlArcClazzMustBeString,
    "The 'clazz' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:clazz' on an <arc> must have a value of data type "
    "'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20907
  { SbgnmlArcSourceMustBeSBase,
    "The attribute 'source' must point to SBase object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:source' of an <arc> object must be the "
    "'metaid' of an existing 'SBase' object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 20908
  { SbgnmlArcTargetMustBeSBase,
    "The attribute 'target' must point to SBase object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:target' of an <arc> object must be the "
    "'metaid' of an existing 'SBase' object defined in the enclosing <model> "
    "object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21001
  { SbgnmlStateAllowedCoreAttributes,
    "Core attributes allowed on <state>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <state> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <state>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21002
  { SbgnmlStateAllowedCoreElements,
    "Core elements allowed on <state>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <state> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <state>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21003
  { SbgnmlStateAllowedAttributes,
    "Attributes allowed on <state>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <state> object may have the optional attributes 'sbgnml:variable' and "
    "'sbgnml:value'. No other attributes from the SBML Level 3 Systems Biology "
    "Graphical Notation - Markup Language namespaces are permitted on a <state> "
    "object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21004
  { SbgnmlStateVariableMustBeString,
    "The 'variable' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:variable' on a <state> must have a value of data "
    "type 'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21005
  { SbgnmlStateValueMustBeString,
    "The 'value' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:value' on a <state> must have a value of data type "
    "'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21101
  { SbgnmlCalloutAllowedCoreAttributes,
    "Core attributes allowed on <callout>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <callout> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on a <callout>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21102
  { SbgnmlCalloutAllowedCoreElements,
    "Core elements allowed on <callout>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <callout> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on a <callout>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21103
  { SbgnmlCalloutAllowedAttributes,
    "Attributes allowed on <callout>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <callout> object may have the optional attribute 'sbgnml:target'. No "
    "other attributes from the SBML Level 3 Systems Biology Graphical Notation "
    "- Markup Language namespaces are permitted on a <callout> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21104
  { SbgnmlCalloutAllowedElements,
    "Elements allowed on <callout>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "A <callout> object must contain one and only one instance of the SbgnPoint "
    "element. No other elements from the SBML Level 3 Systems Biology Graphical "
    "Notation - Markup Language namespaces are permitted on a <callout> object. "
    "",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21105
  { SbgnmlCalloutTargetMustBeSBase,
    "The attribute 'target' must point to SBase object.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The value of the attribute 'sbgnml:target' of a <callout> object must be "
    "the 'metaid' of an existing 'SBase' object defined in the enclosing "
    "<model> object.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21201
  { SbgnmlEntityAllowedCoreAttributes,
    "Core attributes allowed on <entity>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <entity> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <entity>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21202
  { SbgnmlEntityAllowedCoreElements,
    "Core elements allowed on <entity>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <entity> object may have the optional SBML Level 3 Core subobjects for "
    "notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <entity>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21203
  { SbgnmlEntityAllowedAttributes,
    "Attributes allowed on <entity>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <entity> object must have the required attribute 'sbgnml:name'. No "
    "other attributes from the SBML Level 3 Systems Biology Graphical Notation "
    "- Markup Language namespaces are permitted on an <entity> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21204
  { SbgnmlEntityNameMustBeString,
    "The 'name' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:name' on an <entity> must have a value of data type "
    "'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21301
  { SbgnmlArcGroupAllowedCoreAttributes,
    "Core attributes allowed on <arcGroup>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arcGroup> object may have the optional SBML Level 3 Core attributes "
    "'metaid' and 'sboTerm'. No other attributes from the SBML Level 3 Core "
    "namespaces are permitted on an <arcGroup>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21302
  { SbgnmlArcGroupAllowedCoreElements,
    "Core elements allowed on <arcGroup>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arcGroup> object may have the optional SBML Level 3 Core subobjects "
    "for notes and annotations. No other elements from the SBML Level 3 Core "
    "namespaces are permitted on an <arcGroup>.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21303
  { SbgnmlArcGroupAllowedAttributes,
    "Attributes allowed on <arcGroup>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arcGroup> object may have the optional attribute 'sbgnml:clazz'. No "
    "other attributes from the SBML Level 3 Systems Biology Graphical Notation "
    "- Markup Language namespaces are permitted on an <arcGroup> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21304
  { SbgnmlArcGroupAllowedElements,
    "Elements allowed on <arcGroup>.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "An <arcGroup> object may contain one and only one instance of each of the "
    "<listOfGlyphs> and <listOfArcs> elements. No other elements from the SBML "
    "Level 3 Systems Biology Graphical Notation - Markup Language namespaces "
    "are permitted on an <arcGroup> object. ",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  // 21305
  { SbgnmlArcGroupClazzMustBeString,
    "The 'clazz' attribute must be String.",
    LIBSBGN_CAT_GENERAL_CONSISTENCY,
    LIBSBGN_SEV_ERROR,
    "The attribute 'sbgnml:clazz' on an <arcGroup> must have a value of data "
    "type 'string'.",
    { "L3V1 Sbgnml V1 Section"
    }
  },

  /* --------------------------------------------------------------------------
   * Boundary marker.  Application-specific codes should begin at 100000.
   * ----------------------------------------------------------------------- */

  //99994
  {
    SbgnUnknownCoreAttribute,
    "Unknown attribute",
    LIBSBGN_CAT_INTERNAL,
    LIBSBGN_SEV_ERROR,
    "An unknown attribute has been found.", 
    {""
    }
   },

  //99999
  {
    SbgnCodesUpperBound,
    "Upper boundary of libSBGN-specific diagnostic codes",
    LIBSBGN_CAT_INTERNAL,
    LIBSBGN_SEV_NOT_APPLICABLE,
    "Application-specific codes should begin at 100000.", 
    {""
    }
   }
};

LIBSBGN_CPP_NAMESPACE_END
/** @endcond */



#endif /* !SbgnErrorTable_H__ */


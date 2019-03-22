/**
 * @file SbgnError.h
 * @brief Definition of the SbgnError class.
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


#ifndef SbgnError_h
#define SbgnError_h

#include <sbgn/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sbgn/SbgnNamespaces.h>


LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * @enum SbgnErrorCode_t
 * Codes for all SBGN-level errors and warnings from the core specification.
 */
typedef enum
{
  SbgnUnknown                      = 10000 /*!< Encountered unknown internal libSBGN error. */
, SbgnNotUTF8                               = 10001 /*!< File does not use UTF-8 encoding. */
, SbgnUnrecognizedElement                   = 10002 /*!< Encountered unrecognized element. */
, SbgnNotSchemaConformant                   = 10003 /*!< Document does not conform to the SBGN XML schema. */
, SbgnInvalidMathElement                    = 10201
, SbgnMissingExtensionNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, SbgnDuplicateExtensionNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SbgnNamespaceInExtension             = 10403 /*!< The SBGN XML namespace cannot be used in an Extension object. */
, SbgnMultipleExtensions                   = 10404 /*!< Only one Extension object is permitted under a given SBGN object. */
, SbgnExtensionNotElement                  = 10405
, SbgnNotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, SbgnNotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, SbgnNotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, SbgnInvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, SbgnOnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given SBGN object. */
, SbgnmlNSUndeclared      = 10101
, SbgnmlElementNotInNs      = 10102
, SbgnmlDuplicateComponentId      = 10301
, SbgnmlIdSyntaxRule      = 10302
, SbgnInvalidMetaidSyntax      = 10303
, InvalidNamespaceOnSbgn      = 20101
, AllowedAttributes      = 20102
, SbgnEmptyListElement      = 20103
, SbgnmlPointAllowedCoreAttributes      = 20201
, SbgnmlPointAllowedCoreElements      = 20202
, SbgnmlPointAllowedAttributes      = 20203
, SbgnmlPointAllowedElements      = 20204
, SbgnmlPointXMustBeDouble      = 20205
, SbgnmlPointYMustBeDouble      = 20206
, SbgnmlBBoxAllowedCoreAttributes      = 20301
, SbgnmlBBoxAllowedCoreElements      = 20302
, SbgnmlBBoxAllowedAttributes      = 20303
, SbgnmlBBoxXMustBeDouble      = 20304
, SbgnmlBBoxYMustBeDouble      = 20305
, SbgnmlBBoxWidthMustBeDouble      = 20306
, SbgnmlBBoxHeightMustBeDouble      = 20307
, SbgnmlLabelAllowedCoreAttributes      = 20401
, SbgnmlLabelAllowedCoreElements      = 20402
, SbgnmlLabelAllowedAttributes      = 20403
, SbgnmlLabelAllowedElements      = 20404
, SbgnmlLabelTextMustBeString      = 20405
, SbgnmlMapAllowedCoreAttributes      = 20501
, SbgnmlMapAllowedCoreElements      = 20502
, SbgnmlMapAllowedAttributes      = 20503
, SbgnmlMapAllowedElements      = 20504
, SbgnmlMapIdMustBeString      = 20505
, SbgnmlMapLanguageMustBeLanguageEnum      = 20506
, SbgnmlMapMapVersionMustBeMapTypeEnum      = 20507
, SbgnmlDocumentAllowedCoreAttributes      = 20601
, SbgnmlDocumentAllowedCoreElements      = 20602
, SbgnmlDocumentAllowedElements      = 20603
, SbgnmlDocumentEmptyReqdLOElements      = 20604
, SbgnmlDocumentLOMapsAllowedCoreElements      = 20605
, SbgnmlDocumentLOMapsAllowedCoreAttributes      = 20606
, SbgnmlGlyphAllowedCoreAttributes      = 20701
, SbgnmlGlyphAllowedCoreElements      = 20702
, SbgnmlGlyphAllowedAttributes      = 20703
, SbgnmlGlyphAllowedElements      = 20704
, SbgnmlGlyphClazzMustBeString      = 20705
, SbgnmlGlyphCompartmentRefMustBeGlyph      = 20706
, SbgnmlGlyphCompartmentOrderMustBeDouble      = 20707
, SbgnmlGlyphOrientationMustBeOrientationEnum      = 20708
, SbgnmlGlyphMapRefMustBeMap      = 20709
, SbgnmlGlyphTagRefMustBeGlyph      = 20710
, SbgnmlPortAllowedCoreAttributes      = 20801
, SbgnmlPortAllowedCoreElements      = 20802
, SbgnmlPortAllowedAttributes      = 20803
, SbgnmlPortIdMustBeString      = 20804
, SbgnmlPortXMustBeDouble      = 20805
, SbgnmlPortYMustBeDouble      = 20806
, SbgnmlArcAllowedCoreAttributes      = 20901
, SbgnmlArcAllowedCoreElements      = 20902
, SbgnmlArcAllowedAttributes      = 20903
, SbgnmlArcAllowedElements      = 20904
, SbgnmlArcIdMustBeString      = 20905
, SbgnmlArcClazzMustBeString      = 20906
, SbgnmlArcSourceMustBeSBase      = 20907
, SbgnmlArcTargetMustBeSBase      = 20908
, SbgnmlStateAllowedCoreAttributes      = 21001
, SbgnmlStateAllowedCoreElements      = 21002
, SbgnmlStateAllowedAttributes      = 21003
, SbgnmlStateVariableMustBeString      = 21004
, SbgnmlStateValueMustBeString      = 21005
, SbgnmlCalloutAllowedCoreAttributes      = 21101
, SbgnmlCalloutAllowedCoreElements      = 21102
, SbgnmlCalloutAllowedAttributes      = 21103
, SbgnmlCalloutAllowedElements      = 21104
, SbgnmlCalloutTargetMustBeSBase      = 21105
, SbgnmlEntityAllowedCoreAttributes      = 21201
, SbgnmlEntityAllowedCoreElements      = 21202
, SbgnmlEntityAllowedAttributes      = 21203
, SbgnmlEntityNameMustBeString      = 21204
, SbgnmlArcGroupAllowedCoreAttributes      = 21301
, SbgnmlArcGroupAllowedCoreElements      = 21302
, SbgnmlArcGroupAllowedAttributes      = 21303
, SbgnmlArcGroupAllowedElements      = 21304
, SbgnmlArcGroupClazzMustBeString      = 21305
, SbgnUnknownCoreAttribute                  = 99994 /*!< Encountered an unknown attribute in the SBGN Core namespace. */
, SbgnCodesUpperBound                   = 99999 /*!< Upper boundary of libSBGN-specific diagnostic codes. */
} SbgnErrorCode_t;


/**
 * @enum SbgnErrorCategory_t
 * Category codes for SbgnError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SbgnError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * SBGN problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum
{
    LIBSBGN_CAT_INTERNAL = LIBSBML_CAT_INTERNAL,
    LIBSBGN_CAT_SYSTEM = LIBSBML_CAT_SYSTEM,
    LIBSBGN_CAT_XML = LIBSBML_CAT_XML,

    LIBSBGN_CAT_SBGN = (LIBSBGN_CAT_XML + 1)
    /*!< General SBGN error  not falling into another category below. */

  , LIBSBGN_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general SBGN
     * constructs. */

  , LIBSBGN_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model. */

  , LIBSBGN_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the SBGN specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSBGN_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSBGN's
     * internal representation of SBGN constructs. (These are tests
     * performed by libSBGN and do not have equivalent SBGN validation
     * rules.)  */

} SbgnErrorCategory_t;


/**
 * @enum SbgnErrorSeverity_t
 * Severity codes for SbgnError diagnostics.
 *
 * The only publicly-reported values of this type are the four from #XMLErrorSeverity_t.
 * All other values are used internally only, with translation of those
 * codes done in SbgnError.cpp
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygenLibsbgnInternal **/

  /* The following are used internally in SbgnErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SbgnError.cpp.
   */
    LIBSBGN_SEV_WARNING = LIBSBML_SEV_WARNING,
    LIBSBGN_SEV_ERROR = LIBSBML_SEV_ERROR,
    LIBSBGN_SEV_FATAL = LIBSBML_SEV_FATAL,

    LIBSBGN_SEV_SCHEMA_ERROR    = (LIBSBGN_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the SBGN XML
     * Schema.  The content is not valid SBGN. */

  , LIBSBGN_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of SBGN, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSBGN
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSBGN_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of SBGN but not others. */

  /** @endcond **/
} SbgnErrorSeverity_t;

END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSBGN_CPP_NAMESPACE_BEGIN

class LIBSBGN_EXTERN SbgnError : public XMLError
{
public:

  /**
   * Creates a new SbgnError to report that something occurred during SBGN
   * processing.
   *
   * When a libSBGN operation on SBGN content results in a warning, error
   * or other diagnostic, the issue is reported as an SbgnError object.
   * SbgnError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SbgnErrorCode_t">
   * SbgnErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsbgnConstants.html".  See the <a class="el"
   * href="#SbgnErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsbgn libsbgn@endlink.  See the <a class="el"
   * href="#SbgnErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SbgnErrorCode_t">SbgnErrorCode_t</a>, the
   * SbgnError class assumes the error is a low-level system or SBGN layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SbgnErrorCode_t">SbgnErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SbgnErrorSeverity_t">SbgnErrorSeverity_t</a> and <a class="el"
   * href="#SbgnErrorCategory_t">SbgnErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SbgnError class
   * assumes the error is a low-level system or SBGN layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSBGN defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SbgnError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SbgnError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SbgnError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SbgnErrorSeverity_t">SbgnErrorSeverity_t</a> and <a class="el"
   * href="#SbgnErrorCategory_t">SbgnErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SbgnError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SbgnErrorCode_t">SbgnErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SbgnErrorCode_t">SbgnErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SbgnErrorSeverity_t">SbgnErrorSeverity_t</a> and <a class="el"
   * href="#SbgnErrorCategory_t">SbgnErrorCategory_t</a>, but their own
   * special values) for @p severity and
   * @p category. @else As mentioned above,
   * there are additional constants defined for <a class="el"
   * href="#SbgnErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SbgnErrorCategory_t">standard category</a> codes, and every predefined
   * error in libSBGN has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSBGN_SEV_</code> and <code>LIBSBGN_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * SBGN-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SbgnError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of SBGN.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the SBGN Level of the SBGN model
   *
   * @param version the SBGN Version within the Level of the SBGN model
   *
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SbgnError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   *
   * @param line an unsigned int, the line number at which the error occured.
   *
   * @param column an unsigned int, the column number at which the error occured.
   *
   * @param severity an integer indicating severity of the error.
   *
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  SbgnError
  (
     const unsigned int errorId  = 0
   , const unsigned int level    = SBGN_DEFAULT_LEVEL
   , const unsigned int version  = SBGN_DEFAULT_VERSION
   , const std::string& details  = ""
   , const unsigned int line     = 0
   , const unsigned int column   = 0
   , const unsigned int severity = LIBSBGN_SEV_ERROR
   , const unsigned int category = LIBSBGN_CAT_SBGN
  );


  /**
   * Copy constructor; creates a copy of this SbgnError.
   */
  SbgnError(const SbgnError& orig);

  /**
   * Destroys this SbgnError.
   */
  virtual ~SbgnError();


#ifndef SWIG

  /** @cond doxygenLibsbgnInternal **/

  /**
   * Creates and returns a deep copy of this SbgnError object.
   *
   * @return the (deep) copy of this SbgnError object.
   */
  virtual SbgnError* clone() const;

  /**
   * Outputs this SbgnError to stream in the following format (and followed
   * by a newline):
   *
   *   line: (error id) message
   *
   * @param stream the output stream to write to.
   */
  virtual void print(std::ostream& stream) const;

  /** @endcond **/

#endif  /* !SWIG */

protected:
  /** @cond doxygenLibsbgnInternal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  /** @endcond **/
};

LIBSBGN_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SbgnError_h */

/**
 * @file SbgnMap.h
 * @brief Definition of the SbgnMap class.
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
 * @class SbgnMap
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnMap class.
 */

/**
 * <!-- ~ ~ ~ ~ ~ Start of common documentation strings ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
 * The following text is used as common documentation blocks copied multiple
 * times elsewhere in this file. The use of @class is a hack needed because
 * Doxygen's @copydetails command has limited functionality. Symbols
 * beginning with "doc_" are marked as ignored in our Doxygen configuration.
 * ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ -->
 *
 *
 * @class doc_sbgnmap_language
 *
 * @par
 * The attribute "language" on a SbgnMap object is used to TODO:add explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sbgnml specification, the following are the
 * allowable values for "language":
 * <ul>
 * <li> @c "process description", TODO:add description
 *
 * <li> @c "entity relationship", TODO:add description
 *
 * <li> @c "activity flow", TODO:add description
 *
 * </ul>
 *
 * @class doc_sbgnmap_mapVersion
 *
 * @par
 * The attribute "mapVersion" on a SbgnMap object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sbgnml specification, the following are the
 * allowable values for "mapVersion":
 * <ul>
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0", TODO:add description
 *
 * <li> @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1", TODO:add description
 *
 * </ul>
 */


#ifndef SbgnMap_H__
#define SbgnMap_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>
#include <sbgn/common/SbgnEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnBBox.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbgn/SbgnListOfArcs.h>
#include <sbgn/SbgnListOfArcGroups.h>
#include <sbml/common/libsbml-namespace.h>

LIBSBML_CPP_NAMESPACE_BEGIN
class LocalRenderInformation;
LIBSBML_CPP_NAMESPACE_END


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnMap : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  Language_t mLanguage;
  SbgnBBox* mBBox;
  SbgnListOfGlyphs mGlyphs;
  SbgnListOfArcs mArcs;
  SbgnListOfArcGroups mArcGroups;
  MapType_t mMapVersion;

  /** @endcond */

public:

  /**
   * Creates a new SbgnMap using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnMap.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnMap.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnMap(unsigned int level = SBGN_DEFAULT_LEVEL,
          unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnMap using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnMap(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnMap.
   *
   * @param orig the SbgnMap instance to copy.
   */
  SbgnMap(const SbgnMap& orig);


  /**
   * Assignment operator for SbgnMap.
   *
   * @param rhs the SbgnMap object whose values are to be used as the basis of
   * the assignment.
   */
  SbgnMap& operator=(const SbgnMap& rhs);


  /**
   * Creates and returns a deep copy of this SbgnMap object.
   *
   * @return a (deep) copy of this SbgnMap object.
   */
  virtual SbgnMap* clone() const;


  /**
   * Destructor for SbgnMap.
   */
  virtual ~SbgnMap();


  /**
   * Returns the value of the "id" attribute of this SbgnMap.
   *
   * @return the value of the "id" attribute of this SbgnMap as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "language" attribute of this SbgnMap.
   *
   * @return the value of the "language" attribute of this SbgnMap as a
   * Language_t.
   *
   * @copydetails doc_sbgnmap_language
   * @if clike The value is drawn from the enumeration @ref Language_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_ENTITY_RELATIONSHIP, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_ACTIVITY_FLOW, Language_t}
   * @li @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t}
   */
  Language_t getLanguage() const;


  /**
   * Returns the value of the "language" attribute of this SbgnMap.
   *
   * @return the value of the "language" attribute of this SbgnMap as a string.
   *
   * @copydetails doc_sbgnmap_language
   * The possible values returned by this method are:
   * @li @c "process description"
   * @li @c "entity relationship"
   * @li @c "activity flow"
   * @li @c "invalid Language value"
   */
  std::string getLanguageAsString() const;


  /**
   * Returns the value of the "version" attribute of this SbgnMap.
   *
   * @return the value of the "version" attribute of this SbgnMap as a
   * MapType_t.
   *
   * @copydetails doc_sbgnmap_version
   * @if clike The value is drawn from the enumeration @ref MapType_t @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_3, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_2, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_1, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_0, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V2, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_2, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_1, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_0, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_2, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_0, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1, MapType_t}
   * @li @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t}
   */
  MapType_t getMapVersion() const;


  /**
   * Returns the value of the "version" attribute of this SbgnMap.
   *
   * @return the value of the "version" attribute of this SbgnMap as a string.
   *
   * @copydetails doc_sbgnmap_version
   * The possible values returned by this method are:
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0"
   * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1"
   * @li @c "invalid MapType value"
   */
  std::string getMapVersionAsString() const;


  /**
   * Predicate returning @c true if this SbgnMap's "id" attribute is set.
   *
   * @return @c true if this SbgnMap's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SbgnMap's "language" attribute is set.
   *
   * @return @c true if this SbgnMap's "language" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sbgnmap_language
   */
  bool isSetLanguage() const;


  /**
   * Predicate returning @c true if this SbgnMap's "version" attribute is set.
   *
   * @return @c true if this SbgnMap's "version" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sbgnmap_version
   */
  bool isSetMapVersion() const;


  /**
   * Sets the value of the "id" attribute of this SbgnMap.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "language" attribute of this SbgnMap.
   *
   * @param language @if clike Language_t@else int@endif value of the
   * "language" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_language
   */
  int setLanguage(const Language_t language);


  /**
   * Sets the value of the "language" attribute of this SbgnMap.
   *
   * @param language std::string& of the "language" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_language
   */
  int setLanguage(const std::string& language);


  /**
   * Sets the value of the "version" attribute of this SbgnMap.
   *
   * @param mapVersion @if clike MapType_t@else int@endif value of the
   * "version" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_version
   */
  int setMapVersion(const MapType_t mapVersion);


  /**
   * Sets the value of the "version" attribute of this SbgnMap.
   *
   * @param mapVersion std::string& of the "version" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_version
   */
  int setMapVersion(const std::string& mapVersion);


  /**
   * Unsets the value of the "id" attribute of this SbgnMap.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "language" attribute of this SbgnMap.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_language
   */
  int unsetLanguage();


  /**
   * Unsets the value of the "version" attribute of this SbgnMap.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sbgnmap_version
   */
  int unsetMapVersion();


  /**
   * Returns the value of the "bbox" element of this SbgnMap.
   *
   * @return the value of the "bbox" element of this SbgnMap as a SbgnBBox*.
   */
  const SbgnBBox* getBBox() const;


  /**
   * Returns the value of the "bbox" element of this SbgnMap.
   *
   * @return the value of the "bbox" element of this SbgnMap as a SbgnBBox*.
   */
  SbgnBBox* getBBox();


  /**
   * Predicate returning @c true if this SbgnMap's "bbox" element is set.
   *
   * @return @c true if this SbgnMap's "bbox" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetBBox() const;


  /**
   * Sets the value of the "bbox" element of this SbgnMap.
   *
   * @param bbox SbgnBBox* value of the "bbox" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setBBox(const SbgnBBox* bbox);


  /**
   * Creates a new SbgnBBox object, adds it to this SbgnMap object and returns
   * the SbgnBBox object created.
   *
   * @return a new SbgnBBox object instance.
   */
  SbgnBBox* createBBox();


  /**
   * Unsets the value of the "bbox" element of this SbgnMap.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBBox();


  /**
   * Returns the SbgnListOfGlyphs from this SbgnMap.
   *
   * @return the SbgnListOfGlyphs from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const SbgnListOfGlyphs* getListOfGlyphs() const;


  /**
   * Returns the SbgnListOfGlyphs from this SbgnMap.
   *
   * @return the SbgnListOfGlyphs from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  SbgnListOfGlyphs* getListOfGlyphs();


  /**
   * Get a SbgnGlyph from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  SbgnGlyph* getGlyph(unsigned int n);


  /**
   * Get a SbgnGlyph from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const SbgnGlyph* getGlyph(unsigned int n) const;


  /**
   * Get a SbgnGlyph from the SbgnMap based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnMap with the
   * given @p sid or @c NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  SbgnGlyph* getGlyph(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnMap based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnMap with the
   * given @p sid or @c NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  const SbgnGlyph* getGlyph(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnMap based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnMap based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnMap based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByMapRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnMap based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByMapRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnMap based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByTagRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnMap based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnMap based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByTagRef(const std::string& sid);


  /**
   * Adds a copy of the given SbgnGlyph to this SbgnMap.
   *
   * @param sg the SbgnGlyph object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  int addGlyph(const SbgnGlyph* sg);


  /**
   * Get the number of SbgnGlyph objects in this SbgnMap.
   *
   * @return the number of SbgnGlyph objects in this SbgnMap.
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  unsigned int getNumGlyphs() const;


  /**
   * Creates a new SbgnGlyph object, adds it to this SbgnMap object and returns
   * the SbgnGlyph object created.
   *
   * @return a new SbgnGlyph object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   * @see removeGlyph(unsigned int n)
   */
  SbgnGlyph* createGlyph();


  /**
   * Removes the nth SbgnGlyph from this SbgnMap and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * remove.
   *
   * @return a pointer to the nth SbgnGlyph in this SbgnMap.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(const std::string& sid)
   */
  SbgnGlyph* removeGlyph(unsigned int n);


  /**
   * Removes the SbgnGlyph from this SbgnMap based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * remove.
   *
   * @return the SbgnGlyph in this SbgnMap based on the identifier or NULL if
   * no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see getGlyph(const std::string& sid)
   * @see getGlyph(unsigned int n)
   * @see getNumGlyphs()
   * @see removeGlyph(unsigned int n)
   */
  SbgnGlyph* removeGlyph(const std::string& sid);


  /**
   * Returns the SbgnListOfArcs from this SbgnMap.
   *
   * @return the SbgnListOfArcs from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnListOfArcs* getListOfArcs() const;


  /**
   * Returns the SbgnListOfArcs from this SbgnMap.
   *
   * @return the SbgnListOfArcs from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnListOfArcs* getListOfArcs();


  /**
   * Get a SbgnArc from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in the SbgnListOfArcs within this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* getArc(unsigned int n);


  /**
   * Get a SbgnArc from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in the SbgnListOfArcs within this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnArc* getArc(unsigned int n) const;


  /**
   * Get a SbgnArc from the SbgnMap based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in the SbgnListOfArcs within this SbgnMap with the
   * given @p sid or @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* getArc(const std::string& sid);


  /**
   * Get a SbgnArc from the SbgnMap based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in the SbgnListOfArcs within this SbgnMap with the
   * given @p sid or @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnArc* getArc(const std::string& sid) const;


  /**
   * Adds a copy of the given SbgnArc to this SbgnMap.
   *
   * @param sa the SbgnArc object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  int addArc(const SbgnArc* sa);


  /**
   * Get the number of SbgnArc objects in this SbgnMap.
   *
   * @return the number of SbgnArc objects in this SbgnMap.
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  unsigned int getNumArcs() const;


  /**
   * Creates a new SbgnArc object, adds it to this SbgnMap object and returns
   * the SbgnArc object created.
   *
   * @return a new SbgnArc object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* createArc();


  /**
   * Removes the nth SbgnArc from this SbgnMap and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnArc to remove.
   *
   * @return a pointer to the nth SbgnArc in this SbgnMap.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   */
  SbgnArc* removeArc(unsigned int n);


  /**
   * Removes the SbgnArc from this SbgnMap based on its identifier and returns
   * a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnArc to remove.
   *
   * @return the SbgnArc in this SbgnMap based on the identifier or NULL if no
   * such SbgnArc exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(unsigned int n)
   */
  SbgnArc* removeArc(const std::string& sid);


  /**
   * Returns the SbgnListOfArcGroups from this SbgnMap.
   *
   * @return the SbgnListOfArcGroups from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  const SbgnListOfArcGroups* getListOfArcGroups() const;


  /**
   * Returns the SbgnListOfArcGroups from this SbgnMap.
   *
   * @return the SbgnListOfArcGroups from this SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  SbgnListOfArcGroups* getListOfArcGroups();


  /**
   * Get a SbgnArcGroup from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * retrieve.
   *
   * @return the nth SbgnArcGroup in the SbgnListOfArcGroups within this
   * SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  SbgnArcGroup* getArcGroup(unsigned int n);


  /**
   * Get a SbgnArcGroup from the SbgnMap.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * retrieve.
   *
   * @return the nth SbgnArcGroup in the SbgnListOfArcGroups within this
   * SbgnMap.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  const SbgnArcGroup* getArcGroup(unsigned int n) const;


  /**
   * Adds a copy of the given SbgnArcGroup to this SbgnMap.
   *
   * @param sag the SbgnArcGroup object to add.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
   *
   * @copydetails doc_note_object_is_copied
   *
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  int addArcGroup(const SbgnArcGroup* sag);


  /**
   * Get the number of SbgnArcGroup objects in this SbgnMap.
   *
   * @return the number of SbgnArcGroup objects in this SbgnMap.
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  unsigned int getNumArcGroups() const;


  /**
   * Creates a new SbgnArcGroup object, adds it to this SbgnMap object and
   * returns the SbgnArcGroup object created.
   *
   * @return a new SbgnArcGroup object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   * @see removeArcGroup(unsigned int n)
   */
  SbgnArcGroup* createArcGroup();


  /**
   * Removes the nth SbgnArcGroup from this SbgnMap and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * remove.
   *
   * @return a pointer to the nth SbgnArcGroup in this SbgnMap.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see getArcGroup(const std::string& sid)
   * @see getArcGroup(unsigned int n)
   * @see getNumArcGroups()
   * @see removeArcGroup(const std::string& sid)
   */
  SbgnArcGroup* removeArcGroup(unsigned int n);


  /**
   * Returns the XML element name of this SbgnMap object.
   *
   * For SbgnMap, the XML element name is always @c "map".
   *
   * @return the name of this element, i.e. @c "map".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnMap object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_MAP, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnMap object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnMap have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnMap object are:
   * @li "id"
   */
  virtual bool hasRequiredAttributes() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Write any contained elements
   */
  virtual void writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Accepts the given SbgnVisitor
   */
  virtual bool accept(SbgnVisitor& v) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the parent SbgnDocument
   */
  virtual void setSbgnDocument(SbgnDocument* d);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Connects to child elements
   */
  virtual void connectToChild();

  /** @endcond */




  #ifndef SWIG



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, bool& value)
    const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName, int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           double& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           unsigned int& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to retrieve.
   *
   * @param value, the address of the value to record.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int getAttribute(const std::string& attributeName,
                           std::string& value) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Predicate returning @c true if this SbgnMap's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnMap's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, bool value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName, double value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           unsigned int value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to set.
   *
   * @param value, the value of the attribute to set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int setAttribute(const std::string& attributeName,
                           const std::string& value);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Unsets the value of the "attributeName" attribute of this SbgnMap.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates and returns an new "elementName" object in this SbgnMap.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnMap.
   *
   * @param elementName, the name of the element to create.
   *
   * @param element, pointer to the element to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int addChildObject(const std::string& elementName,
                             const SbgnBase* element);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Removes and returns the new "elementName" object with the given id in this
   * SbgnMap.
   *
   * @param elementName, the name of the element to remove.
   *
   * @param id, the id of the element to remove.
   *
   * @return pointer to the element removed.
   */
  virtual SbgnBase* removeChildObject(const std::string& elementName,
                                      const std::string& id);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the number of "elementName" in this SbgnMap.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnMap.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @param index, unsigned int the index of the object to retrieve.
   *
   * @return pointer to the object.
   */
  virtual SbgnBase* getObject(const std::string& elementName,
                              unsigned int index);

  /** @endcond */




  #endif /* !SWIG */


  /**
   * Returns the first child element that has the given @p id in the model-wide
   * SId namespace, or @c NULL if no such object is found.
   *
   * @param id a string representing the id attribute of the object to
   * retrieve.
   *
   * @return a pointer to the SbgnBase element with the given @p id. If no such
   * object is found, this method returns @c NULL.
   */
  virtual SbgnBase* getElementBySId(const std::string& id);


protected:


  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates a new object from the next XMLToken on the XMLInputStream
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds the expected attributes for this element
   */
  virtual void addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
    ExpectedAttributes& attributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Reads the expected attributes into the member data variables
   */
  virtual void readAttributes(
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                XMLAttributes& attributes,
                              const LIBSBML_CPP_NAMESPACE_QUALIFIER
                                ExpectedAttributes& expectedAttributes);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Writes the attributes to the stream
   */
  virtual void writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


  public:

    std::string getRenderInformationAsString() const;

    LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation* 
                                    getRenderInformation() const;

    void setRenderInformation(
         const LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation *info);

  protected:

    virtual bool readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream);


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SbgnMap_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnMap_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnMap_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnMap_t *
SbgnMap_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnMap_t object.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return a (deep) copy of this SbgnMap_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnMap_clone(const SbgnMap_t* sm);


/**
 * Frees this SbgnMap_t object.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
void
SbgnMap_free(SbgnMap_t* sm);


/**
 * Returns the value of the "id" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SbgnMap_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
char *
SbgnMap_getId(const SbgnMap_t * sm);


/**
 * Returns the value of the "language" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this SbgnMap_t as a
 * Language_t.
 *
 * @copydetails doc_sbgnmap_language
 * @if clike The value is drawn from the enumeration @ref Language_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SBGNML_LANGUAGE_PROCESS_DESCRIPTION, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_ENTITY_RELATIONSHIP, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_ACTIVITY_FLOW, Language_t}
 * @li @sbmlconstant{SBGNML_LANGUAGE_INVALID, Language_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
Language_t
SbgnMap_getLanguage(const SbgnMap_t * sm);


/**
 * Returns the value of the "language" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose language is sought.
 *
 * @return the value of the "language" attribute of this SbgnMap_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sbgnmap_language
 * The possible values returned by this method are:
 * @li @c "process description"
 * @li @c "entity relationship"
 * @li @c "activity flow"
 * @li @c "invalid Language value"
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
char *
SbgnMap_getLanguageAsString(const SbgnMap_t * sm);


/**
 * Returns the value of the "version" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose version is sought.
 *
 * @return the value of the "version" attribute of this SbgnMap_t as a
 * MapType_t.
 *
 * @copydetails doc_sbgnmap_version
 * @if clike The value is drawn from the enumeration @ref MapType_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_3, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_2, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_1, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1_0, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_PD_L1_V1, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V2, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_2, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_1, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1_0, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_ER_L1_V1, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_2, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1_0, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_AF_L1_V1, MapType_t}
 * @li @sbmlconstant{SBGNML_MAPTYPE_INVALID, MapType_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
MapType_t
SbgnMap_getMapVersion(const SbgnMap_t * sm);


/**
 * Returns the value of the "version" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose version is sought.
 *
 * @return the value of the "version" attribute of this SbgnMap_t as a const
 * char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sbgnmap_version
 * The possible values returned by this method are:
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.3"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.2"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.1"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1.0"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.pd.level-1.version-1"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-2"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.2"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.1"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1.0"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.er.level-1.version-1"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.2"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1.0"
 * @li @c "http://identifiers.org/combine.specifications/sbgn.af.level-1.version-1"
 * @li @c "invalid MapType value"
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
char *
SbgnMap_getMapVersionAsString(const SbgnMap_t * sm);


/**
 * Predicate returning @c 1 (true) if this SbgnMap_t's "id" attribute is set.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return @c 1 (true) if this SbgnMap_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetId(const SbgnMap_t * sm);


/**
 * Predicate returning @c 1 (true) if this SbgnMap_t's "language" attribute is
 * set.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return @c 1 (true) if this SbgnMap_t's "language" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sbgnmap_language
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetLanguage(const SbgnMap_t * sm);


/**
 * Predicate returning @c 1 (true) if this SbgnMap_t's "version" attribute is
 * set.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return @c 1 (true) if this SbgnMap_t's "version" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sbgnmap_version
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetMapVersion(const SbgnMap_t * sm);


/**
 * Sets the value of the "id" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setId(SbgnMap_t * sm, const char * id);


/**
 * Sets the value of the "language" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param language Language_t value of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_language
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setLanguage(SbgnMap_t * sm, Language_t language);


/**
 * Sets the value of the "language" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param language const char * of the "language" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_language
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setLanguageAsString(SbgnMap_t * sm, const char * language);


/**
 * Sets the value of the "version" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param mapVersion MapType_t value of the "version" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_version
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setMapVersion(SbgnMap_t * sm, MapType_t mapVersion);


/**
 * Sets the value of the "version" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param mapVersion const char * of the "version" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_version
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setMapVersionAsString(SbgnMap_t * sm, const char * mapVersion);


/**
 * Unsets the value of the "id" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetId(SbgnMap_t * sm);


/**
 * Unsets the value of the "language" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_language
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetLanguage(SbgnMap_t * sm);


/**
 * Unsets the value of the "version" attribute of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnmap_version
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetMapVersion(SbgnMap_t * sm);


/**
 * Returns the value of the "bbox" element of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose bbox is sought.
 *
 * @return the value of the "bbox" element of this SbgnMap_t as a SbgnBBox*.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnMap_getBBox(const SbgnMap_t * sm);


/**
 * Predicate returning @c 1 (true) if this SbgnMap_t's "bbox" element is set.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return @c 1 (true) if this SbgnMap_t's "bbox" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetBBox(const SbgnMap_t * sm);


/**
 * Sets the value of the "bbox" element of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @param bbox SbgnBBox_t* value of the "bbox" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_setBBox(SbgnMap_t * sm, const SbgnBBox_t* bbox);


/**
 * Creates a new SbgnBBox_t object, adds it to this SbgnMap_t object and
 * returns the SbgnBBox_t object created.
 *
 * @param sm the SbgnMap_t structure to which the SbgnBBox_t should be added.
 *
 * @return a new SbgnBBox_t object instance.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnMap_createBBox(SbgnMap_t* sm);


/**
 * Unsets the value of the "bbox" element of this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetBBox(SbgnMap_t * sm);


/**
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose SbgnListOfGlyphs is sought.
 *
 * @return the SbgnListOfGlyphs from this SbgnMap_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnMap_addGlyph()
 * @see SbgnMap_createGlyph()
 * @see SbgnMap_getGlyphById()
 * @see SbgnMap_getGlyph()
 * @see SbgnMap_getNumGlyphs()
 * @see SbgnMap_removeGlyphById()
 * @see SbgnMap_removeGlyph()
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfGlyphs(SbgnMap_t* sm);


/**
 * Get a SbgnGlyph_t from the SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the nth SbgnGlyph_t in the SbgnListOfGlyphs within this SbgnMap.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyph(SbgnMap_t* sm, unsigned int n);


/**
 * Get a SbgnGlyph_t from the SbgnMap_t based on its identifier.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the SbgnGlyph_t in the SbgnListOfGlyphs within this SbgnMap with the
 * given @p sid or @c NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphById(SbgnMap_t* sm, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnMap_t based on the CompartmentRef to which it
 * refers.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the "compartmentRef" attribute of the
 * SbgnGlyph_t object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnMap_t based on the given
 * compartmentRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByCompartmentRef(SbgnMap_t* sm, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnMap_t based on the MapRef to which it refers.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the "mapRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnMap_t based on the given mapRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByMapRef(SbgnMap_t* sm, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnMap_t based on the TagRef to which it refers.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the "tagRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnMap_t based on the given tagRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByTagRef(SbgnMap_t* sm, const char *sid);


/**
 * Adds a copy of the given SbgnGlyph_t to this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to which the SbgnGlyph_t should be added.
 *
 * @param sg the SbgnGlyph_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_addGlyph(SbgnMap_t* sm, const SbgnGlyph_t* sg);


/**
 * Get the number of SbgnGlyph_t objects in this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to query.
 *
 * @return the number of SbgnGlyph_t objects in this SbgnMap_t.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumGlyphs(SbgnMap_t* sm);


/**
 * Creates a new SbgnGlyph_t object, adds it to this SbgnMap_t object and
 * returns the SbgnGlyph_t object created.
 *
 * @param sm the SbgnMap_t structure to which the SbgnGlyph_t should be added.
 *
 * @return a new SbgnGlyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_createGlyph(SbgnMap_t* sm);


/**
 * Removes the nth SbgnGlyph_t from this SbgnMap_t and returns a pointer to it.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * remove.
 *
 * @return a pointer to the nth SbgnGlyph_t in this SbgnMap_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_removeGlyph(SbgnMap_t* sm, unsigned int n);


/**
 * Removes the SbgnGlyph_t from this SbgnMap_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * remove.
 *
 * @return the SbgnGlyph_t in this SbgnMap_t based on the identifier or NULL if
 * no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_removeGlyphById(SbgnMap_t* sm, const char* sid);


/**
 * Returns a ListOf_t * containing SbgnArc_t objects from this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose SbgnListOfArcs is sought.
 *
 * @return the SbgnListOfArcs from this SbgnMap_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnMap_addArc()
 * @see SbgnMap_createArc()
 * @see SbgnMap_getArcById()
 * @see SbgnMap_getArc()
 * @see SbgnMap_getNumArcs()
 * @see SbgnMap_removeArcById()
 * @see SbgnMap_removeArc()
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfArcs(SbgnMap_t* sm);


/**
 * Get a SbgnArc_t from the SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to
 * retrieve.
 *
 * @return the nth SbgnArc_t in the SbgnListOfArcs within this SbgnMap.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_getArc(SbgnMap_t* sm, unsigned int n);


/**
 * Get a SbgnArc_t from the SbgnMap_t based on its identifier.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to
 * retrieve.
 *
 * @return the SbgnArc_t in the SbgnListOfArcs within this SbgnMap with the
 * given @p sid or @c NULL if no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_getArcById(SbgnMap_t* sm, const char *sid);


/**
 * Adds a copy of the given SbgnArc_t to this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to which the SbgnArc_t should be added.
 *
 * @param sa the SbgnArc_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_addArc(SbgnMap_t* sm, const SbgnArc_t* sa);


/**
 * Get the number of SbgnArc_t objects in this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to query.
 *
 * @return the number of SbgnArc_t objects in this SbgnMap_t.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumArcs(SbgnMap_t* sm);


/**
 * Creates a new SbgnArc_t object, adds it to this SbgnMap_t object and returns
 * the SbgnArc_t object created.
 *
 * @param sm the SbgnMap_t structure to which the SbgnArc_t should be added.
 *
 * @return a new SbgnArc_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_createArc(SbgnMap_t* sm);


/**
 * Removes the nth SbgnArc_t from this SbgnMap_t and returns a pointer to it.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to remove.
 *
 * @return a pointer to the nth SbgnArc_t in this SbgnMap_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_removeArc(SbgnMap_t* sm, unsigned int n);


/**
 * Removes the SbgnArc_t from this SbgnMap_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to remove.
 *
 * @return the SbgnArc_t in this SbgnMap_t based on the identifier or NULL if
 * no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_removeArcById(SbgnMap_t* sm, const char* sid);


/**
 * Returns a ListOf_t * containing SbgnArcGroup_t objects from this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure whose SbgnListOfArcGroups is sought.
 *
 * @return the SbgnListOfArcGroups from this SbgnMap_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnMap_addArcGroup()
 * @see SbgnMap_createArcGroup()
 * @see SbgnMap_getArcGroupById()
 * @see SbgnMap_getArcGroup()
 * @see SbgnMap_getNumArcGroups()
 * @see SbgnMap_removeArcGroupById()
 * @see SbgnMap_removeArcGroup()
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfArcGroups(SbgnMap_t* sm);


/**
 * Get a SbgnArcGroup_t from the SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArcGroup_t to
 * retrieve.
 *
 * @return the nth SbgnArcGroup_t in the SbgnListOfArcGroups within this
 * SbgnMap.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_getArcGroup(SbgnMap_t* sm, unsigned int n);


/**
 * Adds a copy of the given SbgnArcGroup_t to this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to which the SbgnArcGroup_t should be
 * added.
 *
 * @param sag the SbgnArcGroup_t object to add.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_LEVEL_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_PKG_VERSION_MISMATCH, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_DUPLICATE_OBJECT_ID, OperationReturnValues_t}
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_addArcGroup(SbgnMap_t* sm, const SbgnArcGroup_t* sag);


/**
 * Get the number of SbgnArcGroup_t objects in this SbgnMap_t.
 *
 * @param sm the SbgnMap_t structure to query.
 *
 * @return the number of SbgnArcGroup_t objects in this SbgnMap_t.
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumArcGroups(SbgnMap_t* sm);


/**
 * Creates a new SbgnArcGroup_t object, adds it to this SbgnMap_t object and
 * returns the SbgnArcGroup_t object created.
 *
 * @param sm the SbgnMap_t structure to which the SbgnArcGroup_t should be
 * added.
 *
 * @return a new SbgnArcGroup_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_createArcGroup(SbgnMap_t* sm);


/**
 * Removes the nth SbgnArcGroup_t from this SbgnMap_t and returns a pointer to
 * it.
 *
 * @param sm the SbgnMap_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArcGroup_t to
 * remove.
 *
 * @return a pointer to the nth SbgnArcGroup_t in this SbgnMap_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_removeArcGroup(SbgnMap_t* sm, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnMap_t object have been set.
 *
 * @param sm the SbgnMap_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnMap_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnMap_t object are:
 * @li "id"
 *
 * @memberof SbgnMap_t
 */
LIBSBGN_EXTERN
int
SbgnMap_hasRequiredAttributes(const SbgnMap_t * sm);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnMap_H__ */



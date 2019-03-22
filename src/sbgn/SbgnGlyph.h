/**
 * @file SbgnGlyph.h
 * @brief Definition of the SbgnGlyph class.
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
 * @class SbgnGlyph
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnGlyph class.
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
 * @class doc_sbgnglyph_orientation
 *
 * @par
 * The attribute "orientation" on a SbgnGlyph object is used to TODO:add
 * explanation
 *
 * In the SBML
 * Level&nbsp;3 Version&nbsp;1 Sbgnml specification, the following are the
 * allowable values for "orientation":
 * <ul>
 * <li> @c "horizontal", TODO:add description
 *
 * <li> @c "vertical", TODO:add description
 *
 * <li> @c "left", TODO:add description
 *
 * <li> @c "right", TODO:add description
 *
 * <li> @c "up", TODO:add description
 *
 * <li> @c "down", TODO:add description
 *
 * </ul>
 */


#ifndef SbgnGlyph_H__
#define SbgnGlyph_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>
#include <sbgn/common/SbgnEnumerations.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnLabel.h>
#include <sbgn/SbgnState.h>
#include <sbgn/SbgnGlyph.h>
#include <sbgn/SbgnCallout.h>
#include <sbgn/SbgnEntity.h>
#include <sbgn/SbgnBBox.h>
#include <sbgn/SbgnListOfPorts.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class SbgnListOfGlyphs;

class LIBSBGN_EXTERN SbgnGlyph : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mClazz;
  std::string mCompartmentRef;
  double mCompartmentOrder;
  bool mIsSetCompartmentOrder;
  Orientation_t mOrientation;
  SbgnLabel* mLabel;
  SbgnState* mState;
  SbgnGlyph* mClone;
  SbgnCallout* mCallout;
  SbgnEntity* mEntity;
  SbgnBBox* mBBox;
  SbgnListOfGlyphs * mGlyphs;
  SbgnListOfPorts mPorts;
  std::string mMapRef;
  std::string mTagRef;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SbgnGlyph using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnGlyph.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnGlyph.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnGlyph(unsigned int level = SBGN_DEFAULT_LEVEL,
            unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnGlyph using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnGlyph(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnGlyph.
   *
   * @param orig the SbgnGlyph instance to copy.
   */
  SbgnGlyph(const SbgnGlyph& orig);


  /**
   * Assignment operator for SbgnGlyph.
   *
   * @param rhs the SbgnGlyph object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnGlyph& operator=(const SbgnGlyph& rhs);


  /**
   * Creates and returns a deep copy of this SbgnGlyph object.
   *
   * @return a (deep) copy of this SbgnGlyph object.
   */
  virtual SbgnGlyph* clone() const;


  /**
   * Destructor for SbgnGlyph.
   */
  virtual ~SbgnGlyph();


  /**
   * Returns the value of the "id" attribute of this SbgnGlyph.
   *
   * @return the value of the "id" attribute of this SbgnGlyph as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "class" attribute of this SbgnGlyph.
   *
   * @return the value of the "class" attribute of this SbgnGlyph as a string.
   */
  const std::string& getClazz() const;


  /**
   * Returns the value of the "compartmentRef" attribute of this SbgnGlyph.
   *
   * @return the value of the "compartmentRef" attribute of this SbgnGlyph as a
   * string.
   */
  const std::string& getCompartmentRef() const;


  /**
   * Returns the value of the "compartmentOrder" attribute of this SbgnGlyph.
   *
   * @return the value of the "compartmentOrder" attribute of this SbgnGlyph as
   * a double.
   */
  double getCompartmentOrder() const;


  /**
   * Returns the value of the "orientation" attribute of this SbgnGlyph.
   *
   * @return the value of the "orientation" attribute of this SbgnGlyph as a
   * Orientation_t.
   *
   * @copydetails doc_sbgnglyph_orientation
   * @if clike The value is drawn from the enumeration @ref Orientation_t
   * @endif
   * The possible values returned by this method are:
   * @li @sbmlconstant{SBGNML_ORIENTATION_HORIZONTAL, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_VERTICAL, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_LEFT, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_RIGHT, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_UP, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_DOWN, Orientation_t}
   * @li @sbmlconstant{SBGNML_ORIENTATION_INVALID, Orientation_t}
   */
  Orientation_t getOrientation() const;


  /**
   * Returns the value of the "orientation" attribute of this SbgnGlyph.
   *
   * @return the value of the "orientation" attribute of this SbgnGlyph as a
   * string.
   *
   * @copydetails doc_sbgnglyph_orientation
   * The possible values returned by this method are:
   * @li @c "horizontal"
   * @li @c "vertical"
   * @li @c "left"
   * @li @c "right"
   * @li @c "up"
   * @li @c "down"
   * @li @c "invalid Orientation value"
   */
  std::string getOrientationAsString() const;


  /**
   * Returns the value of the "mapRef" attribute of this SbgnGlyph.
   *
   * @return the value of the "mapRef" attribute of this SbgnGlyph as a string.
   */
  const std::string& getMapRef() const;


  /**
   * Returns the value of the "tagRef" attribute of this SbgnGlyph.
   *
   * @return the value of the "tagRef" attribute of this SbgnGlyph as a string.
   */
  const std::string& getTagRef() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "id" attribute is set.
   *
   * @return @c true if this SbgnGlyph's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "class" attribute is set.
   *
   * @return @c true if this SbgnGlyph's "class" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetClazz() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "compartmentRef" attribute
   * is set.
   *
   * @return @c true if this SbgnGlyph's "compartmentRef" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetCompartmentRef() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "compartmentOrder"
   * attribute is set.
   *
   * @return @c true if this SbgnGlyph's "compartmentOrder" attribute has been
   * set, otherwise @c false is returned.
   */
  bool isSetCompartmentOrder() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "orientation" attribute is
   * set.
   *
   * @return @c true if this SbgnGlyph's "orientation" attribute has been set,
   * otherwise @c false is returned.
   *
   * @copydetails doc_sbgnglyph_orientation
   */
  bool isSetOrientation() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "mapRef" attribute is set.
   *
   * @return @c true if this SbgnGlyph's "mapRef" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetMapRef() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "tagRef" attribute is set.
   *
   * @return @c true if this SbgnGlyph's "tagRef" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTagRef() const;


  /**
   * Sets the value of the "id" attribute of this SbgnGlyph.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * Calling this function with @p id = @c NULL or an empty string is
   * equivalent to calling unsetId().
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "class" attribute of this SbgnGlyph.
   *
   * @param clazz std::string& value of the "class" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p clazz = @c NULL or an empty string is
   * equivalent to calling unsetClazz().
   */
  int setClazz(const std::string& clazz);


  /**
   * Sets the value of the "compartmentRef" attribute of this SbgnGlyph.
   *
   * @param compartmentRef std::string& value of the "compartmentRef" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompartmentRef(const std::string& compartmentRef);


  /**
   * Sets the value of the "compartmentOrder" attribute of this SbgnGlyph.
   *
   * @param compartmentOrder double value of the "compartmentOrder" attribute
   * to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCompartmentOrder(double compartmentOrder);


  /**
   * Sets the value of the "orientation" attribute of this SbgnGlyph.
   *
   * @param orientation @if clike Orientation_t@else int@endif value of the
   * "orientation" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnglyph_orientation
   */
  int setOrientation(const Orientation_t orientation);


  /**
   * Sets the value of the "orientation" attribute of this SbgnGlyph.
   *
   * @param orientation std::string& of the "orientation" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   *
   * @copydetails doc_sbgnglyph_orientation
   */
  int setOrientation(const std::string& orientation);


  /**
   * Sets the value of the "mapRef" attribute of this SbgnGlyph.
   *
   * @param mapRef std::string& value of the "mapRef" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setMapRef(const std::string& mapRef);


  /**
   * Sets the value of the "tagRef" attribute of this SbgnGlyph.
   *
   * @param tagRef std::string& value of the "tagRef" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setTagRef(const std::string& tagRef);


  /**
   * Unsets the value of the "id" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "class" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClazz();


  /**
   * Unsets the value of the "compartmentRef" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompartmentRef();


  /**
   * Unsets the value of the "compartmentOrder" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCompartmentOrder();


  /**
   * Unsets the value of the "orientation" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * @copydetails doc_sbgnglyph_orientation
   */
  int unsetOrientation();


  /**
   * Unsets the value of the "mapRef" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetMapRef();


  /**
   * Unsets the value of the "tagRef" attribute of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTagRef();


  /**
   * Returns the value of the "label" element of this SbgnGlyph.
   *
   * @return the value of the "label" element of this SbgnGlyph as a
   * SbgnLabel*.
   */
  const SbgnLabel* getLabel() const;


  /**
   * Returns the value of the "label" element of this SbgnGlyph.
   *
   * @return the value of the "label" element of this SbgnGlyph as a
   * SbgnLabel*.
   */
  SbgnLabel* getLabel();


  /**
   * Returns the value of the "state" element of this SbgnGlyph.
   *
   * @return the value of the "state" element of this SbgnGlyph as a
   * SbgnState*.
   */
  const SbgnState* getState() const;


  /**
   * Returns the value of the "state" element of this SbgnGlyph.
   *
   * @return the value of the "state" element of this SbgnGlyph as a
   * SbgnState*.
   */
  SbgnState* getState();


  /**
   * Returns the value of the "clone" element of this SbgnGlyph.
   *
   * @return the value of the "clone" element of this SbgnGlyph as a
   * SbgnGlyph*.
   */
  const SbgnGlyph* getClone() const;


  /**
   * Returns the value of the "clone" element of this SbgnGlyph.
   *
   * @return the value of the "clone" element of this SbgnGlyph as a
   * SbgnGlyph*.
   */
  SbgnGlyph* getClone();


  /**
   * Returns the value of the "callout" element of this SbgnGlyph.
   *
   * @return the value of the "callout" element of this SbgnGlyph as a
   * SbgnCallout*.
   */
  const SbgnCallout* getCallout() const;


  /**
   * Returns the value of the "callout" element of this SbgnGlyph.
   *
   * @return the value of the "callout" element of this SbgnGlyph as a
   * SbgnCallout*.
   */
  SbgnCallout* getCallout();


  /**
   * Returns the value of the "entity" element of this SbgnGlyph.
   *
   * @return the value of the "entity" element of this SbgnGlyph as a
   * SbgnEntity*.
   */
  const SbgnEntity* getEntity() const;


  /**
   * Returns the value of the "entity" element of this SbgnGlyph.
   *
   * @return the value of the "entity" element of this SbgnGlyph as a
   * SbgnEntity*.
   */
  SbgnEntity* getEntity();


  /**
   * Returns the value of the "bbox" element of this SbgnGlyph.
   *
   * @return the value of the "bbox" element of this SbgnGlyph as a SbgnBBox*.
   */
  const SbgnBBox* getBBox() const;


  /**
   * Returns the value of the "bbox" element of this SbgnGlyph.
   *
   * @return the value of the "bbox" element of this SbgnGlyph as a SbgnBBox*.
   */
  SbgnBBox* getBBox();


  /**
   * Predicate returning @c true if this SbgnGlyph's "label" element is set.
   *
   * @return @c true if this SbgnGlyph's "label" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetLabel() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "state" element is set.
   *
   * @return @c true if this SbgnGlyph's "state" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetState() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "clone" element is set.
   *
   * @return @c true if this SbgnGlyph's "clone" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetClone() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "callout" element is set.
   *
   * @return @c true if this SbgnGlyph's "callout" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetCallout() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "entity" element is set.
   *
   * @return @c true if this SbgnGlyph's "entity" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetEntity() const;


  /**
   * Predicate returning @c true if this SbgnGlyph's "bbox" element is set.
   *
   * @return @c true if this SbgnGlyph's "bbox" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetBBox() const;


  /**
   * Sets the value of the "label" element of this SbgnGlyph.
   *
   * @param label SbgnLabel* value of the "label" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setLabel(const SbgnLabel* label);


  /**
   * Sets the value of the "state" element of this SbgnGlyph.
   *
   * @param state SbgnState* value of the "state" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setState(const SbgnState* state);


  /**
   * Sets the value of the "clone" element of this SbgnGlyph.
   *
   * @param clone SbgnGlyph* value of the "clone" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setClone(const SbgnGlyph* clone);


  /**
   * Sets the value of the "callout" element of this SbgnGlyph.
   *
   * @param callout SbgnCallout* value of the "callout" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setCallout(const SbgnCallout* callout);


  /**
   * Sets the value of the "entity" element of this SbgnGlyph.
   *
   * @param entity SbgnEntity* value of the "entity" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setEntity(const SbgnEntity* entity);


  /**
   * Sets the value of the "bbox" element of this SbgnGlyph.
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
   * Creates a new SbgnLabel object, adds it to this SbgnGlyph object and
   * returns the SbgnLabel object created.
   *
   * @return a new SbgnLabel object instance.
   */
  SbgnLabel* createLabel();


  /**
   * Creates a new SbgnState object, adds it to this SbgnGlyph object and
   * returns the SbgnState object created.
   *
   * @return a new SbgnState object instance.
   */
  SbgnState* createState();


  /**
   * Creates a new SbgnGlyph object, adds it to this SbgnGlyph object and
   * returns the SbgnGlyph object created.
   *
   * @return a new SbgnGlyph object instance.
   */
  SbgnGlyph* createClone();


  /**
   * Creates a new SbgnCallout object, adds it to this SbgnGlyph object and
   * returns the SbgnCallout object created.
   *
   * @return a new SbgnCallout object instance.
   */
  SbgnCallout* createCallout();


  /**
   * Creates a new SbgnEntity object, adds it to this SbgnGlyph object and
   * returns the SbgnEntity object created.
   *
   * @return a new SbgnEntity object instance.
   */
  SbgnEntity* createEntity();


  /**
   * Creates a new SbgnBBox object, adds it to this SbgnGlyph object and
   * returns the SbgnBBox object created.
   *
   * @return a new SbgnBBox object instance.
   */
  SbgnBBox* createBBox();


  /**
   * Unsets the value of the "label" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetLabel();


  /**
   * Unsets the value of the "state" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetState();


  /**
   * Unsets the value of the "clone" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClone();


  /**
   * Unsets the value of the "callout" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetCallout();


  /**
   * Unsets the value of the "entity" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetEntity();


  /**
   * Unsets the value of the "bbox" element of this SbgnGlyph.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBBox();


  /**
   * Returns the SbgnListOfGlyphs * from this SbgnGlyph.
   *
   * @return the SbgnListOfGlyphs * from this SbgnGlyph.
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
  const SbgnListOfGlyphs * getListOfGlyphs() const;


  /**
   * Returns the SbgnListOfGlyphs * from this SbgnGlyph.
   *
   * @return the SbgnListOfGlyphs * from this SbgnGlyph.
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
  SbgnListOfGlyphs * getListOfGlyphs();


  /**
   * Get a SbgnGlyph from the SbgnGlyph.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs * within this SbgnGlyph.
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
   * Get a SbgnGlyph from the SbgnGlyph.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs * within this SbgnGlyph.
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
   * Get a SbgnGlyph from the SbgnGlyph based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs * within this SbgnGlyph with
   * the given @p sid or @c NULL if no such SbgnGlyph exists.
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
   * Get a SbgnGlyph from the SbgnGlyph based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs * within this SbgnGlyph with
   * the given @p sid or @c NULL if no such SbgnGlyph exists.
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
   * Get a SbgnGlyph from the SbgnGlyph based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnGlyph based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnGlyph based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByMapRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnGlyph based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByMapRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnGlyph based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByTagRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnGlyph based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnGlyph based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByTagRef(const std::string& sid);


  /**
   * Adds a copy of the given SbgnGlyph to this SbgnGlyph.
   *
   * @param sg1 the SbgnGlyph object to add.
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
  int addGlyph(const SbgnGlyph* sg1);


  /**
   * Get the number of SbgnGlyph objects in this SbgnGlyph.
   *
   * @return the number of SbgnGlyph objects in this SbgnGlyph.
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
   * Creates a new SbgnGlyph object, adds it to this SbgnGlyph object and
   * returns the SbgnGlyph object created.
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
   * Removes the nth SbgnGlyph from this SbgnGlyph and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * remove.
   *
   * @return a pointer to the nth SbgnGlyph in this SbgnGlyph.
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
   * Removes the SbgnGlyph from this SbgnGlyph based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * remove.
   *
   * @return the SbgnGlyph in this SbgnGlyph based on the identifier or NULL if
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
   * Returns the SbgnListOfPorts from this SbgnGlyph.
   *
   * @return the SbgnListOfPorts from this SbgnGlyph.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const SbgnListOfPorts* getListOfPorts() const;


  /**
   * Returns the SbgnListOfPorts from this SbgnGlyph.
   *
   * @return the SbgnListOfPorts from this SbgnGlyph.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  SbgnListOfPorts* getListOfPorts();


  /**
   * Get a SbgnPort from the SbgnGlyph.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in the SbgnListOfPorts within this SbgnGlyph.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  SbgnPort* getPort(unsigned int n);


  /**
   * Get a SbgnPort from the SbgnGlyph.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in the SbgnListOfPorts within this SbgnGlyph.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const SbgnPort* getPort(unsigned int n) const;


  /**
   * Get a SbgnPort from the SbgnGlyph based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in the SbgnListOfPorts within this SbgnGlyph with the
   * given @p sid or @c NULL if no such SbgnPort exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  SbgnPort* getPort(const std::string& sid);


  /**
   * Get a SbgnPort from the SbgnGlyph based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in the SbgnListOfPorts within this SbgnGlyph with the
   * given @p sid or @c NULL if no such SbgnPort exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  const SbgnPort* getPort(const std::string& sid) const;


  /**
   * Adds a copy of the given SbgnPort to this SbgnGlyph.
   *
   * @param sp the SbgnPort object to add.
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
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  int addPort(const SbgnPort* sp);


  /**
   * Get the number of SbgnPort objects in this SbgnGlyph.
   *
   * @return the number of SbgnPort objects in this SbgnGlyph.
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  unsigned int getNumPorts() const;


  /**
   * Creates a new SbgnPort object, adds it to this SbgnGlyph object and
   * returns the SbgnPort object created.
   *
   * @return a new SbgnPort object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   * @see removePort(unsigned int n)
   */
  SbgnPort* createPort();


  /**
   * Removes the nth SbgnPort from this SbgnGlyph and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnPort to remove.
   *
   * @return a pointer to the nth SbgnPort in this SbgnGlyph.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(const std::string& sid)
   */
  SbgnPort* removePort(unsigned int n);


  /**
   * Removes the SbgnPort from this SbgnGlyph based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnPort to remove.
   *
   * @return the SbgnPort in this SbgnGlyph based on the identifier or NULL if
   * no such SbgnPort exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see getPort(const std::string& sid)
   * @see getPort(unsigned int n)
   * @see getNumPorts()
   * @see removePort(unsigned int n)
   */
  SbgnPort* removePort(const std::string& sid);


  /**
   * @copydoc doc_renamesidref_common
   */
  virtual void renameSIdRefs(const std::string& oldid,
                             const std::string& newid);


  /**
   * Returns the XML element name of this SbgnGlyph object.
   *
   * For SbgnGlyph, the XML element name is always @c "glyph".
   *
   * @return the name of this element, i.e. @c "glyph".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the XML name of this SbgnGlyph object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBGN type code for this SbgnGlyph object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_GLYPH, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnGlyph object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnGlyph have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnGlyph object are:
   * @li "id"
   * @li "class"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SbgnGlyph object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SbgnGlyph have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SbgnGlyph object are:
   * @li "bbox"
   */
  virtual bool hasRequiredElements() const;



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
   * Gets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Gets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Gets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Gets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Gets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Predicate returning @c true if this SbgnGlyph's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnGlyph's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Sets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Sets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Sets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Sets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Unsets the value of the "attributeName" attribute of this SbgnGlyph.
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
   * Creates and returns an new "elementName" object in this SbgnGlyph.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnGlyph.
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
   * SbgnGlyph.
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
   * Returns the number of "elementName" in this SbgnGlyph.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnGlyph.
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


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SbgnGlyph_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnGlyph_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnGlyph_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t *
SbgnGlyph_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnGlyph_t object.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return a (deep) copy of this SbgnGlyph_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_clone(const SbgnGlyph_t* sg);


/**
 * Frees this SbgnGlyph_t object.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
void
SbgnGlyph_free(SbgnGlyph_t* sg);


/**
 * Returns the value of the "id" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SbgnGlyph_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getId(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "class" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose class is sought.
 *
 * @return the value of the "class" attribute of this SbgnGlyph_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getClazz(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose compartmentRef is sought.
 *
 * @return the value of the "compartmentRef" attribute of this SbgnGlyph_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getCompartmentRef(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose compartmentOrder is sought.
 *
 * @return the value of the "compartmentOrder" attribute of this SbgnGlyph_t as
 * a double.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
double
SbgnGlyph_getCompartmentOrder(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "orientation" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose orientation is sought.
 *
 * @return the value of the "orientation" attribute of this SbgnGlyph_t as a
 * Orientation_t.
 *
 * @copydetails doc_sbgnglyph_orientation
 * @if clike The value is drawn from the enumeration @ref Orientation_t @endif
 * The possible values returned by this method are:
 * @li @sbmlconstant{SBGNML_ORIENTATION_HORIZONTAL, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_VERTICAL, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_LEFT, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_RIGHT, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_UP, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_DOWN, Orientation_t}
 * @li @sbmlconstant{SBGNML_ORIENTATION_INVALID, Orientation_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
Orientation_t
SbgnGlyph_getOrientation(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "orientation" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose orientation is sought.
 *
 * @return the value of the "orientation" attribute of this SbgnGlyph_t as a
 * const char *.
 *
 * @copydetails doc_returned_unowned_char
 *
 * @copydetails doc_sbgnglyph_orientation
 * The possible values returned by this method are:
 * @li @c "horizontal"
 * @li @c "vertical"
 * @li @c "left"
 * @li @c "right"
 * @li @c "up"
 * @li @c "down"
 * @li @c "invalid Orientation value"
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getOrientationAsString(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "mapRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose mapRef is sought.
 *
 * @return the value of the "mapRef" attribute of this SbgnGlyph_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getMapRef(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "tagRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose tagRef is sought.
 *
 * @return the value of the "tagRef" attribute of this SbgnGlyph_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getTagRef(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "id" attribute is set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetId(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "class" attribute is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "class" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetClazz(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "compartmentRef"
 * attribute is set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "compartmentRef" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCompartmentRef(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "compartmentOrder"
 * attribute is set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "compartmentOrder" attribute has
 * been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCompartmentOrder(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "orientation"
 * attribute is set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "orientation" attribute has been
 * set, otherwise @c 0 (false) is returned.
 *
 * @copydetails doc_sbgnglyph_orientation
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetOrientation(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "mapRef" attribute is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "mapRef" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetMapRef(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "tagRef" attribute is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "tagRef" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetTagRef(const SbgnGlyph_t * sg);


/**
 * Sets the value of the "id" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SbgnGlyph_unsetId().
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setId(SbgnGlyph_t * sg, const char * id);


/**
 * Sets the value of the "class" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param clazz const char * value of the "class" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p clazz = @c NULL or an empty string is
 * equivalent to calling SbgnGlyph_unsetClazz().
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setClazz(SbgnGlyph_t * sg, const char * clazz);


/**
 * Sets the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param compartmentRef const char * value of the "compartmentRef" attribute
 * to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCompartmentRef(SbgnGlyph_t * sg, const char * compartmentRef);


/**
 * Sets the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param compartmentOrder double value of the "compartmentOrder" attribute to
 * be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCompartmentOrder(SbgnGlyph_t * sg, double compartmentOrder);


/**
 * Sets the value of the "orientation" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param orientation Orientation_t value of the "orientation" attribute to be
 * set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnglyph_orientation
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setOrientation(SbgnGlyph_t * sg, Orientation_t orientation);


/**
 * Sets the value of the "orientation" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param orientation const char * of the "orientation" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnglyph_orientation
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setOrientationAsString(SbgnGlyph_t * sg, const char * orientation);


/**
 * Sets the value of the "mapRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param mapRef const char * value of the "mapRef" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setMapRef(SbgnGlyph_t * sg, const char * mapRef);


/**
 * Sets the value of the "tagRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param tagRef const char * value of the "tagRef" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setTagRef(SbgnGlyph_t * sg, const char * tagRef);


/**
 * Unsets the value of the "id" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetId(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "class" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetClazz(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCompartmentRef(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCompartmentOrder(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "orientation" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @copydetails doc_sbgnglyph_orientation
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetOrientation(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "mapRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetMapRef(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "tagRef" attribute of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetTagRef(SbgnGlyph_t * sg);


/**
 * Returns the value of the "label" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose label is sought.
 *
 * @return the value of the "label" element of this SbgnGlyph_t as a
 * SbgnLabel*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnLabel_t*
SbgnGlyph_getLabel(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "state" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose state is sought.
 *
 * @return the value of the "state" element of this SbgnGlyph_t as a
 * SbgnState*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnState_t*
SbgnGlyph_getState(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "clone" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose clone is sought.
 *
 * @return the value of the "clone" element of this SbgnGlyph_t as a
 * SbgnGlyph*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnGlyph_t*
SbgnGlyph_getClone(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "callout" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose callout is sought.
 *
 * @return the value of the "callout" element of this SbgnGlyph_t as a
 * SbgnCallout*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnCallout_t*
SbgnGlyph_getCallout(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "entity" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose entity is sought.
 *
 * @return the value of the "entity" element of this SbgnGlyph_t as a
 * SbgnEntity*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnEntity_t*
SbgnGlyph_getEntity(const SbgnGlyph_t * sg);


/**
 * Returns the value of the "bbox" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose bbox is sought.
 *
 * @return the value of the "bbox" element of this SbgnGlyph_t as a SbgnBBox*.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnGlyph_getBBox(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "label" element is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "label" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetLabel(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "state" element is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "state" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetState(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "clone" element is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "clone" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetClone(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "callout" element is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "callout" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCallout(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "entity" element is
 * set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "entity" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetEntity(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "bbox" element is set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) if this SbgnGlyph_t's "bbox" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetBBox(const SbgnGlyph_t * sg);


/**
 * Sets the value of the "label" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param label SbgnLabel_t* value of the "label" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setLabel(SbgnGlyph_t * sg, const SbgnLabel_t* label);


/**
 * Sets the value of the "state" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param state SbgnState_t* value of the "state" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setState(SbgnGlyph_t * sg, const SbgnState_t* state);


/**
 * Sets the value of the "clone" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param clone SbgnGlyph_t* value of the "clone" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setClone(SbgnGlyph_t * sg, const SbgnGlyph_t* clone);


/**
 * Sets the value of the "callout" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param callout SbgnCallout_t* value of the "callout" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCallout(SbgnGlyph_t * sg, const SbgnCallout_t* callout);


/**
 * Sets the value of the "entity" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param entity SbgnEntity_t* value of the "entity" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setEntity(SbgnGlyph_t * sg, const SbgnEntity_t* entity);


/**
 * Sets the value of the "bbox" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @param bbox SbgnBBox_t* value of the "bbox" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setBBox(SbgnGlyph_t * sg, const SbgnBBox_t* bbox);


/**
 * Creates a new SbgnLabel_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnLabel_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnLabel_t should be
 * added.
 *
 * @return a new SbgnLabel_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnLabel_t*
SbgnGlyph_createLabel(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnState_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnState_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnState_t should be
 * added.
 *
 * @return a new SbgnState_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnState_t*
SbgnGlyph_createState(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnGlyph_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnGlyph_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnGlyph_t should be
 * added.
 *
 * @return a new SbgnGlyph_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_createClone(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnCallout_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnCallout_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnCallout_t should be
 * added.
 *
 * @return a new SbgnCallout_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnCallout_t*
SbgnGlyph_createCallout(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnEntity_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnEntity_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnEntity_t should be
 * added.
 *
 * @return a new SbgnEntity_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnEntity_t*
SbgnGlyph_createEntity(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnBBox_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnBBox_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnBBox_t should be added.
 *
 * @return a new SbgnBBox_t object instance.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnGlyph_createBBox(SbgnGlyph_t* sg);


/**
 * Unsets the value of the "label" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetLabel(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "state" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetState(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "clone" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetClone(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "callout" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCallout(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "entity" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetEntity(SbgnGlyph_t * sg);


/**
 * Unsets the value of the "bbox" element of this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetBBox(SbgnGlyph_t * sg);


/**
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose SbgnListOfGlyphs * is sought.
 *
 * @return the SbgnListOfGlyphs * from this SbgnGlyph_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnGlyph_addGlyph()
 * @see SbgnGlyph_createGlyph()
 * @see SbgnGlyph_getGlyphById()
 * @see SbgnGlyph_getGlyph()
 * @see SbgnGlyph_getNumGlyphs()
 * @see SbgnGlyph_removeGlyphById()
 * @see SbgnGlyph_removeGlyph()
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnGlyph_getListOfGlyphs(SbgnGlyph_t* sg);


/**
 * Get a SbgnGlyph_t from the SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the nth SbgnGlyph_t in the SbgnListOfGlyphs * within this SbgnGlyph.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyph(SbgnGlyph_t* sg, unsigned int n);


/**
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on its identifier.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the SbgnGlyph_t in the SbgnListOfGlyphs * within this SbgnGlyph with
 * the given @p sid or @c NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphById(SbgnGlyph_t* sg, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the CompartmentRef to which
 * it refers.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the "compartmentRef" attribute of the
 * SbgnGlyph_t object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnGlyph_t based on the given
 * compartmentRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByCompartmentRef(SbgnGlyph_t* sg, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the MapRef to which it
 * refers.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the "mapRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnGlyph_t based on the given mapRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByMapRef(SbgnGlyph_t* sg, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the TagRef to which it
 * refers.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the "tagRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnGlyph_t based on the given tagRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByTagRef(SbgnGlyph_t* sg, const char *sid);


/**
 * Adds a copy of the given SbgnGlyph_t to this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnGlyph_t should be
 * added.
 *
 * @param sg1 the SbgnGlyph_t object to add.
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
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_addGlyph(SbgnGlyph_t* sg, const SbgnGlyph_t* sg1);


/**
 * Get the number of SbgnGlyph_t objects in this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to query.
 *
 * @return the number of SbgnGlyph_t objects in this SbgnGlyph_t.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnGlyph_getNumGlyphs(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnGlyph_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnGlyph_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnGlyph_t should be
 * added.
 *
 * @return a new SbgnGlyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_createGlyph(SbgnGlyph_t* sg);


/**
 * Removes the nth SbgnGlyph_t from this SbgnGlyph_t and returns a pointer to
 * it.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * remove.
 *
 * @return a pointer to the nth SbgnGlyph_t in this SbgnGlyph_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_removeGlyph(SbgnGlyph_t* sg, unsigned int n);


/**
 * Removes the SbgnGlyph_t from this SbgnGlyph_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * remove.
 *
 * @return the SbgnGlyph_t in this SbgnGlyph_t based on the identifier or NULL
 * if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_removeGlyphById(SbgnGlyph_t* sg, const char* sid);


/**
 * Returns a ListOf_t * containing SbgnPort_t objects from this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure whose SbgnListOfPorts is sought.
 *
 * @return the SbgnListOfPorts from this SbgnGlyph_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnGlyph_addPort()
 * @see SbgnGlyph_createPort()
 * @see SbgnGlyph_getPortById()
 * @see SbgnGlyph_getPort()
 * @see SbgnGlyph_getNumPorts()
 * @see SbgnGlyph_removePortById()
 * @see SbgnGlyph_removePort()
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnGlyph_getListOfPorts(SbgnGlyph_t* sg);


/**
 * Get a SbgnPort_t from the SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to
 * retrieve.
 *
 * @return the nth SbgnPort_t in the SbgnListOfPorts within this SbgnGlyph.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_getPort(SbgnGlyph_t* sg, unsigned int n);


/**
 * Get a SbgnPort_t from the SbgnGlyph_t based on its identifier.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to
 * retrieve.
 *
 * @return the SbgnPort_t in the SbgnListOfPorts within this SbgnGlyph with the
 * given @p sid or @c NULL if no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_getPortById(SbgnGlyph_t* sg, const char *sid);


/**
 * Adds a copy of the given SbgnPort_t to this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnPort_t should be added.
 *
 * @param sp the SbgnPort_t object to add.
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
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_addPort(SbgnGlyph_t* sg, const SbgnPort_t* sp);


/**
 * Get the number of SbgnPort_t objects in this SbgnGlyph_t.
 *
 * @param sg the SbgnGlyph_t structure to query.
 *
 * @return the number of SbgnPort_t objects in this SbgnGlyph_t.
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnGlyph_getNumPorts(SbgnGlyph_t* sg);


/**
 * Creates a new SbgnPort_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnPort_t object created.
 *
 * @param sg the SbgnGlyph_t structure to which the SbgnPort_t should be added.
 *
 * @return a new SbgnPort_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_createPort(SbgnGlyph_t* sg);


/**
 * Removes the nth SbgnPort_t from this SbgnGlyph_t and returns a pointer to
 * it.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to remove.
 *
 * @return a pointer to the nth SbgnPort_t in this SbgnGlyph_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_removePort(SbgnGlyph_t* sg, unsigned int n);


/**
 * Removes the SbgnPort_t from this SbgnGlyph_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sg the SbgnGlyph_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to remove.
 *
 * @return the SbgnPort_t in this SbgnGlyph_t based on the identifier or NULL
 * if no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_removePortById(SbgnGlyph_t* sg, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnGlyph_t object have been set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnGlyph_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnGlyph_t object are:
 * @li "id"
 * @li "class"
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_hasRequiredAttributes(const SbgnGlyph_t * sg);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnGlyph_t object have been set.
 *
 * @param sg the SbgnGlyph_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SbgnGlyph_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SbgnGlyph_t object are:
 * @li "bbox"
 *
 * @memberof SbgnGlyph_t
 */
LIBSBGN_EXTERN
int
SbgnGlyph_hasRequiredElements(const SbgnGlyph_t * sg);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnGlyph_H__ */



/**
 * @file SbgnBBox.h
 * @brief Definition of the SbgnBBox class.
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
 * @class SbgnBBox
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnBBox class.
 */


#ifndef SbgnBBox_H__
#define SbgnBBox_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnBBox : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  double mX;
  bool mIsSetX;
  double mY;
  bool mIsSetY;
  double mWidth;
  bool mIsSetWidth;
  double mHeight;
  bool mIsSetHeight;

  /** @endcond */

public:

  /**
   * Creates a new SbgnBBox using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnBBox.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnBBox.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnBBox(unsigned int level = SBGN_DEFAULT_LEVEL,
           unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnBBox using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnBBox(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnBBox.
   *
   * @param orig the SbgnBBox instance to copy.
   */
  SbgnBBox(const SbgnBBox& orig);


  /**
   * Assignment operator for SbgnBBox.
   *
   * @param rhs the SbgnBBox object whose values are to be used as the basis of
   * the assignment.
   */
  SbgnBBox& operator=(const SbgnBBox& rhs);


  /**
   * Creates and returns a deep copy of this SbgnBBox object.
   *
   * @return a (deep) copy of this SbgnBBox object.
   */
  virtual SbgnBBox* clone() const;


  /**
   * Destructor for SbgnBBox.
   */
  virtual ~SbgnBBox();


  /**
   * Returns the value of the "x" attribute of this SbgnBBox.
   *
   * @return the value of the "x" attribute of this SbgnBBox as a double.
   */
  double getX() const;


  /**
   * Returns the value of the "y" attribute of this SbgnBBox.
   *
   * @return the value of the "y" attribute of this SbgnBBox as a double.
   */
  double getY() const;


  /**
   * Returns the value of the "w" attribute of this SbgnBBox.
   *
   * @return the value of the "w" attribute of this SbgnBBox as a double.
   */
  double getWidth() const;


  /**
   * Returns the value of the "h" attribute of this SbgnBBox.
   *
   * @return the value of the "h" attribute of this SbgnBBox as a double.
   */
  double getHeight() const;


  /**
   * Predicate returning @c true if this SbgnBBox's "x" attribute is set.
   *
   * @return @c true if this SbgnBBox's "x" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetX() const;


  /**
   * Predicate returning @c true if this SbgnBBox's "y" attribute is set.
   *
   * @return @c true if this SbgnBBox's "y" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetY() const;


  /**
   * Predicate returning @c true if this SbgnBBox's "w" attribute is set.
   *
   * @return @c true if this SbgnBBox's "w" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetWidth() const;


  /**
   * Predicate returning @c true if this SbgnBBox's "h" attribute is set.
   *
   * @return @c true if this SbgnBBox's "h" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetHeight() const;


  /**
   * Sets the value of the "x" attribute of this SbgnBBox.
   *
   * @param x double value of the "x" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setX(double x);


  /**
   * Sets the value of the "y" attribute of this SbgnBBox.
   *
   * @param y double value of the "y" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setY(double y);


  /**
   * Sets the value of the "w" attribute of this SbgnBBox.
   *
   * @param width double value of the "w" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setWidth(double width);


  /**
   * Sets the value of the "h" attribute of this SbgnBBox.
   *
   * @param height double value of the "h" attribute to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setHeight(double height);


  /**
   * Unsets the value of the "x" attribute of this SbgnBBox.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetX();


  /**
   * Unsets the value of the "y" attribute of this SbgnBBox.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetY();


  /**
   * Unsets the value of the "w" attribute of this SbgnBBox.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetWidth();


  /**
   * Unsets the value of the "h" attribute of this SbgnBBox.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetHeight();


  /**
   * Returns the XML element name of this SbgnBBox object.
   *
   * For SbgnBBox, the XML element name is always @c "bbox".
   *
   * @return the name of this element, i.e. @c "bbox".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnBBox object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_BBOX, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnBBox object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnBBox have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnBBox object are:
   * @li "x"
   * @li "y"
   * @li "w"
   * @li "h"
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




  #ifndef SWIG



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Gets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Gets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Gets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Gets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Predicate returning @c true if this SbgnBBox's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnBBox's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Sets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Sets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Sets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Sets the value of the "attributeName" attribute of this SbgnBBox.
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
   * Unsets the value of the "attributeName" attribute of this SbgnBBox.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetAttribute(const std::string& attributeName);

  /** @endcond */




  #endif /* !SWIG */


protected:


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
 * Creates a new SbgnBBox_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnBBox_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnBBox_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
SbgnBBox_t *
SbgnBBox_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnBBox_t object.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return a (deep) copy of this SbgnBBox_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnBBox_clone(const SbgnBBox_t* sbb);


/**
 * Frees this SbgnBBox_t object.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
void
SbgnBBox_free(SbgnBBox_t* sbb);


/**
 * Returns the value of the "x" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure whose x is sought.
 *
 * @return the value of the "x" attribute of this SbgnBBox_t as a double.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
double
SbgnBBox_getX(const SbgnBBox_t * sbb);


/**
 * Returns the value of the "y" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure whose y is sought.
 *
 * @return the value of the "y" attribute of this SbgnBBox_t as a double.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
double
SbgnBBox_getY(const SbgnBBox_t * sbb);


/**
 * Returns the value of the "w" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure whose w is sought.
 *
 * @return the value of the "w" attribute of this SbgnBBox_t as a double.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
double
SbgnBBox_getWidth(const SbgnBBox_t * sbb);


/**
 * Returns the value of the "h" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure whose h is sought.
 *
 * @return the value of the "h" attribute of this SbgnBBox_t as a double.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
double
SbgnBBox_getHeight(const SbgnBBox_t * sbb);


/**
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "x" attribute is set.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return @c 1 (true) if this SbgnBBox_t's "x" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetX(const SbgnBBox_t * sbb);


/**
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "y" attribute is set.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return @c 1 (true) if this SbgnBBox_t's "y" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetY(const SbgnBBox_t * sbb);


/**
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "w" attribute is set.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return @c 1 (true) if this SbgnBBox_t's "w" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetWidth(const SbgnBBox_t * sbb);


/**
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "h" attribute is set.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return @c 1 (true) if this SbgnBBox_t's "h" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetHeight(const SbgnBBox_t * sbb);


/**
 * Sets the value of the "x" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @param x double value of the "x" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_setX(SbgnBBox_t * sbb, double x);


/**
 * Sets the value of the "y" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @param y double value of the "y" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_setY(SbgnBBox_t * sbb, double y);


/**
 * Sets the value of the "w" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @param width double value of the "w" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_setWidth(SbgnBBox_t * sbb, double width);


/**
 * Sets the value of the "h" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @param height double value of the "h" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_setHeight(SbgnBBox_t * sbb, double height);


/**
 * Unsets the value of the "x" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetX(SbgnBBox_t * sbb);


/**
 * Unsets the value of the "y" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetY(SbgnBBox_t * sbb);


/**
 * Unsets the value of the "w" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetWidth(SbgnBBox_t * sbb);


/**
 * Unsets the value of the "h" attribute of this SbgnBBox_t.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetHeight(SbgnBBox_t * sbb);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnBBox_t object have been set.
 *
 * @param sbb the SbgnBBox_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnBBox_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnBBox_t object are:
 * @li "x"
 * @li "y"
 * @li "w"
 * @li "h"
 *
 * @memberof SbgnBBox_t
 */
LIBSBGN_EXTERN
int
SbgnBBox_hasRequiredAttributes(const SbgnBBox_t * sbb);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnBBox_H__ */



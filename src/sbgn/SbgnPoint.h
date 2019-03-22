/**
 * @file SbgnPoint.h
 * @brief Definition of the SbgnPoint class.
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
 * @class SbgnPoint
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnPoint class.
 */


#ifndef SbgnPoint_H__
#define SbgnPoint_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class SbgnListOfPoints;

class LIBSBGN_EXTERN SbgnPoint : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  double mX;
  bool mIsSetX;
  double mY;
  bool mIsSetY;
  SbgnListOfPoints * mPoints;
  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SbgnPoint using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnPoint.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnPoint.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnPoint(unsigned int level = SBGN_DEFAULT_LEVEL,
            unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnPoint using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnPoint(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnPoint.
   *
   * @param orig the SbgnPoint instance to copy.
   */
  SbgnPoint(const SbgnPoint& orig);


  /**
   * Assignment operator for SbgnPoint.
   *
   * @param rhs the SbgnPoint object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnPoint& operator=(const SbgnPoint& rhs);


  /**
   * Creates and returns a deep copy of this SbgnPoint object.
   *
   * @return a (deep) copy of this SbgnPoint object.
   */
  virtual SbgnPoint* clone() const;


  /**
   * Destructor for SbgnPoint.
   */
  virtual ~SbgnPoint();


  /**
   * Returns the value of the "x" attribute of this SbgnPoint.
   *
   * @return the value of the "x" attribute of this SbgnPoint as a double.
   */
  double getX() const;


  /**
   * Returns the value of the "y" attribute of this SbgnPoint.
   *
   * @return the value of the "y" attribute of this SbgnPoint as a double.
   */
  double getY() const;


  /**
   * Predicate returning @c true if this SbgnPoint's "x" attribute is set.
   *
   * @return @c true if this SbgnPoint's "x" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetX() const;


  /**
   * Predicate returning @c true if this SbgnPoint's "y" attribute is set.
   *
   * @return @c true if this SbgnPoint's "y" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetY() const;


  /**
   * Sets the value of the "x" attribute of this SbgnPoint.
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
   * Sets the value of the "y" attribute of this SbgnPoint.
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
   * Unsets the value of the "x" attribute of this SbgnPoint.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetX();


  /**
   * Unsets the value of the "y" attribute of this SbgnPoint.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetY();


  /**
   * Returns the SbgnListOfPoints * from this SbgnPoint.
   *
   * @return the SbgnListOfPoints * from this SbgnPoint.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  const SbgnListOfPoints * getListOfPoints() const;


  /**
   * Returns the SbgnListOfPoints * from this SbgnPoint.
   *
   * @return the SbgnListOfPoints * from this SbgnPoint.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  SbgnListOfPoints * getListOfPoints();


  /**
   * Get a SbgnPoint from the SbgnPoint.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in the SbgnListOfPoints * within this SbgnPoint.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  SbgnPoint* getPoint(unsigned int n);


  /**
   * Get a SbgnPoint from the SbgnPoint.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in the SbgnListOfPoints * within this SbgnPoint.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  const SbgnPoint* getPoint(unsigned int n) const;


  /**
   * Adds a copy of the given SbgnPoint to this SbgnPoint.
   *
   * @param sp1 the SbgnPoint object to add.
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
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  int addPoint(const SbgnPoint* sp1);


  /**
   * Get the number of SbgnPoint objects in this SbgnPoint.
   *
   * @return the number of SbgnPoint objects in this SbgnPoint.
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  unsigned int getNumPoints() const;


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnPoint object and
   * returns the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   * @see removePoint(unsigned int n)
   */
  SbgnPoint* createPoint();


  /**
   * Removes the nth SbgnPoint from this SbgnPoint and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * remove.
   *
   * @return a pointer to the nth SbgnPoint in this SbgnPoint.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see getPoint(const std::string& sid)
   * @see getPoint(unsigned int n)
   * @see getNumPoints()
   * @see removePoint(const std::string& sid)
   */
  SbgnPoint* removePoint(unsigned int n);


  /**
   * Returns the XML element name of this SbgnPoint object.
   *
   * For SbgnPoint, the XML element name is always @c "point".
   *
   * @return the name of this element, i.e. @c "point".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the XML name of this SbgnPoint object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBGN type code for this SbgnPoint object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_POINT, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnPoint object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnPoint have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnPoint object are:
   * @li "x"
   * @li "y"
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
   * Gets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Gets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Gets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Gets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Gets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Predicate returning @c true if this SbgnPoint's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnPoint's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Sets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Sets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Sets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Sets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Unsets the value of the "attributeName" attribute of this SbgnPoint.
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
   * Creates and returns an new "elementName" object in this SbgnPoint.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnPoint.
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
   * SbgnPoint.
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
   * Returns the number of "elementName" in this SbgnPoint.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnPoint.
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
 * Creates a new SbgnPoint_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnPoint_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnPoint_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnPoint_t *
SbgnPoint_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnPoint_t object.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @return a (deep) copy of this SbgnPoint_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_clone(const SbgnPoint_t* sp);


/**
 * Frees this SbgnPoint_t object.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
void
SbgnPoint_free(SbgnPoint_t* sp);


/**
 * Returns the value of the "x" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure whose x is sought.
 *
 * @return the value of the "x" attribute of this SbgnPoint_t as a double.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
double
SbgnPoint_getX(const SbgnPoint_t * sp);


/**
 * Returns the value of the "y" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure whose y is sought.
 *
 * @return the value of the "y" attribute of this SbgnPoint_t as a double.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
double
SbgnPoint_getY(const SbgnPoint_t * sp);


/**
 * Predicate returning @c 1 (true) if this SbgnPoint_t's "x" attribute is set.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @return @c 1 (true) if this SbgnPoint_t's "x" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_isSetX(const SbgnPoint_t * sp);


/**
 * Predicate returning @c 1 (true) if this SbgnPoint_t's "y" attribute is set.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @return @c 1 (true) if this SbgnPoint_t's "y" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_isSetY(const SbgnPoint_t * sp);


/**
 * Sets the value of the "x" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @param x double value of the "x" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_setX(SbgnPoint_t * sp, double x);


/**
 * Sets the value of the "y" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @param y double value of the "y" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_setY(SbgnPoint_t * sp, double y);


/**
 * Unsets the value of the "x" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_unsetX(SbgnPoint_t * sp);


/**
 * Unsets the value of the "y" attribute of this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_unsetY(SbgnPoint_t * sp);


/**
 * Returns a ListOf_t * containing SbgnPoint_t objects from this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure whose SbgnListOfPoints * is sought.
 *
 * @return the SbgnListOfPoints * from this SbgnPoint_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnPoint_addPoint()
 * @see SbgnPoint_createPoint()
 * @see SbgnPoint_getPointById()
 * @see SbgnPoint_getPoint()
 * @see SbgnPoint_getNumPoints()
 * @see SbgnPoint_removePointById()
 * @see SbgnPoint_removePoint()
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnPoint_getListOfPoints(SbgnPoint_t* sp);


/**
 * Get a SbgnPoint_t from the SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * retrieve.
 *
 * @return the nth SbgnPoint_t in the SbgnListOfPoints * within this SbgnPoint.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_getPoint(SbgnPoint_t* sp, unsigned int n);


/**
 * Adds a copy of the given SbgnPoint_t to this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure to which the SbgnPoint_t should be
 * added.
 *
 * @param sp1 the SbgnPoint_t object to add.
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
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_addPoint(SbgnPoint_t* sp, const SbgnPoint_t* sp1);


/**
 * Get the number of SbgnPoint_t objects in this SbgnPoint_t.
 *
 * @param sp the SbgnPoint_t structure to query.
 *
 * @return the number of SbgnPoint_t objects in this SbgnPoint_t.
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnPoint_getNumPoints(SbgnPoint_t* sp);


/**
 * Creates a new SbgnPoint_t object, adds it to this SbgnPoint_t object and
 * returns the SbgnPoint_t object created.
 *
 * @param sp the SbgnPoint_t structure to which the SbgnPoint_t should be
 * added.
 *
 * @return a new SbgnPoint_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_createPoint(SbgnPoint_t* sp);


/**
 * Removes the nth SbgnPoint_t from this SbgnPoint_t and returns a pointer to
 * it.
 *
 * @param sp the SbgnPoint_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * remove.
 *
 * @return a pointer to the nth SbgnPoint_t in this SbgnPoint_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_removePoint(SbgnPoint_t* sp, unsigned int n);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnPoint_t object have been set.
 *
 * @param sp the SbgnPoint_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnPoint_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnPoint_t object are:
 * @li "x"
 * @li "y"
 *
 * @memberof SbgnPoint_t
 */
LIBSBGN_EXTERN
int
SbgnPoint_hasRequiredAttributes(const SbgnPoint_t * sp);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnPoint_H__ */



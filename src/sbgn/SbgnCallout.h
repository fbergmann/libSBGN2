/**
 * @file SbgnCallout.h
 * @brief Definition of the SbgnCallout class.
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
 * @class SbgnCallout
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnCallout class.
 */


#ifndef SbgnCallout_H__
#define SbgnCallout_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnPoint.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnCallout : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mTarget;
  SbgnPoint* mPoint;

  /** @endcond */

public:

  /**
   * Creates a new SbgnCallout using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnCallout.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnCallout.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnCallout(unsigned int level = SBGN_DEFAULT_LEVEL,
              unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnCallout using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnCallout(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnCallout.
   *
   * @param orig the SbgnCallout instance to copy.
   */
  SbgnCallout(const SbgnCallout& orig);


  /**
   * Assignment operator for SbgnCallout.
   *
   * @param rhs the SbgnCallout object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnCallout& operator=(const SbgnCallout& rhs);


  /**
   * Creates and returns a deep copy of this SbgnCallout object.
   *
   * @return a (deep) copy of this SbgnCallout object.
   */
  virtual SbgnCallout* clone() const;


  /**
   * Destructor for SbgnCallout.
   */
  virtual ~SbgnCallout();


  /**
   * Returns the value of the "target" attribute of this SbgnCallout.
   *
   * @return the value of the "target" attribute of this SbgnCallout as a
   * string.
   */
  const std::string& getTarget() const;


  /**
   * Predicate returning @c true if this SbgnCallout's "target" attribute is
   * set.
   *
   * @return @c true if this SbgnCallout's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Sets the value of the "target" attribute of this SbgnCallout.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setTarget(const std::string& target);


  /**
   * Unsets the value of the "target" attribute of this SbgnCallout.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Returns the value of the "point" element of this SbgnCallout.
   *
   * @return the value of the "point" element of this SbgnCallout as a
   * SbgnPoint*.
   */
  const SbgnPoint* getPoint() const;


  /**
   * Returns the value of the "point" element of this SbgnCallout.
   *
   * @return the value of the "point" element of this SbgnCallout as a
   * SbgnPoint*.
   */
  SbgnPoint* getPoint();


  /**
   * Predicate returning @c true if this SbgnCallout's "point" element is set.
   *
   * @return @c true if this SbgnCallout's "point" element has been set,
   * otherwise @c false is returned.
   */
  bool isSetPoint() const;


  /**
   * Sets the value of the "point" element of this SbgnCallout.
   *
   * @param point SbgnPoint* value of the "point" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setPoint(const SbgnPoint* point);


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnCallout object and
   * returns the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   */
  SbgnPoint* createPoint();


  /**
   * Unsets the value of the "point" element of this SbgnCallout.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetPoint();


  /**
   * Returns the XML element name of this SbgnCallout object.
   *
   * For SbgnCallout, the XML element name is always @c "callout".
   *
   * @return the name of this element, i.e. @c "callout".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnCallout object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_CALLOUT, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnCallout object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnCallout have been set, otherwise @c false is returned.
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SbgnCallout object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SbgnCallout have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SbgnCallout object are:
   * @li "point"
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
   * Gets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Gets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Gets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Gets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Gets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Predicate returning @c true if this SbgnCallout's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnCallout's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Sets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Sets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Sets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Sets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Unsets the value of the "attributeName" attribute of this SbgnCallout.
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
   * Creates and returns an new "elementName" object in this SbgnCallout.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnCallout.
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
   * SbgnCallout.
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
   * Returns the number of "elementName" in this SbgnCallout.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnCallout.
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
 * Creates a new SbgnCallout_t using the given SBGN Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this
 * SbgnCallout_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnCallout_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
SbgnCallout_t *
SbgnCallout_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnCallout_t object.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @return a (deep) copy of this SbgnCallout_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
SbgnCallout_t*
SbgnCallout_clone(const SbgnCallout_t* sc);


/**
 * Frees this SbgnCallout_t object.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
void
SbgnCallout_free(SbgnCallout_t* sc);


/**
 * Returns the value of the "target" attribute of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SbgnCallout_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
char *
SbgnCallout_getTarget(const SbgnCallout_t * sc);


/**
 * Predicate returning @c 1 (true) if this SbgnCallout_t's "target" attribute
 * is set.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @return @c 1 (true) if this SbgnCallout_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_isSetTarget(const SbgnCallout_t * sc);


/**
 * Sets the value of the "target" attribute of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_setTarget(SbgnCallout_t * sc, const char * target);


/**
 * Unsets the value of the "target" attribute of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_unsetTarget(SbgnCallout_t * sc);


/**
 * Returns the value of the "point" element of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure whose point is sought.
 *
 * @return the value of the "point" element of this SbgnCallout_t as a
 * SbgnPoint*.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnCallout_getPoint(const SbgnCallout_t * sc);


/**
 * Predicate returning @c 1 (true) if this SbgnCallout_t's "point" element is
 * set.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @return @c 1 (true) if this SbgnCallout_t's "point" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_isSetPoint(const SbgnCallout_t * sc);


/**
 * Sets the value of the "point" element of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @param point SbgnPoint_t* value of the "point" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_setPoint(SbgnCallout_t * sc, const SbgnPoint_t* point);


/**
 * Creates a new SbgnPoint_t object, adds it to this SbgnCallout_t object and
 * returns the SbgnPoint_t object created.
 *
 * @param sc the SbgnCallout_t structure to which the SbgnPoint_t should be
 * added.
 *
 * @return a new SbgnPoint_t object instance.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnCallout_createPoint(SbgnCallout_t* sc);


/**
 * Unsets the value of the "point" element of this SbgnCallout_t.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_unsetPoint(SbgnCallout_t * sc);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnCallout_t object have been set.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnCallout_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_hasRequiredAttributes(const SbgnCallout_t * sc);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnCallout_t object have been set.
 *
 * @param sc the SbgnCallout_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SbgnCallout_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SbgnCallout_t object are:
 * @li "point"
 *
 * @memberof SbgnCallout_t
 */
LIBSBGN_EXTERN
int
SbgnCallout_hasRequiredElements(const SbgnCallout_t * sc);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnCallout_H__ */



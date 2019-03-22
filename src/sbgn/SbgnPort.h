/**
 * @file SbgnPort.h
 * @brief Definition of the SbgnPort class.
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
 * @class SbgnPort
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnPort class.
 */


#ifndef SbgnPort_H__
#define SbgnPort_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnPort : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  double mX;
  bool mIsSetX;
  double mY;
  bool mIsSetY;

  /** @endcond */

public:

  /**
   * Creates a new SbgnPort using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnPort.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnPort.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnPort(unsigned int level = SBGN_DEFAULT_LEVEL,
           unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnPort using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnPort(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnPort.
   *
   * @param orig the SbgnPort instance to copy.
   */
  SbgnPort(const SbgnPort& orig);


  /**
   * Assignment operator for SbgnPort.
   *
   * @param rhs the SbgnPort object whose values are to be used as the basis of
   * the assignment.
   */
  SbgnPort& operator=(const SbgnPort& rhs);


  /**
   * Creates and returns a deep copy of this SbgnPort object.
   *
   * @return a (deep) copy of this SbgnPort object.
   */
  virtual SbgnPort* clone() const;


  /**
   * Destructor for SbgnPort.
   */
  virtual ~SbgnPort();


  /**
   * Returns the value of the "id" attribute of this SbgnPort.
   *
   * @return the value of the "id" attribute of this SbgnPort as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "x" attribute of this SbgnPort.
   *
   * @return the value of the "x" attribute of this SbgnPort as a double.
   */
  double getX() const;


  /**
   * Returns the value of the "y" attribute of this SbgnPort.
   *
   * @return the value of the "y" attribute of this SbgnPort as a double.
   */
  double getY() const;


  /**
   * Predicate returning @c true if this SbgnPort's "id" attribute is set.
   *
   * @return @c true if this SbgnPort's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SbgnPort's "x" attribute is set.
   *
   * @return @c true if this SbgnPort's "x" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetX() const;


  /**
   * Predicate returning @c true if this SbgnPort's "y" attribute is set.
   *
   * @return @c true if this SbgnPort's "y" attribute has been set, otherwise
   * @c false is returned.
   */
  bool isSetY() const;


  /**
   * Sets the value of the "id" attribute of this SbgnPort.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "x" attribute of this SbgnPort.
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
   * Sets the value of the "y" attribute of this SbgnPort.
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
   * Unsets the value of the "id" attribute of this SbgnPort.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "x" attribute of this SbgnPort.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetX();


  /**
   * Unsets the value of the "y" attribute of this SbgnPort.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetY();


  /**
   * Returns the XML element name of this SbgnPort object.
   *
   * For SbgnPort, the XML element name is always @c "port".
   *
   * @return the name of this element, i.e. @c "port".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnPort object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_PORT, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnPort object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnPort have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnPort object are:
   * @li "id"
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




  #ifndef SWIG



  /** @cond doxygenlibSBGNInternal */

  /**
   * Gets the value of the "attributeName" attribute of this SbgnPort.
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
   * Gets the value of the "attributeName" attribute of this SbgnPort.
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
   * Gets the value of the "attributeName" attribute of this SbgnPort.
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
   * Gets the value of the "attributeName" attribute of this SbgnPort.
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
   * Gets the value of the "attributeName" attribute of this SbgnPort.
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
   * Predicate returning @c true if this SbgnPort's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnPort's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnPort.
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
   * Sets the value of the "attributeName" attribute of this SbgnPort.
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
   * Sets the value of the "attributeName" attribute of this SbgnPort.
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
   * Sets the value of the "attributeName" attribute of this SbgnPort.
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
   * Sets the value of the "attributeName" attribute of this SbgnPort.
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
   * Unsets the value of the "attributeName" attribute of this SbgnPort.
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
 * Creates a new SbgnPort_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnPort_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnPort_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
SbgnPort_t *
SbgnPort_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnPort_t object.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @return a (deep) copy of this SbgnPort_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnPort_clone(const SbgnPort_t* sp);


/**
 * Frees this SbgnPort_t object.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
void
SbgnPort_free(SbgnPort_t* sp);


/**
 * Returns the value of the "id" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SbgnPort_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
char *
SbgnPort_getId(const SbgnPort_t * sp);


/**
 * Returns the value of the "x" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure whose x is sought.
 *
 * @return the value of the "x" attribute of this SbgnPort_t as a double.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
double
SbgnPort_getX(const SbgnPort_t * sp);


/**
 * Returns the value of the "y" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure whose y is sought.
 *
 * @return the value of the "y" attribute of this SbgnPort_t as a double.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
double
SbgnPort_getY(const SbgnPort_t * sp);


/**
 * Predicate returning @c 1 (true) if this SbgnPort_t's "id" attribute is set.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @return @c 1 (true) if this SbgnPort_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetId(const SbgnPort_t * sp);


/**
 * Predicate returning @c 1 (true) if this SbgnPort_t's "x" attribute is set.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @return @c 1 (true) if this SbgnPort_t's "x" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetX(const SbgnPort_t * sp);


/**
 * Predicate returning @c 1 (true) if this SbgnPort_t's "y" attribute is set.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @return @c 1 (true) if this SbgnPort_t's "y" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetY(const SbgnPort_t * sp);


/**
 * Sets the value of the "id" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_setId(SbgnPort_t * sp, const char * id);


/**
 * Sets the value of the "x" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @param x double value of the "x" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_setX(SbgnPort_t * sp, double x);


/**
 * Sets the value of the "y" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @param y double value of the "y" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_setY(SbgnPort_t * sp, double y);


/**
 * Unsets the value of the "id" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetId(SbgnPort_t * sp);


/**
 * Unsets the value of the "x" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetX(SbgnPort_t * sp);


/**
 * Unsets the value of the "y" attribute of this SbgnPort_t.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetY(SbgnPort_t * sp);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnPort_t object have been set.
 *
 * @param sp the SbgnPort_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnPort_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnPort_t object are:
 * @li "id"
 * @li "x"
 * @li "y"
 *
 * @memberof SbgnPort_t
 */
LIBSBGN_EXTERN
int
SbgnPort_hasRequiredAttributes(const SbgnPort_t * sp);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnPort_H__ */



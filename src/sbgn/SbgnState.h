/**
 * @file SbgnState.h
 * @brief Definition of the SbgnState class.
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
 * @class SbgnState
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnState class.
 */


#ifndef SbgnState_H__
#define SbgnState_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnState : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mVariable;
  std::string mValue;

  /** @endcond */

public:

  /**
   * Creates a new SbgnState using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnState.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnState.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnState(unsigned int level = SBGN_DEFAULT_LEVEL,
            unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnState using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnState(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnState.
   *
   * @param orig the SbgnState instance to copy.
   */
  SbgnState(const SbgnState& orig);


  /**
   * Assignment operator for SbgnState.
   *
   * @param rhs the SbgnState object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnState& operator=(const SbgnState& rhs);


  /**
   * Creates and returns a deep copy of this SbgnState object.
   *
   * @return a (deep) copy of this SbgnState object.
   */
  virtual SbgnState* clone() const;


  /**
   * Destructor for SbgnState.
   */
  virtual ~SbgnState();


  /**
   * Returns the value of the "variable" attribute of this SbgnState.
   *
   * @return the value of the "variable" attribute of this SbgnState as a
   * string.
   */
  const std::string& getVariable() const;


  /**
   * Returns the value of the "value" attribute of this SbgnState.
   *
   * @return the value of the "value" attribute of this SbgnState as a string.
   */
  const std::string& getValue() const;


  /**
   * Predicate returning @c true if this SbgnState's "variable" attribute is
   * set.
   *
   * @return @c true if this SbgnState's "variable" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetVariable() const;


  /**
   * Predicate returning @c true if this SbgnState's "value" attribute is set.
   *
   * @return @c true if this SbgnState's "value" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetValue() const;


  /**
   * Sets the value of the "variable" attribute of this SbgnState.
   *
   * @param variable std::string& value of the "variable" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p variable = @c NULL or an empty string is
   * equivalent to calling unsetVariable().
   */
  int setVariable(const std::string& variable);


  /**
   * Sets the value of the "value" attribute of this SbgnState.
   *
   * @param value std::string& value of the "value" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p value = @c NULL or an empty string is
   * equivalent to calling unsetValue().
   */
  int setValue(const std::string& value);


  /**
   * Unsets the value of the "variable" attribute of this SbgnState.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetVariable();


  /**
   * Unsets the value of the "value" attribute of this SbgnState.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetValue();


  /**
   * Returns the XML element name of this SbgnState object.
   *
   * For SbgnState, the XML element name is always @c "state".
   *
   * @return the name of this element, i.e. @c "state".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnState object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_STATE, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnState object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnState have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SbgnState.
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
   * Gets the value of the "attributeName" attribute of this SbgnState.
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
   * Gets the value of the "attributeName" attribute of this SbgnState.
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
   * Gets the value of the "attributeName" attribute of this SbgnState.
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
   * Gets the value of the "attributeName" attribute of this SbgnState.
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
   * Predicate returning @c true if this SbgnState's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnState's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnState.
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
   * Sets the value of the "attributeName" attribute of this SbgnState.
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
   * Sets the value of the "attributeName" attribute of this SbgnState.
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
   * Sets the value of the "attributeName" attribute of this SbgnState.
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
   * Sets the value of the "attributeName" attribute of this SbgnState.
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
   * Unsets the value of the "attributeName" attribute of this SbgnState.
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
 * Creates a new SbgnState_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnState_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnState_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
SbgnState_t *
SbgnState_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnState_t object.
 *
 * @param ss the SbgnState_t structure.
 *
 * @return a (deep) copy of this SbgnState_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
SbgnState_t*
SbgnState_clone(const SbgnState_t* ss);


/**
 * Frees this SbgnState_t object.
 *
 * @param ss the SbgnState_t structure.
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
void
SbgnState_free(SbgnState_t* ss);


/**
 * Returns the value of the "variable" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure whose variable is sought.
 *
 * @return the value of the "variable" attribute of this SbgnState_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
char *
SbgnState_getVariable(const SbgnState_t * ss);


/**
 * Returns the value of the "value" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure whose value is sought.
 *
 * @return the value of the "value" attribute of this SbgnState_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
char *
SbgnState_getValue(const SbgnState_t * ss);


/**
 * Predicate returning @c 1 (true) if this SbgnState_t's "variable" attribute
 * is set.
 *
 * @param ss the SbgnState_t structure.
 *
 * @return @c 1 (true) if this SbgnState_t's "variable" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_isSetVariable(const SbgnState_t * ss);


/**
 * Predicate returning @c 1 (true) if this SbgnState_t's "value" attribute is
 * set.
 *
 * @param ss the SbgnState_t structure.
 *
 * @return @c 1 (true) if this SbgnState_t's "value" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_isSetValue(const SbgnState_t * ss);


/**
 * Sets the value of the "variable" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure.
 *
 * @param variable const char * value of the "variable" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p variable = @c NULL or an empty string is
 * equivalent to calling SbgnState_unsetVariable().
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_setVariable(SbgnState_t * ss, const char * variable);


/**
 * Sets the value of the "value" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure.
 *
 * @param value const char * value of the "value" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p value = @c NULL or an empty string is
 * equivalent to calling SbgnState_unsetValue().
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_setValue(SbgnState_t * ss, const char * value);


/**
 * Unsets the value of the "variable" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_unsetVariable(SbgnState_t * ss);


/**
 * Unsets the value of the "value" attribute of this SbgnState_t.
 *
 * @param ss the SbgnState_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_unsetValue(SbgnState_t * ss);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnState_t object have been set.
 *
 * @param ss the SbgnState_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnState_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnState_t
 */
LIBSBGN_EXTERN
int
SbgnState_hasRequiredAttributes(const SbgnState_t * ss);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnState_H__ */



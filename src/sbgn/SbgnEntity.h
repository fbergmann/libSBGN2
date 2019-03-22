/**
 * @file SbgnEntity.h
 * @brief Definition of the SbgnEntity class.
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
 * @class SbgnEntity
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnEntity class.
 */


#ifndef SbgnEntity_H__
#define SbgnEntity_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnEntity : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mName;

  /** @endcond */

public:

  /**
   * Creates a new SbgnEntity using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnEntity.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnEntity.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnEntity(unsigned int level = SBGN_DEFAULT_LEVEL,
             unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnEntity using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnEntity(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnEntity.
   *
   * @param orig the SbgnEntity instance to copy.
   */
  SbgnEntity(const SbgnEntity& orig);


  /**
   * Assignment operator for SbgnEntity.
   *
   * @param rhs the SbgnEntity object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnEntity& operator=(const SbgnEntity& rhs);


  /**
   * Creates and returns a deep copy of this SbgnEntity object.
   *
   * @return a (deep) copy of this SbgnEntity object.
   */
  virtual SbgnEntity* clone() const;


  /**
   * Destructor for SbgnEntity.
   */
  virtual ~SbgnEntity();


  /**
   * Returns the value of the "name" attribute of this SbgnEntity.
   *
   * @return the value of the "name" attribute of this SbgnEntity as a string.
   */
  virtual const std::string& getName() const;


  /**
   * Predicate returning @c true if this SbgnEntity's "name" attribute is set.
   *
   * @return @c true if this SbgnEntity's "name" attribute has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetName() const;


  /**
   * Sets the value of the "name" attribute of this SbgnEntity.
   *
   * @param name std::string& value of the "name" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p name = @c NULL or an empty string is
   * equivalent to calling unsetName().
   */
  virtual int setName(const std::string& name);


  /**
   * Unsets the value of the "name" attribute of this SbgnEntity.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetName();


  /**
   * Returns the XML element name of this SbgnEntity object.
   *
   * For SbgnEntity, the XML element name is always @c "entity".
   *
   * @return the name of this element, i.e. @c "entity".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnEntity object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_ENTITY, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnEntity object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnEntity have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnEntity object are:
   * @li "name"
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
   * Gets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Gets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Gets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Gets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Gets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Predicate returning @c true if this SbgnEntity's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnEntity's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Sets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Sets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Sets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Sets the value of the "attributeName" attribute of this SbgnEntity.
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
   * Unsets the value of the "attributeName" attribute of this SbgnEntity.
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
 * Creates a new SbgnEntity_t using the given SBGN Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnEntity_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnEntity_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
SbgnEntity_t *
SbgnEntity_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnEntity_t object.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @return a (deep) copy of this SbgnEntity_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
SbgnEntity_t*
SbgnEntity_clone(const SbgnEntity_t* se);


/**
 * Frees this SbgnEntity_t object.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
void
SbgnEntity_free(SbgnEntity_t* se);


/**
 * Returns the value of the "name" attribute of this SbgnEntity_t.
 *
 * @param se the SbgnEntity_t structure whose name is sought.
 *
 * @return the value of the "name" attribute of this SbgnEntity_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
char *
SbgnEntity_getName(const SbgnEntity_t * se);


/**
 * Predicate returning @c 1 (true) if this SbgnEntity_t's "name" attribute is
 * set.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @return @c 1 (true) if this SbgnEntity_t's "name" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
int
SbgnEntity_isSetName(const SbgnEntity_t * se);


/**
 * Sets the value of the "name" attribute of this SbgnEntity_t.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @param name const char * value of the "name" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p name = @c NULL or an empty string is
 * equivalent to calling SbgnEntity_unsetName().
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
int
SbgnEntity_setName(SbgnEntity_t * se, const char * name);


/**
 * Unsets the value of the "name" attribute of this SbgnEntity_t.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
int
SbgnEntity_unsetName(SbgnEntity_t * se);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnEntity_t object have been set.
 *
 * @param se the SbgnEntity_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnEntity_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnEntity_t object are:
 * @li "name"
 *
 * @memberof SbgnEntity_t
 */
LIBSBGN_EXTERN
int
SbgnEntity_hasRequiredAttributes(const SbgnEntity_t * se);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnEntity_H__ */



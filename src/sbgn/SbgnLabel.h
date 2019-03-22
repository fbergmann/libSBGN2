/**
 * @file SbgnLabel.h
 * @brief Definition of the SbgnLabel class.
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
 * @class SbgnLabel
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnLabel class.
 */


#ifndef SbgnLabel_H__
#define SbgnLabel_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnBBox.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnLabel : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mText;
  SbgnBBox* mBBox;

  /** @endcond */

public:

  /**
   * Creates a new SbgnLabel using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnLabel.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnLabel.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnLabel(unsigned int level = SBGN_DEFAULT_LEVEL,
            unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnLabel using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnLabel(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnLabel.
   *
   * @param orig the SbgnLabel instance to copy.
   */
  SbgnLabel(const SbgnLabel& orig);


  /**
   * Assignment operator for SbgnLabel.
   *
   * @param rhs the SbgnLabel object whose values are to be used as the basis
   * of the assignment.
   */
  SbgnLabel& operator=(const SbgnLabel& rhs);


  /**
   * Creates and returns a deep copy of this SbgnLabel object.
   *
   * @return a (deep) copy of this SbgnLabel object.
   */
  virtual SbgnLabel* clone() const;


  /**
   * Destructor for SbgnLabel.
   */
  virtual ~SbgnLabel();


  /**
   * Returns the value of the "id" attribute of this SbgnLabel.
   *
   * @return the value of the "id" attribute of this SbgnLabel as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "text" attribute of this SbgnLabel.
   *
   * @return the value of the "text" attribute of this SbgnLabel as a string.
   */
  const std::string& getText() const;


  /**
   * Predicate returning @c true if this SbgnLabel's "id" attribute is set.
   *
   * @return @c true if this SbgnLabel's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SbgnLabel's "text" attribute is set.
   *
   * @return @c true if this SbgnLabel's "text" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetText() const;


  /**
   * Sets the value of the "id" attribute of this SbgnLabel.
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
   * Sets the value of the "text" attribute of this SbgnLabel.
   *
   * @param text std::string& value of the "text" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   *
   * Calling this function with @p text = @c NULL or an empty string is
   * equivalent to calling unsetText().
   */
  int setText(const std::string& text);


  /**
   * Unsets the value of the "id" attribute of this SbgnLabel.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "text" attribute of this SbgnLabel.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetText();


  /**
   * Returns the value of the "bbox" element of this SbgnLabel.
   *
   * @return the value of the "bbox" element of this SbgnLabel as a SbgnBBox*.
   */
  const SbgnBBox* getBBox() const;


  /**
   * Returns the value of the "bbox" element of this SbgnLabel.
   *
   * @return the value of the "bbox" element of this SbgnLabel as a SbgnBBox*.
   */
  SbgnBBox* getBBox();


  /**
   * Predicate returning @c true if this SbgnLabel's "bbox" element is set.
   *
   * @return @c true if this SbgnLabel's "bbox" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetBBox() const;


  /**
   * Sets the value of the "bbox" element of this SbgnLabel.
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
   * Creates a new SbgnBBox object, adds it to this SbgnLabel object and
   * returns the SbgnBBox object created.
   *
   * @return a new SbgnBBox object instance.
   */
  SbgnBBox* createBBox();


  /**
   * Unsets the value of the "bbox" element of this SbgnLabel.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetBBox();


  /**
   * Returns the XML element name of this SbgnLabel object.
   *
   * For SbgnLabel, the XML element name is always @c "label".
   *
   * @return the name of this element, i.e. @c "label".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnLabel object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_LABEL, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnLabel object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnLabel have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnLabel object are:
   * @li "text"
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
   * Gets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Gets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Gets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Gets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Gets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Predicate returning @c true if this SbgnLabel's attribute "attributeName"
   * is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnLabel's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Sets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Sets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Sets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Sets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Unsets the value of the "attributeName" attribute of this SbgnLabel.
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
   * Creates and returns an new "elementName" object in this SbgnLabel.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnLabel.
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
   * SbgnLabel.
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
   * Returns the number of "elementName" in this SbgnLabel.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnLabel.
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
 * Creates a new SbgnLabel_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnLabel_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnLabel_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
SbgnLabel_t *
SbgnLabel_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnLabel_t object.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @return a (deep) copy of this SbgnLabel_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
SbgnLabel_t*
SbgnLabel_clone(const SbgnLabel_t* sl);


/**
 * Frees this SbgnLabel_t object.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
void
SbgnLabel_free(SbgnLabel_t* sl);


/**
 * Returns the value of the "id" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SbgnLabel_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
char *
SbgnLabel_getId(const SbgnLabel_t * sl);


/**
 * Returns the value of the "text" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure whose text is sought.
 *
 * @return the value of the "text" attribute of this SbgnLabel_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
char *
SbgnLabel_getText(const SbgnLabel_t * sl);


/**
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "id" attribute is set.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @return @c 1 (true) if this SbgnLabel_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetId(const SbgnLabel_t * sl);


/**
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "text" attribute is
 * set.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @return @c 1 (true) if this SbgnLabel_t's "text" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetText(const SbgnLabel_t * sl);


/**
 * Sets the value of the "id" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p id = @c NULL or an empty string is equivalent
 * to calling SbgnLabel_unsetId().
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_setId(SbgnLabel_t * sl, const char * id);


/**
 * Sets the value of the "text" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @param text const char * value of the "text" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p text = @c NULL or an empty string is
 * equivalent to calling SbgnLabel_unsetText().
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_setText(SbgnLabel_t * sl, const char * text);


/**
 * Unsets the value of the "id" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetId(SbgnLabel_t * sl);


/**
 * Unsets the value of the "text" attribute of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetText(SbgnLabel_t * sl);


/**
 * Returns the value of the "bbox" element of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure whose bbox is sought.
 *
 * @return the value of the "bbox" element of this SbgnLabel_t as a SbgnBBox*.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnLabel_getBBox(const SbgnLabel_t * sl);


/**
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "bbox" element is set.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @return @c 1 (true) if this SbgnLabel_t's "bbox" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetBBox(const SbgnLabel_t * sl);


/**
 * Sets the value of the "bbox" element of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @param bbox SbgnBBox_t* value of the "bbox" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_setBBox(SbgnLabel_t * sl, const SbgnBBox_t* bbox);


/**
 * Creates a new SbgnBBox_t object, adds it to this SbgnLabel_t object and
 * returns the SbgnBBox_t object created.
 *
 * @param sl the SbgnLabel_t structure to which the SbgnBBox_t should be added.
 *
 * @return a new SbgnBBox_t object instance.
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnLabel_createBBox(SbgnLabel_t* sl);


/**
 * Unsets the value of the "bbox" element of this SbgnLabel_t.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetBBox(SbgnLabel_t * sl);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnLabel_t object have been set.
 *
 * @param sl the SbgnLabel_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnLabel_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnLabel_t object are:
 * @li "text"
 *
 * @memberof SbgnLabel_t
 */
LIBSBGN_EXTERN
int
SbgnLabel_hasRequiredAttributes(const SbgnLabel_t * sl);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnLabel_H__ */



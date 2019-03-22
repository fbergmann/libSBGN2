/**
 * @file SbgnDocument.h
 * @brief Definition of the SbgnDocument class.
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
 * @class SbgnDocument
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnDocument class.
 */


#ifndef SbgnDocument_H__
#define SbgnDocument_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnListOfMaps.h>
#include <sbgn/SbgnErrorLog.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnDocument : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  SbgnListOfMaps mMaps;
  SbgnErrorLog mErrorLog;

  /** @endcond */

public:

  /**
   * Creates a new SbgnDocument using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnDocument.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnDocument.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnDocument(unsigned int level = SBGN_DEFAULT_LEVEL,
               unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnDocument using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnDocument(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnDocument.
   *
   * @param orig the SbgnDocument instance to copy.
   */
  SbgnDocument(const SbgnDocument& orig);


  /**
   * Assignment operator for SbgnDocument.
   *
   * @param rhs the SbgnDocument object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnDocument& operator=(const SbgnDocument& rhs);


  /**
   * Creates and returns a deep copy of this SbgnDocument object.
   *
   * @return a (deep) copy of this SbgnDocument object.
   */
  virtual SbgnDocument* clone() const;


  /**
   * Destructor for SbgnDocument.
   */
  virtual ~SbgnDocument();


  /**
   * Returns the SbgnListOfMaps from this SbgnDocument.
   *
   * @return the SbgnListOfMaps from this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  const SbgnListOfMaps* getListOfMaps() const;


  /**
   * Returns the SbgnListOfMaps from this SbgnDocument.
   *
   * @return the SbgnListOfMaps from this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  SbgnListOfMaps* getListOfMaps();


  /**
   * Get a SbgnMap from the SbgnDocument.
   *
   * @param n an unsigned int representing the index of the SbgnMap to
   * retrieve.
   *
   * @return the nth SbgnMap in the SbgnListOfMaps within this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  SbgnMap* getMap(unsigned int n);


  /**
   * Get a SbgnMap from the SbgnDocument.
   *
   * @param n an unsigned int representing the index of the SbgnMap to
   * retrieve.
   *
   * @return the nth SbgnMap in the SbgnListOfMaps within this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  const SbgnMap* getMap(unsigned int n) const;


  /**
   * Get a SbgnMap from the SbgnDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnMap to
   * retrieve.
   *
   * @return the SbgnMap in the SbgnListOfMaps within this SbgnDocument with
   * the given @p sid or @c NULL if no such SbgnMap exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  SbgnMap* getMap(const std::string& sid);


  /**
   * Get a SbgnMap from the SbgnDocument based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnMap to
   * retrieve.
   *
   * @return the SbgnMap in the SbgnListOfMaps within this SbgnDocument with
   * the given @p sid or @c NULL if no such SbgnMap exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  const SbgnMap* getMap(const std::string& sid) const;


  /**
   * Adds a copy of the given SbgnMap to this SbgnDocument.
   *
   * @param sm the SbgnMap object to add.
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
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  int addMap(const SbgnMap* sm);


  /**
   * Get the number of SbgnMap objects in this SbgnDocument.
   *
   * @return the number of SbgnMap objects in this SbgnDocument.
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  unsigned int getNumMaps() const;


  /**
   * Creates a new SbgnMap object, adds it to this SbgnDocument object and
   * returns the SbgnMap object created.
   *
   * @return a new SbgnMap object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   * @see removeMap(unsigned int n)
   */
  SbgnMap* createMap();


  /**
   * Removes the nth SbgnMap from this SbgnDocument and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnMap to remove.
   *
   * @return a pointer to the nth SbgnMap in this SbgnDocument.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(const std::string& sid)
   */
  SbgnMap* removeMap(unsigned int n);


  /**
   * Removes the SbgnMap from this SbgnDocument based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnMap to remove.
   *
   * @return the SbgnMap in this SbgnDocument based on the identifier or NULL
   * if no such SbgnMap exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see getMap(const std::string& sid)
   * @see getMap(unsigned int n)
   * @see getNumMaps()
   * @see removeMap(unsigned int n)
   */
  SbgnMap* removeMap(const std::string& sid);


  /**
   * Returns the XML element name of this SbgnDocument object.
   *
   * For SbgnDocument, the XML element name is always @c "sbgn".
   *
   * @return the name of this element, i.e. @c "sbgn".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnDocument object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_DOCUMENT, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required elements for this
   * SbgnDocument object have been set.
   *
   * @return @c true to indicate that all the required elements of this
   * SbgnDocument have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SbgnDocument object are:
   * @li "map"
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
   * Gets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Gets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Gets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Gets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Gets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Predicate returning @c true if this SbgnDocument's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnDocument's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Sets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Sets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Sets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Sets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Unsets the value of the "attributeName" attribute of this SbgnDocument.
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
   * Creates and returns an new "elementName" object in this SbgnDocument.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnDocument.
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
   * SbgnDocument.
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
   * Returns the number of "elementName" in this SbgnDocument.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnDocument.
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


  /**
   * Returns the value of the "Namespaces" element of this SbgnDocument.
   *
   * @return the value of the "Namespaces" element of this SbgnDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces()
    const;


  /**
   * Returns the value of the "Namespaces" element of this SbgnDocument.
   *
   * @return the value of the "Namespaces" element of this SbgnDocument as a
   * LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*.
   */
  virtual LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* getNamespaces();


  /**
   * Returns the value of the "SbgnErrorLog" element of this SbgnDocument.
   *
   * @return the value of the "SbgnErrorLog" element of this SbgnDocument as a
   * SbgnErrorLog*.
   */
  const SbgnErrorLog* getErrorLog() const;


  /**
   * Returns the value of the "SbgnErrorLog" element of this SbgnDocument.
   *
   * @return the value of the "SbgnErrorLog" element of this SbgnDocument as a
   * SbgnErrorLog*.
   */
  SbgnErrorLog* getErrorLog();


  /**
   * Get a SbgnError from the SbgnDocument.
   *
   * @param n an unsigned int representing the index of the SbgnError to
   * retrieve.
   *
   * @return the nth SbgnError within this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  SbgnError* getError(unsigned int n);


  /**
   * Get a SbgnError from the SbgnDocument.
   *
   * @param n an unsigned int representing the index of the SbgnError to
   * retrieve.
   *
   * @return the nth SbgnError within this SbgnDocument.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see getNumErrors()
   */
  const SbgnError* getError(unsigned int n) const;


  /**
   * Get the number of SbgnError objects in this SbgnDocument.
   *
   * @return the number of SbgnError objects in this SbgnDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors() const;


  /**
   * Get the number of SbgnError objects in this SbgnDocument with the given
   * severity.
   *
   * @param severity the severity of the SbgnError to return.
   *
   * @return the number of SbgnError objects in this SbgnDocument.
   *
   * @see getError(unsigned int n)
   */
  unsigned int getNumErrors(unsigned int severity) const;


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
   * Writes the namespace for the Sbgnml package
   */
  virtual void writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
    stream) const;

  /** @endcond */


};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Creates a new SbgnDocument_t using the given SBGN Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this
 * SbgnDocument_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnDocument_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnDocument_t *
SbgnDocument_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnDocument_t object.
 *
 * @param sd the SbgnDocument_t structure.
 *
 * @return a (deep) copy of this SbgnDocument_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnDocument_t*
SbgnDocument_clone(const SbgnDocument_t* sd);


/**
 * Frees this SbgnDocument_t object.
 *
 * @param sd the SbgnDocument_t structure.
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
void
SbgnDocument_free(SbgnDocument_t* sd);


/**
 * Returns a ListOf_t * containing SbgnMap_t objects from this SbgnDocument_t.
 *
 * @param sd the SbgnDocument_t structure whose SbgnListOfMaps is sought.
 *
 * @return the SbgnListOfMaps from this SbgnDocument_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnDocument_addMap()
 * @see SbgnDocument_createMap()
 * @see SbgnDocument_getMapById()
 * @see SbgnDocument_getMap()
 * @see SbgnDocument_getNumMaps()
 * @see SbgnDocument_removeMapById()
 * @see SbgnDocument_removeMap()
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnDocument_getListOfMaps(SbgnDocument_t* sd);


/**
 * Get a SbgnMap_t from the SbgnDocument_t.
 *
 * @param sd the SbgnDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnMap_t to
 * retrieve.
 *
 * @return the nth SbgnMap_t in the SbgnListOfMaps within this SbgnDocument.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_getMap(SbgnDocument_t* sd, unsigned int n);


/**
 * Get a SbgnMap_t from the SbgnDocument_t based on its identifier.
 *
 * @param sd the SbgnDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnMap_t to
 * retrieve.
 *
 * @return the SbgnMap_t in the SbgnListOfMaps within this SbgnDocument with
 * the given @p sid or @c NULL if no such SbgnMap_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_getMapById(SbgnDocument_t* sd, const char *sid);


/**
 * Adds a copy of the given SbgnMap_t to this SbgnDocument_t.
 *
 * @param sd the SbgnDocument_t structure to which the SbgnMap_t should be
 * added.
 *
 * @param sm the SbgnMap_t object to add.
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
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
int
SbgnDocument_addMap(SbgnDocument_t* sd, const SbgnMap_t* sm);


/**
 * Get the number of SbgnMap_t objects in this SbgnDocument_t.
 *
 * @param sd the SbgnDocument_t structure to query.
 *
 * @return the number of SbgnMap_t objects in this SbgnDocument_t.
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnDocument_getNumMaps(SbgnDocument_t* sd);


/**
 * Creates a new SbgnMap_t object, adds it to this SbgnDocument_t object and
 * returns the SbgnMap_t object created.
 *
 * @param sd the SbgnDocument_t structure to which the SbgnMap_t should be
 * added.
 *
 * @return a new SbgnMap_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_createMap(SbgnDocument_t* sd);


/**
 * Removes the nth SbgnMap_t from this SbgnDocument_t and returns a pointer to
 * it.
 *
 * @param sd the SbgnDocument_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnMap_t to remove.
 *
 * @return a pointer to the nth SbgnMap_t in this SbgnDocument_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_removeMap(SbgnDocument_t* sd, unsigned int n);


/**
 * Removes the SbgnMap_t from this SbgnDocument_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sd the SbgnDocument_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnMap_t to remove.
 *
 * @return the SbgnMap_t in this SbgnDocument_t based on the identifier or NULL
 * if no such SbgnMap_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_removeMapById(SbgnDocument_t* sd, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnDocument_t object have been set.
 *
 * @param sd the SbgnDocument_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SbgnDocument_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SbgnDocument_t object are:
 * @li "map"
 *
 * @memberof SbgnDocument_t
 */
LIBSBGN_EXTERN
int
SbgnDocument_hasRequiredElements(const SbgnDocument_t * sd);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnDocument_H__ */



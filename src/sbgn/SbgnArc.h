/**
 * @file SbgnArc.h
 * @brief Definition of the SbgnArc class.
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
 * @class SbgnArc
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnArc class.
 */


#ifndef SbgnArc_H__
#define SbgnArc_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnPoint.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbgn/SbgnListOfPoints.h>
#include <sbgn/SbgnListOfPorts.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnArc : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mClazz;
  std::string mSource;
  std::string mTarget;
  SbgnListOfGlyphs mGlyphs;
  SbgnPoint* mStart;
  SbgnListOfPoints mPoints;
  SbgnPoint* mEnd;
  SbgnListOfPorts mPorts;

  /** @endcond */

public:

  /**
   * Creates a new SbgnArc using the given SBGN Level and @ p version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this SbgnArc.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnArc.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnArc(unsigned int level = SBGN_DEFAULT_LEVEL,
          unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnArc using the given SbgnNamespaces object @p sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnArc(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnArc.
   *
   * @param orig the SbgnArc instance to copy.
   */
  SbgnArc(const SbgnArc& orig);


  /**
   * Assignment operator for SbgnArc.
   *
   * @param rhs the SbgnArc object whose values are to be used as the basis of
   * the assignment.
   */
  SbgnArc& operator=(const SbgnArc& rhs);


  /**
   * Creates and returns a deep copy of this SbgnArc object.
   *
   * @return a (deep) copy of this SbgnArc object.
   */
  virtual SbgnArc* clone() const;


  /**
   * Destructor for SbgnArc.
   */
  virtual ~SbgnArc();


  /**
   * Returns the value of the "id" attribute of this SbgnArc.
   *
   * @return the value of the "id" attribute of this SbgnArc as a string.
   */
  virtual const std::string& getId() const;


  /**
   * Returns the value of the "class" attribute of this SbgnArc.
   *
   * @return the value of the "class" attribute of this SbgnArc as a string.
   */
  const std::string& getClazz() const;


  /**
   * Returns the value of the "source" attribute of this SbgnArc.
   *
   * @return the value of the "source" attribute of this SbgnArc as a string.
   */
  const std::string& getSource() const;


  /**
   * Returns the value of the "target" attribute of this SbgnArc.
   *
   * @return the value of the "target" attribute of this SbgnArc as a string.
   */
  const std::string& getTarget() const;


  /**
   * Predicate returning @c true if this SbgnArc's "id" attribute is set.
   *
   * @return @c true if this SbgnArc's "id" attribute has been set, otherwise
   * @c false is returned.
   */
  virtual bool isSetId() const;


  /**
   * Predicate returning @c true if this SbgnArc's "class" attribute is set.
   *
   * @return @c true if this SbgnArc's "class" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetClazz() const;


  /**
   * Predicate returning @c true if this SbgnArc's "source" attribute is set.
   *
   * @return @c true if this SbgnArc's "source" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetSource() const;


  /**
   * Predicate returning @c true if this SbgnArc's "target" attribute is set.
   *
   * @return @c true if this SbgnArc's "target" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetTarget() const;


  /**
   * Sets the value of the "id" attribute of this SbgnArc.
   *
   * @param id std::string& value of the "id" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int setId(const std::string& id);


  /**
   * Sets the value of the "class" attribute of this SbgnArc.
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
   * Sets the value of the "source" attribute of this SbgnArc.
   *
   * @param source std::string& value of the "source" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setSource(const std::string& source);


  /**
   * Sets the value of the "target" attribute of this SbgnArc.
   *
   * @param target std::string& value of the "target" attribute to be set.
   *
   * @copydetails doc_returns_one_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  int setTarget(const std::string& target);


  /**
   * Unsets the value of the "id" attribute of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  virtual int unsetId();


  /**
   * Unsets the value of the "class" attribute of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClazz();


  /**
   * Unsets the value of the "source" attribute of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetSource();


  /**
   * Unsets the value of the "target" attribute of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetTarget();


  /**
   * Returns the value of the "start" element of this SbgnArc.
   *
   * @return the value of the "start" element of this SbgnArc as a SbgnPoint*.
   */
  const SbgnPoint* getStart() const;


  /**
   * Returns the value of the "start" element of this SbgnArc.
   *
   * @return the value of the "start" element of this SbgnArc as a SbgnPoint*.
   */
  SbgnPoint* getStart();


  /**
   * Returns the value of the "end" element of this SbgnArc.
   *
   * @return the value of the "end" element of this SbgnArc as a SbgnPoint*.
   */
  const SbgnPoint* getEnd() const;


  /**
   * Returns the value of the "end" element of this SbgnArc.
   *
   * @return the value of the "end" element of this SbgnArc as a SbgnPoint*.
   */
  SbgnPoint* getEnd();


  /**
   * Predicate returning @c true if this SbgnArc's "start" element is set.
   *
   * @return @c true if this SbgnArc's "start" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetStart() const;


  /**
   * Predicate returning @c true if this SbgnArc's "end" element is set.
   *
   * @return @c true if this SbgnArc's "end" element has been set, otherwise
   * @c false is returned.
   */
  bool isSetEnd() const;


  /**
   * Sets the value of the "start" element of this SbgnArc.
   *
   * @param start SbgnPoint* value of the "start" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setStart(const SbgnPoint* start);


  /**
   * Sets the value of the "end" element of this SbgnArc.
   *
   * @param end SbgnPoint* value of the "end" element to be set.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE,
   * OperationReturnValues_t}
   */
  int setEnd(const SbgnPoint* end);


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
   * the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   */
  SbgnPoint* createStart();


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
   * the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   */
  SbgnPoint* createEnd();


  /**
   * Unsets the value of the "start" element of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetStart();


  /**
   * Unsets the value of the "end" element of this SbgnArc.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetEnd();


  /**
   * Returns the SbgnListOfGlyphs from this SbgnArc.
   *
   * @return the SbgnListOfGlyphs from this SbgnArc.
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
   * Returns the SbgnListOfGlyphs from this SbgnArc.
   *
   * @return the SbgnListOfGlyphs from this SbgnArc.
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
   * Get a SbgnGlyph from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this SbgnArc.
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
   * Get a SbgnGlyph from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this SbgnArc.
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
   * Get a SbgnGlyph from the SbgnArc based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnArc with the
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
   * Get a SbgnGlyph from the SbgnArc based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnArc with the
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
   * Get a SbgnGlyph from the SbgnArc based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArc based on the CompartmentRef to which it
   * refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnArc based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByMapRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArc based on the MapRef to which it refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByMapRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnArc based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByTagRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArc based on the TagRef to which it refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArc based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByTagRef(const std::string& sid);


  /**
   * Adds a copy of the given SbgnGlyph to this SbgnArc.
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
   * Get the number of SbgnGlyph objects in this SbgnArc.
   *
   * @return the number of SbgnGlyph objects in this SbgnArc.
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
   * Creates a new SbgnGlyph object, adds it to this SbgnArc object and returns
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
   * Removes the nth SbgnGlyph from this SbgnArc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * remove.
   *
   * @return a pointer to the nth SbgnGlyph in this SbgnArc.
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
   * Removes the SbgnGlyph from this SbgnArc based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * remove.
   *
   * @return the SbgnGlyph in this SbgnArc based on the identifier or NULL if
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
   * Returns the SbgnListOfPoints from this SbgnArc.
   *
   * @return the SbgnListOfPoints from this SbgnArc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  const SbgnListOfPoints* getListOfNexts() const;


  /**
   * Returns the SbgnListOfPoints from this SbgnArc.
   *
   * @return the SbgnListOfPoints from this SbgnArc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  SbgnListOfPoints* getListOfNexts();


  /**
   * Get a SbgnPoint from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in the SbgnListOfPoints within this SbgnArc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  SbgnPoint* getNext(unsigned int n);


  /**
   * Get a SbgnPoint from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in the SbgnListOfPoints within this SbgnArc.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  const SbgnPoint* getNext(unsigned int n) const;


  /**
   * Adds a copy of the given SbgnPoint to this SbgnArc.
   *
   * @param sp the SbgnPoint object to add.
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
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  int addNext(const SbgnPoint* sp);


  /**
   * Get the number of SbgnPoint objects in this SbgnArc.
   *
   * @return the number of SbgnPoint objects in this SbgnArc.
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  unsigned int getNumNexts() const;


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
   * the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   * @see removeNext(unsigned int n)
   */
  SbgnPoint* createNext();


  /**
   * Removes the nth SbgnPoint from this SbgnArc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * remove.
   *
   * @return a pointer to the nth SbgnPoint in this SbgnArc.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addNext(const SbgnPoint* object)
   * @see createNext()
   * @see getNext(const std::string& sid)
   * @see getNext(unsigned int n)
   * @see getNumNexts()
   * @see removeNext(const std::string& sid)
   */
  SbgnPoint* removeNext(unsigned int n);


  /**
   * Returns the SbgnListOfPorts from this SbgnArc.
   *
   * @return the SbgnListOfPorts from this SbgnArc.
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
   * Returns the SbgnListOfPorts from this SbgnArc.
   *
   * @return the SbgnListOfPorts from this SbgnArc.
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
   * Get a SbgnPort from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in the SbgnListOfPorts within this SbgnArc.
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
   * Get a SbgnPort from the SbgnArc.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in the SbgnListOfPorts within this SbgnArc.
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
   * Get a SbgnPort from the SbgnArc based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in the SbgnListOfPorts within this SbgnArc with the
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
   * Get a SbgnPort from the SbgnArc based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in the SbgnListOfPorts within this SbgnArc with the
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
   * Adds a copy of the given SbgnPort to this SbgnArc.
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
   * Get the number of SbgnPort objects in this SbgnArc.
   *
   * @return the number of SbgnPort objects in this SbgnArc.
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
   * Creates a new SbgnPort object, adds it to this SbgnArc object and returns
   * the SbgnPort object created.
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
   * Removes the nth SbgnPort from this SbgnArc and returns a pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnPort to remove.
   *
   * @return a pointer to the nth SbgnPort in this SbgnArc.
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
   * Removes the SbgnPort from this SbgnArc based on its identifier and returns
   * a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnPort to remove.
   *
   * @return the SbgnPort in this SbgnArc based on the identifier or NULL if no
   * such SbgnPort exists.
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
   * Returns the XML element name of this SbgnArc object.
   *
   * For SbgnArc, the XML element name is always @c "arc".
   *
   * @return the name of this element, i.e. @c "arc".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnArc object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_ARC, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnArc object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnArc have been set, otherwise @c false is returned.
   *
   *
   * @note The required attributes for the SbgnArc object are:
   * @li "id"
   * @li "class"
   * @li "source"
   * @li "target"
   */
  virtual bool hasRequiredAttributes() const;


  /**
   * Predicate returning @c true if all the required elements for this SbgnArc
   * object have been set.
   *
   * @return @c true to indicate that all the required elements of this SbgnArc
   * have been set, otherwise @c false is returned.
   *
   *
   * @note The required elements for the SbgnArc object are:
   * @li "start"
   * @li "end"
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
   * Gets the value of the "attributeName" attribute of this SbgnArc.
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
   * Gets the value of the "attributeName" attribute of this SbgnArc.
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
   * Gets the value of the "attributeName" attribute of this SbgnArc.
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
   * Gets the value of the "attributeName" attribute of this SbgnArc.
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
   * Gets the value of the "attributeName" attribute of this SbgnArc.
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
   * Predicate returning @c true if this SbgnArc's attribute "attributeName" is
   * set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnArc's attribute "attributeName" has been set,
   * otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnArc.
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
   * Sets the value of the "attributeName" attribute of this SbgnArc.
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
   * Sets the value of the "attributeName" attribute of this SbgnArc.
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
   * Sets the value of the "attributeName" attribute of this SbgnArc.
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
   * Sets the value of the "attributeName" attribute of this SbgnArc.
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
   * Unsets the value of the "attributeName" attribute of this SbgnArc.
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
   * Creates and returns an new "elementName" object in this SbgnArc.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnArc.
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
   * SbgnArc.
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
   * Returns the number of "elementName" in this SbgnArc.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnArc.
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
 * Creates a new SbgnArc_t using the given SBGN Level and @ p version values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this SbgnArc_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnArc_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnArc_t *
SbgnArc_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnArc_t object.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return a (deep) copy of this SbgnArc_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArc_clone(const SbgnArc_t* sa);


/**
 * Frees this SbgnArc_t object.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
void
SbgnArc_free(SbgnArc_t* sa);


/**
 * Returns the value of the "id" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose id is sought.
 *
 * @return the value of the "id" attribute of this SbgnArc_t as a pointer to a
 * string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
char *
SbgnArc_getId(const SbgnArc_t * sa);


/**
 * Returns the value of the "class" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose class is sought.
 *
 * @return the value of the "class" attribute of this SbgnArc_t as a pointer to
 * a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
char *
SbgnArc_getClazz(const SbgnArc_t * sa);


/**
 * Returns the value of the "source" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose source is sought.
 *
 * @return the value of the "source" attribute of this SbgnArc_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
char *
SbgnArc_getSource(const SbgnArc_t * sa);


/**
 * Returns the value of the "target" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose target is sought.
 *
 * @return the value of the "target" attribute of this SbgnArc_t as a pointer
 * to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
char *
SbgnArc_getTarget(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "id" attribute is set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "id" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetId(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "class" attribute is
 * set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "class" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetClazz(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "source" attribute is
 * set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "source" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetSource(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "target" attribute is
 * set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "target" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetTarget(const SbgnArc_t * sa);


/**
 * Sets the value of the "id" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param id const char * value of the "id" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setId(SbgnArc_t * sa, const char * id);


/**
 * Sets the value of the "class" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param clazz const char * value of the "class" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p clazz = @c NULL or an empty string is
 * equivalent to calling SbgnArc_unsetClazz().
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setClazz(SbgnArc_t * sa, const char * clazz);


/**
 * Sets the value of the "source" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param source const char * value of the "source" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setSource(SbgnArc_t * sa, const char * source);


/**
 * Sets the value of the "target" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param target const char * value of the "target" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setTarget(SbgnArc_t * sa, const char * target);


/**
 * Unsets the value of the "id" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetId(SbgnArc_t * sa);


/**
 * Unsets the value of the "class" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetClazz(SbgnArc_t * sa);


/**
 * Unsets the value of the "source" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetSource(SbgnArc_t * sa);


/**
 * Unsets the value of the "target" attribute of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetTarget(SbgnArc_t * sa);


/**
 * Returns the value of the "start" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose start is sought.
 *
 * @return the value of the "start" element of this SbgnArc_t as a SbgnPoint*.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnArc_getStart(const SbgnArc_t * sa);


/**
 * Returns the value of the "end" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose end is sought.
 *
 * @return the value of the "end" element of this SbgnArc_t as a SbgnPoint*.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnArc_getEnd(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "start" element is set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "start" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetStart(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if this SbgnArc_t's "end" element is set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) if this SbgnArc_t's "end" element has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetEnd(const SbgnArc_t * sa);


/**
 * Sets the value of the "start" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param start SbgnPoint_t* value of the "start" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setStart(SbgnArc_t * sa, const SbgnPoint_t* start);


/**
 * Sets the value of the "end" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @param end SbgnPoint_t* value of the "end" element to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_ATTRIBUTE_VALUE, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_setEnd(SbgnArc_t * sa, const SbgnPoint_t* end);


/**
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPoint_t should be added.
 *
 * @return a new SbgnPoint_t object instance.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createStart(SbgnArc_t* sa);


/**
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPoint_t should be added.
 *
 * @return a new SbgnPoint_t object instance.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createEnd(SbgnArc_t* sa);


/**
 * Unsets the value of the "start" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetStart(SbgnArc_t * sa);


/**
 * Unsets the value of the "end" element of this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetEnd(SbgnArc_t * sa);


/**
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose SbgnListOfGlyphs is sought.
 *
 * @return the SbgnListOfGlyphs from this SbgnArc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnArc_addGlyph()
 * @see SbgnArc_createGlyph()
 * @see SbgnArc_getGlyphById()
 * @see SbgnArc_getGlyph()
 * @see SbgnArc_getNumGlyphs()
 * @see SbgnArc_removeGlyphById()
 * @see SbgnArc_removeGlyph()
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfGlyphs(SbgnArc_t* sa);


/**
 * Get a SbgnGlyph_t from the SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the nth SbgnGlyph_t in the SbgnListOfGlyphs within this SbgnArc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyph(SbgnArc_t* sa, unsigned int n);


/**
 * Get a SbgnGlyph_t from the SbgnArc_t based on its identifier.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the SbgnGlyph_t in the SbgnListOfGlyphs within this SbgnArc with the
 * given @p sid or @c NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphById(SbgnArc_t* sa, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArc_t based on the CompartmentRef to which it
 * refers.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the "compartmentRef" attribute of the
 * SbgnGlyph_t object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArc_t based on the given
 * compartmentRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByCompartmentRef(SbgnArc_t* sa, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArc_t based on the MapRef to which it refers.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the "mapRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArc_t based on the given mapRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByMapRef(SbgnArc_t* sa, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArc_t based on the TagRef to which it refers.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the "tagRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArc_t based on the given tagRef
 * attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByTagRef(SbgnArc_t* sa, const char *sid);


/**
 * Adds a copy of the given SbgnGlyph_t to this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to which the SbgnGlyph_t should be added.
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
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_addGlyph(SbgnArc_t* sa, const SbgnGlyph_t* sg);


/**
 * Get the number of SbgnGlyph_t objects in this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to query.
 *
 * @return the number of SbgnGlyph_t objects in this SbgnArc_t.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumGlyphs(SbgnArc_t* sa);


/**
 * Creates a new SbgnGlyph_t object, adds it to this SbgnArc_t object and
 * returns the SbgnGlyph_t object created.
 *
 * @param sa the SbgnArc_t structure to which the SbgnGlyph_t should be added.
 *
 * @return a new SbgnGlyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_createGlyph(SbgnArc_t* sa);


/**
 * Removes the nth SbgnGlyph_t from this SbgnArc_t and returns a pointer to it.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * remove.
 *
 * @return a pointer to the nth SbgnGlyph_t in this SbgnArc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_removeGlyph(SbgnArc_t* sa, unsigned int n);


/**
 * Removes the SbgnGlyph_t from this SbgnArc_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * remove.
 *
 * @return the SbgnGlyph_t in this SbgnArc_t based on the identifier or NULL if
 * no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_removeGlyphById(SbgnArc_t* sa, const char* sid);


/**
 * Returns a ListOf_t * containing SbgnPoint_t objects from this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose SbgnListOfPoints is sought.
 *
 * @return the SbgnListOfPoints from this SbgnArc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnArc_addNext()
 * @see SbgnArc_createNext()
 * @see SbgnArc_getNextById()
 * @see SbgnArc_getNext()
 * @see SbgnArc_getNumNexts()
 * @see SbgnArc_removeNextById()
 * @see SbgnArc_removeNext()
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfNexts(SbgnArc_t* sa);


/**
 * Get a SbgnPoint_t from the SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * retrieve.
 *
 * @return the nth SbgnPoint_t in the SbgnListOfPoints within this SbgnArc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_getNext(SbgnArc_t* sa, unsigned int n);


/**
 * Adds a copy of the given SbgnPoint_t to this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPoint_t should be added.
 *
 * @param sp the SbgnPoint_t object to add.
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
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_addNext(SbgnArc_t* sa, const SbgnPoint_t* sp);


/**
 * Get the number of SbgnPoint_t objects in this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to query.
 *
 * @return the number of SbgnPoint_t objects in this SbgnArc_t.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumNexts(SbgnArc_t* sa);


/**
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPoint_t should be added.
 *
 * @return a new SbgnPoint_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createNext(SbgnArc_t* sa);


/**
 * Removes the nth SbgnPoint_t from this SbgnArc_t and returns a pointer to it.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * remove.
 *
 * @return a pointer to the nth SbgnPoint_t in this SbgnArc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_removeNext(SbgnArc_t* sa, unsigned int n);


/**
 * Returns a ListOf_t * containing SbgnPort_t objects from this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure whose SbgnListOfPorts is sought.
 *
 * @return the SbgnListOfPorts from this SbgnArc_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnArc_addPort()
 * @see SbgnArc_createPort()
 * @see SbgnArc_getPortById()
 * @see SbgnArc_getPort()
 * @see SbgnArc_getNumPorts()
 * @see SbgnArc_removePortById()
 * @see SbgnArc_removePort()
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfPorts(SbgnArc_t* sa);


/**
 * Get a SbgnPort_t from the SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to
 * retrieve.
 *
 * @return the nth SbgnPort_t in the SbgnListOfPorts within this SbgnArc.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_getPort(SbgnArc_t* sa, unsigned int n);


/**
 * Get a SbgnPort_t from the SbgnArc_t based on its identifier.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to
 * retrieve.
 *
 * @return the SbgnPort_t in the SbgnListOfPorts within this SbgnArc with the
 * given @p sid or @c NULL if no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_getPortById(SbgnArc_t* sa, const char *sid);


/**
 * Adds a copy of the given SbgnPort_t to this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPort_t should be added.
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
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_addPort(SbgnArc_t* sa, const SbgnPort_t* sp);


/**
 * Get the number of SbgnPort_t objects in this SbgnArc_t.
 *
 * @param sa the SbgnArc_t structure to query.
 *
 * @return the number of SbgnPort_t objects in this SbgnArc_t.
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumPorts(SbgnArc_t* sa);


/**
 * Creates a new SbgnPort_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPort_t object created.
 *
 * @param sa the SbgnArc_t structure to which the SbgnPort_t should be added.
 *
 * @return a new SbgnPort_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_createPort(SbgnArc_t* sa);


/**
 * Removes the nth SbgnPort_t from this SbgnArc_t and returns a pointer to it.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to remove.
 *
 * @return a pointer to the nth SbgnPort_t in this SbgnArc_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_removePort(SbgnArc_t* sa, unsigned int n);


/**
 * Removes the SbgnPort_t from this SbgnArc_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sa the SbgnArc_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to remove.
 *
 * @return the SbgnPort_t in this SbgnArc_t based on the identifier or NULL if
 * no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_removePortById(SbgnArc_t* sa, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnArc_t object have been set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnArc_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required attributes for the SbgnArc_t object are:
 * @li "id"
 * @li "class"
 * @li "source"
 * @li "target"
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_hasRequiredAttributes(const SbgnArc_t * sa);


/**
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnArc_t object have been set.
 *
 * @param sa the SbgnArc_t structure.
 *
 * @return @c 1 (true) to indicate that all the required elements of this
 * SbgnArc_t have been set, otherwise @c 0 (false) is returned.
 *
 *
 * @note The required elements for the SbgnArc_t object are:
 * @li "start"
 * @li "end"
 *
 * @memberof SbgnArc_t
 */
LIBSBGN_EXTERN
int
SbgnArc_hasRequiredElements(const SbgnArc_t * sa);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnArc_H__ */



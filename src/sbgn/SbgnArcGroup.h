/**
 * @file SbgnArcGroup.h
 * @brief Definition of the SbgnArcGroup class.
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
 * @class SbgnArcGroup
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnArcGroup class.
 */


#ifndef SbgnArcGroup_H__
#define SbgnArcGroup_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnBase.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbgn/SbgnListOfArcs.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnArcGroup : public SbgnBase
{
protected:

  /** @cond doxygenlibSBGNInternal */

  SbgnListOfGlyphs mGlyphs;
  SbgnListOfArcs mArcs;
  std::string mClazz;

  /** @endcond */

public:

  /**
   * Creates a new SbgnArcGroup using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnArcGroup.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnArcGroup.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnArcGroup(unsigned int level = SBGN_DEFAULT_LEVEL,
               unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnArcGroup using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnArcGroup(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnArcGroup.
   *
   * @param orig the SbgnArcGroup instance to copy.
   */
  SbgnArcGroup(const SbgnArcGroup& orig);


  /**
   * Assignment operator for SbgnArcGroup.
   *
   * @param rhs the SbgnArcGroup object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnArcGroup& operator=(const SbgnArcGroup& rhs);


  /**
   * Creates and returns a deep copy of this SbgnArcGroup object.
   *
   * @return a (deep) copy of this SbgnArcGroup object.
   */
  virtual SbgnArcGroup* clone() const;


  /**
   * Destructor for SbgnArcGroup.
   */
  virtual ~SbgnArcGroup();


  /**
   * Returns the value of the "class" attribute of this SbgnArcGroup.
   *
   * @return the value of the "class" attribute of this SbgnArcGroup as a
   * string.
   */
  const std::string& getClazz() const;


  /**
   * Predicate returning @c true if this SbgnArcGroup's "class" attribute is
   * set.
   *
   * @return @c true if this SbgnArcGroup's "class" attribute has been set,
   * otherwise @c false is returned.
   */
  bool isSetClazz() const;


  /**
   * Sets the value of the "class" attribute of this SbgnArcGroup.
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
   * Unsets the value of the "class" attribute of this SbgnArcGroup.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
   */
  int unsetClazz();


  /**
   * Returns the SbgnListOfGlyphs from this SbgnArcGroup.
   *
   * @return the SbgnListOfGlyphs from this SbgnArcGroup.
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
   * Returns the SbgnListOfGlyphs from this SbgnArcGroup.
   *
   * @return the SbgnListOfGlyphs from this SbgnArcGroup.
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
   * Get a SbgnGlyph from the SbgnArcGroup.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this
   * SbgnArcGroup.
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
   * Get a SbgnGlyph from the SbgnArcGroup.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in the SbgnListOfGlyphs within this
   * SbgnArcGroup.
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
   * Get a SbgnGlyph from the SbgnArcGroup based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnArcGroup
   * with the given @p sid or @c NULL if no such SbgnGlyph exists.
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
   * Get a SbgnGlyph from the SbgnArcGroup based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in the SbgnListOfGlyphs within this SbgnArcGroup
   * with the given @p sid or @c NULL if no such SbgnGlyph exists.
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
   * Get a SbgnGlyph from the SbgnArcGroup based on the CompartmentRef to which
   * it refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArcGroup based on the CompartmentRef to which
   * it refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByCompartmentRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnArcGroup based on the MapRef to which it
   * refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByMapRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArcGroup based on the MapRef to which it
   * refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given mapRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByMapRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnArcGroup based on the TagRef to which it
   * refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getGlyphByTagRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnArcGroup based on the TagRef to which it
   * refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnArcGroup based on the given tagRef
   * attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getGlyphByTagRef(const std::string& sid);


  /**
   * Adds a copy of the given SbgnGlyph to this SbgnArcGroup.
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
   * Get the number of SbgnGlyph objects in this SbgnArcGroup.
   *
   * @return the number of SbgnGlyph objects in this SbgnArcGroup.
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
   * Creates a new SbgnGlyph object, adds it to this SbgnArcGroup object and
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
   * Removes the nth SbgnGlyph from this SbgnArcGroup and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * remove.
   *
   * @return a pointer to the nth SbgnGlyph in this SbgnArcGroup.
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
   * Removes the SbgnGlyph from this SbgnArcGroup based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * remove.
   *
   * @return the SbgnGlyph in this SbgnArcGroup based on the identifier or NULL
   * if no such SbgnGlyph exists.
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
   * Returns the SbgnListOfArcs from this SbgnArcGroup.
   *
   * @return the SbgnListOfArcs from this SbgnArcGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnListOfArcs* getListOfArcs() const;


  /**
   * Returns the SbgnListOfArcs from this SbgnArcGroup.
   *
   * @return the SbgnListOfArcs from this SbgnArcGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnListOfArcs* getListOfArcs();


  /**
   * Get a SbgnArc from the SbgnArcGroup.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in the SbgnListOfArcs within this SbgnArcGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* getArc(unsigned int n);


  /**
   * Get a SbgnArc from the SbgnArcGroup.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in the SbgnListOfArcs within this SbgnArcGroup.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnArc* getArc(unsigned int n) const;


  /**
   * Get a SbgnArc from the SbgnArcGroup based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in the SbgnListOfArcs within this SbgnArcGroup with
   * the given @p sid or @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* getArc(const std::string& sid);


  /**
   * Get a SbgnArc from the SbgnArcGroup based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in the SbgnListOfArcs within this SbgnArcGroup with
   * the given @p sid or @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  const SbgnArc* getArc(const std::string& sid) const;


  /**
   * Adds a copy of the given SbgnArc to this SbgnArcGroup.
   *
   * @param sa the SbgnArc object to add.
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
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  int addArc(const SbgnArc* sa);


  /**
   * Get the number of SbgnArc objects in this SbgnArcGroup.
   *
   * @return the number of SbgnArc objects in this SbgnArcGroup.
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  unsigned int getNumArcs() const;


  /**
   * Creates a new SbgnArc object, adds it to this SbgnArcGroup object and
   * returns the SbgnArc object created.
   *
   * @return a new SbgnArc object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   * @see removeArc(unsigned int n)
   */
  SbgnArc* createArc();


  /**
   * Removes the nth SbgnArc from this SbgnArcGroup and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnArc to remove.
   *
   * @return a pointer to the nth SbgnArc in this SbgnArcGroup.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(const std::string& sid)
   */
  SbgnArc* removeArc(unsigned int n);


  /**
   * Removes the SbgnArc from this SbgnArcGroup based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnArc to remove.
   *
   * @return the SbgnArc in this SbgnArcGroup based on the identifier or NULL
   * if no such SbgnArc exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see getArc(const std::string& sid)
   * @see getArc(unsigned int n)
   * @see getNumArcs()
   * @see removeArc(unsigned int n)
   */
  SbgnArc* removeArc(const std::string& sid);


  /**
   * Returns the XML element name of this SbgnArcGroup object.
   *
   * For SbgnArcGroup, the XML element name is always @c "arcgroup".
   *
   * @return the name of this element, i.e. @c "arcgroup".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnArcGroup object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_SBGNML_ARCGROUP, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getTypeCode() const;


  /**
   * Predicate returning @c true if all the required attributes for this
   * SbgnArcGroup object have been set.
   *
   * @return @c true to indicate that all the required attributes of this
   * SbgnArcGroup have been set, otherwise @c false is returned.
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
   * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Predicate returning @c true if this SbgnArcGroup's attribute
   * "attributeName" is set.
   *
   * @param attributeName, the name of the attribute to query.
   *
   * @return @c true if this SbgnArcGroup's attribute "attributeName" has been
   * set, otherwise @c false is returned.
   */
  virtual bool isSetAttribute(const std::string& attributeName) const;

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Unsets the value of the "attributeName" attribute of this SbgnArcGroup.
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
   * Creates and returns an new "elementName" object in this SbgnArcGroup.
   *
   * @param elementName, the name of the element to create.
   *
   * @return pointer to the element created.
   */
  virtual SbgnBase* createChildObject(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Adds a new "elementName" object to this SbgnArcGroup.
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
   * SbgnArcGroup.
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
   * Returns the number of "elementName" in this SbgnArcGroup.
   *
   * @param elementName, the name of the element to get number of.
   *
   * @return unsigned int number of elements.
   */
  virtual unsigned int getNumObjects(const std::string& elementName);

  /** @endcond */



  /** @cond doxygenlibSBGNInternal */

  /**
   * Returns the nth object of "objectName" in this SbgnArcGroup.
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
 * Creates a new SbgnArcGroup_t using the given SBGN Level and @ p version
 * values.
 *
 * @param level an unsigned int, the SBGN Level to assign to this
 * SbgnArcGroup_t.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnArcGroup_t.
 *
 * @copydetails doc_note_setting_lv_pkg
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t *
SbgnArcGroup_create(unsigned int level, unsigned int version);


/**
 * Creates and returns a deep copy of this SbgnArcGroup_t object.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @return a (deep) copy of this SbgnArcGroup_t object.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnArcGroup_clone(const SbgnArcGroup_t* sag);


/**
 * Frees this SbgnArcGroup_t object.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
void
SbgnArcGroup_free(SbgnArcGroup_t* sag);


/**
 * Returns the value of the "class" attribute of this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure whose class is sought.
 *
 * @return the value of the "class" attribute of this SbgnArcGroup_t as a
 * pointer to a string.
 *
 * @copydetails doc_returned_owned_char
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
char *
SbgnArcGroup_getClazz(const SbgnArcGroup_t * sag);


/**
 * Predicate returning @c 1 (true) if this SbgnArcGroup_t's "class" attribute
 * is set.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @return @c 1 (true) if this SbgnArcGroup_t's "class" attribute has been set,
 * otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_isSetClazz(const SbgnArcGroup_t * sag);


/**
 * Sets the value of the "class" attribute of this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @param clazz const char * value of the "class" attribute to be set.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * Calling this function with @p clazz = @c NULL or an empty string is
 * equivalent to calling SbgnArcGroup_unsetClazz().
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_setClazz(SbgnArcGroup_t * sag, const char * clazz);


/**
 * Unsets the value of the "class" attribute of this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_OPERATION_FAILED, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_unsetClazz(SbgnArcGroup_t * sag);


/**
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this
 * SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure whose SbgnListOfGlyphs is sought.
 *
 * @return the SbgnListOfGlyphs from this SbgnArcGroup_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnArcGroup_addGlyph()
 * @see SbgnArcGroup_createGlyph()
 * @see SbgnArcGroup_getGlyphById()
 * @see SbgnArcGroup_getGlyph()
 * @see SbgnArcGroup_getNumGlyphs()
 * @see SbgnArcGroup_removeGlyphById()
 * @see SbgnArcGroup_removeGlyph()
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArcGroup_getListOfGlyphs(SbgnArcGroup_t* sag);


/**
 * Get a SbgnGlyph_t from the SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the nth SbgnGlyph_t in the SbgnListOfGlyphs within this
 * SbgnArcGroup.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyph(SbgnArcGroup_t* sag, unsigned int n);


/**
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on its identifier.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the SbgnGlyph_t in the SbgnListOfGlyphs within this SbgnArcGroup
 * with the given @p sid or @c NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphById(SbgnArcGroup_t* sag, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the CompartmentRef to
 * which it refers.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the "compartmentRef" attribute of the
 * SbgnGlyph_t object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArcGroup_t based on the given
 * compartmentRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByCompartmentRef(SbgnArcGroup_t* sag, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the MapRef to which it
 * refers.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the "mapRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArcGroup_t based on the given
 * mapRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByMapRef(SbgnArcGroup_t* sag, const char *sid);


/**
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the TagRef to which it
 * refers.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the "tagRef" attribute of the SbgnGlyph_t
 * object to retrieve.
 *
 * @return the first SbgnGlyph_t in this SbgnArcGroup_t based on the given
 * tagRef attribute or NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByTagRef(SbgnArcGroup_t* sag, const char *sid);


/**
 * Adds a copy of the given SbgnGlyph_t to this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to which the SbgnGlyph_t should be
 * added.
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
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_addGlyph(SbgnArcGroup_t* sag, const SbgnGlyph_t* sg);


/**
 * Get the number of SbgnGlyph_t objects in this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to query.
 *
 * @return the number of SbgnGlyph_t objects in this SbgnArcGroup_t.
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnArcGroup_getNumGlyphs(SbgnArcGroup_t* sag);


/**
 * Creates a new SbgnGlyph_t object, adds it to this SbgnArcGroup_t object and
 * returns the SbgnGlyph_t object created.
 *
 * @param sag the SbgnArcGroup_t structure to which the SbgnGlyph_t should be
 * added.
 *
 * @return a new SbgnGlyph_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_createGlyph(SbgnArcGroup_t* sag);


/**
 * Removes the nth SbgnGlyph_t from this SbgnArcGroup_t and returns a pointer
 * to it.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * remove.
 *
 * @return a pointer to the nth SbgnGlyph_t in this SbgnArcGroup_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_removeGlyph(SbgnArcGroup_t* sag, unsigned int n);


/**
 * Removes the SbgnGlyph_t from this SbgnArcGroup_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * remove.
 *
 * @return the SbgnGlyph_t in this SbgnArcGroup_t based on the identifier or
 * NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_removeGlyphById(SbgnArcGroup_t* sag, const char* sid);


/**
 * Returns a ListOf_t * containing SbgnArc_t objects from this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure whose SbgnListOfArcs is sought.
 *
 * @return the SbgnListOfArcs from this SbgnArcGroup_t as a ListOf_t *.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @see SbgnArcGroup_addArc()
 * @see SbgnArcGroup_createArc()
 * @see SbgnArcGroup_getArcById()
 * @see SbgnArcGroup_getArc()
 * @see SbgnArcGroup_getNumArcs()
 * @see SbgnArcGroup_removeArcById()
 * @see SbgnArcGroup_removeArc()
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArcGroup_getListOfArcs(SbgnArcGroup_t* sag);


/**
 * Get a SbgnArc_t from the SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to
 * retrieve.
 *
 * @return the nth SbgnArc_t in the SbgnListOfArcs within this SbgnArcGroup.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_getArc(SbgnArcGroup_t* sag, unsigned int n);


/**
 * Get a SbgnArc_t from the SbgnArcGroup_t based on its identifier.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to
 * retrieve.
 *
 * @return the SbgnArc_t in the SbgnListOfArcs within this SbgnArcGroup with
 * the given @p sid or @c NULL if no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_getArcById(SbgnArcGroup_t* sag, const char *sid);


/**
 * Adds a copy of the given SbgnArc_t to this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to which the SbgnArc_t should be
 * added.
 *
 * @param sa the SbgnArc_t object to add.
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
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_addArc(SbgnArcGroup_t* sag, const SbgnArc_t* sa);


/**
 * Get the number of SbgnArc_t objects in this SbgnArcGroup_t.
 *
 * @param sag the SbgnArcGroup_t structure to query.
 *
 * @return the number of SbgnArc_t objects in this SbgnArcGroup_t.
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnArcGroup_getNumArcs(SbgnArcGroup_t* sag);


/**
 * Creates a new SbgnArc_t object, adds it to this SbgnArcGroup_t object and
 * returns the SbgnArc_t object created.
 *
 * @param sag the SbgnArcGroup_t structure to which the SbgnArc_t should be
 * added.
 *
 * @return a new SbgnArc_t object instance.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_createArc(SbgnArcGroup_t* sag);


/**
 * Removes the nth SbgnArc_t from this SbgnArcGroup_t and returns a pointer to
 * it.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to remove.
 *
 * @return a pointer to the nth SbgnArc_t in this SbgnArcGroup_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_removeArc(SbgnArcGroup_t* sag, unsigned int n);


/**
 * Removes the SbgnArc_t from this SbgnArcGroup_t based on its identifier and
 * returns a pointer to it.
 *
 * @param sag the SbgnArcGroup_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to remove.
 *
 * @return the SbgnArc_t in this SbgnArcGroup_t based on the identifier or NULL
 * if no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_removeArcById(SbgnArcGroup_t* sag, const char* sid);


/**
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnArcGroup_t object have been set.
 *
 * @param sag the SbgnArcGroup_t structure.
 *
 * @return @c 1 (true) to indicate that all the required attributes of this
 * SbgnArcGroup_t have been set, otherwise @c 0 (false) is returned.
 *
 * @memberof SbgnArcGroup_t
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_hasRequiredAttributes(const SbgnArcGroup_t * sag);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnArcGroup_H__ */



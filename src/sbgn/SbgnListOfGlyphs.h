/**
 * @file SbgnListOfGlyphs.h
 * @brief Definition of the SbgnListOfGlyphs class.
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
 * @class SbgnListOfGlyphs
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfGlyphs class.
 */


#ifndef SbgnListOfGlyphs_H__
#define SbgnListOfGlyphs_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnGlyph.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfGlyphs : public SbgnListOf
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SbgnListOfGlyphs using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfGlyphs.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfGlyphs.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfGlyphs(unsigned int level = SBGN_DEFAULT_LEVEL,
                   unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfGlyphs using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfGlyphs(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfGlyphs.
   *
   * @param orig the SbgnListOfGlyphs instance to copy.
   */
  SbgnListOfGlyphs(const SbgnListOfGlyphs& orig);


  /**
   * Assignment operator for SbgnListOfGlyphs.
   *
   * @param rhs the SbgnListOfGlyphs object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnListOfGlyphs& operator=(const SbgnListOfGlyphs& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfGlyphs object.
   *
   * @return a (deep) copy of this SbgnListOfGlyphs object.
   */
  virtual SbgnListOfGlyphs* clone() const;


  /**
   * Destructor for SbgnListOfGlyphs.
   */
  virtual ~SbgnListOfGlyphs();


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in this SbgnListOfGlyphs.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(const std::string& sid)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnGlyph* get(unsigned int n);


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * retrieve.
   *
   * @return the nth SbgnGlyph in this SbgnListOfGlyphs.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(const std::string& sid)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnGlyph* get(unsigned int n) const;


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in this SbgnListOfGlyphs with the given @p sid or
   * @c NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnGlyph* get(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * retrieve.
   *
   * @return the SbgnGlyph in this SbgnListOfGlyphs with the given @p sid or
   * @c NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnGlyph* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnGlyph from this SbgnListOfGlyphs and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SbgnGlyph to
   * remove.
   *
   * @return a pointer to the nth SbgnGlyph in this SbgnListOfGlyphs.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   */
  virtual SbgnGlyph* remove(unsigned int n);


  /**
   * Removes the SbgnGlyph from this SbgnListOfGlyphs based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnGlyph to
   * remove.
   *
   * @return the SbgnGlyph in this SbgnListOfGlyphs based on the identifier or
   * NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(unsigned int n)
   */
  virtual SbgnGlyph* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnGlyph to this SbgnListOfGlyphs.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addGlyph(const SbgnGlyph* sg);


  /**
   * Get the number of SbgnGlyph objects in this SbgnListOfGlyphs.
   *
   * @return the number of SbgnGlyph objects in this SbgnListOfGlyphs.
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see createGlyph()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumGlyphs() const;


  /**
   * Creates a new SbgnGlyph object, adds it to this SbgnListOfGlyphs object
   * and returns the SbgnGlyph object created.
   *
   * @return a new SbgnGlyph object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addGlyph(const SbgnGlyph* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumGlyphs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnGlyph* createGlyph();


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the CompartmentRef to
   * which it refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getByCompartmentRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the CompartmentRef to
   * which it refers.
   *
   * @param sid a string representing the "compartmentRef" attribute of the
   * SbgnGlyph object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * compartmentRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getByCompartmentRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the MapRef to which it
   * refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * mapRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getByMapRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the MapRef to which it
   * refers.
   *
   * @param sid a string representing the "mapRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * mapRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getByMapRef(const std::string& sid);


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the TagRef to which it
   * refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * tagRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  const SbgnGlyph* getByTagRef(const std::string& sid) const;


  /**
   * Get a SbgnGlyph from the SbgnListOfGlyphs based on the TagRef to which it
   * refers.
   *
   * @param sid a string representing the "tagRef" attribute of the SbgnGlyph
   * object to retrieve.
   *
   * @return the first SbgnGlyph in this SbgnListOfGlyphs based on the given
   * tagRef attribute or NULL if no such SbgnGlyph exists.
   *
   * @copydetails doc_returned_unowned_pointer
   */
  SbgnGlyph* getByTagRef(const std::string& sid);


  /**
   * Returns the XML element name of this SbgnListOfGlyphs object.
   *
   * For SbgnListOfGlyphs, the XML element name is always @c "listOfGlyphs".
   *
   * @return the name of this element, i.e. @c "listOfGlyphs".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the XML name of this SbgnListOfGlyphs object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBGN type code for this SbgnListOfGlyphs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_LIST_OF, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   */
  virtual int getTypeCode() const;


  /**
   * Returns the libSBGN type code for the SBGN objects contained in this
   * SbgnListOfGlyphs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfGlyphs:
   * @sbgnconstant{SBGN_SBGNML_GLYPH, SbgnTypeCode_t}.
   *
   * @copydetails doc_warning_typecodes_not_unique
   *
   * @see getElementName()
   */
  virtual int getItemTypeCode() const;




  #ifndef SWIG




  #endif /* !SWIG */


protected:


  /** @cond doxygenlibSBGNInternal */

  /**
   * Creates a new SbgnGlyph in this SbgnListOfGlyphs
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnMap;
  friend class SbgnGlyph;
  friend class SbgnArc;
  friend class SbgnArcGroup;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnGlyph_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the nth SbgnGlyph_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfGlyphs_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_getGlyph(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnGlyph_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * retrieve.
 *
 * @return the SbgnGlyph_t in this SbgnListOf_t with the given @p sid or
 * @c NULL if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfGlyphs_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnGlyph_t from this SbgnListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnGlyph_t to
 * remove.
 *
 * @return a pointer to the nth SbgnGlyph_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfGlyphs_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnGlyph_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnGlyph_t to
 * remove.
 *
 * @return the SbgnGlyph_t in this SbgnListOf_t based on the identifier or NULL
 * if no such SbgnGlyph_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfGlyphs_t
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfGlyphs_H__ */



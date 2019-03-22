/**
 * @file SbgnListOfArcGroups.h
 * @brief Definition of the SbgnListOfArcGroups class.
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
 * @class SbgnListOfArcGroups
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfArcGroups class.
 */


#ifndef SbgnListOfArcGroups_H__
#define SbgnListOfArcGroups_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnArcGroup.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfArcGroups : public SbgnListOf
{

public:

  /**
   * Creates a new SbgnListOfArcGroups using the given SBGN Level and @ p
   * version values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfArcGroups.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfArcGroups.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfArcGroups(unsigned int level = SBGN_DEFAULT_LEVEL,
                      unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfArcGroups using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfArcGroups(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfArcGroups.
   *
   * @param orig the SbgnListOfArcGroups instance to copy.
   */
  SbgnListOfArcGroups(const SbgnListOfArcGroups& orig);


  /**
   * Assignment operator for SbgnListOfArcGroups.
   *
   * @param rhs the SbgnListOfArcGroups object whose values are to be used as
   * the basis of the assignment.
   */
  SbgnListOfArcGroups& operator=(const SbgnListOfArcGroups& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfArcGroups object.
   *
   * @return a (deep) copy of this SbgnListOfArcGroups object.
   */
  virtual SbgnListOfArcGroups* clone() const;


  /**
   * Destructor for SbgnListOfArcGroups.
   */
  virtual ~SbgnListOfArcGroups();


  /**
   * Get a SbgnArcGroup from the SbgnListOfArcGroups.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * retrieve.
   *
   * @return the nth SbgnArcGroup in this SbgnListOfArcGroups.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnArcGroup* get(unsigned int n);


  /**
   * Get a SbgnArcGroup from the SbgnListOfArcGroups.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * retrieve.
   *
   * @return the nth SbgnArcGroup in this SbgnListOfArcGroups.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnArcGroup* get(unsigned int n) const;


  /**
   * Get a SbgnArcGroup from the SbgnListOfArcGroups based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArcGroup to
   * retrieve.
   *
   * @return the SbgnArcGroup in this SbgnListOfArcGroups with the given @p sid
   * or @c NULL if no such SbgnArcGroup exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnArcGroup* get(const std::string& sid);


  /**
   * Get a SbgnArcGroup from the SbgnListOfArcGroups based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArcGroup to
   * retrieve.
   *
   * @return the SbgnArcGroup in this SbgnListOfArcGroups with the given @p sid
   * or @c NULL if no such SbgnArcGroup exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnArcGroup* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnArcGroup from this SbgnListOfArcGroups and returns a
   * pointer to it.
   *
   * @param n an unsigned int representing the index of the SbgnArcGroup to
   * remove.
   *
   * @return a pointer to the nth SbgnArcGroup in this SbgnListOfArcGroups.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   */
  virtual SbgnArcGroup* remove(unsigned int n);


  /**
   * Removes the SbgnArcGroup from this SbgnListOfArcGroups based on its
   * identifier and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnArcGroup to
   * remove.
   *
   * @return the SbgnArcGroup in this SbgnListOfArcGroups based on the
   * identifier or NULL if no such SbgnArcGroup exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(unsigned int n)
   */
  virtual SbgnArcGroup* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnArcGroup to this SbgnListOfArcGroups.
   *
   * @param sag the SbgnArcGroup object to add.
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
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addArcGroup(const SbgnArcGroup* sag);


  /**
   * Get the number of SbgnArcGroup objects in this SbgnListOfArcGroups.
   *
   * @return the number of SbgnArcGroup objects in this SbgnListOfArcGroups.
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see createArcGroup()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumArcGroups() const;


  /**
   * Creates a new SbgnArcGroup object, adds it to this SbgnListOfArcGroups
   * object and returns the SbgnArcGroup object created.
   *
   * @return a new SbgnArcGroup object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArcGroup(const SbgnArcGroup* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcGroups()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnArcGroup* createArcGroup();


  /**
   * Returns the XML element name of this SbgnListOfArcGroups object.
   *
   * For SbgnListOfArcGroups, the XML element name is always
   * @c "listOfArcGroups".
   *
   * @return the name of this element, i.e. @c "listOfArcGroups".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnListOfArcGroups object.
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
   * SbgnListOfArcGroups object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfArcGroups:
   * @sbgnconstant{SBGN_SBGNML_ARCGROUP, SbgnTypeCode_t}.
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
   * Creates a new SbgnArcGroup in this SbgnListOfArcGroups
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnMap;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnArcGroup_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArcGroup_t to
 * retrieve.
 *
 * @return the nth SbgnArcGroup_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfArcGroups_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_getArcGroup(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnArcGroup_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArcGroup_t to
 * retrieve.
 *
 * @return the SbgnArcGroup_t in this SbgnListOf_t with the given @p sid or
 * @c NULL if no such SbgnArcGroup_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfArcGroups_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnArcGroup_t from this SbgnListOf_t and returns a pointer
 * to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArcGroup_t to
 * remove.
 *
 * @return a pointer to the nth SbgnArcGroup_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfArcGroups_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnArcGroup_t from this SbgnListOf_t based on its identifier
 * and returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArcGroup_t to
 * remove.
 *
 * @return the SbgnArcGroup_t in this SbgnListOf_t based on the identifier or
 * NULL if no such SbgnArcGroup_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfArcGroups_t
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfArcGroups_H__ */



/**
 * @file SbgnListOfMaps.h
 * @brief Definition of the SbgnListOfMaps class.
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
 * @class SbgnListOfMaps
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfMaps class.
 */


#ifndef SbgnListOfMaps_H__
#define SbgnListOfMaps_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnMap.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfMaps : public SbgnListOf
{

public:

  /**
   * Creates a new SbgnListOfMaps using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfMaps.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfMaps.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfMaps(unsigned int level = SBGN_DEFAULT_LEVEL,
                 unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfMaps using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfMaps(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfMaps.
   *
   * @param orig the SbgnListOfMaps instance to copy.
   */
  SbgnListOfMaps(const SbgnListOfMaps& orig);


  /**
   * Assignment operator for SbgnListOfMaps.
   *
   * @param rhs the SbgnListOfMaps object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnListOfMaps& operator=(const SbgnListOfMaps& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfMaps object.
   *
   * @return a (deep) copy of this SbgnListOfMaps object.
   */
  virtual SbgnListOfMaps* clone() const;


  /**
   * Destructor for SbgnListOfMaps.
   */
  virtual ~SbgnListOfMaps();


  /**
   * Get a SbgnMap from the SbgnListOfMaps.
   *
   * @param n an unsigned int representing the index of the SbgnMap to
   * retrieve.
   *
   * @return the nth SbgnMap in this SbgnListOfMaps.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(const std::string& sid)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnMap* get(unsigned int n);


  /**
   * Get a SbgnMap from the SbgnListOfMaps.
   *
   * @param n an unsigned int representing the index of the SbgnMap to
   * retrieve.
   *
   * @return the nth SbgnMap in this SbgnListOfMaps.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(const std::string& sid)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnMap* get(unsigned int n) const;


  /**
   * Get a SbgnMap from the SbgnListOfMaps based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnMap to
   * retrieve.
   *
   * @return the SbgnMap in this SbgnListOfMaps with the given @p sid or
   * @c NULL if no such SbgnMap exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnMap* get(const std::string& sid);


  /**
   * Get a SbgnMap from the SbgnListOfMaps based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnMap to
   * retrieve.
   *
   * @return the SbgnMap in this SbgnListOfMaps with the given @p sid or
   * @c NULL if no such SbgnMap exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnMap* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnMap from this SbgnListOfMaps and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnMap to remove.
   *
   * @return a pointer to the nth SbgnMap in this SbgnListOfMaps.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   */
  virtual SbgnMap* remove(unsigned int n);


  /**
   * Removes the SbgnMap from this SbgnListOfMaps based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnMap to remove.
   *
   * @return the SbgnMap in this SbgnListOfMaps based on the identifier or NULL
   * if no such SbgnMap exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(unsigned int n)
   */
  virtual SbgnMap* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnMap to this SbgnListOfMaps.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addMap(const SbgnMap* sm);


  /**
   * Get the number of SbgnMap objects in this SbgnListOfMaps.
   *
   * @return the number of SbgnMap objects in this SbgnListOfMaps.
   *
   * @see addMap(const SbgnMap* object)
   * @see createMap()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumMaps() const;


  /**
   * Creates a new SbgnMap object, adds it to this SbgnListOfMaps object and
   * returns the SbgnMap object created.
   *
   * @return a new SbgnMap object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addMap(const SbgnMap* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumMaps()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnMap* createMap();


  /**
   * Returns the XML element name of this SbgnListOfMaps object.
   *
   * For SbgnListOfMaps, the XML element name is always @c "listOfMaps".
   *
   * @return the name of this element, i.e. @c "listOfMaps".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnListOfMaps object.
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
   * SbgnListOfMaps object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfMaps:
   * @sbgnconstant{SBGN_SBGNML_MAP, SbgnTypeCode_t}.
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
   * Creates a new SbgnMap in this SbgnListOfMaps
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnDocument;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnMap_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnMap_t to
 * retrieve.
 *
 * @return the nth SbgnMap_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfMaps_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_getMap(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnMap_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnMap_t to
 * retrieve.
 *
 * @return the SbgnMap_t in this SbgnListOf_t with the given @p sid or @c NULL
 * if no such SbgnMap_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfMaps_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnMap_t from this SbgnListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnMap_t to remove.
 *
 * @return a pointer to the nth SbgnMap_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfMaps_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnMap_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnMap_t to remove.
 *
 * @return the SbgnMap_t in this SbgnListOf_t based on the identifier or NULL
 * if no such SbgnMap_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfMaps_t
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfMaps_H__ */



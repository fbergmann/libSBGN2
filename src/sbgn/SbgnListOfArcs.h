/**
 * @file SbgnListOfArcs.h
 * @brief Definition of the SbgnListOfArcs class.
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
 * @class SbgnListOfArcs
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfArcs class.
 */


#ifndef SbgnListOfArcs_H__
#define SbgnListOfArcs_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnArc.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfArcs : public SbgnListOf
{

public:

  /**
   * Creates a new SbgnListOfArcs using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfArcs.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfArcs.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfArcs(unsigned int level = SBGN_DEFAULT_LEVEL,
                 unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfArcs using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfArcs(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfArcs.
   *
   * @param orig the SbgnListOfArcs instance to copy.
   */
  SbgnListOfArcs(const SbgnListOfArcs& orig);


  /**
   * Assignment operator for SbgnListOfArcs.
   *
   * @param rhs the SbgnListOfArcs object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnListOfArcs& operator=(const SbgnListOfArcs& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfArcs object.
   *
   * @return a (deep) copy of this SbgnListOfArcs object.
   */
  virtual SbgnListOfArcs* clone() const;


  /**
   * Destructor for SbgnListOfArcs.
   */
  virtual ~SbgnListOfArcs();


  /**
   * Get a SbgnArc from the SbgnListOfArcs.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in this SbgnListOfArcs.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(const std::string& sid)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnArc* get(unsigned int n);


  /**
   * Get a SbgnArc from the SbgnListOfArcs.
   *
   * @param n an unsigned int representing the index of the SbgnArc to
   * retrieve.
   *
   * @return the nth SbgnArc in this SbgnListOfArcs.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(const std::string& sid)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnArc* get(unsigned int n) const;


  /**
   * Get a SbgnArc from the SbgnListOfArcs based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in this SbgnListOfArcs with the given @p sid or
   * @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnArc* get(const std::string& sid);


  /**
   * Get a SbgnArc from the SbgnListOfArcs based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnArc to
   * retrieve.
   *
   * @return the SbgnArc in this SbgnListOfArcs with the given @p sid or
   * @c NULL if no such SbgnArc exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnArc* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnArc from this SbgnListOfArcs and returns a pointer to
   * it.
   *
   * @param n an unsigned int representing the index of the SbgnArc to remove.
   *
   * @return a pointer to the nth SbgnArc in this SbgnListOfArcs.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   */
  virtual SbgnArc* remove(unsigned int n);


  /**
   * Removes the SbgnArc from this SbgnListOfArcs based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnArc to remove.
   *
   * @return the SbgnArc in this SbgnListOfArcs based on the identifier or NULL
   * if no such SbgnArc exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(unsigned int n)
   */
  virtual SbgnArc* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnArc to this SbgnListOfArcs.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addArc(const SbgnArc* sa);


  /**
   * Get the number of SbgnArc objects in this SbgnListOfArcs.
   *
   * @return the number of SbgnArc objects in this SbgnListOfArcs.
   *
   * @see addArc(const SbgnArc* object)
   * @see createArc()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumArcs() const;


  /**
   * Creates a new SbgnArc object, adds it to this SbgnListOfArcs object and
   * returns the SbgnArc object created.
   *
   * @return a new SbgnArc object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addArc(const SbgnArc* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumArcs()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnArc* createArc();


  /**
   * Returns the XML element name of this SbgnListOfArcs object.
   *
   * For SbgnListOfArcs, the XML element name is always @c "listOfArcs".
   *
   * @return the name of this element, i.e. @c "listOfArcs".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnListOfArcs object.
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
   * SbgnListOfArcs object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfArcs:
   * @sbgnconstant{SBGN_SBGNML_ARC, SbgnTypeCode_t}.
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
   * Creates a new SbgnArc in this SbgnListOfArcs
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnMap;
  friend class SbgnArcGroup;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnArc_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to
 * retrieve.
 *
 * @return the nth SbgnArc_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfArcs_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_getArc(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnArc_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to
 * retrieve.
 *
 * @return the SbgnArc_t in this SbgnListOf_t with the given @p sid or @c NULL
 * if no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfArcs_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnArc_t from this SbgnListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnArc_t to remove.
 *
 * @return a pointer to the nth SbgnArc_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfArcs_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnArc_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnArc_t to remove.
 *
 * @return the SbgnArc_t in this SbgnListOf_t based on the identifier or NULL
 * if no such SbgnArc_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfArcs_t
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfArcs_H__ */



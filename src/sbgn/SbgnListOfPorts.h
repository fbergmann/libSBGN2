/**
 * @file SbgnListOfPorts.h
 * @brief Definition of the SbgnListOfPorts class.
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
 * @class SbgnListOfPorts
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfPorts class.
 */


#ifndef SbgnListOfPorts_H__
#define SbgnListOfPorts_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnPort.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfPorts : public SbgnListOf
{

public:

  /**
   * Creates a new SbgnListOfPorts using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfPorts.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfPorts.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfPorts(unsigned int level = SBGN_DEFAULT_LEVEL,
                  unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfPorts using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfPorts(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfPorts.
   *
   * @param orig the SbgnListOfPorts instance to copy.
   */
  SbgnListOfPorts(const SbgnListOfPorts& orig);


  /**
   * Assignment operator for SbgnListOfPorts.
   *
   * @param rhs the SbgnListOfPorts object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnListOfPorts& operator=(const SbgnListOfPorts& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfPorts object.
   *
   * @return a (deep) copy of this SbgnListOfPorts object.
   */
  virtual SbgnListOfPorts* clone() const;


  /**
   * Destructor for SbgnListOfPorts.
   */
  virtual ~SbgnListOfPorts();


  /**
   * Get a SbgnPort from the SbgnListOfPorts.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in this SbgnListOfPorts.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(const std::string& sid)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnPort* get(unsigned int n);


  /**
   * Get a SbgnPort from the SbgnListOfPorts.
   *
   * @param n an unsigned int representing the index of the SbgnPort to
   * retrieve.
   *
   * @return the nth SbgnPort in this SbgnListOfPorts.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(const std::string& sid)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnPort* get(unsigned int n) const;


  /**
   * Get a SbgnPort from the SbgnListOfPorts based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in this SbgnListOfPorts with the given @p sid or
   * @c NULL if no such SbgnPort exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnPort* get(const std::string& sid);


  /**
   * Get a SbgnPort from the SbgnListOfPorts based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPort to
   * retrieve.
   *
   * @return the SbgnPort in this SbgnListOfPorts with the given @p sid or
   * @c NULL if no such SbgnPort exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnPort* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnPort from this SbgnListOfPorts and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SbgnPort to remove.
   *
   * @return a pointer to the nth SbgnPort in this SbgnListOfPorts.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   */
  virtual SbgnPort* remove(unsigned int n);


  /**
   * Removes the SbgnPort from this SbgnListOfPorts based on its identifier and
   * returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnPort to remove.
   *
   * @return the SbgnPort in this SbgnListOfPorts based on the identifier or
   * NULL if no such SbgnPort exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(unsigned int n)
   */
  virtual SbgnPort* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnPort to this SbgnListOfPorts.
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
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addPort(const SbgnPort* sp);


  /**
   * Get the number of SbgnPort objects in this SbgnListOfPorts.
   *
   * @return the number of SbgnPort objects in this SbgnListOfPorts.
   *
   * @see addPort(const SbgnPort* object)
   * @see createPort()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumPorts() const;


  /**
   * Creates a new SbgnPort object, adds it to this SbgnListOfPorts object and
   * returns the SbgnPort object created.
   *
   * @return a new SbgnPort object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPort(const SbgnPort* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPorts()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnPort* createPort();


  /**
   * Returns the XML element name of this SbgnListOfPorts object.
   *
   * For SbgnListOfPorts, the XML element name is always @c "listOfPorts".
   *
   * @return the name of this element, i.e. @c "listOfPorts".
   */
  virtual const std::string& getElementName() const;


  /**
   * Returns the libSBGN type code for this SbgnListOfPorts object.
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
   * SbgnListOfPorts object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfPorts:
   * @sbgnconstant{SBGN_SBGNML_PORT, SbgnTypeCode_t}.
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
   * Creates a new SbgnPort in this SbgnListOfPorts
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnGlyph;
  friend class SbgnArc;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnPort_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to
 * retrieve.
 *
 * @return the nth SbgnPort_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfPorts_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_getPort(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnPort_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to
 * retrieve.
 *
 * @return the SbgnPort_t in this SbgnListOf_t with the given @p sid or @c NULL
 * if no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfPorts_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnPort_t from this SbgnListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPort_t to remove.
 *
 * @return a pointer to the nth SbgnPort_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfPorts_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnPort_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPort_t to remove.
 *
 * @return the SbgnPort_t in this SbgnListOf_t based on the identifier or NULL
 * if no such SbgnPort_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfPorts_t
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfPorts_H__ */



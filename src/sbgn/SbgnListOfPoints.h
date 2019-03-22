/**
 * @file SbgnListOfPoints.h
 * @brief Definition of the SbgnListOfPoints class.
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
 * @class SbgnListOfPoints
 * @sbmlbrief{sbgnml} TODO:Definition of the SbgnListOfPoints class.
 */


#ifndef SbgnListOfPoints_H__
#define SbgnListOfPoints_H__


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>


#ifdef __cplusplus


#include <string>


#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnPoint.h>
#include <sbml/common/libsbml-namespace.h>


LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnListOfPoints : public SbgnListOf
{
protected:

  /** @cond doxygenlibSBGNInternal */

  std::string mElementName;

  /** @endcond */

public:

  /**
   * Creates a new SbgnListOfPoints using the given SBGN Level and @ p version
   * values.
   *
   * @param level an unsigned int, the SBGN Level to assign to this
   * SbgnListOfPoints.
   *
   * @param version an unsigned int, the SBGN Version to assign to this
   * SbgnListOfPoints.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfPoints(unsigned int level = SBGN_DEFAULT_LEVEL,
                   unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOfPoints using the given SbgnNamespaces object @p
   * sbgnns.
   *
   * @param sbgnns the SbgnNamespaces object.
   *
   * @copydetails doc_note_setting_lv_pkg
   */
  SbgnListOfPoints(SbgnNamespaces *sbgnns);


  /**
   * Copy constructor for SbgnListOfPoints.
   *
   * @param orig the SbgnListOfPoints instance to copy.
   */
  SbgnListOfPoints(const SbgnListOfPoints& orig);


  /**
   * Assignment operator for SbgnListOfPoints.
   *
   * @param rhs the SbgnListOfPoints object whose values are to be used as the
   * basis of the assignment.
   */
  SbgnListOfPoints& operator=(const SbgnListOfPoints& rhs);


  /**
   * Creates and returns a deep copy of this SbgnListOfPoints object.
   *
   * @return a (deep) copy of this SbgnListOfPoints object.
   */
  virtual SbgnListOfPoints* clone() const;


  /**
   * Destructor for SbgnListOfPoints.
   */
  virtual ~SbgnListOfPoints();


  /**
   * Get a SbgnPoint from the SbgnListOfPoints.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in this SbgnListOfPoints.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnPoint* get(unsigned int n);


  /**
   * Get a SbgnPoint from the SbgnListOfPoints.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * retrieve.
   *
   * @return the nth SbgnPoint in this SbgnListOfPoints.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnPoint* get(unsigned int n) const;


  /**
   * Get a SbgnPoint from the SbgnListOfPoints based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPoint to
   * retrieve.
   *
   * @return the SbgnPoint in this SbgnListOfPoints with the given @p sid or
   * @c NULL if no such SbgnPoint exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual SbgnPoint* get(const std::string& sid);


  /**
   * Get a SbgnPoint from the SbgnListOfPoints based on its identifier.
   *
   * @param sid a string representing the identifier of the SbgnPoint to
   * retrieve.
   *
   * @return the SbgnPoint in this SbgnListOfPoints with the given @p sid or
   * @c NULL if no such SbgnPoint exists.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  virtual const SbgnPoint* get(const std::string& sid) const;


  /**
   * Removes the nth SbgnPoint from this SbgnListOfPoints and returns a pointer
   * to it.
   *
   * @param n an unsigned int representing the index of the SbgnPoint to
   * remove.
   *
   * @return a pointer to the nth SbgnPoint in this SbgnListOfPoints.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   */
  virtual SbgnPoint* remove(unsigned int n);


  /**
   * Removes the SbgnPoint from this SbgnListOfPoints based on its identifier
   * and returns a pointer to it.
   *
   * @param sid a string representing the identifier of the SbgnPoint to
   * remove.
   *
   * @return the SbgnPoint in this SbgnListOfPoints based on the identifier or
   * NULL if no such SbgnPoint exists.
   *
   * @copydetails doc_returned_owned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(unsigned int n)
   */
  virtual SbgnPoint* remove(const std::string& sid);


  /**
   * Adds a copy of the given SbgnPoint to this SbgnListOfPoints.
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
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  int addPoint(const SbgnPoint* sp);


  /**
   * Get the number of SbgnPoint objects in this SbgnListOfPoints.
   *
   * @return the number of SbgnPoint objects in this SbgnListOfPoints.
   *
   * @see addPoint(const SbgnPoint* object)
   * @see createPoint()
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  unsigned int getNumPoints() const;


  /**
   * Creates a new SbgnPoint object, adds it to this SbgnListOfPoints object
   * and returns the SbgnPoint object created.
   *
   * @return a new SbgnPoint object instance.
   *
   * @copydetails doc_returned_unowned_pointer
   *
   * @see addPoint(const SbgnPoint* object)
   * @see get(const std::string& sid)
   * @see get(unsigned int n)
   * @see getNumPoints()
   * @see remove(const std::string& sid)
   * @see remove(unsigned int n)
   */
  SbgnPoint* createPoint();


  /**
   * Returns the XML element name of this SbgnListOfPoints object.
   *
   * For SbgnListOfPoints, the XML element name is always @c "listOfPoints".
   *
   * @return the name of this element, i.e. @c "listOfPoints".
   */
  virtual const std::string& getElementName() const;



  /** @cond doxygenlibSBGNInternal */

  /**
   * Sets the XML name of this SbgnListOfPoints object.
   */
  virtual void setElementName(const std::string& name);

  /** @endcond */


  /**
   * Returns the libSBGN type code for this SbgnListOfPoints object.
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
   * SbgnListOfPoints object.
   *
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN typecode for the objects contained in this
   * SbgnListOfPoints:
   * @sbgnconstant{SBGN_SBGNML_POINT, SbgnTypeCode_t}.
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
   * Creates a new SbgnPoint in this SbgnListOfPoints
   */
  virtual SbgnBase* createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
    XMLInputStream& stream);

  /** @endcond */


  friend class SbgnPoint;
  friend class SbgnArc;
};



LIBSBGN_CPP_NAMESPACE_END




#endif /* __cplusplus */




#ifndef SWIG




LIBSBGN_CPP_NAMESPACE_BEGIN




BEGIN_C_DECLS


/**
 * Get a SbgnPoint_t from the SbgnListOf_t.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * retrieve.
 *
 * @return the nth SbgnPoint_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfPoints_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnListOfPoints_getPoint(SbgnListOf_t* slo, unsigned int n);


/**
 * Get a SbgnPoint_t from the SbgnListOf_t based on its identifier.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPoint_t to
 * retrieve.
 *
 * @return the SbgnPoint_t in this SbgnListOf_t with the given @p sid or
 * @c NULL if no such SbgnPoint_t exists.
 *
 * @copydetails doc_returned_unowned_pointer
 *
 * @memberof SbgnListOfPoints_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnListOfPoints_getById(SbgnListOf_t* slo, const char *sid);


/**
 * Removes the nth SbgnPoint_t from this SbgnListOf_t and returns a pointer to
 * it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param n an unsigned int representing the index of the SbgnPoint_t to
 * remove.
 *
 * @return a pointer to the nth SbgnPoint_t in this SbgnListOf_t.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfPoints_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnListOfPoints_remove(SbgnListOf_t* slo, unsigned int n);


/**
 * Removes the SbgnPoint_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 *
 * @param slo the SbgnListOf_t structure to search.
 *
 * @param sid a string representing the identifier of the SbgnPoint_t to
 * remove.
 *
 * @return the SbgnPoint_t in this SbgnListOf_t based on the identifier or NULL
 * if no such SbgnPoint_t exists.
 *
 * @copydetails doc_returned_owned_pointer
 *
 * @memberof SbgnListOfPoints_t
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnListOfPoints_removeById(SbgnListOf_t* slo, const char* sid);




END_C_DECLS




LIBSBGN_CPP_NAMESPACE_END




#endif /* !SWIG */




#endif /* !SbgnListOfPoints_H__ */



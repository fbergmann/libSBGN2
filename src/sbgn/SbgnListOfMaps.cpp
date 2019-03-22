/**
 * @file SbgnListOfMaps.cpp
 * @brief Implementation of the SbgnListOfMaps class.
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
 */
#include <sbgn/SbgnListOfMaps.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfMaps using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfMaps::SbgnListOfMaps(unsigned int level, unsigned int version)
  : SbgnListOf(level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfMaps using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfMaps::SbgnListOfMaps(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfMaps.
 */
SbgnListOfMaps::SbgnListOfMaps(const SbgnListOfMaps& orig)
  : SbgnListOf( orig )
{
}


/*
 * Assignment operator for SbgnListOfMaps.
 */
SbgnListOfMaps&
SbgnListOfMaps::operator=(const SbgnListOfMaps& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfMaps object.
 */
SbgnListOfMaps*
SbgnListOfMaps::clone() const
{
  return new SbgnListOfMaps(*this);
}


/*
 * Destructor for SbgnListOfMaps.
 */
SbgnListOfMaps::~SbgnListOfMaps()
{
}


/*
 * Get a SbgnMap from the SbgnListOfMaps.
 */
SbgnMap*
SbgnListOfMaps::get(unsigned int n)
{
  return static_cast<SbgnMap*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnMap from the SbgnListOfMaps.
 */
const SbgnMap*
SbgnListOfMaps::get(unsigned int n) const
{
  return static_cast<const SbgnMap*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnMap from the SbgnListOfMaps based on its identifier.
 */
SbgnMap*
SbgnListOfMaps::get(const std::string& sid)
{
  return const_cast<SbgnMap*>(static_cast<const
    SbgnListOfMaps&>(*this).get(sid));
}


/*
 * Get a SbgnMap from the SbgnListOfMaps based on its identifier.
 */
const SbgnMap*
SbgnListOfMaps::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnMap>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnMap*> (*result);
}


/*
 * Removes the nth SbgnMap from this SbgnListOfMaps and returns a pointer to
 * it.
 */
SbgnMap*
SbgnListOfMaps::remove(unsigned int n)
{
  return static_cast<SbgnMap*>(SbgnListOf::remove(n));
}


/*
 * Removes the SbgnMap from this SbgnListOfMaps based on its identifier and
 * returns a pointer to it.
 */
SbgnMap*
SbgnListOfMaps::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnMap>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SbgnMap*> (item);
}


/*
 * Adds a copy of the given SbgnMap to this SbgnListOfMaps.
 */
int
SbgnListOfMaps::addMap(const SbgnMap* sm)
{
  if (sm == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sm->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sm->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sm->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sm)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sm);
  }
}


/*
 * Get the number of SbgnMap objects in this SbgnListOfMaps.
 */
unsigned int
SbgnListOfMaps::getNumMaps() const
{
  return size();
}


/*
 * Creates a new SbgnMap object, adds it to this SbgnListOfMaps object and
 * returns the SbgnMap object created.
 */
SbgnMap*
SbgnListOfMaps::createMap()
{
  SbgnMap* sm = NULL;

  try
  {
    sm = new SbgnMap(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sm != NULL)
  {
    appendAndOwn(sm);
  }

  return sm;
}


/*
 * Returns the XML element name of this SbgnListOfMaps object.
 */
const std::string&
SbgnListOfMaps::getElementName() const
{
  static const string name = "listOfMaps";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnListOfMaps object.
 */
int
SbgnListOfMaps::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfMaps object.
 */
int
SbgnListOfMaps::getItemTypeCode() const
{
  return SBGN_SBGNML_MAP;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new SbgnMap in this SbgnListOfMaps
 */
SbgnBase*
SbgnListOfMaps::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == "map")
  {
    object = new SbgnMap(getSbgnNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SbgnMap_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_getMap(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfMaps*>(slo)->get(n);
}


/*
 * Get a SbgnMap_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfMaps*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SbgnMap_t from this SbgnListOf_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfMaps*>(slo)->remove(n);
}


/*
 * Removes the SbgnMap_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnListOfMaps_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfMaps*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END



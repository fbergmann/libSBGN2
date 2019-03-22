/**
 * @file SbgnListOfArcGroups.cpp
 * @brief Implementation of the SbgnListOfArcGroups class.
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
#include <sbgn/SbgnListOfArcGroups.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfArcGroups using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfArcGroups::SbgnListOfArcGroups(unsigned int level,
                                         unsigned int version)
  : SbgnListOf(level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfArcGroups using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfArcGroups::SbgnListOfArcGroups(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfArcGroups.
 */
SbgnListOfArcGroups::SbgnListOfArcGroups(const SbgnListOfArcGroups& orig)
  : SbgnListOf( orig )
{
}


/*
 * Assignment operator for SbgnListOfArcGroups.
 */
SbgnListOfArcGroups&
SbgnListOfArcGroups::operator=(const SbgnListOfArcGroups& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfArcGroups object.
 */
SbgnListOfArcGroups*
SbgnListOfArcGroups::clone() const
{
  return new SbgnListOfArcGroups(*this);
}


/*
 * Destructor for SbgnListOfArcGroups.
 */
SbgnListOfArcGroups::~SbgnListOfArcGroups()
{
}


/*
 * Get a SbgnArcGroup from the SbgnListOfArcGroups.
 */
SbgnArcGroup*
SbgnListOfArcGroups::get(unsigned int n)
{
  return static_cast<SbgnArcGroup*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnArcGroup from the SbgnListOfArcGroups.
 */
const SbgnArcGroup*
SbgnListOfArcGroups::get(unsigned int n) const
{
  return static_cast<const SbgnArcGroup*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnArcGroup from the SbgnListOfArcGroups based on its identifier.
 */
SbgnArcGroup*
SbgnListOfArcGroups::get(const std::string& sid)
{
  return const_cast<SbgnArcGroup*>(static_cast<const
    SbgnListOfArcGroups&>(*this).get(sid));
}


/*
 * Get a SbgnArcGroup from the SbgnListOfArcGroups based on its identifier.
 */
const SbgnArcGroup*
SbgnListOfArcGroups::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnArcGroup>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnArcGroup*>
    (*result);
}


/*
 * Removes the nth SbgnArcGroup from this SbgnListOfArcGroups and returns a
 * pointer to it.
 */
SbgnArcGroup*
SbgnListOfArcGroups::remove(unsigned int n)
{
  return static_cast<SbgnArcGroup*>(SbgnListOf::remove(n));
}


/*
 * Removes the SbgnArcGroup from this SbgnListOfArcGroups based on its
 * identifier and returns a pointer to it.
 */
SbgnArcGroup*
SbgnListOfArcGroups::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnArcGroup>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SbgnArcGroup*> (item);
}


/*
 * Adds a copy of the given SbgnArcGroup to this SbgnListOfArcGroups.
 */
int
SbgnListOfArcGroups::addArcGroup(const SbgnArcGroup* sag)
{
  if (sag == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sag->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sag->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sag->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sag)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sag);
  }
}


/*
 * Get the number of SbgnArcGroup objects in this SbgnListOfArcGroups.
 */
unsigned int
SbgnListOfArcGroups::getNumArcGroups() const
{
  return size();
}


/*
 * Creates a new SbgnArcGroup object, adds it to this SbgnListOfArcGroups
 * object and returns the SbgnArcGroup object created.
 */
SbgnArcGroup*
SbgnListOfArcGroups::createArcGroup()
{
  SbgnArcGroup* sag = NULL;

  try
  {
    sag = new SbgnArcGroup(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sag != NULL)
  {
    appendAndOwn(sag);
  }

  return sag;
}


/*
 * Returns the XML element name of this SbgnListOfArcGroups object.
 */
const std::string&
SbgnListOfArcGroups::getElementName() const
{
  static const string name = "listOfArcGroups";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnListOfArcGroups object.
 */
int
SbgnListOfArcGroups::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfArcGroups object.
 */
int
SbgnListOfArcGroups::getItemTypeCode() const
{
  return SBGN_SBGNML_ARCGROUP;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new SbgnArcGroup in this SbgnListOfArcGroups
 */
SbgnBase*
SbgnListOfArcGroups::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER
  XMLInputStream& stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == "arcGroup")
  {
    object = new SbgnArcGroup(getSbgnNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SbgnArcGroup_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_getArcGroup(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfArcGroups*>(slo)->get(n);
}


/*
 * Get a SbgnArcGroup_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfArcGroups*>(slo)->get(sid) :
    NULL;
}


/*
 * Removes the nth SbgnArcGroup_t from this SbgnListOf_t and returns a pointer
 * to it.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfArcGroups*>(slo)->remove(n);
}


/*
 * Removes the SbgnArcGroup_t from this SbgnListOf_t based on its identifier
 * and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnListOfArcGroups_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfArcGroups*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END



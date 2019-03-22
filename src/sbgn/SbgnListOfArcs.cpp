/**
 * @file SbgnListOfArcs.cpp
 * @brief Implementation of the SbgnListOfArcs class.
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
#include <sbgn/SbgnListOfArcs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfArcs using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfArcs::SbgnListOfArcs(unsigned int level, unsigned int version)
  : SbgnListOf(level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfArcs using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfArcs::SbgnListOfArcs(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfArcs.
 */
SbgnListOfArcs::SbgnListOfArcs(const SbgnListOfArcs& orig)
  : SbgnListOf( orig )
{
}


/*
 * Assignment operator for SbgnListOfArcs.
 */
SbgnListOfArcs&
SbgnListOfArcs::operator=(const SbgnListOfArcs& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfArcs object.
 */
SbgnListOfArcs*
SbgnListOfArcs::clone() const
{
  return new SbgnListOfArcs(*this);
}


/*
 * Destructor for SbgnListOfArcs.
 */
SbgnListOfArcs::~SbgnListOfArcs()
{
}


/*
 * Get a SbgnArc from the SbgnListOfArcs.
 */
SbgnArc*
SbgnListOfArcs::get(unsigned int n)
{
  return static_cast<SbgnArc*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnArc from the SbgnListOfArcs.
 */
const SbgnArc*
SbgnListOfArcs::get(unsigned int n) const
{
  return static_cast<const SbgnArc*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnArc from the SbgnListOfArcs based on its identifier.
 */
SbgnArc*
SbgnListOfArcs::get(const std::string& sid)
{
  return const_cast<SbgnArc*>(static_cast<const
    SbgnListOfArcs&>(*this).get(sid));
}


/*
 * Get a SbgnArc from the SbgnListOfArcs based on its identifier.
 */
const SbgnArc*
SbgnListOfArcs::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnArc>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnArc*> (*result);
}


/*
 * Removes the nth SbgnArc from this SbgnListOfArcs and returns a pointer to
 * it.
 */
SbgnArc*
SbgnListOfArcs::remove(unsigned int n)
{
  return static_cast<SbgnArc*>(SbgnListOf::remove(n));
}


/*
 * Removes the SbgnArc from this SbgnListOfArcs based on its identifier and
 * returns a pointer to it.
 */
SbgnArc*
SbgnListOfArcs::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnArc>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SbgnArc*> (item);
}


/*
 * Adds a copy of the given SbgnArc to this SbgnListOfArcs.
 */
int
SbgnListOfArcs::addArc(const SbgnArc* sa)
{
  if (sa == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sa->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sa->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sa->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sa)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sa);
  }
}


/*
 * Get the number of SbgnArc objects in this SbgnListOfArcs.
 */
unsigned int
SbgnListOfArcs::getNumArcs() const
{
  return size();
}


/*
 * Creates a new SbgnArc object, adds it to this SbgnListOfArcs object and
 * returns the SbgnArc object created.
 */
SbgnArc*
SbgnListOfArcs::createArc()
{
  SbgnArc* sa = NULL;

  try
  {
    sa = new SbgnArc(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sa != NULL)
  {
    appendAndOwn(sa);
  }

  return sa;
}


/*
 * Returns the XML element name of this SbgnListOfArcs object.
 */
const std::string&
SbgnListOfArcs::getElementName() const
{
  static const string name = "listOfArcs";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnListOfArcs object.
 */
int
SbgnListOfArcs::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfArcs object.
 */
int
SbgnListOfArcs::getItemTypeCode() const
{
  return SBGN_SBGNML_ARC;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new SbgnArc in this SbgnListOfArcs
 */
SbgnBase*
SbgnListOfArcs::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == "arc")
  {
    object = new SbgnArc(getSbgnNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SbgnArc_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_getArc(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfArcs*>(slo)->get(n);
}


/*
 * Get a SbgnArc_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfArcs*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SbgnArc_t from this SbgnListOf_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfArcs*>(slo)->remove(n);
}


/*
 * Removes the SbgnArc_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnListOfArcs_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfArcs*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END



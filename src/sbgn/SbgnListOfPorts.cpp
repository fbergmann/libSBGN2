/**
 * @file SbgnListOfPorts.cpp
 * @brief Implementation of the SbgnListOfPorts class.
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
#include <sbgn/SbgnListOfPorts.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfPorts using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfPorts::SbgnListOfPorts(unsigned int level, unsigned int version)
  : SbgnListOf(level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfPorts using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfPorts::SbgnListOfPorts(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfPorts.
 */
SbgnListOfPorts::SbgnListOfPorts(const SbgnListOfPorts& orig)
  : SbgnListOf( orig )
{
}


/*
 * Assignment operator for SbgnListOfPorts.
 */
SbgnListOfPorts&
SbgnListOfPorts::operator=(const SbgnListOfPorts& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfPorts object.
 */
SbgnListOfPorts*
SbgnListOfPorts::clone() const
{
  return new SbgnListOfPorts(*this);
}


/*
 * Destructor for SbgnListOfPorts.
 */
SbgnListOfPorts::~SbgnListOfPorts()
{
}


/*
 * Get a SbgnPort from the SbgnListOfPorts.
 */
SbgnPort*
SbgnListOfPorts::get(unsigned int n)
{
  return static_cast<SbgnPort*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnPort from the SbgnListOfPorts.
 */
const SbgnPort*
SbgnListOfPorts::get(unsigned int n) const
{
  return static_cast<const SbgnPort*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnPort from the SbgnListOfPorts based on its identifier.
 */
SbgnPort*
SbgnListOfPorts::get(const std::string& sid)
{
  return const_cast<SbgnPort*>(static_cast<const
    SbgnListOfPorts&>(*this).get(sid));
}


/*
 * Get a SbgnPort from the SbgnListOfPorts based on its identifier.
 */
const SbgnPort*
SbgnListOfPorts::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnPort>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnPort*>
    (*result);
}


/*
 * Removes the nth SbgnPort from this SbgnListOfPorts and returns a pointer to
 * it.
 */
SbgnPort*
SbgnListOfPorts::remove(unsigned int n)
{
  return static_cast<SbgnPort*>(SbgnListOf::remove(n));
}


/*
 * Removes the SbgnPort from this SbgnListOfPorts based on its identifier and
 * returns a pointer to it.
 */
SbgnPort*
SbgnListOfPorts::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnPort>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SbgnPort*> (item);
}


/*
 * Adds a copy of the given SbgnPort to this SbgnListOfPorts.
 */
int
SbgnListOfPorts::addPort(const SbgnPort* sp)
{
  if (sp == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sp)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return append(sp);
  }
}


/*
 * Get the number of SbgnPort objects in this SbgnListOfPorts.
 */
unsigned int
SbgnListOfPorts::getNumPorts() const
{
  return size();
}


/*
 * Creates a new SbgnPort object, adds it to this SbgnListOfPorts object and
 * returns the SbgnPort object created.
 */
SbgnPort*
SbgnListOfPorts::createPort()
{
  SbgnPort* sp = NULL;

  try
  {
    sp = new SbgnPort(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    appendAndOwn(sp);
  }

  return sp;
}


/*
 * Returns the XML element name of this SbgnListOfPorts object.
 */
const std::string&
SbgnListOfPorts::getElementName() const
{
  static const string name = "listOfPorts";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnListOfPorts object.
 */
int
SbgnListOfPorts::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfPorts object.
 */
int
SbgnListOfPorts::getItemTypeCode() const
{
  return SBGN_SBGNML_PORT;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new SbgnPort in this SbgnListOfPorts
 */
SbgnBase*
SbgnListOfPorts::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == "port")
  {
    object = new SbgnPort(getSbgnNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SbgnPort_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_getPort(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfPorts*>(slo)->get(n);
}


/*
 * Get a SbgnPort_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfPorts*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SbgnPort_t from this SbgnListOf_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfPorts*>(slo)->remove(n);
}


/*
 * Removes the SbgnPort_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnListOfPorts_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfPorts*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END



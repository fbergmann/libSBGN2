/**
 * @file SbgnNamespaces.cpp
 * @brief Implementation of the SbgnNamespaces class.
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


#include <sbgn/SbgnNamespaces.h>
#include <sstream>
#include <sbgn/common/common.h>
#include <iostream>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */


LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsbgnInternal */
void 
SbgnNamespaces::initSbgnNamespace()
{
  mNamespaces = new XMLNamespaces();

  switch (mLevel)
  {
  case 0:
  default:
    switch (mVersion)
    {
    case 1:
      mNamespaces->add(SBGN_XMLNS_L0V1);
      break;
    case 2:
      mNamespaces->add(SBGN_XMLNS_L0V2);
      break;
    case 3:
    default:
      mNamespaces->add(SBGN_XMLNS_L0V3);
      break;
    }
    break;
  }

  if (mNamespaces->getLength() == 0)
  {
    mLevel = SBGN_INT_MAX;
    mVersion = SBGN_INT_MAX;
    delete mNamespaces;
    mNamespaces = NULL;
  }
}
/** @endcond */


SbgnNamespaces::SbgnNamespaces(unsigned int level, unsigned int version)
 : mLevel(level)
  ,mVersion(version)
{
  initSbgnNamespace();
}


SbgnNamespaces::~SbgnNamespaces()
{
  if (mNamespaces != NULL)
    delete mNamespaces;
}


/*
 * Copy constructor; creates a copy of a SbgnNamespaces.
 */
SbgnNamespaces::SbgnNamespaces(const SbgnNamespaces& orig)
 : mLevel(orig.mLevel)
 , mVersion(orig.mVersion)
 , mNamespaces(NULL)
{
  if(orig.mNamespaces != NULL)
    this->mNamespaces = 
          new XMLNamespaces(*const_cast<SbgnNamespaces&>(orig).mNamespaces);
}


const List * 
SbgnNamespaces::getSupportedNamespaces()
{
  List *result = new List();
  result->add(new SbgnNamespaces(0,1));
  result->add(new SbgnNamespaces(0,2));
  result->add(new SbgnNamespaces(0,3));
  return result;
}


void 
SbgnNamespaces::freeSbgnNamespaces(List * supportedNS)
{
  if (supportedNS == NULL) return;
  for (unsigned int i = 0; i < supportedNS->getSize(); i++)
  {
    delete (SbgnNamespaces*)supportedNS->get(i);
  }
  delete supportedNS;
}

/*
 * Assignment operator for SbgnNamespaces.
 */
SbgnNamespaces&
SbgnNamespaces::operator=(const SbgnNamespaces& rhs)
{
  if (&rhs != this)
  {
    mLevel   = rhs.mLevel;
    mVersion = rhs.mVersion;
    delete this->mNamespaces;
    if(rhs.mNamespaces != NULL)
      this->mNamespaces = 
            new XMLNamespaces(*const_cast<SbgnNamespaces&>(rhs).mNamespaces);
    else
      this->mNamespaces = NULL;
  }

  return *this;
}



/*
 * Creates and returns a deep copy of this SbgnNamespaces.
 */
SbgnNamespaces *
SbgnNamespaces::clone () const
{
  return new SbgnNamespaces(*this);
}


std::string 
SbgnNamespaces::getSbgnNamespaceURI(unsigned int level,
                                 unsigned int version)
{
  std::string uri = "";
  switch (level)
  {
  case 0:
  default:
    switch (version)
    {
    case 1:
      uri = SBGN_XMLNS_L0V1;
      break;
    case 2:
      uri = SBGN_XMLNS_L0V2;
      break;
    case 3:
    default:
      uri = SBGN_XMLNS_L0V3;
      break;
    }
    break;
  }
  return uri;
}


std::string
SbgnNamespaces::getURI() const
{
  return getSbgnNamespaceURI(mLevel,mVersion);
}


unsigned int 
SbgnNamespaces::getLevel()
{
  return mLevel;
}


unsigned int 
SbgnNamespaces::getLevel() const
{
  return mLevel;
}


unsigned int 
SbgnNamespaces::getVersion()
{
  return mVersion;
}


unsigned int 
SbgnNamespaces::getVersion() const
{
  return mVersion;
}


XMLNamespaces * 
SbgnNamespaces::getNamespaces()
{
  return mNamespaces;
}


const XMLNamespaces * 
SbgnNamespaces::getNamespaces() const
{
  return mNamespaces;
}


int
SbgnNamespaces::addNamespaces(const XMLNamespaces * xmlns)
{
  int success = LIBSBGN_OPERATION_SUCCESS;

  if (xmlns == NULL)
    return LIBSBGN_INVALID_OBJECT;

  if (!mNamespaces) 
  {
    initSbgnNamespace();
  }

  /* check whether the namespace already exists
   * add if it does not
   */
  for (int i = 0; i < xmlns->getLength(); i++)
  {
    if (mNamespaces != NULL && !(mNamespaces->hasNS(xmlns->getURI(i), xmlns->getPrefix(i))))
    {
      success = mNamespaces->add(xmlns->getURI(i), xmlns->getPrefix(i));
    }
  }

  return success;
}


int
SbgnNamespaces::addNamespace(const std::string &uri, const std::string &prefix)
{
  if (!mNamespaces) 
  {
    initSbgnNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->add(uri, prefix) : LIBSBGN_INVALID_OBJECT;
}


int
SbgnNamespaces::removeNamespace(const std::string &uri)
{
  if (!mNamespaces) 
  {
    initSbgnNamespace();
  }

  return mNamespaces != NULL ? mNamespaces->remove(mNamespaces->getIndex(uri)) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c true if the given
 * URL is one of SBGN XML namespaces.
 */
bool 
SbgnNamespaces::isSbgnNamespace(const std::string& uri)
{
  if (uri == SBGN_XMLNS_L0V1)   return true;

  return false;
}

bool 
SbgnNamespaces::isValidCombination()
{
  bool valid = true;
  bool sbgnDeclared = false;
  std::string declaredURI("");
  unsigned int version = getVersion();
  XMLNamespaces *xmlns = getNamespaces();

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SBGN_XMLNS_L0V1))
    {
      ++numNS;
      declaredURI.assign(SBGN_XMLNS_L0V1);
    }

    if (xmlns->hasURI(SBGN_XMLNS_L0V2))
    {
      ++numNS;
      declaredURI.assign(SBGN_XMLNS_L0V2);
    }

    if (xmlns->hasURI(SBGN_XMLNS_L0V3))
    {
      ++numNS;
      declaredURI.assign(SBGN_XMLNS_L0V3);
    }

    // checks if the SBGN Namespace is explicitly defined.
    for (int i=0; i < xmlns->getLength(); i++)
    {
      if (!declaredURI.empty() && 
                      xmlns->getURI(i) == declaredURI)
      {
        sbgnDeclared = true;
        break;
      }
    }
  }


  switch (getLevel())
  {
  case 0:
    switch (version)
    {
    case 1:
      // the namespaces contains the sbgn namespaces
      // check it is the correct ns for the level/version
      if (sbgnDeclared)
      {
        if (declaredURI != string(SBGN_XMLNS_L0V1))
        {
          valid = false;
        }
      }
      break;
    case 2:
      // the namespaces contains the sbgn namespaces
      // check it is the correct ns for the level/version
      if (sbgnDeclared)
      {
        if (declaredURI != string(SBGN_XMLNS_L0V2))
        {
          valid = false;
        }
      }
      break;
    case 3:
      // the namespaces contains the sbgn namespaces
      // check it is the correct ns for the level/version
      if (sbgnDeclared)
      {
        if (declaredURI != string(SBGN_XMLNS_L0V3))
        {
          valid = false;
        }
      }
      break;
    default:
      valid = false;
      break;
    }
    break;
  default:
    valid = false;
    break;
  }

  return valid;
}


/** @cond doxygenLibsbgnInternal */
void 
SbgnNamespaces::setLevel(unsigned int level)
{
  mLevel = level;
}


void 
SbgnNamespaces::setVersion(unsigned int version)
{
  mVersion = version;
}


void 
SbgnNamespaces::setNamespaces(XMLNamespaces * xmlns)
{
  delete mNamespaces;
  if (xmlns != NULL)
    mNamespaces = xmlns->clone();
  else
    mNamespaces = NULL;
}
/** @endcond */

#endif /* __cplusplus */


/** @cond doxygenIgnored */

LIBSBGN_EXTERN
SbgnNamespaces_t *
SbgnNamespaces_create(unsigned int level, unsigned int version)
{
  return new SbgnNamespaces(level, version);
}


LIBSBGN_EXTERN
void
SbgnNamespaces_free(SbgnNamespaces_t* ns)
{
  if (ns == NULL) return;
  delete static_cast<SbgnNamespaces*>(ns);
}


LIBSBGN_EXTERN
unsigned int
SbgnNamespaces_getLevel(SbgnNamespaces_t *sbgnns)
{
  return (sbgnns != NULL) ? sbgnns->getLevel() : SBGN_INT_MAX;
}


LIBSBGN_EXTERN
unsigned int
SbgnNamespaces_getVersion(SbgnNamespaces_t *sbgnns)
{
  return (sbgnns != NULL) ? sbgnns->getVersion() : SBGN_INT_MAX;
}


LIBSBGN_EXTERN
XMLNamespaces_t *
SbgnNamespaces_getNamespaces(SbgnNamespaces_t *sbgnns)
{
  return (sbgnns != NULL) ? sbgnns->getNamespaces() : NULL;
}


LIBSBGN_EXTERN
char *
SbgnNamespaces_getSbgnNamespaceURI(unsigned int level, unsigned int version)
{
  return safe_strdup(SbgnNamespaces::getSbgnNamespaceURI(level, version).c_str());
}


LIBSBGN_EXTERN
int
SbgnNamespaces_addNamespaces(SbgnNamespaces_t *sbgnns,
                             const XMLNamespaces_t * xmlns)
{
  if (sbgnns != NULL)
    return sbgnns->addNamespaces(xmlns);
  else
    return LIBSBGN_INVALID_OBJECT;
}

LIBSBGN_EXTERN
SbgnNamespaces_t **
SbgnNamespaces_getSupportedNamespaces(int *length)
{
  if (length == NULL) return NULL;
   const List* supported = SbgnNamespaces::getSupportedNamespaces();
  
   *length = (int) supported->getSize();
  SbgnNamespaces_t ** result = (SbgnNamespaces_t**)malloc(sizeof(SbgnNamespaces_t*)*((unsigned long)*length));
  memset(result, 0, sizeof(SbgnNamespaces_t*)*((unsigned long)*length));
  for (int i = 0; i < *length; i++)
  {
    result[i] = ((SbgnNamespaces*)supported->get((unsigned int)i))->clone();
  }
  SbgnNamespaces::freeSbgnNamespaces(const_cast<List*>(supported));
  return result;
}
/** @endcond */

LIBSBGN_CPP_NAMESPACE_END


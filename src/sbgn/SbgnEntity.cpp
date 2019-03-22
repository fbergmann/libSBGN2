/**
 * @file SbgnEntity.cpp
 * @brief Implementation of the SbgnEntity class.
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
#include <sbgn/SbgnEntity.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnEntity using the given SBGN Level and @ p version values.
 */
SbgnEntity::SbgnEntity(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mName ("")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnEntity using the given SbgnNamespaces object @p sbgnns.
 */
SbgnEntity::SbgnEntity(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mName ("")
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnEntity.
 */
SbgnEntity::SbgnEntity(const SbgnEntity& orig)
  : SbgnBase( orig )
  , mName ( orig.mName )
{
}


/*
 * Assignment operator for SbgnEntity.
 */
SbgnEntity&
SbgnEntity::operator=(const SbgnEntity& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mName = rhs.mName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnEntity object.
 */
SbgnEntity*
SbgnEntity::clone() const
{
  return new SbgnEntity(*this);
}


/*
 * Destructor for SbgnEntity.
 */
SbgnEntity::~SbgnEntity()
{
}


/*
 * Returns the value of the "name" attribute of this SbgnEntity.
 */
const std::string&
SbgnEntity::getName() const
{
  return mName;
}


/*
 * Predicate returning @c true if this SbgnEntity's "name" attribute is set.
 */
bool
SbgnEntity::isSetName() const
{
  return (mName.empty() == false);
}


/*
 * Sets the value of the "name" attribute of this SbgnEntity.
 */
int
SbgnEntity::setName(const std::string& name)
{
  mName = name;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "name" attribute of this SbgnEntity.
 */
int
SbgnEntity::unsetName()
{
  mName.erase();

  if (mName.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SbgnEntity object.
 */
const std::string&
SbgnEntity::getElementName() const
{
  static const string name = "entity";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnEntity object.
 */
int
SbgnEntity::getTypeCode() const
{
  return SBGN_SBGNML_ENTITY;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnEntity object have been set.
 */
bool
SbgnEntity::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetName() == false)
  {
    allPresent = false;
  }

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
SbgnEntity::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnEntity::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnEntity::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::getAttribute(const std::string& attributeName,
                         double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::getAttribute(const std::string& attributeName,
                         unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::getAttribute(const std::string& attributeName,
                         std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "name")
  {
    value = getName();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnEntity's attribute "attributeName"
 * is set.
 */
bool
SbgnEntity::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "name")
  {
    value = isSetName();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::setAttribute(const std::string& attributeName,
                         const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "name")
  {
    return_value = setName(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnEntity.
 */
int
SbgnEntity::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "name")
  {
    value = unsetName();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
SbgnEntity::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("name");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnEntity::readAttributes(
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&
                             attributes,
                           const LIBSBML_CPP_NAMESPACE_QUALIFIER
                             ExpectedAttributes& expectedAttributes)
{
  unsigned int level = getLevel();
  unsigned int version = getVersion();
  unsigned int numErrs;
  bool assigned = false;
  SbgnErrorLog* log = getErrorLog();

  SbgnBase::readAttributes(attributes, expectedAttributes);

  if (log)
  {
    numErrs = log->getNumErrors();

    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnmlEntityAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // name string (use = "required" )
  // 

  assigned = attributes.readInto("name", mName);

  if (assigned == true)
  {
    if (mName.empty() == true)
    {
      logEmptyString(mName, level, version, "<SbgnEntity>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'name' is missing from the "
      "<SbgnEntity> element.";
    log->logError(SbgnmlEntityAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnEntity::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetName() == true)
  {
    stream.writeAttribute("name", getPrefix(), mName);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnEntity_t using the given SBGN Level and @ p version
 * values.
 */
LIBSBGN_EXTERN
SbgnEntity_t *
SbgnEntity_create(unsigned int level, unsigned int version)
{
  return new SbgnEntity(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnEntity_t object.
 */
LIBSBGN_EXTERN
SbgnEntity_t*
SbgnEntity_clone(const SbgnEntity_t* se)
{
  if (se != NULL)
  {
    return static_cast<SbgnEntity_t*>(se->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnEntity_t object.
 */
LIBSBGN_EXTERN
void
SbgnEntity_free(SbgnEntity_t* se)
{
  if (se != NULL)
  {
    delete se;
  }
}


/*
 * Returns the value of the "name" attribute of this SbgnEntity_t.
 */
LIBSBGN_EXTERN
char *
SbgnEntity_getName(const SbgnEntity_t * se)
{
  if (se == NULL)
  {
    return NULL;
  }

  return se->getName().empty() ? NULL : safe_strdup(se->getName().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnEntity_t's "name" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnEntity_isSetName(const SbgnEntity_t * se)
{
  return (se != NULL) ? static_cast<int>(se->isSetName()) : 0;
}


/*
 * Sets the value of the "name" attribute of this SbgnEntity_t.
 */
LIBSBGN_EXTERN
int
SbgnEntity_setName(SbgnEntity_t * se, const char * name)
{
  return (se != NULL) ? se->setName(name) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "name" attribute of this SbgnEntity_t.
 */
LIBSBGN_EXTERN
int
SbgnEntity_unsetName(SbgnEntity_t * se)
{
  return (se != NULL) ? se->unsetName() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnEntity_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnEntity_hasRequiredAttributes(const SbgnEntity_t * se)
{
  return (se != NULL) ? static_cast<int>(se->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



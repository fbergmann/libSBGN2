/**
 * @file SbgnPort.cpp
 * @brief Implementation of the SbgnPort class.
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
#include <sbgn/SbgnPort.h>
#include <sbgn/SbgnListOfPorts.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnPort using the given SBGN Level and @ p version values.
 */
SbgnPort::SbgnPort(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnPort using the given SbgnNamespaces object @p sbgnns.
 */
SbgnPort::SbgnPort(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnPort.
 */
SbgnPort::SbgnPort(const SbgnPort& orig)
  : SbgnBase( orig )
  , mX ( orig.mX )
  , mIsSetX ( orig.mIsSetX )
  , mY ( orig.mY )
  , mIsSetY ( orig.mIsSetY )
{
}


/*
 * Assignment operator for SbgnPort.
 */
SbgnPort&
SbgnPort::operator=(const SbgnPort& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mX = rhs.mX;
    mIsSetX = rhs.mIsSetX;
    mY = rhs.mY;
    mIsSetY = rhs.mIsSetY;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnPort object.
 */
SbgnPort*
SbgnPort::clone() const
{
  return new SbgnPort(*this);
}


/*
 * Destructor for SbgnPort.
 */
SbgnPort::~SbgnPort()
{
}


/*
 * Returns the value of the "id" attribute of this SbgnPort.
 */
const std::string&
SbgnPort::getId() const
{
  return mId;
}


/*
 * Returns the value of the "x" attribute of this SbgnPort.
 */
double
SbgnPort::getX() const
{
  return mX;
}


/*
 * Returns the value of the "y" attribute of this SbgnPort.
 */
double
SbgnPort::getY() const
{
  return mY;
}


/*
 * Predicate returning @c true if this SbgnPort's "id" attribute is set.
 */
bool
SbgnPort::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnPort's "x" attribute is set.
 */
bool
SbgnPort::isSetX() const
{
  return mIsSetX;
}


/*
 * Predicate returning @c true if this SbgnPort's "y" attribute is set.
 */
bool
SbgnPort::isSetY() const
{
  return mIsSetY;
}


/*
 * Sets the value of the "id" attribute of this SbgnPort.
 */
int
SbgnPort::setId(const std::string& id)
{
  if (!(SyntaxChecker::isValidXMLID(id)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mId = id;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "x" attribute of this SbgnPort.
 */
int
SbgnPort::setX(double x)
{
  mX = x;
  mIsSetX = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "y" attribute of this SbgnPort.
 */
int
SbgnPort::setY(double y)
{
  mY = y;
  mIsSetY = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SbgnPort.
 */
int
SbgnPort::unsetId()
{
  mId.erase();

  if (mId.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "x" attribute of this SbgnPort.
 */
int
SbgnPort::unsetX()
{
  mX = util_NaN();
  mIsSetX = false;

  if (isSetX() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "y" attribute of this SbgnPort.
 */
int
SbgnPort::unsetY()
{
  mY = util_NaN();
  mIsSetY = false;

  if (isSetY() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SbgnPort object.
 */
const std::string&
SbgnPort::getElementName() const
{
  static const string name = "port";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnPort object.
 */
int
SbgnPort::getTypeCode() const
{
  return SBGN_SBGNML_PORT;
}


/*
 * Predicate returning @c true if all the required attributes for this SbgnPort
 * object have been set.
 */
bool
SbgnPort::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetX() == false)
  {
    allPresent = false;
  }

  if (isSetY() == false)
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
SbgnPort::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SbgnPort::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnPort::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "x")
  {
    value = getX();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "y")
  {
    value = getY();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "id")
  {
    value = getId();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnPort's attribute "attributeName" is
 * set.
 */
bool
SbgnPort::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "x")
  {
    value = isSetX();
  }
  else if (attributeName == "y")
  {
    value = isSetY();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "x")
  {
    return_value = setX(value);
  }
  else if (attributeName == "y")
  {
    return_value = setY(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnPort.
 */
int
SbgnPort::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "x")
  {
    value = unsetX();
  }
  else if (attributeName == "y")
  {
    value = unsetY();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
SbgnPort::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("x");

  attributes.add("y");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnPort::readAttributes(
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

  if (log && getParentSbgnObject() &&
    static_cast<SbgnListOfPorts*>(getParentSbgnObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnUnknown, level, version, details);
      }
    }
  }

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
        log->logError(SbgnmlPortAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // id ID (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SbgnPort>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnUnknown, level, version, "The attribute id='" + mId + "' "
        "does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'id' is missing from the <SbgnPort> "
      "element.";
    log->logError(SbgnmlPortAllowedAttributes, level, version, message);
  }

  // 
  // x double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetX = attributes.readInto("x", mX);

  if ( mIsSetX == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'x' from the <SbgnPort> element "
        "must be an integer.";
      log->logError(SbgnmlPortXMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'x' is missing from the "
        "<SbgnPort> element.";
      log->logError(SbgnmlPortAllowedAttributes, level, version, message);
    }
  }

  // 
  // y double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetY = attributes.readInto("y", mY);

  if ( mIsSetY == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'y' from the <SbgnPort> element "
        "must be an integer.";
      log->logError(SbgnmlPortYMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'y' is missing from the "
        "<SbgnPort> element.";
      log->logError(SbgnmlPortAllowedAttributes, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnPort::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetX() == true)
  {
    stream.writeAttribute("x", getPrefix(), mX);
  }

  if (isSetY() == true)
  {
    stream.writeAttribute("y", getPrefix(), mY);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnPort_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnPort_t *
SbgnPort_create(unsigned int level, unsigned int version)
{
  return new SbgnPort(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnPort_t object.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnPort_clone(const SbgnPort_t* sp)
{
  if (sp != NULL)
  {
    return static_cast<SbgnPort_t*>(sp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnPort_t object.
 */
LIBSBGN_EXTERN
void
SbgnPort_free(SbgnPort_t* sp)
{
  if (sp != NULL)
  {
    delete sp;
  }
}


/*
 * Returns the value of the "id" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
char *
SbgnPort_getId(const SbgnPort_t * sp)
{
  if (sp == NULL)
  {
    return NULL;
  }

  return sp->getId().empty() ? NULL : safe_strdup(sp->getId().c_str());
}


/*
 * Returns the value of the "x" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
double
SbgnPort_getX(const SbgnPort_t * sp)
{
  return (sp != NULL) ? sp->getX() : util_NaN();
}


/*
 * Returns the value of the "y" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
double
SbgnPort_getY(const SbgnPort_t * sp)
{
  return (sp != NULL) ? sp->getY() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SbgnPort_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetId(const SbgnPort_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnPort_t's "x" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetX(const SbgnPort_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnPort_t's "y" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnPort_isSetY(const SbgnPort_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetY()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_setId(SbgnPort_t * sp, const char * id)
{
  return (sp != NULL) ? sp->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "x" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_setX(SbgnPort_t * sp, double x)
{
  return (sp != NULL) ? sp->setX(x) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "y" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_setY(SbgnPort_t * sp, double y)
{
  return (sp != NULL) ? sp->setY(y) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetId(SbgnPort_t * sp)
{
  return (sp != NULL) ? sp->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "x" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetX(SbgnPort_t * sp)
{
  return (sp != NULL) ? sp->unsetX() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "y" attribute of this SbgnPort_t.
 */
LIBSBGN_EXTERN
int
SbgnPort_unsetY(SbgnPort_t * sp)
{
  return (sp != NULL) ? sp->unsetY() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnPort_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnPort_hasRequiredAttributes(const SbgnPort_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



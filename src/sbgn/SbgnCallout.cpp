/**
 * @file SbgnCallout.cpp
 * @brief Implementation of the SbgnCallout class.
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
#include <sbgn/SbgnCallout.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnCallout using the given SBGN Level and @ p version values.
 */
SbgnCallout::SbgnCallout(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mTarget ("")
  , mPoint (NULL)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnCallout using the given SbgnNamespaces object @p sbgnns.
 */
SbgnCallout::SbgnCallout(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mTarget ("")
  , mPoint (NULL)
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnCallout.
 */
SbgnCallout::SbgnCallout(const SbgnCallout& orig)
  : SbgnBase( orig )
  , mTarget ( orig.mTarget )
  , mPoint ( NULL )
{
  if (orig.mPoint != NULL)
  {
    mPoint = orig.mPoint->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnCallout.
 */
SbgnCallout&
SbgnCallout::operator=(const SbgnCallout& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mTarget = rhs.mTarget;
    delete mPoint;
    if (rhs.mPoint != NULL)
    {
      mPoint = rhs.mPoint->clone();
    }
    else
    {
      mPoint = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnCallout object.
 */
SbgnCallout*
SbgnCallout::clone() const
{
  return new SbgnCallout(*this);
}


/*
 * Destructor for SbgnCallout.
 */
SbgnCallout::~SbgnCallout()
{
  delete mPoint;
  mPoint = NULL;
}


/*
 * Returns the value of the "target" attribute of this SbgnCallout.
 */
const std::string&
SbgnCallout::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this SbgnCallout's "target" attribute is set.
 */
bool
SbgnCallout::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "target" attribute of this SbgnCallout.
 */
int
SbgnCallout::setTarget(const std::string& target)
{
  if (!(SyntaxChecker::isValidXMLID(target)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTarget = target;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "target" attribute of this SbgnCallout.
 */
int
SbgnCallout::unsetTarget()
{
  mTarget.erase();

  if (mTarget.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "point" element of this SbgnCallout.
 */
const SbgnPoint*
SbgnCallout::getPoint() const
{
  return mPoint;
}


/*
 * Returns the value of the "point" element of this SbgnCallout.
 */
SbgnPoint*
SbgnCallout::getPoint()
{
  return mPoint;
}


/*
 * Predicate returning @c true if this SbgnCallout's "point" element is set.
 */
bool
SbgnCallout::isSetPoint() const
{
  return (mPoint != NULL);
}


/*
 * Sets the value of the "point" element of this SbgnCallout.
 */
int
SbgnCallout::setPoint(const SbgnPoint* point)
{
  if (mPoint == point)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (point == NULL)
  {
    delete mPoint;
    mPoint = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mPoint;
    mPoint = (point != NULL) ? point->clone() : NULL;
    if (mPoint != NULL)
    {
      mPoint->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SbgnPoint object, adds it to this SbgnCallout object and
 * returns the SbgnPoint object created.
 */
SbgnPoint*
SbgnCallout::createPoint()
{
  if (mPoint != NULL)
  {
    delete mPoint;
  }

  mPoint = new SbgnPoint(getSbgnNamespaces());

  connectToChild();

  return mPoint;
}


/*
 * Unsets the value of the "point" element of this SbgnCallout.
 */
int
SbgnCallout::unsetPoint()
{
  delete mPoint;
  mPoint = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SbgnCallout object.
 */
const std::string&
SbgnCallout::getElementName() const
{
  static const string name = "callout";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnCallout object.
 */
int
SbgnCallout::getTypeCode() const
{
  return SBGN_SBGNML_CALLOUT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnCallout object have been set.
 */
bool
SbgnCallout::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SbgnCallout object have been set.
 */
bool
SbgnCallout::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetPoint() == false)
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
SbgnCallout::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  if (isSetPoint() == true)
  {
    mPoint->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnCallout::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnCallout::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  if (mPoint != NULL)
  {
    mPoint->setSbgnDocument(d);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnCallout::connectToChild()
{
  SbgnBase::connectToChild();

  if (mPoint != NULL)
  {
    mPoint->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::getAttribute(const std::string& attributeName,
                          double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::getAttribute(const std::string& attributeName,
                          unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::getAttribute(const std::string& attributeName,
                          std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnCallout's attribute "attributeName"
 * is set.
 */
bool
SbgnCallout::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::setAttribute(const std::string& attributeName,
                          unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::setAttribute(const std::string& attributeName,
                          const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnCallout.
 */
int
SbgnCallout::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnCallout.
 */
SbgnBase*
SbgnCallout::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "point")
  {
    return createPoint();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnCallout.
 */
int
SbgnCallout::addChildObject(const std::string& elementName,
                            const SbgnBase* element)
{
  if (elementName == "point" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return setPoint((const SbgnPoint*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnCallout.
 */
SbgnBase*
SbgnCallout::removeChildObject(const std::string& elementName,
                               const std::string& id)
{
  if (elementName == "point")
  {
    SbgnPoint * obj = getPoint();
    if (unsetPoint() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnCallout.
 */
unsigned int
SbgnCallout::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "point")
  {
    if (isSetPoint())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnCallout.
 */
SbgnBase*
SbgnCallout::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "point")
  {
    return getPoint();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnCallout::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mPoint != NULL)
  {
    if (mPoint->getId() == id)
    {
      return mPoint;
    }

    obj = mPoint->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  return obj;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SbgnBase*
SbgnCallout::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "point")
  {
    if (isSetPoint())
    {
      getErrorLog()->logError(SbgnmlCalloutAllowedElements, getLevel(),
        getVersion());
    }

    delete mPoint;
    mPoint = new SbgnPoint(getSbgnNamespaces());
    obj = mPoint;
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
SbgnCallout::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnCallout::readAttributes(
                            const LIBSBML_CPP_NAMESPACE_QUALIFIER
                              XMLAttributes& attributes,
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
        log->logError(SbgnmlCalloutAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // target IDREF (use = "optional" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SbgnCallout>");
    }
    else if (SyntaxChecker::isValidXMLID(mTarget) == false)
    {
      std::string msg = "The target attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTarget + "', which does not conform to the syntax.";
      logError(SbgnUnknown, level, version, msg);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnCallout::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnCallout_t using the given SBGN Level and @ p version
 * values.
 */
LIBSBGN_EXTERN
SbgnCallout_t *
SbgnCallout_create(unsigned int level, unsigned int version)
{
  return new SbgnCallout(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnCallout_t object.
 */
LIBSBGN_EXTERN
SbgnCallout_t*
SbgnCallout_clone(const SbgnCallout_t* sc)
{
  if (sc != NULL)
  {
    return static_cast<SbgnCallout_t*>(sc->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnCallout_t object.
 */
LIBSBGN_EXTERN
void
SbgnCallout_free(SbgnCallout_t* sc)
{
  if (sc != NULL)
  {
    delete sc;
  }
}


/*
 * Returns the value of the "target" attribute of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
char *
SbgnCallout_getTarget(const SbgnCallout_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return sc->getTarget().empty() ? NULL : safe_strdup(sc->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnCallout_t's "target" attribute
 * is set.
 */
LIBSBGN_EXTERN
int
SbgnCallout_isSetTarget(const SbgnCallout_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetTarget()) : 0;
}


/*
 * Sets the value of the "target" attribute of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
int
SbgnCallout_setTarget(SbgnCallout_t * sc, const char * target)
{
  return (sc != NULL) ? sc->setTarget(target) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
int
SbgnCallout_unsetTarget(SbgnCallout_t * sc)
{
  return (sc != NULL) ? sc->unsetTarget() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "point" element of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnCallout_getPoint(const SbgnCallout_t * sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sc->getPoint());
}


/*
 * Predicate returning @c 1 (true) if this SbgnCallout_t's "point" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnCallout_isSetPoint(const SbgnCallout_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->isSetPoint()) : 0;
}


/*
 * Sets the value of the "point" element of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
int
SbgnCallout_setPoint(SbgnCallout_t * sc, const SbgnPoint_t* point)
{
  return (sc != NULL) ? sc->setPoint(point) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new SbgnPoint_t object, adds it to this SbgnCallout_t object and
 * returns the SbgnPoint_t object created.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnCallout_createPoint(SbgnCallout_t* sc)
{
  if (sc == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sc->createPoint());
}


/*
 * Unsets the value of the "point" element of this SbgnCallout_t.
 */
LIBSBGN_EXTERN
int
SbgnCallout_unsetPoint(SbgnCallout_t * sc)
{
  return (sc != NULL) ? sc->unsetPoint() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnCallout_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnCallout_hasRequiredAttributes(const SbgnCallout_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnCallout_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnCallout_hasRequiredElements(const SbgnCallout_t * sc)
{
  return (sc != NULL) ? static_cast<int>(sc->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



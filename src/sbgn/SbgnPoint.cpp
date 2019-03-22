/**
 * @file SbgnPoint.cpp
 * @brief Implementation of the SbgnPoint class.
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
#include <sbgn/SbgnPoint.h>
#include <sbgn/SbgnListOfPoints.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnPoint using the given SBGN Level and @ p version values.
 */
SbgnPoint::SbgnPoint(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mPoints (new SbgnListOfPoints (level, version))
  , mElementName("point")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnPoint using the given SbgnNamespaces object @p sbgnns.
 */
SbgnPoint::SbgnPoint(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mPoints (new SbgnListOfPoints (sbgnns))
  , mElementName("point")
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnPoint.
 */
SbgnPoint::SbgnPoint(const SbgnPoint& orig)
  : SbgnBase( orig )
  , mX ( orig.mX )
  , mIsSetX ( orig.mIsSetX )
  , mY ( orig.mY )
  , mIsSetY ( orig.mIsSetY )
  , mPoints ( NULL )
  , mElementName ( orig.mElementName )
{
  if (orig.mPoints != NULL)
  {
    mPoints = orig.mPoints->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnPoint.
 */
SbgnPoint&
SbgnPoint::operator=(const SbgnPoint& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mX = rhs.mX;
    mIsSetX = rhs.mIsSetX;
    mY = rhs.mY;
    mIsSetY = rhs.mIsSetY;
    mElementName = rhs.mElementName;
    delete mPoints;
    if (rhs.mPoints != NULL)
    {
      mPoints = rhs.mPoints->clone();
    }
    else
    {
      mPoints = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnPoint object.
 */
SbgnPoint*
SbgnPoint::clone() const
{
  return new SbgnPoint(*this);
}


/*
 * Destructor for SbgnPoint.
 */
SbgnPoint::~SbgnPoint()
{
  delete mPoints;
  mPoints = NULL;
}


/*
 * Returns the value of the "x" attribute of this SbgnPoint.
 */
double
SbgnPoint::getX() const
{
  return mX;
}


/*
 * Returns the value of the "y" attribute of this SbgnPoint.
 */
double
SbgnPoint::getY() const
{
  return mY;
}


/*
 * Predicate returning @c true if this SbgnPoint's "x" attribute is set.
 */
bool
SbgnPoint::isSetX() const
{
  return mIsSetX;
}


/*
 * Predicate returning @c true if this SbgnPoint's "y" attribute is set.
 */
bool
SbgnPoint::isSetY() const
{
  return mIsSetY;
}


/*
 * Sets the value of the "x" attribute of this SbgnPoint.
 */
int
SbgnPoint::setX(double x)
{
  mX = x;
  mIsSetX = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "y" attribute of this SbgnPoint.
 */
int
SbgnPoint::setY(double y)
{
  mY = y;
  mIsSetY = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "x" attribute of this SbgnPoint.
 */
int
SbgnPoint::unsetX()
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
 * Unsets the value of the "y" attribute of this SbgnPoint.
 */
int
SbgnPoint::unsetY()
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
 * Returns the SbgnListOfPoints * from this SbgnPoint.
 */
const SbgnListOfPoints *
SbgnPoint::getListOfPoints() const
{
  return mPoints;
}


/*
 * Returns the SbgnListOfPoints * from this SbgnPoint.
 */
SbgnListOfPoints *
SbgnPoint::getListOfPoints()
{
  return mPoints;
}


/*
 * Get a SbgnPoint from the SbgnPoint.
 */
SbgnPoint*
SbgnPoint::getPoint(unsigned int n)
{
  return mPoints->get(n);
}


/*
 * Get a SbgnPoint from the SbgnPoint.
 */
const SbgnPoint*
SbgnPoint::getPoint(unsigned int n) const
{
  return mPoints->get(n);
}


/*
 * Adds a copy of the given SbgnPoint to this SbgnPoint.
 */
int
SbgnPoint::addPoint(const SbgnPoint* sp1)
{
  if (sp1 == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sp1->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sp1->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp1->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sp1)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mPoints->append(sp1);
  }
}


/*
 * Get the number of SbgnPoint objects in this SbgnPoint.
 */
unsigned int
SbgnPoint::getNumPoints() const
{
  return mPoints->size();
}


/*
 * Creates a new SbgnPoint object, adds it to this SbgnPoint object and returns
 * the SbgnPoint object created.
 */
SbgnPoint*
SbgnPoint::createPoint()
{
  SbgnPoint* sp1 = NULL;

  try
  {
    sp1 = new SbgnPoint(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sp1 != NULL)
  {
    mPoints->appendAndOwn(sp1);
  }

  return sp1;
}


/*
 * Removes the nth SbgnPoint from this SbgnPoint and returns a pointer to it.
 */
SbgnPoint*
SbgnPoint::removePoint(unsigned int n)
{
  return mPoints->remove(n);
}


/*
 * Returns the XML element name of this SbgnPoint object.
 */
const std::string&
SbgnPoint::getElementName() const
{
  return mElementName;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the XML name of this SbgnPoint object.
 */
void
SbgnPoint::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBGN type code for this SbgnPoint object.
 */
int
SbgnPoint::getTypeCode() const
{
  return SBGN_SBGNML_POINT;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnPoint object have been set.
 */
bool
SbgnPoint::hasRequiredAttributes() const
{
  bool allPresent = true;

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
SbgnPoint::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  for (unsigned int i = 0; i < getNumPoints(); i++)
  {
    getPoint(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnPoint::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnPoint::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  mPoints->setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnPoint::connectToChild()
{
  SbgnBase::connectToChild();

  mPoints->connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::getAttribute(const std::string& attributeName, double& value) const
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
 * Gets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnPoint's attribute "attributeName" is
 * set.
 */
bool
SbgnPoint::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "x")
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
 * Sets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::setAttribute(const std::string& attributeName, double value)
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
 * Sets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnPoint.
 */
int
SbgnPoint::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "x")
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
 * Creates and returns an new "elementName" object in this SbgnPoint.
 */
SbgnBase*
SbgnPoint::createChildObject(const std::string& elementName)
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
 * Adds a new "elementName" object to this SbgnPoint.
 */
int
SbgnPoint::addChildObject(const std::string& elementName,
                          const SbgnBase* element)
{
  if (elementName == "point" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return addPoint((const SbgnPoint*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnPoint.
 */
SbgnBase*
SbgnPoint::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "point")
  {
    for (unsigned int i = 0; i < getNumPoints(); i++)
    {
      if (getPoint(i)->getId() == id)
      {
        return removePoint(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnPoint.
 */
unsigned int
SbgnPoint::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "point")
  {
    return getNumPoints();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnPoint.
 */
SbgnBase*
SbgnPoint::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "point")
  {
    return getPoint(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnPoint::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  obj = mPoints->getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SbgnBase*
SbgnPoint::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "point")
  {
    obj = mPoints->createObject(stream);
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
SbgnPoint::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("x");

  attributes.add("y");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnPoint::readAttributes(
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
    static_cast<SbgnListOfPoints*>(getParentSbgnObject())->size() < 2)
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
        log->logError(SbgnmlPointAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
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
      std::string message = "Sbgnml attribute 'x' from the <SbgnPoint> element "
        "must be an integer.";
      log->logError(SbgnmlPointXMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'x' is missing from the "
        "<SbgnPoint> element.";
      log->logError(SbgnmlPointAllowedAttributes, level, version, message);
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
      std::string message = "Sbgnml attribute 'y' from the <SbgnPoint> element "
        "must be an integer.";
      log->logError(SbgnmlPointYMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'y' is missing from the "
        "<SbgnPoint> element.";
      log->logError(SbgnmlPointAllowedAttributes, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnPoint::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

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
 * Creates a new SbgnPoint_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnPoint_t *
SbgnPoint_create(unsigned int level, unsigned int version)
{
  return new SbgnPoint(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnPoint_t object.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_clone(const SbgnPoint_t* sp)
{
  if (sp != NULL)
  {
    return static_cast<SbgnPoint_t*>(sp->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnPoint_t object.
 */
LIBSBGN_EXTERN
void
SbgnPoint_free(SbgnPoint_t* sp)
{
  if (sp != NULL)
  {
    delete sp;
  }
}


/*
 * Returns the value of the "x" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
double
SbgnPoint_getX(const SbgnPoint_t * sp)
{
  return (sp != NULL) ? sp->getX() : util_NaN();
}


/*
 * Returns the value of the "y" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
double
SbgnPoint_getY(const SbgnPoint_t * sp)
{
  return (sp != NULL) ? sp->getY() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SbgnPoint_t's "x" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnPoint_isSetX(const SbgnPoint_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnPoint_t's "y" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnPoint_isSetY(const SbgnPoint_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->isSetY()) : 0;
}


/*
 * Sets the value of the "x" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
int
SbgnPoint_setX(SbgnPoint_t * sp, double x)
{
  return (sp != NULL) ? sp->setX(x) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "y" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
int
SbgnPoint_setY(SbgnPoint_t * sp, double y)
{
  return (sp != NULL) ? sp->setY(y) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "x" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
int
SbgnPoint_unsetX(SbgnPoint_t * sp)
{
  return (sp != NULL) ? sp->unsetX() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "y" attribute of this SbgnPoint_t.
 */
LIBSBGN_EXTERN
int
SbgnPoint_unsetY(SbgnPoint_t * sp)
{
  return (sp != NULL) ? sp->unsetY() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SbgnPoint_t objects from this SbgnPoint_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnPoint_getListOfPoints(SbgnPoint_t* sp)
{
  return (sp != NULL) ? sp->getListOfPoints() : NULL;
}


/*
 * Get a SbgnPoint_t from the SbgnPoint_t.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_getPoint(SbgnPoint_t* sp, unsigned int n)
{
  return (sp != NULL) ? sp->getPoint(n) : NULL;
}


/*
 * Adds a copy of the given SbgnPoint_t to this SbgnPoint_t.
 */
LIBSBGN_EXTERN
int
SbgnPoint_addPoint(SbgnPoint_t* sp, const SbgnPoint_t* sp1)
{
  return (sp != NULL) ? sp->addPoint(sp1) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnPoint_t objects in this SbgnPoint_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnPoint_getNumPoints(SbgnPoint_t* sp)
{
  return (sp != NULL) ? sp->getNumPoints() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnPoint_t object, adds it to this SbgnPoint_t object and
 * returns the SbgnPoint_t object created.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_createPoint(SbgnPoint_t* sp)
{
  return (sp != NULL) ? sp->createPoint() : NULL;
}


/*
 * Removes the nth SbgnPoint_t from this SbgnPoint_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnPoint_removePoint(SbgnPoint_t* sp, unsigned int n)
{
  return (sp != NULL) ? sp->removePoint(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnPoint_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnPoint_hasRequiredAttributes(const SbgnPoint_t * sp)
{
  return (sp != NULL) ? static_cast<int>(sp->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



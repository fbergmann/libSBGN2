/**
 * @file SbgnBBox.cpp
 * @brief Implementation of the SbgnBBox class.
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
#include <sbgn/SbgnBBox.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnBBox using the given SBGN Level and @ p version values.
 */
SbgnBBox::SbgnBBox(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mWidth (util_NaN())
  , mIsSetWidth (false)
  , mHeight (util_NaN())
  , mIsSetHeight (false)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnBBox using the given SbgnNamespaces object @p sbgnns.
 */
SbgnBBox::SbgnBBox(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mX (util_NaN())
  , mIsSetX (false)
  , mY (util_NaN())
  , mIsSetY (false)
  , mWidth (util_NaN())
  , mIsSetWidth (false)
  , mHeight (util_NaN())
  , mIsSetHeight (false)
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnBBox.
 */
SbgnBBox::SbgnBBox(const SbgnBBox& orig)
  : SbgnBase( orig )
  , mX ( orig.mX )
  , mIsSetX ( orig.mIsSetX )
  , mY ( orig.mY )
  , mIsSetY ( orig.mIsSetY )
  , mWidth ( orig.mWidth )
  , mIsSetWidth ( orig.mIsSetWidth )
  , mHeight ( orig.mHeight )
  , mIsSetHeight ( orig.mIsSetHeight )
{
}


/*
 * Assignment operator for SbgnBBox.
 */
SbgnBBox&
SbgnBBox::operator=(const SbgnBBox& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mX = rhs.mX;
    mIsSetX = rhs.mIsSetX;
    mY = rhs.mY;
    mIsSetY = rhs.mIsSetY;
    mWidth = rhs.mWidth;
    mIsSetWidth = rhs.mIsSetWidth;
    mHeight = rhs.mHeight;
    mIsSetHeight = rhs.mIsSetHeight;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnBBox object.
 */
SbgnBBox*
SbgnBBox::clone() const
{
  return new SbgnBBox(*this);
}


/*
 * Destructor for SbgnBBox.
 */
SbgnBBox::~SbgnBBox()
{
}


/*
 * Returns the value of the "x" attribute of this SbgnBBox.
 */
double
SbgnBBox::getX() const
{
  return mX;
}


/*
 * Returns the value of the "y" attribute of this SbgnBBox.
 */
double
SbgnBBox::getY() const
{
  return mY;
}


/*
 * Returns the value of the "w" attribute of this SbgnBBox.
 */
double
SbgnBBox::getWidth() const
{
  return mWidth;
}


/*
 * Returns the value of the "h" attribute of this SbgnBBox.
 */
double
SbgnBBox::getHeight() const
{
  return mHeight;
}


/*
 * Predicate returning @c true if this SbgnBBox's "x" attribute is set.
 */
bool
SbgnBBox::isSetX() const
{
  return mIsSetX;
}


/*
 * Predicate returning @c true if this SbgnBBox's "y" attribute is set.
 */
bool
SbgnBBox::isSetY() const
{
  return mIsSetY;
}


/*
 * Predicate returning @c true if this SbgnBBox's "w" attribute is set.
 */
bool
SbgnBBox::isSetWidth() const
{
  return mIsSetWidth;
}


/*
 * Predicate returning @c true if this SbgnBBox's "h" attribute is set.
 */
bool
SbgnBBox::isSetHeight() const
{
  return mIsSetHeight;
}


/*
 * Sets the value of the "x" attribute of this SbgnBBox.
 */
int
SbgnBBox::setX(double x)
{
  mX = x;
  mIsSetX = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "y" attribute of this SbgnBBox.
 */
int
SbgnBBox::setY(double y)
{
  mY = y;
  mIsSetY = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "w" attribute of this SbgnBBox.
 */
int
SbgnBBox::setWidth(double width)
{
  mWidth = width;
  mIsSetWidth = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "h" attribute of this SbgnBBox.
 */
int
SbgnBBox::setHeight(double height)
{
  mHeight = height;
  mIsSetHeight = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "x" attribute of this SbgnBBox.
 */
int
SbgnBBox::unsetX()
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
 * Unsets the value of the "y" attribute of this SbgnBBox.
 */
int
SbgnBBox::unsetY()
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
 * Unsets the value of the "w" attribute of this SbgnBBox.
 */
int
SbgnBBox::unsetWidth()
{
  mWidth = util_NaN();
  mIsSetWidth = false;

  if (isSetWidth() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "h" attribute of this SbgnBBox.
 */
int
SbgnBBox::unsetHeight()
{
  mHeight = util_NaN();
  mIsSetHeight = false;

  if (isSetHeight() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SbgnBBox object.
 */
const std::string&
SbgnBBox::getElementName() const
{
  static const string name = "bbox";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnBBox object.
 */
int
SbgnBBox::getTypeCode() const
{
  return SBGN_SBGNML_BBOX;
}


/*
 * Predicate returning @c true if all the required attributes for this SbgnBBox
 * object have been set.
 */
bool
SbgnBBox::hasRequiredAttributes() const
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

  if (isSetWidth() == false)
  {
    allPresent = false;
  }

  if (isSetHeight() == false)
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
SbgnBBox::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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
SbgnBBox::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnBBox::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::getAttribute(const std::string& attributeName, double& value) const
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
  else if (attributeName == "w")
  {
    value = getWidth();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "h")
  {
    value = getHeight();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::getAttribute(const std::string& attributeName,
                       unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::getAttribute(const std::string& attributeName,
                       std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnBBox's attribute "attributeName" is
 * set.
 */
bool
SbgnBBox::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "w")
  {
    value = isSetWidth();
  }
  else if (attributeName == "h")
  {
    value = isSetHeight();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::setAttribute(const std::string& attributeName, double value)
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
  else if (attributeName == "w")
  {
    return_value = setWidth(value);
  }
  else if (attributeName == "h")
  {
    return_value = setHeight(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::setAttribute(const std::string& attributeName,
                       const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnBBox.
 */
int
SbgnBBox::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "w")
  {
    value = unsetWidth();
  }
  else if (attributeName == "h")
  {
    value = unsetHeight();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
SbgnBBox::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("x");

  attributes.add("y");

  attributes.add("w");

  attributes.add("h");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnBBox::readAttributes(
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
        log->logError(SbgnmlBBoxAllowedAttributes, level, version, details,
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
      std::string message = "Sbgnml attribute 'x' from the <SbgnBBox> element "
        "must be an integer.";
      log->logError(SbgnmlBBoxXMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'x' is missing from the "
        "<SbgnBBox> element.";
      log->logError(SbgnmlBBoxAllowedAttributes, level, version, message);
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
      std::string message = "Sbgnml attribute 'y' from the <SbgnBBox> element "
        "must be an integer.";
      log->logError(SbgnmlBBoxYMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'y' is missing from the "
        "<SbgnBBox> element.";
      log->logError(SbgnmlBBoxAllowedAttributes, level, version, message);
    }
  }

  // 
  // w double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetWidth = attributes.readInto("w", mWidth);

  if ( mIsSetWidth == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'w' from the <SbgnBBox> element "
        "must be an integer.";
      log->logError(SbgnmlBBoxWidthMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'w' is missing from the "
        "<SbgnBBox> element.";
      log->logError(SbgnmlBBoxAllowedAttributes, level, version, message);
    }
  }

  // 
  // h double (use = "required" )
  // 

  numErrs = log->getNumErrors();
  mIsSetHeight = attributes.readInto("h", mHeight);

  if ( mIsSetHeight == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'h' from the <SbgnBBox> element "
        "must be an integer.";
      log->logError(SbgnmlBBoxHeightMustBeDouble, level, version, message);
    }
    else
    {
      std::string message = "Sbgnml attribute 'h' is missing from the "
        "<SbgnBBox> element.";
      log->logError(SbgnmlBBoxAllowedAttributes, level, version, message);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnBBox::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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

  if (isSetWidth() == true)
  {
    stream.writeAttribute("w", getPrefix(), mWidth);
  }

  if (isSetHeight() == true)
  {
    stream.writeAttribute("h", getPrefix(), mHeight);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnBBox_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnBBox_t *
SbgnBBox_create(unsigned int level, unsigned int version)
{
  return new SbgnBBox(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnBBox_t object.
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnBBox_clone(const SbgnBBox_t* sbb)
{
  if (sbb != NULL)
  {
    return static_cast<SbgnBBox_t*>(sbb->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnBBox_t object.
 */
LIBSBGN_EXTERN
void
SbgnBBox_free(SbgnBBox_t* sbb)
{
  if (sbb != NULL)
  {
    delete sbb;
  }
}


/*
 * Returns the value of the "x" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
double
SbgnBBox_getX(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->getX() : util_NaN();
}


/*
 * Returns the value of the "y" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
double
SbgnBBox_getY(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->getY() : util_NaN();
}


/*
 * Returns the value of the "w" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
double
SbgnBBox_getWidth(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->getWidth() : util_NaN();
}


/*
 * Returns the value of the "h" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
double
SbgnBBox_getHeight(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->getHeight() : util_NaN();
}


/*
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "x" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetX(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? static_cast<int>(sbb->isSetX()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "y" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetY(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? static_cast<int>(sbb->isSetY()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "w" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetWidth(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? static_cast<int>(sbb->isSetWidth()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnBBox_t's "h" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnBBox_isSetHeight(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? static_cast<int>(sbb->isSetHeight()) : 0;
}


/*
 * Sets the value of the "x" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_setX(SbgnBBox_t * sbb, double x)
{
  return (sbb != NULL) ? sbb->setX(x) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "y" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_setY(SbgnBBox_t * sbb, double y)
{
  return (sbb != NULL) ? sbb->setY(y) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "w" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_setWidth(SbgnBBox_t * sbb, double width)
{
  return (sbb != NULL) ? sbb->setWidth(width) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "h" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_setHeight(SbgnBBox_t * sbb, double height)
{
  return (sbb != NULL) ? sbb->setHeight(height) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "x" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetX(SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->unsetX() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "y" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetY(SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->unsetY() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "w" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetWidth(SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->unsetWidth() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "h" attribute of this SbgnBBox_t.
 */
LIBSBGN_EXTERN
int
SbgnBBox_unsetHeight(SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? sbb->unsetHeight() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnBBox_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnBBox_hasRequiredAttributes(const SbgnBBox_t * sbb)
{
  return (sbb != NULL) ? static_cast<int>(sbb->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



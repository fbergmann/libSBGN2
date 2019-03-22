/**
 * @file SbgnLabel.cpp
 * @brief Implementation of the SbgnLabel class.
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
#include <sbgn/SbgnLabel.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnLabel using the given SBGN Level and @ p version values.
 */
SbgnLabel::SbgnLabel(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mText ("")
  , mBBox (NULL)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnLabel using the given SbgnNamespaces object @p sbgnns.
 */
SbgnLabel::SbgnLabel(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mText ("")
  , mBBox (NULL)
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnLabel.
 */
SbgnLabel::SbgnLabel(const SbgnLabel& orig)
  : SbgnBase( orig )
  , mText ( orig.mText )
  , mBBox ( NULL )
{
  if (orig.mBBox != NULL)
  {
    mBBox = orig.mBBox->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnLabel.
 */
SbgnLabel&
SbgnLabel::operator=(const SbgnLabel& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mText = rhs.mText;
    delete mBBox;
    if (rhs.mBBox != NULL)
    {
      mBBox = rhs.mBBox->clone();
    }
    else
    {
      mBBox = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnLabel object.
 */
SbgnLabel*
SbgnLabel::clone() const
{
  return new SbgnLabel(*this);
}


/*
 * Destructor for SbgnLabel.
 */
SbgnLabel::~SbgnLabel()
{
  delete mBBox;
  mBBox = NULL;
}


/*
 * Returns the value of the "id" attribute of this SbgnLabel.
 */
const std::string&
SbgnLabel::getId() const
{
  return mId;
}


/*
 * Returns the value of the "text" attribute of this SbgnLabel.
 */
const std::string&
SbgnLabel::getText() const
{
  return mText;
}


/*
 * Predicate returning @c true if this SbgnLabel's "id" attribute is set.
 */
bool
SbgnLabel::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnLabel's "text" attribute is set.
 */
bool
SbgnLabel::isSetText() const
{
  return (mText.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SbgnLabel.
 */
int
SbgnLabel::setId(const std::string& id)
{
  mId = id;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "text" attribute of this SbgnLabel.
 */
int
SbgnLabel::setText(const std::string& text)
{
  mText = text;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SbgnLabel.
 */
int
SbgnLabel::unsetId()
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
 * Unsets the value of the "text" attribute of this SbgnLabel.
 */
int
SbgnLabel::unsetText()
{
  mText.erase();

  if (mText.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "bbox" element of this SbgnLabel.
 */
const SbgnBBox*
SbgnLabel::getBBox() const
{
  return mBBox;
}


/*
 * Returns the value of the "bbox" element of this SbgnLabel.
 */
SbgnBBox*
SbgnLabel::getBBox()
{
  return mBBox;
}


/*
 * Predicate returning @c true if this SbgnLabel's "bbox" element is set.
 */
bool
SbgnLabel::isSetBBox() const
{
  return (mBBox != NULL);
}


/*
 * Sets the value of the "bbox" element of this SbgnLabel.
 */
int
SbgnLabel::setBBox(const SbgnBBox* bbox)
{
  if (mBBox == bbox)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (bbox == NULL)
  {
    delete mBBox;
    mBBox = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mBBox;
    mBBox = (bbox != NULL) ? bbox->clone() : NULL;
    if (mBBox != NULL)
    {
      mBBox->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SbgnBBox object, adds it to this SbgnLabel object and returns
 * the SbgnBBox object created.
 */
SbgnBBox*
SbgnLabel::createBBox()
{
  if (mBBox != NULL)
  {
    delete mBBox;
  }

  mBBox = new SbgnBBox(getSbgnNamespaces());

  connectToChild();

  return mBBox;
}


/*
 * Unsets the value of the "bbox" element of this SbgnLabel.
 */
int
SbgnLabel::unsetBBox()
{
  delete mBBox;
  mBBox = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the XML element name of this SbgnLabel object.
 */
const std::string&
SbgnLabel::getElementName() const
{
  static const string name = "label";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnLabel object.
 */
int
SbgnLabel::getTypeCode() const
{
  return SBGN_SBGNML_LABEL;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnLabel object have been set.
 */
bool
SbgnLabel::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetText() == false)
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
SbgnLabel::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  if (isSetBBox() == true)
  {
    mBBox->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnLabel::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnLabel::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  if (mBBox != NULL)
  {
    mBBox->setSbgnDocument(d);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnLabel::connectToChild()
{
  SbgnBase::connectToChild();

  if (mBBox != NULL)
  {
    mBBox->connectToParent(this);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "text")
  {
    value = getText();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnLabel's attribute "attributeName" is
 * set.
 */
bool
SbgnLabel::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "text")
  {
    value = isSetText();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "text")
  {
    return_value = setText(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnLabel.
 */
int
SbgnLabel::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "text")
  {
    value = unsetText();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnLabel.
 */
SbgnBase*
SbgnLabel::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return createBBox();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnLabel.
 */
int
SbgnLabel::addChildObject(const std::string& elementName,
                          const SbgnBase* element)
{
  if (elementName == "bbox" && element->getTypeCode() == SBGN_SBGNML_BBOX)
  {
    return setBBox((const SbgnBBox*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnLabel.
 */
SbgnBase*
SbgnLabel::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "bbox")
  {
    SbgnBBox * obj = getBBox();
    if (unsetBBox() == LIBSBML_OPERATION_SUCCESS) return obj;
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnLabel.
 */
unsigned int
SbgnLabel::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bbox")
  {
    if (isSetBBox())
    {
      return 1;
    }
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnLabel.
 */
SbgnBase*
SbgnLabel::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return getBBox();
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnLabel::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mBBox != NULL)
  {
    if (mBBox->getId() == id)
    {
      return mBBox;
    }

    obj = mBBox->getElementBySId(id);
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
SbgnLabel::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "bbox")
  {
    if (isSetBBox())
    {
      getErrorLog()->logError(SbgnmlLabelAllowedElements, getLevel(),
        getVersion());
    }

    delete mBBox;
    mBBox = new SbgnBBox(getSbgnNamespaces());
    obj = mBBox;
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
SbgnLabel::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("text");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnLabel::readAttributes(
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
        log->logError(SbgnmlLabelAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // id SId (use = "optional" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SbgnLabel>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SbgnmlIdSyntaxRule, level, version, "The id on the <" +
        getElementName() + "> is '" + mId + "', which does not conform to the "
          "syntax.");
    }
  }

  // 
  // text string (use = "required" )
  // 

  assigned = attributes.readInto("text", mText);

  if (assigned == true)
  {
    if (mText.empty() == true)
    {
      logEmptyString(mText, level, version, "<SbgnLabel>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'text' is missing from the "
      "<SbgnLabel> element.";
    log->logError(SbgnmlLabelAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnLabel::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetText() == true)
  {
    stream.writeAttribute("text", getPrefix(), mText);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnLabel_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnLabel_t *
SbgnLabel_create(unsigned int level, unsigned int version)
{
  return new SbgnLabel(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnLabel_t object.
 */
LIBSBGN_EXTERN
SbgnLabel_t*
SbgnLabel_clone(const SbgnLabel_t* sl)
{
  if (sl != NULL)
  {
    return static_cast<SbgnLabel_t*>(sl->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnLabel_t object.
 */
LIBSBGN_EXTERN
void
SbgnLabel_free(SbgnLabel_t* sl)
{
  if (sl != NULL)
  {
    delete sl;
  }
}


/*
 * Returns the value of the "id" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
char *
SbgnLabel_getId(const SbgnLabel_t * sl)
{
  if (sl == NULL)
  {
    return NULL;
  }

  return sl->getId().empty() ? NULL : safe_strdup(sl->getId().c_str());
}


/*
 * Returns the value of the "text" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
char *
SbgnLabel_getText(const SbgnLabel_t * sl)
{
  if (sl == NULL)
  {
    return NULL;
  }

  return sl->getText().empty() ? NULL : safe_strdup(sl->getText().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetId(const SbgnLabel_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "text" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetText(const SbgnLabel_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetText()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_setId(SbgnLabel_t * sl, const char * id)
{
  return (sl != NULL) ? sl->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "text" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_setText(SbgnLabel_t * sl, const char * text)
{
  return (sl != NULL) ? sl->setText(text) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetId(SbgnLabel_t * sl)
{
  return (sl != NULL) ? sl->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "text" attribute of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetText(SbgnLabel_t * sl)
{
  return (sl != NULL) ? sl->unsetText() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "bbox" element of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnLabel_getBBox(const SbgnLabel_t * sl)
{
  if (sl == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sl->getBBox());
}


/*
 * Predicate returning @c 1 (true) if this SbgnLabel_t's "bbox" element is set.
 */
LIBSBGN_EXTERN
int
SbgnLabel_isSetBBox(const SbgnLabel_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->isSetBBox()) : 0;
}


/*
 * Sets the value of the "bbox" element of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_setBBox(SbgnLabel_t * sl, const SbgnBBox_t* bbox)
{
  return (sl != NULL) ? sl->setBBox(bbox) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new SbgnBBox_t object, adds it to this SbgnLabel_t object and
 * returns the SbgnBBox_t object created.
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnLabel_createBBox(SbgnLabel_t* sl)
{
  if (sl == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sl->createBBox());
}


/*
 * Unsets the value of the "bbox" element of this SbgnLabel_t.
 */
LIBSBGN_EXTERN
int
SbgnLabel_unsetBBox(SbgnLabel_t * sl)
{
  return (sl != NULL) ? sl->unsetBBox() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnLabel_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnLabel_hasRequiredAttributes(const SbgnLabel_t * sl)
{
  return (sl != NULL) ? static_cast<int>(sl->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



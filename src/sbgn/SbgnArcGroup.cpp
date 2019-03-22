/**
 * @file SbgnArcGroup.cpp
 * @brief Implementation of the SbgnArcGroup class.
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
#include <sbgn/SbgnArcGroup.h>
#include <sbgn/SbgnListOfArcGroups.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnArcGroup using the given SBGN Level and @ p version
 * values.
 */
SbgnArcGroup::SbgnArcGroup(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mGlyphs (level, version)
  , mArcs (level, version)
  , mClazz ("")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnArcGroup using the given SbgnNamespaces object @p sbgnns.
 */
SbgnArcGroup::SbgnArcGroup(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mGlyphs (sbgnns)
  , mArcs (sbgnns)
  , mClazz ("")
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnArcGroup.
 */
SbgnArcGroup::SbgnArcGroup(const SbgnArcGroup& orig)
  : SbgnBase( orig )
  , mGlyphs ( orig.mGlyphs )
  , mArcs ( orig.mArcs )
  , mClazz ( orig.mClazz )
{
  connectToChild();
}


/*
 * Assignment operator for SbgnArcGroup.
 */
SbgnArcGroup&
SbgnArcGroup::operator=(const SbgnArcGroup& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mGlyphs = rhs.mGlyphs;
    mArcs = rhs.mArcs;
    mClazz = rhs.mClazz;
    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnArcGroup object.
 */
SbgnArcGroup*
SbgnArcGroup::clone() const
{
  return new SbgnArcGroup(*this);
}


/*
 * Destructor for SbgnArcGroup.
 */
SbgnArcGroup::~SbgnArcGroup()
{
}


/*
 * Returns the value of the "class" attribute of this SbgnArcGroup.
 */
const std::string&
SbgnArcGroup::getClazz() const
{
  return mClazz;
}


/*
 * Predicate returning @c true if this SbgnArcGroup's "class" attribute is set.
 */
bool
SbgnArcGroup::isSetClazz() const
{
  return (mClazz.empty() == false);
}


/*
 * Sets the value of the "class" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setClazz(const std::string& clazz)
{
  mClazz = clazz;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "class" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::unsetClazz()
{
  mClazz.erase();

  if (mClazz.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnArcGroup.
 */
const SbgnListOfGlyphs*
SbgnArcGroup::getListOfGlyphs() const
{
  return &mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnArcGroup.
 */
SbgnListOfGlyphs*
SbgnArcGroup::getListOfGlyphs()
{
  return &mGlyphs;
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup.
 */
SbgnGlyph*
SbgnArcGroup::getGlyph(unsigned int n)
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup.
 */
const SbgnGlyph*
SbgnArcGroup::getGlyph(unsigned int n) const
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on its identifier.
 */
SbgnGlyph*
SbgnArcGroup::getGlyph(const std::string& sid)
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on its identifier.
 */
const SbgnGlyph*
SbgnArcGroup::getGlyph(const std::string& sid) const
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the CompartmentRef to which
 * it refers.
 */
const SbgnGlyph*
SbgnArcGroup::getGlyphByCompartmentRef(const std::string& sid) const
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the CompartmentRef to which
 * it refers.
 */
SbgnGlyph*
SbgnArcGroup::getGlyphByCompartmentRef(const std::string& sid)
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the MapRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnArcGroup::getGlyphByMapRef(const std::string& sid) const
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the MapRef to which it
 * refers.
 */
SbgnGlyph*
SbgnArcGroup::getGlyphByMapRef(const std::string& sid)
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the TagRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnArcGroup::getGlyphByTagRef(const std::string& sid) const
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArcGroup based on the TagRef to which it
 * refers.
 */
SbgnGlyph*
SbgnArcGroup::getGlyphByTagRef(const std::string& sid)
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Adds a copy of the given SbgnGlyph to this SbgnArcGroup.
 */
int
SbgnArcGroup::addGlyph(const SbgnGlyph* sg)
{
  if (sg == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sg->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sg->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sg->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sg)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (sg->isSetId() && (mGlyphs.get(sg->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mGlyphs.append(sg);
  }
}


/*
 * Get the number of SbgnGlyph objects in this SbgnArcGroup.
 */
unsigned int
SbgnArcGroup::getNumGlyphs() const
{
  return mGlyphs.size();
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnArcGroup object and
 * returns the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnArcGroup::createGlyph()
{
  SbgnGlyph* sg = NULL;

  try
  {
    sg = new SbgnGlyph(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sg != NULL)
  {
    mGlyphs.appendAndOwn(sg);
  }

  return sg;
}


/*
 * Removes the nth SbgnGlyph from this SbgnArcGroup and returns a pointer to
 * it.
 */
SbgnGlyph*
SbgnArcGroup::removeGlyph(unsigned int n)
{
  return mGlyphs.remove(n);
}


/*
 * Removes the SbgnGlyph from this SbgnArcGroup based on its identifier and
 * returns a pointer to it.
 */
SbgnGlyph*
SbgnArcGroup::removeGlyph(const std::string& sid)
{
  return mGlyphs.remove(sid);
}


/*
 * Returns the SbgnListOfArcs from this SbgnArcGroup.
 */
const SbgnListOfArcs*
SbgnArcGroup::getListOfArcs() const
{
  return &mArcs;
}


/*
 * Returns the SbgnListOfArcs from this SbgnArcGroup.
 */
SbgnListOfArcs*
SbgnArcGroup::getListOfArcs()
{
  return &mArcs;
}


/*
 * Get a SbgnArc from the SbgnArcGroup.
 */
SbgnArc*
SbgnArcGroup::getArc(unsigned int n)
{
  return mArcs.get(n);
}


/*
 * Get a SbgnArc from the SbgnArcGroup.
 */
const SbgnArc*
SbgnArcGroup::getArc(unsigned int n) const
{
  return mArcs.get(n);
}


/*
 * Get a SbgnArc from the SbgnArcGroup based on its identifier.
 */
SbgnArc*
SbgnArcGroup::getArc(const std::string& sid)
{
  return mArcs.get(sid);
}


/*
 * Get a SbgnArc from the SbgnArcGroup based on its identifier.
 */
const SbgnArc*
SbgnArcGroup::getArc(const std::string& sid) const
{
  return mArcs.get(sid);
}


/*
 * Adds a copy of the given SbgnArc to this SbgnArcGroup.
 */
int
SbgnArcGroup::addArc(const SbgnArc* sa)
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
  else if (sa->isSetId() && (mArcs.get(sa->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mArcs.append(sa);
  }
}


/*
 * Get the number of SbgnArc objects in this SbgnArcGroup.
 */
unsigned int
SbgnArcGroup::getNumArcs() const
{
  return mArcs.size();
}


/*
 * Creates a new SbgnArc object, adds it to this SbgnArcGroup object and
 * returns the SbgnArc object created.
 */
SbgnArc*
SbgnArcGroup::createArc()
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
    mArcs.appendAndOwn(sa);
  }

  return sa;
}


/*
 * Removes the nth SbgnArc from this SbgnArcGroup and returns a pointer to it.
 */
SbgnArc*
SbgnArcGroup::removeArc(unsigned int n)
{
  return mArcs.remove(n);
}


/*
 * Removes the SbgnArc from this SbgnArcGroup based on its identifier and
 * returns a pointer to it.
 */
SbgnArc*
SbgnArcGroup::removeArc(const std::string& sid)
{
  return mArcs.remove(sid);
}


/*
 * Returns the XML element name of this SbgnArcGroup object.
 */
const std::string&
SbgnArcGroup::getElementName() const
{
  static const string name = "arcgroup";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnArcGroup object.
 */
int
SbgnArcGroup::getTypeCode() const
{
  return SBGN_SBGNML_ARCGROUP;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnArcGroup object have been set.
 */
bool
SbgnArcGroup::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
SbgnArcGroup::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumArcs(); i++)
  {
    getArc(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnArcGroup::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnArcGroup::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  mGlyphs.setSbgnDocument(d);

  mArcs.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnArcGroup::connectToChild()
{
  SbgnBase::connectToChild();

  mGlyphs.connectToParent(this);

  mArcs.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "class")
  {
    value = getClazz();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnArcGroup's attribute "attributeName"
 * is set.
 */
bool
SbgnArcGroup::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "class")
  {
    value = isSetClazz();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "class")
  {
    return_value = setClazz(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnArcGroup.
 */
int
SbgnArcGroup::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "class")
  {
    value = unsetClazz();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnArcGroup.
 */
SbgnBase*
SbgnArcGroup::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "glyph")
  {
    return createGlyph();
  }
  else if (elementName == "arc")
  {
    return createArc();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnArcGroup.
 */
int
SbgnArcGroup::addChildObject(const std::string& elementName,
                             const SbgnBase* element)
{
  if (elementName == "glyph" && element->getTypeCode() == SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const SbgnGlyph*)(element));
  }
  else if (elementName == "arc" && element->getTypeCode() == SBGN_SBGNML_ARC)
  {
    return addArc((const SbgnArc*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnArcGroup.
 */
SbgnBase*
SbgnArcGroup::removeChildObject(const std::string& elementName,
                                const std::string& id)
{
  if (elementName == "glyph")
  {
    return removeGlyph(id);
  }
  else if (elementName == "arc")
  {
    return removeArc(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnArcGroup.
 */
unsigned int
SbgnArcGroup::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "glyph")
  {
    return getNumGlyphs();
  }
  else if (elementName == "arc")
  {
    return getNumArcs();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnArcGroup.
 */
SbgnBase*
SbgnArcGroup::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "glyph")
  {
    return getGlyph(index);
  }
  else if (elementName == "arc")
  {
    return getArc(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnArcGroup::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  obj = mGlyphs.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mArcs.getElementBySId(id);

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
SbgnArcGroup::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "glyph")
  {
    obj = mGlyphs.createObject(stream);
  }
  else if (name == "arc")
  {
    obj = mArcs.createObject(stream);
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
SbgnArcGroup::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("class");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnArcGroup::readAttributes(
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

  if (log && getParentSbgnObject() &&
    static_cast<SbgnListOfArcGroups*>(getParentSbgnObject())->size() < 2)
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
        log->logError(SbgnmlArcGroupAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // class string (use = "optional" )
  // 

  assigned = attributes.readInto("class", mClazz);

  if (assigned == true)
  {
    if (mClazz.empty() == true)
    {
      logEmptyString(mClazz, level, version, "<SbgnArcGroup>");
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnArcGroup::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetClazz() == true)
  {
    stream.writeAttribute("class", getPrefix(), mClazz);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnArcGroup_t using the given SBGN Level and @ p version
 * values.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t *
SbgnArcGroup_create(unsigned int level, unsigned int version)
{
  return new SbgnArcGroup(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnArcGroup_t object.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnArcGroup_clone(const SbgnArcGroup_t* sag)
{
  if (sag != NULL)
  {
    return static_cast<SbgnArcGroup_t*>(sag->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnArcGroup_t object.
 */
LIBSBGN_EXTERN
void
SbgnArcGroup_free(SbgnArcGroup_t* sag)
{
  if (sag != NULL)
  {
    delete sag;
  }
}


/*
 * Returns the value of the "class" attribute of this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
char *
SbgnArcGroup_getClazz(const SbgnArcGroup_t * sag)
{
  if (sag == NULL)
  {
    return NULL;
  }

  return sag->getClazz().empty() ? NULL : safe_strdup(sag->getClazz().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnArcGroup_t's "class" attribute
 * is set.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_isSetClazz(const SbgnArcGroup_t * sag)
{
  return (sag != NULL) ? static_cast<int>(sag->isSetClazz()) : 0;
}


/*
 * Sets the value of the "class" attribute of this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_setClazz(SbgnArcGroup_t * sag, const char * clazz)
{
  return (sag != NULL) ? sag->setClazz(clazz) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "class" attribute of this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_unsetClazz(SbgnArcGroup_t * sag)
{
  return (sag != NULL) ? sag->unsetClazz() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this
 * SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArcGroup_getListOfGlyphs(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->getListOfGlyphs() : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyph(SbgnArcGroup_t* sag, unsigned int n)
{
  return (sag != NULL) ? sag->getGlyph(n) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphById(SbgnArcGroup_t* sag, const char *sid)
{
  return (sag != NULL && sid != NULL) ? sag->getGlyph(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the CompartmentRef to
 * which it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByCompartmentRef(SbgnArcGroup_t* sag, const char *sid)
{
  return (sag != NULL && sid != NULL) ? sag->getGlyphByCompartmentRef(sid) :
    NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the MapRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByMapRef(SbgnArcGroup_t* sag, const char *sid)
{
  return (sag != NULL && sid != NULL) ? sag->getGlyphByMapRef(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArcGroup_t based on the TagRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_getGlyphByTagRef(SbgnArcGroup_t* sag, const char *sid)
{
  return (sag != NULL && sid != NULL) ? sag->getGlyphByTagRef(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnGlyph_t to this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_addGlyph(SbgnArcGroup_t* sag, const SbgnGlyph_t* sg)
{
  return (sag != NULL) ? sag->addGlyph(sg) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnGlyph_t objects in this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnArcGroup_getNumGlyphs(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnGlyph_t object, adds it to this SbgnArcGroup_t object and
 * returns the SbgnGlyph_t object created.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_createGlyph(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->createGlyph() : NULL;
}


/*
 * Removes the nth SbgnGlyph_t from this SbgnArcGroup_t and returns a pointer
 * to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_removeGlyph(SbgnArcGroup_t* sag, unsigned int n)
{
  return (sag != NULL) ? sag->removeGlyph(n) : NULL;
}


/*
 * Removes the SbgnGlyph_t from this SbgnArcGroup_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArcGroup_removeGlyphById(SbgnArcGroup_t* sag, const char* sid)
{
  return (sag != NULL && sid != NULL) ? sag->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnArc_t objects from this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArcGroup_getListOfArcs(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->getListOfArcs() : NULL;
}


/*
 * Get a SbgnArc_t from the SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_getArc(SbgnArcGroup_t* sag, unsigned int n)
{
  return (sag != NULL) ? sag->getArc(n) : NULL;
}


/*
 * Get a SbgnArc_t from the SbgnArcGroup_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_getArcById(SbgnArcGroup_t* sag, const char *sid)
{
  return (sag != NULL && sid != NULL) ? sag->getArc(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnArc_t to this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_addArc(SbgnArcGroup_t* sag, const SbgnArc_t* sa)
{
  return (sag != NULL) ? sag->addArc(sa) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnArc_t objects in this SbgnArcGroup_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnArcGroup_getNumArcs(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->getNumArcs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnArc_t object, adds it to this SbgnArcGroup_t object and
 * returns the SbgnArc_t object created.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_createArc(SbgnArcGroup_t* sag)
{
  return (sag != NULL) ? sag->createArc() : NULL;
}


/*
 * Removes the nth SbgnArc_t from this SbgnArcGroup_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_removeArc(SbgnArcGroup_t* sag, unsigned int n)
{
  return (sag != NULL) ? sag->removeArc(n) : NULL;
}


/*
 * Removes the SbgnArc_t from this SbgnArcGroup_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArcGroup_removeArcById(SbgnArcGroup_t* sag, const char* sid)
{
  return (sag != NULL && sid != NULL) ? sag->removeArc(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnArcGroup_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnArcGroup_hasRequiredAttributes(const SbgnArcGroup_t * sag)
{
  return (sag != NULL) ? static_cast<int>(sag->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



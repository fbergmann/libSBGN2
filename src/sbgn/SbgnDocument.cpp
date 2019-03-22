/**
 * @file SbgnDocument.cpp
 * @brief Implementation of the SbgnDocument class.
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
#include <sbgn/SbgnDocument.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnDocument using the given SBGN Level and @ p version
 * values.
 */
SbgnDocument::SbgnDocument(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mMaps (level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  setSbgnDocument(this);
  connectToChild();
}


/*
 * Creates a new SbgnDocument using the given SbgnNamespaces object @p sbgnns.
 */
SbgnDocument::SbgnDocument(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mMaps (sbgnns)
{
  setElementNamespace(sbgnns->getURI());
  setSbgnDocument(this);
  connectToChild();
}


/*
 * Copy constructor for SbgnDocument.
 */
SbgnDocument::SbgnDocument(const SbgnDocument& orig)
  : SbgnBase( orig )
  , mMaps ( orig.mMaps )
{
  setSbgnDocument(this);

  connectToChild();
}


/*
 * Assignment operator for SbgnDocument.
 */
SbgnDocument&
SbgnDocument::operator=(const SbgnDocument& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mMaps = rhs.mMaps;
    connectToChild();
    setSbgnDocument(this);
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnDocument object.
 */
SbgnDocument*
SbgnDocument::clone() const
{
  return new SbgnDocument(*this);
}


/*
 * Destructor for SbgnDocument.
 */
SbgnDocument::~SbgnDocument()
{
}


/*
 * Returns the SbgnListOfMaps from this SbgnDocument.
 */
const SbgnListOfMaps*
SbgnDocument::getListOfMaps() const
{
  return &mMaps;
}


/*
 * Returns the SbgnListOfMaps from this SbgnDocument.
 */
SbgnListOfMaps*
SbgnDocument::getListOfMaps()
{
  return &mMaps;
}


/*
 * Get a SbgnMap from the SbgnDocument.
 */
SbgnMap*
SbgnDocument::getMap(unsigned int n)
{
  return mMaps.get(n);
}


/*
 * Get a SbgnMap from the SbgnDocument.
 */
const SbgnMap*
SbgnDocument::getMap(unsigned int n) const
{
  return mMaps.get(n);
}


/*
 * Get a SbgnMap from the SbgnDocument based on its identifier.
 */
SbgnMap*
SbgnDocument::getMap(const std::string& sid)
{
  return mMaps.get(sid);
}


/*
 * Get a SbgnMap from the SbgnDocument based on its identifier.
 */
const SbgnMap*
SbgnDocument::getMap(const std::string& sid) const
{
  return mMaps.get(sid);
}


/*
 * Adds a copy of the given SbgnMap to this SbgnDocument.
 */
int
SbgnDocument::addMap(const SbgnMap* sm)
{
  if (sm == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sm->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sm->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sm->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sm)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (sm->isSetId() && (mMaps.get(sm->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mMaps.append(sm);
  }
}


/*
 * Get the number of SbgnMap objects in this SbgnDocument.
 */
unsigned int
SbgnDocument::getNumMaps() const
{
  return mMaps.size();
}


/*
 * Creates a new SbgnMap object, adds it to this SbgnDocument object and
 * returns the SbgnMap object created.
 */
SbgnMap*
SbgnDocument::createMap()
{
  SbgnMap* sm = NULL;

  try
  {
    sm = new SbgnMap(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sm != NULL)
  {
    mMaps.appendAndOwn(sm);
  }

  return sm;
}


/*
 * Removes the nth SbgnMap from this SbgnDocument and returns a pointer to it.
 */
SbgnMap*
SbgnDocument::removeMap(unsigned int n)
{
  return mMaps.remove(n);
}


/*
 * Removes the SbgnMap from this SbgnDocument based on its identifier and
 * returns a pointer to it.
 */
SbgnMap*
SbgnDocument::removeMap(const std::string& sid)
{
  return mMaps.remove(sid);
}


/*
 * Returns the XML element name of this SbgnDocument object.
 */
const std::string&
SbgnDocument::getElementName() const
{
  static const string name = "sbgn";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnDocument object.
 */
int
SbgnDocument::getTypeCode() const
{
  return SBGN_DOCUMENT;
}


/*
 * Predicate returning @c true if all the required elements for this
 * SbgnDocument object have been set.
 */
bool
SbgnDocument::hasRequiredElements() const
{
  bool allPresent = true;

  if (getNumMaps() == 0)
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
SbgnDocument::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  for (unsigned int i = 0; i < getNumMaps(); i++)
  {
    getMap(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnDocument::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnDocument::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  mMaps.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnDocument::connectToChild()
{
  SbgnBase::connectToChild();

  mMaps.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::getAttribute(const std::string& attributeName,
                           bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::getAttribute(const std::string& attributeName,
                           double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::getAttribute(const std::string& attributeName,
                           unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::getAttribute(const std::string& attributeName,
                           std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnDocument's attribute "attributeName"
 * is set.
 */
bool
SbgnDocument::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::setAttribute(const std::string& attributeName,
                           unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::setAttribute(const std::string& attributeName,
                           const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnDocument.
 */
int
SbgnDocument::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnDocument.
 */
SbgnBase*
SbgnDocument::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "map")
  {
    return createMap();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnDocument.
 */
int
SbgnDocument::addChildObject(const std::string& elementName,
                             const SbgnBase* element)
{
  if (elementName == "map" && element->getTypeCode() == SBGN_SBGNML_MAP)
  {
    return addMap((const SbgnMap*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnDocument.
 */
SbgnBase*
SbgnDocument::removeChildObject(const std::string& elementName,
                                const std::string& id)
{
  if (elementName == "map")
  {
    return removeMap(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnDocument.
 */
unsigned int
SbgnDocument::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "map")
  {
    return getNumMaps();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnDocument.
 */
SbgnBase*
SbgnDocument::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "map")
  {
    return getMap(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnDocument::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  obj = mMaps.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  return obj;
}


/*
 * Returns the value of the "Namespaces" element of this SbgnDocument.
 */
const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SbgnDocument::getNamespaces() const
{
  return mSbgnNamespaces->getNamespaces();
}


/*
 * Returns the value of the "Namespaces" element of this SbgnDocument.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SbgnDocument::getNamespaces()
{
  return mSbgnNamespaces->getNamespaces();
}


/*
 * Returns the value of the "SbgnErrorLog" element of this SbgnDocument.
 */
const SbgnErrorLog*
SbgnDocument::getErrorLog() const
{
  return &mErrorLog;
}


/*
 * Returns the value of the "SbgnErrorLog" element of this SbgnDocument.
 */
SbgnErrorLog*
SbgnDocument::getErrorLog()
{
  return &mErrorLog;
}


/*
 * Get a SbgnError from the SbgnDocument.
 */
SbgnError*
SbgnDocument::getError(unsigned int n)
{
  return const_cast<SbgnError*>(mErrorLog.getError(n));
}


/*
 * Get a SbgnError from the SbgnDocument.
 */
const SbgnError*
SbgnDocument::getError(unsigned int n) const
{
  return mErrorLog.getError(n);
}


/*
 * Get the number of SbgnError objects in this SbgnDocument.
 */
unsigned int
SbgnDocument::getNumErrors() const
{
  return mErrorLog.getNumErrors();
}


/*
 * Get the number of SbgnError objects in this SbgnDocument with the given
 * severity.
 */
unsigned int
SbgnDocument::getNumErrors(unsigned int severity) const
{
  return getErrorLog()->getNumFailsWithSeverity(severity);
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new object from the next XMLToken on the XMLInputStream
 */
SbgnBase*
SbgnDocument::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "map")
  {
    obj = mMaps.createObject(stream);
  }

  connectToChild();

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the namespace for the Sbgnml package
 */
void
SbgnDocument::writeXMLNS(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces xmlns;
  std::string prefix = getPrefix();

  if (prefix.empty())
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* thisxmlns =
      getNamespaces();
    if (thisxmlns && thisxmlns->hasURI(SBGN_XMLNS_L0V2))
    {
      xmlns.add(SBGN_XMLNS_L0V2, prefix);
    }
  }

  stream << xmlns;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnDocument_t using the given SBGN Level and @ p version
 * values.
 */
LIBSBGN_EXTERN
SbgnDocument_t *
SbgnDocument_create(unsigned int level, unsigned int version)
{
  return new SbgnDocument(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnDocument_t object.
 */
LIBSBGN_EXTERN
SbgnDocument_t*
SbgnDocument_clone(const SbgnDocument_t* sd)
{
  if (sd != NULL)
  {
    return static_cast<SbgnDocument_t*>(sd->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnDocument_t object.
 */
LIBSBGN_EXTERN
void
SbgnDocument_free(SbgnDocument_t* sd)
{
  if (sd != NULL)
  {
    delete sd;
  }
}


/*
 * Returns a ListOf_t * containing SbgnMap_t objects from this SbgnDocument_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnDocument_getListOfMaps(SbgnDocument_t* sd)
{
  return (sd != NULL) ? sd->getListOfMaps() : NULL;
}


/*
 * Get a SbgnMap_t from the SbgnDocument_t.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_getMap(SbgnDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->getMap(n) : NULL;
}


/*
 * Get a SbgnMap_t from the SbgnDocument_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_getMapById(SbgnDocument_t* sd, const char *sid)
{
  return (sd != NULL && sid != NULL) ? sd->getMap(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnMap_t to this SbgnDocument_t.
 */
LIBSBGN_EXTERN
int
SbgnDocument_addMap(SbgnDocument_t* sd, const SbgnMap_t* sm)
{
  return (sd != NULL) ? sd->addMap(sm) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnMap_t objects in this SbgnDocument_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnDocument_getNumMaps(SbgnDocument_t* sd)
{
  return (sd != NULL) ? sd->getNumMaps() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnMap_t object, adds it to this SbgnDocument_t object and
 * returns the SbgnMap_t object created.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_createMap(SbgnDocument_t* sd)
{
  return (sd != NULL) ? sd->createMap() : NULL;
}


/*
 * Removes the nth SbgnMap_t from this SbgnDocument_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_removeMap(SbgnDocument_t* sd, unsigned int n)
{
  return (sd != NULL) ? sd->removeMap(n) : NULL;
}


/*
 * Removes the SbgnMap_t from this SbgnDocument_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnDocument_removeMapById(SbgnDocument_t* sd, const char* sid)
{
  return (sd != NULL && sid != NULL) ? sd->removeMap(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnDocument_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnDocument_hasRequiredElements(const SbgnDocument_t * sd)
{
  return (sd != NULL) ? static_cast<int>(sd->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



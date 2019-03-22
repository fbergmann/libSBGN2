/**
 * @file SbgnMap.cpp
 * @brief Implementation of the SbgnMap class.
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
#include <sbgn/SbgnMap.h>
#include <sbgn/SbgnListOfMaps.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnMap using the given SBGN Level and @ p version values.
 */
SbgnMap::SbgnMap(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mLanguage (SBGNML_LANGUAGE_INVALID)
  , mBBox (NULL)
  , mGlyphs (level, version)
  , mArcs (level, version)
  , mArcGroups (level, version)
  , mMapVersion (SBGNML_MAPTYPE_INVALID)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnMap using the given SbgnNamespaces object @p sbgnns.
 */
SbgnMap::SbgnMap(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mLanguage (SBGNML_LANGUAGE_INVALID)
  , mBBox (NULL)
  , mGlyphs (sbgnns)
  , mArcs (sbgnns)
  , mArcGroups (sbgnns)
  , mMapVersion (SBGNML_MAPTYPE_INVALID)
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnMap.
 */
SbgnMap::SbgnMap(const SbgnMap& orig)
  : SbgnBase( orig )
  , mLanguage ( orig.mLanguage )
  , mBBox ( NULL )
  , mGlyphs ( orig.mGlyphs )
  , mArcs ( orig.mArcs )
  , mArcGroups ( orig.mArcGroups )
  , mMapVersion ( orig.mMapVersion )
{
  if (orig.mBBox != NULL)
  {
    mBBox = orig.mBBox->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnMap.
 */
SbgnMap&
SbgnMap::operator=(const SbgnMap& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mLanguage = rhs.mLanguage;
    mGlyphs = rhs.mGlyphs;
    mArcs = rhs.mArcs;
    mArcGroups = rhs.mArcGroups;
    mMapVersion = rhs.mMapVersion;
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
 * Creates and returns a deep copy of this SbgnMap object.
 */
SbgnMap*
SbgnMap::clone() const
{
  return new SbgnMap(*this);
}


/*
 * Destructor for SbgnMap.
 */
SbgnMap::~SbgnMap()
{
  delete mBBox;
  mBBox = NULL;
}


/*
 * Returns the value of the "id" attribute of this SbgnMap.
 */
const std::string&
SbgnMap::getId() const
{
  return mId;
}


/*
 * Returns the value of the "language" attribute of this SbgnMap.
 */
Language_t
SbgnMap::getLanguage() const
{
  return mLanguage;
}


/*
 * Returns the value of the "language" attribute of this SbgnMap.
 */
std::string
SbgnMap::getLanguageAsString() const
{
  std::string code_str = Language_toString(mLanguage);
  return code_str;
}


/*
 * Returns the value of the "version" attribute of this SbgnMap.
 */
MapType_t
SbgnMap::getMapVersion() const
{
  return mMapVersion;
}


/*
 * Returns the value of the "version" attribute of this SbgnMap.
 */
std::string
SbgnMap::getMapVersionAsString() const
{
  std::string code_str = MapType_toString(mMapVersion);
  return code_str;
}


/*
 * Predicate returning @c true if this SbgnMap's "id" attribute is set.
 */
bool
SbgnMap::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnMap's "language" attribute is set.
 */
bool
SbgnMap::isSetLanguage() const
{
  return (mLanguage != SBGNML_LANGUAGE_INVALID);
}


/*
 * Predicate returning @c true if this SbgnMap's "version" attribute is set.
 */
bool
SbgnMap::isSetMapVersion() const
{
  return (mMapVersion != SBGNML_MAPTYPE_INVALID);
}


/*
 * Sets the value of the "id" attribute of this SbgnMap.
 */
int
SbgnMap::setId(const std::string& id)
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
 * Sets the value of the "language" attribute of this SbgnMap.
 */
int
SbgnMap::setLanguage(const Language_t language)
{
  if (Language_isValid(language) == 0)
  {
    mLanguage = SBGNML_LANGUAGE_INVALID;
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mLanguage = language;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "language" attribute of this SbgnMap.
 */
int
SbgnMap::setLanguage(const std::string& language)
{
  mLanguage = Language_fromString(language.c_str());

  if (mLanguage == SBGNML_LANGUAGE_INVALID)
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "version" attribute of this SbgnMap.
 */
int
SbgnMap::setMapVersion(const MapType_t mapVersion)
{
  if (MapType_isValid(mapVersion) == 0)
  {
    mMapVersion = SBGNML_MAPTYPE_INVALID;
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mMapVersion = mapVersion;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "version" attribute of this SbgnMap.
 */
int
SbgnMap::setMapVersion(const std::string& mapVersion)
{
  mMapVersion = MapType_fromString(mapVersion.c_str());

  if (mMapVersion == SBGNML_MAPTYPE_INVALID)
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "id" attribute of this SbgnMap.
 */
int
SbgnMap::unsetId()
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
 * Unsets the value of the "language" attribute of this SbgnMap.
 */
int
SbgnMap::unsetLanguage()
{
  mLanguage = SBGNML_LANGUAGE_INVALID;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "version" attribute of this SbgnMap.
 */
int
SbgnMap::unsetMapVersion()
{
  mMapVersion = SBGNML_MAPTYPE_INVALID;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the value of the "bbox" element of this SbgnMap.
 */
const SbgnBBox*
SbgnMap::getBBox() const
{
  return mBBox;
}


/*
 * Returns the value of the "bbox" element of this SbgnMap.
 */
SbgnBBox*
SbgnMap::getBBox()
{
  return mBBox;
}


/*
 * Predicate returning @c true if this SbgnMap's "bbox" element is set.
 */
bool
SbgnMap::isSetBBox() const
{
  return (mBBox != NULL);
}


/*
 * Sets the value of the "bbox" element of this SbgnMap.
 */
int
SbgnMap::setBBox(const SbgnBBox* bbox)
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
 * Creates a new SbgnBBox object, adds it to this SbgnMap object and returns
 * the SbgnBBox object created.
 */
SbgnBBox*
SbgnMap::createBBox()
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
 * Unsets the value of the "bbox" element of this SbgnMap.
 */
int
SbgnMap::unsetBBox()
{
  delete mBBox;
  mBBox = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnMap.
 */
const SbgnListOfGlyphs*
SbgnMap::getListOfGlyphs() const
{
  return &mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnMap.
 */
SbgnListOfGlyphs*
SbgnMap::getListOfGlyphs()
{
  return &mGlyphs;
}


/*
 * Get a SbgnGlyph from the SbgnMap.
 */
SbgnGlyph*
SbgnMap::getGlyph(unsigned int n)
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnMap.
 */
const SbgnGlyph*
SbgnMap::getGlyph(unsigned int n) const
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on its identifier.
 */
SbgnGlyph*
SbgnMap::getGlyph(const std::string& sid)
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on its identifier.
 */
const SbgnGlyph*
SbgnMap::getGlyph(const std::string& sid) const
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the CompartmentRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnMap::getGlyphByCompartmentRef(const std::string& sid) const
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the CompartmentRef to which it
 * refers.
 */
SbgnGlyph*
SbgnMap::getGlyphByCompartmentRef(const std::string& sid)
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the MapRef to which it refers.
 */
const SbgnGlyph*
SbgnMap::getGlyphByMapRef(const std::string& sid) const
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the MapRef to which it refers.
 */
SbgnGlyph*
SbgnMap::getGlyphByMapRef(const std::string& sid)
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the TagRef to which it refers.
 */
const SbgnGlyph*
SbgnMap::getGlyphByTagRef(const std::string& sid) const
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnMap based on the TagRef to which it refers.
 */
SbgnGlyph*
SbgnMap::getGlyphByTagRef(const std::string& sid)
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Adds a copy of the given SbgnGlyph to this SbgnMap.
 */
int
SbgnMap::addGlyph(const SbgnGlyph* sg)
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
 * Get the number of SbgnGlyph objects in this SbgnMap.
 */
unsigned int
SbgnMap::getNumGlyphs() const
{
  return mGlyphs.size();
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnMap object and returns
 * the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnMap::createGlyph()
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
 * Removes the nth SbgnGlyph from this SbgnMap and returns a pointer to it.
 */
SbgnGlyph*
SbgnMap::removeGlyph(unsigned int n)
{
  return mGlyphs.remove(n);
}


/*
 * Removes the SbgnGlyph from this SbgnMap based on its identifier and returns
 * a pointer to it.
 */
SbgnGlyph*
SbgnMap::removeGlyph(const std::string& sid)
{
  return mGlyphs.remove(sid);
}


/*
 * Returns the SbgnListOfArcs from this SbgnMap.
 */
const SbgnListOfArcs*
SbgnMap::getListOfArcs() const
{
  return &mArcs;
}


/*
 * Returns the SbgnListOfArcs from this SbgnMap.
 */
SbgnListOfArcs*
SbgnMap::getListOfArcs()
{
  return &mArcs;
}


/*
 * Get a SbgnArc from the SbgnMap.
 */
SbgnArc*
SbgnMap::getArc(unsigned int n)
{
  return mArcs.get(n);
}


/*
 * Get a SbgnArc from the SbgnMap.
 */
const SbgnArc*
SbgnMap::getArc(unsigned int n) const
{
  return mArcs.get(n);
}


/*
 * Get a SbgnArc from the SbgnMap based on its identifier.
 */
SbgnArc*
SbgnMap::getArc(const std::string& sid)
{
  return mArcs.get(sid);
}


/*
 * Get a SbgnArc from the SbgnMap based on its identifier.
 */
const SbgnArc*
SbgnMap::getArc(const std::string& sid) const
{
  return mArcs.get(sid);
}


/*
 * Adds a copy of the given SbgnArc to this SbgnMap.
 */
int
SbgnMap::addArc(const SbgnArc* sa)
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
 * Get the number of SbgnArc objects in this SbgnMap.
 */
unsigned int
SbgnMap::getNumArcs() const
{
  return mArcs.size();
}


/*
 * Creates a new SbgnArc object, adds it to this SbgnMap object and returns the
 * SbgnArc object created.
 */
SbgnArc*
SbgnMap::createArc()
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
 * Removes the nth SbgnArc from this SbgnMap and returns a pointer to it.
 */
SbgnArc*
SbgnMap::removeArc(unsigned int n)
{
  return mArcs.remove(n);
}


/*
 * Removes the SbgnArc from this SbgnMap based on its identifier and returns a
 * pointer to it.
 */
SbgnArc*
SbgnMap::removeArc(const std::string& sid)
{
  return mArcs.remove(sid);
}


/*
 * Returns the SbgnListOfArcGroups from this SbgnMap.
 */
const SbgnListOfArcGroups*
SbgnMap::getListOfArcGroups() const
{
  return &mArcGroups;
}


/*
 * Returns the SbgnListOfArcGroups from this SbgnMap.
 */
SbgnListOfArcGroups*
SbgnMap::getListOfArcGroups()
{
  return &mArcGroups;
}


/*
 * Get a SbgnArcGroup from the SbgnMap.
 */
SbgnArcGroup*
SbgnMap::getArcGroup(unsigned int n)
{
  return mArcGroups.get(n);
}


/*
 * Get a SbgnArcGroup from the SbgnMap.
 */
const SbgnArcGroup*
SbgnMap::getArcGroup(unsigned int n) const
{
  return mArcGroups.get(n);
}


/*
 * Adds a copy of the given SbgnArcGroup to this SbgnMap.
 */
int
SbgnMap::addArcGroup(const SbgnArcGroup* sag)
{
  if (sag == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sag->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sag->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sag->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sag)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mArcGroups.append(sag);
  }
}


/*
 * Get the number of SbgnArcGroup objects in this SbgnMap.
 */
unsigned int
SbgnMap::getNumArcGroups() const
{
  return mArcGroups.size();
}


/*
 * Creates a new SbgnArcGroup object, adds it to this SbgnMap object and
 * returns the SbgnArcGroup object created.
 */
SbgnArcGroup*
SbgnMap::createArcGroup()
{
  SbgnArcGroup* sag = NULL;

  try
  {
    sag = new SbgnArcGroup(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sag != NULL)
  {
    mArcGroups.appendAndOwn(sag);
  }

  return sag;
}


/*
 * Removes the nth SbgnArcGroup from this SbgnMap and returns a pointer to it.
 */
SbgnArcGroup*
SbgnMap::removeArcGroup(unsigned int n)
{
  return mArcGroups.remove(n);
}


/*
 * Returns the XML element name of this SbgnMap object.
 */
const std::string&
SbgnMap::getElementName() const
{
  static const string name = "map";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnMap object.
 */
int
SbgnMap::getTypeCode() const
{
  return SBGN_SBGNML_MAP;
}


/*
 * Predicate returning @c true if all the required attributes for this SbgnMap
 * object have been set.
 */
bool
SbgnMap::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
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
SbgnMap::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SbgnBase::writeElements(stream);

  if (isSetBBox() == true)
  {
    mBBox->write(stream);
  }

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumArcs(); i++)
  {
    getArc(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumArcGroups(); i++)
  {
    getArcGroup(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnMap::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnMap::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  if (mBBox != NULL)
  {
    mBBox->setSbgnDocument(d);
  }

  mGlyphs.setSbgnDocument(d);

  mArcs.setSbgnDocument(d);

  mArcGroups.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnMap::connectToChild()
{
  SbgnBase::connectToChild();

  if (mBBox != NULL)
  {
    mBBox->connectToParent(this);
  }

  mGlyphs.connectToParent(this);

  mArcs.connectToParent(this);

  mArcGroups.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "language")
  {
    value = getLanguageAsString();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "version")
  {
    value = getMapVersionAsString();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnMap's attribute "attributeName" is
 * set.
 */
bool
SbgnMap::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "language")
  {
    value = isSetLanguage();
  }
  else if (attributeName == "version")
  {
    value = isSetMapVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "language")
  {
    return_value = setLanguage(value);
  }
  else if (attributeName == "version")
  {
    return_value = setMapVersion(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnMap.
 */
int
SbgnMap::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "language")
  {
    value = unsetLanguage();
  }
  else if (attributeName == "version")
  {
    value = unsetMapVersion();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnMap.
 */
SbgnBase*
SbgnMap::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return createBBox();
  }
  else if (elementName == "glyph")
  {
    return createGlyph();
  }
  else if (elementName == "arc")
  {
    return createArc();
  }
  else if (elementName == "arcgroup")
  {
    return createArcGroup();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnMap.
 */
int
SbgnMap::addChildObject(const std::string& elementName,
                        const SbgnBase* element)
{
  if (elementName == "bbox" && element->getTypeCode() == SBGN_SBGNML_BBOX)
  {
    return setBBox((const SbgnBBox*)(element));
  }
  else if (elementName == "glyph" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const SbgnGlyph*)(element));
  }
  else if (elementName == "arc" && element->getTypeCode() == SBGN_SBGNML_ARC)
  {
    return addArc((const SbgnArc*)(element));
  }
  else if (elementName == "arcgroup" && element->getTypeCode() ==
    SBGN_SBGNML_ARCGROUP)
  {
    return addArcGroup((const SbgnArcGroup*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnMap.
 */
SbgnBase*
SbgnMap::removeChildObject(const std::string& elementName,
                           const std::string& id)
{
  if (elementName == "bbox")
  {
    SbgnBBox * obj = getBBox();
    if (unsetBBox() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "glyph")
  {
    return removeGlyph(id);
  }
  else if (elementName == "arc")
  {
    return removeArc(id);
  }
  else if (elementName == "arcgroup")
  {
    for (unsigned int i = 0; i < getNumArcGroups(); i++)
    {
      if (getArcGroup(i)->getId() == id)
      {
        return removeArcGroup(i);
      }
    }
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnMap.
 */
unsigned int
SbgnMap::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "bbox")
  {
    if (isSetBBox())
    {
      return 1;
    }
  }
  else if (elementName == "glyph")
  {
    return getNumGlyphs();
  }
  else if (elementName == "arc")
  {
    return getNumArcs();
  }
  else if (elementName == "arcgroup")
  {
    return getNumArcGroups();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnMap.
 */
SbgnBase*
SbgnMap::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "bbox")
  {
    return getBBox();
  }
  else if (elementName == "glyph")
  {
    return getGlyph(index);
  }
  else if (elementName == "arc")
  {
    return getArc(index);
  }
  else if (elementName == "arcgroup")
  {
    return getArcGroup(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnMap::getElementBySId(const std::string& id)
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

  obj = mArcGroups.getElementBySId(id);

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
SbgnMap::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "bbox")
  {
    if (isSetBBox())
    {
      getErrorLog()->logError(SbgnmlMapAllowedElements, getLevel(),
        getVersion());
    }

    delete mBBox;
    mBBox = new SbgnBBox(getSbgnNamespaces());
    obj = mBBox;
  }
  else if (name == "glyph")
  {
    obj = mGlyphs.createObject(stream);
  }
  else if (name == "arc")
  {
    obj = mArcs.createObject(stream);
  }
  else if (name == "arcgroup")
  {
    obj = mArcGroups.createObject(stream);
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
SbgnMap::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("language");

  attributes.add("version");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnMap::readAttributes(
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
    static_cast<SbgnListOfMaps*>(getParentSbgnObject())->size() < 2)
  {
    numErrs = log->getNumErrors();
    for (int n = numErrs-1; n >= 0; n--)
    {
      if (log->getError(n)->getErrorId() == SbgnUnknownCoreAttribute)
      {
        const std::string details = log->getError(n)->getMessage();
        log->remove(SbgnUnknownCoreAttribute);
        log->logError(SbgnmlDocumentLOMapsAllowedCoreAttributes, level,
          version, details);
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
        log->logError(SbgnmlMapAllowedAttributes, level, version, details,
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
      logEmptyString(mId, level, version, "<SbgnMap>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnUnknown, level, version, "The attribute id='" + mId + "' "
        "does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'id' is missing from the <SbgnMap> "
      "element.";
    log->logError(SbgnmlMapAllowedAttributes, level, version, message);
  }

  // 
  // language enum (use = "optional" )
  // 

  std::string language;
  assigned = attributes.readInto("language", language);

  if (assigned == true)
  {
    if (language.empty() == true)
    {
      logEmptyString(language, level, version, "<SbgnMap>");
    }
    else
    {
      mLanguage = Language_fromString(language.c_str());

      if (Language_isValid(mLanguage) == 0)
      {
        std::string msg = "The language on the <SbgnMap> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + language + "', which is not a valid option.";

        log->logError(SbgnmlMapLanguageMustBeLanguageEnum, level, version,
          msg);
      }
    }
  }

  // 
  // version enum (use = "optional" )
  // 

  std::string mapVersion;
  assigned = attributes.readInto("version", mapVersion);

  if (assigned == true)
  {
    if (mapVersion.empty() == true)
    {
      logEmptyString(mapVersion, level, version, "<SbgnMap>");
    }
    else
    {
      mMapVersion = MapType_fromString(mapVersion.c_str());

      if (MapType_isValid(mMapVersion) == 0)
      {
        std::string msg = "The version on the <SbgnMap> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + mapVersion + "', which is not a valid option.";

        log->logError(SbgnmlMapMapVersionMustBeMapTypeEnum, level, version,
          msg);
      }
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnMap::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetLanguage() == true)
  {
    stream.writeAttribute("language", getPrefix(),
      Language_toString(mLanguage));
  }

  if (isSetMapVersion() == true)
  {
    stream.writeAttribute("version", getPrefix(),
      MapType_toString(mMapVersion));
  }
}

/** @endcond */



LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

#include <sbml/packages/render/common/RenderExtensionTypes.h>
#include <sbml/packages/render/sbml/LocalRenderInformation.h>

bool
SbgnMap::readOtherXML(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  return false;
}

std::string SbgnMap::getRenderInformationAsString() const
{
  LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation* info = getRenderInformation();
  if (info != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode node = info->toXML();
    return XMLNode::convertXMLNodeToString(&node);
  }
  return std::string();
}

const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
getRenderInformationNode(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* node)
{
  if (node == NULL)
    return NULL;

  if (node->getName() == "renderInformation")
    return node;

  for (unsigned int i = 0; i < node->getNumChildren(); ++i)
  {
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& current = node->getChild(i);
    if (current.getName() == "renderInformation")
      return &current;
  }

  return NULL;
}

LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation*
SbgnMap::getRenderInformation() const
{
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* node = getExtension();
  if (node == NULL) 
    return NULL;

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* infoNode = getRenderInformationNode(node);
  if (infoNode == NULL)
    return NULL;

  LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation* result = new LIBSBML_CPP_NAMESPACE_QUALIFIER
    LocalRenderInformation();

  result->parseXML(*infoNode);

  return result;
}

void
SbgnMap::setRenderInformation(
  const LIBSBML_CPP_NAMESPACE_QUALIFIER LocalRenderInformation *info)
{
  if (info == NULL) return;

  XMLNode xml = info->toXML();

  xml.addNamespace(info->getURI());

  replaceTopLevelExtensionElement(&xml);

}

#endif // __cplusplus

LIBSBGN_CPP_NAMESPACE_END


#endif /* __cplusplus */


/*
 * Creates a new SbgnMap_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnMap_t *
SbgnMap_create(unsigned int level, unsigned int version)
{
  return new SbgnMap(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnMap_t object.
 */
LIBSBGN_EXTERN
SbgnMap_t*
SbgnMap_clone(const SbgnMap_t* sm)
{
  if (sm != NULL)
  {
    return static_cast<SbgnMap_t*>(sm->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnMap_t object.
 */
LIBSBGN_EXTERN
void
SbgnMap_free(SbgnMap_t* sm)
{
  if (sm != NULL)
  {
    delete sm;
  }
}


/*
 * Returns the value of the "id" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
char *
SbgnMap_getId(const SbgnMap_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return sm->getId().empty() ? NULL : safe_strdup(sm->getId().c_str());
}


/*
 * Returns the value of the "language" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
Language_t
SbgnMap_getLanguage(const SbgnMap_t * sm)
{
  if (sm == NULL)
  {
    return SBGNML_LANGUAGE_INVALID;
  }

  return sm->getLanguage();
}


/*
 * Returns the value of the "language" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
char *
SbgnMap_getLanguageAsString(const SbgnMap_t * sm)
{
  return (char*)(Language_toString(sm->getLanguage()));
}


/*
 * Returns the value of the "version" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
MapType_t
SbgnMap_getMapVersion(const SbgnMap_t * sm)
{
  if (sm == NULL)
  {
    return SBGNML_MAPTYPE_INVALID;
  }

  return sm->getMapVersion();
}


/*
 * Returns the value of the "version" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
char *
SbgnMap_getMapVersionAsString(const SbgnMap_t * sm)
{
  return (char*)(MapType_toString(sm->getMapVersion()));
}


/*
 * Predicate returning @c 1 (true) if this SbgnMap_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetId(const SbgnMap_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnMap_t's "language" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetLanguage(const SbgnMap_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetLanguage()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnMap_t's "version" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetMapVersion(const SbgnMap_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetMapVersion()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setId(SbgnMap_t * sm, const char * id)
{
  return (sm != NULL) ? sm->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setLanguage(SbgnMap_t * sm, Language_t language)
{
  return (sm != NULL) ? sm->setLanguage(language) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "language" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setLanguageAsString(SbgnMap_t * sm, const char * language)
{
  return (sm != NULL) ? sm->setLanguage(language): LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "version" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setMapVersion(SbgnMap_t * sm, MapType_t mapVersion)
{
  return (sm != NULL) ? sm->setMapVersion(mapVersion) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "version" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setMapVersionAsString(SbgnMap_t * sm, const char * mapVersion)
{
  return (sm != NULL) ? sm->setMapVersion(mapVersion): LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetId(SbgnMap_t * sm)
{
  return (sm != NULL) ? sm->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "language" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetLanguage(SbgnMap_t * sm)
{
  return (sm != NULL) ? sm->unsetLanguage() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "version" attribute of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetMapVersion(SbgnMap_t * sm)
{
  return (sm != NULL) ? sm->unsetMapVersion() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "bbox" element of this SbgnMap_t.
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnMap_getBBox(const SbgnMap_t * sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sm->getBBox());
}


/*
 * Predicate returning @c 1 (true) if this SbgnMap_t's "bbox" element is set.
 */
LIBSBGN_EXTERN
int
SbgnMap_isSetBBox(const SbgnMap_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->isSetBBox()) : 0;
}


/*
 * Sets the value of the "bbox" element of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_setBBox(SbgnMap_t * sm, const SbgnBBox_t* bbox)
{
  return (sm != NULL) ? sm->setBBox(bbox) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new SbgnBBox_t object, adds it to this SbgnMap_t object and
 * returns the SbgnBBox_t object created.
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnMap_createBBox(SbgnMap_t* sm)
{
  if (sm == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sm->createBBox());
}


/*
 * Unsets the value of the "bbox" element of this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_unsetBBox(SbgnMap_t * sm)
{
  return (sm != NULL) ? sm->unsetBBox() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfGlyphs(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getListOfGlyphs() : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyph(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->getGlyph(n) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnMap_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphById(SbgnMap_t* sm, const char *sid)
{
  return (sm != NULL && sid != NULL) ? sm->getGlyph(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnMap_t based on the CompartmentRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByCompartmentRef(SbgnMap_t* sm, const char *sid)
{
  return (sm != NULL && sid != NULL) ? sm->getGlyphByCompartmentRef(sid) :
    NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnMap_t based on the MapRef to which it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByMapRef(SbgnMap_t* sm, const char *sid)
{
  return (sm != NULL && sid != NULL) ? sm->getGlyphByMapRef(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnMap_t based on the TagRef to which it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_getGlyphByTagRef(SbgnMap_t* sm, const char *sid)
{
  return (sm != NULL && sid != NULL) ? sm->getGlyphByTagRef(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnGlyph_t to this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_addGlyph(SbgnMap_t* sm, const SbgnGlyph_t* sg)
{
  return (sm != NULL) ? sm->addGlyph(sg) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnGlyph_t objects in this SbgnMap_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumGlyphs(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnGlyph_t object, adds it to this SbgnMap_t object and
 * returns the SbgnGlyph_t object created.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_createGlyph(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->createGlyph() : NULL;
}


/*
 * Removes the nth SbgnGlyph_t from this SbgnMap_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_removeGlyph(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->removeGlyph(n) : NULL;
}


/*
 * Removes the SbgnGlyph_t from this SbgnMap_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnMap_removeGlyphById(SbgnMap_t* sm, const char* sid)
{
  return (sm != NULL && sid != NULL) ? sm->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnArc_t objects from this SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfArcs(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getListOfArcs() : NULL;
}


/*
 * Get a SbgnArc_t from the SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_getArc(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->getArc(n) : NULL;
}


/*
 * Get a SbgnArc_t from the SbgnMap_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_getArcById(SbgnMap_t* sm, const char *sid)
{
  return (sm != NULL && sid != NULL) ? sm->getArc(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnArc_t to this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_addArc(SbgnMap_t* sm, const SbgnArc_t* sa)
{
  return (sm != NULL) ? sm->addArc(sa) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnArc_t objects in this SbgnMap_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumArcs(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getNumArcs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnArc_t object, adds it to this SbgnMap_t object and returns
 * the SbgnArc_t object created.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_createArc(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->createArc() : NULL;
}


/*
 * Removes the nth SbgnArc_t from this SbgnMap_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_removeArc(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->removeArc(n) : NULL;
}


/*
 * Removes the SbgnArc_t from this SbgnMap_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnMap_removeArcById(SbgnMap_t* sm, const char* sid)
{
  return (sm != NULL && sid != NULL) ? sm->removeArc(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnArcGroup_t objects from this SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnMap_getListOfArcGroups(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getListOfArcGroups() : NULL;
}


/*
 * Get a SbgnArcGroup_t from the SbgnMap_t.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_getArcGroup(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->getArcGroup(n) : NULL;
}


/*
 * Adds a copy of the given SbgnArcGroup_t to this SbgnMap_t.
 */
LIBSBGN_EXTERN
int
SbgnMap_addArcGroup(SbgnMap_t* sm, const SbgnArcGroup_t* sag)
{
  return (sm != NULL) ? sm->addArcGroup(sag) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnArcGroup_t objects in this SbgnMap_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnMap_getNumArcGroups(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->getNumArcGroups() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnArcGroup_t object, adds it to this SbgnMap_t object and
 * returns the SbgnArcGroup_t object created.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_createArcGroup(SbgnMap_t* sm)
{
  return (sm != NULL) ? sm->createArcGroup() : NULL;
}


/*
 * Removes the nth SbgnArcGroup_t from this SbgnMap_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnArcGroup_t*
SbgnMap_removeArcGroup(SbgnMap_t* sm, unsigned int n)
{
  return (sm != NULL) ? sm->removeArcGroup(n) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnMap_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnMap_hasRequiredAttributes(const SbgnMap_t * sm)
{
  return (sm != NULL) ? static_cast<int>(sm->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



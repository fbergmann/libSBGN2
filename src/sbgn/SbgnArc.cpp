/**
 * @file SbgnArc.cpp
 * @brief Implementation of the SbgnArc class.
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
#include <sbgn/SbgnArc.h>
#include <sbgn/SbgnListOfArcs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnArc using the given SBGN Level and @ p version values.
 */
SbgnArc::SbgnArc(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mClazz ("")
  , mSource ("")
  , mTarget ("")
  , mGlyphs (level, version)
  , mStart (NULL)
  , mPoints (level, version)
  , mEnd (NULL)
  , mPorts (level, version)
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  mPoints.setElementName("next");
  connectToChild();
}


/*
 * Creates a new SbgnArc using the given SbgnNamespaces object @p sbgnns.
 */
SbgnArc::SbgnArc(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mClazz ("")
  , mSource ("")
  , mTarget ("")
  , mGlyphs (sbgnns)
  , mStart (NULL)
  , mPoints (sbgnns)
  , mEnd (NULL)
  , mPorts (sbgnns)
{
  setElementNamespace(sbgnns->getURI());
  mPoints.setElementName("next");
  connectToChild();
}


/*
 * Copy constructor for SbgnArc.
 */
SbgnArc::SbgnArc(const SbgnArc& orig)
  : SbgnBase( orig )
  , mClazz ( orig.mClazz )
  , mSource ( orig.mSource )
  , mTarget ( orig.mTarget )
  , mGlyphs ( orig.mGlyphs )
  , mStart ( NULL )
  , mPoints ( orig.mPoints )
  , mEnd ( NULL )
  , mPorts ( orig.mPorts )
{
  if (orig.mStart != NULL)
  {
    mStart = orig.mStart->clone();
  }

  if (orig.mEnd != NULL)
  {
    mEnd = orig.mEnd->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnArc.
 */
SbgnArc&
SbgnArc::operator=(const SbgnArc& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mClazz = rhs.mClazz;
    mSource = rhs.mSource;
    mTarget = rhs.mTarget;
    mGlyphs = rhs.mGlyphs;
    mPoints = rhs.mPoints;
    mPorts = rhs.mPorts;
    delete mStart;
    if (rhs.mStart != NULL)
    {
      mStart = rhs.mStart->clone();
    }
    else
    {
      mStart = NULL;
    }

    delete mEnd;
    if (rhs.mEnd != NULL)
    {
      mEnd = rhs.mEnd->clone();
    }
    else
    {
      mEnd = NULL;
    }

    connectToChild();
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnArc object.
 */
SbgnArc*
SbgnArc::clone() const
{
  return new SbgnArc(*this);
}


/*
 * Destructor for SbgnArc.
 */
SbgnArc::~SbgnArc()
{
  delete mStart;
  mStart = NULL;
  delete mEnd;
  mEnd = NULL;
}


/*
 * Returns the value of the "id" attribute of this SbgnArc.
 */
const std::string&
SbgnArc::getId() const
{
  return mId;
}


/*
 * Returns the value of the "class" attribute of this SbgnArc.
 */
const std::string&
SbgnArc::getClazz() const
{
  return mClazz;
}


/*
 * Returns the value of the "source" attribute of this SbgnArc.
 */
const std::string&
SbgnArc::getSource() const
{
  return mSource;
}


/*
 * Returns the value of the "target" attribute of this SbgnArc.
 */
const std::string&
SbgnArc::getTarget() const
{
  return mTarget;
}


/*
 * Predicate returning @c true if this SbgnArc's "id" attribute is set.
 */
bool
SbgnArc::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnArc's "class" attribute is set.
 */
bool
SbgnArc::isSetClazz() const
{
  return (mClazz.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnArc's "source" attribute is set.
 */
bool
SbgnArc::isSetSource() const
{
  return (mSource.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnArc's "target" attribute is set.
 */
bool
SbgnArc::isSetTarget() const
{
  return (mTarget.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SbgnArc.
 */
int
SbgnArc::setId(const std::string& id)
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
 * Sets the value of the "class" attribute of this SbgnArc.
 */
int
SbgnArc::setClazz(const std::string& clazz)
{
  mClazz = clazz;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "source" attribute of this SbgnArc.
 */
int
SbgnArc::setSource(const std::string& source)
{
  if (!(SyntaxChecker::isValidXMLID(source)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mSource = source;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "target" attribute of this SbgnArc.
 */
int
SbgnArc::setTarget(const std::string& target)
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
 * Unsets the value of the "id" attribute of this SbgnArc.
 */
int
SbgnArc::unsetId()
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
 * Unsets the value of the "class" attribute of this SbgnArc.
 */
int
SbgnArc::unsetClazz()
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
 * Unsets the value of the "source" attribute of this SbgnArc.
 */
int
SbgnArc::unsetSource()
{
  mSource.erase();

  if (mSource.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "target" attribute of this SbgnArc.
 */
int
SbgnArc::unsetTarget()
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
 * Returns the value of the "start" element of this SbgnArc.
 */
const SbgnPoint*
SbgnArc::getStart() const
{
  return mStart;
}


/*
 * Returns the value of the "start" element of this SbgnArc.
 */
SbgnPoint*
SbgnArc::getStart()
{
  return mStart;
}


/*
 * Returns the value of the "end" element of this SbgnArc.
 */
const SbgnPoint*
SbgnArc::getEnd() const
{
  return mEnd;
}


/*
 * Returns the value of the "end" element of this SbgnArc.
 */
SbgnPoint*
SbgnArc::getEnd()
{
  return mEnd;
}


/*
 * Predicate returning @c true if this SbgnArc's "start" element is set.
 */
bool
SbgnArc::isSetStart() const
{
  return (mStart != NULL);
}


/*
 * Predicate returning @c true if this SbgnArc's "end" element is set.
 */
bool
SbgnArc::isSetEnd() const
{
  return (mEnd != NULL);
}


/*
 * Sets the value of the "start" element of this SbgnArc.
 */
int
SbgnArc::setStart(const SbgnPoint* start)
{
  if (mStart == start)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (start == NULL)
  {
    delete mStart;
    mStart = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mStart;
    mStart = (start != NULL) ? start->clone() : NULL;
    if (mStart != NULL)
    {
      mStart->setElementName("start");
      mStart->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "end" element of this SbgnArc.
 */
int
SbgnArc::setEnd(const SbgnPoint* end)
{
  if (mEnd == end)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (end == NULL)
  {
    delete mEnd;
    mEnd = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mEnd;
    mEnd = (end != NULL) ? end->clone() : NULL;
    if (mEnd != NULL)
    {
      mEnd->setElementName("end");
      mEnd->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
 * the SbgnPoint object created.
 */
SbgnPoint*
SbgnArc::createStart()
{
  if (mStart != NULL)
  {
    delete mStart;
  }

  mStart = new SbgnPoint(getSbgnNamespaces());

  mStart->setElementName("start");

  connectToChild();

  return mStart;
}


/*
 * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
 * the SbgnPoint object created.
 */
SbgnPoint*
SbgnArc::createEnd()
{
  if (mEnd != NULL)
  {
    delete mEnd;
  }

  mEnd = new SbgnPoint(getSbgnNamespaces());

  mEnd->setElementName("end");

  connectToChild();

  return mEnd;
}


/*
 * Unsets the value of the "start" element of this SbgnArc.
 */
int
SbgnArc::unsetStart()
{
  delete mStart;
  mStart = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "end" element of this SbgnArc.
 */
int
SbgnArc::unsetEnd()
{
  delete mEnd;
  mEnd = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnArc.
 */
const SbgnListOfGlyphs*
SbgnArc::getListOfGlyphs() const
{
  return &mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs from this SbgnArc.
 */
SbgnListOfGlyphs*
SbgnArc::getListOfGlyphs()
{
  return &mGlyphs;
}


/*
 * Get a SbgnGlyph from the SbgnArc.
 */
SbgnGlyph*
SbgnArc::getGlyph(unsigned int n)
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnArc.
 */
const SbgnGlyph*
SbgnArc::getGlyph(unsigned int n) const
{
  return mGlyphs.get(n);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on its identifier.
 */
SbgnGlyph*
SbgnArc::getGlyph(const std::string& sid)
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on its identifier.
 */
const SbgnGlyph*
SbgnArc::getGlyph(const std::string& sid) const
{
  return mGlyphs.get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the CompartmentRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnArc::getGlyphByCompartmentRef(const std::string& sid) const
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the CompartmentRef to which it
 * refers.
 */
SbgnGlyph*
SbgnArc::getGlyphByCompartmentRef(const std::string& sid)
{
  return mGlyphs.getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the MapRef to which it refers.
 */
const SbgnGlyph*
SbgnArc::getGlyphByMapRef(const std::string& sid) const
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the MapRef to which it refers.
 */
SbgnGlyph*
SbgnArc::getGlyphByMapRef(const std::string& sid)
{
  return mGlyphs.getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the TagRef to which it refers.
 */
const SbgnGlyph*
SbgnArc::getGlyphByTagRef(const std::string& sid) const
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnArc based on the TagRef to which it refers.
 */
SbgnGlyph*
SbgnArc::getGlyphByTagRef(const std::string& sid)
{
  return mGlyphs.getByTagRef(sid);
}


/*
 * Adds a copy of the given SbgnGlyph to this SbgnArc.
 */
int
SbgnArc::addGlyph(const SbgnGlyph* sg)
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
 * Get the number of SbgnGlyph objects in this SbgnArc.
 */
unsigned int
SbgnArc::getNumGlyphs() const
{
  return mGlyphs.size();
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnArc object and returns
 * the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnArc::createGlyph()
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
 * Removes the nth SbgnGlyph from this SbgnArc and returns a pointer to it.
 */
SbgnGlyph*
SbgnArc::removeGlyph(unsigned int n)
{
  return mGlyphs.remove(n);
}


/*
 * Removes the SbgnGlyph from this SbgnArc based on its identifier and returns
 * a pointer to it.
 */
SbgnGlyph*
SbgnArc::removeGlyph(const std::string& sid)
{
  return mGlyphs.remove(sid);
}


/*
 * Returns the SbgnListOfPoints from this SbgnArc.
 */
const SbgnListOfPoints*
SbgnArc::getListOfNexts() const
{
  return &mPoints;
}


/*
 * Returns the SbgnListOfPoints from this SbgnArc.
 */
SbgnListOfPoints*
SbgnArc::getListOfNexts()
{
  return &mPoints;
}


/*
 * Get a SbgnPoint from the SbgnArc.
 */
SbgnPoint*
SbgnArc::getNext(unsigned int n)
{
  return mPoints.get(n);
}


/*
 * Get a SbgnPoint from the SbgnArc.
 */
const SbgnPoint*
SbgnArc::getNext(unsigned int n) const
{
  return mPoints.get(n);
}


/*
 * Adds a copy of the given SbgnPoint to this SbgnArc.
 */
int
SbgnArc::addNext(const SbgnPoint* sp)
{
  if (sp == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sp)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return mPoints.append(sp);
  }
}


/*
 * Get the number of SbgnPoint objects in this SbgnArc.
 */
unsigned int
SbgnArc::getNumNexts() const
{
  return mPoints.size();
}


/*
 * Creates a new SbgnPoint object, adds it to this SbgnArc object and returns
 * the SbgnPoint object created.
 */
SbgnPoint*
SbgnArc::createNext()
{
  SbgnPoint* sp = NULL;

  try
  {
    sp = new SbgnPoint(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    sp->setElementName("next");
    mPoints.appendAndOwn(sp);
  }

  return sp;
}


/*
 * Removes the nth SbgnPoint from this SbgnArc and returns a pointer to it.
 */
SbgnPoint*
SbgnArc::removeNext(unsigned int n)
{
  return mPoints.remove(n);
}


/*
 * Returns the SbgnListOfPorts from this SbgnArc.
 */
const SbgnListOfPorts*
SbgnArc::getListOfPorts() const
{
  return &mPorts;
}


/*
 * Returns the SbgnListOfPorts from this SbgnArc.
 */
SbgnListOfPorts*
SbgnArc::getListOfPorts()
{
  return &mPorts;
}


/*
 * Get a SbgnPort from the SbgnArc.
 */
SbgnPort*
SbgnArc::getPort(unsigned int n)
{
  return mPorts.get(n);
}


/*
 * Get a SbgnPort from the SbgnArc.
 */
const SbgnPort*
SbgnArc::getPort(unsigned int n) const
{
  return mPorts.get(n);
}


/*
 * Get a SbgnPort from the SbgnArc based on its identifier.
 */
SbgnPort*
SbgnArc::getPort(const std::string& sid)
{
  return mPorts.get(sid);
}


/*
 * Get a SbgnPort from the SbgnArc based on its identifier.
 */
const SbgnPort*
SbgnArc::getPort(const std::string& sid) const
{
  return mPorts.get(sid);
}


/*
 * Adds a copy of the given SbgnPort to this SbgnArc.
 */
int
SbgnArc::addPort(const SbgnPort* sp)
{
  if (sp == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sp->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sp->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sp->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sp)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (sp->isSetId() && (mPorts.get(sp->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mPorts.append(sp);
  }
}


/*
 * Get the number of SbgnPort objects in this SbgnArc.
 */
unsigned int
SbgnArc::getNumPorts() const
{
  return mPorts.size();
}


/*
 * Creates a new SbgnPort object, adds it to this SbgnArc object and returns
 * the SbgnPort object created.
 */
SbgnPort*
SbgnArc::createPort()
{
  SbgnPort* sp = NULL;

  try
  {
    sp = new SbgnPort(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sp != NULL)
  {
    mPorts.appendAndOwn(sp);
  }

  return sp;
}


/*
 * Removes the nth SbgnPort from this SbgnArc and returns a pointer to it.
 */
SbgnPort*
SbgnArc::removePort(unsigned int n)
{
  return mPorts.remove(n);
}


/*
 * Removes the SbgnPort from this SbgnArc based on its identifier and returns a
 * pointer to it.
 */
SbgnPort*
SbgnArc::removePort(const std::string& sid)
{
  return mPorts.remove(sid);
}


/*
 * Returns the XML element name of this SbgnArc object.
 */
const std::string&
SbgnArc::getElementName() const
{
  static const string name = "arc";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnArc object.
 */
int
SbgnArc::getTypeCode() const
{
  return SBGN_SBGNML_ARC;
}


/*
 * Predicate returning @c true if all the required attributes for this SbgnArc
 * object have been set.
 */
bool
SbgnArc::hasRequiredAttributes() const
{
  bool allPresent = true;

  if (isSetId() == false)
  {
    allPresent = false;
  }

  if (isSetClazz() == false)
  {
    allPresent = false;
  }

  if (isSetSource() == false)
  {
    allPresent = false;
  }

  if (isSetTarget() == false)
  {
    allPresent = false;
  }

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SbgnArc
 * object have been set.
 */
bool
SbgnArc::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetStart() == false)
  {
    allPresent = false;
  }

  if (isSetEnd() == false)
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
SbgnArc::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream)
  const
{
  SbgnBase::writeElements(stream);

  if (isSetStart() == true)
  {
    mStart->write(stream);
  }

  if (isSetEnd() == true)
  {
    mEnd->write(stream);
  }

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumNexts(); i++)
  {
    getNext(i)->write(stream);
  }

  for (unsigned int i = 0; i < getNumPorts(); i++)
  {
    getPort(i)->write(stream);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnArc::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnArc::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  if (mStart != NULL)
  {
    mStart->setSbgnDocument(d);
  }

  if (mEnd != NULL)
  {
    mEnd->setSbgnDocument(d);
  }

  mGlyphs.setSbgnDocument(d);

  mPoints.setSbgnDocument(d);

  mPorts.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnArc::connectToChild()
{
  SbgnBase::connectToChild();

  if (mStart != NULL)
  {
    mStart->connectToParent(this);
  }

  if (mEnd != NULL)
  {
    mEnd->connectToParent(this);
  }

  mGlyphs.connectToParent(this);

  mPoints.connectToParent(this);

  mPorts.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::getAttribute(const std::string& attributeName,
                      unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "class")
  {
    value = getClazz();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "source")
  {
    value = getSource();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "target")
  {
    value = getTarget();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnArc's attribute "attributeName" is
 * set.
 */
bool
SbgnArc::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = isSetId();
  }
  else if (attributeName == "class")
  {
    value = isSetClazz();
  }
  else if (attributeName == "source")
  {
    value = isSetSource();
  }
  else if (attributeName == "target")
  {
    value = isSetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::setAttribute(const std::string& attributeName,
                      const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "id")
  {
    return_value = setId(value);
  }
  else if (attributeName == "class")
  {
    return_value = setClazz(value);
  }
  else if (attributeName == "source")
  {
    return_value = setSource(value);
  }
  else if (attributeName == "target")
  {
    return_value = setTarget(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnArc.
 */
int
SbgnArc::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "id")
  {
    value = unsetId();
  }
  else if (attributeName == "class")
  {
    value = unsetClazz();
  }
  else if (attributeName == "source")
  {
    value = unsetSource();
  }
  else if (attributeName == "target")
  {
    value = unsetTarget();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnArc.
 */
SbgnBase*
SbgnArc::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "start")
  {
    return createStart();
  }
  else if (elementName == "end")
  {
    return createEnd();
  }
  else if (elementName == "glyph")
  {
    return createGlyph();
  }
  else if (elementName == "next")
  {
    return createNext();
  }
  else if (elementName == "port")
  {
    return createPort();
  }

  return obj;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds a new "elementName" object to this SbgnArc.
 */
int
SbgnArc::addChildObject(const std::string& elementName,
                        const SbgnBase* element)
{
  if (elementName == "start" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return setStart((const SbgnPoint*)(element));
  }
  else if (elementName == "end" && element->getTypeCode() == SBGN_SBGNML_POINT)
  {
    return setEnd((const SbgnPoint*)(element));
  }
  else if (elementName == "glyph" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const SbgnGlyph*)(element));
  }
  else if (elementName == "next" && element->getTypeCode() ==
    SBGN_SBGNML_POINT)
  {
    return addNext((const SbgnPoint*)(element));
  }
  else if (elementName == "port" && element->getTypeCode() == SBGN_SBGNML_PORT)
  {
    return addPort((const SbgnPort*)(element));
  }

  return LIBSBML_OPERATION_FAILED;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Removes and returns the new "elementName" object with the given id in this
 * SbgnArc.
 */
SbgnBase*
SbgnArc::removeChildObject(const std::string& elementName,
                           const std::string& id)
{
  if (elementName == "start")
  {
    SbgnPoint * obj = getStart();
    if (unsetStart() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "end")
  {
    SbgnPoint * obj = getEnd();
    if (unsetEnd() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "glyph")
  {
    return removeGlyph(id);
  }
  else if (elementName == "next")
  {
    for (unsigned int i = 0; i < getNumNexts(); i++)
    {
      if (getNext(i)->getId() == id)
      {
        return removeNext(i);
      }
    }
  }
  else if (elementName == "port")
  {
    return removePort(id);
  }

  return NULL;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the number of "elementName" in this SbgnArc.
 */
unsigned int
SbgnArc::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "start")
  {
    if (isSetStart())
    {
      return 1;
    }
  }
  else if (elementName == "end")
  {
    if (isSetEnd())
    {
      return 1;
    }
  }
  else if (elementName == "glyph")
  {
    return getNumGlyphs();
  }
  else if (elementName == "next")
  {
    return getNumNexts();
  }
  else if (elementName == "port")
  {
    return getNumPorts();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnArc.
 */
SbgnBase*
SbgnArc::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "start")
  {
    return getStart();
  }
  else if (elementName == "end")
  {
    return getEnd();
  }
  else if (elementName == "glyph")
  {
    return getGlyph(index);
  }
  else if (elementName == "next")
  {
    return getNext(index);
  }
  else if (elementName == "port")
  {
    return getPort(index);
  }

  return obj;
}

/** @endcond */


/*
 * Returns the first child element that has the given @p id in the model-wide
 * SId namespace, or @c NULL if no such object is found.
 */
SbgnBase*
SbgnArc::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mStart != NULL)
  {
    if (mStart->getId() == id)
    {
      return mStart;
    }

    obj = mStart->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mEnd != NULL)
  {
    if (mEnd->getId() == id)
    {
      return mEnd;
    }

    obj = mEnd->getElementBySId(id);
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

  obj = mPoints.getElementBySId(id);

  if (obj != NULL)
  {
    return obj;
  }

  obj = mPorts.getElementBySId(id);

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
SbgnArc::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "start")
  {
    if (isSetStart())
    {
      getErrorLog()->logError(SbgnmlArcAllowedElements, getLevel(),
        getVersion());
    }

    delete mStart;
    mStart = new SbgnPoint(getSbgnNamespaces());
    mStart->setElementName(name);
    obj = mStart;
  }
  else if (name == "end")
  {
    if (isSetEnd())
    {
      getErrorLog()->logError(SbgnmlArcAllowedElements, getLevel(),
        getVersion());
    }

    delete mEnd;
    mEnd = new SbgnPoint(getSbgnNamespaces());
    mEnd->setElementName(name);
    obj = mEnd;
  }
  else if (name == "glyph")
  {
    obj = mGlyphs.createObject(stream);
  }
  else if (name == "next")
  {
    obj = mPoints.createObject(stream);
  }
  else if (name == "port")
  {
    obj = mPorts.createObject(stream);
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
SbgnArc::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("class");

  attributes.add("source");

  attributes.add("target");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnArc::readAttributes(
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
    static_cast<SbgnListOfArcs*>(getParentSbgnObject())->size() < 2)
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
        log->logError(SbgnmlArcAllowedAttributes, level, version, details,
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
      logEmptyString(mId, level, version, "<SbgnArc>");
    }
    else if (SyntaxChecker::isValidXMLID(mId) == false)
    {
      logError(SbgnUnknown, level, version, "The attribute id='" + mId + "' "
        "does not conform to the syntax.");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'id' is missing from the <SbgnArc> "
      "element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message);
  }

  // 
  // class string (use = "required" )
  // 

  assigned = attributes.readInto("class", mClazz);

  if (assigned == true)
  {
    if (mClazz.empty() == true)
    {
      logEmptyString(mClazz, level, version, "<SbgnArc>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'class' is missing from the "
      "<SbgnArc> element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message);
  }

  // 
  // source IDREF (use = "required" )
  // 

  assigned = attributes.readInto("source", mSource);

  if (assigned == true)
  {
    if (mSource.empty() == true)
    {
      logEmptyString(mSource, level, version, "<SbgnArc>");
    }
    else if (SyntaxChecker::isValidXMLID(mSource) == false)
    {
      std::string msg = "The source attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mSource + "', which does not conform to the syntax.";
      logError(SbgnUnknown, level, version, msg);
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'source' is missing from the "
      "<SbgnArc> element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message);
  }

  // 
  // target IDREF (use = "required" )
  // 

  assigned = attributes.readInto("target", mTarget);

  if (assigned == true)
  {
    if (mTarget.empty() == true)
    {
      logEmptyString(mTarget, level, version, "<SbgnArc>");
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
  else
  {
    std::string message = "Sbgnml attribute 'target' is missing from the "
      "<SbgnArc> element.";
    log->logError(SbgnmlArcAllowedAttributes, level, version, message);
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnArc::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetId() == true)
  {
    stream.writeAttribute("id", getPrefix(), mId);
  }

  if (isSetClazz() == true)
  {
    stream.writeAttribute("class", getPrefix(), mClazz);
  }

  if (isSetSource() == true)
  {
    stream.writeAttribute("source", getPrefix(), mSource);
  }

  if (isSetTarget() == true)
  {
    stream.writeAttribute("target", getPrefix(), mTarget);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnArc_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnArc_t *
SbgnArc_create(unsigned int level, unsigned int version)
{
  return new SbgnArc(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnArc_t object.
 */
LIBSBGN_EXTERN
SbgnArc_t*
SbgnArc_clone(const SbgnArc_t* sa)
{
  if (sa != NULL)
  {
    return static_cast<SbgnArc_t*>(sa->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnArc_t object.
 */
LIBSBGN_EXTERN
void
SbgnArc_free(SbgnArc_t* sa)
{
  if (sa != NULL)
  {
    delete sa;
  }
}


/*
 * Returns the value of the "id" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
char *
SbgnArc_getId(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getId().empty() ? NULL : safe_strdup(sa->getId().c_str());
}


/*
 * Returns the value of the "class" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
char *
SbgnArc_getClazz(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getClazz().empty() ? NULL : safe_strdup(sa->getClazz().c_str());
}


/*
 * Returns the value of the "source" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
char *
SbgnArc_getSource(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getSource().empty() ? NULL : safe_strdup(sa->getSource().c_str());
}


/*
 * Returns the value of the "target" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
char *
SbgnArc_getTarget(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return sa->getTarget().empty() ? NULL : safe_strdup(sa->getTarget().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetId(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "class" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetClazz(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetClazz()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "source" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetSource(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetSource()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "target" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetTarget(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetTarget()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setId(SbgnArc_t * sa, const char * id)
{
  return (sa != NULL) ? sa->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "class" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setClazz(SbgnArc_t * sa, const char * clazz)
{
  return (sa != NULL) ? sa->setClazz(clazz) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "source" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setSource(SbgnArc_t * sa, const char * source)
{
  return (sa != NULL) ? sa->setSource(source) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "target" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setTarget(SbgnArc_t * sa, const char * target)
{
  return (sa != NULL) ? sa->setTarget(target) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetId(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "class" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetClazz(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetClazz() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "source" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetSource(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetSource() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "target" attribute of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetTarget(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetTarget() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "start" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnArc_getStart(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sa->getStart());
}


/*
 * Returns the value of the "end" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
const SbgnPoint_t*
SbgnArc_getEnd(const SbgnArc_t * sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sa->getEnd());
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "start" element is set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetStart(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetStart()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnArc_t's "end" element is set.
 */
LIBSBGN_EXTERN
int
SbgnArc_isSetEnd(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->isSetEnd()) : 0;
}


/*
 * Sets the value of the "start" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setStart(SbgnArc_t * sa, const SbgnPoint_t* start)
{
  return (sa != NULL) ? sa->setStart(start) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "end" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_setEnd(SbgnArc_t * sa, const SbgnPoint_t* end)
{
  return (sa != NULL) ? sa->setEnd(end) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createStart(SbgnArc_t* sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sa->createStart());
}


/*
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createEnd(SbgnArc_t* sa)
{
  if (sa == NULL)
  {
    return NULL;
  }

  return (SbgnPoint_t*)(sa->createEnd());
}


/*
 * Unsets the value of the "start" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetStart(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetStart() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "end" element of this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_unsetEnd(SbgnArc_t * sa)
{
  return (sa != NULL) ? sa->unsetEnd() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfGlyphs(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getListOfGlyphs() : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyph(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->getGlyph(n) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArc_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphById(SbgnArc_t* sa, const char *sid)
{
  return (sa != NULL && sid != NULL) ? sa->getGlyph(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArc_t based on the CompartmentRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByCompartmentRef(SbgnArc_t* sa, const char *sid)
{
  return (sa != NULL && sid != NULL) ? sa->getGlyphByCompartmentRef(sid) :
    NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArc_t based on the MapRef to which it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByMapRef(SbgnArc_t* sa, const char *sid)
{
  return (sa != NULL && sid != NULL) ? sa->getGlyphByMapRef(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnArc_t based on the TagRef to which it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_getGlyphByTagRef(SbgnArc_t* sa, const char *sid)
{
  return (sa != NULL && sid != NULL) ? sa->getGlyphByTagRef(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnGlyph_t to this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_addGlyph(SbgnArc_t* sa, const SbgnGlyph_t* sg)
{
  return (sa != NULL) ? sa->addGlyph(sg) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnGlyph_t objects in this SbgnArc_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumGlyphs(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnGlyph_t object, adds it to this SbgnArc_t object and
 * returns the SbgnGlyph_t object created.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_createGlyph(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->createGlyph() : NULL;
}


/*
 * Removes the nth SbgnGlyph_t from this SbgnArc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_removeGlyph(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->removeGlyph(n) : NULL;
}


/*
 * Removes the SbgnGlyph_t from this SbgnArc_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnArc_removeGlyphById(SbgnArc_t* sa, const char* sid)
{
  return (sa != NULL && sid != NULL) ? sa->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnPoint_t objects from this SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfNexts(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getListOfNexts() : NULL;
}


/*
 * Get a SbgnPoint_t from the SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_getNext(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->getNext(n) : NULL;
}


/*
 * Adds a copy of the given SbgnPoint_t to this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_addNext(SbgnArc_t* sa, const SbgnPoint_t* sp)
{
  return (sa != NULL) ? sa->addNext(sp) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnPoint_t objects in this SbgnArc_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumNexts(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getNumNexts() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnPoint_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPoint_t object created.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_createNext(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->createNext() : NULL;
}


/*
 * Removes the nth SbgnPoint_t from this SbgnArc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnPoint_t*
SbgnArc_removeNext(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->removeNext(n) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnPort_t objects from this SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnArc_getListOfPorts(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getListOfPorts() : NULL;
}


/*
 * Get a SbgnPort_t from the SbgnArc_t.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_getPort(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->getPort(n) : NULL;
}


/*
 * Get a SbgnPort_t from the SbgnArc_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_getPortById(SbgnArc_t* sa, const char *sid)
{
  return (sa != NULL && sid != NULL) ? sa->getPort(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnPort_t to this SbgnArc_t.
 */
LIBSBGN_EXTERN
int
SbgnArc_addPort(SbgnArc_t* sa, const SbgnPort_t* sp)
{
  return (sa != NULL) ? sa->addPort(sp) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnPort_t objects in this SbgnArc_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnArc_getNumPorts(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->getNumPorts() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnPort_t object, adds it to this SbgnArc_t object and
 * returns the SbgnPort_t object created.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_createPort(SbgnArc_t* sa)
{
  return (sa != NULL) ? sa->createPort() : NULL;
}


/*
 * Removes the nth SbgnPort_t from this SbgnArc_t and returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_removePort(SbgnArc_t* sa, unsigned int n)
{
  return (sa != NULL) ? sa->removePort(n) : NULL;
}


/*
 * Removes the SbgnPort_t from this SbgnArc_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnArc_removePortById(SbgnArc_t* sa, const char* sid)
{
  return (sa != NULL && sid != NULL) ? sa->removePort(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnArc_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnArc_hasRequiredAttributes(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnArc_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnArc_hasRequiredElements(const SbgnArc_t * sa)
{
  return (sa != NULL) ? static_cast<int>(sa->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



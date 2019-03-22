/**
 * @file SbgnGlyph.cpp
 * @brief Implementation of the SbgnGlyph class.
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
#include <sbgn/SbgnGlyph.h>
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnGlyph using the given SBGN Level and @ p version values.
 */
SbgnGlyph::SbgnGlyph(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mClazz ("")
  , mCompartmentRef ("")
  , mCompartmentOrder (util_NaN())
  , mIsSetCompartmentOrder (false)
  , mOrientation (SBGNML_ORIENTATION_INVALID)
  , mLabel (NULL)
  , mState (NULL)
  , mClone (NULL)
  , mCallout (NULL)
  , mEntity (NULL)
  , mBBox (NULL)
  , mGlyphs (new SbgnListOfGlyphs (level, version))
  , mPorts (level, version)
  , mMapRef ("")
  , mTagRef ("")
  , mElementName("glyph")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
  connectToChild();
}


/*
 * Creates a new SbgnGlyph using the given SbgnNamespaces object @p sbgnns.
 */
SbgnGlyph::SbgnGlyph(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mClazz ("")
  , mCompartmentRef ("")
  , mCompartmentOrder (util_NaN())
  , mIsSetCompartmentOrder (false)
  , mOrientation (SBGNML_ORIENTATION_INVALID)
  , mLabel (NULL)
  , mState (NULL)
  , mClone (NULL)
  , mCallout (NULL)
  , mEntity (NULL)
  , mBBox (NULL)
  , mGlyphs (new SbgnListOfGlyphs (sbgnns))
  , mPorts (sbgnns)
  , mMapRef ("")
  , mTagRef ("")
  , mElementName("glyph")
{
  setElementNamespace(sbgnns->getURI());
  connectToChild();
}


/*
 * Copy constructor for SbgnGlyph.
 */
SbgnGlyph::SbgnGlyph(const SbgnGlyph& orig)
  : SbgnBase( orig )
  , mClazz ( orig.mClazz )
  , mCompartmentRef ( orig.mCompartmentRef )
  , mCompartmentOrder ( orig.mCompartmentOrder )
  , mIsSetCompartmentOrder ( orig.mIsSetCompartmentOrder )
  , mOrientation ( orig.mOrientation )
  , mLabel ( NULL )
  , mState ( NULL )
  , mClone ( NULL )
  , mCallout ( NULL )
  , mEntity ( NULL )
  , mBBox ( NULL )
  , mGlyphs ( NULL )
  , mPorts ( orig.mPorts )
  , mMapRef ( orig.mMapRef )
  , mTagRef ( orig.mTagRef )
  , mElementName ( orig.mElementName )
{
  if (orig.mLabel != NULL)
  {
    mLabel = orig.mLabel->clone();
  }

  if (orig.mState != NULL)
  {
    mState = orig.mState->clone();
  }

  if (orig.mClone != NULL)
  {
    mClone = orig.mClone->clone();
  }

  if (orig.mCallout != NULL)
  {
    mCallout = orig.mCallout->clone();
  }

  if (orig.mEntity != NULL)
  {
    mEntity = orig.mEntity->clone();
  }

  if (orig.mBBox != NULL)
  {
    mBBox = orig.mBBox->clone();
  }

  if (orig.mGlyphs != NULL)
  {
    mGlyphs = orig.mGlyphs->clone();
  }

  connectToChild();
}


/*
 * Assignment operator for SbgnGlyph.
 */
SbgnGlyph&
SbgnGlyph::operator=(const SbgnGlyph& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mClazz = rhs.mClazz;
    mCompartmentRef = rhs.mCompartmentRef;
    mCompartmentOrder = rhs.mCompartmentOrder;
    mIsSetCompartmentOrder = rhs.mIsSetCompartmentOrder;
    mOrientation = rhs.mOrientation;
    mPorts = rhs.mPorts;
    mMapRef = rhs.mMapRef;
    mTagRef = rhs.mTagRef;
    mElementName = rhs.mElementName;
    delete mGlyphs;
    if (rhs.mGlyphs != NULL)
    {
      mGlyphs = rhs.mGlyphs->clone();
    }
    else
    {
      mGlyphs = NULL;
    }

    delete mLabel;
    if (rhs.mLabel != NULL)
    {
      mLabel = rhs.mLabel->clone();
    }
    else
    {
      mLabel = NULL;
    }

    delete mState;
    if (rhs.mState != NULL)
    {
      mState = rhs.mState->clone();
    }
    else
    {
      mState = NULL;
    }

    delete mClone;
    if (rhs.mClone != NULL)
    {
      mClone = rhs.mClone->clone();
    }
    else
    {
      mClone = NULL;
    }

    delete mCallout;
    if (rhs.mCallout != NULL)
    {
      mCallout = rhs.mCallout->clone();
    }
    else
    {
      mCallout = NULL;
    }

    delete mEntity;
    if (rhs.mEntity != NULL)
    {
      mEntity = rhs.mEntity->clone();
    }
    else
    {
      mEntity = NULL;
    }

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
 * Creates and returns a deep copy of this SbgnGlyph object.
 */
SbgnGlyph*
SbgnGlyph::clone() const
{
  return new SbgnGlyph(*this);
}


/*
 * Destructor for SbgnGlyph.
 */
SbgnGlyph::~SbgnGlyph()
{
  delete mLabel;
  mLabel = NULL;
  delete mState;
  mState = NULL;
  delete mClone;
  mClone = NULL;
  delete mCallout;
  mCallout = NULL;
  delete mEntity;
  mEntity = NULL;
  delete mBBox;
  mBBox = NULL;
  delete mGlyphs;
  mGlyphs = NULL;
}


/*
 * Returns the value of the "id" attribute of this SbgnGlyph.
 */
const std::string&
SbgnGlyph::getId() const
{
  return mId;
}


/*
 * Returns the value of the "class" attribute of this SbgnGlyph.
 */
const std::string&
SbgnGlyph::getClazz() const
{
  return mClazz;
}


/*
 * Returns the value of the "compartmentRef" attribute of this SbgnGlyph.
 */
const std::string&
SbgnGlyph::getCompartmentRef() const
{
  return mCompartmentRef;
}


/*
 * Returns the value of the "compartmentOrder" attribute of this SbgnGlyph.
 */
double
SbgnGlyph::getCompartmentOrder() const
{
  return mCompartmentOrder;
}


/*
 * Returns the value of the "orientation" attribute of this SbgnGlyph.
 */
Orientation_t
SbgnGlyph::getOrientation() const
{
  return mOrientation;
}


/*
 * Returns the value of the "orientation" attribute of this SbgnGlyph.
 */
std::string
SbgnGlyph::getOrientationAsString() const
{
  std::string code_str = Orientation_toString(mOrientation);
  return code_str;
}


/*
 * Returns the value of the "mapRef" attribute of this SbgnGlyph.
 */
const std::string&
SbgnGlyph::getMapRef() const
{
  return mMapRef;
}


/*
 * Returns the value of the "tagRef" attribute of this SbgnGlyph.
 */
const std::string&
SbgnGlyph::getTagRef() const
{
  return mTagRef;
}


/*
 * Predicate returning @c true if this SbgnGlyph's "id" attribute is set.
 */
bool
SbgnGlyph::isSetId() const
{
  return (mId.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "class" attribute is set.
 */
bool
SbgnGlyph::isSetClazz() const
{
  return (mClazz.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "compartmentRef" attribute
 * is set.
 */
bool
SbgnGlyph::isSetCompartmentRef() const
{
  return (mCompartmentRef.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "compartmentOrder" attribute
 * is set.
 */
bool
SbgnGlyph::isSetCompartmentOrder() const
{
  return mIsSetCompartmentOrder;
}


/*
 * Predicate returning @c true if this SbgnGlyph's "orientation" attribute is
 * set.
 */
bool
SbgnGlyph::isSetOrientation() const
{
  return (mOrientation != SBGNML_ORIENTATION_INVALID);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "mapRef" attribute is set.
 */
bool
SbgnGlyph::isSetMapRef() const
{
  return (mMapRef.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "tagRef" attribute is set.
 */
bool
SbgnGlyph::isSetTagRef() const
{
  return (mTagRef.empty() == false);
}


/*
 * Sets the value of the "id" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setId(const std::string& id)
{
  mId = id;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "class" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setClazz(const std::string& clazz)
{
  mClazz = clazz;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "compartmentRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setCompartmentRef(const std::string& compartmentRef)
{
  if (!(SyntaxChecker::isValidInternalSId(compartmentRef)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mCompartmentRef = compartmentRef;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "compartmentOrder" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setCompartmentOrder(double compartmentOrder)
{
  mCompartmentOrder = compartmentOrder;
  mIsSetCompartmentOrder = true;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "orientation" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setOrientation(const Orientation_t orientation)
{
  if (Orientation_isValid(orientation) == 0)
  {
    mOrientation = SBGNML_ORIENTATION_INVALID;
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mOrientation = orientation;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "orientation" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setOrientation(const std::string& orientation)
{
  mOrientation = Orientation_fromString(orientation.c_str());

  if (mOrientation == SBGNML_ORIENTATION_INVALID)
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }

  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "mapRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setMapRef(const std::string& mapRef)
{
  if (!(SyntaxChecker::isValidInternalSId(mapRef)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mMapRef = mapRef;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "tagRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setTagRef(const std::string& tagRef)
{
  if (!(SyntaxChecker::isValidInternalSId(tagRef)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mTagRef = tagRef;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Unsets the value of the "id" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetId()
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
 * Unsets the value of the "class" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetClazz()
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
 * Unsets the value of the "compartmentRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetCompartmentRef()
{
  mCompartmentRef.erase();

  if (mCompartmentRef.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "compartmentOrder" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetCompartmentOrder()
{
  mCompartmentOrder = util_NaN();
  mIsSetCompartmentOrder = false;

  if (isSetCompartmentOrder() == false)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "orientation" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetOrientation()
{
  mOrientation = SBGNML_ORIENTATION_INVALID;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "mapRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetMapRef()
{
  mMapRef.erase();

  if (mMapRef.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "tagRef" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetTagRef()
{
  mTagRef.erase();

  if (mTagRef.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the value of the "label" element of this SbgnGlyph.
 */
const SbgnLabel*
SbgnGlyph::getLabel() const
{
  return mLabel;
}


/*
 * Returns the value of the "label" element of this SbgnGlyph.
 */
SbgnLabel*
SbgnGlyph::getLabel()
{
  return mLabel;
}


/*
 * Returns the value of the "state" element of this SbgnGlyph.
 */
const SbgnState*
SbgnGlyph::getState() const
{
  return mState;
}


/*
 * Returns the value of the "state" element of this SbgnGlyph.
 */
SbgnState*
SbgnGlyph::getState()
{
  return mState;
}


/*
 * Returns the value of the "clone" element of this SbgnGlyph.
 */
const SbgnGlyph*
SbgnGlyph::getClone() const
{
  return mClone;
}


/*
 * Returns the value of the "clone" element of this SbgnGlyph.
 */
SbgnGlyph*
SbgnGlyph::getClone()
{
  return mClone;
}


/*
 * Returns the value of the "callout" element of this SbgnGlyph.
 */
const SbgnCallout*
SbgnGlyph::getCallout() const
{
  return mCallout;
}


/*
 * Returns the value of the "callout" element of this SbgnGlyph.
 */
SbgnCallout*
SbgnGlyph::getCallout()
{
  return mCallout;
}


/*
 * Returns the value of the "entity" element of this SbgnGlyph.
 */
const SbgnEntity*
SbgnGlyph::getEntity() const
{
  return mEntity;
}


/*
 * Returns the value of the "entity" element of this SbgnGlyph.
 */
SbgnEntity*
SbgnGlyph::getEntity()
{
  return mEntity;
}


/*
 * Returns the value of the "bbox" element of this SbgnGlyph.
 */
const SbgnBBox*
SbgnGlyph::getBBox() const
{
  return mBBox;
}


/*
 * Returns the value of the "bbox" element of this SbgnGlyph.
 */
SbgnBBox*
SbgnGlyph::getBBox()
{
  return mBBox;
}


/*
 * Predicate returning @c true if this SbgnGlyph's "label" element is set.
 */
bool
SbgnGlyph::isSetLabel() const
{
  return (mLabel != NULL);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "state" element is set.
 */
bool
SbgnGlyph::isSetState() const
{
  return (mState != NULL);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "clone" element is set.
 */
bool
SbgnGlyph::isSetClone() const
{
  return (mClone != NULL);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "callout" element is set.
 */
bool
SbgnGlyph::isSetCallout() const
{
  return (mCallout != NULL);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "entity" element is set.
 */
bool
SbgnGlyph::isSetEntity() const
{
  return (mEntity != NULL);
}


/*
 * Predicate returning @c true if this SbgnGlyph's "bbox" element is set.
 */
bool
SbgnGlyph::isSetBBox() const
{
  return (mBBox != NULL);
}


/*
 * Sets the value of the "label" element of this SbgnGlyph.
 */
int
SbgnGlyph::setLabel(const SbgnLabel* label)
{
  if (mLabel == label)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (label == NULL)
  {
    delete mLabel;
    mLabel = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mLabel;
    mLabel = (label != NULL) ? label->clone() : NULL;
    if (mLabel != NULL)
    {
      mLabel->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "state" element of this SbgnGlyph.
 */
int
SbgnGlyph::setState(const SbgnState* state)
{
  if (mState == state)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (state == NULL)
  {
    delete mState;
    mState = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mState;
    mState = (state != NULL) ? state->clone() : NULL;
    if (mState != NULL)
    {
      mState->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "clone" element of this SbgnGlyph.
 */
int
SbgnGlyph::setClone(const SbgnGlyph* clone)
{
  if (mClone == clone)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (clone == NULL)
  {
    delete mClone;
    mClone = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mClone;
    mClone = (clone != NULL) ? clone->clone() : NULL;
    if (mClone != NULL)
    {
      mClone->setElementName("clone");
      mClone->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "callout" element of this SbgnGlyph.
 */
int
SbgnGlyph::setCallout(const SbgnCallout* callout)
{
  if (mCallout == callout)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (callout == NULL)
  {
    delete mCallout;
    mCallout = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mCallout;
    mCallout = (callout != NULL) ? callout->clone() : NULL;
    if (mCallout != NULL)
    {
      mCallout->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "entity" element of this SbgnGlyph.
 */
int
SbgnGlyph::setEntity(const SbgnEntity* entity)
{
  if (mEntity == entity)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (entity == NULL)
  {
    delete mEntity;
    mEntity = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    delete mEntity;
    mEntity = (entity != NULL) ? entity->clone() : NULL;
    if (mEntity != NULL)
    {
      mEntity->connectToParent(this);
    }

    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the value of the "bbox" element of this SbgnGlyph.
 */
int
SbgnGlyph::setBBox(const SbgnBBox* bbox)
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
 * Creates a new SbgnLabel object, adds it to this SbgnGlyph object and returns
 * the SbgnLabel object created.
 */
SbgnLabel*
SbgnGlyph::createLabel()
{
  if (mLabel != NULL)
  {
    delete mLabel;
  }

  mLabel = new SbgnLabel(getSbgnNamespaces());

  connectToChild();

  return mLabel;
}


/*
 * Creates a new SbgnState object, adds it to this SbgnGlyph object and returns
 * the SbgnState object created.
 */
SbgnState*
SbgnGlyph::createState()
{
  if (mState != NULL)
  {
    delete mState;
  }

  mState = new SbgnState(getSbgnNamespaces());

  connectToChild();

  return mState;
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnGlyph object and returns
 * the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnGlyph::createClone()
{
  if (mClone != NULL)
  {
    delete mClone;
  }

  mClone = new SbgnGlyph(getSbgnNamespaces());

  mClone->setElementName("clone");

  connectToChild();

  return mClone;
}


/*
 * Creates a new SbgnCallout object, adds it to this SbgnGlyph object and
 * returns the SbgnCallout object created.
 */
SbgnCallout*
SbgnGlyph::createCallout()
{
  if (mCallout != NULL)
  {
    delete mCallout;
  }

  mCallout = new SbgnCallout(getSbgnNamespaces());

  connectToChild();

  return mCallout;
}


/*
 * Creates a new SbgnEntity object, adds it to this SbgnGlyph object and
 * returns the SbgnEntity object created.
 */
SbgnEntity*
SbgnGlyph::createEntity()
{
  if (mEntity != NULL)
  {
    delete mEntity;
  }

  mEntity = new SbgnEntity(getSbgnNamespaces());

  connectToChild();

  return mEntity;
}


/*
 * Creates a new SbgnBBox object, adds it to this SbgnGlyph object and returns
 * the SbgnBBox object created.
 */
SbgnBBox*
SbgnGlyph::createBBox()
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
 * Unsets the value of the "label" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetLabel()
{
  delete mLabel;
  mLabel = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "state" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetState()
{
  delete mState;
  mState = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "clone" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetClone()
{
  delete mClone;
  mClone = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "callout" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetCallout()
{
  delete mCallout;
  mCallout = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "entity" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetEntity()
{
  delete mEntity;
  mEntity = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "bbox" element of this SbgnGlyph.
 */
int
SbgnGlyph::unsetBBox()
{
  delete mBBox;
  mBBox = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Returns the SbgnListOfGlyphs * from this SbgnGlyph.
 */
const SbgnListOfGlyphs *
SbgnGlyph::getListOfGlyphs() const
{
  return mGlyphs;
}


/*
 * Returns the SbgnListOfGlyphs * from this SbgnGlyph.
 */
SbgnListOfGlyphs *
SbgnGlyph::getListOfGlyphs()
{
  return mGlyphs;
}


/*
 * Get a SbgnGlyph from the SbgnGlyph.
 */
SbgnGlyph*
SbgnGlyph::getGlyph(unsigned int n)
{
  return mGlyphs->get(n);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph.
 */
const SbgnGlyph*
SbgnGlyph::getGlyph(unsigned int n) const
{
  return mGlyphs->get(n);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on its identifier.
 */
SbgnGlyph*
SbgnGlyph::getGlyph(const std::string& sid)
{
  return mGlyphs->get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on its identifier.
 */
const SbgnGlyph*
SbgnGlyph::getGlyph(const std::string& sid) const
{
  return mGlyphs->get(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the CompartmentRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnGlyph::getGlyphByCompartmentRef(const std::string& sid) const
{
  return mGlyphs->getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the CompartmentRef to which it
 * refers.
 */
SbgnGlyph*
SbgnGlyph::getGlyphByCompartmentRef(const std::string& sid)
{
  return mGlyphs->getByCompartmentRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the MapRef to which it refers.
 */
const SbgnGlyph*
SbgnGlyph::getGlyphByMapRef(const std::string& sid) const
{
  return mGlyphs->getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the MapRef to which it refers.
 */
SbgnGlyph*
SbgnGlyph::getGlyphByMapRef(const std::string& sid)
{
  return mGlyphs->getByMapRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the TagRef to which it refers.
 */
const SbgnGlyph*
SbgnGlyph::getGlyphByTagRef(const std::string& sid) const
{
  return mGlyphs->getByTagRef(sid);
}


/*
 * Get a SbgnGlyph from the SbgnGlyph based on the TagRef to which it refers.
 */
SbgnGlyph*
SbgnGlyph::getGlyphByTagRef(const std::string& sid)
{
  return mGlyphs->getByTagRef(sid);
}


/*
 * Adds a copy of the given SbgnGlyph to this SbgnGlyph.
 */
int
SbgnGlyph::addGlyph(const SbgnGlyph* sg1)
{
  if (sg1 == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (sg1->hasRequiredAttributes() == false)
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != sg1->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != sg1->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (matchesRequiredSbgnNamespacesForAddition(static_cast<const
    SbgnBase*>(sg1)) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else if (sg1->isSetId() && (mGlyphs->get(sg1->getId())) != NULL)
  {
    return LIBSBGN_DUPLICATE_OBJECT_ID;
  }
  else
  {
    return mGlyphs->append(sg1);
  }
}


/*
 * Get the number of SbgnGlyph objects in this SbgnGlyph.
 */
unsigned int
SbgnGlyph::getNumGlyphs() const
{
  return mGlyphs->size();
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnGlyph object and returns
 * the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnGlyph::createGlyph()
{
  SbgnGlyph* sg1 = NULL;

  try
  {
    sg1 = new SbgnGlyph(getSbgnNamespaces());
  }
  catch (...)
  {
  }

  if (sg1 != NULL)
  {
    mGlyphs->appendAndOwn(sg1);
  }

  return sg1;
}


/*
 * Removes the nth SbgnGlyph from this SbgnGlyph and returns a pointer to it.
 */
SbgnGlyph*
SbgnGlyph::removeGlyph(unsigned int n)
{
  return mGlyphs->remove(n);
}


/*
 * Removes the SbgnGlyph from this SbgnGlyph based on its identifier and
 * returns a pointer to it.
 */
SbgnGlyph*
SbgnGlyph::removeGlyph(const std::string& sid)
{
  return mGlyphs->remove(sid);
}


/*
 * Returns the SbgnListOfPorts from this SbgnGlyph.
 */
const SbgnListOfPorts*
SbgnGlyph::getListOfPorts() const
{
  return &mPorts;
}


/*
 * Returns the SbgnListOfPorts from this SbgnGlyph.
 */
SbgnListOfPorts*
SbgnGlyph::getListOfPorts()
{
  return &mPorts;
}


/*
 * Get a SbgnPort from the SbgnGlyph.
 */
SbgnPort*
SbgnGlyph::getPort(unsigned int n)
{
  return mPorts.get(n);
}


/*
 * Get a SbgnPort from the SbgnGlyph.
 */
const SbgnPort*
SbgnGlyph::getPort(unsigned int n) const
{
  return mPorts.get(n);
}


/*
 * Get a SbgnPort from the SbgnGlyph based on its identifier.
 */
SbgnPort*
SbgnGlyph::getPort(const std::string& sid)
{
  return mPorts.get(sid);
}


/*
 * Get a SbgnPort from the SbgnGlyph based on its identifier.
 */
const SbgnPort*
SbgnGlyph::getPort(const std::string& sid) const
{
  return mPorts.get(sid);
}


/*
 * Adds a copy of the given SbgnPort to this SbgnGlyph.
 */
int
SbgnGlyph::addPort(const SbgnPort* sp)
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
 * Get the number of SbgnPort objects in this SbgnGlyph.
 */
unsigned int
SbgnGlyph::getNumPorts() const
{
  return mPorts.size();
}


/*
 * Creates a new SbgnPort object, adds it to this SbgnGlyph object and returns
 * the SbgnPort object created.
 */
SbgnPort*
SbgnGlyph::createPort()
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
 * Removes the nth SbgnPort from this SbgnGlyph and returns a pointer to it.
 */
SbgnPort*
SbgnGlyph::removePort(unsigned int n)
{
  return mPorts.remove(n);
}


/*
 * Removes the SbgnPort from this SbgnGlyph based on its identifier and returns
 * a pointer to it.
 */
SbgnPort*
SbgnGlyph::removePort(const std::string& sid)
{
  return mPorts.remove(sid);
}


/*
 * @copydoc doc_renamesidref_common
 */
void
SbgnGlyph::renameSIdRefs(const std::string& oldid, const std::string& newid)
{
  if (isSetCompartmentRef() && mCompartmentRef == oldid)
  {
    setCompartmentRef(newid);
  }

  if (isSetMapRef() && mMapRef == oldid)
  {
    setMapRef(newid);
  }

  if (isSetTagRef() && mTagRef == oldid)
  {
    setTagRef(newid);
  }
}


/*
 * Returns the XML element name of this SbgnGlyph object.
 */
const std::string&
SbgnGlyph::getElementName() const
{
  return mElementName;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the XML name of this SbgnGlyph object.
 */
void
SbgnGlyph::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBGN type code for this SbgnGlyph object.
 */
int
SbgnGlyph::getTypeCode() const
{
  return SBGN_SBGNML_GLYPH;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnGlyph object have been set.
 */
bool
SbgnGlyph::hasRequiredAttributes() const
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

  return allPresent;
}


/*
 * Predicate returning @c true if all the required elements for this SbgnGlyph
 * object have been set.
 */
bool
SbgnGlyph::hasRequiredElements() const
{
  bool allPresent = true;

  if (isSetBBox() == false)
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
SbgnGlyph::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);

  if (isSetLabel() == true)
  {
    mLabel->write(stream);
  }

  if (isSetState() == true)
  {
    mState->write(stream);
  }

  if (isSetClone() == true)
  {
    mClone->write(stream);
  }

  if (isSetCallout() == true)
  {
    mCallout->write(stream);
  }

  if (isSetEntity() == true)
  {
    mEntity->write(stream);
  }

  if (isSetBBox() == true)
  {
    mBBox->write(stream);
  }

  for (unsigned int i = 0; i < getNumGlyphs(); i++)
  {
    getGlyph(i)->write(stream);
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
SbgnGlyph::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnGlyph::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);

  if (mLabel != NULL)
  {
    mLabel->setSbgnDocument(d);
  }

  if (mState != NULL)
  {
    mState->setSbgnDocument(d);
  }

  if (mClone != NULL)
  {
    mClone->setSbgnDocument(d);
  }

  if (mCallout != NULL)
  {
    mCallout->setSbgnDocument(d);
  }

  if (mEntity != NULL)
  {
    mEntity->setSbgnDocument(d);
  }

  if (mBBox != NULL)
  {
    mBBox->setSbgnDocument(d);
  }

  mGlyphs->setSbgnDocument(d);

  mPorts.setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Connects to child elements
 */
void
SbgnGlyph::connectToChild()
{
  SbgnBase::connectToChild();

  if (mLabel != NULL)
  {
    mLabel->connectToParent(this);
  }

  if (mState != NULL)
  {
    mState->connectToParent(this);
  }

  if (mClone != NULL)
  {
    mClone->connectToParent(this);
  }

  if (mCallout != NULL)
  {
    mCallout->connectToParent(this);
  }

  if (mEntity != NULL)
  {
    mEntity->connectToParent(this);
  }

  if (mBBox != NULL)
  {
    mBBox->connectToParent(this);
  }

  mGlyphs->connectToParent(this);

  mPorts.connectToParent(this);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "compartmentOrder")
  {
    value = getCompartmentOrder();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::getAttribute(const std::string& attributeName,
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
  else if (attributeName == "compartmentRef")
  {
    value = getCompartmentRef();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "orientation")
  {
    value = getOrientationAsString();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "mapRef")
  {
    value = getMapRef();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "tagRef")
  {
    value = getTagRef();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnGlyph's attribute "attributeName" is
 * set.
 */
bool
SbgnGlyph::isSetAttribute(const std::string& attributeName) const
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
  else if (attributeName == "compartmentRef")
  {
    value = isSetCompartmentRef();
  }
  else if (attributeName == "compartmentOrder")
  {
    value = isSetCompartmentOrder();
  }
  else if (attributeName == "orientation")
  {
    value = isSetOrientation();
  }
  else if (attributeName == "mapRef")
  {
    value = isSetMapRef();
  }
  else if (attributeName == "tagRef")
  {
    value = isSetTagRef();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "compartmentOrder")
  {
    return_value = setCompartmentOrder(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::setAttribute(const std::string& attributeName,
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
  else if (attributeName == "compartmentRef")
  {
    return_value = setCompartmentRef(value);
  }
  else if (attributeName == "orientation")
  {
    return_value = setOrientation(value);
  }
  else if (attributeName == "mapRef")
  {
    return_value = setMapRef(value);
  }
  else if (attributeName == "tagRef")
  {
    return_value = setTagRef(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnGlyph.
 */
int
SbgnGlyph::unsetAttribute(const std::string& attributeName)
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
  else if (attributeName == "compartmentRef")
  {
    value = unsetCompartmentRef();
  }
  else if (attributeName == "compartmentOrder")
  {
    value = unsetCompartmentOrder();
  }
  else if (attributeName == "orientation")
  {
    value = unsetOrientation();
  }
  else if (attributeName == "mapRef")
  {
    value = unsetMapRef();
  }
  else if (attributeName == "tagRef")
  {
    value = unsetTagRef();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Creates and returns an new "elementName" object in this SbgnGlyph.
 */
SbgnBase*
SbgnGlyph::createChildObject(const std::string& elementName)
{
  SbgnBase* obj = NULL;

  if (elementName == "label")
  {
    return createLabel();
  }
  else if (elementName == "state")
  {
    return createState();
  }
  else if (elementName == "clone")
  {
    return createClone();
  }
  else if (elementName == "callout")
  {
    return createCallout();
  }
  else if (elementName == "entity")
  {
    return createEntity();
  }
  else if (elementName == "bbox")
  {
    return createBBox();
  }
  else if (elementName == "glyph")
  {
    return createGlyph();
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
 * Adds a new "elementName" object to this SbgnGlyph.
 */
int
SbgnGlyph::addChildObject(const std::string& elementName,
                          const SbgnBase* element)
{
  if (elementName == "label" && element->getTypeCode() == SBGN_SBGNML_LABEL)
  {
    return setLabel((const SbgnLabel*)(element));
  }
  else if (elementName == "state" && element->getTypeCode() ==
    SBGN_SBGNML_STATE)
  {
    return setState((const SbgnState*)(element));
  }
  else if (elementName == "clone" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return setClone((const SbgnGlyph*)(element));
  }
  else if (elementName == "callout" && element->getTypeCode() ==
    SBGN_SBGNML_CALLOUT)
  {
    return setCallout((const SbgnCallout*)(element));
  }
  else if (elementName == "entity" && element->getTypeCode() ==
    SBGN_SBGNML_ENTITY)
  {
    return setEntity((const SbgnEntity*)(element));
  }
  else if (elementName == "bbox" && element->getTypeCode() == SBGN_SBGNML_BBOX)
  {
    return setBBox((const SbgnBBox*)(element));
  }
  else if (elementName == "glyph" && element->getTypeCode() ==
    SBGN_SBGNML_GLYPH)
  {
    return addGlyph((const SbgnGlyph*)(element));
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
 * SbgnGlyph.
 */
SbgnBase*
SbgnGlyph::removeChildObject(const std::string& elementName,
                             const std::string& id)
{
  if (elementName == "label")
  {
    SbgnLabel * obj = getLabel();
    if (unsetLabel() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "state")
  {
    SbgnState * obj = getState();
    if (unsetState() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "clone")
  {
    SbgnGlyph * obj = getClone();
    if (unsetClone() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "callout")
  {
    SbgnCallout * obj = getCallout();
    if (unsetCallout() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "entity")
  {
    SbgnEntity * obj = getEntity();
    if (unsetEntity() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "bbox")
  {
    SbgnBBox * obj = getBBox();
    if (unsetBBox() == LIBSBML_OPERATION_SUCCESS) return obj;
  }
  else if (elementName == "glyph")
  {
    return removeGlyph(id);
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
 * Returns the number of "elementName" in this SbgnGlyph.
 */
unsigned int
SbgnGlyph::getNumObjects(const std::string& elementName)
{
  unsigned int n = 0;

  if (elementName == "label")
  {
    if (isSetLabel())
    {
      return 1;
    }
  }
  else if (elementName == "state")
  {
    if (isSetState())
    {
      return 1;
    }
  }
  else if (elementName == "clone")
  {
    if (isSetClone())
    {
      return 1;
    }
  }
  else if (elementName == "callout")
  {
    if (isSetCallout())
    {
      return 1;
    }
  }
  else if (elementName == "entity")
  {
    if (isSetEntity())
    {
      return 1;
    }
  }
  else if (elementName == "bbox")
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
  else if (elementName == "port")
  {
    return getNumPorts();
  }

  return n;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Returns the nth object of "objectName" in this SbgnGlyph.
 */
SbgnBase*
SbgnGlyph::getObject(const std::string& elementName, unsigned int index)
{
  SbgnBase* obj = NULL;

  if (elementName == "label")
  {
    return getLabel();
  }
  else if (elementName == "state")
  {
    return getState();
  }
  else if (elementName == "clone")
  {
    return getClone();
  }
  else if (elementName == "callout")
  {
    return getCallout();
  }
  else if (elementName == "entity")
  {
    return getEntity();
  }
  else if (elementName == "bbox")
  {
    return getBBox();
  }
  else if (elementName == "glyph")
  {
    return getGlyph(index);
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
SbgnGlyph::getElementBySId(const std::string& id)
{
  if (id.empty())
  {
    return NULL;
  }

  SbgnBase* obj = NULL;

  if (mLabel != NULL)
  {
    if (mLabel->getId() == id)
    {
      return mLabel;
    }

    obj = mLabel->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mState != NULL)
  {
    if (mState->getId() == id)
    {
      return mState;
    }

    obj = mState->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mClone != NULL)
  {
    if (mClone->getId() == id)
    {
      return mClone;
    }

    obj = mClone->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mCallout != NULL)
  {
    if (mCallout->getId() == id)
    {
      return mCallout;
    }

    obj = mCallout->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

  if (mEntity != NULL)
  {
    if (mEntity->getId() == id)
    {
      return mEntity;
    }

    obj = mEntity->getElementBySId(id);
    if (obj != NULL)
    {
      return obj;
    }
  }

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

  obj = mGlyphs->getElementBySId(id);

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
SbgnGlyph::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  SbgnBase* obj = NULL;

  const std::string& name = stream.peek().getName();

  if (name == "label")
  {
    if (isSetLabel())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mLabel;
    mLabel = new SbgnLabel(getSbgnNamespaces());
    obj = mLabel;
  }
  else if (name == "state")
  {
    if (isSetState())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mState;
    mState = new SbgnState(getSbgnNamespaces());
    obj = mState;
  }
  else if (name == "clone")
  {
    if (isSetClone())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mClone;
    mClone = new SbgnGlyph(getSbgnNamespaces());
    mClone->setElementName(name);
    obj = mClone;
  }
  else if (name == "callout")
  {
    if (isSetCallout())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mCallout;
    mCallout = new SbgnCallout(getSbgnNamespaces());
    obj = mCallout;
  }
  else if (name == "entity")
  {
    if (isSetEntity())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mEntity;
    mEntity = new SbgnEntity(getSbgnNamespaces());
    obj = mEntity;
  }
  else if (name == "bbox")
  {
    if (isSetBBox())
    {
      getErrorLog()->logError(SbgnmlGlyphAllowedElements, getLevel(),
        getVersion());
    }

    delete mBBox;
    mBBox = new SbgnBBox(getSbgnNamespaces());
    obj = mBBox;
  }
  else if (name == "glyph")
  {
    obj = mGlyphs->createObject(stream);
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
SbgnGlyph::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("id");

  attributes.add("class");

  attributes.add("compartmentRef");

  attributes.add("compartmentOrder");

  attributes.add("orientation");

  attributes.add("mapRef");

  attributes.add("tagRef");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnGlyph::readAttributes(
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
    static_cast<SbgnListOfGlyphs*>(getParentSbgnObject())->size() < 2)
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
        log->logError(SbgnmlGlyphAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // id SId (use = "required" )
  // 

  assigned = attributes.readInto("id", mId);

  if (assigned == true)
  {
    if (mId.empty() == true)
    {
      logEmptyString(mId, level, version, "<SbgnGlyph>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mId) == false)
    {
      logError(SbgnmlIdSyntaxRule, level, version, "The id on the <" +
        getElementName() + "> is '" + mId + "', which does not conform to the "
          "syntax.");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'id' is missing from the "
      "<SbgnGlyph> element.";
    log->logError(SbgnmlGlyphAllowedAttributes, level, version, message);
  }

  // 
  // class string (use = "required" )
  // 

  assigned = attributes.readInto("class", mClazz);

  if (assigned == true)
  {
    if (mClazz.empty() == true)
    {
      logEmptyString(mClazz, level, version, "<SbgnGlyph>");
    }
  }
  else
  {
    std::string message = "Sbgnml attribute 'class' is missing from the "
      "<SbgnGlyph> element.";
    log->logError(SbgnmlGlyphAllowedAttributes, level, version, message);
  }

  // 
  // compartmentRef SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("compartmentRef", mCompartmentRef);

  if (assigned == true)
  {
    if (mCompartmentRef.empty() == true)
    {
      logEmptyString(mCompartmentRef, level, version, "<SbgnGlyph>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mCompartmentRef) == false)
    {
      std::string msg = "The compartmentRef attribute on the <" +
        getElementName() + ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mCompartmentRef + "', which does not conform to the "
        "syntax.";
      logError(SbgnmlGlyphCompartmentRefMustBeGlyph, level, version, msg);
    }
  }

  // 
  // compartmentOrder double (use = "optional" )
  // 

  numErrs = log->getNumErrors();
  mIsSetCompartmentOrder = attributes.readInto("compartmentOrder",
    mCompartmentOrder);

  if ( mIsSetCompartmentOrder == false)
  {
    if (log->getNumErrors() == numErrs + 1 &&
      log->contains(XMLAttributeTypeMismatch))
    {
      log->remove(XMLAttributeTypeMismatch);
      std::string message = "Sbgnml attribute 'compartmentOrder' from the "
        "<SbgnGlyph> element must be an integer.";
      log->logError(SbgnmlGlyphCompartmentOrderMustBeDouble, level, version,
        message);
    }
  }

  // 
  // orientation enum (use = "optional" )
  // 

  std::string orientation;
  assigned = attributes.readInto("orientation", orientation);

  if (assigned == true)
  {
    if (orientation.empty() == true)
    {
      logEmptyString(orientation, level, version, "<SbgnGlyph>");
    }
    else
    {
      mOrientation = Orientation_fromString(orientation.c_str());

      if (Orientation_isValid(mOrientation) == 0)
      {
        std::string msg = "The orientation on the <SbgnGlyph> ";

        if (isSetId())
        {
          msg += "with id '" + getId() + "'";
        }

        msg += "is '" + orientation + "', which is not a valid option.";

        log->logError(SbgnmlGlyphOrientationMustBeOrientationEnum, level,
          version, msg);
      }
    }
  }

  // 
  // mapRef SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("mapRef", mMapRef);

  if (assigned == true)
  {
    if (mMapRef.empty() == true)
    {
      logEmptyString(mMapRef, level, version, "<SbgnGlyph>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mMapRef) == false)
    {
      std::string msg = "The mapRef attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mMapRef + "', which does not conform to the syntax.";
      logError(SbgnmlGlyphMapRefMustBeMap, level, version, msg);
    }
  }

  // 
  // tagRef SIdRef (use = "optional" )
  // 

  assigned = attributes.readInto("tagRef", mTagRef);

  if (assigned == true)
  {
    if (mTagRef.empty() == true)
    {
      logEmptyString(mTagRef, level, version, "<SbgnGlyph>");
    }
    else if (SyntaxChecker::isValidSBMLSId(mTagRef) == false)
    {
      std::string msg = "The tagRef attribute on the <" + getElementName() +
        ">";
      if (isSetId())
      {
        msg += " with id '" + getId() + "'";
      }

      msg += " is '" + mTagRef + "', which does not conform to the syntax.";
      logError(SbgnmlGlyphTagRefMustBeGlyph, level, version, msg);
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnGlyph::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
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

  if (isSetCompartmentRef() == true)
  {
    stream.writeAttribute("compartmentRef", getPrefix(), mCompartmentRef);
  }

  if (isSetCompartmentOrder() == true)
  {
    stream.writeAttribute("compartmentOrder", getPrefix(), mCompartmentOrder);
  }

  if (isSetOrientation() == true)
  {
    stream.writeAttribute("orientation", getPrefix(),
      Orientation_toString(mOrientation));
  }

  if (isSetMapRef() == true)
  {
    stream.writeAttribute("mapRef", getPrefix(), mMapRef);
  }

  if (isSetTagRef() == true)
  {
    stream.writeAttribute("tagRef", getPrefix(), mTagRef);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnGlyph_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnGlyph_t *
SbgnGlyph_create(unsigned int level, unsigned int version)
{
  return new SbgnGlyph(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnGlyph_t object.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_clone(const SbgnGlyph_t* sg)
{
  if (sg != NULL)
  {
    return static_cast<SbgnGlyph_t*>(sg->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnGlyph_t object.
 */
LIBSBGN_EXTERN
void
SbgnGlyph_free(SbgnGlyph_t* sg)
{
  if (sg != NULL)
  {
    delete sg;
  }
}


/*
 * Returns the value of the "id" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getId(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return sg->getId().empty() ? NULL : safe_strdup(sg->getId().c_str());
}


/*
 * Returns the value of the "class" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getClazz(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return sg->getClazz().empty() ? NULL : safe_strdup(sg->getClazz().c_str());
}


/*
 * Returns the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getCompartmentRef(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return sg->getCompartmentRef().empty() ? NULL :
    safe_strdup(sg->getCompartmentRef().c_str());
}


/*
 * Returns the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
double
SbgnGlyph_getCompartmentOrder(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->getCompartmentOrder() : util_NaN();
}


/*
 * Returns the value of the "orientation" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
Orientation_t
SbgnGlyph_getOrientation(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return SBGNML_ORIENTATION_INVALID;
  }

  return sg->getOrientation();
}


/*
 * Returns the value of the "orientation" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getOrientationAsString(const SbgnGlyph_t * sg)
{
  return (char*)(Orientation_toString(sg->getOrientation()));
}


/*
 * Returns the value of the "mapRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getMapRef(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return sg->getMapRef().empty() ? NULL : safe_strdup(sg->getMapRef().c_str());
}


/*
 * Returns the value of the "tagRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
char *
SbgnGlyph_getTagRef(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return sg->getTagRef().empty() ? NULL : safe_strdup(sg->getTagRef().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "id" attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetId(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetId()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "class" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetClazz(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetClazz()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "compartmentRef"
 * attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCompartmentRef(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetCompartmentRef()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "compartmentOrder"
 * attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCompartmentOrder(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetCompartmentOrder()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "orientation"
 * attribute is set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetOrientation(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetOrientation()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "mapRef" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetMapRef(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetMapRef()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "tagRef" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetTagRef(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetTagRef()) : 0;
}


/*
 * Sets the value of the "id" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setId(SbgnGlyph_t * sg, const char * id)
{
  return (sg != NULL) ? sg->setId(id) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "class" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setClazz(SbgnGlyph_t * sg, const char * clazz)
{
  return (sg != NULL) ? sg->setClazz(clazz) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCompartmentRef(SbgnGlyph_t * sg, const char * compartmentRef)
{
  return (sg != NULL) ? sg->setCompartmentRef(compartmentRef) :
    LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCompartmentOrder(SbgnGlyph_t * sg, double compartmentOrder)
{
  return (sg != NULL) ? sg->setCompartmentOrder(compartmentOrder) :
    LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "orientation" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setOrientation(SbgnGlyph_t * sg, Orientation_t orientation)
{
  return (sg != NULL) ? sg->setOrientation(orientation) :
    LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "orientation" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setOrientationAsString(SbgnGlyph_t * sg, const char * orientation)
{
  return (sg != NULL) ? sg->setOrientation(orientation):
    LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "mapRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setMapRef(SbgnGlyph_t * sg, const char * mapRef)
{
  return (sg != NULL) ? sg->setMapRef(mapRef) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "tagRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setTagRef(SbgnGlyph_t * sg, const char * tagRef)
{
  return (sg != NULL) ? sg->setTagRef(tagRef) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "id" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetId(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetId() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "class" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetClazz(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetClazz() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "compartmentRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCompartmentRef(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetCompartmentRef() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "compartmentOrder" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCompartmentOrder(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetCompartmentOrder() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "orientation" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetOrientation(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetOrientation() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "mapRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetMapRef(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetMapRef() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "tagRef" attribute of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetTagRef(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetTagRef() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns the value of the "label" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnLabel_t*
SbgnGlyph_getLabel(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnLabel_t*)(sg->getLabel());
}


/*
 * Returns the value of the "state" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnState_t*
SbgnGlyph_getState(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnState_t*)(sg->getState());
}


/*
 * Returns the value of the "clone" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnGlyph_t*
SbgnGlyph_getClone(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnGlyph_t*)(sg->getClone());
}


/*
 * Returns the value of the "callout" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnCallout_t*
SbgnGlyph_getCallout(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnCallout_t*)(sg->getCallout());
}


/*
 * Returns the value of the "entity" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnEntity_t*
SbgnGlyph_getEntity(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnEntity_t*)(sg->getEntity());
}


/*
 * Returns the value of the "bbox" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
const SbgnBBox_t*
SbgnGlyph_getBBox(const SbgnGlyph_t * sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sg->getBBox());
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "label" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetLabel(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetLabel()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "state" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetState(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetState()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "clone" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetClone(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetClone()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "callout" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetCallout(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetCallout()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "entity" element is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetEntity(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetEntity()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnGlyph_t's "bbox" element is set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_isSetBBox(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->isSetBBox()) : 0;
}


/*
 * Sets the value of the "label" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setLabel(SbgnGlyph_t * sg, const SbgnLabel_t* label)
{
  return (sg != NULL) ? sg->setLabel(label) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "state" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setState(SbgnGlyph_t * sg, const SbgnState_t* state)
{
  return (sg != NULL) ? sg->setState(state) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "clone" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setClone(SbgnGlyph_t * sg, const SbgnGlyph_t* clone)
{
  return (sg != NULL) ? sg->setClone(clone) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "callout" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setCallout(SbgnGlyph_t * sg, const SbgnCallout_t* callout)
{
  return (sg != NULL) ? sg->setCallout(callout) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "entity" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setEntity(SbgnGlyph_t * sg, const SbgnEntity_t* entity)
{
  return (sg != NULL) ? sg->setEntity(entity) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "bbox" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_setBBox(SbgnGlyph_t * sg, const SbgnBBox_t* bbox)
{
  return (sg != NULL) ? sg->setBBox(bbox) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Creates a new SbgnLabel_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnLabel_t object created.
 */
LIBSBGN_EXTERN
SbgnLabel_t*
SbgnGlyph_createLabel(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnLabel_t*)(sg->createLabel());
}


/*
 * Creates a new SbgnState_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnState_t object created.
 */
LIBSBGN_EXTERN
SbgnState_t*
SbgnGlyph_createState(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnState_t*)(sg->createState());
}


/*
 * Creates a new SbgnGlyph_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnGlyph_t object created.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_createClone(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnGlyph_t*)(sg->createClone());
}


/*
 * Creates a new SbgnCallout_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnCallout_t object created.
 */
LIBSBGN_EXTERN
SbgnCallout_t*
SbgnGlyph_createCallout(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnCallout_t*)(sg->createCallout());
}


/*
 * Creates a new SbgnEntity_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnEntity_t object created.
 */
LIBSBGN_EXTERN
SbgnEntity_t*
SbgnGlyph_createEntity(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnEntity_t*)(sg->createEntity());
}


/*
 * Creates a new SbgnBBox_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnBBox_t object created.
 */
LIBSBGN_EXTERN
SbgnBBox_t*
SbgnGlyph_createBBox(SbgnGlyph_t* sg)
{
  if (sg == NULL)
  {
    return NULL;
  }

  return (SbgnBBox_t*)(sg->createBBox());
}


/*
 * Unsets the value of the "label" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetLabel(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetLabel() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "state" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetState(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetState() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "clone" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetClone(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetClone() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "callout" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetCallout(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetCallout() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "entity" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetEntity(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetEntity() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "bbox" element of this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_unsetBBox(SbgnGlyph_t * sg)
{
  return (sg != NULL) ? sg->unsetBBox() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Returns a ListOf_t * containing SbgnGlyph_t objects from this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnGlyph_getListOfGlyphs(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->getListOfGlyphs() : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnGlyph_t.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyph(SbgnGlyph_t* sg, unsigned int n)
{
  return (sg != NULL) ? sg->getGlyph(n) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphById(SbgnGlyph_t* sg, const char *sid)
{
  return (sg != NULL && sid != NULL) ? sg->getGlyph(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the CompartmentRef to which
 * it refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByCompartmentRef(SbgnGlyph_t* sg, const char *sid)
{
  return (sg != NULL && sid != NULL) ? sg->getGlyphByCompartmentRef(sid) :
    NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the MapRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByMapRef(SbgnGlyph_t* sg, const char *sid)
{
  return (sg != NULL && sid != NULL) ? sg->getGlyphByMapRef(sid) : NULL;
}


/*
 * Get a SbgnGlyph_t from the SbgnGlyph_t based on the TagRef to which it
 * refers.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_getGlyphByTagRef(SbgnGlyph_t* sg, const char *sid)
{
  return (sg != NULL && sid != NULL) ? sg->getGlyphByTagRef(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnGlyph_t to this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_addGlyph(SbgnGlyph_t* sg, const SbgnGlyph_t* sg1)
{
  return (sg != NULL) ? sg->addGlyph(sg1) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnGlyph_t objects in this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnGlyph_getNumGlyphs(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->getNumGlyphs() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnGlyph_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnGlyph_t object created.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_createGlyph(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->createGlyph() : NULL;
}


/*
 * Removes the nth SbgnGlyph_t from this SbgnGlyph_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_removeGlyph(SbgnGlyph_t* sg, unsigned int n)
{
  return (sg != NULL) ? sg->removeGlyph(n) : NULL;
}


/*
 * Removes the SbgnGlyph_t from this SbgnGlyph_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnGlyph_removeGlyphById(SbgnGlyph_t* sg, const char* sid)
{
  return (sg != NULL && sid != NULL) ? sg->removeGlyph(sid) : NULL;
}


/*
 * Returns a ListOf_t * containing SbgnPort_t objects from this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
SbgnListOf_t*
SbgnGlyph_getListOfPorts(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->getListOfPorts() : NULL;
}


/*
 * Get a SbgnPort_t from the SbgnGlyph_t.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_getPort(SbgnGlyph_t* sg, unsigned int n)
{
  return (sg != NULL) ? sg->getPort(n) : NULL;
}


/*
 * Get a SbgnPort_t from the SbgnGlyph_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_getPortById(SbgnGlyph_t* sg, const char *sid)
{
  return (sg != NULL && sid != NULL) ? sg->getPort(sid) : NULL;
}


/*
 * Adds a copy of the given SbgnPort_t to this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_addPort(SbgnGlyph_t* sg, const SbgnPort_t* sp)
{
  return (sg != NULL) ? sg->addPort(sp) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Get the number of SbgnPort_t objects in this SbgnGlyph_t.
 */
LIBSBGN_EXTERN
unsigned int
SbgnGlyph_getNumPorts(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->getNumPorts() : SBGN_INT_MAX;
}


/*
 * Creates a new SbgnPort_t object, adds it to this SbgnGlyph_t object and
 * returns the SbgnPort_t object created.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_createPort(SbgnGlyph_t* sg)
{
  return (sg != NULL) ? sg->createPort() : NULL;
}


/*
 * Removes the nth SbgnPort_t from this SbgnGlyph_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_removePort(SbgnGlyph_t* sg, unsigned int n)
{
  return (sg != NULL) ? sg->removePort(n) : NULL;
}


/*
 * Removes the SbgnPort_t from this SbgnGlyph_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnPort_t*
SbgnGlyph_removePortById(SbgnGlyph_t* sg, const char* sid)
{
  return (sg != NULL && sid != NULL) ? sg->removePort(sid) : NULL;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnGlyph_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_hasRequiredAttributes(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->hasRequiredAttributes()) : 0;
}


/*
 * Predicate returning @c 1 (true) if all the required elements for this
 * SbgnGlyph_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnGlyph_hasRequiredElements(const SbgnGlyph_t * sg)
{
  return (sg != NULL) ? static_cast<int>(sg->hasRequiredElements()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



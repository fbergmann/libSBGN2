/**
 * @file SbgnBase.cpp
 * @brief Implementation of the SbgnBase class.
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


#include <sstream>
#include <vector>

#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbml/xml/XMLOutputStream.h>
#include <sbml/xml/XMLInputStream.h>
#include <sbml/xml/XMLToken.h>
#include <sbml/xml/XMLNode.h>

#include <sbml/util/util.h>

#include <sbgn/SbgnError.h>
#include <sbgn/SbgnErrorLog.h>
#include <sbgn/SbgnDocument.h>
#include <sbgn/SbgnListOf.h>
#include <sbgn/SbgnBase.h>


/** @cond doxygenIgnored */
using namespace std;
/** @endcond */

LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SbgnBase*
SbgnBase::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;

  return NULL;
}


const SbgnBase*
SbgnBase::getElementBySId(const std::string& id) const 
{
  if (id.empty()) return NULL;

  return NULL;
}


SbgnBase*
SbgnBase::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;

  return NULL;
}

const SbgnBase*
SbgnBase::getElementByMetaId(const std::string& metaid) const 
{
  if (metaid.empty()) return NULL;

  return NULL;
}


List*
SbgnBase::getAllElements()
{
  return NULL;
}

/** @cond doxygenLibsbgnInternal */
/*
 * Creates a new SbgnBase object with the given level and version.
 * Only subclasses may create SbgnBase objects.
 */
SbgnBase::SbgnBase (unsigned int level, unsigned int version) 
 : mMetaId ("")
 , mId ("")
 , mNotes(NULL)
 , mExtension( NULL )
 , mSbgn      ( NULL )
 , mSbgnNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSbgnObject (NULL)
  , mHasBeenDeleted(false)
  , mEmptyString("")
 , mURI("")
{
  mSbgnNamespaces = new SbgnNamespaces(level, version);

  //
  // Sets the XMLNS URI of corresponding SBGN Level/Version to
  // the element namespace (mURI) of this object.
  //
  //
  setElementNamespace(mSbgnNamespaces->getURI());
}



/*
 * Creates a new SbgnBase object with the given SbgnNamespaces.
 * Only subclasses may create SbgnBase objects.
 */
SbgnBase::SbgnBase (SbgnNamespaces *sbgnns) 
 : mMetaId("")
 , mId("")
 , mNotes(NULL)
 , mExtension( NULL )
 , mSbgn      ( NULL )
 , mSbgnNamespaces (NULL)
 , mUserData(NULL)
 , mLine      ( 0 )
 , mColumn    ( 0 )
 , mParentSbgnObject (NULL)
  , mHasBeenDeleted(false)
  , mEmptyString("")
 , mURI("")
{
  if (!sbgnns)
  {
    std::string err("SbgnBase::SbgnBase(SbgnNamespaces*) : SbgnNamespaces is null");
    throw SbgnConstructorException(err);
  }
  mSbgnNamespaces = sbgnns->clone();

  setElementNamespace(static_cast<SbgnNamespaces>(*mSbgnNamespaces).getURI());
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Copy constructor. Creates a copy of this SbgnBase object.
 */
SbgnBase::SbgnBase(const SbgnBase& orig)
  : mMetaId (orig.mMetaId)
  , mId (orig.mId)
  , mNotes (NULL)
  , mExtension (NULL)
  , mSbgn (NULL)
  , mSbgnNamespaces(NULL)
  , mUserData(orig.mUserData)
  , mLine(orig.mLine)
  , mColumn(orig.mColumn)
  , mParentSbgnObject(NULL)
  , mURI(orig.mURI)
{
  if(orig.mNotes != NULL)
    this->mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SbgnBase&>(orig).getNotes());
  else
    this->mNotes = NULL;

  if(orig.mExtension != NULL)
    this->mExtension = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SbgnBase&>(orig).mExtension);
  else
    this->mExtension = NULL;

  if(orig.getSbgnNamespaces() != NULL)
    this->mSbgnNamespaces =
    new SbgnNamespaces(*const_cast<SbgnBase&>(orig).getSbgnNamespaces());
  else
    this->mSbgnNamespaces = NULL;

  this->mHasBeenDeleted = false;
}
/** @endcond */


/*
 * Destroy this SbgnBase object.
 */
SbgnBase::~SbgnBase ()
{
  if (mNotes != NULL)       delete mNotes;
  if (mExtension != NULL)  delete mExtension;
  if (mSbgnNamespaces != NULL)  delete mSbgnNamespaces;
}

/*
 * Assignment operator
 */
SbgnBase& SbgnBase::operator=(const SbgnBase& rhs)
{
  if(&rhs!=this)
  {
    this->mMetaId = rhs.mMetaId;
    this->mId = rhs.mId;

    delete this->mNotes;

    if(rhs.mNotes != NULL)
      this->mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SbgnBase&>(rhs).getNotes());
    else
      this->mNotes = NULL;

    delete this->mExtension;

    if(rhs.mExtension != NULL)
      this->mExtension = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(*const_cast<SbgnBase&>(rhs).mExtension);
    else
      this->mExtension = NULL;

    this->mSbgn       = rhs.mSbgn;
    this->mLine       = rhs.mLine;
    this->mColumn     = rhs.mColumn;
    this->mParentSbgnObject = rhs.mParentSbgnObject;
    this->mUserData   = rhs.mUserData;

    delete this->mSbgnNamespaces;

    if(rhs.mSbgnNamespaces != NULL)
      this->mSbgnNamespaces =
      new SbgnNamespaces(*const_cast<SbgnBase&>(rhs).mSbgnNamespaces);
    else
      this->mSbgnNamespaces = NULL;


    this->mURI = rhs.mURI;
  }

  return *this;
}


/*
 * @return the metaid of this SBGN object.
 */
const string&
SbgnBase::getMetaId () const
{
  return mMetaId;
}


/*
 * @return the metaid of this SBGN object.
 */
string&
SbgnBase::getMetaId ()
{
  return mMetaId;
}


const string&
SbgnBase::getId() const
{
  return mId;
}


/*
 * @return the notes of this SBGN object.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SbgnBase::getNotes()
{
  return mNotes;
}


const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SbgnBase::getNotes() const
{
  return mNotes;
}


/*
 * @return the notes of this SBGN object by string.
 */
std::string
SbgnBase::getNotesString()
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(mNotes);
}


std::string
SbgnBase::getNotesString() const
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(mNotes);
}


/*
 * @return the annotation of this SBGN object.
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SbgnBase::getExtension ()
{
  return mExtension;
}


const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*
SbgnBase::getExtension () const
{
  return const_cast<SbgnBase *>(this)->getExtension();
}


/*
 * @return the annotation of this SBGN object by string.
 */
std::string
SbgnBase::getExtensionString ()
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(getExtension());
}


std::string
SbgnBase::getExtensionString () const
{
  return LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertXMLNodeToString(getExtension());
}


/** @cond doxygenLibsbgnInternal */
std::string
SbgnBase::getURI() const
{
  const SbgnDocument* doc = getSbgnDocument();

  if (doc == NULL)
    return getElementNamespace();

  SbgnNamespaces* sbgnns = doc->getSbgnNamespaces();

  if (sbgnns == NULL)
    return getElementNamespace();

  return getElementNamespace();
}
/** @endcond */


void *
SbgnBase::getUserData() const
{
  return this->mUserData;
}


int
SbgnBase::setUserData(void *userData)
{
  this->mUserData = userData;
  if (userData == NULL && mUserData == NULL)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (mUserData != NULL)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}

bool
SbgnBase::isSetUserData() const
{
  if (mUserData != NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int
SbgnBase::unsetUserData()
{
  this->mUserData = NULL;
  if (mUserData == NULL)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}

/*
 * @return the Namespaces associated with this SBGN object
 */
LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SbgnBase::getNamespaces()
{
  if (mSbgn != NULL)
    return mSbgn->getSbgnNamespaces()->getNamespaces();
  else
    return mSbgnNamespaces->getNamespaces();
}


const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces*
SbgnBase::getNamespaces() const
{
  if (mSbgn != NULL)
    return mSbgn->getSbgnNamespaces()->getNamespaces();
  else
    return mSbgnNamespaces->getNamespaces();
}


/*
 * @return the parent SbgnDocument of this SBGN object.
 */
const SbgnDocument*
SbgnBase::getSbgnDocument () const
{
  if (mSbgn != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSbgn->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSbgn;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mSbgn;
}

/*
 * @return the parent SbgnDocument of this SBGN object.
 */
SbgnDocument*
SbgnBase::getSbgnDocument ()
{
  if (mSbgn != NULL)
  {
    // if the doc object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mSbgn->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mSbgn;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }
  return mSbgn;
}
SbgnBase*
SbgnBase::getParentSbgnObject ()
{
  if (mParentSbgnObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSbgnObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSbgnObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSbgnObject;
}

const SbgnBase*
SbgnBase::getParentSbgnObject () const
{
  if (mParentSbgnObject != NULL)
  {
    // if the parent object has been deleted the pointer is
    // still valid but points to nothing
    try
    {
      if (mParentSbgnObject->getHasBeenDeleted())
      {
        return NULL;
      }
      else
      {
        return mParentSbgnObject;
      }
    }
    catch ( ... )
    {
      return NULL;
    }
  }

  return mParentSbgnObject;
}


/*
 * @return the line number of this SBGN object.
 */
unsigned int
SbgnBase::getLine () const
{
  return mLine;
}


/*
 * @return the column number of this SBGN object.
 */
unsigned int
SbgnBase::getColumn () const
{
  return mColumn;
}


/*
 * @return true if the metaid of this SBGN object is set, false
 * otherwise.
 */
bool
SbgnBase::isSetMetaId () const
{
  return (mMetaId.empty() == false);
}


bool
SbgnBase::isSetId() const
{
  return (getId().empty() == false);
}


/*
 * @return true if the notes of this SBGN object is set, false
 * otherwise.
 */
bool
SbgnBase::isSetNotes () const
{
  return (mNotes != NULL);
}


/*
 * @return true if the annotation of this SBGN object is set,
 * false otherwise.
 */
bool
SbgnBase::isSetExtension () const
{
  return (mExtension != NULL);
}


/*
 * Sets the metaid field of the given SBGN object to a copy of metaid.
 */
int
SbgnBase::setMetaId (const std::string& metaid)
{
  if (metaid.empty())
  {
    mMetaId.erase();
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (!(SyntaxChecker::isValidXMLID(metaid)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mMetaId = metaid;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}

/*
 * Sets the id field of the given SBGN object to a copy of sid.
 */
int
SbgnBase::setId (const std::string& sid)
{
  if (sid.empty())
  {
    mId.erase();
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (!(SyntaxChecker::isValidXMLID(sid)))
  {
    return LIBSBGN_INVALID_ATTRIBUTE_VALUE;
  }
  else
  {
    mId = sid;
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Sets the annotation of this SBGN object to a copy of annotation.
 */
int
SbgnBase::setExtension (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  if (annotation == NULL)
  {
    delete mExtension;
    mExtension = NULL;
  }

  if (mExtension != annotation)
  {
    delete mExtension;

    mExtension = annotation->clone();
  }

  return LIBSBGN_OPERATION_SUCCESS;
}

/*
 * Sets the annotation (by string) of this SBGN object to a copy of annotation.
 */
int
SbgnBase::setExtension (const std::string& annotation)
{
  
  int success = LIBSBGN_OPERATION_FAILED;
  
  if(annotation.empty())
  {
    unsetExtension();
    return LIBSBGN_OPERATION_SUCCESS;
  }
  
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  
  // you might not have a document !!
  if (getSbgnDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSbgnDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }
  
  if(annt_xmln != NULL)
  {
    success = setExtension(annt_xmln);
    delete annt_xmln;
  }
  return success;  
}


/*
 * Appends annotation to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SbgnBase::appendExtension (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  int success = LIBSBGN_OPERATION_FAILED;
  unsigned int duplicates = 0;

  if(annotation == NULL)
    return LIBSBGN_OPERATION_SUCCESS;

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* new_annotation = NULL;
  const string&  name = annotation->getName();

  // check for annotation tags and add if necessary
  if (name != "extension")
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken ann_t = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("extension", "", ""), LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());
    new_annotation = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(ann_t);
    new_annotation->addChild(*annotation);
  }
  else
  {
    new_annotation = annotation->clone();
  }


  if (mExtension != NULL)
  {
    // if mExtension is just <annotation/> need to tell
    // it to no longer be an end
    if (mExtension->isEnd())
    {
      mExtension->unsetEnd();
    }


    // create a list of existing top level ns
      vector<string> topLevelNs;
    unsigned int i = 0;
    for(i = 0; i < mExtension->getNumChildren(); i++)
    {
          topLevelNs.push_back(mExtension->getChild(i).getName());
    }



    for(i = 0; i < new_annotation->getNumChildren(); i++)
    {
          if (find(topLevelNs.begin(), topLevelNs.end(), (new_annotation->getChild(i).getName())) != topLevelNs.end())
      {
        mExtension->addChild(new_annotation->getChild(i));
      }
      else
      {
        duplicates++;
      }
    }

    delete new_annotation;

    if (duplicates > 0)
    {
      success = LIBSBGN_DUPLICATE_ANNOTATION_NS;
    }
    else
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode *copy = mExtension->clone();
      success = setExtension(copy);
      delete copy;
    }


  }
  else
  {
    success = setExtension(new_annotation);

    delete new_annotation;
  }

  return success;
}

/*
 * Appends annotation (by string) to the existing annotations.
 * This allows other annotations to be preserved whilst
 * adding additional information.
 */
int
SbgnBase::appendExtension (const std::string& annotation)
{
  int success = LIBSBGN_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  if (getSbgnDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSbgnDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = appendExtension(annt_xmln);
    delete annt_xmln;
  }

  return success;
}


int
SbgnBase::removeTopLevelExtensionElement(const std::string elementName,
    const std::string elementURI)
{

  int success = LIBSBGN_OPERATION_FAILED;
  if (mExtension == NULL)
  {
    success = LIBSBGN_OPERATION_SUCCESS;
    return success;
  }

  int index = mExtension->getIndex(elementName);
  if (index < 0)
  {
    // the annotation does not have a child of this name
    success = LIBSBGN_ANNOTATION_NAME_NOT_FOUND;
    return success;
  }
  else
  {
    // check uri matches
    if (elementURI.empty() == false)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode child = mExtension->getChild(index);
      std::string prefix = child.getPrefix();

      if (prefix.empty() == false
        && elementURI != child.getNamespaceURI(prefix))
      {
        success = LIBSBGN_ANNOTATION_NS_NOT_FOUND;
        return success;
      }
      else
      {
        bool match = false;
        int n = 0;

        while (match == false && n < child.getNamespacesLength())
        {
          if (elementURI == child.getNamespaceURI(n))
          {
            match = true;
          }
          n++;
        }

        if (match == false)
        {
          success = LIBSBGN_ANNOTATION_NS_NOT_FOUND;
          return success;
        }
      }
    }

    // remove the annotation at the index corresponding to the name
    delete mExtension->removeChild(index);

      if (mExtension->getNumChildren() == 0)
        {
          delete mExtension;
          mExtension = NULL;
        }

    // check success
    if (mExtension == NULL || mExtension->getIndex(elementName) < 0)
    {
      success = LIBSBGN_OPERATION_SUCCESS;
    }
  }

  return success;
}


int
SbgnBase::replaceTopLevelExtensionElement(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annotation)
{
  int success = LIBSBGN_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode * replacement = NULL;
  if (annotation->getName() == "extension")
  {
    if (annotation->getNumChildren() != 1)
    {
      success = LIBSBGN_INVALID_OBJECT;
      return success;
    }
    else
    {
      replacement = annotation->getChild(0).clone();
    }
  }
  else
  {
    replacement = annotation->clone();
  }

  success = removeTopLevelExtensionElement(replacement->getName());
  if (success == LIBSBGN_OPERATION_SUCCESS)
  {
    success = appendExtension(annotation);
  }

  delete (replacement);

  return success;
}


int
SbgnBase::replaceTopLevelExtensionElement(const std::string& annotation)
{
  int success = LIBSBGN_OPERATION_FAILED;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* annt_xmln;
  if (getSbgnDocument() != NULL)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSbgnDocument()->getNamespaces();
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation,xmlns);
  }
  else
  {
    annt_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(annotation);
  }

  if(annt_xmln != NULL)
  {
    success = replaceTopLevelExtensionElement(annt_xmln);
  }

  delete annt_xmln;

  return success;
}


/*
 * Sets the notes of this SBGN object to a copy of notes.
 */
int
SbgnBase::setNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes)
{
  if (mNotes == notes)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (notes == NULL)
  {
    delete mNotes;
    mNotes = NULL;
    return LIBSBGN_OPERATION_SUCCESS;
  }

  delete mNotes;
  const string&  name = notes->getName();

  /* check for notes tags and add if necessary */

  if (name == "notes")
  {
    mNotes = static_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode*>( notes->clone() );
  }
  else
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken notes_t = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("notes", "", ""),
                                LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());
    mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(notes_t);

    // The root node of the given XMLNode tree can be an empty XMLNode
    // (i.e. neither start, end, nor text XMLNode) if the given notes was
    // converted from an XML string whose top level elements are neither
    // "html" nor "body" and not enclosed with <notes>..</notes> tag
    // (e.g. <p ...>..</p><br/>).
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      for (unsigned int i=0; i < notes->getNumChildren(); i++)
      {
        if (mNotes->addChild(notes->getChild(i)) < 0)
        {
          return LIBSBGN_OPERATION_FAILED;
        }
      }
    }
    else
    {
      if (mNotes->addChild(*notes) < 0)
        return LIBSBGN_OPERATION_FAILED;
    }
  }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(mNotes, NULL))
    {
      delete mNotes;
      mNotes = NULL;
      return LIBSBGN_INVALID_OBJECT;
    }

  return LIBSBGN_OPERATION_SUCCESS;

}

/*
 * Sets the notes (by std::string) of this SBGN object to a copy of notes.
 */
int
SbgnBase::setNotes(const std::string& notes, bool addXHTMLMarkup)
{
  int success = LIBSBGN_OPERATION_FAILED;
  
  if (notes.empty())
  {
    success = unsetNotes();
  }
  else
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes_xmln;

    // you might not have a document !!
    if (getSbgnDocument() != NULL)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSbgnDocument()->getNamespaces();
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes,xmlns);
    }
    else
    {
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes);
    }

    if (notes_xmln != NULL)
    {
      if (addXHTMLMarkup == true)
      {
        if (notes_xmln->getNumChildren() == 0
            && notes_xmln->isStart() == false
            && notes_xmln->isEnd() == false
            && notes_xmln->isText() == true)
        {
          //create a parent node of xhtml type p
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes blank_att = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes();
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple triple = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("p", "http://www.w3.org/1999/xhtml", "");
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces xmlns = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces();
          xmlns.add("http://www.w3.org/1999/xhtml", "");
          LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode *xmlnode = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken(triple, blank_att, xmlns));

          // create a text node from the text given
          xmlnode->addChild(*notes_xmln);
          success = setNotes(xmlnode);
          delete xmlnode;
        }
        else
        {
          success = setNotes(notes_xmln);
        }
      }
      else
      {
        success = setNotes(notes_xmln);
      }

      delete notes_xmln;
    }
  }
  return success;
}


/*
 * Appends notes to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SbgnBase::appendNotes(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes)
{
  int success = LIBSBGN_OPERATION_FAILED;
  if(notes == NULL)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }

  const string&  name = notes->getName();

  // The content of notes in SBGN can consist only of the following
  // possibilities:
  //
  //  1. A complete XHTML document (minus the XML and DOCTYPE
  //     declarations), that is, XHTML content beginning with the
  //     html tag.
  //     (_NotesType is _ANotesHTML.)
  //
  //  2. The body element from an XHTML document.
  //     (_NotesType is _ANotesBody.)
  //
  //  3. Any XHTML content that would be permitted within a body
  //     element, each one must declare the XML namespace separately.
  //     (_NotesType is _ANotesAny.)
  //

  typedef enum { _ANotesHTML, _ANotesBody, _ANotesAny } _NotesType;

  _NotesType addedNotesType = _ANotesAny;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode   addedNotes;

  //------------------------------------------------------------
  //
  // STEP1 : identifies the type of the given notes
  //
  //------------------------------------------------------------

  if (name == "notes")
  {
    /* check for notes tags on the added notes and strip if present and
       the notes tag has "html" or "body" element */

    if (notes->getNumChildren() > 0)
    {
      // notes->getChild(0) must be "html", "body", or any XHTML
      // element that would be permitted within a "body" element
      // (e.g. <p>..</p>,  <br>..</br> and so forth).

      const string& cname = notes->getChild(0).getName();

      if (cname == "html")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesHTML;
      }
      else if (cname == "body")
      {
        addedNotes = notes->getChild(0);
        addedNotesType = _ANotesBody;
      }
      else
      {
        // the notes tag must NOT be stripped if notes->getChild(0) node
        // is neither "html" nor "body" element because the children of
        // the addedNotes will be added to the curNotes later if the node
        // is neither "html" nor "body".
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
    }
    else
    {
      // the given notes is empty
      return LIBSBGN_OPERATION_SUCCESS;
    }
  }
  else
  {
    // if the XMLNode argument notes has been created from a string and
    // it is a set of subelements there may be a single empty node
    // as parent - leaving this in doesnt affect the writing out of notes
    // but messes up the check for correct syntax
    if (!notes->isStart() && !notes->isEnd() && !notes->isText() )
    {
      if (notes->getNumChildren() > 0)
      {
        addedNotes = *notes;
        addedNotesType = _ANotesAny;
      }
      else
      {
        // the given notes is empty
        return LIBSBGN_OPERATION_SUCCESS;
      }
    }
    else
    {
      if (name == "html")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesHTML;
      }
      else if (name == "body")
      {
        addedNotes = *notes;
        addedNotesType = _ANotesBody;
      }
      else
      {
        // The given notes node needs to be added to a parent node
        // if the node is neither "html" nor "body" element because the
        // children of addedNotes will be added to the curNotes later if the
        // node is neither "html" nor "body" (i.e. any XHTML element that
        // would be permitted within a "body" element)
        addedNotes.addChild(*notes);
        addedNotesType = _ANotesAny;
      }
    }
  }

  //
  // checks the addedNotes of "html" if the html tag contains "head" and
  // "body" tags which must be located in this order.
  //
  if (addedNotesType == _ANotesHTML)
  {
    if ((addedNotes.getNumChildren() != 2) ||
        ( (addedNotes.getChild(0).getName() != "head") ||
          (addedNotes.getChild(1).getName() != "body")
        )
       )
    {
      return LIBSBGN_INVALID_OBJECT;
    }
  }

  // check whether notes is valid xhtml
  if (getLevel() > 2
    || (getLevel() == 2 && getVersion() > 1))
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode tmpNotes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLTriple("notes","",""), LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes());

    if (addedNotesType == _ANotesAny)
    {
      for (unsigned int i=0; i < addedNotes.getNumChildren(); i++)
      {
        tmpNotes.addChild(addedNotes.getChild(i));
      }
    }
    else
    {
      tmpNotes.addChild(addedNotes);
    }

    if (!SyntaxChecker::hasExpectedXHTMLSyntax(&tmpNotes, NULL))
    {
      return LIBSBGN_INVALID_OBJECT;
    }
  }


  if ( mNotes != NULL )
  {
    //------------------------------------------------------------
    //
    //  STEP2: identifies the type of the existing notes
    //
    //------------------------------------------------------------

    _NotesType curNotesType   = _ANotesAny;
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode&  curNotes = *mNotes;

    // curNotes.getChild(0) must be "html", "body", or any XHTML
    // element that would be permitted within a "body" element .

    const string& cname = curNotes.getChild(0).getName();

    if (cname == "html")
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curHTML = curNotes.getChild(0);
      //
      // checks the curHTML if the html tag contains "head" and "body" tags
      // which must be located in this order, otherwise nothing will be done.
      //
      if ((curHTML.getNumChildren() != 2) ||
          ( (curHTML.getChild(0).getName() != "head") ||
            (curHTML.getChild(1).getName() != "body")
          )
         )
      {
        return LIBSBGN_INVALID_OBJECT;
      }
      curNotesType = _ANotesHTML;
    }
    else if (cname == "body")
    {
      curNotesType = _ANotesBody;
    }
    else
    {
      curNotesType = _ANotesAny;
    }

    /*
     * BUT we also have the issue of the rules relating to notes
     * contents and where to add them ie we cannot add a second body element
     * etc...
     */

    //------------------------------------------------------------
    //
    //  STEP3: appends the given notes to the current notes
    //
    //------------------------------------------------------------

    unsigned int i;

    if (curNotesType == _ANotesHTML)
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curHTML = curNotes.getChild(0);
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody = curHTML.getChild(1);

      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current html tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedNotes.getChild(1);

        for (i=0; i < addedBody.getNumChildren(); i++)
        {
          if (curBody.addChild(addedBody.getChild(i)) < 0 )
            return LIBSBGN_OPERATION_FAILED;
        }
      }
      else if ((addedNotesType == _ANotesBody)
             || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // html tag

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0 )
            return LIBSBGN_OPERATION_FAILED;
        }
      }
      success = LIBSBGN_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesBody)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current body tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode  addedHTML(addedNotes);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedHTML.getChild(1);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody   = curNotes.getChild(0);

        for (i=0; i < curBody.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curBody.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSBGN_OPERATION_FAILED;
      }
      else if ((addedNotesType == _ANotesBody) || (addedNotesType == _ANotesAny))
      {
        // adds the given body or other tag (permitted in the body) to the current
        // body tag

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& curBody = curNotes.getChild(0);

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curBody.addChild(addedNotes.getChild(i)) < 0)
            return LIBSBGN_OPERATION_FAILED;
        }
      }
      success = LIBSBGN_OPERATION_SUCCESS;
    }
    else if (curNotesType == _ANotesAny)
    {
      if (addedNotesType == _ANotesHTML)
      {
        // adds the given html tag to the current any tag permitted in the body.

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode  addedHTML(addedNotes);
        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode& addedBody = addedHTML.getChild(1);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedHTML) < 0)
          return LIBSBGN_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesBody)
      {
        // adds the given body tag to the current any tag permitted in the body.

        LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode addedBody(addedNotes);

        for (i=0; i < curNotes.getNumChildren(); i++)
        {
          addedBody.insertChild(i,curNotes.getChild(i));
        }

        curNotes.removeChildren();
        if (curNotes.addChild(addedBody) < 0)
          return LIBSBGN_OPERATION_FAILED;
      }
      else if (addedNotesType == _ANotesAny)
      {
        // adds the given any tag permitted in the boy to that of the current
        // any tag.

        for (i=0; i < addedNotes.getNumChildren(); i++)
        {
          if (curNotes.addChild(addedNotes.getChild(i)) < 0)
            return LIBSBGN_OPERATION_FAILED;
        }
      }
      success = LIBSBGN_OPERATION_SUCCESS;
    }
  }
  else // if (mNotes == NULL)
  {
    // setNotes accepts XMLNode with/without top level notes tags.
    success = setNotes(notes);
  }

  return success;
}

/*
 * Appends notes (by string) to the existing notes.
 * This allows other notes to be preserved whilst
 * adding additional information.
 */
int
SbgnBase::appendNotes(const std::string& notes)
{
  int success = LIBSBGN_OPERATION_FAILED;
  if (notes.empty())
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* notes_xmln;
  // you might not have a document !!
  if (getSbgnDocument() != NULL)
  {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns = getSbgnDocument()->getNamespaces();
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes,xmlns);
  }
  else
  {
      notes_xmln = LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode::convertStringToXMLNode(notes);
  }

  if(notes_xmln != NULL)
  {
    success = appendNotes(notes_xmln);
    delete notes_xmln;
  }
  return success;
}


/** @cond doxygenLibsbgnInternal */
/*
 * Sets the parent SbgnDocument of this SBGN object.
 */
void
SbgnBase::setSbgnDocument (SbgnDocument* d)
{
  mSbgn = d;
}


/*
  * Sets the parent SBGN object of this SBGN object.
  *
  * @param sb the SBGN object to use
  */
void
SbgnBase::connectToParent (SbgnBase* parent)
{
  mParentSbgnObject = parent;
  if (mParentSbgnObject)
  {
#if 0
    cout << "[DEBUG] connectToParent " << this << " (parent) " << SbgnTypeCode_toString(parent->getTypeCode(),"core")
         << " " << parent->getSbgnDocument() << endl;
#endif
    setSbgnDocument(mParentSbgnObject->getSbgnDocument());
  }
  else
  {
    setSbgnDocument(NULL);
  }
}


/*
 * Sets this SBGN object to child SBGN objects (if any).
 * (Creates a child-parent relationship by the parent)
 *
 * Subclasses must override this function if they define
 * one ore more child elements.
 * Basically, this function needs to be called in
 * constructors, copy constructors and assignment operators.
 */
void
SbgnBase::connectToChild()
{
}
/** @endcond */

SbgnBase*
SbgnBase::getAncestorOfType(int type)
{
  if (type == SBGN_DOCUMENT)
    return getSbgnDocument();

  SbgnBase *child;
  SbgnBase *parent = getParentSbgnObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SBGN_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSbgnObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


const SbgnBase*
SbgnBase::getAncestorOfType(int type) const
{
  if (type == SBGN_DOCUMENT)
    return getSbgnDocument();

  const SbgnBase *child;
  const SbgnBase *parent = getParentSbgnObject();

  while ( parent != NULL &&
          !( parent->getTypeCode() == SBGN_DOCUMENT )
        )
  {
    if (parent->getTypeCode() == type)
      return parent;
    else
    {
      child = parent;
      parent = child->getParentSbgnObject();
    }
  }

  // if we get here we havent found an ancestor of this type
  return NULL;

}


/*
 * Sets the namespaces relevant of this SBGN object.
 *
 * @param xmlns the namespaces to set
 */
int
SbgnBase::setNamespaces(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns)
{
  if (xmlns == NULL)
  {
    mSbgnNamespaces->setNamespaces(NULL);
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    mSbgnNamespaces->setNamespaces(xmlns);
    return LIBSBGN_OPERATION_SUCCESS;
  }
}



/*
 * Unsets the metaid of this SBGN object.
 */
int
SbgnBase::unsetMetaId ()
{
  mMetaId.erase();

  if (mMetaId.empty())
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the id of this SBGN object.
 */
int
SbgnBase::unsetId ()
{
  mId.erase();

  if (mId.empty())
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the notes of this SBGN object.
 */
int
SbgnBase::unsetNotes ()
{
  delete mNotes;
  mNotes = NULL;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the annotation of this SBGN object.
 */
int
SbgnBase::unsetExtension ()
{
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode* empty = NULL;
  return setExtension(empty);
}


/*
 * @return the SBGN level of this SBGN object.
 */
unsigned int
SbgnBase::getLevel () const
{
  if (mSbgnNamespaces != NULL)
    return mSbgnNamespaces->getLevel();
  else
    return SBGN_DEFAULT_LEVEL;
}


/*
 * @return the SBGN version of this SBGN object.
 */
unsigned int
SbgnBase::getVersion () const
{
  if (mSbgnNamespaces != NULL)
    return mSbgnNamespaces->getVersion();
  else
    return SBGN_DEFAULT_VERSION;
}


/*
 * @return the typecode (int) of this SBGN object or SBGN_UNKNOWN
 * (default).
 *
 * This method MAY return the typecode of this SBGN object or it MAY
 * return SBGN_UNKNOWN.  That is, subclasses of SbgnBase are not required to
 * implement this method to return a typecode.  This method is meant
 * primarily for the LibSBGN C interface where class and subclass
 * information is not readily available.
 *
 * @see getElementName()
 */
int
SbgnBase::getTypeCode () const
{
  return SBGN_UNKNOWN;
}


bool
SbgnBase::hasValidLevelVersionNamespaceCombination()
{
  int typecode = getTypeCode();
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();

  return hasValidLevelVersionNamespaceCombination(typecode, xmlns);
}

/** @cond doxygenLibsbgnInternal */
bool
SbgnBase::matchesSbgnNamespaces(const SbgnBase * sb)
{
  bool match = matchesCoreSbgnNamespace(sb);

  return match;
}

bool
SbgnBase::matchesSbgnNamespaces(const SbgnBase * sb) const
{
  bool match = matchesCoreSbgnNamespace(sb);

  return match;
}


bool
SbgnBase::matchesRequiredSbgnNamespacesForAddition(const SbgnBase * sb)
{
  // if core does not match forget it
  bool match = matchesCoreSbgnNamespace(sb);

  return match;
}


bool
SbgnBase::matchesRequiredSbgnNamespacesForAddition(const SbgnBase * sb) const
{
  // if core does not match forget it
  bool match = matchesCoreSbgnNamespace(sb);

  return match;
}


bool
SbgnBase::matchesCoreSbgnNamespace(const SbgnBase * sb)
{
  bool match = false;

  SbgnNamespaces *sbgnns = getSbgnNamespaces();
  SbgnNamespaces *sbgnns_rhs = sb->getSbgnNamespaces();

  if (sbgnns->getLevel() != sbgnns_rhs->getLevel())
    return match;

  if (sbgnns->getVersion() != sbgnns_rhs->getVersion())
    return match;

  std::string coreNs = SbgnNamespaces::getSbgnNamespaceURI(
                       sbgnns->getLevel(), sbgnns->getVersion());

  if (sbgnns->getNamespaces()->containsUri(coreNs)
    && sbgnns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SbgnBase::matchesCoreSbgnNamespace(const SbgnBase * sb) const
{
  bool match = false;

  SbgnNamespaces *sbgnns = getSbgnNamespaces();
  SbgnNamespaces *sbgnns_rhs = sb->getSbgnNamespaces();

  if (sbgnns->getLevel() != sbgnns_rhs->getLevel())
    return match;

  if (sbgnns->getVersion() != sbgnns_rhs->getVersion())
    return match;

  std::string coreNs = SbgnNamespaces::getSbgnNamespaceURI(
                       sbgnns->getLevel(), sbgnns->getVersion());

  if (sbgnns->getNamespaces()->containsUri(coreNs)
    && sbgnns_rhs->getNamespaces()->containsUri(coreNs))
  {
    match = true;
  }

  return match;
}


bool
SbgnBase::hasValidLevelVersionNamespaceCombination(int typecode, LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns)
{


  //
  // (TODO) Currently, the following check code works only for
  //        elements in SBGN core.
  //        This function may need to be extented for other elements
  //        defined in each package extension.
  //

  bool valid = true;
  bool sbgnDeclared = false;
  std::string declaredURI("");

  if (xmlns != NULL)
  {
    int numNS = 0;

    if (xmlns->hasURI(SBGN_XMLNS_L0V1))
    {
      // checks different SBGN XMLNamespaces
      if (numNS > 0) return false;
      ++numNS;
      declaredURI.assign(SBGN_XMLNS_L0V1);
    }

    // checks if the SBGN Namespace is explicitly defined.
    for (int i=0; i < xmlns->getLength(); i++)
    {
      if (!declaredURI.empty() &&
                      xmlns->getURI(i) == declaredURI)
      {
        sbgnDeclared = true;
        break;

      }
    }
  }

  return valid;
}

/* sets the Sbgnnamespaces - internal use only*/
int
SbgnBase::setSbgnNamespaces(SbgnNamespaces * sbgnns)
{
  if (sbgnns == NULL)
    return LIBSBGN_INVALID_OBJECT;

  SbgnNamespaces* sbgnnsClone = (sbgnns) ? sbgnns->clone() : 0;
  setSbgnNamespacesAndOwn(sbgnnsClone);

  return LIBSBGN_OPERATION_SUCCESS;
}

/*
 * sets the Sbgnnamespaces - only for internal use in the
 * constructors of SbgnBase subclasses in extension packages.
 */
void
SbgnBase::setSbgnNamespacesAndOwn(SbgnNamespaces * sbgnns)
{
  delete mSbgnNamespaces;
  mSbgnNamespaces = sbgnns;

  if(sbgnns != NULL)
    setElementNamespace(sbgnns->getURI());
}


/* gets the Sbgnnamespaces - internal use only*/
SbgnNamespaces *
SbgnBase::getSbgnNamespaces() const
{
  if (mSbgn != NULL)
    return mSbgn->mSbgnNamespaces;
  
  // initialize SBGN namespace if need be
  if (mSbgnNamespaces == NULL)
    const_cast<SbgnBase*>(this)->mSbgnNamespaces = new SbgnNamespaces(getLevel(), getVersion());
  return mSbgnNamespaces;  
}
/** @endcond */



/*
 * @return the partial SBGN that describes this SBGN object.
 */
char*
SbgnBase::toSbgn ()
{
  ostringstream    os;
  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream  stream(os, "UTF-8", false);

  write(stream);

  return safe_strdup( os.str().c_str() );
}


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::getAttribute(const std::string& attributeName, double& value) const
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::getAttribute(const std::string& attributeName, bool& value) const
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::getAttribute(const std::string& attributeName, int& value) const
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::getAttribute(const std::string& attributeName, unsigned int& value) const
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::getAttribute(const std::string& attributeName, std::string& value) const
{
  if (attributeName == "metaid")
  {
    value = getMetaId();
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "id")
  {
    value = getId();
    return LIBSBGN_OPERATION_SUCCESS;
  }

  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
bool 
SbgnBase::isSetAttribute(const std::string& attributeName) const
{
  bool value = false;
  if (attributeName == "metaid")
  {
    value = isSetMetaId();
  }
  else if (attributeName == "id")
  {
    value = isSetId();
  }

  return value;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::setAttribute(const std::string& attributeName, double value)
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::setAttribute(const std::string& attributeName, bool value)
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::setAttribute(const std::string& attributeName, int value)
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::setAttribute(const std::string& attributeName, unsigned int value)
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::setAttribute(const std::string& attributeName, const std::string& value)
{
  int return_value = LIBSBGN_OPERATION_FAILED;
  if (attributeName == "metaid")
  {
    return_value = setMetaId(value);
  }
  else if (attributeName == "id")
  {
    return_value = setId(value);
  }

  return return_value;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
int 
SbgnBase::unsetAttribute(const std::string& attributeName)
{
  int value = LIBSBGN_OPERATION_FAILED;
  if (attributeName == "metaid")
  {
    value = unsetMetaId();
  }
  else if (attributeName == "id")
  {
    value = unsetId();
  }

  return value;
}
/** @endcond */

/** @cond doxygenLibsbgnInternal */
SbgnBase* 
SbgnBase::createChildObject(const std::string& elementName)
{
  return NULL;
}
/** @endcond */

/** @cond doxygenLibsbgnInternal */
int
SbgnBase::addChildObject(const std::string& elementName, const SbgnBase* element)
{
  return LIBSBGN_OPERATION_FAILED;
}
/** @endcond */

/** @cond doxygenLibsbgnInternal */
SbgnBase*
SbgnBase::removeChildObject(const std::string& elementName, const std::string& id)
{
  return NULL;
}
/** @endcond */

/** @cond doxygenLibsbgnInternal */

unsigned int
  SbgnBase::getNumObjects(const std::string& objectName)
{
  return 0;
}

  /** @endcond */

  /** @cond doxygenLibsbgnInternal */

SbgnBase* 
SbgnBase::getObject(const std::string& objectName, unsigned int index)
{
  return NULL;
}

  /** @endcond */
/** @cond doxygenLibsbgnInternal */
/*
 * Reads (initializes) this SBGN object by reading from XMLInputStream.
 */
void
SbgnBase::read (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  if ( !stream.peek().isStart() ) return;

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken  element  = stream.next();
  int             position =  0;

  setSbgnBaseFields( element );

  ExpectedAttributes expectedAttributes;
  addExpectedAttributes(expectedAttributes);
  readAttributes( element.getAttributes(), expectedAttributes );

  /* if we are reading a document pass the
   * SBGN Namespace information to the input stream object
   * thus the MathML reader can find out what level/version
   * of SBGN it is parsing
   */
  if (element.getName() == "Extension")
  {
 //   stream.setSbgnNamespaces(this->getSbgnNamespaces());
    // need to check that any prefix on the sbgnns also occurs on element
    // remembering the horrible situation where the sbgnns might be declared
    // with more than one prefix
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces * xmlns = this->getSbgnNamespaces()->getNamespaces();
    if (xmlns != NULL)
    {
      int i = xmlns->getIndexByPrefix(element.getPrefix());
      if (i < xmlns->getNumNamespaces())
      {
        bool errorLoggedAlready = false;
        bool error = false;
        if (i > -1)
        {
          if (xmlns->getURI(i) != this->getSbgnNamespaces()->getURI())
          {
            error = true;
          }
        }
        else if ( i == -1)
        {
          error = true;
        }

        /* if there is a mismatch in level/version this will already
         * be logged; do not need another error
         */
        for (unsigned int n = 0; n < this->getErrorLog()->getNumErrors(); n++)
        {
          unsigned int errorId =
                             this->getErrorLog()->getError(n)->getErrorId();
          if ( errorId == SbgnmlDocumentAllowedCoreAttributes
            || errorId == InvalidNamespaceOnSbgn)
          {
            errorLoggedAlready = true;
          }
        }

        if (error == true && errorLoggedAlready == false)
        {
          static ostringstream errMsg;
          errMsg.str("");
          errMsg << "The prefix for the <sbgn> element does not match "
            << "the prefix for the SBGN namespace.  This means that "
            << "the <sbgn> element in not in the SbgnNamespace."<< endl;

          logError(InvalidNamespaceOnSbgn,
                    getLevel(), getVersion(), errMsg.str());
        }
      }
    }

  }
  else
  {
    //
    // checks if the given default namespace (if any) is a valid
    // SBGN namespace
    //
    checkDefaultNamespace(mSbgnNamespaces->getNamespaces(), element.getName());
    if (!element.getPrefix().empty())
    {
      LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces * prefixedNS = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces();
      prefixedNS->add(element.getURI(), element.getPrefix());
      checkDefaultNamespace(prefixedNS, element.getName(), element.getPrefix());
      delete prefixedNS;
    }
  }

  if ( element.isEnd() ) return;

  while ( stream.isGood() )
  {
    // this used to skip the text
    //    stream.skipText();
    // instead, read text and store in variable
    std::string text;
    while(stream.isGood() && stream.peek().isText())
    {
      text += stream.next().getCharacters();
    }
    setElementText(text);

    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& next = stream.peek();

    // Re-check stream.isGood() because stream.peek() could hit something.
    if ( !stream.isGood() ) break;

    if ( next.isEndFor(element) )
    {
      stream.next();
      break;
    }
    else if ( next.isStart() )
    {
      const std::string nextName = next.getName();

      SbgnBase * object = createObject(stream);

      if (object != NULL)
      {
        position = object->getElementPosition();

        object->connectToParent(static_cast <SbgnBase*>(this));

        object->read(stream);

        if ( !stream.isGood() ) break;

        checkSbgnListOfPopulated(object);
      }
      else if ( !( readOtherXML(stream)
                   || readExtension(stream)
                   || readNotes(stream) ))
      {
        logUnknownElement(nextName, getLevel(), getVersion());
        stream.skipPastEnd( stream.next() );
      }
    }
    else
    {
      stream.skipPastEnd( stream.next() );
    }
  }
}
/** @endcond */


void
SbgnBase::setElementText(const std::string &text)
{
}

/** @cond doxygenLibsbgnInternal */
/*
 * Writes (serializes) this SBGN object by writing it to XMLOutputStream.
 */
void
SbgnBase::write (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  stream.startElement( getElementName(), getPrefix() );

  writeXMLNS     ( stream );
  writeAttributes( stream );
  writeElements  ( stream );

  stream.endElement( getElementName(), getPrefix() );

}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Subclasses should override this method to write out their contained
 * SBGN objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SbgnBase::writeElements (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  if ( mNotes != NULL ) stream << *mNotes;

  if (mExtension != NULL) stream << *mExtension;
}


/** @cond doxygenLibsbgnInternal */
/*
 * Subclasses should override this method to create, store, and then
 * return an SBGN object corresponding to the next XMLToken in the
 * XMLInputStream.
 *
 * @return the SBGN object corresponding to next XMLToken in the
 * XMLInputStream or @c NULL if the token was not recognized.
 */
SbgnBase*
SbgnBase::createObject (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  return NULL;
}


/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Subclasses should override this method to read (and store) XHTML,
 * MathML, etc. directly from the XMLInputStream.
 *
 * @return true if the subclass read from the stream, false otherwise.
 */
bool
SbgnBase::readOtherXML (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  bool read = false;
  return read;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * @return true if read an <annotation> element from the stream
 */
bool
SbgnBase::readExtension (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "extension")
  {
    // If an annotation already exists, log it as an error and replace
    // the content of the existing annotation with the new one.

    if (mExtension != NULL)
    {
      string msg = "An SBGN <" + getElementName() + "> element ";
      msg += "has multiple <annotation> children.";
      logError(SbgnMultipleExtensions, getLevel(), getVersion(), msg);
    }

    delete mExtension;
    mExtension = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream);
    checkExtension();
    return true;
  }

  return false;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * @return true if read a <notes> element from the stream
 */
bool
SbgnBase::readNotes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream& stream)
{
  const string& name = stream.peek().getName();

  if (name == "notes")
  {
    // If a notes element already exists, then it is an error.
    // If an annotation element already exists, then the ordering is wrong.
    // In either case, replace existing content with the new notes read.

    if (mNotes != NULL)
    {
      logError(SbgnOnlyOneNotesElementAllowed, getLevel(), getVersion());
    }

    delete mNotes;
    mNotes = new LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode(stream);

    //
    // checks if the given default namespace (if any) is a valid
    // SBGN namespace
    //
    const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces &xmlns = mNotes->getNamespaces();
    checkDefaultNamespace(&xmlns,"notes");

    return true;
  }

  return false;
}

bool
SbgnBase::getHasBeenDeleted() const
{
  return mHasBeenDeleted;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * @return the ordinal position of the element with respect to its siblings
 * or -1 (default) to indicate the position is not significant.
 */
int
SbgnBase::getElementPosition () const
{
  return -1;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
SbgnErrorLog*
SbgnBase::getErrorLog ()
{
  return (mSbgn != NULL) ? mSbgn->getErrorLog() : NULL;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Helper to log a common type of error.
 */
void
SbgnBase::logUnknownAttribute( const string& attribute,
                            const unsigned int level,
                            const unsigned int version,
                            const string& element,
                            const string& prefix)
{
  ostringstream msg;

    msg << "Attribute '" << attribute << "' is not part of the "
        << "definition of an SBGN Level " << level
        << " Version " << version << " <" << element << "> element.";

  if (mSbgn)
  {
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SbgnDocument attached.
  //
        getErrorLog()->logError(SbgnUnknownCoreAttribute, level,
          version, msg.str(), getLine(), getColumn());
  }
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Helper to log a common type of error.
 */
void
SbgnBase::logUnknownElement( const string& element,
        const unsigned int level,
        const unsigned int version )
{


    ostringstream msg;

    msg << "Element '" << element << "' is not part of the definition of "
        << "SBGN Level " << level << " Version " << version << ".";

    if (mSbgn != NULL)
    {
      getErrorLog()->logError(SbgnUnrecognizedElement,
            level, version, msg.str(), getLine(), getColumn());
    }
  

}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Helper to log a common type of error.
 */
void
SbgnBase::logEmptyString( const string& attribute,
                       const unsigned int level,
                       const unsigned int version,
                       const string& element )

{
  ostringstream msg;

  msg << "Attribute '" << attribute << "' on an "
    << element << " must not be an empty string.";

  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SbgnDocument attached.
  //
  if (mSbgn != NULL)
    getErrorLog()->logError(SbgnNotSchemaConformant,
                            level, version, msg.str(), getLine(), getColumn());
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Convenience method for easily logging problems from within method
 * implementations.
 *
 * This is essentially a short form of getErrorLog()->logError(...)
 */
void
SbgnBase::logError (  unsigned int       id
                 , const unsigned int level
                 , const unsigned int version
                 , const std::string& details )
{
  //
  // (TODO) Needs to be fixed so that error can be added when
  // no SbgnDocument attached.
  //
  if ( SbgnBase::getErrorLog() != NULL && mSbgn != NULL)
    getErrorLog()->logError(id, getLevel(), getVersion(), details, getLine(), getColumn());
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/**
 * Subclasses should override this method to get the list of
 * expected attributes.
 * This function is invoked from corresponding readAttributes()
 * function.
 */
void
SbgnBase::addExpectedAttributes(ExpectedAttributes& attributes)
{
  //
  // metaid: ID { use="optional" }  (L2v1 ->)
  //
  attributes.add("metaid");
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SbgnBase::readAttributes (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes& attributes,
                       const LIBSBML_CPP_NAMESPACE_QUALIFIER ExpectedAttributes& expectedAttributes)
{
  const_cast<LIBSBML_CPP_NAMESPACE_QUALIFIER XMLAttributes&>(attributes).setErrorLog(getErrorLog());

  const unsigned int level   = getLevel  ();
  const unsigned int version = getVersion();

  //
  // check that all attributes are expected
  //
  for (int i = 0; i < attributes.getLength(); i++)
  {
    std::string name   = attributes.getName(i);
    std::string uri    = attributes.getURI(i);
    std::string prefix = attributes.getPrefix(i);

    //
    // To allow prefixed attribute whose namespace doesn't belong to
    // core or extension package.
    //
    // (e.g. xsi:type attribute in Curve element in layout extension)
    //
    if (!prefix.empty())
    {
      if ( expectedAttributes.hasAttribute(prefix + ":" + name) ) continue;
    }


    //
    // Checks if there are attributes of unknown package extensions
    //
    // if we happen to be on the sbgn element (document) then
    // getPrefix() and mURI have not been set and just return defaults
    // thus a prefix does not appear to come from the right place !!!
    if (!prefix.empty() && getElementName() == "Extension")
    {
      if (!expectedAttributes.hasAttribute(name))
      {
        logUnknownAttribute(name, level, version, getElementName());
      }
    }
    else if (!expectedAttributes.hasAttribute(name))
    {
      logUnknownAttribute(name, level, version, getElementName(), prefix);
    }
  }

    bool assigned = attributes.readInto("metaid", mMetaId, getErrorLog(), false, getLine(), getColumn());

    if (assigned && mMetaId.empty())
    {
      logEmptyString("metaid", level, version,
                     SbgnTypeCode_toString(getTypeCode()));
    }

    if (isSetMetaId())
    {
      if (!SyntaxChecker::isValidXMLID(mMetaId))
      {
        logError(SbgnInvalidMetaidSyntax, getLevel(), getVersion(), "The metaid '" + mMetaId + "' does not conform to the syntax.");
      }
  }

}


/** @cond doxygenLibsbgnInternal */
/*
 * Returns the prefix of this element.
 */
std::string
SbgnBase::getPrefix() const
{
  std::string prefix = "";

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();
  string uri = getURI();
  if(xmlns && mSbgn)
  {
    prefix = xmlns->getPrefix(uri);
  }

  return prefix;
}


/*
 * Returns the prefix of this element.
 */
std::string
SbgnBase::getSbgnPrefix() const
{
  std::string prefix = "";

  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces *xmlns = getNamespaces();
  if (xmlns == NULL)
    return getPrefix();

  for (int i = 0; i < xmlns->getNumNamespaces(); i++)
  {
    string uri = xmlns->getURI(i);
    if (SbgnNamespaces::isSbgnNamespace(uri))
      return xmlns->getPrefix(i);
  }

  return getPrefix();
}

/*
 * Returns the root element of this element.
 *
 * @note The root element may not be an SbgnDocument element. For example,
 * this element is the root element if this element doesn't have a parent
 * SBGN object (i.e. mParentSbgnObject is NULL)
 */
SbgnBase*
SbgnBase::getRootElement()
{
  if (mSbgn)
  {
    return mSbgn;
  }
  else if (mParentSbgnObject)
  {
    return mParentSbgnObject->getRootElement();
  }
  else
  {
    return this;
  }
}


/*
 * Subclasses should override this method to write their XML attributes
 * to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 */
void
SbgnBase::writeAttributes (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  string sbgnPrefix    = getSbgnPrefix();
  if ( !mMetaId.empty() )
  {
    stream.writeAttribute("metaid", sbgnPrefix, mMetaId);
  }

}


/*
 *
 * Subclasses should override this method to write their xmlns attriubutes
 * (if any) to the XMLOutputStream.  Be sure to call your parents implementation
 * of this method as well.
 *
 */
void
SbgnBase::writeXMLNS (LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream& stream) const
{
  // do nothing.
}
/** @endcond */



/** @cond doxygenLibsbgnInternal */
/*
  * Checks that an SBGN SbgnListOf element has been populated.
  * If a listOf element has been declared with no elements,
  * an error is logged.
  */
void
SbgnBase::checkSbgnListOfPopulated(SbgnBase* object)
{
    // for now log the empty list
  if (object->getTypeCode() == SBGN_LIST_OF)
  {
    if (static_cast <SbgnListOf*> (object)->size() == 0)
    {
      SbgnErrorCode_t error = SbgnEmptyListElement;
      ostringstream errMsg;
      errMsg << object->getElementName() << " cannot be empty.";

      logError(error, getLevel(), getVersion(), errMsg.str());
    }
  }
}
/** @endcond */

//This assumes that the parent of the object is of the type SbgnListOf.  If this is not the case, it will need to be overridden.
int SbgnBase::removeFromParentAndDelete()
{
  SbgnBase* parent = getParentSbgnObject();

  if (parent==NULL) return LIBSBGN_OPERATION_FAILED;
  
  SbgnListOf* parentList = static_cast<SbgnListOf*>(parent);
  
  if (parentList == NULL) return LIBSBGN_OPERATION_FAILED;
  
  for (unsigned int i=0; i<parentList->size(); i++) 
  {
    SbgnBase* sibling = parentList->get(i);
    if (sibling == this) 
    {
      parentList->remove(i);
      delete this;
      return LIBSBGN_OPERATION_SUCCESS;
    }
  }
  return LIBSBGN_OPERATION_FAILED;
}

/** @cond doxygenLibsbgnInternal */
const std::string
SbgnBase::checkMathMLNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken elem)
{
  std::string prefix = "";
  unsigned int match = 0;
  int n;
  if (elem.getNamespaces().getLength() != 0)
  {
    for (n = 0; n < elem.getNamespaces().getLength(); n++)
    {
      if (!strcmp(elem.getNamespaces().getURI(n).c_str(),
                  "http://www.w3.org/1998/Math/MathML"))
      {
        match = 1;
        break;
      }
    }
  }
  if (match == 0)
  {
    if( mSbgn->getNamespaces() != NULL)
    /* check for implicit declaration */
    {
      for (n = 0; n < mSbgn->getNamespaces()->getLength(); n++)
      {
        if (!strcmp(mSbgn->getNamespaces()->getURI(n).c_str(),
                    "http://www.w3.org/1998/Math/MathML"))
        {
          match = 1;
          prefix = mSbgn->getNamespaces()->getPrefix(n);
          break;
        }
      }
    }
  }
  if (match == 0)
  {
    logError(SbgnInvalidMathElement, getLevel(), getVersion(), "The MathML namespace 'http://www.w3.org/1998/Math/MathML' was not found.");
  }

  return prefix;
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
void
SbgnBase::checkDefaultNamespace(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* xmlns,
                             const std::string& elementName,
                             const std::string& prefix)
{
  //
  // checks if the given default namespace (if any) is a valid
  // SBGN namespace
  //
  if (xmlns == NULL || xmlns->getLength() == 0)
    return;

  const std::string defaultURI = xmlns->getURI(prefix);
  if (defaultURI.empty() || mURI == defaultURI)
    return;

  // if this element (SbgnBase derived) has notes or annotation elements,
  // it is ok for them to be in the SBGN namespace!
  if ( SbgnNamespaces::isSbgnNamespace(defaultURI)
       && !SbgnNamespaces::isSbgnNamespace(mURI)
       && (elementName == "notes" || elementName == "extension"))
    return;

  static ostringstream errMsg;
  errMsg.str("");
  errMsg << "xmlns=\"" << defaultURI << "\" in <" << elementName
         << "> element is an invalid namespace." << endl;

  logError(SbgnNotSchemaConformant, getLevel(), getVersion(), errMsg.str());

}

/*
  * Checks the annotation does not declare an sbgn namespace.
  * If the annotation declares an sbgn namespace an error is logged.
  */
void
SbgnBase::checkExtension()
{
  unsigned int nNodes = 0;
  unsigned int match = 0;
  int n = 0;
  std::vector<std::string> uri_list;
  uri_list.clear();

  if (mExtension == NULL) return;

  //
  // checks if the given default namespace (if any) is a valid
  // SBGN namespace
  //
  const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces &xmlns = mExtension->getNamespaces();
  checkDefaultNamespace(&xmlns,"extension");

  while (nNodes < mExtension->getNumChildren())
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode topLevel = mExtension->getChild(nNodes);

    // the top level must be an element (so it should be a start)
    if (topLevel.isStart() == false)
    {
      logError(SbgnExtensionNotElement, getLevel(), getVersion());
      nNodes++;
      continue;
    }
    std::string uri = topLevel.getURI();
    std::string prefix = topLevel.getPrefix();

#ifdef USE_LIBXML
    // sometimes libxml does not catch an empty ns with a prefix
    if (uri.empty() && !prefix.empty())
    {
      logError(BadXMLPrefix);
      nNodes++;
      continue;
    }
#endif

    // cannot be other toplevel element with this uri
    if (!uri.empty())
    {
      if (find(uri_list.begin(), uri_list.end(), uri)
                                               != uri_list.end())
      {
        string msg = "An SBGN <" + getElementName() + "> element ";
        msg += "has an <annotation> child with multiple children with the same namespace.";
        logError(SbgnDuplicateExtensionNamespaces, getLevel(), getVersion(), msg);
      }
      uri_list.push_back(uri);
    }

    match = 0;
    n = 0;

    bool implicitNSdecl = false;
   // must have a namespace
    if (topLevel.getNamespaces().getLength() == 0)
    {
      // not on actual element - is it explicit ??
      if(mSbgn != NULL && mSbgn->getNamespaces() != NULL)
      /* check for implicit declaration */
      {
        for (n = 0; n < mSbgn->getNamespaces()->getLength(); n++)
        {
          if (!strcmp(mSbgn->getNamespaces()->getPrefix(n).c_str(),
                        prefix.c_str()))
          {
            implicitNSdecl = true;
            break;
          }
        }
     }


      if (!implicitNSdecl)
      {
        logError(SbgnMissingExtensionNamespace);
      }
    }
    // cannot declare sbgn namespace
    while(!match && n < topLevel.getNamespaces().getLength())
    {
      match += !strcmp(topLevel.getNamespaces().getURI(n).c_str(),
                                          "http://sbgn.org/libsbgn/pd/0.1");
      n++;
    }
    string msg = "An SBGN <" + getElementName() + "> element ";
    if (match > 0)
    {
      msg += "uses a restricted namespace on an element in its child <annotation>.";
      logError(SbgnNamespaceInExtension, getLevel(), getVersion(), msg);
      break;
    }

    if (implicitNSdecl && prefix.empty())
    {
      msg += "assumes the sbgn namespace on an element in its child <annotation>.";
      logError(SbgnMissingExtensionNamespace, getLevel(), getVersion(), msg);
    }
    nNodes++;
  }
}
/** @endcond */


/** @cond doxygenLibsbgnInternal */
/*
 * Checks that the XHTML is valid.
 * If the xhtml does not conform to the specification of valid xhtml within
 * an sbgn document, an error is logged.
 */
void
SbgnBase::checkXHTML(const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNode * xhtml)
{
  if (xhtml == NULL) return;

  const string&  name = xhtml->getName();
  unsigned int i, errorNS, errorXML, errorDOC, errorELEM;

  if (name == "notes")
  {
    errorNS   = SbgnNotesNotInXHTMLNamespace;
    errorXML  = SbgnNotesContainsXMLDecl;
    errorDOC  = SbgnNotesContainsDOCTYPE;
    errorELEM = SbgnInvalidNotesContent;
  }
  else                                  // We shouldn't ever get to this point.
  {
    logError(SbgnUnknown);
    return;
  }

  /*
  * errors relating to a misplaced XML or DOCTYPE declaration
  * will also cause a parser error.
  * since parsing will terminate at this error, then if it has occurred
  * it will be in the XML currently being checked and so a more
  * informative message can be added
  */
  for (i = 0; i < getErrorLog()->getNumErrors(); i++)
  {
    if (getErrorLog()->getError(i)->getErrorId() == BadXMLDeclLocation)
    {
      logError(errorXML);
    }
    if (getErrorLog()->getError(i)->getErrorId() == BadlyFormedXML)
    {
      logError(errorDOC);
    }
  }

  LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces* toplevelNS = (mSbgn) ? mSbgn->getNamespaces() : NULL;

  /*
  * namespace declaration is variable
  * if a whole html tag has been used
  * or a whole body tag then namespace can be implicitly declared
  */
  unsigned int children = xhtml->getNumChildren();

  if (children > 1)
  {
    for (i=0; i < children; i++)
    {
      if (SyntaxChecker::isAllowedElement(xhtml->getChild(i)))
      {
        if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(i),
                                                  toplevelNS))
        {
          logError(errorNS);
        }
      }
      else
      {
        logError(errorELEM);
      }
    }
  }
  else
  {
    /* only one element which can be html or body with either implicit/explicit
    * namespace declaration
    * OR could be one of the listed elements.
    */

    const string& top_name = xhtml->getChild(0).getName();

    if (top_name != "html" && top_name != "body"
      && !SyntaxChecker::isAllowedElement(xhtml->getChild(0)))
    {
      logError(errorELEM);
    }
    else
    {
      if (!SyntaxChecker::hasDeclaredNS(xhtml->getChild(0), toplevelNS))
      {
        logError(errorNS);
      }
      if (top_name == "html"
        && !SyntaxChecker::isCorrectHTMLNode(xhtml->getChild(0)))
      {
        logError(errorELEM);
      }
    }
  }
}
/** @endcond */
/** @cond doxygenLibsbgnInternal */
/* default for components that have no required attributes */
bool
SbgnBase::hasRequiredAttributes() const
{
  return true;
}

/* default for components that have no required elements */
bool
SbgnBase::hasRequiredElements() const
{
  return true;
}

int
SbgnBase::checkCompatibility(const SbgnBase * object) const
{
  if (object == NULL)
  {
    return LIBSBGN_OPERATION_FAILED;
  }
  else if (!(object->hasRequiredAttributes()) || !(object->hasRequiredElements()))
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else if (getLevel() != object->getLevel())
  {
    return LIBSBGN_LEVEL_MISMATCH;
  }
  else if (getVersion() != object->getVersion())
  {
    return LIBSBGN_VERSION_MISMATCH;
  }
  else if (this->matchesRequiredSbgnNamespacesForAddition(object) == false)
  {
    return LIBSBGN_NAMESPACES_MISMATCH;
  }
  else
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
}

/** @endcond */

/** @cond doxygenLibsbgnInternal */
/*
 * Stores the location (line and column) and any XML namespaces (for
 * roundtripping) declared on this SBGN (XML) element.
 */
void
SbgnBase::setSbgnBaseFields (const LIBSBML_CPP_NAMESPACE_QUALIFIER XMLToken& element)
{
  mLine   = element.getLine  ();
  mColumn = element.getColumn();

  if (element.getNamespaces().getLength() > 0)
  {
    LIBSBML_CPP_NAMESPACE_QUALIFIER XMLNamespaces tmpxmlns(element.getNamespaces());
    setNamespaces(&tmpxmlns);
  }
  else
  {
    setNamespaces(NULL);
  }
}


/*
 * Sets the XML namespace to which this element belongs to.
 */
int
SbgnBase::setElementNamespace(const std::string &uri)
{
  mURI = uri;

  return LIBSBGN_OPERATION_SUCCESS;
}

/*
 * Gets the XML namespace to which this element belongs to.
 */
const std::string&
SbgnBase::getElementNamespace() const
{
  return mURI;
}
/** @endcond */

#endif /* __cplusplus */


LIBSBGN_EXTERN
int
SbgnBase_getTypeCode (const SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getTypeCode() : SBGN_UNKNOWN;
}


LIBSBGN_EXTERN
const char *
SbgnBase_getMetaId (SbgnBase_t *sb)
{
  return (sb != NULL && sb->isSetMetaId()) ? sb->getMetaId().c_str() : NULL;
}


LIBSBGN_EXTERN
const SbgnDocument_t *
SbgnBase_getSbgnDocument (SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getSbgnDocument() : NULL;
}


LIBSBGN_EXTERN
const SbgnBase_t *
SbgnBase_getParentSbgnObject (SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getParentSbgnObject() : NULL;
}


LIBSBGN_EXTERN
const SbgnBase_t *
SbgnBase_getAncestorOfType (SbgnBase_t *sb, int type)
{
  return (sb != NULL) ? sb->getAncestorOfType(type) : NULL;
}


LIBSBGN_EXTERN
unsigned int
SbgnBase_getLevel (const SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getLevel() : SBGN_INT_MAX;
}


LIBSBGN_EXTERN
unsigned int
SbgnBase_getVersion (const SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getVersion() : SBGN_INT_MAX;
}


LIBSBGN_EXTERN
XMLNode_t *
SbgnBase_getNotes (SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getNotes() : NULL;
}


LIBSBGN_EXTERN
char*
SbgnBase_getNotesString (SbgnBase_t *sb)
{
  return (sb != NULL && sb->isSetNotes()) ?
    safe_strdup(sb->getNotesString().c_str()) : NULL;
}


LIBSBGN_EXTERN
XMLNode_t *
SbgnBase_getExtension (SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getExtension() : NULL;
}


LIBSBGN_EXTERN
char*
SbgnBase_getExtensionString (SbgnBase_t *sb)
{
  return (sb != NULL && sb->isSetExtension()) ?
    safe_strdup(sb->getExtensionString().c_str()) : NULL;
}


LIBSBGN_EXTERN
int
SbgnBase_isSetMetaId (const SbgnBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetMetaId() ) : 0;
}


LIBSBGN_EXTERN
int
SbgnBase_isSetNotes (const SbgnBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetNotes() ) : 0;
}


LIBSBGN_EXTERN
int
SbgnBase_isSetExtension (const SbgnBase_t *sb)
{
  return (sb != NULL) ? static_cast<int>( sb->isSetExtension() ) : 0;
}


LIBSBGN_EXTERN
int
SbgnBase_setMetaId (SbgnBase_t *sb, const char *metaid)
{
  if (sb != NULL)
    return (metaid == NULL) ? sb->unsetMetaId() : sb->setMetaId(metaid);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setNamespaces (SbgnBase_t *sb, XMLNamespaces_t *xmlns)
{
  if (sb != NULL)
    return sb->setNamespaces(xmlns);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setNotes (SbgnBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->setNotes(notes);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setNotesString (SbgnBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes);
    }
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setNotesStringAddMarkup (SbgnBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if(notes == NULL)
    {
      return sb->unsetNotes();
    }
    else
    {
      return sb->setNotes(notes, true);
    }
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_appendNotes (SbgnBase_t *sb, XMLNode_t *notes)
{
  if (sb != NULL)
    return sb->appendNotes(notes);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_appendNotesString (SbgnBase_t *sb, const char *notes)
{
  if (sb != NULL)
  {
    if (notes != NULL)
      return sb->appendNotes(notes);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setExtension (SbgnBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->setExtension(annotation);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_setExtensionString (SbgnBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if(annotation == NULL)
    {
      return sb->unsetExtension();
    }
    else
    {
      return sb->setExtension(annotation);
    }
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_appendExtension (SbgnBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
    return sb->appendExtension(annotation);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_appendExtensionString (SbgnBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->appendExtension(annotation);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}

LIBSBGN_EXTERN
int
SbgnBase_removeTopLevelExtensionElement (SbgnBase_t *sb, const char *name)
{
  if (sb != NULL)
  {
    if (name != NULL)
      return sb->removeTopLevelExtensionElement(name);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_removeTopLevelExtensionElementWithURI (SbgnBase_t *sb, const char *name,
                                              const char *uri)
{
  if (sb != NULL)
  {
    if (name != NULL && uri != NULL)
      return sb->removeTopLevelExtensionElement(name, uri);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_replaceTopLevelExtensionElement (SbgnBase_t *sb, XMLNode_t *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelExtensionElement(annotation);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_replaceTopLevelExtensionElementString (SbgnBase_t *sb, const char *annotation)
{
  if (sb != NULL)
  {
    if (annotation != NULL)
      return sb->replaceTopLevelExtensionElement(annotation);
    else
      return LIBSBGN_INVALID_OBJECT;
  }
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_unsetMetaId (SbgnBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetMetaId();
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_unsetNotes (SbgnBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetNotes();
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnBase_unsetExtension (SbgnBase_t *sb)
{
  if (sb != NULL)
    return sb->unsetExtension();
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
const char *
SbgnBase_getElementName (const SbgnBase_t *sb)
{
  return (sb != NULL && !(sb->getElementName().empty())) ?
    sb->getElementName().c_str() : NULL;
}


LIBSBGN_EXTERN
unsigned int
SbgnBase_getLine (const SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getLine() : 0;
}


LIBSBGN_EXTERN
unsigned int
SbgnBase_getColumn (const SbgnBase_t *sb)
{
  return (sb != NULL) ? sb->getColumn() : 0;
}


LIBSBGN_EXTERN
int
SbgnBase_hasValidLevelVersionNamespaceCombination(SbgnBase_t *sb)
{
  return (sb != NULL) ?
    static_cast <int> (sb->hasValidLevelVersionNamespaceCombination()) : 0;
}


LIBSBGN_EXTERN
int
SbgnBase_setUserData(SbgnBase_t* sb, void *userData)
{
  if (sb == NULL) return LIBSBGN_INVALID_OBJECT;
  return sb->setUserData(userData);
}


LIBSBGN_EXTERN
void *
SbgnBase_getUserData(const SbgnBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getUserData();
}

LIBSBGN_EXTERN
int
SbgnBase_isSetUserData(const SbgnBase_t* sb)
{
  if (sb == NULL) return 0;
  return static_cast <int>(sb->isSetUserData());
}

LIBSBGN_EXTERN
int
SbgnBase_unsetUserData(SbgnBase_t* sb)
{
  if (sb == NULL) return LIBSBGN_INVALID_OBJECT;
  return sb->unsetUserData();
}

LIBSBGN_EXTERN
SbgnBase_t*
SbgnBase_getElementByMetaId(SbgnBase_t* sb, const char* metaid)
{
  if (sb == NULL) return NULL;
  return sb->getElementByMetaId(metaid);
}

LIBSBGN_EXTERN
List_t*
SbgnBase_getAllElements(SbgnBase_t* sb)
{
  if (sb == NULL) return NULL;
  return sb->getAllElements();
}

/** @endcond */

LIBSBGN_CPP_NAMESPACE_END

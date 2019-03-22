/**
 * @file SbgnListOf.cpp
 * @brief Implementation of the SbgnListOf class.
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


#include <algorithm>
#include <functional>

#include <sbgn/SbgnVisitor.h>
#include <sbgn/SbgnListOf.h>
#include <sbgn/common/common.h>

/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBGN_CPP_NAMESPACE_BEGIN
#ifdef __cplusplus

/*
 * Creates a new SbgnListOf items.
 */
SbgnListOf::SbgnListOf (unsigned int level, unsigned int version)
: SbgnBase(level,version)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw SbgnConstructorException();
}


/*
 * Creates a new SbgnListOf items.
 */
SbgnListOf::SbgnListOf (SbgnNamespaces* sbgnns)
: SbgnBase(sbgnns)
{
    if (!hasValidLevelVersionNamespaceCombination())
    throw SbgnConstructorException();
}


/**
 * Used by the Destructor to delete each item in mItems.
 */
struct Delete : public unary_function<SbgnBase*, void>
{
  void operator() (SbgnBase* sb) { delete sb; }
};


/*
 * Destroys the given SbgnListOf and its constituent items.
 */
SbgnListOf::~SbgnListOf ()
{
  for_each( mItems.begin(), mItems.end(), Delete() );
}


/**
 * Used by the Copy Constructor to clone each item in mItems.
 */
struct Clone : public unary_function<SbgnBase*, SbgnBase*>
{
  SbgnBase* operator() (SbgnBase* sb) { return sb->clone(); }
};


/*
 * Copy constructor. Creates a copy of this SbgnListOf items.
 */
SbgnListOf::SbgnListOf (const SbgnListOf& orig) : SbgnBase(orig), mItems()
{
  mItems.resize( orig.size() );
  transform( orig.mItems.begin(), orig.mItems.end(), mItems.begin(), Clone() );
  connectToChild();
}


/*
 * Assignment operator
 */
SbgnListOf& SbgnListOf::operator=(const SbgnListOf& rhs)
{
  if(&rhs!=this)
  {
    this->SbgnBase::operator =(rhs);
    // Deletes existing items
    for_each( mItems.begin(), mItems.end(), Delete() );
    mItems.resize( rhs.size() );
    transform( rhs.mItems.begin(), rhs.mItems.end(), mItems.begin(), Clone() );
    connectToChild();
  }

  return *this;
}

/** @cond doxygenLibsbgnInternal */
bool
SbgnListOf::accept (SbgnVisitor& v) const
{
  v.visit(*this, getItemTypeCode() );
  for (unsigned int n = 0 ; n < mItems.size() && mItems[n]->accept(v); ++n) ;
  v.leave(*this, getItemTypeCode() );

  return true;
}
/** @endcond */


/*
 * @return a (deep) copy of this SbgnListOf items.
 */
SbgnListOf*
SbgnListOf::clone () const
{
  return new SbgnListOf(*this);
}


/*
 * Inserts the item at the given location.  This SbgnListOf items assumes
 * no ownership of item and will not delete it.
 */
int 
SbgnListOf::insert(int location, const SbgnBase* item)
{
  return insertAndOwn(location, item->clone());
}


/*
 * Inserts the item at the given location.  This SbgnListOf items assumes
 * ownership of item and will delete it.
 */
int 
SbgnListOf::insertAndOwn(int location, SbgnBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == SBGN_UNKNOWN )
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else
  {
    mItems.insert( mItems.begin() + location, item );
    item->connectToParent(this);
    return LIBSBGN_OPERATION_SUCCESS;
  }
}


/*
 * Adds item to the end of this SbgnListOf items.  This SbgnListOf items assumes
 * no ownership of item and will not delete it.
 */
int
SbgnListOf::append (const SbgnBase* item)
{
  SbgnBase* clone = item->clone();
  int ret = appendAndOwn( clone );
  if (ret != LIBSBGN_OPERATION_SUCCESS) 
  {
    delete clone;
  }
  return ret;
}


/*
 * Adds item to the end of this SbgnListOf items.  This SbgnListOf items assumes
 * ownership of item and will delete it.
 */
int
SbgnListOf::appendAndOwn (SbgnBase* item)
{
  /* no list elements yet */
  if (this->getItemTypeCode() == SBGN_UNKNOWN )
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else if (!isValidTypeForList(item))
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  else
  {
    mItems.push_back( item );
    item->connectToParent(this);
    return LIBSBGN_OPERATION_SUCCESS;
  }
}

int SbgnListOf::appendFrom(const SbgnListOf* list)
{
  if (list==NULL) return LIBSBGN_INVALID_OBJECT;
  
  if (getItemTypeCode() != list->getItemTypeCode()) 
  {
    return LIBSBGN_INVALID_OBJECT;
  }
  
  int ret = LIBSBGN_OPERATION_SUCCESS;
  
  for (unsigned int item=0; item<list->size(); item++) 
  {
    ret = appendAndOwn(list->get(item)->clone());
    if (ret != LIBSBGN_OPERATION_SUCCESS) return ret;
  }
  return ret;
}

/*
 * @return the nth item in this SbgnListOf items.
 */
const SbgnBase*
SbgnListOf::get (unsigned int n) const
{
  return (n < mItems.size()) ? mItems[n] : NULL;
}


/*
 * @return the nth item in this SbgnListOf items.
 */
SbgnBase*
SbgnListOf::get (unsigned int n)
{
  return const_cast<SbgnBase*>( static_cast<const SbgnListOf&>(*this).get(n) );
}


SbgnBase*
SbgnListOf::getElementBySId(const std::string& id)
{
  if (id.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    SbgnBase* obj = get(i);
    if (obj->getId() == id)
    {
      return obj;
    }
    
    obj = obj->getElementBySId(id);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


SbgnBase*
SbgnListOf::getElementByMetaId(const std::string& metaid)
{
  if (metaid.empty()) return NULL;
  
  for (unsigned int i = 0; i < size(); i++)
  {
    SbgnBase* obj = get(i);
    if (obj->getMetaId() == metaid)
    {
      return obj;
    }
    
    obj = obj->getElementByMetaId(metaid);
    
    if (obj != NULL) return obj;
  }

  return NULL;
}


List*
SbgnListOf::getAllElements()
{
  List* ret = new List();
  List* sublist = NULL;
  
  for (unsigned int i = 0; i < size(); i++) 
  {
    SbgnBase* obj = get(i);
    ret->add(obj);
    sublist = obj->getAllElements();
    ret->transferFrom(sublist);
    delete sublist;
  }

  return ret;
}


/*
 * Removes all items in this SbgnListOf object.
 *
 * If doDelete is true (default), all items in this SbgnListOf object are deleted
 * and cleared, and thus the caller doesn't have to delete those items.
 * Otherwise, all items are just cleared from this SbgnListOf object and the caller
 * is responsible for deleting all items (In this case, pointers to all items
 * should be stored elsewhere before calling this function by the caller).
 */
void
SbgnListOf::clear (bool doDelete)
{
  if (doDelete)
    for_each( mItems.begin(), mItems.end(), Delete() );
  
  mItems.clear();
}


int SbgnListOf::removeFromParentAndDelete()
{
  clear(true);
  unsetExtension();
  unsetMetaId();
  unsetNotes();
  return LIBSBGN_OPERATION_SUCCESS;
}

/*
 * Removes the nth item from this SbgnListOf items and returns a pointer to
 * it.  The caller owns the returned item and is responsible for deleting
 * it.
 */
SbgnBase*
SbgnListOf::remove (unsigned int n)
{
  SbgnBase* item = get(n);
  
  if (item != NULL) mItems.erase( mItems.begin() + n );
  
  return item;
}


/*
 * @return the number of items in this SbgnListOf items.
 */
unsigned int
SbgnListOf::size () const
{
  return (unsigned int)mItems.size();
}


/**
 * Used by SbgnListOf::setSbgnDocument().
 */
struct SetSbgnDocument : public unary_function<SbgnBase*, void>
{
  SbgnDocument* d;

  SetSbgnDocument (SbgnDocument* d) : d(d) { }
  void operator() (SbgnBase* sbase) { sbase->setSbgnDocument(d); }
};


/**
 * Used by SbgnListOf::setParentSbgnObject().
 */
struct SetParentSbgnObject : public unary_function<SbgnBase*, void>
{
  SbgnBase* sb;

  SetParentSbgnObject (SbgnBase *sb) : sb(sb) { }
  void operator() (SbgnBase* sbase) { sbase->connectToParent(sb); }
};

/** @cond doxygenLibsbgnInternal */

/*
 * Sets the parent SbgnDocument of this SBGN object.
 */
void
SbgnListOf::setSbgnDocument (SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);
  for_each( mItems.begin(), mItems.end(), SetSbgnDocument(d) );
}


/*
 * Sets this SBGN object to child SBGN objects (if any).
 * (Creates a child-parent relationship by the parent)
  */
void
SbgnListOf::connectToChild()
{
  SbgnBase::connectToChild();
  for_each( mItems.begin(), mItems.end(), SetParentSbgnObject(this) );
}

/** @endcond */


/*
 * @return the typecode (int) of this SBGN object or SBGN_UNKNOWN
 * (default).
 */
int
SbgnListOf::getTypeCode () const
{
  return SBGN_LIST_OF;
}


/*
 * @return the typecode (int) of SBGN objects contained in this SbgnListOf or
 * SBGN_UNKNOWN (default).
 */
int
SbgnListOf::getItemTypeCode () const
{
  return SBGN_UNKNOWN;
}


/*
 * @return the name of this element ie "listOf".
 
 */
const string&
SbgnListOf::getElementName () const
{
  static const string name = "listOf";
  return name;
}


/**
 * Used by SbgnListOf::writeElements().
 */
struct Write : public unary_function<SbgnBase*, void>
{
  XMLOutputStream& stream;

  Write (XMLOutputStream& s) : stream(s) { }
  void operator() (SbgnBase* sbase) { sbase->write(stream); }
};


/** @cond doxygenLibsbgnInternal */
/*
 * Subclasses should override this method to write out their contained
 * SBGN objects as XML elements.  Be sure to call your parents
 * implementation of this method as well.
 */
void
SbgnListOf::writeElements (XMLOutputStream& stream) const
{
  SbgnBase::writeElements(stream);
  for_each( mItems.begin(), mItems.end(), Write(stream) );
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
SbgnListOf::addExpectedAttributes(ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);
}


/*
 * Subclasses should override this method to read values from the given
 * XMLAttributes set into their specific fields.  Be sure to call your
 * parents implementation of this method as well.
 */
void
SbgnListOf::readAttributes (const XMLAttributes& attributes,
                       const ExpectedAttributes& expectedAttributes)
{
  SbgnBase::readAttributes(attributes,expectedAttributes);

  //
  // sboTerm: SBOTerm { use="optional" }  (L2v3 ->)
  // is read in SbgnBase::readAttributes()
  //
}

void 
SbgnListOf::writeAttributes (XMLOutputStream& stream) const
{
  SbgnBase::writeAttributes(stream);
}


bool
SbgnListOf::isValidTypeForList(SbgnBase * item)
{
  bool match = false;

  match = (item->getTypeCode() == getItemTypeCode());

  return match;
}
/** @endcond */



#endif /* __cplusplus */
/** @cond doxygenIgnored */
LIBSBGN_EXTERN
SbgnListOf_t *
SbgnListOf_create (unsigned int level, unsigned int version)
{
  return new(nothrow) SbgnListOf(level,version);
}


LIBSBGN_EXTERN
void
SbgnListOf_free (SbgnListOf_t *lo)
{
  if (lo != NULL)
  delete lo;
}


LIBSBGN_EXTERN
SbgnListOf_t *
SbgnListOf_clone (const SbgnListOf_t *lo)
{
  return (lo != NULL) ? static_cast<SbgnListOf_t*>( lo->clone() ) : NULL;
}


LIBSBGN_EXTERN
int
SbgnListOf_append (SbgnListOf_t *lo, const SbgnBase *item)
{
  if (lo != NULL)
    return lo->append(item);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnListOf_appendAndOwn (SbgnListOf_t *lo, SbgnBase_t *item)
{
  if (lo != NULL)
    return lo->appendAndOwn(item);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnListOf_appendFrom (SbgnListOf_t *lo, SbgnListOf_t *list)
{
  if (lo != NULL)
    return lo->appendFrom(list);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnListOf_insert (SbgnListOf_t *lo, int location, const SbgnBase_t *item)
{
  if (lo != NULL)
    return lo->insert(location, item);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
int
SbgnListOf_insertAndOwn (SbgnListOf_t *lo, int location, SbgnBase_t *item)
{
  if (lo != NULL)
    return lo->insertAndOwn(location, item);
  else
    return LIBSBGN_INVALID_OBJECT;
}


LIBSBGN_EXTERN
SbgnBase *
SbgnListOf_get (SbgnListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->get(n) : NULL;
}


LIBSBGN_EXTERN
void
SbgnListOf_clear (SbgnListOf_t *lo, int doDelete)
{
  if (lo != NULL)
  lo->clear(doDelete);
}


LIBSBGN_EXTERN
SbgnBase *
SbgnListOf_remove (SbgnListOf_t *lo, unsigned int n)
{
  return (lo != NULL) ? lo->remove(n) : NULL;
}


LIBSBGN_EXTERN
unsigned int
SbgnListOf_size (const SbgnListOf_t *lo)
{
  return (lo != NULL) ? lo->size() : SBGN_INT_MAX;
}


LIBSBGN_EXTERN
int
SbgnListOf_getItemTypeCode (const SbgnListOf_t *lo)
{
  return (lo != NULL) ? lo->getItemTypeCode() : SBGN_UNKNOWN;
}

/** @endcond */

LIBSBGN_CPP_NAMESPACE_END


/**
 * @file SbgnListOf.h
 * @brief Definition of the SbgnListOf class.
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
 *
 * @class SbgnListOf
 * @sbmlbrief{} TODO:Definition of the SbgnListOf class.
 */


#ifndef SbgnListOf_h
#define SbgnListOf_h


#include <sbgn/common/extern.h>
#include <sbgn/common/sbgnfwd.h>
#include <sbgn/SbgnTypeCodes.h>


#ifdef __cplusplus


#include <vector>
#include <algorithm>
#include <functional>

#include <sbgn/SbgnBase.h>

LIBSBGN_CPP_NAMESPACE_BEGIN

class SbgnVisitor;


/** @cond doxygenLibsbgnInternal */
/**
 * Used by SbgnListOf::get() to lookup an SbgnBase based by its id.
 */
#ifndef SWIG
template<class CNAME>
struct SbgnIdEq : public std::unary_function<SbgnBase*, bool>
{
  const std::string& id;

  SbgnIdEq (const std::string& id) : id(id) { }
  bool operator() (SbgnBase* sb) 
       { return static_cast <CNAME*> (sb)->getId() == id; }
};
#endif /* SWIG */
/** @endcond */


class LIBSBGN_EXTERN SbgnListOf : public SbgnBase
{
public:

  /**
   * Creates a new SbgnListOf object.
   *
   * @param level the SBGN Level; if not assigned, defaults to the
   * value of SBGN_DEFAULT_LEVEL.
   *
   * @param version the Version within the SBGN Level; if not assigned,
   * defaults to the value of SBGN_DEFAULT_VERSION.
   */
  SbgnListOf (unsigned int level   = SBGN_DEFAULT_LEVEL,
          unsigned int version = SBGN_DEFAULT_VERSION);


  /**
   * Creates a new SbgnListOf with a given SbgnNamespaces object.
   *
   * @param sbgnns the set of SBGN namespaces that this SbgnListOf should
   * contain.
   */
  SbgnListOf (SbgnNamespaces* sbgnns);


  /**
   * Destroys this SbgnListOf and the items inside it.
   */
  virtual ~SbgnListOf ();


  /**
   * Copy constructor; creates a copy of this SbgnListOf.
   *
   * @param orig the SbgnListOf instance to copy.
   */
  SbgnListOf (const SbgnListOf& orig);


  /**
   * Assignment operator for SbgnListOf.
   */
  SbgnListOf& operator=(const SbgnListOf& rhs);



  /** @cond doxygenLibsbgnInternal */
  /**
   * Accepts the given SbgnVisitor.
   *
   * @param v the SbgnVisitor instance to be used.
   *
   * @return the result of calling <code>v.visit()</code>, which indicates
   * whether the Visitor would like to visit the next item in the
   * list.
   */
  virtual bool accept (SbgnVisitor& v) const;
  /** @endcond */


  /**
   * Creates and returns a deep copy of this SbgnListOf object.
   *
   * @return the (deep) copy of this SbgnListOf object.
   */
  virtual SbgnListOf* clone () const;


  /**
   * Adds an item to the end of this SbgnListOf's list of items.
   *
   * This method makes a clone of the @p item handed to it.  This means that
   * when the SbgnListOf object is destroyed, the original items will not be
   * destroyed.  For a method with an alternative ownership behavior, see the
   * SbgnListOf::appendAndOwn(@if java SbgnBase@endif) method.
   *
   * @param item the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see appendAndOwn(SbgnBase* disownedItem)
   * @see appendFrom(const SbgnListOf* list)
   */
  int append (const SbgnBase* item);


  /**
   * Adds an item to the end of this SbgnListOf's list of items.
   *
   * This method does not clone the @p disownedItem handed to it; instead, it assumes
   * ownership of it.  This means that when the SbgnListOf is destroyed, the item
   * will be destroyed along with it.  For a method with an alternative
   * ownership behavior, see the SbgnListOf::append(SbgnBase* item) method.
   *
   * @param disownedItem the item to be added to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SbgnBase* item)
   * @see appendFrom(const SbgnListOf* list)
   */
  int appendAndOwn (SbgnBase* disownedItem);


  /**
   * Adds a clone of a list of items to this SbgnListOf's list.
   *
   * Note that because this clones the objects handed to it, the original
   * items will not be destroyed when this SbgnListOf object is destroyed.
   *
   * @param list a list of items to be added.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see append(const SbgnBase* item)
   * @see appendAndOwn(SbgnBase* disownedItem)
   */
  virtual int appendFrom (const SbgnListOf* list);


  /**
   * Inserts an item at a given position in this SbgnListOf's list of items.
   *
   * This variant of the method makes a clone of the @p item handed to it.
   * This means that when the SbgnListOf is destroyed, the original @p item will
   * <em>not</em> be destroyed.
   *
   * @param location the location in the list where to insert the item.
   * @param item the item to be inserted to the list.
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insertAndOwn(int location, SbgnBase* item)
   */
  int insert (int location, const SbgnBase* item);


  /**
   * Inserts an item at a given position in this SbgnListOf's list of items.
   *
   * This variant of the method does not make a clone of the @p disownedItem handed to it.
   * This means that when the SbgnListOf is destroyed, the original @p item
   * <em>will</em> be destroyed.
   *
   * @param location the location where to insert the item
   * @param disownedItem the item to be inserted to the list
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
   *
   * @see insert(int location, const SbgnBase* item)
   */
  int insertAndOwn(int location, SbgnBase* disownedItem);


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   *
   * @return the <em>n</em>th item in this SbgnListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual const SbgnBase* get (unsigned int n) const;


  /**
   * Get an item from the list.
   *
   * @param n the index number of the item to get.
   * 
   * @return the <em>n</em>th item in this SbgnListOf items, or a null pointer if
   * the index number @p n refers to a nonexistent position in this list.
   *
   * @see size()
   */
  virtual SbgnBase* get (unsigned int n);


  /**
   * Returns the first child element it can find with a specific "id"
   * attribute value, or @c NULL if no such object is found.
   *
   * @param id string representing the "id" attribute value of the
   * object to find.
   *
   * @return pointer to the first element found with the given identifier.
   */
  virtual SbgnBase* getElementBySId(const std::string& id);


  /**
   * Returns the first child element found with the given meta-identifier.
   *
   * @param metaid string representing the "metaid" attribute of the object
   * to find.
   *
   * @return the first element found with the given @p metaid, or @c NULL if
   * no such object is found.
   */
  virtual SbgnBase* getElementByMetaId(const std::string& metaid);


  /**
   * Returns a List of all child SbgnBase objects.
   *
   * The values returned include all children of the objects in this SbgnListOf
   * list, nested to an arbitrary depth.
   *
   * @return a List of pointers to all child objects.
   */
  virtual List* getAllElements();


  /**
   * Removes all items in this SbgnListOf object.
   *
   * If parameter @p doDelete is @c true (default), all items in this SbgnListOf
   * object are deleted and cleared, and thus the caller doesn't have to
   * delete those items.  Otherwise, all items are cleared only from this
   * SbgnListOf object; the caller is still responsible for deleting the actual
   * items.  (In the latter case, callers are advised to store pointers to
   * all items elsewhere before calling this function.)
   *
   * @param doDelete if @c true (default), all items are deleted and cleared.
   * Otherwise, all items are just cleared and not deleted.
   *
   * @ifnot hasDefaultArgs @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  void clear (bool doDelete = true);


  /**
   * Removes all items in this SbgnListOf object and deletes its properties too.
   *
   * This performs a call to clear() with an argument of @c true (thus removing
   * all the child objects in the list), followed by calls to various libSBGN
   * <code>unset<em>Foo</em></code> methods to delete everything else: CVTerm
   * objects, model history objects, etc.
   *
   * @if cpp Implementations of subclasses of SbgnListOf may need to override
   * this method if different handling of child objects is needed.@endif@~
   *
   * @copydetails doc_returns_success_code
   * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
   */
  virtual int removeFromParentAndDelete();


  /**
   * Removes the <em>n</em>th item from this SbgnListOf list of items and returns
   * it.
   *
   * The caller owns the returned item and is responsible for deleting it.
   *
   * @param n the index of the item to remove
   *
   * @see size()
   */
  virtual SbgnBase* remove (unsigned int n);


  /**
   * Returns number of items in this SbgnListOf list.
   *
   * @return the number of items in this SbgnListOf items.
   */
  unsigned int size () const;


  /** @cond doxygenLibsbgnInternal */
  /**
   * Sets the parent SbgnDocument of this SBGN object.
   *
   * @param d the SbgnDocument that should become the parent of this
   * SbgnListOf.
   */
  virtual void setSbgnDocument (SbgnDocument* d);
  /** @endcond */


  /** @cond doxygenLibsbgnInternal */
  /**
   * Sets this SBGN object to child SBGN objects (if any).
   * (Creates a child-parent relationship by the parent)
   *
   * Subclasses must override this function if they define
   * one ore more child elements.
   * Basically, this function needs to be called in
   * constructor, copy constructor and assignment operator.
   *
   * @if cpp
   * @see setSbgnDocument()
   * @see enablePackageInternal()
   * @endif
   */
  virtual void connectToChild ();
  /** @endcond */


  /**
   * Returns the libSBGN type code for this object, namely,
   * @sbgnconstant{SBGN_LIST_OF, SbgnTypeCode_t}.
   * 
   * @copydetails doc_what_are_typecodes
   *
   * @return the SBGN type code for this object:
   * @sbgnconstant{SBGN_LIST_OF, SbgnTypeCode_t} (default).
   *
   * @note The various SbgnListOf classes mostly differ from each other in what they
   * contain.  Hence, one must call getItemTypeCode() to fully determine the
   * class of this SBGN object.
   *
   * @see getItemTypeCode()
   * @see getElementName()
   */
  virtual int getTypeCode () const;


  /**
   * Get the type code of the objects contained in this SbgnListOf.
   *
   * Classes that inherit from the SbgnListOf class should override this method
   * to return the SBGN type code for the objects contained in this SbgnListOf.
   * If they do not, this method will return
   * @sbgnconstant{SBGN_UNKNOWN, SbgnTypeCode_t}
   *
   * @return The SbgnListOf base class contains no SBGN objects, and therefore
   * this method returns @sbgnconstant{SBGN_UNKNOWN, SbgnTypeCode_t}.
   *
   * @see getElementName()
   * @see getPackageName()
   */
  virtual int getItemTypeCode () const;


  /**
   * Returns the XML element name of this object, which for SbgnListOf, is
   * always @c "listOf".
   *
   * @return the XML name of this element.
   */
  virtual const std::string& getElementName () const;


  /** @cond doxygenLibsbgnInternal */
  /**
   * Subclasses should override this method to write out their contained
   * SBGN objects as XML elements.  Be sure to call your parents
   * implementation of this method as well.
   */
  virtual void writeElements (XMLOutputStream& stream) const;
  /** @endcond */


protected:
  /** @cond doxygenLibsbgnInternal */
  typedef std::vector<SbgnBase*>           ListItem;
  typedef std::vector<SbgnBase*>::iterator ListItemIter;

  /**
   * Subclasses should override this method to get the list of
   * expected attributes.
   * This function is invoked from corresponding readAttributes()
   * function.
   */
  virtual void addExpectedAttributes(ExpectedAttributes& attributes);

  
  /**
   * Subclasses should override this method to read values from the given
   * XMLAttributes set into their specific fields.  Be sure to call your
   * parents implementation of this method as well.
   */
  virtual void readAttributes (const XMLAttributes& attributes,
                               const ExpectedAttributes& expectedAttributes);

  /**
   * Subclasses should override this method to write their XML attributes
   * to the XMLOutputStream.  Be sure to call your parents implementation
   * of this method as well.  For example:
   *
   *   SbgnBase::writeAttributes(stream);
   *   stream.writeAttribute( "id"  , mId   );
   *   stream.writeAttribute( "name", mName );
   *   ...
   */
  virtual void writeAttributes (XMLOutputStream& stream) const;

  virtual bool isValidTypeForList(SbgnBase * item);

  ListItem mItems;

  /** @endcond */
};

LIBSBGN_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Creates a new instance of a SbgnListOf_t structure.
 *
 * @param level an unsigned int, the SBGN Level to assign to this
 * SbgnListOf_t structure.
 *
 * @param version an unsigned int, the SBGN Version to assign to this
 * SbgnListOf_t structure.
 *
 * @return a pointer to the newly-created SbgnListOf_t structure.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
SbgnListOf_t *
SbgnListOf_create (unsigned int level, unsigned int version);


/**
 * Frees the given SbgnListOf_t structure.
 *
 * This function assumes each item in the list is derived from SbgnBase_t.
 *
 * @param lo the SbgnListOf_t structure to be freed.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
void
SbgnListOf_free (SbgnListOf_t *lo);


/**
 * Creates a deep copy of the given SbgnListOf_t structure.
 *
 * @param lo the SbgnListOf_t structure to be copied.
 *
 * @return a (deep) copy of the given SbgnListOf_t structure, or a null
 * pointer if a failure occurred.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
SbgnListOf_t *
SbgnListOf_clone (const SbgnListOf_t *lo);


/**
 * Adds a copy of a given item to the end of a SbgnListOf_t list.
 *
 * @param lo the SbgnListOf_t structure to which the @p item should be appended.
 * @param item the item to append to the list.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see SbgnListOf_appendAndOwn()
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_append (SbgnListOf_t *lo, const SbgnBase_t *item);


/**
 * Adds the given item to the end of a SbgnListOf_t list.
 *
 * @param lo the SbgnListOf_t structure to which the @p disownedItem should be appended.
 * @param disownedItem the item to append to the list.
 *
 * Unlike SbgnListOf_append(), this function does not copy the @p disownedItem.
 * The given @p lo list will contain the original item.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @see SbgnListOf_append()
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_appendAndOwn (SbgnListOf_t *lo, SbgnBase_t *disownedItem);


/**
 * Adds clones a list of items from one list to another.
 *
 * @param lo the SbgnListOf_t list to which @p list will be appended.
 * @param list the list of items to append to @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_appendFrom (SbgnListOf_t *lo, SbgnListOf_t *list);


/**
 * Inserts a copy of an item into a SbgnListOf_t list at a given position.
 *
 * @param lo the list into which @p item will be inserted.
 * @param location the starting index for the @p item in the @p lo list.
 * @param item the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_insert (SbgnListOf_t *lo, int location, const SbgnBase_t *item);


/**
 * Inserts an item into a SbgnListOf_t list at a given position.
 *
 * Unlike SbgnListOf_insert(), this function does not clone @p disownedItem before
 * inserting it into @p lo, which means that @p lo becomes the owner.
 *
 * @param lo the list into which @p disownedItem will be inserted.
 * @param location the starting index for the @p disownedItem in the @p lo list.
 * @param disownedItem the item to append to insert into @p lo.
 *
 * @copydetails doc_returns_success_code
 * @li @sbgnconstant{LIBSBGN_OPERATION_SUCCESS, OperationReturnValues_t}
 * @li @sbgnconstant{LIBSBGN_INVALID_OBJECT, OperationReturnValues_t}
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_insertAndOwn (SbgnListOf_t *lo, int location, SbgnBase_t *disownedItem);


/**
 * Returns the <em>n</em>th item of a given list.
 *
 * @param lo the list from which to retrieve the item.
 * @param n the index of the item to retrieve.
 *
 * @return the <em>n</em>th item in this SbgnListOf items, or a null pointer if
 * the index number @p n refers to a nonexistent position in @p lo.
 *
 * @see SbgnListOf_size()
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
SbgnBase_t *
SbgnListOf_get (SbgnListOf_t *lo, unsigned int n);


/**
 * Removes all items in this SbgnListOf_t structure.
 *
 * If @p doDelete is true (non-zero), all items in this SbgnListOf_t structure
 * are both deleted and cleared, and thus the caller doesn't have to delete
 * those items.  Otherwise, if @p doDelete is false (zero), all items are
 * only cleared from this SbgnListOf_t structure and the caller is responsible
 * for deleting all items.  (In the latter case, callers are advised to store
 * pointers to all items elsewhere before calling this function.)
 *
 * @param lo the SbgnListOf_t structure to clear
 * @param doDelete whether to delete the items.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
void
SbgnListOf_clear (SbgnListOf_t *lo, int doDelete);


/**
 * Removes the <em>n</em>th item from this SbgnListOf_t list and returns it.
 *
 * The caller owns the returned item and is responsible for deleting it.
 *
 * @param lo the list from which the item should be removed.
 * @param n the index number of the item to remove.
 *
 * @return the item removed, or a null pointer if no item existed at the
 * index @p n.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
SbgnBase_t *
SbgnListOf_remove (SbgnListOf_t *lo, unsigned int n);


/**
 * Returns the number of items in this SbgnListOf_t items.
 *
 * @param lo the SbgnListOf_t structure to count.
 *
 * @return the number of items in @p lo.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
unsigned int
SbgnListOf_size (const SbgnListOf_t *lo);


/**
 * Get the type code of the objects contained in the given SbgnListOf_t
 * structure.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @param lo the SbgnListOf_t whose item type codes are sought.
 *
 * @return the type code corresponding to the objects in @p lo,
 * or @sbgnconstant{SBGN_UNKNOWN, SbgnTypeCode_t}.
 *
 * @memberof SbgnListOf_t
 */
LIBSBGN_EXTERN
int
SbgnListOf_getItemTypeCode (const SbgnListOf_t *lo);


END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* SbgnListOf_h */


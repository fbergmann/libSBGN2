/**
 * @file SbgnListOfGlyphs.cpp
 * @brief Implementation of the SbgnListOfGlyphs class.
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
#include <sbgn/SbgnListOfGlyphs.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnListOfGlyphs using the given SBGN Level and @ p version
 * values.
 */
SbgnListOfGlyphs::SbgnListOfGlyphs(unsigned int level, unsigned int version)
  : SbgnListOf(level, version)
  , mElementName("glyph")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnListOfGlyphs using the given SbgnNamespaces object @p
 * sbgnns.
 */
SbgnListOfGlyphs::SbgnListOfGlyphs(SbgnNamespaces *sbgnns)
  : SbgnListOf(sbgnns)
  , mElementName("glyph")
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnListOfGlyphs.
 */
SbgnListOfGlyphs::SbgnListOfGlyphs(const SbgnListOfGlyphs& orig)
  : SbgnListOf( orig )
  , mElementName ( orig.mElementName )
{
}


/*
 * Assignment operator for SbgnListOfGlyphs.
 */
SbgnListOfGlyphs&
SbgnListOfGlyphs::operator=(const SbgnListOfGlyphs& rhs)
{
  if (&rhs != this)
  {
    SbgnListOf::operator=(rhs);
    mElementName = rhs.mElementName;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnListOfGlyphs object.
 */
SbgnListOfGlyphs*
SbgnListOfGlyphs::clone() const
{
  return new SbgnListOfGlyphs(*this);
}


/*
 * Destructor for SbgnListOfGlyphs.
 */
SbgnListOfGlyphs::~SbgnListOfGlyphs()
{
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs.
 */
SbgnGlyph*
SbgnListOfGlyphs::get(unsigned int n)
{
  return static_cast<SbgnGlyph*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs.
 */
const SbgnGlyph*
SbgnListOfGlyphs::get(unsigned int n) const
{
  return static_cast<const SbgnGlyph*>(SbgnListOf::get(n));
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on its identifier.
 */
SbgnGlyph*
SbgnListOfGlyphs::get(const std::string& sid)
{
  return const_cast<SbgnGlyph*>(static_cast<const
    SbgnListOfGlyphs&>(*this).get(sid));
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on its identifier.
 */
const SbgnGlyph*
SbgnListOfGlyphs::get(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnGlyph>(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnGlyph*>
    (*result);
}


/*
 * Removes the nth SbgnGlyph from this SbgnListOfGlyphs and returns a pointer
 * to it.
 */
SbgnGlyph*
SbgnListOfGlyphs::remove(unsigned int n)
{
  return static_cast<SbgnGlyph*>(SbgnListOf::remove(n));
}


/*
 * Removes the SbgnGlyph from this SbgnListOfGlyphs based on its identifier and
 * returns a pointer to it.
 */
SbgnGlyph*
SbgnListOfGlyphs::remove(const std::string& sid)
{
  SbgnBase* item = NULL;
  vector<SbgnBase*>::iterator result;

  result = find_if(mItems.begin(), mItems.end(), SbgnIdEq<SbgnGlyph>(sid));

  if (result != mItems.end())
  {
    item = *result;
    mItems.erase(result);
  }

  return static_cast <SbgnGlyph*> (item);
}


/*
 * Adds a copy of the given SbgnGlyph to this SbgnListOfGlyphs.
 */
int
SbgnListOfGlyphs::addGlyph(const SbgnGlyph* sg)
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
  else
  {
    return append(sg);
  }
}


/*
 * Get the number of SbgnGlyph objects in this SbgnListOfGlyphs.
 */
unsigned int
SbgnListOfGlyphs::getNumGlyphs() const
{
  return size();
}


/*
 * Creates a new SbgnGlyph object, adds it to this SbgnListOfGlyphs object and
 * returns the SbgnGlyph object created.
 */
SbgnGlyph*
SbgnListOfGlyphs::createGlyph()
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
    appendAndOwn(sg);
  }

  return sg;
}


/*
 * Used by SbgnListOfGlyphs::get() to lookup a SbgnGlyph based on its
 * CompartmentRef.
 */
struct SbgnIdEqCR : public std::unary_function<SbgnBase*, bool>
{
  const string& id;
   
  SbgnIdEqCR (const string& id) : id(id) { }
  bool operator() (SbgnBase* sb)
  {
  return (static_cast<SbgnGlyph*>(sb)->getCompartmentRef() == id);
  }
};


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the CompartmentRef to
 * which it refers.
 */
const SbgnGlyph*
SbgnListOfGlyphs::getByCompartmentRef(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEqCR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnGlyph*>
    (*result);
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the CompartmentRef to
 * which it refers.
 */
SbgnGlyph*
SbgnListOfGlyphs::getByCompartmentRef(const std::string& sid)
{
  return const_cast<SbgnGlyph*>(static_cast<const
    SbgnListOfGlyphs&>(*this).getByCompartmentRef(sid));
}


/*
 * Used by SbgnListOfGlyphs::get() to lookup a SbgnGlyph based on its MapRef.
 */
struct SbgnIdEqMR : public std::unary_function<SbgnBase*, bool>
{
  const string& id;
   
  SbgnIdEqMR (const string& id) : id(id) { }
  bool operator() (SbgnBase* sb)
  {
  return (static_cast<SbgnGlyph*>(sb)->getMapRef() == id);
  }
};


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the MapRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnListOfGlyphs::getByMapRef(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEqMR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnGlyph*>
    (*result);
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the MapRef to which it
 * refers.
 */
SbgnGlyph*
SbgnListOfGlyphs::getByMapRef(const std::string& sid)
{
  return const_cast<SbgnGlyph*>(static_cast<const
    SbgnListOfGlyphs&>(*this).getByMapRef(sid));
}


/*
 * Used by SbgnListOfGlyphs::get() to lookup a SbgnGlyph based on its TagRef.
 */
struct SbgnIdEqTR : public std::unary_function<SbgnBase*, bool>
{
  const string& id;
   
  SbgnIdEqTR (const string& id) : id(id) { }
  bool operator() (SbgnBase* sb)
  {
  return (static_cast<SbgnGlyph*>(sb)->getTagRef() == id);
  }
};


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the TagRef to which it
 * refers.
 */
const SbgnGlyph*
SbgnListOfGlyphs::getByTagRef(const std::string& sid) const
{
  vector<SbgnBase*>::const_iterator result;
  result = find_if(mItems.begin(), mItems.end(), SbgnIdEqTR(sid));
  return (result == mItems.end()) ? 0 : static_cast <const SbgnGlyph*>
    (*result);
}


/*
 * Get a SbgnGlyph from the SbgnListOfGlyphs based on the TagRef to which it
 * refers.
 */
SbgnGlyph*
SbgnListOfGlyphs::getByTagRef(const std::string& sid)
{
  return const_cast<SbgnGlyph*>(static_cast<const
    SbgnListOfGlyphs&>(*this).getByTagRef(sid));
}


/*
 * Returns the XML element name of this SbgnListOfGlyphs object.
 */
const std::string&
SbgnListOfGlyphs::getElementName() const
{
  return mElementName;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the XML name of this SbgnListOfGlyphs object.
 */
void
SbgnListOfGlyphs::setElementName(const std::string& name)
{
  mElementName = name;
}

/** @endcond */


/*
 * Returns the libSBGN type code for this SbgnListOfGlyphs object.
 */
int
SbgnListOfGlyphs::getTypeCode() const
{
  return SBGN_LIST_OF;
}


/*
 * Returns the libSBGN type code for the SBGN objects contained in this
 * SbgnListOfGlyphs object.
 */
int
SbgnListOfGlyphs::getItemTypeCode() const
{
  return SBGN_SBGNML_GLYPH;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Creates a new SbgnGlyph in this SbgnListOfGlyphs
 */
SbgnBase*
SbgnListOfGlyphs::createObject(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLInputStream&
  stream)
{
  const std::string& name = stream.peek().getName();
  SbgnBase* object = NULL;

  if (name == "glyph")
  {
    object = new SbgnGlyph(getSbgnNamespaces());
    appendAndOwn(object);
  }

  return object;
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Get a SbgnGlyph_t from the SbgnListOf_t.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_getGlyph(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfGlyphs*>(slo)->get(n);
}


/*
 * Get a SbgnGlyph_t from the SbgnListOf_t based on its identifier.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_getById(SbgnListOf_t* slo, const char *sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfGlyphs*>(slo)->get(sid) : NULL;
}


/*
 * Removes the nth SbgnGlyph_t from this SbgnListOf_t and returns a pointer to
 * it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_remove(SbgnListOf_t* slo, unsigned int n)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return static_cast <SbgnListOfGlyphs*>(slo)->remove(n);
}


/*
 * Removes the SbgnGlyph_t from this SbgnListOf_t based on its identifier and
 * returns a pointer to it.
 */
LIBSBGN_EXTERN
SbgnGlyph_t*
SbgnListOfGlyphs_removeById(SbgnListOf_t* slo, const char* sid)
{
  if (slo == NULL)
  {
    return NULL;
  }

  return (sid != NULL) ? static_cast <SbgnListOfGlyphs*>(slo)->remove(sid) :
    NULL;
}




LIBSBGN_CPP_NAMESPACE_END



/**
 * @file SbgnState.cpp
 * @brief Implementation of the SbgnState class.
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
#include <sbgn/SbgnState.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;



LIBSBGN_CPP_NAMESPACE_BEGIN




#ifdef __cplusplus


/*
 * Creates a new SbgnState using the given SBGN Level and @ p version values.
 */
SbgnState::SbgnState(unsigned int level, unsigned int version)
  : SbgnBase(level, version)
  , mVariable ("")
  , mValue ("")
{
  setSbgnNamespacesAndOwn(new SbgnNamespaces(level, version));
}


/*
 * Creates a new SbgnState using the given SbgnNamespaces object @p sbgnns.
 */
SbgnState::SbgnState(SbgnNamespaces *sbgnns)
  : SbgnBase(sbgnns)
  , mVariable ("")
  , mValue ("")
{
  setElementNamespace(sbgnns->getURI());
}


/*
 * Copy constructor for SbgnState.
 */
SbgnState::SbgnState(const SbgnState& orig)
  : SbgnBase( orig )
  , mVariable ( orig.mVariable )
  , mValue ( orig.mValue )
{
}


/*
 * Assignment operator for SbgnState.
 */
SbgnState&
SbgnState::operator=(const SbgnState& rhs)
{
  if (&rhs != this)
  {
    SbgnBase::operator=(rhs);
    mVariable = rhs.mVariable;
    mValue = rhs.mValue;
  }

  return *this;
}


/*
 * Creates and returns a deep copy of this SbgnState object.
 */
SbgnState*
SbgnState::clone() const
{
  return new SbgnState(*this);
}


/*
 * Destructor for SbgnState.
 */
SbgnState::~SbgnState()
{
}


/*
 * Returns the value of the "variable" attribute of this SbgnState.
 */
const std::string&
SbgnState::getVariable() const
{
  return mVariable;
}


/*
 * Returns the value of the "value" attribute of this SbgnState.
 */
const std::string&
SbgnState::getValue() const
{
  return mValue;
}


/*
 * Predicate returning @c true if this SbgnState's "variable" attribute is set.
 */
bool
SbgnState::isSetVariable() const
{
  return (mVariable.empty() == false);
}


/*
 * Predicate returning @c true if this SbgnState's "value" attribute is set.
 */
bool
SbgnState::isSetValue() const
{
  return (mValue.empty() == false);
}


/*
 * Sets the value of the "variable" attribute of this SbgnState.
 */
int
SbgnState::setVariable(const std::string& variable)
{
  mVariable = variable;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Sets the value of the "value" attribute of this SbgnState.
 */
int
SbgnState::setValue(const std::string& value)
{
  mValue = value;
  return LIBSBGN_OPERATION_SUCCESS;
}


/*
 * Unsets the value of the "variable" attribute of this SbgnState.
 */
int
SbgnState::unsetVariable()
{
  mVariable.erase();

  if (mVariable.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Unsets the value of the "value" attribute of this SbgnState.
 */
int
SbgnState::unsetValue()
{
  mValue.erase();

  if (mValue.empty() == true)
  {
    return LIBSBGN_OPERATION_SUCCESS;
  }
  else
  {
    return LIBSBGN_OPERATION_FAILED;
  }
}


/*
 * Returns the XML element name of this SbgnState object.
 */
const std::string&
SbgnState::getElementName() const
{
  static const string name = "state";
  return name;
}


/*
 * Returns the libSBGN type code for this SbgnState object.
 */
int
SbgnState::getTypeCode() const
{
  return SBGN_SBGNML_STATE;
}


/*
 * Predicate returning @c true if all the required attributes for this
 * SbgnState object have been set.
 */
bool
SbgnState::hasRequiredAttributes() const
{
  bool allPresent = true;

  return allPresent;
}



/** @cond doxygenlibSBGNInternal */

/*
 * Write any contained elements
 */
void
SbgnState::writeElements(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeElements(stream);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Accepts the given SbgnVisitor
 */
bool
SbgnState::accept(SbgnVisitor& v) const
{
  return false;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the parent SbgnDocument
 */
void
SbgnState::setSbgnDocument(SbgnDocument* d)
{
  SbgnBase::setSbgnDocument(d);
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::getAttribute(const std::string& attributeName, bool& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::getAttribute(const std::string& attributeName, int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::getAttribute(const std::string& attributeName, double& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::getAttribute(const std::string& attributeName,
                        unsigned int& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Gets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::getAttribute(const std::string& attributeName,
                        std::string& value) const
{
  int return_value = SbgnBase::getAttribute(attributeName, value);

  if (return_value == LIBSBGN_OPERATION_SUCCESS)
  {
    return return_value;
  }

  if (attributeName == "variable")
  {
    value = getVariable();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }
  else if (attributeName == "value")
  {
    value = getValue();
    return_value = LIBSBGN_OPERATION_SUCCESS;
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Predicate returning @c true if this SbgnState's attribute "attributeName" is
 * set.
 */
bool
SbgnState::isSetAttribute(const std::string& attributeName) const
{
  bool value = SbgnBase::isSetAttribute(attributeName);

  if (attributeName == "variable")
  {
    value = isSetVariable();
  }
  else if (attributeName == "value")
  {
    value = isSetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::setAttribute(const std::string& attributeName, bool value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::setAttribute(const std::string& attributeName, int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::setAttribute(const std::string& attributeName, double value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::setAttribute(const std::string& attributeName, unsigned int value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Sets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::setAttribute(const std::string& attributeName,
                        const std::string& value)
{
  int return_value = SbgnBase::setAttribute(attributeName, value);

  if (attributeName == "variable")
  {
    return_value = setVariable(value);
  }
  else if (attributeName == "value")
  {
    return_value = setValue(value);
  }

  return return_value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Unsets the value of the "attributeName" attribute of this SbgnState.
 */
int
SbgnState::unsetAttribute(const std::string& attributeName)
{
  int value = SbgnBase::unsetAttribute(attributeName);

  if (attributeName == "variable")
  {
    value = unsetVariable();
  }
  else if (attributeName == "value")
  {
    value = unsetValue();
  }

  return value;
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Adds the expected attributes for this element
 */
void
SbgnState::addExpectedAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER
  ExpectedAttributes& attributes)
{
  SbgnBase::addExpectedAttributes(attributes);

  attributes.add("variable");

  attributes.add("value");
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Reads the expected attributes into the member data variables
 */
void
SbgnState::readAttributes(
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
        log->logError(SbgnmlStateAllowedAttributes, level, version, details,
          getLine(), getColumn());
      }
    }
  }

  // 
  // variable string (use = "optional" )
  // 

  assigned = attributes.readInto("variable", mVariable);

  if (assigned == true)
  {
    if (mVariable.empty() == true)
    {
      logEmptyString(mVariable, level, version, "<SbgnState>");
    }
  }

  // 
  // value string (use = "optional" )
  // 

  assigned = attributes.readInto("value", mValue);

  if (assigned == true)
  {
    if (mValue.empty() == true)
    {
      logEmptyString(mValue, level, version, "<SbgnState>");
    }
  }
}

/** @endcond */



/** @cond doxygenlibSBGNInternal */

/*
 * Writes the attributes to the stream
 */
void
SbgnState::writeAttributes(LIBSBML_CPP_NAMESPACE_QUALIFIER XMLOutputStream&
  stream) const
{
  SbgnBase::writeAttributes(stream);

  if (isSetVariable() == true)
  {
    stream.writeAttribute("variable", getPrefix(), mVariable);
  }

  if (isSetValue() == true)
  {
    stream.writeAttribute("value", getPrefix(), mValue);
  }
}

/** @endcond */




#endif /* __cplusplus */


/*
 * Creates a new SbgnState_t using the given SBGN Level and @ p version values.
 */
LIBSBGN_EXTERN
SbgnState_t *
SbgnState_create(unsigned int level, unsigned int version)
{
  return new SbgnState(level, version);
}


/*
 * Creates and returns a deep copy of this SbgnState_t object.
 */
LIBSBGN_EXTERN
SbgnState_t*
SbgnState_clone(const SbgnState_t* ss)
{
  if (ss != NULL)
  {
    return static_cast<SbgnState_t*>(ss->clone());
  }
  else
  {
    return NULL;
  }
}


/*
 * Frees this SbgnState_t object.
 */
LIBSBGN_EXTERN
void
SbgnState_free(SbgnState_t* ss)
{
  if (ss != NULL)
  {
    delete ss;
  }
}


/*
 * Returns the value of the "variable" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
char *
SbgnState_getVariable(const SbgnState_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getVariable().empty() ? NULL :
    safe_strdup(ss->getVariable().c_str());
}


/*
 * Returns the value of the "value" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
char *
SbgnState_getValue(const SbgnState_t * ss)
{
  if (ss == NULL)
  {
    return NULL;
  }

  return ss->getValue().empty() ? NULL : safe_strdup(ss->getValue().c_str());
}


/*
 * Predicate returning @c 1 (true) if this SbgnState_t's "variable" attribute
 * is set.
 */
LIBSBGN_EXTERN
int
SbgnState_isSetVariable(const SbgnState_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetVariable()) : 0;
}


/*
 * Predicate returning @c 1 (true) if this SbgnState_t's "value" attribute is
 * set.
 */
LIBSBGN_EXTERN
int
SbgnState_isSetValue(const SbgnState_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->isSetValue()) : 0;
}


/*
 * Sets the value of the "variable" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
int
SbgnState_setVariable(SbgnState_t * ss, const char * variable)
{
  return (ss != NULL) ? ss->setVariable(variable) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Sets the value of the "value" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
int
SbgnState_setValue(SbgnState_t * ss, const char * value)
{
  return (ss != NULL) ? ss->setValue(value) : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "variable" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
int
SbgnState_unsetVariable(SbgnState_t * ss)
{
  return (ss != NULL) ? ss->unsetVariable() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Unsets the value of the "value" attribute of this SbgnState_t.
 */
LIBSBGN_EXTERN
int
SbgnState_unsetValue(SbgnState_t * ss)
{
  return (ss != NULL) ? ss->unsetValue() : LIBSBGN_INVALID_OBJECT;
}


/*
 * Predicate returning @c 1 (true) if all the required attributes for this
 * SbgnState_t object have been set.
 */
LIBSBGN_EXTERN
int
SbgnState_hasRequiredAttributes(const SbgnState_t * ss)
{
  return (ss != NULL) ? static_cast<int>(ss->hasRequiredAttributes()) : 0;
}




LIBSBGN_CPP_NAMESPACE_END



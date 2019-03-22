/**
 * @file SbgnError.cpp
 * @brief Implementation of the SbgnError class.
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



#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include <sbml/xml/XMLError.h>

#include <sbgn/SbgnError.h>
#include <sbgn/SbgnErrorTable.h>


/** @cond doxygenIgnored */

using namespace std;

/** @endcond */

LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

/** @cond doxygenLibsbgnInternal **/
/** 
 * Helper function for SbgnError().  Takes an index, SBGN level and version,
 * and returns the appropriate field for the severity code out of the
   sbgnErrorTable entry.
 */
static const unsigned int
getSeverityForEntry(unsigned int index,
                    unsigned int level,
                    unsigned int version)
{
  if ( level == 1 )
  {
    switch (version)
    {
    case 1:
    default:
      return sbgnErrorTable[index].l1v1_severity;
    }
  }
  else
  {
    return sbgnErrorTable[index].l1v1_severity;
  }
}


/*
 * @return the severity as a string for the given @n code.
 */
std::string SbgnError::stringForSeverity(unsigned int code) const
{
  /* it should never happen that an error ends up with a severity
   * that is not in the XMLSeverity_t enumeration
   * but just in case:
   */
  if (code < LIBSBGN_SEV_SCHEMA_ERROR)
  {
    return XMLError::stringForSeverity(code);
  }
  else
  {
    switch (code)
    {
      case LIBSBGN_SEV_SCHEMA_ERROR:
        return "Schema error";
        break;

      case LIBSBGN_SEV_GENERAL_WARNING:
        return "General warning";
        break;

      case LIBSBGN_SEV_NOT_APPLICABLE:
        return "Not applicable";
        break;

      default:
        return "";
        break;
    }
  }
}

/*
 * Table of strings corresponding to the values from SbgnErrorCategory_t.
 * The enumeration starts at a number higher than 0, so each entry is keyed
 * by its enum value.
 *
 * A similar table for severity strings is currently unnecessary because
 * libSBGN never returns anything more than the XMLSeverityCode_t values.
 */
static struct sbgnCategoryString {
  unsigned int catCode;
  const char * catString;
} sbgnCategoryStringTable[] = 
{
  { LIBSBGN_CAT_SBGN,                   "General SBGN conformance"    },
  { LIBSBGN_CAT_GENERAL_CONSISTENCY,	"SBGN component consistency"  },
  { LIBSBGN_CAT_IDENTIFIER_CONSISTENCY,	"SBGN identifier consistency" },
  { LIBSBGN_CAT_MATHML_CONSISTENCY,     "MathML consistency"          },
  { LIBSBGN_CAT_INTERNAL_CONSISTENCY,   "Internal consistency"        }
};

static unsigned int sbgnCategoryStringTableSize
  = sizeof(sbgnCategoryStringTable)/sizeof(sbgnCategoryStringTable[0]);

/*
 * @return the category as a string for the given @n code.
 */
std::string SbgnError::stringForCategory(unsigned int code) const
{
  if ( code >= LIBSBGN_CAT_SBGN )
  {
    for ( unsigned int i = 0; i < sbgnCategoryStringTableSize; i++ )
      if ( sbgnCategoryStringTable[i].catCode == code )
        return sbgnCategoryStringTable[i].catString;
  }

  return XMLError::stringForCategory(code);
}
/** @endcond **/


SbgnError::SbgnError (  const unsigned int errorId
                      , const unsigned int level
                      , const unsigned int version 
                      , const std::string& details
                      , const unsigned int line
                      , const unsigned int column
                      , const unsigned int severity
                      , const unsigned int category) :
    XMLError((int)errorId, details, line, column, severity, category)
{
  // Check if the given @p id is one we have in our table of error codes.  If
  // it is, fill in the fields of the error object with the appropriate
  // content.  If it's not in the table, take the content as-is.

  if ( /*mErrorId >= 0 &&*/ mErrorId < XMLErrorCodesUpperBound )
  {
    // The error was caught during the XML read and the XMLError
    // constructor will have filled in all the right pieces.
    return;
  }
  else if ( mErrorId > XMLErrorCodesUpperBound
            && mErrorId < SbgnCodesUpperBound )
  {
    unsigned int tableSize = sizeof(sbgnErrorTable)/sizeof(sbgnErrorTable[0]);
    unsigned int index = 0;

    for ( unsigned int i = 0; i < tableSize; i++ )
    {
      if ( mErrorId == sbgnErrorTable[i].code )
      {
        index = i;
        break;
      }
    }

    if ( index == 0 && mErrorId != SbgnUnknown )
    {
      // The id is in the range of error numbers that are supposed to be in
      // the SBGN layer, but it's NOT in our table. This is an internal error.
      // Unfortunately, we don't have an error log or anywhere to report it
      // except the measure of last resort: the standard error output.
    
      //cerr << "Internal error: unknown error code '" << mErrorId
      //     << "' encountered while processing error." << endl;
      //return;
      // Changed this behaviour

      // Now we log the error as an UnKnown Error and mark it as invalid

      mValidError = false;
    }

    // The rest of this block massages the results to account for how some
    // internal bookkeeping is done in libSBGN 3, and also to provide
    // additional info in the messages.

    mCategory     = sbgnErrorTable[index].category;
    mShortMessage = sbgnErrorTable[index].shortMessage;

    ostringstream newMsg;
    mSeverity = getSeverityForEntry(index, level, version);

    if (mValidError == false)
      mSeverity = LIBSBGN_SEV_WARNING;

    if (mSeverity == LIBSBGN_SEV_SCHEMA_ERROR)
    {
      mErrorId  = SbgnNotSchemaConformant;
      mSeverity = LIBSBGN_SEV_ERROR;
      newMsg << sbgnErrorTable[3].message << " "; // FIXME
    }
    else if (mSeverity == LIBSBGN_SEV_GENERAL_WARNING)
    {

      mSeverity = LIBSBGN_SEV_WARNING;
      newMsg << "[Although SBGN Level " << level
             << " Version " << version << " does not explicitly define the "
             << "following as an error, other Levels and/or Versions "
             << "of SBGN do.] " << endl;
    }

    // Finish updating the (full) error message.

    if (!((string)sbgnErrorTable[index].message).empty()) {
      newMsg << sbgnErrorTable[index].message << endl;
    }

    // look for individual references
    // if the code for this error does not yet exist skip

    if (sbgnErrorTable[index].reference.ref_l1v1 != NULL)
    {

      std::string ref;
      switch(level)
      {
      case 1:
      default:
       switch(version)
        {
        case 1:
        default:
          ref = sbgnErrorTable[index].reference.ref_l1v1;
        break;
        }
       break;
      }

      if (!ref.empty())
      {
        newMsg << "Reference: " << ref << endl;
      }
    }
    if (!details.empty())
    {
      newMsg << " " << details;
      if (details[details.size()-1] != '\n') {
        newMsg << endl;
      }
    }      
    mMessage  = newMsg.str();

    // We mucked around with the severity code and (maybe) category code
    // after creating the XMLError object, so we may have to update the
    // corresponding strings.

    mSeverityString = stringForSeverity(mSeverity);
    mCategoryString = stringForCategory(mCategory);

    return;
  }


   // It's not an error code in the SBGN layer, so assume the caller has
  // filled in all the relevant additional data.  (If they didn't, the
  // following merely assigns the defaults.)
  mMessage        = details;
  mSeverity       = severity;
  mCategory       = category;
  mSeverityString = stringForSeverity(mSeverity);
  mCategoryString = stringForCategory(mCategory);
}


/*
 * Copy Constructor
 */
SbgnError::SbgnError(const SbgnError& orig) :
 XMLError(orig)
{
}


 /*
 * Destroys this SbgnError.
 */
SbgnError::~SbgnError ()
{
}


/** @cond doxygenLibsbgnInternal **/
/*
 * clone function
 */
SbgnError* 
SbgnError::clone() const
{
  return new SbgnError(*this);
}
/** @endcond **/


/** @cond doxygenLibsbgnInternal **/
/*
 * Outputs this SbgnError to stream in the following format (and followed by
 * a newline):
 *
 *   line: (error_id [severity]) message
 */
void
SbgnError::print(ostream& s) const
{
    s << "line " << getLine() << ": ("
      << setfill('0') << setw(5) << getErrorId()
      << " [" << getSeverityAsString() << "]) "
      << getMessage() << endl;
}
/** @endcond **/


#endif /* __cplusplus */

LIBSBGN_CPP_NAMESPACE_END


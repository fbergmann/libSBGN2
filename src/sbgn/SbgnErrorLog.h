/**
 * @file SbgnErrorLog.h
 * @brief Definition of the SbgnErrorLog class.
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
 * @class SbgnErrorLog
 * @sbmlbrief{} TODO:Definition of the SbgnErrorLog class.
 */


#ifndef SbgnErrorLog_h
#define SbgnErrorLog_h


#include <sbgn/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sbml/xml/XMLErrorLog.h>
#include <sbgn/SbgnError.h>


#ifdef __cplusplus

#include <vector>

LIBSBGN_CPP_NAMESPACE_BEGIN

class LIBSBGN_EXTERN SbgnErrorLog : public XMLErrorLog
{
public:

  /**
   * Returns the <i>n</i>th SbgnError object in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   *
   * @return the <i>n</i>th SbgnError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java XMLErrorLog::getNumErrors()@else getNumErrors()@endif.
   *
   * @see getNumErrors()
   */
  const SbgnError* getError (unsigned int n) const;


  /**
   * Returns the <i>n</i>th SbgnError object with given severity in this log.
   *
   * Index @p n is counted from 0.  Callers should first inquire about the
   * number of items in the log by using the
   * @if java SbgnErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif@~ method.
   * Attempts to use an error index number that exceeds the actual number
   * of errors in the log will result in a @c NULL being returned.
   *
   * @param n the index number of the error to retrieve (with 0 being the
   * first error).
   * @param severity the severity of the error to retrieve 
   *
   * @return the <i>n</i>th SbgnError in this log, or @c NULL if @p n is
   * greater than or equal to
   * @if java SbgnErrorLog::getNumFailsWithSeverity(long severity)@else getNumFailsWithSeverity()@endif.
   *
   * @see getNumFailsWithSeverity(unsigned int severity)
   */
  const SbgnError* getErrorWithSeverity(unsigned int n, unsigned int severity) const;


  /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #SbgnErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSBGN_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsbgnConstants.html">libsbgnConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSBGN_SEV_</code> constants defined by
   * the interface class @link libsbgn libsbgn@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity);


   /**
   * Returns the number of errors that have been logged with the given
   * severity code.
   *
   * @if clike @param severity a value from
   * #SbgnErrorSeverity_t @endif@if java @param severity a
   * value from the set of <code>LIBSBGN_SEV_</code> constants defined by
   * the interface class <code><a
   * href="libsbgnConstants.html">libsbgnConstants</a></code> @endif@if python @param severity a
   * value from the set of <code>LIBSBGN_SEV_</code> constants defined by
   * the interface class @link libsbgn libsbgn@endlink. @endif@~
   *
   * @return a count of the number of errors with the given severity code.
   *
   * @see getNumErrors()
   */
  unsigned int getNumFailsWithSeverity(unsigned int severity) const;


  /** @cond doxygenLibsbgnInternal */
  
  /**
   * Creates a new, empty SbgnErrorLog.
   */
  SbgnErrorLog ();


  /**
   * Copy Constructor
   */
  SbgnErrorLog (const SbgnErrorLog& other);


  /**
   * Assignment operator for SbgnErrorLog
   */
  SbgnErrorLog& operator=(const SbgnErrorLog& other);


  /**
   * Destroys this SbgnErrorLog.
   */
  virtual ~SbgnErrorLog ();


  /**
   * Convenience function that combines creating an SbgnError object and
   * adding it to the log.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level an unsigned int, the SBGN Level
   *
   * @param version an unsigned int, the SBGN Level's Version
   * 
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SbgnError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   * 
   * @param line an unsigned int, the line number at which the error occured.
   * 
   * @param column an unsigned int, the column number at which the error occured.
   * 
   * @param severity an integer indicating severity of the error.
   * 
   * @param category an integer indicating the category to which the error
   * belongs.
   */
  void logError
  (
      const unsigned int errorId  = 0
    , const unsigned int level    = SBGN_DEFAULT_LEVEL
    , const unsigned int version  = SBGN_DEFAULT_VERSION
    , const std::string& details  = ""
    , const unsigned int line     = 0
    , const unsigned int column   = 0
    , const unsigned int severity = LIBSBGN_SEV_ERROR
    , const unsigned int category = LIBSBGN_CAT_SBGN
  );


  /**
   * Adds the given SbgnError to the log.
   *
   * @param error SbgnError, the error to be logged.
   */
  void add (const SbgnError& error);


  /** @cond doxygenCppOnly */

  /**
   * Adds (copies) the SbgnErrors in the given SbgnError list to this
   * SbgnErrorLog.
   *
   * @param errors list, a list of SbgnError to be added to the log.
   */
  void add (const std::list<SbgnError>& errors);


  /**
   * Adds (copies) the SbgnErrors in the given SbgnError vector to this
   * SbgnErrorLog.
   *
   * @param errors vector, a vector of SbgnError to be added to the log.
   */
  void add (const std::vector<SbgnError>& errors);

  /** @endcond */


  /**
   * Removes an error having errorId from the SbgnError list.
   *  
   * Only the first item will be removed if there are multiple errors
   * with the given errorId.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void remove (const unsigned int errorId);


  /**
   * Removes all errors having errorId from the SbgnError list.
   *
   * @param errorId the error identifier of the error to be removed.
   */
  void removeAll(const unsigned int errorId);

  /**
   * Returns true if SbgnErrorLog contains an errorId
   *
   * @param errorId the error identifier of the error to be found.
   */
  bool contains (const unsigned int errorId) const;


  /** @endcond */
};

LIBSBGN_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SbgnErrorLog_h */

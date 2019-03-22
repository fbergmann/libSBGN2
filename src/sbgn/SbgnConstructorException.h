/**
 * @file SbgnConstructorException.h
 * @brief Definition of the SbgnConstructorException class.
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
 * @class SbgnConstructorException
 * @sbmlbrief{} TODO:Definition of the SbgnConstructorException class.
 */


#ifndef SBGN_CONSTRUCTOR_EXCEPTION_H
#define SBGN_CONSTRUCTOR_EXCEPTION_H

#include <sbgn/common/extern.h>
#include <sbgn/SbgnNamespaces.h>

#ifdef __cplusplus

#include <string>
#include <stdexcept>
#include <algorithm>

LIBSBGN_CPP_NAMESPACE_BEGIN


class LIBSBGN_EXTERN SbgnConstructorException : public std::invalid_argument
{
public:

  /** @cond doxygenLibsbgnInternal */
  
  /* constructor */
  SbgnConstructorException (std::string errmsg = "");
  SbgnConstructorException (std::string errmsg, std::string sbgnErrMsg);
  SbgnConstructorException (std::string elementName, SbgnNamespaces* xmlns);
  virtual ~SbgnConstructorException () throw();
  
 /** @endcond */

  /**
   * Returns the message associated with this Sbgn exception.
   *
   * @return the message string.
   */
  const std::string getSbgnErrMsg() const { return mSbgnErrMsg; }

private:
  std::string mSbgnErrMsg;
};


LIBSBGN_CPP_NAMESPACE_END

#endif /* __cplusplus */

#endif /* SBGN_CONSTRUCTOR_EXCEPTION_H */


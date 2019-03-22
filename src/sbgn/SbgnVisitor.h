/**
 * @file SbgnVisitor.h
 * @brief Definition of the SbgnVisitor class.
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
 * @class SbgnVisitor
 * @sbmlbrief{} TODO:Definition of the SbgnVisitor class.
 */



#ifndef SbgnVisitor_h
#define SbgnVisitor_h


#ifdef __cplusplus


#include <sbgn/SbgnTypeCodes.h>


LIBSBGN_CPP_NAMESPACE_BEGIN

/**
 * Forward class name declarations avoid cyclic dependencies.
 */

class SbgnBase;

class SbgnDocument;
class SbgnListOf;

class SbgnPoint;
class SbgnBBox;
class SbgnLabel;
class SbgnMap;
class SbgnGlyph;
class SbgnPort;
class SbgnArc;
class SbgnState;
class SbgnCallout;
class SbgnEntity;
class SbgnArcGroup;


class SbgnVisitor
{
public:

  /**
   * Destructor method.
   */
  virtual ~SbgnVisitor ();

  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SbgnDocument objects.
   *
   * @param x the SbgnDocument object to visit.
   */
  virtual void visit (const SbgnDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SbgnListOf objects.
   *
   * @param x the SbgnListOf object to visit.
   *
   * @param type the object type code.
   */
  virtual void visit (const SbgnListOf       &x, int type);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SbgnBase objects.
   *
   * @param x the SbgnBase object to visit.
   */
  virtual bool visit (const SbgnBase                    &x);



/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnPoint &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnBBox &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnLabel &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnMap &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnGlyph &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnPort &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnArc &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnState &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnCallout &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnEntity &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to visit.
 */
virtual bool visit (const SbgnArcGroup &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SbgnDocument objects.
   *
   * @param x the SbgnDocument object to visit.
   */
  virtual void leave (const SbgnDocument &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on Reaction objects.
   *
   * @param x the Reaction object to visit.
   */
  virtual void leave (const SbgnBase     &x);


  /**
   * Interface method for using the <a target="_blank" 
   * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
   * Pattern</i></a> to perform operations on SbgnListOf objects.
   *
   * @param x the SbgnListOf object to visit.
   *
   * @param type the object type code.
   *
   */
  virtual void leave (const SbgnListOf &x, int type);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnPoint &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnBBox &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnLabel &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnMap &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnGlyph &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnPort &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnArc &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnState &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnCallout &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnEntity &x);


/**
 * Interface method for using the <a target="_blank"
 * href="http://en.wikipedia.org/wiki/Design_pattern_(computer_science)"><i>Visitor
 * Pattern</i></a> to perform operations on SbgnBase objects.
 *
 * @param x the SbgnBase object to leave.
 */
virtual void leave (const SbgnArcGroup &x);
};

LIBSBGN_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* SbgnVisitor_h */


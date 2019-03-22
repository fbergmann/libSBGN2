/**
 * @file SbgnVisitor.cpp
 * @brief Implementation of the SbgnVisitor class.
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



#include <sbgn/SbgnVisitor.h>
#include <sbgn/SbgnTypes.h>

LIBSBGN_CPP_NAMESPACE_BEGIN

#ifdef __cplusplus

SbgnVisitor::~SbgnVisitor ()
{
}


void
SbgnVisitor::visit (const SbgnDocument& x)
{
  visit( static_cast<const SbgnBase&>(x) );
}


void
SbgnVisitor::visit (const SbgnListOf& x, int type)
{
  visit( static_cast<const SbgnBase&>(x) );
}


bool
SbgnVisitor::visit (const SbgnBase& sb)
{
  return false;
}


/*
 * Visit the SbgnPoint
 */
bool
SbgnVisitor::visit(const SbgnPoint& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnBBox
 */
bool
SbgnVisitor::visit(const SbgnBBox& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnLabel
 */
bool
SbgnVisitor::visit(const SbgnLabel& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnMap
 */
bool
SbgnVisitor::visit(const SbgnMap& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnGlyph
 */
bool
SbgnVisitor::visit(const SbgnGlyph& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnPort
 */
bool
SbgnVisitor::visit(const SbgnPort& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnArc
 */
bool
SbgnVisitor::visit(const SbgnArc& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnState
 */
bool
SbgnVisitor::visit(const SbgnState& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnCallout
 */
bool
SbgnVisitor::visit(const SbgnCallout& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnEntity
 */
bool
SbgnVisitor::visit(const SbgnEntity& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


/*
 * Visit the SbgnArcGroup
 */
bool
SbgnVisitor::visit(const SbgnArcGroup& x)
{
  return visit(static_cast<const SbgnBase&>(x));
}


void
SbgnVisitor::leave (const SbgnDocument& x)
{
}


void
SbgnVisitor::leave (const SbgnBase& sb)
{
}


void
SbgnVisitor::leave (const SbgnListOf& x, int type)
{
}


/*
 * Leave the SbgnPoint
 */
void
SbgnVisitor::leave(const SbgnPoint& x)
{
}


/*
 * Leave the SbgnBBox
 */
void
SbgnVisitor::leave(const SbgnBBox& x)
{
}


/*
 * Leave the SbgnLabel
 */
void
SbgnVisitor::leave(const SbgnLabel& x)
{
}


/*
 * Leave the SbgnMap
 */
void
SbgnVisitor::leave(const SbgnMap& x)
{
}


/*
 * Leave the SbgnGlyph
 */
void
SbgnVisitor::leave(const SbgnGlyph& x)
{
}


/*
 * Leave the SbgnPort
 */
void
SbgnVisitor::leave(const SbgnPort& x)
{
}


/*
 * Leave the SbgnArc
 */
void
SbgnVisitor::leave(const SbgnArc& x)
{
}


/*
 * Leave the SbgnState
 */
void
SbgnVisitor::leave(const SbgnState& x)
{
}


/*
 * Leave the SbgnCallout
 */
void
SbgnVisitor::leave(const SbgnCallout& x)
{
}


/*
 * Leave the SbgnEntity
 */
void
SbgnVisitor::leave(const SbgnEntity& x)
{
}


/*
 * Leave the SbgnArcGroup
 */
void
SbgnVisitor::leave(const SbgnArcGroup& x)
{
}



#endif /* __cplusplus */


LIBSBGN_CPP_NAMESPACE_END

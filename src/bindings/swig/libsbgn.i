/**
 * @file libsbgn.i
 * @brief Base file
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


%module(directors="1") libsbgn

%pragma(java) moduleclassmodifiers="
/**
  * Wrapper class for global methods and constants defined by libSBGN.
  * <p>
  * <em style='color: #555'>
  * This class of objects is defined by libSBGN only and has no direct
  * equivalent in terms of Sbgn components.  This class is not prescribed by
  * the Sbgn specifications, although it is used to implement features
  * defined in Sbgn.
  * </em>
  * <p>
  * In the C++ and C versions of libSBGN, there exists a small number of
  * methods that are global in scope; in addition, libSBGN uses a number
  * of enum's to define such things as error codes in a way that can be
  * used by both C++ and C.  This poses a problem in languages such as
  * Java, where there is no concept of global method or global constant.
  * SWIG wraps these global identifiers in the class whose documentation
  * you see before you.
  */
public class"


%{
#include "libsbgn.h"

LIBSBGN_CPP_NAMESPACE_USE

#include "local.cpp"
%}

%import  sbgn/common/libsbgn-namespace.h
%import  sbgn/common/extern.h
%import  sbgn/common/sbgnfwd.h
%import  sbml/common/extern.h
%import  sbml/xml/XMLExtern.h

/**
 * Wraps List class by ListWrapper<TYPENAME> template class.
 * TYPENAME is replaced with a corresponding data type which is
 * stored in the List object (e.g. ModelCreator, CVTerm and ASTNode). 
 *
 * ListWrapper<TYPENAME> class is wrapped as TYPENAMEList class
 * (e.g. ListWrapper<CVTerm> -> CVTermList)
 *
 */

%include "ListWrapper.h"
%template(ASTNodeList)        ListWrapper<ASTNode>;
%template(SbgnNamespacesList) ListWrapper<SbgnNamespaces>;
%template(SbgnBaseList)          ListWrapper<SbgnBase>;
%template(SBaseList)          ListWrapper<SBase>;

/**
 *
 * Includes a language specific interface file.
 *
 */

%include local.i

/**
 * Unfortunately, SWIG makes no distinction between const and non-const
 * member functions (SWIG 1.3 Manual, Section 6.25), but in libSBGN C++ we
 * have both const and non-const versions of most getter methods.  To avoid
 * a ton of warning messages about 'const' methods not being wrapped, we
 * disable Warning(516).
 */
#pragma SWIG nowarn=516

/**
 * Ignore the Visitor pattern accept() method (for now) on all Sbgn
 * objects.
 */
%ignore *::accept;

/**
 * Ignore internal implementation methods in ASTNode.h
 */
%ignore ASTNode(Token_t*);
%ignore ASTNode::getListOfNodes(ASTNodePredicate predicate) const;
%ignore ASTNode::fillListOfNodes;
%ignore ASTNode::setSemanticsFlag;
%ignore ASTNode::unsetSemanticsFlag;
%ignore ASTNode::getSemanticsFlag;
%ignore ASTNode::setDefinitionURL;
%ignore ASTNode::setUserData;
%ignore ASTNode::getUserData;
%ignore ASTNode::setParentSBMLObject;

/**
 * SWIG makes no distinction between int and long arguments.
 * (SWIG 1.3 Manual, Section 6.15.2)
 */
%ignore ASTNode::setValue(int);

/**
 * Ignore operator= and operator<< on all Sbgn objects.
 */
%ignore *::operator=;
%ignore *::operator<<;
%ignore operator==;
%ignore operator!=;

/**
 * Ignore certain internal implementation methods on all objects.
 */
%ignore *::writeElements;
%ignore *::setSbgnDocument;
%ignore *::setParentSbgnObject;

/**
 * Ignore internal implementation methods in MathML.h
 */
%ignore readMathML;
%ignore writeMathML;

/**
 * Ignore methods whose pointer argument serves as both input and output
 */
%ignore XMLAttributes::readInto;

/**
 * Ignore methods which receive std::list.
 */
%ignore XMLErrorLog::add(const std::list<XMLError>& errors);
%ignore SbgnErrorLog::add(const std::list<SbgnError>& errors);
%ignore SbgnErrorLog::add(const std::vector<SbgnError>& errors);

/**
 * Ignore 'struct xmlErrorTableEntry' in XMLError.h.
 */
%ignore xmlErrorTableEntry;

/**
 * Both "const std::string& SbgnBase::getMetaId() const" and
 * "std:string& SbgnBase::getMetaId()" are defined in SbgnBase.cpp.
 * By default, SWIG doesn't convert non-const std:string& to and from
 * target language string.
 * So we ignore the non-const version.
 */
%ignore SbgnBase::getMetaId();

/**
 * Ignore internal implementation methods in XMLErrorLog
 */
%ignore XMLErrorLog::setParser;

/**
 * Ignore internal implementation methods in SyntaxChecer
 */
%ignore SyntaxChecker::isAllowedElement;
%ignore SyntaxChecker::hasDeclaredNS;
%ignore SyntaxChecker::isCorrectHTMLNode;

/**
 * Ignore internal implementation methods in XMLToken
 */
%ignore XMLToken::write;

/**
 * Ignore internal implementation methods in XMLNode
 */
//%ignore XMLNode::XMLNode(XMLInputStream&);
%ignore XMLNode::write;

/**
 * Ignore internal implementation methods in XMLOutputStream
 */
%ignore XMLOutputStream::getStringStream;

/**
 * Ignore internal implementation classes
 */
%ignore XMLOutputStringStream;
%ignore XMLOutputFileStream;

/**
 * Ignore the unsigned int version of XMLOutputStream::writeAttribute method
 * in order to properly wrap the long version of XMLOutputStream::writeAttribute 
 * method which should be used instead of the unsigned int version.
 */
%ignore XMLOutputStream::writeAttribute(const std::string&, const unsigned int&);
%ignore XMLOutputStream::writeAttribute(const XMLTriple&,   const unsigned int&);

/**
 * The following methods will create new objects.  To prevent memory
 * leaks we must inform SWIG of this.
 */

%typemap(newfree) char * "free($1);";

%newobject *::clone;
%newobject SbgnBase::toSbgn;
%newobject SbgnReader::readSBGNFromString;
%newobject SbgnReader::readSBGNFromFile;
%newobject SbgnReader::readSBGN;
%newobject readSBGN(const char *);
%newobject readSBGNFromString(const char *);
%newobject readSBGNFromFile(const char *);
%newobject SbgnWriter::writeToString;
%newobject writeSBGNToString;
%newobject readMathMLFromString;
%newobject writeMathMLToString;
%newobject SBML_formulaToString;
%newobject SBML_formulaToL3String;
%newobject SBML_formulaToL3StringWithSettings;
%newobject SBML_parseFormula;
%newobject SBML_parseL3Formula;
%newobject SBML_parseL3FormulaWithModel;
%newobject SBML_parseL3FormulaWithSettings;
%newobject SBML_getDefaultL3ParserSettings;
%newobject SBML_getLastParseL3Error;
%newobject ASTNode::deepCopy;
%newobject ASTNode::getListOfNodes();
%newobject *::remove;
%newobject XMLNode::removeChild;
%newobject XMLNode::convertStringToXMLNode;

/**
 * We can't currently support attaching arbitrary user data to
 * libSBGN objects.
 */
%ignore *::setUserData;
%ignore *::getUserData;

/**
 * In the wrapped languages, these methods will appear as:
 *
 *  - libsbml.formulaToString()
 *  - libsbml.parseFormula()
 */
%rename(formulaToL3String) SBML_formulaToL3String;
%rename(formulaToL3StringWithSettings) SBML_formulaToL3StringWithSettings;
%rename(formulaToString) SBML_formulaToString;
%rename(parseFormula)    SBML_parseFormula;
%rename(parseL3Formula)    SBML_parseL3Formula;
%rename(parseL3FormulaWithModel)    SBML_parseL3FormulaWithModel;
%rename(parseL3FormulaWithSettings)    SBML_parseL3FormulaWithSettings;
%rename(getDefaultL3ParserSettings)    SBML_getDefaultL3ParserSettings;
%rename(getLastParseL3Error)    SBML_getLastParseL3Error;

/**
 *
 * wraps "List* ASTNode::getListOfNodes(ASTNodePredicate)" function
 * as "ListWrapper<ASTNode>* ASTNode::getListOfNodes()" function
 * which returns a list of all ASTNodes.
 *
 */

%ignore SbgnBase::getAllElements;

%extend SbgnBase
{
	ListWrapper<SbgnBase>* getListOfAllElements()
	{
		List* list = $self->getAllElements();
		return new ListWrapper<SbgnBase>(list);
	}
}

%extend ASTNode
{
  ListWrapper<ASTNode>* getListOfNodes()
  {
    List *list = $self->getListOfNodes(ASTNode_true);
    return new ListWrapper<ASTNode>(list);
  }
}

/**
 * Wrap these files.
 */

%include "std_string.i"
%include "std_vector.i"
%template(DoubleStdVector) std::vector<double>;
typedef std::vector<double> DoubleStdVector;
%template(XmlErrorStdVector) std::vector<XMLError*>;
typedef std::vector<XMLError*> XmlErrorStdVector;
%template(SbgnErrorStdVector) std::vector<SbgnError>;
typedef std::vector<SbgnError> SbgnErrorStdVector;

%include sbgn/common/libsbgn-version.h
%include sbgn/common/SbgnOperationReturnValues.h
%include sbml/common/libsbml-version.h
%include sbml/common/operationReturnValues.h

%include sbml/SyntaxChecker.h
%include sbml/ExpectedAttributes.h

%include sbml/xml/XMLAttributes.h
%include sbml/xml/XMLConstructorException.h
%include sbml/xml/XMLNamespaces.h
%include sbml/xml/XMLToken.h
%include sbml/xml/XMLNode.h
%include sbml/xml/XMLTriple.h
%include sbml/xml/XMLOutputStream.h
%include sbml/xml/XMLInputStream.h
%include sbml/xml/XMLError.h
%include sbml/xml/XMLErrorLog.h


%include sbml/extension/ISBMLExtensionNamespaces.h
%include sbml/extension/SBaseExtensionPoint.h
%include sbml/extension/SBasePlugin.h
%include sbml/extension/SBMLDocumentPlugin.h
%include sbml/extension/SBMLExtension.h
%include sbml/extension/SBMLExtensionException.h
%include sbml/extension/SBMLExtensionNamespaces.h
%include sbml/extension/SBMLExtensionRegistry.h

%include ASTNodes.i
%include layout-package.i
%include render-package.i


%include <sbgn/SbgnReader.h>
%include <sbgn/SbgnWriter.h>
%include <sbgn/SbgnTypeCodes.h>
%include <sbgn/SbgnTypes.h>
%include <sbgn/SbgnBase.h>
%include <sbgn/SbgnListOf.h>
%include <sbgn/SbgnDocument.h>
%include <sbgn/SbgnErrorLog.h>
%include <sbgn/SbgnError.h>

%include <sbgn/SbgnConstructorException.h>
%include <sbgn/SbgnNamespaces.h>

%include <sbgn/SbgnPoint.h>
%include <sbgn/SbgnListOfPoints.h>
%include <sbgn/SbgnBBox.h>
%include <sbgn/SbgnLabel.h>
%include <sbgn/SbgnMap.h>
%include <sbgn/SbgnListOfMaps.h>
%include <sbgn/SbgnGlyph.h>
%include <sbgn/SbgnListOfGlyphs.h>
%include <sbgn/SbgnPort.h>
%include <sbgn/SbgnListOfPorts.h>
%include <sbgn/SbgnArc.h>
%include <sbgn/SbgnListOfArcs.h>
%include <sbgn/SbgnState.h>
%include <sbgn/SbgnCallout.h>
%include <sbgn/SbgnEntity.h>
%include <sbgn/SbgnArcGroup.h>
%include <sbgn/SbgnListOfArcGroups.h>


/**
 * @file    libsbgn-namespace.h
 * @brief   Defines C++ namespace of libSBGN
 */
 

#ifndef LIBSBGN_NAMESPACE_H
#define LIBSBGN_NAMESPACE_H 1

#ifndef SWIG
#include <sbml/common/libsbml-namespace.h>

LIBSBML_CPP_NAMESPACE_USE

#endif
/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable libSBGN C++ namespace */
#cmakedefine LIBSBGN_USE_CPP_NAMESPACE 1


#if defined(__cplusplus) && defined(LIBSBGN_USE_CPP_NAMESPACE) && !defined(SWIG)
  /* C++ namespace of libSBGN */
  #define LIBSBGN_CPP_NAMESPACE            libsbgn
  #define LIBSBGN_CPP_NAMESPACE_BEGIN      namespace LIBSBGN_CPP_NAMESPACE {
  #define LIBSBGN_CPP_NAMESPACE_END        }
  #define LIBSBGN_CPP_NAMESPACE_USE        using namespace LIBSBGN_CPP_NAMESPACE;
  #define LIBSBGN_CPP_NAMESPACE_QUALIFIER  LIBSBGN_CPP_NAMESPACE::

  namespace LIBSBGN_CPP_NAMESPACE {}
#else
  #define LIBSBGN_CPP_NAMESPACE 
  #define LIBSBGN_CPP_NAMESPACE_BEGIN
  #define LIBSBGN_CPP_NAMESPACE_END  
  #define LIBSBGN_CPP_NAMESPACE_USE 
  #define LIBSBGN_CPP_NAMESPACE_QUALIFIER 
#endif


#endif  /* LIBSBGN_NAMESPACE_H */


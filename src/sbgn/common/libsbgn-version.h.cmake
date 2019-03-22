/**
 * @file    libsbgn-version.h
 * @brief   Define libSBGN version numbers for access from client software.
 *
 */


#ifndef LIBSBGN_VERSION_H
#define LIBSBGN_VERSION_H 

#include <sbgn/common/extern.h>


/**
 * LIBSBGN_DOTTED_VERSION:
 *
 * A version string of the form "1.2.3".
 */
#define LIBSBGN_DOTTED_VERSION	"@PACKAGE_VERSION@"


/**
 * LIBSBGN_VERSION:
 *
 * The version as an integer: version 1.2.3 becomes 10203.  Since the major
 * number comes first, the overall number will always increase when a new
 * libSBGN is released, making it easy to use less-than and greater-than
 * comparisons when testing versions numbers.
 */
#define LIBSBGN_VERSION		@LIBSBGN_VERSION_NUMERIC@


/**
 * LIBSBGN_VERSION_STRING:
 *
 * The numeric version as a string: version 1.2.3 becomes "10203".
 */
#define LIBSBGN_VERSION_STRING	"@LIBSBGN_VERSION_NUMERIC@"


LIBSBGN_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the version number of this copy of libSBGN as an integer.
 *
 * @return the libSBGN version as an integer; version 1.2.3 becomes 10203.
 */
LIBSBGN_EXTERN
int 
getLibSBGNVersion();


/**
 * Returns the version number of this copy of libSBGN as a string.
 *
 * @return the libSBGN version as a string; version 1.2.3 becomes
 * "1.2.3".
 *
 * @see getLibSBGNVersionString()
 */
LIBSBGN_EXTERN
const char* 
getLibSBGNDottedVersion();


/**
 * Returns the version number of this copy of libSBGN as a string without
 * periods.
 *
 * @return the libSBGN version as a string: version 1.2.3 becomes "10203".
 *
 * @see getLibSBGNDottedVersion()
 */
LIBSBGN_EXTERN
const char* 
getLibSBGNVersionString();


END_C_DECLS
LIBSBGN_CPP_NAMESPACE_END

#endif  /* LIBSBGN_VERSION_H */

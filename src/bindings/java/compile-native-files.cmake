#################################################
 # @file compile-native-files.cmake
 # @brief Base file
 # @author DEVISER
 #
 # <!--------------------------------------------------------------------------
 # This file is part of libSBML. Please visit http://sbml.org for more
 # information about SBML, and the latest version of libSBML.
 #
 # Copyright (C) 2019 jointly by the following organizations:
 # 1. California Institute of Technology, Pasadena, CA, USA
 # 2. University of Heidelberg, Heidelberg, Germany
 #
 # Copyright (C) 2013-2018 jointly by the following organizations:
 # 1. California Institute of Technology, Pasadena, CA, USA
 # 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 # 3. University of Heidelberg, Heidelberg, Germany
 #
 # Copyright (C) 2009-2013 jointly by the following organizations:
 # 1. California Institute of Technology, Pasadena, CA, USA
 # 2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 #
 # Copyright (C) 2006-2008 by the California Institute of Technology,
 # Pasadena, CA, USA
 #
 # Copyright (C) 2002-2005 jointly by the following organizations:
 # 1. California Institute of Technology, Pasadena, CA, USA
 # 2. Japan Science and Technology Agency, Japan
 #
 # This library is free software; you can redistribute it and/or modify it
 # under the terms of the GNU Lesser General Public License as published by the
 # Free Software Foundation. A copy of the license agreement is provided in the
 # file named "LICENSE.txt" included with this software distribution and also
 # available online as http://sbml.org/software/libsbml/license.html
 # ------------------------------------------------------------------------ -->
 #


message("Creating: libsbgn.jar")

# find all sources
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${BIN_DIRECTORY} ${BIN_DIRECTORY}/java-files/org/sbgn/libsbgn/*.java)

# convert paths
set(NATIVE_FILES)
foreach(javaFile ${SOURCE_FILES})
	file(TO_NATIVE_PATH ${javaFile} temp)
	set(NATIVE_FILES ${NATIVE_FILES} ${temp})
endforeach()

# delete file if it exists
if (EXISTS ${BIN_DIRECTORY}/libsbgn.jar)
	file(REMOVE ${BIN_DIRECTORY}/libsbgn.jar)	
endif()

# figure out the compativility args to use
SET (COMPATIBILITY_ARGS)
if (COMPATIBILIY)
SET (COMPATIBILITY_ARGS ${COMPATIBILITY_ARGS} -source ${COMPATIBILIY} -target ${COMPATIBILIY})
endif()


# compile files
execute_process(

  COMMAND "${Java_JAVAC_EXECUTABLE}"
  ${COMPATIBILITY_ARGS}
  -d java-files
  ${NATIVE_FILES}

  ERROR_VARIABLE COMPILE_ERRORS

  WORKING_DIRECTORY "${BIN_DIRECTORY}"
)


if (NOT COMPILE_ERRORS STREQUAL "" AND COMPILE_ERRORS MATCHES "error")
  message (FATAL_ERROR
"
Could not compile java wrappers:

${COMPILE_ERRORS}
")
endif()


# enumerate class files
file(GLOB_RECURSE CLASS_FILES RELATIVE ${BIN_DIRECTORY}/java-files ${BIN_DIRECTORY}/java-files/org/sbgn/libsbgn/*.class)
set(NATIVE_CLASS_FILES)
foreach(classFile ${CLASS_FILES})
	file(TO_NATIVE_PATH ${classFile} temp)
	set(NATIVE_CLASS_FILES ${NATIVE_CLASS_FILES} ${temp})
endforeach()

# create jar
execute_process(
	COMMAND "${Java_JAR_EXECUTABLE}"
		 -cvfm ..${PATH_SEP}libsbgnj.jar
		 ../Manifest.txt
		 ${NATIVE_CLASS_FILES}	
	WORKING_DIRECTORY "${BIN_DIRECTORY}/java-files"
)

# # print variables for debug purposes 
# message("BIN_DIRECTORY         : ${BIN_DIRECTORY}")
# message("Java_JAVAC_EXECUTABLE : ${Java_JAVAC_EXECUTABLE}")
# message("Java_JAR_EXECUTABLE   : ${Java_JAR_EXECUTABLE}")


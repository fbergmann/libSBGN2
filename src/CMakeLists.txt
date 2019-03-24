###############################################################################
#
# Initialize Sbgn sources
#
set(LIBSBGN_SOURCES)

###############################################################################
#
# utility macro for copying files only if they have changed, for this it is
# assumed that the source file is always created. Then the macro is called.
# If the target file will only be overwritten if it does not yet exist, or
# its content is different. At the end the source file will be removed.
#
macro(copy_if_different_and_remove source target)
# message(
# "
# copy_if_different_and_remove called with:
#     source = ${source}
#     target = ${target}
# "
# )
file(READ ${source} CONTENT)

if (EXISTS ${target})
    # message("target exists")
    file(READ ${target} CURRENT_CONTENT)
    string(COMPARE EQUAL ${CURRENT_CONTENT} ${CONTENT} IS_SAME)
    if (NOT ${IS_SAME})
        #message("content is different")
        file(WRITE ${target} ${CONTENT})
    endif()
else()
    #message("target does not exist")
    file(WRITE ${target} ${CONTENT})
endif()

file(REMOVE ${source})

endmacro(copy_if_different_and_remove)

###############################################################################
#
# create libsbgn-config-common.h
#
include(CheckIncludeFiles)
check_include_files (check.h HAVE_CHECK_H)
check_include_files (expat.h HAVE_EXPAT_H)
check_include_files (errno.h HAVE_ERRNO_H)
check_include_files (ieeefp.h HAVE_IEEEFP_H)
check_include_files (math.h HAVE_MATH_H)
check_include_files (sys/types.h HAVE_SYS_TYPES_H)
check_include_files (float.h STDC_HEADERS)
check_include_files (stdarg.h STDC_HEADERS)
check_include_files (stdlib.h STDC_HEADERS)
check_include_files (string.h STDC_HEADERS)

set(WORDS_BIGENDIAN)
if (UNIX)
  include (TestBigEndian)
  test_big_endian(WORDS_BIGENDIAN)
else()
  # test_big_endian seems to fail with nmake (VS 2010) on windows
  # however, windows is always little endian, so catch this here
  set(WORDS_BIGENDIAN FALSE)
endif()

# for whatever reason some of the values are not correctly picked up
# so we encode these values here
if (MSVC)
  set(HAVE_ERRNO_H TRUE)
  set(HAVE_IEEEFP_H TRUE)
  set(STDC_HEADERS TRUE)
  set(HAVE_MATH_H TRUE)
  set(HAVE_SYS_TYPES_H TRUE)
endif()


include(CheckLibraryExists)
check_library_exists(m sqrt "" HAVE_LIBM)

# generate configuration for this system
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/sbgn/common/libsbgn-config-common.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/sbgn/common/libsbgn-config-common.h
)

# Replace: @LIBSBGN_DOTTED_VERSION@ and @LIBSBGN_VERSION_NUMERIC@
configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/sbgn/common/libsbgn-version.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/sbgn/common/libsbgn-version.h"
)

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/sbgn/common/libsbgn-namespace.h.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/sbgn/common/libsbgn-namespace.h"
)

  
###############################################################################
#
# mark header files for installation
#

foreach(dir annotation common compress conversion extension units util validator xml  )

    file(GLOB header_files "${CMAKE_CURRENT_SOURCE_DIR}/sbgn/${dir}/*.h")
    install(FILES ${header_files} DESTINATION include/sbgn/${dir})

endforeach(dir)


file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/sbgn/*.h")
install(FILES ${files} DESTINATION include/sbgn)


###############################################################################
#
# copy build specific header files
#

file(GLOB additional_common "${CMAKE_CURRENT_BINARY_DIR}/sbgn/common/*.h")

install(FILES ${additional_common} DESTINATION include/sbgn/common)

###############################################################################
#
# specify include directories
#

include_directories(BEFORE ${LIBSBGN_ROOT_SOURCE_DIR}/src/sbgn)
include_directories(BEFORE ${LIBSBGN_ROOT_SOURCE_DIR}/src)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR}/src/sbgn)
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)


###############################################################################
#
# Find all sources
#

macro(ADD_FUNCTION directory)

    set(prefix "sbgn/")

    if ("${directory}" STREQUAL "sbgn")
        set(prefix "")
    endif()


    file(GLOB temp
            ${prefix}${directory}/*.cpp
            ${prefix}${directory}/*.cxx
            ${prefix}${directory}/*.c
            ${prefix}${directory}/*.h)

    # Set the constraint files to be 'headers' as they don't have to be compiled
    # since they don't contain symbols but rather are included directly.  Could
    # remove them, but that keeps their content from being found in searches, etc.
    # in IDEs such as VisualStudio.
    foreach(tempFile ${temp})
        if ("${directory}" STREQUAL "validator/constraints")
            if ("${tempFile}" MATCHES ".*Constraints.cpp")
              set_source_files_properties(
                  ${tempFile}
                  PROPERTIES HEADER_FILE_ONLY true
                  )
#              list(REMOVE_ITEM temp "${tempFile}")
            endif()
        endif()
        if ("${tempFile}" MATCHES ".*.cxx")
          set_source_files_properties(
              ${tempFile}
              PROPERTIES HEADER_FILE_ONLY true
              )
        endif()
    endforeach()

    # create source group for IDEs
    source_group(${directory} FILES ${temp})

    # add to libsbgn sources
    set(LIBSBGN_SOURCES ${LIBSBGN_SOURCES} ${temp})

endmacro(ADD_FUNCTION)

foreach (directory common sbgn)

	ADD_FUNCTION(${directory})
				       
endforeach()

###############################################################################
#
# this is a directory level operation!
#
if (MSVC)
if (WITH_STATIC_RUNTIME)
    foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)

        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif(${flag_var} MATCHES "/MD")


    endforeach(flag_var)
    add_definitions( -D_MT)
endif(WITH_STATIC_RUNTIME)
endif(MSVC)

###############################################################################
#
# Build library
#

if (NOT LIBSBGN_SKIP_SHARED_LIBRARY)

add_library (${LIBSBGN_LIBRARY} SHARED ${LIBSBGN_SOURCES} )

if (LIBSBGN_SHARED_VERSION)
  SET_TARGET_PROPERTIES(${LIBSBGN_LIBRARY} PROPERTIES
                        SOVERSION ${LIBSBGN_VERSION_MAJOR}
                        VERSION ${LIBSBGN_VERSION_MAJOR}.${LIBSBGN_VERSION_MINOR}.${LIBSBGN_VERSION_PATCH})
endif()

target_link_libraries(${LIBSBGN_LIBRARY} ${LIBSBGN_LIBS} ${EXTRA_LIBS})

INSTALL(TARGETS ${LIBSBGN_LIBRARY}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )

endif()

add_library (${LIBSBGN_LIBRARY}-static STATIC ${LIBSBGN_SOURCES} )

if (WIN32 AND NOT CYGWIN)
    # don't decorate static library 
    set_target_properties(${LIBSBGN_LIBRARY}-static PROPERTIES COMPILE_DEFINITIONS "LIBLAX_STATIC=1;LIBSBGN_STATIC=1")
endif(WIN32 AND NOT CYGWIN)

target_link_libraries(${LIBSBGN_LIBRARY}-static ${LIBSBGN_LIBS} ${EXTRA_LIBS})

INSTALL(TARGETS ${LIBSBGN_LIBRARY}-static
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

##############################################################################
#
# add native tests
#
add_subdirectory(sbgn)

##############################################################################
#
# construct list of all header files to create dependency list for 
# language bindings
#

file(GLOB LIBSBGN_HEADER_FILES "${CMAKE_CURRENT_BINARY_DIR}/sbgn/common/*.h")    
foreach(file ${LIBSBGN_SOURCES})
   
   if ("${file}" MATCHES "h$" )
     get_filename_component(full_path ${file} ABSOLUTE)
     list(APPEND LIBSBGN_HEADER_FILES ${full_path})     
   endif()

endforeach()

##############################################################################
#
# create language bindings
#
add_subdirectory(bindings)

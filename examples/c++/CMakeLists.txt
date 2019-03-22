## @file    CMakeLists.txt
## @brief   CMake build script for example programs
## @author  Frank T. Bergmann
##
## <!--------------------------------------------------------------------------
## This file is part of libSBML.  Please visit http://sbml.org for more
## information about SBML, and the latest version of libSBML.
##
## Copyright (C) 2013-2018 jointly by the following organizations:
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
##     3. University of Heidelberg, Heidelberg, Germany
##
## Copyright (C) 2009-2013 jointly by the following organizations:
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
##
## Copyright (C) 2006-2008 by the California Institute of Technology,
##     Pasadena, CA, USA
##
## Copyright (C) 2002-2005 jointly by the following organizations:
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. Japan Science and Technology Agency, Japan
##
## This library is free software; you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation.  A copy of the license agreement is provided
## in the file named "LICENSE.txt" included with this software distribution
## and also available online as http://sbml.org/software/libsbml/license.html
## ------------------------------------------------------------------------ -->



include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_BINARY_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/sbgn)
include_directories(${LIBSBML_INCLUDE_DIR})

if (EXTRA_INCLUDE_DIRS)
include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

add_definitions(-DLIBSBGN_STATIC)
add_definitions(-std=c++11)


foreach( file 
		 write_example1
		 print_sbgn
		 print_render_extension
		 echo_sbgn
		 create_cpp_example
		 create_render_extension

		 write_af_activity-nodes
         write_af_AF_Reference_Card
         write_af_auxiliary-units
         write_af_compartment
         write_af_delay
         write_af_modulation
         write_af_submap
         write_af_submaps_all-in-one
         write_af_submap_expanded
         write_af_two_edges_between_two_activities

		 write_er_binary-no-outcome
         write_er_binary-with-perturbation-and-phenotype
         write_er_cis
         write_er_delay
         write_er_ER_Reference_Card
         write_er_existence_variable
         write_er_implicit_xor
         write_er_location
         write_er_outcome-dual
         write_er_outcome-simplified
         write_er_phosphorylation
         write_er_ternary-interaction
         write_er_ternary-with-cardinality
         write_er_ternary-with-perturbation-and-phenotype
	 write_pd_activated_stat1alpha_induction_of_the_irf1_gene
         write_pd_adh
         write_pd_and
         write_pd_annotation
         write_pd_bool-expr-pd
         write_pd_clone-marker
         write_pd_compartmentOrder1
         write_pd_compartmentOrder2
         write_pd_compartments
         write_pd_edgerouting
         write_pd_glycolysis
         write_pd_insulin-like_growth_factor_signaling
         write_pd_labeledCloneMarker
         write_pd_mapk_cascade
         write_pd_multimer
         write_pd_multimer2
         write_pd_neuronal_muscle_signalling
         write_pd_neuronal_muscle_signalling_color
         write_pd_or-simple
         write_pd_PD_Reference_Card
         write_pd_protein_degradation
         write_pd_reversible-verticalpn
         write_pd_states
         write_pd_statesType2
         write_pd_stoichiometry
         write_pd_submap
         write_pd_submaps_MAPKcascade
         write_pd_submap_expanded
         write_pd_utf8_test_case_without_byte_order_mark
         write_pd_utf8_test_case_with_byte_order_mark
)

add_executable(${file} ${file}.cpp)
target_link_libraries(${file} ${LIBSBGN_LIBRARY}-static)

endforeach()

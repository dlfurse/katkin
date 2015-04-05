##########
# global #
##########

cmake_minimum_required( VERSION 2.8 )
project( katkin C CXX )

# module settings
set( MODULE_VERSION_MAJOR 0 )
set( MODULE_VERSION_MINOR 1 )
set( MODULE_VERSION_PATCH 0 )
set( MODULE_VERSION "${MODULE_VERSION_MAJOR}.${MODULE_VERSION_MINOR}.${MODULE_VERSION_PATCH}" )
set( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/" )

# rpath settings
if( APPLE )
	set( CMAKE_MACOSX_RPATH TRUE )
endif()
set( CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib" )
set( CMAKE_SKIP_RPATH FALSE )
set( CMAKE_SKIP_BUILD_RPATH  FALSE )
set( CMAKE_BUILD_WITH_INSTALL_RPATH TRUE )

# utilities

include( KatkinUtility )

#########
# flags #
#########

add_definitions( -Wall )
add_definitions( -std=c++11 )

########
# core #
########

set( katkin_core_dependencies
)
set( katkin_core_directory
	.
)
set( katkin_core_headers
	katkin/core/_.hh
	katkin/core/x.hh
	katkin/core/name.hh
	katkin/core/print.hh
	katkin/core/terminal.hh
	katkin/core.hh
	katkin/types/empty.hh
	katkin/types/b.hh
	katkin/types/i.hh
	katkin/types.hh
	katkin/operations/and.hh
	katkin/operations/or.hh
	katkin/operations/not.hh
	katkin/operations/equal.hh
	katkin/operations/unequal.hh
	katkin/operations/larger.hh
	katkin/operations/smaller.hh
	katkin/operations/largerequal.hh
	katkin/operations/smallerequal.hh
	katkin/operations/add.hh
	katkin/operations/subtract.hh
	katkin/operations/multiply.hh
	katkin/operations/divide.hh
	katkin/operations/modulo.hh
	katkin/operations.hh
	katkin/sequences/node.hh
	katkin/sequences/list.hh
	katkin/sequences/pair.hh
	katkin/sequences/length.hh
	katkin/sequences/at_front.hh
	katkin/sequences/pop_front.hh
	katkin/sequences/push_front.hh
	katkin/sequences/sub_front.hh
	katkin/sequences/at_back.hh
	katkin/sequences/pop_back.hh
	katkin/sequences/push_back.hh
	katkin/sequences/sub_back.hh
	katkin/sequences/at_idx.hh
	katkin/sequences/pop_idx.hh
	katkin/sequences/push_idx.hh
	katkin/sequences/sub_idx.hh
	katkin/sequences/at_key.hh
	katkin/sequences/pop_key.hh
	katkin/sequences/push_key.hh
	katkin/sequences/sub_key.hh
	katkin/sequences.hh
	katkin/algorithms/if.hh
	katkin/algorithms/arg.hh
	katkin/algorithms/key.hh
	katkin/algorithms/idx.hh
	katkin/algorithms/at.hh
	katkin/algorithms/pop.hh
	katkin/algorithms/push.hh
	katkin/algorithms/sub.hh
	katkin/algorithms/fold.hh
	katkin/algorithms.hh
	katkin/katkin.hh
)
set( katkin_core_sources
	katkin/core/terminal.cc
)

katkin_library( core )

set( katkin_core_examples_dependencies
	core
)
set( katkin_core_examples_directory
	examples
)
set( katkin_core_examples_programs 
	test_print
	test_operations_logic
	test_operations_comparison
	test_operations_arithmetic
	test_sequence_front
	test_sequence_back
	test_sequence_keyed
	test_sequence_indexed
	test_algorithm_at
	test_algorithm_placeholders
	test_algorithm_fold
	test_expression
)

katkin_executables( core_examples )
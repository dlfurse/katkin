#########################################
# macro to define and install libraries #
#########################################

macro( katkin_library name )

	foreach( dependency ${katkin_${name}_dependencies} )
		list( APPEND katkin_${name}_dependency_names _katkin_${dependency} )
	endforeach( dependency )
	
	foreach( base ${katkin_${name}_headers} )
		list( APPEND katkin_${name}_header_files ${CMAKE_CURRENT_SOURCE_DIR}/${katkin_${name}_directory}/${base} )
	endforeach( base )
	
	foreach( base ${katkin_${name}_sources} )
		list( APPEND katkin_${name}_source_files ${CMAKE_CURRENT_SOURCE_DIR}/${katkin_${name}_directory}/${base} )
	endforeach( base )
	
	include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/${katkin_${name}_directory} )
	
	add_library( _katkin_${name} SHARED ${katkin_${name}_header_files} ${katkin_${name}_source_files} )
	target_link_libraries( _katkin_${name} ${katkin_${name}_dependency_names} ${katkin_external_libraries} )
	
	install( FILES ${katkin_${name}_header_files} DESTINATION include )
	
	install( TARGETS _katkin_${name} DESTINATION lib )

endmacro( katkin_library )

###########################################
# macro to define and install executables #
###########################################

macro( katkin_executables name )

	foreach( dependency ${katkin_${name}_dependencies} )
		list( APPEND katkin_${name}_dependency_names _katkin_${dependency} )
	endforeach( dependency )
	
	foreach( program ${katkin_${name}_programs} )
		add_executable( ${program} ${CMAKE_CURRENT_SOURCE_DIR}/${katkin_${name}_directory}/${program}.cc )
		target_link_libraries( ${program} ${katkin_${name}_dependency_names} ${katkin_external_libraries} )
		install( TARGETS ${program} DESTINATION bin )
	endforeach( program )
	
endmacro( katkin_executables )

####################################
# macro to define and install json #
####################################

macro( katkin_json name )

	foreach( base ${katkin_${name}_files} )
		list( APPEND katkin_${name}_file_files ${CMAKE_CURRENT_SOURCE_DIR}/${katkin_${name}_directory}/${base} )
	endforeach( base )
	
	install( FILES ${katkin_${name}_file_files} DESTINATION json )
	
endmacro( katkin_json )


cmake_minimum_required (VERSION 2.8)

project(dzlib)

list(APPEND include_dirs "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(src
	"src/console_helpers.cpp")

set(hdr_public
	"include/dzlib/strstream.h"
	"include/dzlib/dzexception.h"
	"include/dzlib/console_helpers.h")

add_library(dzlib STATIC ${src} ${hdr_public})
set_target_properties(dzlib PROPERTIES
	PUBLIC_HEADER "${hdr_public}"
	INCLUDE_DIRECTORIES "${include_dirs}"
	INTERFACE_INCLUDE_DIRECTORIES "${include_dirs}"
	)

install(TARGETS dzlib
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	PUBLIC_HEADER DESTINATION include/dzlib)

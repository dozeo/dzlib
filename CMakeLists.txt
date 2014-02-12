cmake_minimum_required (VERSION 2.8)

project (dzlib CXX)

include (cmake/unify.cmake)

include_directories ("include/")

set (srcfiles
	"src/strstream.cpp")

set (hdr_public
	"include/dzlib/strstream.h")

add_library (dzlib STATIC ${srcfiles} ${hdr_public})

install (TARGETS dzlib
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib)

install (FILES ${hdr_public}
	DESTINATION include/dzlib)
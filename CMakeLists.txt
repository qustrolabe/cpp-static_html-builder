cmake_minimum_required(VERSION 3.13.0)
project(static_builder VERSION 0.0.1)

include(cmake/CPM.cmake)

CPMAddPackage(
	NAME HtmlBuilder
	GITHUB_REPOSITORY SRombauts/HtmlBuilder
	GIT_TAG master
	DOWNLOAD_ONLY YES
	)

#if (HtmlBuilder_ADDED)
#  add_library(HtmlBuilder INTERFACE IMPORTED)
#  target_include_directories(HtmlBuilder INTERFACE ${HtmlBuilder_SOURCE_DIR}/include)
#endif()

CPMAddPackage(
	NAME maddy_lib
	GIT_TAG master
	GITHUB_REPOSITORY progsource/maddy
	DOWNLOAD_ONLY YES
	)

#if (maddy_lib_ADDED)
#  add_library(maddy_lib INTERFACE IMPORTED)
#  target_include_directories(maddy_lib INTERFACE ${maddy_lib_SOURCE_DIR}/include)
#endif()


target_include_directories(static_builder ${maddy_lib_SOURCE_DIR}/include ${HtmlBuilder_SOURCE_DIR}/include)
 
add_executable(static_builder main.cpp)
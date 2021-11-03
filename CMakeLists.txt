cmake_minimum_required(VERSION 3.13.0)
project(static_builder VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

include(cmake/CPM.cmake)

CPMAddPackage(
	NAME HtmlBuilder
	GITHUB_REPOSITORY SRombauts/HtmlBuilder
	GIT_TAG master
	DOWNLOAD_ONLY YES
)

CPMAddPackage(
	NAME maddy_lib
	GIT_TAG master
	GITHUB_REPOSITORY progsource/maddy
	DOWNLOAD_ONLY YES
)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(
	${PROJECT_NAME} PRIVATE
	${maddy_lib_SOURCE_DIR}/include
	${HtmlBuilder_SOURCE_DIR}/include
)
 
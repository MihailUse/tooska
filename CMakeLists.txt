cmake_minimum_required(VERSION 2.6)
project(tooska)

set(PROJECT_NAME "tooska")

option(BUILD_TOOLS "Build tools(html formatter, wsdl parser)" ON)
option(BUILD_TEST "Build tests" ON)


add_subdirectory(src)


IF (BUILD_TEST)
	add_subdirectory(test)
ENDIF()

IF (BUILD_TOOLS)
	add_subdirectory(tools)
ENDIF()

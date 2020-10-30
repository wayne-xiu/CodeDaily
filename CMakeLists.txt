cmake_minimum_required(VERSION 3.5)
project(CodeDaily)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GUN" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/include")

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CodeDaily.cpp
)

add_executable(CodeDaily ${TEST_SOURCES})
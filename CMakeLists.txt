cmake_minimum_required(VERSION 3.11)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME substring_search)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-g -Wall")

project(substring_search)

include_directories("${CMAKE_SOURCE_DIR}/cpp/include/algos")
include_directories("${CMAKE_SOURCE_DIR}/python")

file (GLOB SOURCE_FILES "cpp/src/*.cpp")
file (GLOB HEADER_FILES "cpp/include/algos/*.hpp")
file (GLOB PYTHON_FILES "python_lib/*.cpp" "python_lib/*.hpp")
message("${HEADER_FILES}")

add_subdirectory(extern/pybind11)
pybind11_add_module(substring_search
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${PYTHON_FILES}
        )

target_link_libraries(substring_search PUBLIC)

#message(${CMAKE_BINARY_DIR})
install(TARGETS substring_search
        COMPONENT python_lib
        LIBRARY DESTINATION ${PYTHON_SITE_PACKAGES}
        )
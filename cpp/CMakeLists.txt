cmake_minimum_required(VERSION 3.11)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME substring_search)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-g -Wall")
# If you want your own include/ directory, set this, and then you can do
# include_directories(${COMMON_INCLUDES}) in other CMakeLists.txt files.
# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Define project sources and includes
#----------------------------------------------------------------------------
set(COMMON_INCLUDES include/algos)
include_directories(${COMMON_INCLUDES})
file(GLOB TEST_SRC_FILES test/*.cpp)

set(HEADERS include/algos/Brute-Force.hpp
        include/algos/Finite-Automata.hpp
        include/algos/Karp-Rabin.hpp
        include/algos/Knuth-Morris-Pratt.hpp)

set(SRC_FILES ${HEADERS} src/Brute-Force.cpp
        src/Karp-Rabin.cpp
        src/Finite-Automata.cpp
        src/Knuth-Morris-Pratt.cpp
        )

set(CMAKE_CXX_STANDARD 11)
add_library(substring SHARED ${SRC_FILES})
target_include_directories(substring PRIVATE ${COMMON_INCLUDES})

install(TARGETS substring DESTINATION lib)
install(FILES include/substring_search DESTINATION include)
install(DIRECTORY include/algos DESTINATION include)

#add_executable(brute_force ${PROJECT_SOURCE_DIR}/src/main1.cpp)
#add_executable(karp_rabin ${PROJECT_SOURCE_DIR}/src/main2.cpp)
#add_executable(finite_automata ${PROJECT_SOURCE_DIR}/src/main3.cpp)
#add_executable(knutt_morris_pratt ${PROJECT_SOURCE_DIR}/src/main4.cpp)
#
#target_link_libraries(brute_force substring_search_lib)
#target_link_libraries(karp_rabin substring_search_lib)
#target_link_libraries(finite_automata substring_search_lib)
#target_link_libraries(knutt_morris_pratt substring_search_lib)


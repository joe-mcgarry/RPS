cmake_minimum_required(VERSION 3.20)
project(RPS VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# will fetch catch2 if not found locally
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2
        GIT_TAG v3.9.1
)
# Find Catch2 locally
find_package(Catch2 3 REQUIRED)

if(NOT Catch2_FOUND)
    message(STATUS "Catch2 not found locally. Downloading...")
    FetchContent_MakeAvailable(Catch2)
endif ()

#Defines source files in repo
set(GAME_SOURCES
        src/Game.cpp
        src/GameInterface.cpp
)

set(GAME_HEADERS
        include/Game.h
        include/GameConstants.h
        include/GameInterface.h
        include/GameManager.h
)

# Main game executables
add_executable(RPS
        src/main.cpp
        ${GAME_SOURCES}
        ${GAME_HEADERS}
)

target_include_directories(RPS PRIVATE include)

# Test targets and executables
add_executable(tests
        tests/test_main.cpp
        ${GAME_SOURCES}
        ${GAME_HEADERS}
)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

#Set output directories
set_target_properties(RPS tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

#Enable testing
enable_testing()
add_test(NAME unit_tests COMMAND tests)

#Compiler warnings
if(MSVC)
    target_compile_options(RPS PRIVATE /W4)
    target_compile_options(tests PRIVATE /W4)
else()
    target_compile_options(RPS PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)
endif()
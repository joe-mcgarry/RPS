cmake_minimum_required(VERSION 4.0)
project(RPS)

set(CMAKE_CXX_STANDARD 23)

# Find Catch2
find_package(Catch2 3 REQUIRED)

# Main game executables
add_executable(RPS main.cpp Game.cpp Game.h
        GameInterface.h
        GameInterface.cpp
        GameConstants.h)

# Test targets and executables
add_executable(tests Game.cpp Game.h GameInterface.cpp GameInterface.h GameConstants.h test_main.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

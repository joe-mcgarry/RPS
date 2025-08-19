# Rock Paper Scissors Game

A C++23 Rock Paper Scissors game with unit tests using Catch2.

## Prerequisites

- CMake 3.20 or higher
- A C++23 compatible compiler:
    - GCC 11+ (Linux/macOS)
    - Clang 14+ (Linux/macOS)
    - Visual Studio 2022+ (Windows)
- Internet connection (for automatic Catch2 download if not installed locally)

## Building the Project

### Linux/macOS

```bash
# Clone the repository
git clone https://github.com/joe-mcgarry/RPS.git
cd RPS

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Build the project
make

# Run the game
./bin/RPS

# Run tests
./bin/tests
# or use CTest
ctest
```

### Windows (Command Prompt)

```cmd
# Clone the repository
git clone https://github.com/joe-mcgarry/RPS.git
cd RPS

# Create build directory
mkdir build
cd build

# Generate build files (Visual Studio)
cmake ..

# Build the project
cmake --build . --config Release

# Run the game
.\bin\Release\RPS.exe

# Run tests
.\bin\Release\tests.exe
```

### Alternative One-liner Build

```bash
# From project root
cmake -B build && cmake --build build
```

## Project Structure

```
RPS/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── Game.cpp
│   └── GameInterface.cpp
├── include/
│   ├── Game.h
│   ├── GameInterface.h
│   └── GameConstants.h
├── tests/              # New directory
│   └── test_main.cpp   # Moved here
└── build/
```
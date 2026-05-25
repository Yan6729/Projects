#!/bin/bash
# Alternative build script using CMake

set -e

echo "Starting build process..."

echo "Creating build directory..."
mkdir -p build
cd build

echo "Configuring project with CMake..."
cmake ..

echo "Compiling the project..."
# Using $(nproc) to use all available CPU cores for faster compilation
make -j$(nproc)

echo "Build successful! Arcade binary is at the root and plugins are in the lib/ directory."

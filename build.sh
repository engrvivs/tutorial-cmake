#!/bin/bash

echo "Removing earlier build ..."
rm -rf build

echo "Creating new build"
mkdir build
cd build

cmake ../src/
cmake --build .

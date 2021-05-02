#!/bin/bash
#set -x
#set -v

echo "Removing earlier build ..."
rm -rf .cache/
rm -rf build

echo "Creating new build"
mkdir build
cd build

## Option to include custom (math) library - S ##
read -p "USE_MYMATH (ON/OFF): " use_mymath
if [[ "${use_mymath^^}" != "ON" ]]
then
    cmake ../src/
else
    cmake -DUSE_MYMATH=ON ../src/
fi
## Option to include custom (math) library - E ##

# install appropriate header files, libraries and executables
# CMAKE_INSTALL_PREFIX to determine the root of where files will be installed
# --prefix to provide custom installation directory
# --config to specify configuration
cmake --install

cmake --build .

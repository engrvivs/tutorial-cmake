# CMake - Tutorial

## Step 2: tags 0.4.0, 0.5.0 - Add a Library

- tag: 0.5.0 - classic approach to optionally include a library

## Step 3: tags 0.5.1/2 - Add a Library (INTERFACE usage requirement)

- Anbody linking to MathFunctions library needs to include the current source
directory, while MathFunctions itself doesn't

## Step 4: Basic Install (0.5.3) and Test support (0.5.4) through CMake

## Step 5: (0.6.0) System Inspection

- test for availability of platform specific functions using `CheckSymbolExists`
module
- accordingly, use new defines in `TutotialConfig.h.in`

## References

- [cmake.org](https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html)
- [Gitlab Kitware/cmake `Help/guide/tutorial`](https://gitlab.kitware.com/cmake/cmake/-/tree/master/Help/guide/tutorial)

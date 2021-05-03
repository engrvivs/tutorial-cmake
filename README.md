# CMake - Tutorial

## Step 2: tags [0.4.0](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.4.0-lw), [0.5.0](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.0-lw) - Add a Library

- tag: [0.5.0](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.0-lw) - classic approach to optionally include a library

## Step 3: tags [0.5.1](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.1-lw)/[0.5.2](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.2-lw) - Add a Library (INTERFACE usage requirement)

- Anbody linking to MathFunctions library needs to include the current source
directory, while MathFunctions itself doesn't

## Step 4: Basic Install ([0.5.3](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.3)) and Test support ([0.5.4](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.5.4)) through CMake

## Step 5: ([0.6.0](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.6.0-lw)/[0.6.1](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.6.1-lw)/[0.6.2](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.6.2)) System Inspection

- test for availability of platform specific functions using `CheckSymbolExists`
module
- accordingly, use new defines in `TutorialConfig.h.in`
- [0.6.3](https://github.com/engrvivs/tutorial-cmake/releases/tag/0.6.3-lwt) specify `PRIVATE` compile definitions, rather than through `TutorialConfig.h.in`

## References

- [cmake.org](https://cmake.org/cmake/help/v3.16/guide/tutorial/index.html)
- [Gitlab Kitware/cmake `Help/guide/tutorial`](https://gitlab.kitware.com/cmake/cmake/-/tree/master/Help/guide/tutorial)

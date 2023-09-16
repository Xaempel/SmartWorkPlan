# SmartWorkPlan

[![License](https://img.shields.io/badge/License-GPLv2-blue.svg)](https://www.gnu.org/licenses/gpl-2.0.html)
![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
[![Catch2](https://img.shields.io/badge/Tested_with-Catch2-2f2f2f.svg)](https://github.com/catchorg/Catch2)
[![Qt](https://img.shields.io/badge/Framework-Qt-41CD52.svg)](https://www.qt.io/)

## Description
SmartWorkPlan is intended to be an intelligent aid in creating a work plan for employees.
Source for SmartWorkPlan is available on github
[Link](https://github.com/Xaempel/SmartWorkPlan)

### Project Reference

* [Documentation](docs/ReadMe.md)

* [Contributing](.github/CONTRIBUTING.md)

  --> [Code Formatting for this project](.github/CONTRIBUTING.md#1-using-clang-format)

### README.md Reference

* [License](#license)

* [System Requirements](#system-requirements)

* [Installation](#installation)

* [Building and Running](#building-and-running)

* [Tools and Dependencies](#tools-and-dependencies)

* [Authors](#authors)

* [Acknowledgements](#acknowledgements)

* [Contact](#contact)

## License

This project is licensed under the GNU General Public License version 2. You can find the full text of the license in the LICENSE file.

The project also uses the catch2 library which uses the Boost software license 1.0 [Link for license](https://github.com/catchorg/Catch2/blob/devel/LICENSE.txt).

[Return](#readmemd-reference)
## System Requirements

To run SmartWorkPlan, your system should meet the following requirements:

- Compiler: C++20 compatible compiler (GCC 13.1.1 or later)
- Libraries and Dependencies:
  - Qt Framework: Version 6 or later
  - CMake: Version 3.20 or later
  - Git: Version 2.41.0 or later 
  - Clang-format: Version 16.0.5 or later
  - Catch2 Version 2.13.7 or later  

[Return](#readmemd-reference)
## Installation

1. Clone this project to your device with the git command:
2. Navigate to the project folder:
3. Install the dependencies:

[Return](#readmemd-reference)
## Building and Running 

Creat build dir

``` mkdir build ``` 

Enter build dir

``` cd build ``` 

Build cmake 

``` cmake .. ``` 

Compiling projects

``` ninja ``` 

Enter app 
``` ./app ```  

**or enter gui e.g windows or ubuntu and enter build folders and click on application icon to start app in gui**

[Return](#readmemd-reference)
## Tools and Dependencies

This project uses the following tools and dependencies:

* [CMake](https://cmake.org/): Cross-platform build system.
  [CMake Source](https://github.com/Kitware/CMake)

* [Qt](https://www.qt.io/): Cross-platform application framework.
  * Project uses the following modules Qt Widgets, PrintSupport code for these modules can be found in the links below

  [Qt Source Archives any version](https://download.qt.io/archive/qt/)
  [Qt Source Archive version 6.0.0](https://download.qt.io/archive/qt/6.0/6.0.0/)

* [Git](https://git-scm.com/): Git is a free and open source distributed version control.
  [Git Source](https://github.com/git/git)

* [Clang-format](https://llvm.org/): A tool supplied with the Clang compiler,
  [Clang-format Source](https://github.com/llvm/llvm-project/tree/main/clang/tools/clang-format)
  [Clang-format reference](https://clang.llvm.org/docs/ClangFormat.html)

* [Catch2 Readme File on GitHub](https://github.com/catchorg/Catch2/blob/devel/README.md): Catch2 is a unit testing framework for C++.
  [Catch2 Source](https://github.com/catchorg/Catch2) 

  Catch2 library uses Boost Software-1.0 license more on project github page [Link for license](https://github.com/catchorg/Catch2/blob/devel/LICENSE.txt) 
  or in build/_deps/catch2-src/LICENSE.txt 
  (this directory will be available after building the project because cmake downloads catch2 from the internet) path or similar

[Return](#readmemd-reference)

## Authors

* [Xaempel]

[Return](#readmemd-reference)
## Acknowledgements

thanks to the following people or organization

-- [Qt Company](https://www.qt.io/) for Qt framework

-- [Catch2 community ](https://github.com/catchorg/Catch2) for Catch2 test library

-- [Kitware and cmake community](https://github.com/Kitware/CMake) for cmake tools

-- [LLVM community](https://github.com/llvm/llvm-project) for llvm tools

-- [Git community and linus torvalds](https://github.com/git/git) for creating Git and other good tools 

and other people on contributing projects for used for this project you are all great :> 

[Return](#readmemd-reference)
## Contact 

If you have any questions or feedback, feel free to contact us at: [xaempelfeedback@gmail.com]

[Return](#readmemd-reference)
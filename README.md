# cpp_tutorial
This repo contains cpp tutorial with cmake.

## Pointers
- The most basic CMake project is an executable built from a single source code file. For simple projects like this, a CMakeLists.txt file with three commands is all that is required.
    
    - **cmake_minimum_required()** : Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command. This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.
    
    - **project()** : To start a project, we use the project() command to set the project name. This call is required with every project and should be called soon after cmake_minimum_required(). As we will see later, this command can also be used to specify other project level information such as the language or version number.
    
    - **add_executable()** : The add_executable() command tells CMake to create an executable using the specified source code files.

-

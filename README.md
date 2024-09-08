# cpp_tutorial
This repo contains cpp tutorial with cmake.

## Pointers
- The most basic CMake project is an executable built from a single source code file. For simple projects like this, a CMakeLists.txt file with three commands is all that is required.
    
    - **cmake_minimum_required()** : Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command. This establishes policy settings and ensures that the following CMake functions are run with a compatible version of CMake.
    
    - **project()** : To start a project, we use the project() command to set the project name. This call is required with every project and should be called soon after cmake_minimum_required(). As we will see later, this command can also be used to specify other project level information such as the language or version number.
    
    - **add_executable()** : The add_executable() command tells CMake to create an executable using the specified source code files.


- **Specifying the C++ Standard** : We will need to explicitly state in the CMake code that it should use the correct flags. One way to enable support for a specific C++ standard in CMake is by using the **CMAKE_CXX_STANDARD** variable. For this tutorial, set the CMAKE_CXX_STANDARD variable in the CMakeLists.txt file to 17 and **CMAKE_CXX_STANDARD_REQUIRED** to True. Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable().

- **include_directories(x/y)** affects directory scope. All executable targets in this CMakeList, as well as those in all subdirectories added after the point of its call, will have the path x/y added to their include path. <br /> **target_include_directories(t x/y)** has target scope—it adds x/y to the include path for executable target t.

-  
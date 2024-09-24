# Any project's top most CMakeLists.txt must start by specifying a minimum CMake version using the cmake_minimum_required() command.
# Mandatory
cmake_minimum_required(VERSION 3.22.1)

# To start a project, we use the project() command to set the project name. 
# This call is required with every project and should be called soon after cmake_minimum_required().
# Mandatory
project(cpp_tutorial)


# We will need to explicitly state in the CMake code that it should use the correct flags. 
# One way to enable support for a specific C++ standard in CMake is by using the CMAKE_CXX_STANDARD variable. 
# For this tutorial, set the CMAKE_CXX_STANDARD variable in the CMakeLists.txt file to 17 and CMAKE_CXX_STANDARD_REQUIRED to True. 
# Make sure to add the CMAKE_CXX_STANDARD declarations above the call to add_executable().
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Bring the headers, such as xyz.hpp into the project. This makes headers available for all the apps within the program.
# include_directories("include")

# Can manually add the sources using the set command as follows:
# set(SOURCES src/mainapp.cpp src/xyz.cpp)

# However, the file(GLOB...) allows for wildcard additions:
# file(GLOB SOURCES "src/*.cpp")
# Finally, the add_executable() command tells CMake to create an executable using the specified source code files.
set(SOURCES src/01_hello_world.cpp)
add_executable(01_hello_world ${SOURCES})
target_include_directories(01_hello_world PUBLIC "include")

set(SOURCES src/02_pointers.cpp)
add_executable(02_pointers ${SOURCES})

set(SOURCES src/03_dynamic_memory.cpp)
add_executable(03_dynamic_memory ${SOURCES})

set(SOURCES src/04_structures.cpp)
add_executable(04_structures ${SOURCES})

set(SOURCES src/05_class_example_01.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_01 ${SOURCES})
target_include_directories(05_class_example_01 PUBLIC "include/class")

set(SOURCES src/05_class_example_02.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_02 ${SOURCES})
target_include_directories(05_class_example_02 PUBLIC "include/class")

set(SOURCES src/05_class_example_03.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_03 ${SOURCES})
target_include_directories(05_class_example_03 PUBLIC "include/class")

set(SOURCES src/05_class_example_04.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_04 ${SOURCES})
target_include_directories(05_class_example_04 PUBLIC "include/class")

set(SOURCES src/05_class_example_05.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_05 ${SOURCES})
target_include_directories(05_class_example_05 PUBLIC "include/class")

set(SOURCES src/05_class_example_06.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_06 ${SOURCES})
target_include_directories(05_class_example_06 PUBLIC "include/class")

set(SOURCES src/05_class_example_07.cpp src/utils/class_helper.cpp)
add_executable(05_class_example_07 ${SOURCES})
target_include_directories(05_class_example_07 PUBLIC "include/class")

set(SOURCES src/06_type_conversions.cpp)
add_executable(06_type_conversions ${SOURCES})

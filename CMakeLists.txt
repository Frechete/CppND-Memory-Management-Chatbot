cmake_minimum_required(VERSION 3.11.3)

IF (CMAKE_VERSION VERSION_GREATER_EQUAL "3.12.0")
  # `FindOpenGL`` prefers GLVND by default when available:
  CMAKE_POLICY(SET CMP0072 NEW)
ENDIF(CMAKE_VERSION VERSION_GREATER_EQUAL "3.12.0")

FIND_PACKAGE(OpenGL)


set(CMAKE_CXX_STANDARD 17)

project(Membot)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)

add_executable(membot ${project_SRCS})
target_link_libraries(membot ${wxWidgets_LIBRARIES})
target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})

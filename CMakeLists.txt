cmake_minimum_required(VERSION 3.11.3)


set(CMAKE_CXX_STANDARD 17)

project(Membot)

find_package(wxWidgets REQUIRED COMPONENTS core base)
#find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
include(clang-format.cmake)


file(GLOB project_SRCS src/*.cpp)

add_executable(membot ${project_SRCS})
target_link_libraries(membot ${wxWidgets_LIBRARIES})

target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})



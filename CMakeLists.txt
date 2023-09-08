cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME "StateMachine")

project(${PROJECT_NAME}
    LANGUAGES CXX
    VERSION "1.0.0"
)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wconversion -Wsign-conversion -Winit-self -Wunreachable-code -pedantic -D_GLIBCXX_USE_NANOSLEEP -DLINUX -lpthread")
message(STATUS "CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler options: ${CMAKE_CXX_FLAGS}")

add_subdirectory(src)

if(TEST_ENABLE)
  enable_testing()
  # find_package(gtest REQUIRED)
  add_subdirectory(tst)
endif()
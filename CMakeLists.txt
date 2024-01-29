cmake_minimum_required(VERSION 3.0)

project(interactive_program)

set(CMAKE_CXX_STANDARD 17)

set(SRC_FILES
    src/main.cpp
    src/cmdhandler.cpp
    src/cmdbuiltin.cpp
)

include_directories(
    inc
)

set(EXE_NAME app)

add_executable(${EXE_NAME} ${SRC_FILES})
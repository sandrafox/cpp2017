cmake_minimum_required(VERSION 3.8)
project(FutureAndPromise)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp promise.h shared_state.h)
add_executable(FutureAndPromise ${SOURCE_FILES})
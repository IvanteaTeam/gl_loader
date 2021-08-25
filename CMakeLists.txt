cmake_minimum_required(VERSION 3.20)

project(gl_loader LANGUAGES CXX)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE headers ${dir}/include/*.hpp)
file(GLOB src ${dir}/src/*.cpp)

message(WARNING ${headers})

add_library(gl_loader STATIC ${headers} ${src})

target_compile_features(gl_loader PUBLIC cxx_std_17)
target_include_directories(gl_loader PUBLIC ${dir}/include)

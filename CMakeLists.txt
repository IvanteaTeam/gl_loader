cmake_minimum_required(VERSION 3.20)



include(FetchContent)

FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
    GIT_TAG 30368fe7ac297cae50acced001fbea2ed8ad9a97
)

FetchContent_GetProperties(glad)

if(NOT glad_POPULATED)

    FetchContent_Populate(glad)

endif()

set(GLAD_SOURCES_DIR ${glad_SOURCE_DIR})

add_subdirectory(${glad_SOURCE_DIR}/cmake/ ${glad_BINARY_DIR} EXCLUDE_FROM_ALL)

glad_add_library(glad_lib STATIC EXCLUDE_FROM_ALL QUIET LOADER ALIAS LOCATION ${glad_BINARY_DIR}/ API gl:core=4.6 wgl=1.0  EXTENSIONS WGL_EXT_swap_control WGL_ARB_pixel_format)

project(gl_loader LANGUAGES CXX)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE headers ${dir}/include/*.hpp)
file(GLOB src ${dir}/src/*.cpp)

add_library(gl_loader STATIC ${headers} ${src})

target_compile_features(gl_loader PUBLIC cxx_std_17)
target_include_directories(gl_loader PUBLIC ${dir}/include ${glad_BINARY_DIR}/include)
target_link_libraries(gl_loader PRIVATE glad_lib)

message(WARNING ${glad_BINARY_DIR}/include)
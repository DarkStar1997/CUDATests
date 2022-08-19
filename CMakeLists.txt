cmake_minimum_required(VERSION 3.22)
enable_language(CUDA)
find_program(CCACHE_PROGRAM ccache)

if(CCACHE_PROGRAM)
    MESSAGE("CCACHE support enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE "Release")

set(FETCHCONTENT_QUIET FALSE)
include(FetchContent)

FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY "https://github.com/fmtlib/fmt"
    GIT_TAG fbb568bce09347da842e1fcda4277c978f711dd9
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(fmtlib)

function(add_code name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} tbb fmt)
endfunction()

function(add_cuda_code name)
    add_executable(${name} ${name}.cu)
    target_link_libraries(${name} fmt::fmt)
endfunction()

add_code(test1)
add_code(generate)
add_cuda_code(test2)

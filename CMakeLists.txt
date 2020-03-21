cmake_minimum_required(VERSION 3.11)

project(Graphs LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

add_library(graph)
add_executable(tests)

target_sources(graph
    PRIVATE
        src/bfs.cpp
        src/dfs.cpp
        src/topological.cpp
)

target_include_directories(graph
    PUBLIC
        include
)

# Unit testing
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
)

FetchContent_MakeAvailable(Catch2)

target_link_libraries(tests graph Catch2::Catch2)

target_sources(tests
    PRIVATE
        tests/main.cpp
        tests/bfs.cpp
        tests/dfs.cpp
        tests/topological.cpp
)


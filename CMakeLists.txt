cmake_minimum_required(VERSION 3.5)
project(magic_enum)

add_library(magic_enum INTERFACE)
target_include_directories(magic_enum INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(magic_enum INTERFACE -std=c++11)

add_executable(magic_enum_example examples/main.cpp)
target_link_libraries(magic_enum_example PRIVATE magic_enum)

add_executable(magic_enum_test tests/test_magic_enum.cpp)
target_link_libraries(magic_enum_test PRIVATE magic_enum)

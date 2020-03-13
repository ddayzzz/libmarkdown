cmake_minimum_required(VERSION 2.8)
project(libmarkdown)
# set output path of lib and demo
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# require C++11
set(CMAKE_CXX_STANDARD 11)
include_directories(inc)
# library
add_library(markdown STATIC "src/lex_parse.cpp" "src/parser.cpp")
# demo
add_executable(md2html "src/demo.cpp")
target_link_libraries(md2html markdown)
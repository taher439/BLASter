cmake_minimum_required(VERSION 3.0)

project(Optimizer C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

add_executable(optimizer src/main.c src/symbol.c src/lex.yy.c src/y.tab.c src/headers/symbol.h src/headers/defs.h src/headers/y.tab.h)
target_link_libraries(optimizer rt pthread )
target_compile_options(optimizer PRIVATE  -Wall)

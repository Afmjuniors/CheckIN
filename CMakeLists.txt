cmake_minimum_required(VERSION 3.7.0)

project(Cadastro)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 1)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)

add_executable(cadastro "")
target_sources(cadastro 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/database.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/helper/helper.c
    ${CMAKE_CURRENT_LIST_DIR}/src/check.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/menu.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/use_cases/check_add.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/use_cases/check_find.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/use_cases/check_list.c 
    ${CMAKE_CURRENT_LIST_DIR}/src/use_cases/check_quit.c 
    )

target_include_directories(cadastro 
    PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/include 
    ${CMAKE_CURRENT_LIST_DIR}/src/repository/file 

)
cmake_minimum_required(VERSION 3.11)
project(clib C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

#library source
aux_source_directory(. LIB_SRCS)
list(REMOVE_ITEM LIB_SRCS "test*")
add_library(clib ${LIB_SRCS})

#test_sds
add_executable(test_sds test_sds.c)
target_link_libraries(test_sds clib)

#test_dlist
add_executable(test_dlist test_dlist.c)
target_link_libraries(test_dlist clib)
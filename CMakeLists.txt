cmake_minimum_required(VERSION 3.0)
project(serv_test)

include_directories(_include)

#set(SOURCES ./app/serv.c)
file(GLOB SOURCES "./app/*.cpp")

add_executable(testServ ${SOURCES})


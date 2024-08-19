cmake_minimum_required(VERSION 3.28)

project(TP-jogosTabuleiro-cpp)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.hpp")

add_executable(TP-jogosTabuleiro-cpp ${SOURCES})

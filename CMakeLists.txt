cmake_minimum_required(VERSION 3.28)

project(TP-jogosTabuleiro-cpp)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES "src/*.cpp")


include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(TP-jogosTabuleiro-cpp ${SOURCES})

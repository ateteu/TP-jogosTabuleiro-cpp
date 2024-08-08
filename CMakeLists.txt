cmake_minimum_required(VERSION 3.28)

project(TP-jogosTabuleiro-cpp)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.hpp")

add_executable(TP-jogosTabuleiro-cpp ${SOURCES} ${HEADERS})

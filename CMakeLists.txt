cmake_minimum_required(VERSION 3.28)

project(TP-jogosTabuleiro-cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP-jogosTabuleiro-cpp
				       src/main.cpp src/Jogador.cpp 
				       src/Cadastro_de_jogadores.cpp )

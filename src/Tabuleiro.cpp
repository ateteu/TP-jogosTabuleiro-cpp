#include "../include/Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro() {

}

void Tabuleiro::inicializar(int _linhas, int _colunas) {
    this -> linhas = _linhas;
    this -> colunas = _colunas;
}

void Tabuleiro::definirPosicao(int _linha, int _coluna, char _valor) {
    
}

void Tabuleiro::imprimir() {
    // desenha a quantidade de linhas do tabuleiro
    for(int i = 0; i < this -> linhas; i ++) {
        // desenha as colunnas do tabuleiro
        for(int i = 0; i < this -> colunas; i++) {
            std::cout << "|" << std::endl;
        }
    }
}

Tabuleiro::~Tabuleiro() {
}


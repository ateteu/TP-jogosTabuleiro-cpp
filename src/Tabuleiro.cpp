#include "../include/Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro() {

}

void Tabuleiro::inicializar(int _linhas, int _colunas) {
    this -> linhas = _linhas;
    this -> colunas = _colunas;
}

bool Tabuleiro::posicaoValida(int _x, int _y) {

}


void Tabuleiro::definirPosicao(int _x, int  _y, char _peca) {
    if(posicaoValida(_x, _y)) {
        //tabuleiro[_x][_y] = _peca;
    }
    
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


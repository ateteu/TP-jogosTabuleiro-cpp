#include "../include/Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro() {

}

void Tabuleiro::inicializar(int _linhas, int _colunas) {
    this -> linhas = _linhas;
    this -> colunas = _colunas;
    // Aloca matriz para o tabuleiro

    matrizTabuleiro = new char*[_linhas];

    for(int i = 0; i < _linhas; i++){
        matrizTabuleiro[i] = new char [colunas];
        for (int j = 0; j < _colunas; j++) {
            matrizTabuleiro[i][j] = '.'; // inicializa as posicoes com ponto
        }
    }
}

void Tabuleiro::definirPosicao(int _x, int _y, char _peca) {
    if(_x >= 0 && _x < linhas && _y >= 0 && _y < colunas){
        matrizTabuleiro[_x][_y] = _peca;
    }
}

char Tabuleiro::obterPeca(int _x, int _y) {
    if(_x >= 0 && _x < linhas && _y >= 0 && _y < colunas) {
        return matrizTabuleiro[_x][_y];
    }
    return '.'; // retorna um '.' se a posicao for inválida
}

bool Tabuleiro::posicaoValida(int _x, int _y) {
    return ( (_x >= 0 &&  _x < linhas && _y >= 0 && _y < colunas) && (matrizTabuleiro[_x][_y] == '.'));
}

void Tabuleiro::imprimir() {
    // desenha a quantidade de linhas do tabuleiro
    for(int i = 0; i < this -> linhas; i ++) {
        // desenha as colunnas do tabuleiro
        for(int j = 0; j < this -> colunas; j++) {
            std::cout << matrizTabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Tabuleiro::~Tabuleiro() {
    if (matrizTabuleiro) {
        for (int i = 0; i < linhas; i++) {
            delete[] matrizTabuleiro[i];
            /* code */
        }
        delete[] matrizTabuleiro;
    }
    
}


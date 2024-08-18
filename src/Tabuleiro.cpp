#include "../include/Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro() : linhas(0), colunas(0), matrizTabuleiro(nullptr) {
    // Inicializa o número de linhas e colunas e a matrizTabuleiro
}

void Tabuleiro::configurarTabuleiro(int _linhas, int _colunas) {
    linhas = _linhas;
    colunas = _colunas;

    // Aloca matriz para o tabuleiro
    matrizTabuleiro = new char*[linhas];
    for (int i = 0; i < linhas; i++) {
        matrizTabuleiro[i] = new char[colunas];
        for (int j = 0; j < colunas; j++) {
            matrizTabuleiro[i][j] = '.'; // inicializa as posições com ponto
        }
    }
}

void Tabuleiro::definirPosicao(int _x, int _y, char _peca) {
    if (posicaoValida(_x, _y)) {
        matrizTabuleiro[_x][_y] = _peca;
    }
}

char Tabuleiro::obterPeca(int _x, int _y) {
    if (posicaoValida(_x, _y)) {
        return matrizTabuleiro[_x][_y];
    }
    return '.'; // retorna um '.' se a posição for inválida
}

bool Tabuleiro::posicaoValida(int _x, int _y) {
    return (_x >= 0 && _x < linhas && _y >= 0 && _y < colunas);
}

void Tabuleiro::imprimir() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << matrizTabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Tabuleiro::~Tabuleiro() {
    if (matrizTabuleiro) {
        for (int i = 0; i < linhas; i++) {
            delete[] matrizTabuleiro[i];
        }
        delete[] matrizTabuleiro;
    }
}

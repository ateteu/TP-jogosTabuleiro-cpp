#include "../include/Tabuleiro.hpp"
#include <iostream>

Tabuleiro::Tabuleiro() : linhas(0), colunas(0) {}

void Tabuleiro::configurarTabuleiro(int _linhas, int _colunas) {
    // Verifica se há uma matriz alocada previamente e libera a memória
    if (matrizTabuleiro) {
        matrizTabuleiro.reset();
    }

    linhas = _linhas;
    colunas = _colunas;

    // Aloca a matriz para o tabuleiro usando smart pointers
    matrizTabuleiro = std::make_unique<std::unique_ptr<char[]>[]>(linhas);
    for (int i = 0; i < linhas; i++) {
        matrizTabuleiro[i] = std::make_unique<char[]>(colunas);
        for (int j = 0; j < colunas; j++) {
            matrizTabuleiro[i][j] = '.'; // Inicializa as posições com ponto
        }
    }

    // Imprime o tabuleiro após a configuração
    imprimir();
}

void Tabuleiro::definirPosicao(int _x, int _y, char _peca) {
    if (posicaoValida(_x, _y)) {
        matrizTabuleiro[_x][_y] = _peca;
    } else {
        throw std::out_of_range("Posição inválida no tabuleiro");
    }
}

char Tabuleiro::obterPeca(int _x, int _y) const {
    if (posicaoValida(_x, _y)) {
        return matrizTabuleiro[_x][_y];
    }
    return '.'; // Retorna um '.' se a posição for inválida
}

bool Tabuleiro::posicaoValida(int _x, int _y) const {
    return (_x >= 0 && _x < linhas && _y >= 0 && _y < colunas);
}

void Tabuleiro::imprimir() const {
    for (int i = 0; i < linhas - 6; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cout << matrizTabuleiro[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Tabuleiro::~Tabuleiro() = default; // Destrutor padrão

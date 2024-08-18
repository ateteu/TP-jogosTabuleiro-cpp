#include "Lig4.hpp"
#include <iostream>

// Construtor
Lig4::Lig4() {
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro() {
    // Inicializa o tabuleiro com as dimensões específicas para Lig4
    tabuleiro.inicializar(altura, largura);
}

bool Lig4::validarJogada(int coluna) {
    // Verifica se a coluna é válida e se há espaço disponível na coluna
    if (coluna < 0 || coluna >= largura) {
        std::cout << "Coluna inválida!" << std::endl;
        return false;
    }
    if (tabuleiro[0][coluna] != ' ') {
        std::cout << "Coluna cheia!" << std::endl;
        return false;
    }
    return true;

    bool Lig4::verificarCondicaoVitoria() {
    // Verifica as condições de vitória em todas as direções (horizontal, vertical, diagonal)
        char jogador = jogadorAtual->getSimbolo();

    // Verifica horizontalmente
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i][j+1] == jogador &&
                    tabuleiro[i][j+2] == jogador && tabuleiro[i][j+3] == jogador) {
                    return true;
                }
            }
        }

    // Verifica verticalmente
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura; j++) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i+1][j] == jogador &&
                    tabuleiro[i+2][j] == jogador && tabuleiro[i+3][j] == jogador) {
                    return true;
                }
            }
        }

    // Verifica diagonal (cima para baixo DIAGONAL DESCENDENTE)
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i+1][j+1] == jogador &&
                    tabuleiro[i+2][j+2] == jogador && tabuleiro[i+3][j+3] == jogador) {
                    return true;
                }
            }
        }

     // Verifica diagonal (baixo para cima DIAGONAL ASCENDENTE)
        for (int i = 3; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro[i][j] == jogador && tabuleiro[i-1][j+1] == jogador &&
                    tabuleiro[i-2][j+2] == jogador && tabuleiro[i-3][j+3] == jogador) {
                    return true;
                }
            }
        }

        return false;
    }
}
#include "Lig4.hpp"
#include <iostream>

// Construtor
Lig4::Lig4() {
    inicializarTabuleiro();
}

void Lig4::inicializarTabuleiro() {
    tabuleiro->configurarTabuleiro(altura, largura);
}

bool Lig4::validarJogada(int linha, int coluna, Jogador* jogador) {
    if (coluna < 0 || coluna >= largura) {
        std::cout << "Coluna inválida!" << std::endl;
        return false;
    }
    if (tabuleiro->obterPeca(0, coluna) != '.') {
        std::cout << "Coluna cheia!" << std::endl;
        return false;
    }
    return true;
}

int Lig4::verificarCondicaoVitoria() {
    
    char jogador = getJogadorAtual() -> minhaPeca();
    char oponente = (jogador == jogador1Peca) ? jogador2Peca : jogador1Peca;

    // Verifica horizontalmente
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura - 3; j++) {
            if (tabuleiro->obterPeca(i, j) == jogador &&
                tabuleiro->obterPeca(i, j+1) == jogador &&
                tabuleiro->obterPeca(i, j+2) == jogador &&
                tabuleiro->obterPeca(i, j+3) == jogador) {
                return 1;  // Jogador atual venceu
            }
        }
    }

    // Verifica verticalmente
    for (int i = 0; i < altura - 3; i++) {
        for (int j = 0; j < largura; j++) {
            if (tabuleiro->obterPeca(i, j) == jogador &&
                tabuleiro->obterPeca(i+1, j) == jogador &&
                tabuleiro->obterPeca(i+2, j) == jogador &&
                tabuleiro->obterPeca(i+3, j) == jogador) {
                return 1;  // Jogador atual venceu
            }
        }
    }

    // Verifica diagonal (cima para baixo - DIAGONAL DESCENDENTE)
    for (int i = 0; i < altura - 3; i++) {
        for (int j = 0; j < largura - 3; j++) {
            if (tabuleiro->obterPeca(i, j) == jogador &&
                tabuleiro->obterPeca(i+1, j+1) == jogador &&
                tabuleiro->obterPeca(i+2, j+2) == jogador &&
                tabuleiro->obterPeca(i+3, j+3) == jogador) {
                return 1;  // Jogador atual venceu
            }
        }
    }

    // Verifica diagonal (baixo para cima - DIAGONAL ASCENDENTE)
    for (int i = 3; i < altura; i++) {
        for (int j = 0; j < largura - 3; j++) {
            if (tabuleiro->obterPeca(i, j) == jogador &&
                tabuleiro->obterPeca(i-1, j+1) == jogador &&
                tabuleiro->obterPeca(i-2, j+2) == jogador &&
                tabuleiro->obterPeca(i-3, j+3) == jogador) {
                return 1;  // Jogador atual venceu
            }
        }
    }

    // Verifica se o tabuleiro está cheio
    bool tabuleiroCheio = true;
    for (int j = 0; j < largura; j++) {
        if (tabuleiro->obterPeca(0, j) == '.') {
            tabuleiroCheio = false;
            break;
        }
    }

    if (tabuleiroCheio) {
        return -1;  // Jogo terminou em empate
    }

    return 0;  // O jogo deve continuar
}

void Lig4::realizarJogada() {
    int coluna;
    std::cout << "Digite a coluna a ser jogada" << std::endl;
    std::cin >> coluna;
    if (!validarJogada(0, coluna, getJogadorAtual())) {
        return;
    }

    // Realiza a jogada, ou seja, coloca a peça na posição correta na coluna especificada
    for (int i = altura - 1; i >= 0; i--) {
        if (tabuleiro->obterPeca(i, coluna) == '.') {
            tabuleiro->definirPosicao(i, coluna, getJogadorAtual()-> minhaPeca());
            break;
        }
    }

    // Imprime o estado atual do tabuleiro após a jogada
    tabuleiro->imprimir();
}
#include "../include/Lig4.hpp"
#include "../include/Tabuleiro.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

// Construtor
Lig4::Lig4(Jogador* _jogador1, Jogador* _jogador2)
    : jogador1(_jogador1), jogador2(_jogador2), vezJogador1(true) {}

void Lig4::inicializarTabuleiro() {
    try {
        tabuleiro.configurarTabuleiro(6, 7);
        tabuleiro.imprimir();
    } catch (const std::exception& e) {
        std::cerr << "Erro ao inicializar o tabuleiro: " << e.what() << std::endl;
        throw; // Rethrow the exception to signal failure to the caller
    }
}

bool Lig4::validarJogada(int linha, int coluna, Jogador* jogador, char peca) {
    try {
        if (coluna < 0 || coluna >= largura) {
            throw std::out_of_range("Coluna inválida!");
        }
        if (tabuleiro.obterPeca(0, coluna) != '.') {
            throw std::logic_error("Coluna cheia!");
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro na validação da jogada: " << e.what() << std::endl;
        return false;
    }

    return true;
}

int Lig4::verificarCondicaoVitoria() {
    try {
        char jogador = jogador1->minhaPeca();
        char oponente = (jogador == jogador1Peca) ? jogador2Peca : jogador1Peca;

        // Verifica horizontalmente
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == jogador &&
                    tabuleiro.obterPeca(i, j+1) == jogador &&
                    tabuleiro.obterPeca(i, j+2) == jogador &&
                    tabuleiro.obterPeca(i, j+3) == jogador) {
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica verticalmente
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura; j++) {
                if (tabuleiro.obterPeca(i, j) == jogador &&
                    tabuleiro.obterPeca(i+1, j) == jogador &&
                    tabuleiro.obterPeca(i+2, j) == jogador &&
                    tabuleiro.obterPeca(i+3, j) == jogador) {
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica diagonal (cima para baixo - DIAGONAL DESCENDENTE)
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == jogador &&
                    tabuleiro.obterPeca(i+1, j+1) == jogador &&
                    tabuleiro.obterPeca(i+2, j+2) == jogador &&
                    tabuleiro.obterPeca(i+3, j+3) == jogador) {
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica diagonal (baixo para cima - DIAGONAL ASCENDENTE)
        for (int i = 3; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == jogador &&
                    tabuleiro.obterPeca(i-1, j+1) == jogador &&
                    tabuleiro.obterPeca(i-2, j+2) == jogador &&
                    tabuleiro.obterPeca(i-3, j+3) == jogador) {
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica se o tabuleiro está cheio
        bool tabuleiroCheio = true;
        for (int j = 0; j < largura; j++) {
            if (tabuleiro.obterPeca(0, j) == '.') {
                tabuleiroCheio = false;
                break;
            }
        }

        if (tabuleiroCheio) {
            return -1;  // Jogo terminou em empate
        }

        return 0;  // O jogo deve continuar

    } catch (const std::exception& e) {
        std::cerr << "Erro ao verificar a condição de vitória: " << e.what() << std::endl;
        throw; // Rethrow the exception to signal failure to the caller
    }
}

void Lig4::realizarJogada(Jogador* jogador, char peca) {
    int coluna;
    while (true) {
        try {
            std::cout << "Digite a coluna a ser jogada:" << std::endl;
            std::cin >> coluna;

            if (std::cin.fail()) {
                std::cin.clear(); // clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                throw std::invalid_argument("Entrada inválida. Por favor, insira um número.");
            }

            if (validarJogada(0, coluna, jogador, peca)) {
                for (int i = altura - 1; i >= 0; i--) {
                    if (tabuleiro.obterPeca(i, coluna) == '.') {
                        tabuleiro.definirPosicao(i, coluna, peca);
                        tabuleiro.imprimir();
                        return;
                    }
                }
            } else {
                throw std::logic_error("Jogada inválida! Tente novamente.");
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        }
    }
}

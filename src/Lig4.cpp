#include "../include/Lig4.hpp"
#include "../include/Tabuleiro.hpp"
#include <iostream>

// Construtor
Lig4::Lig4(Jogador* _jogador1, Jogador* _jogador2)
    : jogador1(_jogador1), jogador2(_jogador2), vezJogador1(true) {}

void Lig4::inicializarTabuleiro() {
    tabuleiro.configurarTabuleiro(6, 7);
    tabuleiro.imprimir();
}

bool Lig4::validarJogada(int linha, int coluna, Jogador* jogador, char peca) {
    if (coluna < 0 || coluna >= largura) {
        std::cout << "Coluna invalida!" << std::endl;
        return false;
    }
    if (tabuleiro.obterPeca(0, coluna) != '.') {
        std::cout << "Coluna cheia!" << std::endl;
        return false;
    }

    std::cout << "coluna: " << coluna << std::endl;
    return true;
}

int Lig4::verificarCondicaoVitoria(char peca) {

    if(peca == jogador1->minhaPeca()) {
        char jogador = jogador1->minhaPeca();

        // Verifica horizontalmente
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == jogador &&
                    tabuleiro.obterPeca(i, j+1) == jogador &&
                    tabuleiro.obterPeca(i, j+2) == jogador &&
                    tabuleiro.obterPeca(i, j+3) == jogador) {
                    score.adicionarVitorias(jogador1->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador2->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
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
                    score.adicionarVitorias(jogador1->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador2->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
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
                    score.adicionarVitorias(jogador1->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador2->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
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
                    score.adicionarVitorias(jogador1->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador2->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica se o tabuleiro esta cheio
        bool tabuleiroCheio = true;
        for (int j = 0; j < largura; j++) {
            if (tabuleiro.obterPeca(0, j) == '.') {
                tabuleiroCheio = false;
                break;
            }
        }

        if (tabuleiroCheio) {
            score.adicionarEmpates(jogador1->getNome(), "Lig4", 1);  // Atualiza empates
            score.adicionarEmpates(jogador2->getNome(), "Lig4", 1);  // Atualiza empates
            score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
            score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
            return -1;  // Jogo terminou em empate
        }

        return 0;  // O jogo deve continuar
    } 
    if(peca == jogador2->minhaPeca()) {
        char oponente = jogador2->minhaPeca();

        // Verifica horizontalmente
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == oponente &&
                    tabuleiro.obterPeca(i, j+1) == oponente &&
                    tabuleiro.obterPeca(i, j+2) == oponente &&
                    tabuleiro.obterPeca(i, j+3) == oponente) {
                    score.adicionarVitorias(jogador2->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador1->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica verticalmente
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura; j++) {
                if (tabuleiro.obterPeca(i, j) == oponente &&
                    tabuleiro.obterPeca(i+1, j) == oponente &&
                    tabuleiro.obterPeca(i+2, j) == oponente &&
                    tabuleiro.obterPeca(i+3, j) == oponente) {
                    score.adicionarVitorias(jogador2->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador1->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica diagonal (cima para baixo - DIAGONAL DESCENDENTE)
        for (int i = 0; i < altura - 3; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == oponente &&
                    tabuleiro.obterPeca(i+1, j+1) == oponente &&
                    tabuleiro.obterPeca(i+2, j+2) == oponente &&
                    tabuleiro.obterPeca(i+3, j+3) == oponente) {
                    score.adicionarVitorias(jogador2->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador1->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica diagonal (baixo para cima - DIAGONAL ASCENDENTE)
        for (int i = 3; i < altura; i++) {
            for (int j = 0; j < largura - 3; j++) {
                if (tabuleiro.obterPeca(i, j) == oponente &&
                    tabuleiro.obterPeca(i-1, j+1) == oponente &&
                    tabuleiro.obterPeca(i-2, j+2) == oponente &&
                    tabuleiro.obterPeca(i-3, j+3) == oponente) {
                    score.adicionarVitorias(jogador2->getNome(), "Lig4", 1);  // Atualiza vitórias
                    score.adicionarDerrotas(jogador1->getNome(), "Lig4", 1);  // Atualiza derrotas
                    score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
                    score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
                    return 1;  // Jogador atual venceu
                }
            }
        }

        // Verifica se o tabuleiro esta cheio
        bool tabuleiroCheio = true;
        for (int j = 0; j < largura; j++) {
            if (tabuleiro.obterPeca(0, j) == '.') {
                tabuleiroCheio = false;
                break;
            }
        }

        if (tabuleiroCheio) {
            score.adicionarEmpates(jogador1->getNome(), "Lig4", 1);  // Atualiza empates
            score.adicionarEmpates(jogador2->getNome(), "Lig4", 1);  // Atualiza empates
            score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Lig4");
            score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Lig4");
            return -1;  // Jogo terminou em empate
        }

        return 0;  // O jogo deve continuar
    }
    
}

void Lig4::realizarJogada(Jogador* jogador, char peca) {
    int coluna;
    while (true) {
        std::cout << "Digite a coluna a ser jogada:" << std::endl;
        std::cin >> coluna;

        break;
    }

    if(!validarJogada(0, coluna, jogador, peca)) {
        std::cout << "Jogada invalida! Tente novamente" << std::endl;
        realizarJogada(jogador, peca);
    }

    for (int i = altura - 1; i >= 0; i--) {
        if (tabuleiro.obterPeca(i, coluna) == '.') {
            tabuleiro.definirPosicao(i, coluna, peca);
            tabuleiro.imprimir();
            return;
        }
    }
}

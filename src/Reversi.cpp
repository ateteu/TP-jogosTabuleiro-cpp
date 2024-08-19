#include <iostream>
#include "../include/Reversi.hpp"
#include <vector>
#include <utility>
#include <limits>

void Reversi::imprimirTabuleiro() {
    tabuleiro.imprimir();
}

void Reversi::inicializarTabuleiro() {
    tabuleiro.configurarTabuleiro(8, 8); // configura pra ter 8 linhas e 8 colunas
    tabuleiro.definirPosicao(3, 3, 'B');
    tabuleiro.definirPosicao(4, 4, 'B');
    tabuleiro.definirPosicao(3, 4, 'W');
    tabuleiro.definirPosicao(4, 3, 'W');
}

bool Reversi::validarJogada(int x, int y, Jogador* jogador) {
    // verifica se a posição está dentro do tabuleiro e está vazia
    if (!tabuleiro.posicaoValida(x, y) || tabuleiro.obterPeca(x, y) != '.') {
        return false;
    }

    // direções: direita, esquerda, baixo, cima, diagonais
    int direcoes[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, 
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    // determina as peças do jogador e do oponente
    char pecaJogador = jogador->minhaPeca();  // 'W' ou 'B'
    char pecaOponente = (pecaJogador == 'B') ? 'W' : 'B';

    // verifica cada direção
    for (int i = 0; i < 8; i++) {
        int dx = direcoes[i][0];
        int dy = direcoes[i][1];
        int nx = x + dx;
        int ny = y + dy;

        bool encontrouOponente = false;

        // avança na direção até encontrar uma peça do jogador ou sair do tabuleiro
        while (tabuleiro.posicaoValida(nx, ny)) {
            char pecaAtual = tabuleiro.obterPeca(nx, ny);
            if (pecaAtual == pecaOponente) {
                encontrouOponente = true;
            }
            else if (pecaAtual == pecaJogador) {
                // a jogada é válida se encontrar uma peça do jogador após peças do oponente
                if (encontrouOponente) {
                    return true;
                }
                break;
            }
            else {
                break; // encontra uma casa vazia ou fim do tabuleiro
            }
            nx += dx;
            ny += dy;
        }
    }

    // se nenhuma direção for válida, a jogada não é válida
    return false;
}

Reversi::Reversi(Jogador* _jogador1, Jogador* _jogador2)
    : jogador1(_jogador1), jogador2(_jogador2), vezJogador1(true) {}  // Inicializa vezJogador1 como true

int Reversi::verificarCondicaoVitoria() {
    bool temMovimentoParaJogador1 = false;
    bool temMovimentoParaJogador2 = false;

    // Itera por todas as posições do tabuleiro
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (tabuleiro.obterPeca(x, y) == '.') {
                if (validarJogada(x, y, jogador1)) {
                    temMovimentoParaJogador1 = true;
                }
                if (validarJogada(x, y, jogador2)) {
                    temMovimentoParaJogador2 = true;
                }
            }
        }
    }

    // Se nenhum jogador tem movimento válido, conta as peças no tabuleiro
    if (!temMovimentoParaJogador1 && !temMovimentoParaJogador2) {
        int contagemJogador1 = 0;
        int contagemJogador2 = 0;

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                char peca = tabuleiro.obterPeca(x, y);
                if (peca == jogador1->minhaPeca()) {
                    contagemJogador1++;
                } else if (peca == jogador2->minhaPeca()) {
                    contagemJogador2++;
                }
            }
        }

        // Determina o resultado do jogo
        if (contagemJogador1 > contagemJogador2) {
            return 1; // Jogador 1 vence
        } else if (contagemJogador2 > contagemJogador1) {
            return 1; // Jogador 2 vence
        } else {
            return -1; // Empate
        }
    }

    return 0; // O jogo continua
}

void Reversi::capturarDirecao(int x, int y, Jogador* jogador, int deltaX, int deltaY) {
    int i = x + deltaX;
    int j = y + deltaY;
    std::vector<std::pair<int, int>> pecasParaVirar;

    // verifica a sequência de peças
    while (tabuleiro.posicaoValida(i, j) && tabuleiro.obterPeca(i, j) == (jogador == jogador1 ? jogador2->minhaPeca() : jogador1->minhaPeca())) {
        pecasParaVirar.push_back({i, j});
        i += deltaX;
        j += deltaY;
    }

    // verifica se há uma peça do jogador atual no final da sequência
    if (tabuleiro.posicaoValida(i, j) && tabuleiro.obterPeca(i, j) == jogador->minhaPeca()) {
        for (const auto& pos : pecasParaVirar) {
            tabuleiro.definirPosicao(pos.first, pos.second, jogador->minhaPeca());
        }
    }
}

void Reversi::realizarJogada() {
    Jogador* jogadorAtual = (vezJogador1) ? jogador1 : jogador2; // alterna entre jogador1 e jogador2
    int x, y;

    while (true) {
        std::cout << jogadorAtual->getNome() << ", digite a linha a ser jogada (0-7): ";
        std::cin >> x;

        if (std::cin.fail() || x < 0 || x > 7) {
            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida
            std::cout << "Entrada inválida. Por favor, digite um número entre 0 e 7." << std::endl;
            continue;
        }

        std::cout << jogadorAtual->getNome() << ", digite a coluna a ser jogada (0-7): ";
        std::cin >> y;

        if (std::cin.fail() || y < 0 || y > 7) {
            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida
            std::cout << "Entrada inválida. Por favor, digite um número entre 0 e 7." << std::endl;
            continue;
        }

        // se ambas as entradas forem válidas, sai do loop
        break;
    }

    // verifica se a jogada é válida
    if (!validarJogada(x, y, jogadorAtual)) {
        std::cout << "Jogada inválida. Tente novamente." << std::endl;
        return;
    }

    // coloca a peça do jogador no tabuleiro
    tabuleiro.definirPosicao(x, y, jogadorAtual->minhaPeca());

    // lógica para capturar as peças do oponente
    capturarPecas(x, y, jogadorAtual);

    // alterna a vez do jogador
    vezJogador1 = !vezJogador1;
}

void Reversi::capturarPecas(int x, int y, Jogador* jogador) {
    // chama o método para capturar peças em todas as direções
    capturarDirecao(x, y, jogador, 0, 1);  // direita
    capturarDirecao(x, y, jogador, 0, -1); // esquerda
    capturarDirecao(x, y, jogador, 1, 0);  // baixo
    capturarDirecao(x, y, jogador, -1, 0); // cima
    capturarDirecao(x, y, jogador, -1, -1); // diagonal superior esquerda
    capturarDirecao(x, y, jogador, 1, 1);   // diagonal inferior direita
    capturarDirecao(x, y, jogador, -1, 1);  // diagonal superior direita
    capturarDirecao(x, y, jogador, 1, -1);  // diagonal inferior esquerda
}

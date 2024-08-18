#include "../include/Reversi.hpp"

void Reversi::inicializarTabuleiro() {
    tabuleiro.inicializar(8, 8); // configura pra ter 8 linhas e 8 colunas
    tabuleiro.definirPosicao(3, 3, 'B');
    tabuleiro.definirPosicao(4, 4, 'B');
    tabuleiro.definirPosicao(3, 4, 'W');
    tabuleiro.definirPosicao(4, 3, 'W');
}

bool Reversi::validarJogada(int x, int y, Jogador jogador) {
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
    char pecaJogador = jogador.minhaPeca();  // 'W' ou 'B'
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

bool verificarCondicaoVitoria() override {
    // implementação específica do reversi
    return false;
}

void imprimirTabuleiro() override {
    // implementação específica do reversi
}

void realizarJogada(int x, int y, Jogador jogador) override {
    // implementação específica do reversi
}

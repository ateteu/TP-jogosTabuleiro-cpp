#include "../include/Reversi.hpp"

void Reversi::inicializarTabuleiro() {
    tabuleiro.configurarTabuleiro(8, 8); // configura pra ter 8 linhas e 8 colunas
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

bool Reversi::verificarCondicaoVitoria() {
    // verifica se há movimentos válidos para os jogadores
    bool temMovimentoParaJogador1 = false;
    bool temMovimentoParaJogador2 = false;

    // itera por todas as posições do tabuleiro
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (tabuleiro.obterPeca(x, y) == '.') {
                // verifica se há movimentos válidos para o jogador 1
                if (validarJogada(x, y, jogador1)) {
                    temMovimentoParaJogador1 = true;
                }
                // verifica se há movimentos válidos para o jogador 2
                if (validarJogada(x, y, jogador2)) {
                    temMovimentoParaJogador2 = true;
                }
            }
        }
    }

    // verifica se ambos os jogadores não têm mais movimentos válidos
    if (!temMovimentoParaJogador1 && !temMovimentoParaJogador2) {
        // conta peças de cada jogador
        int contagemJogador1 = 0;
        int contagemJogador2 = 0;

        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                char peca = tabuleiro.obterPeca(x, y);
                if (peca == jogador1.minhaPeca()) {
                    contagemJogador1++;
                } else if (peca == jogador2.minhaPeca()) {
                    contagemJogador2++;
                }
            }
        }

        // determina o vencedor
        if (contagemJogador1 > contagemJogador2) {
            // jogador 1 vence
            std::cout << "Jogador 1 vence!" << std::endl;
            jogador1.registrarVitoria();
            jogador2.registrarDerrota();
        } else if (contagemJogador2 > contagemJogador1) {
            // jogador 2 vence
            std::cout << "Jogador 2 vence!" << std::endl;
            jogador2.registrarVitoria();
            jogador1.registrarDerrota();
        } else {
            // empate
            std::cout << "Empate!" << std::endl;
            jogador1.registrarEmpate();
            jogador2.registrarEmpate();
        }

        return true; // jogo terminado
    }

    // o jogo ainda está em andamento
    return false;
}

void imprimirTabuleiro() override {
    // implementação específica do reversi
}

void realizarJogada(int x, int y, Jogador jogador) override {
    // implementação específica do reversi
}

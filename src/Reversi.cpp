#include <iostream>
#include "../include/Reversi.hpp"
#include <vector>
#include <utility>
#include <limits>
#include <iostream>

void Reversi::inicializarTabuleiro() {
    tabuleiro.configurarTabuleiro(8, 8); // configura pra ter 8 linhas e 8 colunas
    tabuleiro.definirPosicao(3, 3, 'B');
    tabuleiro.definirPosicao(4, 4, 'B');
    tabuleiro.definirPosicao(3, 4, 'W');
    tabuleiro.definirPosicao(4, 3, 'W');
    tabuleiro.imprimir();
}

bool Reversi::validarJogada(int x, int y, Jogador* jogador, char peca) {
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
    char pecaJogador = peca;  // 'W' ou 'B'
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

int Reversi::verificarCondicaoVitoria(char peca) {
    bool temMovimentoParaJogador1 = false;
    bool temMovimentoParaJogador2 = false;

    // Itera por todas as posições do tabuleiro
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (tabuleiro.obterPeca(x, y) == '.') {
                if (validarJogada(x, y, jogador1, jogador1->minhaPeca())) {
                    temMovimentoParaJogador1 = true;
                }
                if (validarJogada(x, y, jogador2, jogador2->minhaPeca())) {
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
            score.adicionarVitorias(jogador1->getNome(),"Reverse",1);
            score.adicionarDerrotas(jogador2->getNome(),"Reverse",1);
            score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Reverse");
            score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Reverse");
            return 1; // Jogador 1 vence
        } else if (contagemJogador2 > contagemJogador1) {
            score.adicionarVitorias(jogador2->getNome(),"Reverse",1);
            score.adicionarDerrotas(jogador1->getNome(),"Reverse",1);
            score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Reverse");
            score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Reverse");
            return 1; // Jogador 2 vence
        } else {
            score.adicionarEmpates(jogador1->getNome(),"Reverse",1);
            score.adicionarEmpates(jogador2->getNome(),"Reverse",1);
            score.imprimirEstatisticasPorNomeEJogo(jogador1->getNome(),"Reverse");
            score.imprimirEstatisticasPorNomeEJogo(jogador2->getNome(),"Reverse");
            return -1; // Empate
        }
    }

    return 0; // O jogo continua
}

void Reversi::capturarDirecao(int x, int y, Jogador* jogador, int deltaX, int deltaY, char peca) {
    int i = x + deltaX;
    int j = y + deltaY;
    std::vector<std::pair<int, int>> pecasParaVirar;

    // verifica a sequência de peças
    while (tabuleiro.posicaoValida(i, j) && tabuleiro.obterPeca(i, j) == (jogador->minhaPeca() == 'W' ? 'B' : 'W')) {
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

void Reversi::realizarJogada(Jogador* jogadorAtual, char peca) {
    int x, y;

    std::cout << "Peca do jogador: " << jogadorAtual->minhaPeca() << std::endl;

    while (true) {
        std::cout << "Digite a linha a ser jogada (0-7): ";
        std::cin >> x;

        if (std::cin.fail() || x < 0 || x > 7) {
            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida
            std::cout << "Entrada invalida. Por favor, digite um numero entre 0 e 7." << std::endl;
            continue;
        }

        std::cout << "Digite a coluna a ser jogada (0-7): ";
        std::cin >> y;

        if (std::cin.fail() || y < 0 || y > 7) {
            std::cin.clear(); // limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida
            std::cout << "Entrada invalida. Por favor, digite um numero entre 0 e 7." << std::endl;
            continue;
        }

        // se ambas as entradas forem válidas, sai do loop
        break;
    }

    // verifica se a jogada é válida
    if (!validarJogada(x, y, jogadorAtual, peca)) {
        std::cout << "Jogada invalida. Tente novamente." << std::endl;
        realizarJogada(jogadorAtual, peca);
    }
    else{
        // coloca a peça do jogador no tabuleiro
        tabuleiro.definirPosicao(x, y, jogadorAtual->minhaPeca());

        // lógica para capturar as peças do oponente
        capturarPecas(x, y, jogadorAtual, peca);
    }


}

void Reversi::capturarPecas(int x, int y, Jogador* jogador, char peca) {
    // chama o método para capturar peças em todas as direções
    capturarDirecao(x, y, jogador, 0, 1, peca);  // direita
    capturarDirecao(x, y, jogador, 0, -1, peca); // esquerda
    capturarDirecao(x, y, jogador, 1, 0, peca);  // baixo
    capturarDirecao(x, y, jogador, -1, 0, peca); // cima
    capturarDirecao(x, y, jogador, -1, -1, peca); // diagonal superior esquerda
    capturarDirecao(x, y, jogador, 1, 1, peca);   // diagonal inferior direita
    capturarDirecao(x, y, jogador, -1, 1, peca);  // diagonal superior direita
    capturarDirecao(x, y, jogador, 1, -1, peca);  // diagonal inferior esquerda

    tabuleiro.imprimir(); // imprimir o tabuleiro atualizado
}

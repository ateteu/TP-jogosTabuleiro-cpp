#include "../include/SistemaDeJogo.hpp"
#include <iostream>

SistemaDeJogo::SistemaDeJogo() {
    cadastroDeJogadores.criarArquivoJogadores();
    cadastroDeJogadores.carregarJogadoresDeArquivo("jogadores.txt");
}

void SistemaDeJogo::escolherJogo() {
    int escolha;
    std::cout << "Escolha o jogo: " << std::endl;
    std::cout << "1. Reversi" << std::endl;
    std::cout << "2. Lig4" << std::endl;
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            jogo = std::make_unique<Jogo>(); // Inicializa o Reversi
            break;
        case 2:
            jogo = std::make_unique<Jogo>(); // Inicializa o Lig4
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }
}

void SistemaDeJogo::executarPartida() {
    std::string nomeJogador1, nomeJogador2;
    
    std::cout << "Digite o nome do primeiro jogador: ";
    std::cin >> nomeJogador1;
    Jogador* jogador1 = cadastroDeJogadores.getJogadorPorNome(nomeJogador1);

    if (jogador1 == nullptr) {
        char opcao;
        std::cout << "Jogador " << nomeJogador1 << " não encontrado. Deseja cadastrá-lo? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's' || opcao == 'S') {
            cadastroDeJogadores.adicionarJogadorNoArquivo(nomeJogador1);
            jogador1 = cadastroDeJogadores.getJogadorPorNome(nomeJogador1);
        } else {
            return;
        }
    }

    std::cout << "Digite o nome do segundo jogador: ";
    std::cin >> nomeJogador2;
    Jogador* jogador2 = cadastroDeJogadores.getJogadorPorNome(nomeJogador2);

    if (jogador2 == nullptr) {
        char opcao;
        std::cout << "Jogador " << nomeJogador2 << " não encontrado. Deseja cadastrá-lo? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's' || opcao == 'S') {
            cadastroDeJogadores.adicionarJogadorNoArquivo(nomeJogador2);
            jogador2 = cadastroDeJogadores.getJogadorPorNome(nomeJogador2);
        } else {
            return;
        }
    }

    escolherJogo();

    if (jogo) {
        jogo->inicializarTabuleiro();
        bool turnoJogador1 = true; // Inicia com o jogador 1
        int coluna;

        while (!jogo->verificarCondicaoVitoria()) {
            jogo->imprimirTabuleiro();

            if (turnoJogador1) {
                std::cout << "Vez de " << nomeJogador1 << std::endl;
                std::cout << "Digite a coluna a ser jogada" << std::endl;
                std::cin >> coluna;
                jogo->realizarJogada(coluna); 
            } else {
                std::cout << "Vez de " << nomeJogador2 << std::endl;
                std::cout << "Digite a coluna a ser jogada" << std::endl;
                std::cin >> coluna;
                jogo->realizarJogada(coluna);
            }

            turnoJogador1 = !turnoJogador1; // Alterna o turno entre os jogadores
        }

        jogo->imprimirTabuleiro();
        std::cout << "Fim de jogo!" << std::endl;
    }
}

SistemaDeJogo::~SistemaDeJogo() {
    // Os recursos são automaticamente liberados por causa dos smart pointers
}

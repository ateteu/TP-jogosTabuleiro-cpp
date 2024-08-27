#include "../include/SistemaDeJogo.hpp"
#include <iostream>

SistemaDeJogo::SistemaDeJogo() {
    cadastroDeJogadores.criarArquivoJogadores();
    cadastroDeJogadores.carregarJogadoresDeArquivo("jogadores.txt");
    jogador1 = nullptr;
    jogador2 = nullptr;
}

void SistemaDeJogo::escolherJogo() {
    int escolha;
    std::cout << "Escolha o jogo: " << std::endl;
    std::cout << "1. Reversi" << std::endl;
    std::cout << "2. Lig4" << std::endl;
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            jogo = std::make_unique<Reversi>(jogador1, jogador2); // Inicializa o Reversi
            break;
        case 2:
            jogo = std::make_unique<Lig4>(); // Inicializa o Lig4
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }
}

Jogador* verificarOuCadastrarJogador(const std::string& nome, CadastroDeJogadores& cadastro) {
    Jogador* jogador = cadastro.getJogadorPorNome(nome);
    if (jogador == nullptr) {
        char opcao;
        std::cout << "Jogador " << nome << " não encontrado. Deseja cadastrá-lo? (s/n): ";
        std::cin >> opcao;
        if (opcao == 's' || opcao == 'S') {
            cadastro.adicionarJogadorNoArquivo(nome);
            jogador = cadastro.getJogadorPorNome(nome);
        }
    }
    return jogador;
}

void SistemaDeJogo::executarPartida() {
    std::string nomeJogador1, nomeJogador2;
    
    std::cout << "Digite o nome do primeiro jogador: ";
    std::cin >> nomeJogador1;
    jogador1 = verificarOuCadastrarJogador(nomeJogador1, cadastroDeJogadores);
    if (jogador1 == nullptr) return;

    std::cout << "Digite o nome do segundo jogador: ";
    std::cin >> nomeJogador2;
    jogador2 = verificarOuCadastrarJogador(nomeJogador2, cadastroDeJogadores);
    if (jogador2 == nullptr) return;

    escolherJogo();

    if (jogo) {
        jogo->inicializarTabuleiro();
        bool turnoJogador1 = true;
        int condicaoVitoria = 0;

        while (condicaoVitoria == 0) {
            Jogador* jogadorAtual = turnoJogador1 ? jogador1 : jogador2;
            std::cout << "Vez de " << (turnoJogador1 ? nomeJogador1 : nomeJogador2) << ". ";
            jogadorAtual->setPeca(turnoJogador1 ? 'W' : 'B');
            jogo->realizarJogada(jogadorAtual, jogadorAtual->minhaPeca());

            turnoJogador1 = !turnoJogador1;
            condicaoVitoria = jogo->verificarCondicaoVitoria();
        }

        jogo->imprimirTabuleiro();
        std::cout << "Fim de jogo!" << std::endl;

        if (condicaoVitoria == -1) {
            std::cout << "O jogo terminou em empate!";
            jogador1->registrarEmpate();
            jogador2->registrarEmpate();
        }
        // Outras condições de vitória podem ser adicionadas aqui
    }
}


SistemaDeJogo::~SistemaDeJogo() {
    // Os recursos são automaticamente liberados por causa dos smart pointers
}

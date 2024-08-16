#include "../include/SistemaDeJogo.hpp"
#include <iostream>

SistemaDeJogo::SistemaDeJogo() {
    // Inicializa o tabuleiro e o cadastro de jogadores
    jogo.inicializarTabuleiro();
}

void SistemaDeJogo::inicializar() {
    std::string nome_jogador_1, nome_jogador_2;

    // Entrar com o nome do primeiro jogador
    std::cout << "Entre com o nome do Jogador 1: ";
    std::getline(std::cin, nome_jogador_1);

    Jogador* jogador_1 = cadastro.buscarJogador(nome_jogador_1);
    if (!jogador_1) {
        char opcao;
        std::cout << "Jogador não encontrado. Deseja criar um novo jogador com esse nome? (s/n): ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer de entrada

        if (opcao == 's' || opcao == 'S') {
            cadastro.adicionar_jogador_no_arquivo(nome_jogador_1);
            jogador_1 = cadastro.buscar_jogador_no_arquivo(nome_jogador_1);
        } else {
            std::cout << "Operação cancelada. O jogo não pode prosseguir sem o Jogador 1." << std::endl;
            return;
        }
    }

    // Entrar com o nome do segundo jogador
    std::cout << "Entre com o nome do Jogador 2: ";
    std::getline(std::cin, nome_jogador_2);

    Jogador* jogador_2 = cadastro.buscarJogador(nome_jogador_2);
    if (!jogador_2) {
        char opcao;
        std::cout << "Jogador não encontrado. Deseja criar um novo jogador com esse nome? (s/n): ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer de entrada

        if (opcao == 's' || opcao == 'S') {
            cadastro.adicionar_jogador_no_arquivo(nome_jogador_2);
            jogador_2 = cadastro.buscar_jogador_no_arquivo(nome_jogador_2);
        } else {
            std::cout << "Operação cancelada. O jogo não pode prosseguir sem o Jogador 2." << std::endl;
            return;
        }
    }

    // Inicializa o tabuleiro para a partida
    jogo.inicializarTabuleiro();

    std::cout << "Jogadores prontos! O jogo pode começar." << std::endl;
}

void SistemaDeJogo::executarPartida() {
    int opcao_jogo;

    // Pergunta ao usuário qual jogo ele deseja jogar
    std::cout << "Escolha o jogo que deseja jogar:\n";
    std::cout << "1. Reversi\n";
    std::cout << "2. Lig4\n";
    std::cout << "Digite o número correspondente ao jogo: ";
    std::cin >> opcao_jogo;
    std::cin.ignore(); // Limpa o buffer de entrada

    // Configura o tabuleiro de acordo com a escolha
    switch (opcao_jogo) {
        case 1:
            std::cout << "Você escolheu o Reversi.\n";
            jogo.imprimirTabuleiro();
            break;
        case 2:
            std::cout << "Você escolheu o Lig4.\n";
            jogo.imprimirTabuleiro();
            break;
        default:
            std::cout << "Opção inválida. O jogo será encerrado.\n";
            return;
    }

    // Jogadores alternam após cada jogada
    Jogador* jogador_atual = cadastro.buscar_jogador_no_arquivo(1);  // Começa com o primeiro jogador
    Jogador* outro_jogador = cadastro.buscar_jogador_no_arquivo(2);

    // Lógica para executar uma partida
    while (!jogo.verificarCondicaoVitoria()) {
        jogo.realizarJogada(*jogador_atual);
        jogo.imprimirTabuleiro();

        // Verificar se a partida terminou em empate
        if (jogo.verificarCondicaoEmpate()) {
            registrarEmpate(*jogador_atual, *outro_jogador);
            return;
        }

        // Troca de jogadores
        std::swap(jogador_atual, outro_jogador);
    }
    
    // Registro da vitória
    registrarVitoria(*jogador_atual);
}

void SistemaDeJogo::registrarVitoria(Jogador& vencedor) {
    vencedor.registrarVitoria();
    // Outra lógica associada ao registro da vitória
}

void SistemaDeJogo::registrarDerrota(Jogador& perdedor) {
    perdedor.registrarDerrota();
    // Outra lógica associada ao registro da derrota
}

void SistemaDeJogo::registrarEmpate(Jogador& jogador_1, Jogador& jogador_2) {
    jogador_1.registrarEmpate();
    jogador_2.registrarEmpate();
    // Outra lógica associada ao registro do empate
}

void SistemaDeJogo::listarJogadores() {
    cadastro.listarJogadores();
}

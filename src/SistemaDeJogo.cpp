#include "../include/SistemaDeJogo.hpp"
#include <iostream>
#include <stdexcept>  
#include <limits>

void printMenuJogos() {
    std::cout << "+-----------------+" << std::endl;
    std::cout << "| Escolha o jogo: |" << std::endl;
    std::cout << "| 1. Reversi      |" << std::endl;
    std::cout << "| 2. Lig4         |" << std::endl;
    std::cout << "| 0. Voltar       |" << std::endl;
    std::cout << "+-----------------+" << std::endl;
}

SistemaDeJogo::SistemaDeJogo() {
    try {
        cadastroDeJogadores.criarArquivoJogadores();
        cadastroDeJogadores.carregarJogadoresDeArquivo("jogadores.txt");
        jogador1 = nullptr;
        jogador2 = nullptr;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao inicializar o sistema de jogo: " << e.what() << std::endl;
        system("pause");
        return;
    }
}

void SistemaDeJogo::escolherJogo() {
    int escolha;

    do {
        try {
            printMenuJogos();
            if (!(std::cin >> escolha)) {
                throw std::invalid_argument("Entrada invalida. Por favor, digite um numero inteiro.");
            }

            if (escolha == 1) {
                jogo = std::make_unique<Reversi>(jogador1, jogador2);
            } 
            else if (escolha == 2) {
                jogo = std::make_unique<Lig4>(jogador1, jogador2);
            } 
            else if (escolha == 0) {
                std::cout << "Voltando ao menu principal..." << std::endl;
            } 
            else {
                std::cout << "Opcao invalida! Por favor, escolha novamente." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
            // Limpa o estado da entrada para evitar loops infinitos devido a erros de entrada
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (escolha != 1 && escolha != 2 && escolha != 0);
}

Jogador* verificarOuCadastrarJogador(const std::string& nome, CadastroDeJogadores& cadastro) {
    try {
        Jogador* jogador = cadastro.getJogadorPorNome(nome);
        if (jogador == nullptr) {
            char opcao;
            std::cout << "Jogador " << nome << " nao encontrado. Deseja cadastra-lo? (s/n): ";
            std::cin >> opcao;
            if (opcao == 's' || opcao == 'S') {
                cadastro.adicionarJogadorNoArquivo(nome);
                jogador = cadastro.getJogadorPorNome(nome);
            }
        }
        return jogador;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao verificar ou cadastrar jogador: " << e.what() << std::endl;
        return nullptr;  // Retorna nullptr para indicar que algo deu errado
    }
}

void SistemaDeJogo::executarPartida() {
    try {
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
                try {
                    Jogador* jogadorAtual = turnoJogador1 ? jogador1 : jogador2;
                    std::cout << "Vez de " << (turnoJogador1 ? nomeJogador1 : nomeJogador2) << ". ";
                    jogadorAtual->setPeca(turnoJogador1 ? 'W' : 'B');
                    jogo->realizarJogada(jogadorAtual, jogadorAtual->minhaPeca());

                    turnoJogador1 = !turnoJogador1;
                    condicaoVitoria = jogo->verificarCondicaoVitoria(jogadorAtual->minhaPeca());
                } catch (const std::exception& e) {
                    std::cerr << "Erro durante a jogada: " << e.what() << std::endl;
                    return;  // Encerra a partida se ocorrer um erro crítico
                }
            }

            std::cout << "Fim de jogo!" << std::endl;

            if (condicaoVitoria == -1) {
                std::cout << "O jogo terminou em empate!" << std::endl;
                jogador1->registrarEmpate();
                jogador2->registrarEmpate();
            }
            if (condicaoVitoria == 1) {
                if (turnoJogador1) {
                    std::cout << "O jogador " << nomeJogador2 << " venceu!" << std::endl;
                    jogador2->registrarVitoria();
                    jogador1->registrarDerrota();
                } else {
                    std::cout << "O jogador " << nomeJogador1 << " venceu!" << std::endl;
                    jogador1->registrarVitoria();
                    jogador2->registrarDerrota();
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao executar a partida: " << e.what() << std::endl;
    }
}

SistemaDeJogo::~SistemaDeJogo() {
    // Os recursos são automaticamente liberados por causa dos smart pointers
}

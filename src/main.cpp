#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "../include/Jogador.hpp"
#include "../include/CadastroDeJogadores.hpp"
#include "../include/SistemaDeJogo.hpp"
#include "../include/Tabuleiro.hpp"

void printMenu() {
    std::cout << "+------------------------+" << std::endl;
    std::cout << "| Menu - Opcoes:         |" << std::endl;
    std::cout << "| 1. Adicionar jogador   |" << std::endl;
    std::cout << "| 2. Listar jogadores    |" << std::endl;
    std::cout << "| 3. Buscar jogador      |" << std::endl;
    std::cout << "| 4. Remover jogador     |" << std::endl;
    std::cout << "| 5. Jogar               |" << std::endl;
    std::cout << "| 0. Encerrar o programa |" << std::endl;
    std::cout << "+------------------------+" << std::endl;
}

int main() {
    SistemaDeJogo sistema; // Cria uma instância de SistemaDeJogo
    CadastroDeJogadores cadastroDeJogadores; // Cria uma instância de CadastroDeJogadores
    Tabuleiro tabuleiro;
    
    while (true) {
        try {
            int escolha;
            std::string nome;

            while (true) {
                printMenu();
                std::cout << "Digite sua escolha: ";
                if (!(std::cin >> escolha)) {
                    throw std::invalid_argument("Entrada invalida. Por favor, digite um numero inteiro.");
                }

                if (escolha >= 1 && escolha <= 6) {
                    if (escolha == 1) {
                        std::cout << "Digite o nome do jogador: ";
                        std::cin >> nome;
                        cadastroDeJogadores.adicionarJogadorNoArquivo(nome);
                    }
                    if (escolha == 2) {
                        cadastroDeJogadores.listarJogadoresDoArquivo();
                    }
                    if (escolha == 3) {
                        cadastroDeJogadores.buscarJogadorNoArquivo();
                    }
                    if (escolha == 4) {
                        cadastroDeJogadores.removerJogadorDoArquivo("jogadores.txt");
                    }
                    if (escolha == 5) {
                        sistema.executarPartida();
                    }
                } else if (escolha < 0 || escolha > 6) {
                    std::cout << "Opcao invalida. Por favor, digite uma opcao entre 0 e 5." << std::endl;
                }

                if (escolha == 0) {
                    std::cout << "Obrigado por jogar!" << std::endl;
                    return 0;
                }
            }

        } catch (const std::invalid_argument& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
        } catch (const std::ios_base::failure& e) {
            std::cerr << "Erro ao acessar o arquivo: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erro inesperado: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Erro desconhecido ocorreu." << std::endl;
        }

        // Limpa o estado da entrada para evitar loops infinitos devido a erros de entrada
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "Reiniciando o jogo..." << std::endl;
    }

    return 0;
}

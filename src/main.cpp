#include <iostream>
#include <string>
#include "../include/Jogador.hpp"
#include "../include/CadastroDeJogadores.hpp"
#include "../include/SistemaDeJogo.hpp"
#include "../include/Tabuleiro.hpp"

int main() {
    SistemaDeJogo sistema; // Cria uma instância de SistemaDeJogo
    Jogador jogador; // Cria uma instância de Jogador
    CadastroDeJogadores cadastroDeJogadores; // Cria uma instância de CadastroDeJogadores
    Tabuleiro tabuleiro;

    std::cout << "Opcoes: " << std::endl;
    std::cout << "1. Adicionar jogador" << std::endl;
    std::cout << "2. Listar jogadores" << std::endl;
    std::cout << "3. Buscar jogador" << std::endl;
    std::cout << "4. Remover jogador" << std::endl;
    std::cout << "5. Jogar" << std::endl;
    std::cout << "0. Encerrar o programa" << std::endl;
    std::cout << std::endl;
    int escolha;
     
    std::string nome;

    while(true){

        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        if( escolha >= 1 && escolha <= 5) {
            if(escolha == 1) {
                std::cout << "Digite o nome do jogador: ";
                std::cin >> nome;
                cadastroDeJogadores.adicionarJogadorNoArquivo(nome);
            }

            if(escolha == 2) {
                cadastroDeJogadores.listarJogadoresDoArquivo();
            }

            if (escolha == 3) {
                cadastroDeJogadores.buscarJogadorNoArquivo();
            }

            if(escolha == 4) {
                cadastroDeJogadores.removerJogadorDoArquivo("jogadores.txt");
            }

            if(escolha == 5) {
                sistema.executarPartida();
            }
         }

        if(escolha < 0 || escolha > 5){
            std::cout << "Opcao inválida. Digite de novo" << std::endl;
        }

        if(escolha == 0){
            break;
        }
    }
    
    std::cout << "Obrigado por jogar!" << std::endl;
    return 0;
}
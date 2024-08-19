#include <iostream>
#include <string>
#include "../include/Jogador.hpp"
#include "../include/CadastroDeJogadores.hpp"
#include "../include/SistemaDeJogo.hpp"

int main() {
    SistemaDeJogo sistema; // Cria uma instância de SistemaDeJogo
    Jogador jogador; // Cria uma instância de Jogador
    CadastroDeJogadores cadastroDeJogadores; // Cria uma instância de CadastroDeJogadores

    std::cout << "Escolha o que fazer: " << std::endl;
    std::cout << "1. Adicionar jogador" << std::endl;
    std::cout << "2. Listar jogadores" << std::endl;
    std::cout << "3. Buscar jogador" << std::endl;
    std::cout << "4. Remover jogador" << std::endl;
    std::cout << "5. Jogar" << std::endl;

    int escolha;
    std::cin >> escolha;
    std::string nome;

    switch (escolha) {
        case 1:
            std::cout << "Digite o nome do jogador: ";
            std::cin >> nome;
            cadastroDeJogadores.adicionarJogadorNoArquivo(nome);
            break;
        case 2:
            cadastroDeJogadores.listarJogadoresDoArquivo();
            break;
        case 3:
            cadastroDeJogadores.buscarJogadorNoArquivo("jogadores.txt");
            break;
        case 4:
            cadastroDeJogadores.removerJogadorDoArquivo("jogadores.txt");
            break;
        case 5:
            sistema.executarPartida();
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }

    std::cout << "Obrigado por jogar!" << std::endl;
    return 0;
}
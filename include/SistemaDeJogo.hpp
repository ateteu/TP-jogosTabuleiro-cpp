#ifndef SISTEMA_DE_JOGO_HPP
#define SISTEMA_DE_JOGO_HPP

#include "CadastroDeJogadores.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp" //precisa criar a classe, ela não existe ainda

/**
 * @brief Classe que gerencia o sistema de jogo, incluindo cadastro de jogadores, 
 *        registro de partidas e atualização dos resultados dos jogadores.
 */
class SistemaDeJogo {
private:
    CadastroDeJogadores cadastro; ///< Objeto responsável pelo cadastro dos jogadores.
    Jogo jogo; ///< Objeto responsável pela lógica do jogo.
    Jogador jogador; ///< Objeto para manipulação de dados dos jogadores.

public:
    /**
     * @brief Construtor padrão da classe SistemaDeJogo.
     */
    SistemaDeJogo();

    /**
     * @brief Inicializa o sistema de jogo, preparando-o para a execução.
     */
    void inicializar();

    /**
     * @brief Executa uma partida de jogo entre os jogadores cadastrados.
     */
    void executarPartida();

    /**
     * @brief Registra a vitória de um jogador.
     * 
     * @param vencedor Referência para o jogador que venceu a partida.
     */
    void registrarVitoria(Jogador& vencedor);

    /**
     * @brief Registra a derrota de um jogador.
     * 
     * @param perdedor Referência para o jogador que perdeu a partida.
     */
    void registrarDerrota(Jogador& perdedor);

    /**
     * @brief Registra um empate entre dois jogadores.
     * 
     * @param jogador1 Referência para o primeiro jogador envolvido no empate.
     * @param jogador2 Referência para o segundo jogador envolvido no empate.
     */
    void registrarEmpate(Jogador& jogador1, Jogador& jogador2); 

    /**
     * @brief Lista todos os jogadores cadastrados no sistema.
     */
    void listarJogadores();
};

#endif

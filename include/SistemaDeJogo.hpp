#ifndef SISTEMADEJOGO_HPP
#define SISTEMADEJOGO_HPP

#include "Jogo.hpp"
#include "CadastroDeJogadores.hpp"
#include <memory>

/**
 * @class SistemaDeJogo
 * @brief Classe responsável pela gestão e execução das partidas.
 *
 * A classe SistemaDeJogo gerencia a interação entre o jogo e o cadastro de jogadores,
 * permitindo a escolha de jogadores e o controle do fluxo da partida.
 */
class SistemaDeJogo {
private:
    std::unique_ptr<Jogo> jogo; /**< Ponteiro único para o objeto Jogo. */
    CadastroDeJogadores cadastroDeJogadores; /**< Objeto para gerenciamento de jogadores. */
    
public:
    /**
     * @brief Construtor da classe SistemaDeJogo.
     *
     * Inicializa o sistema de jogo e carrega os jogadores.
     */
    SistemaDeJogo();

    /**
     * @brief Método para executar a partida.
     *
     * Permite ao usuário escolher os jogadores, inicializa o tabuleiro e controla o fluxo do jogo.
     */
    void executarPartida();

    /**
     * @brief Método para escolher o jogo.
     *
     * Permite ao usuário selecionar o tipo de jogo que deseja jogar.
     */
    void escolherJogo();
    
    /**
     * @brief Destrutor da classe SistemaDeJogo.
     *
     * Libera os recursos alocados.
     */
    ~SistemaDeJogo(); 
};

#endif // SISTEMADEJOGO_HPP
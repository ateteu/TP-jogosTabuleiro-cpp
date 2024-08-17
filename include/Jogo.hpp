#ifndef JOGO_HPP
#define JOGO_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

/**
 * @class Jogo
 * @brief Classe responsável pela gestão do jogo, incluindo o tabuleiro e os jogadores.
 *
 * A classe Jogo herda de Tabuleiro e Jogador e gerencia as operações principais
 * como inicializar o tabuleiro, validar jogadas, verificar condições de vitória, 
 * e realizar jogadas.
 */
class Jogo : public Tabuleiro, public Jogador {
private:
    Tabuleiro* tabuleiro; /**< Ponteiro para o tabuleiro do jogo. */
    Jogador* JogogadorAtual; /**< Ponteiro para o jogador atual. */

public:
    /**
     * @brief Construtor padrão da classe Jogo.
     *
     * Inicializa os ponteiros do tabuleiro e do jogador atual.
     */
    Jogo();

    /**
     * @brief Inicializa o tabuleiro do jogo.
     *
     * Método virtual que deve ser implementado para definir o estado inicial do tabuleiro.
     */
    virtual void inicializarTabuleiro();

    /**
     * @brief Valida a jogada de um jogador.
     * @param _linha Linha onde o jogador deseja jogar.
     * @param _coluna Coluna onde o jogador deseja jogar.
     *
     * Verifica se a jogada feita é válida com base nas regras do jogo.
     */
    void validarJogada(int _linha, int _coluna);

    /**
     * @brief Verifica a condição de vitória.
     *
     * Analisa o tabuleiro para determinar se algum jogador cumpriu as condições de vitória.
     */
    void verificarCondicaoVitoria();

    /**
     * @brief Imprime o estado atual do jogo.
     *
     * Sobrescreve o método de impressão para mostrar o tabuleiro e as jogadas.
     */
    void imprimir() override;

    /**
     * @brief Realiza a jogada de um jogador.
     *
     * Garante que o jogador atual execute sua jogada conforme as regras do jogo.
     */
    void realizarJogada();

    /**
     * @brief Destrutor da classe Jogo.
     *
     * Libera a memória alocada para o tabuleiro e o jogador atual.
     */
    ~Jogo();
};

#endif

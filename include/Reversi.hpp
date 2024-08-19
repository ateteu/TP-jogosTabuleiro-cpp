#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include "Tabuleiro.hpp"
#include "Jogador.hpp"

/**
 * @class Reversi
 * @brief Classe que representa o jogo Reversi, derivada de Jogo.
 * 
 * A classe Reversi contém a lógica específica para o jogo Reversi,
 * incluindo métodos para verificar a condição de vitória, realizar jogadas
 * e inicializar o tabuleiro. A classe interage com a classe Jogador para 
 * rastrear as peças de cada jogador e determinar o vencedor.
 */
class Reversi : public Jogo {
private:
    bool vezJogador1; ///< Indica se é a vez do jogador 1
    Jogador* jogador1; ///< Ponteiro para o primeiro jogador
    Jogador* jogador2; ///< Ponteiro para o segundo jogador
    Tabuleiro tabuleiro; ///< Objeto que representa o tabuleiro do jogo Reversi.

public:
    /** 
     * @brief Inicializa o tabuleiro do jogo Reversi, colocando as peças iniciais.
     */
    void inicializarTabuleiro() override;

    /**
     * @brief Construtor da classe Reversi.
     * 
     * @param _jogador1 Ponteiro para o primeiro jogador.
     * @param _jogador2 Ponteiro para o segundo jogador.
     */
    Reversi(Jogador* _jogador1, Jogador* _jogador2);

    /**
     * @brief Valida se uma jogada é possível de acordo com as regras do Reversi.
     * @param x Posição X no tabuleiro.
     * @param y Posição Y no tabuleiro.
     * @param jogador Ponteiro para o jogador que está fazendo a jogada.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool validarJogada(int x, int y, Jogador* jogador) override;

    /**
     * @brief Verifica a condição de vitória.
     * 
     * Analisa o tabuleiro para determinar se algum jogador cumpriu as condições de vitória.
     * @return 1 se um jogador venceu, -1 em caso de empate, 0 se o jogo continua.
     */
    virtual int verificarCondicaoVitoria();

    /** 
     * @brief Imprime o estado atual do tabuleiro no terminal.
     */
    void imprimirTabuleiro();

    /** 
     * @brief Realiza uma jogada no tabuleiro.
     */
    void realizarJogada() override;

    /**
     * @brief Captura as peças do oponente em todas as direções possíveis (horizontal, vertical e diagonal).
     * 
     * Este método é chamado após uma peça ser colocada no tabuleiro. Ele verifica em todas as direções
     * a partir da posição (x, y) se existem peças do oponente que podem ser capturadas, ou seja, se estão 
     * entre a peça recém-colocada e outra peça do jogador atual.
     * 
     * @param x A coordenada x da peça que foi colocada.
     * @param y A coordenada y da peça que foi colocada.
     * @param jogador Ponteiro para o jogador que realizou a jogada.
     */
    void capturarPecas(int x, int y, Jogador* jogador);

    /**
     * @brief Captura as peças do oponente em uma direção específica.
     * 
     * Este método verifica se há peças do oponente em uma sequência em uma direção definida pelos 
     * deltas (deltaX, deltaY). Se a sequência termina com uma peça do jogador atual, todas as peças
     * do oponente nessa sequência são capturadas.
     * 
     * @param x A coordenada x inicial.
     * @param y A coordenada y inicial.
     * @param jogador O jogador que realizou a jogada.
     * @param deltaX O incremento para a coordenada x na direção.
     * @param deltaY O incremento para a coordenada y na direção.
     */
    void capturarDirecao(int x, int y, Jogador* jogador, int deltaX, int deltaY);
};

#endif // REVERSI_HPP

#ifndef JOGO_HPP
#define JOGO_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

/**
 * @class Jogo
 * @brief Classe responsável pela gestão do jogo, incluindo o tabuleiro e os jogadores.
 *
 * A classe Jogo gerencia as operações principais como inicializar o tabuleiro,
 * validar jogadas, verificar condições de vitória e realizar jogadas.
 */
class Jogo {
private:
    Tabuleiro* tabuleiro = new Tabuleiro(); /**< Ponteiro para o tabuleiro do jogo. */
    Jogador* jogadorAtual; /**< Ponteiro para o jogador atual. */

public:
    /**
     * @brief Construtor padrão da classe Jogo.
     *
     * Inicializa o ponteiro do tabuleiro e o ponteiro do jogador atual.
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
     * @param jogador Objeto que representa o jogador que está realizando a jogada.
     * @return true se a jogada for válida, false caso contrário.
     *
     * Verifica se a jogada feita é válida com base nas regras do jogo.
     */
    virtual bool validarJogada(int _linha, int _coluna, Jogador* jogador) = 0;

    /**
     * @brief Verifica a condição de vitória.
     *
     * Analisa o tabuleiro para determinar se algum jogador cumpriu as condições de vitória.
     * @return true se algum jogador venceu, false caso contrário.
     */
    virtual int verificarCondicaoVitoria();
    
    /**
     * @brief Imprime o estado atual do jogo.
     *
     * Usa o método imprimir() da classe Tabuleiro para mostrar o tabuleiro e as jogadas.
     */
    void imprimirTabuleiro();

    /**
     * @brief Realiza a jogada de um jogador.
     *
     * Garante que o jogador atual execute sua jogada conforme as regras do jogo.
     */
    virtual void realizarJogada();

    Jogador* getJogadorAtual(){}

    /**
     * @brief Destrutor da classe Jogo.
     *
     * Libera a memória alocada para o tabuleiro e o jogador atual.
     */
    ~Jogo();
};

#endif

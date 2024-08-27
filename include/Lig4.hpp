#ifndef LIG4_HPP
#define LIG4_HPP

#include "Jogo.hpp"
#include "Tabuleiro.hpp"

/**
 * @class Lig4
 * @brief Classe que representa o jogo Lig4, derivada da classe base Jogo.
 *
 * A classe Lig4 implementa as regras específicas para o jogo Lig4, incluindo
 * a inicialização do tabuleiro, validação das jogadas, verificação das 
 * condições de vitória e a realização das jogadas.
 */
class Lig4 : public Jogo {
public:
    /**
     * @brief Construtor da classe Lig4.
     *
     * Inicializa o tabuleiro com as dimensões específicas de Lig4 e define
     * as peças dos jogadores.
     */
    Lig4();

    /**
     * @brief Inicializa o tabuleiro do jogo Lig4.
     *
     * Sobrescreve o método da classe base para definir o estado inicial
     * do tabuleiro de Lig4.
     */
    void inicializarTabuleiro() override;

    /**
     * @brief Valida a jogada de um jogador no jogo Lig4.
     * @param linha Linha onde o jogador deseja jogar.
     * @param coluna Coluna onde o jogador deseja jogar.
     * @param jogador Objeto que representa o jogador que está realizando a jogada.
     * @return true se a jogada for válida, false caso contrário.
     *
     * Verifica se a jogada feita é válida com base nas regras do Lig4.
     */
    bool validarJogada(int linha, int coluna, Jogador* jogador, char peca) override; 

    /**
     * @brief Verifica a condição de vitória no jogo Lig4.
     *
     * Analisa o tabuleiro de Lig4 para determinar o estado atual do jogo.
     * 
     * @return int Retorna `1` se algum jogador venceu, `-1` em caso de empate, ou `0` se o jogo deve continuar.
     */
    int verificarCondicaoVitoria() override;

    /**
     * @brief Realiza a jogada de um jogador em uma coluna no jogo Lig4.
     * 
     * Sobrescreve o método da classe base para realizar uma jogada
     * em uma coluna específica do tabuleiro.
     */
    void realizarJogada(Jogador* jogador, char peca) override;

private:
    static const int largura = 7;  /**< Largura do tabuleiro para Lig4. */
    static const int altura = 6;   /**< Altura do tabuleiro para Lig4. */
    Tabuleiro* tabuleiro = new Tabuleiro(); /**< Ponteiro para o tabuleiro do jogo Lig4. */
    char jogador1Peca = 'X'; /**< Peça do jogador 1. */
    char jogador2Peca = 'O'; /**< Peça do jogador 2. */
};

#endif // LIG4_HPP
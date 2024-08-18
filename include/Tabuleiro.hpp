#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include "Jogador.hpp"

/**
 * @class Tabuleiro
 * @brief Classe que representa o tabuleiro de um jogo.
 *
 * A classe Tabuleiro gerencia a estrutura do tabuleiro, incluindo o número de linhas e colunas,
 * e fornece métodos para inicializar e definir posições no tabuleiro. Ela também possui um
 * método virtual puro para imprimir o estado atual do tabuleiro.
 */
class Tabuleiro {

private:
    int linhas;  /**< Número de linhas do tabuleiro. */
    int colunas; /**< Número de colunas do tabuleiro. */
    char **matrizTabuleiro;

public:
    /**
     * @brief Construtor padrão da classe Tabuleiro.
     *
     * Inicializa o tabuleiro com dimensões padrão.
     */
    Tabuleiro();

    /**
     * @brief Inicializa o tabuleiro com o número de linhas e colunas especificadas.
     * @param linha Número de linhas do tabuleiro.
     * @param col Número de colunas do tabuleiro.
     *
     * Configura o tabuleiro para ter as dimensões especificadas.
     */
    void inicializar(int linha, int col);

    /**
     * @brief Define uma posição específica no tabuleiro.
     *
     * Implementa a lógica necessária para configurar uma posição no tabuleiro.
     */
    void definirPosicao(int _x, int _y, char _peca);

    char obterPeca(int _x, int _y);

    bool posicaoValida(int _x, int _y);


    /**
     * @brief Imprime o estado atual do tabuleiro.
     *
     * Este é um método virtual puro que deve ser implementado pelas classes derivadas.
     */
    virtual void imprimir() = 0;

    /**
     * @brief Destrutor da classe Tabuleiro.
     *
     * Libera qualquer recurso alocado pela classe Tabuleiro.
     */
    ~Tabuleiro();
};

#endif

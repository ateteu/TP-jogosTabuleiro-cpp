#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include "Jogador.hpp"

/**
 * @class Tabuleiro
 * @brief Classe que representa o tabuleiro de um jogo.
 *
 * A classe Tabuleiro gerencia a estrutura do tabuleiro, incluindo o número de linhas e colunas,
 * e fornece métodos para inicializar e definir posições no tabuleiro. Ela também possui um
 * método para imprimir o estado atual do tabuleiro.
 */
class Tabuleiro {

private:
    int linhas;  /**< Número de linhas do tabuleiro. */
    int colunas; /**< Número de colunas do tabuleiro. */
    char **matrizTabuleiro; /**< Matriz que representa o estado do tabuleiro. */

public:
    /**
     * @brief Construtor padrão da classe Tabuleiro.
     *
     * Inicializa o tabuleiro com dimensões padrão.
     */
    Tabuleiro();

    /**
     * @brief Configura o tamanho do tabuleiro com o número de linhas e colunas especificadas.
     * @param linha Número de linhas do tabuleiro.
     * @param col Número de colunas do tabuleiro.
     *
     * Configura o tabuleiro para ter as dimensões especificadas.
     */
    void configurarTabuleiro(int linha, int col);

    // que diabos isso faz?
    void definirPosicao(int _x, int _y, char _peca);

    /**
     * @brief Obtém o conteúdo da célula na posição especificada do tabuleiro.
     * @param _x Coordenada x da posição no tabuleiro.
     * @param _y Coordenada y da posição no tabuleiro.
     * @return Caracter que representa o conteúdo da célula na posição especificada.
     */
    char obterPeca(int _x, int _y);

    /**
     * @brief Verifica se a posição especificada está dentro dos limites do tabuleiro.
     * @param _x Coordenada x da posição no tabuleiro.
     * @param _y Coordenada y da posição no tabuleiro.
     * @return Verdadeiro se a posição estiver dentro dos limites, falso caso contrário.
     */
    bool posicaoValida(int _x, int _y);

    /**
     * @brief Imprime o estado atual do tabuleiro.
     *
     * Imprime o tabuleiro no estado atual.
     */
    void imprimir();

    /**
     * @brief Destrutor da classe Tabuleiro.
     *
     * Libera qualquer recurso alocado pela classe Tabuleiro.
     */
    ~Tabuleiro();
};

#endif

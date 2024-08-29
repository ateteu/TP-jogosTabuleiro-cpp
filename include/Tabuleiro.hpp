#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <memory> // Inclui para usar smart pointers

class Tabuleiro {
private:
    /**
     * @brief Número de linhas do tabuleiro.
     */
    int linhas;

    /**
     * @brief Número de colunas do tabuleiro.
     */
    int colunas;

    /**
     * @brief Matriz que representa o tabuleiro de jogo.
     * 
     * A matriz é gerenciada por smart pointers para garantir a liberação de memória.
     */
    std::unique_ptr<std::unique_ptr<char[]>[]> matrizTabuleiro;

public:
    /**
     * @brief Construtor padrão da classe Tabuleiro.
     * 
     * Inicializa um objeto Tabuleiro com configurações padrão.
     */
    Tabuleiro();

    /**
     * @brief Configura o tabuleiro com um número específico de linhas e colunas.
     * 
     * @param _linhas Número de linhas.
     * @param _colunas Número de colunas.
     */
    void configurarTabuleiro(int _linhas, int _colunas);

    /**
     * @brief Define uma peça em uma posição específica do tabuleiro.
     * 
     * @param _x Coordenada x da posição.
     * @param _y Coordenada y da posição.
     * @param _peca A peça a ser colocada na posição (_x, _y).
     */
    void definirPosicao(int _x, int _y, char _peca);

    /**
     * @brief Retorna a peça na posição específica do tabuleiro.
     * 
     * @param _x Coordenada x da posição.
     * @param _y Coordenada y da posição.
     * @return A peça na posição (_x, _y).
     */
    char obterPeca(int _x, int _y) const;

    /**
     * @brief Verifica se a posição especificada é válida dentro do tabuleiro.
     * 
     * @param _x Coordenada x da posição.
     * @param _y Coordenada y da posição.
     * @return true se a posição é válida, false caso contrário.
     */
    bool posicaoValida(int _x, int _y) const;

    /**
     * @brief Imprime o tabuleiro no console.
     */
    void imprimir() const;

    /**
     * @brief Destrutor da classe Tabuleiro.
     * 
     * Libera os recursos alocados para a matriz do tabuleiro.
     */
    ~Tabuleiro();
};

#endif // TABULEIRO_HPP
#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include "Tabuleiro.hpp"
#include "Jogador.hpp"

/** 
 * @brief Classe que implementa o jogo Reversi, derivada da classe base Jogo.
 */
class Reversi : public Jogo {
private:
    Tabuleiro tabuleiro;  // Declaração do tabuleiro como membro da classe Reversi

public:
    /** 
     * @brief Inicializa o tabuleiro do jogo Reversi, colocando as peças iniciais.
     */
    void inicializarTabuleiro() override;

    /** 
     * @brief Valida se uma jogada é possível de acordo com as regras do Reversi.
     * @param x Posição X no tabuleiro.
     * @param y Posição Y no tabuleiro.
     * @param jogador Referência ao jogador que está fazendo a jogada.
     * @return true se a jogada for válida, false caso contrário.
     */
    bool validarJogada(int x, int y, Jogador jogador) override;

    /** 
     * @brief Verifica se a condição de vitória foi atingida.
     * @return true se houver um vencedor, false caso contrário.
     */
    bool verificarCondicaoVitoria() override;

    /** 
     * @brief Imprime o estado atual do tabuleiro no terminal.
     */
    void imprimirTabuleiro() override;

    /** 
     * @brief Realiza uma jogada no tabuleiro.
     * @param x Posição X no tabuleiro.
     * @param y Posição Y no tabuleiro.
     * @param jogador Referência ao jogador que está fazendo a jogada.
     */
    void realizarJogada(int x, int y, Jogador jogador) override;
};

#endif // REVERSI_HPP

#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <memory> // Inclui para usar smart pointers

class Tabuleiro {
private:
    int linhas;
    int colunas;
    std::unique_ptr<std::unique_ptr<char[]>[]> matrizTabuleiro;

public:
    Tabuleiro();

    void configurarTabuleiro(int _linhas, int _colunas);
    void definirPosicao(int _x, int _y, char _peca);
    char obterPeca(int _x, int _y) const;
    bool posicaoValida(int _x, int _y) const;
    void imprimir() const;

    ~Tabuleiro();
};

#endif // TABULEIRO_HPP

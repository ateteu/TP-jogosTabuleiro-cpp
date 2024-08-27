class Tabuleiro {
private:
    int linhas;
    int colunas;
    char** matrizTabuleiro;

public:
    // Construtor
    Tabuleiro() : linhas(0), colunas(0), matrizTabuleiro(nullptr) {}

    // Destrutor
    ~Tabuleiro() {
        liberarMemoria();
    }

    void configurarTabuleiro(int _linhas, int _colunas) {
        // Libera a memória da matrizTabuleiro, se já alocada
        liberarMemoria();

        // Atualiza as dimensões
        linhas = _linhas;
        colunas = _colunas;

        // Aloca matriz para o tabuleiro
        matrizTabuleiro = new char*[linhas];
        for (int i = 0; i < linhas; i++) {
            matrizTabuleiro[i] = new char[colunas];
            for (int j = 0; j < colunas; j++) {
                matrizTabuleiro[i][j] = '.'; // inicializa as posições com ponto
            }
        }
    }

private:
    void liberarMemoria() {
        if (matrizTabuleiro) {
            for (int i = 0; i < linhas; i++) {
                delete[] matrizTabuleiro[i];
            }
            delete[] matrizTabuleiro;
            matrizTabuleiro = nullptr;
        }
    }
};

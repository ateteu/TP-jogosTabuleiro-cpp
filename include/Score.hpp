//
// Created by Ian Godoi on 28/08/24.
//

#ifndef TP_JOGOSTABULEIRO_CPP_SCORE_HPP
#define TP_JOGOSTABULEIRO_CPP_SCORE_HPP

#include <string>
#include <unordered_map>
#include <fstream>

#include <string>
#include <unordered_map>
#include <fstream>

class Score {
public:
    Score();
    void adicionarVitorias(const std::string& jogador, const std::string& jogo, int quantidade);
    void adicionarDerrotas(const std::string& jogador, const std::string& jogo, int quantidade);
    void adicionarEmpates(const std::string& jogador, const std::string& jogo, int quantidade);
    void imprimirEstatisticasPorNome(const std::string& nome) const;

    int obterVitorias(const std::string& jogador, const std::string& jogo) const;
    int obterDerrotas(const std::string& jogador, const std::string& jogo) const;
    int obterEmpates(const std::string& jogador, const std::string& jogo) const;

    void imprimirEstatisticas(const std::string& jogador) const;
    void imprimirEstatisticasPorJogo(const std::string& jogador) const;
    void salvar() const;
    void limparScore( const std::string& nomeJogador);
    void carregar();

private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> estatisticas;
    std::string arquivo = "score.txt";

    void atualizarArquivo();
};

#endif //TP_JOGOSTABULEIRO_CPP_SCORE_HPP


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


    void imprimirEstatisticasPorNomeEJogo(const std::string& jogador, const std::string& jogo) ;

    void limparScore( const std::string& nomeJogador);
    void carregar();

private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> estatisticas;
    std::string arquivo = "score.txt";

    void atualizarArquivo();
};

#endif //TP_JOGOSTABULEIRO_CPP_SCORE_HPP


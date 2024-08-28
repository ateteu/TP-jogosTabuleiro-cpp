#include "../include/Score.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iomanip>

// Construtor que carrega estatísticas do arquivo score.txt

Score::Score() {
    // Verifica se o arquivo existe
    std::ifstream fileStream(arquivo);  
    if (!fileStream) {
        // O arquivo não existe, cria um novo arquivo
        std::ofstream novoArquivo(arquivo);
        if (!novoArquivo) {
            std::cerr << "Erro ao criar o arquivo " << arquivo << std::endl;
            // Trate o erro conforme necessário
        }
        // Fecha o arquivo que foi criado
        novoArquivo.close();
    } else {
        // Carrega as estatísticas do arquivo
        carregar();
    }
}


// Adiciona vitórias ao jogador para um jogo específico
void Score::adicionarVitorias(const std::string& jogador, const std::string& jogo, int quantidade) {
    estatisticas[jogador][jogo + " vitorias"] += quantidade;
    atualizarArquivo();
}

// Adiciona derrotas ao jogador para um jogo específico
void Score::adicionarDerrotas(const std::string& jogador, const std::string& jogo, int quantidade) {
    estatisticas[jogador][jogo + " derrotas"] += quantidade;
    atualizarArquivo();
}

// Adiciona empates ao jogador para um jogo específico
void Score::adicionarEmpates(const std::string& jogador, const std::string& jogo, int quantidade) {
    estatisticas[jogador][jogo + " empates"] += quantidade;
    atualizarArquivo();
}


void Score::imprimirEstatisticasPorNomeEJogo(const std::string& jogador, const std::string& jogo) {
    // Verifica se as estatísticas já foram carregadas
    if (estatisticas.empty()) {
        carregar(); // Carrega as estatísticas do arquivo se ainda não foram carregadas
    }
    std::cout <<"------SCORE------"<<std::endl;
    // Verifica se o jogador está nas estatísticas carregadas
    auto it = estatisticas.find(jogador);
    if (it != estatisticas.end()) {
        // Obtém as estatísticas do jogador
        const auto& estatisticasJogador = it->second;

        // Imprime o nome do jogador
        std::cout << jogador << ":\n";

        // Construa as chaves para vitórias, derrotas e empates
        std::string jogoVitorias = jogo + " vitorias";
        std::string jogoDerrotas = jogo + " derrotas";
        std::string jogoEmpates = jogo + " empates";


        // Verifica e imprime vitórias, removendo o nome do jogo na impressão
        auto vit = estatisticasJogador.find(jogoVitorias);
        if (vit != estatisticasJogador.end()) {
            std::cout << "Vitórias: " << vit->second << "\n";
        }

        // Verifica e imprime derrotas, removendo o nome do jogo na impressão
        auto der = estatisticasJogador.find(jogoDerrotas);
        if (der != estatisticasJogador.end()) {
            std::cout << "Derrotas: " << der->second << "\n";
        }

        // Verifica e imprime empates, removendo o nome do jogo na impressão
        auto emp = estatisticasJogador.find(jogoEmpates);
        if (emp != estatisticasJogador.end()) {
            std::cout << "Empates: " << emp->second << "\n";
        }

    } else {
        std::cout << "Nenhuma estatística encontrada para o jogador " << jogador << ".\n";
    }
}




// Carrega as estatísticas do arquivo
void Score::carregar() {
    std::ifstream arquivoStream(arquivo);

    if (arquivoStream.is_open()) {
        std::string linha;
        std::string jogador;
        std::unordered_map<std::string, int> estatisticasJogador;

        // Limpa as estatísticas carregadas previamente
        estatisticas.clear();

        while (std::getline(arquivoStream, linha)) {
            // Remove espaços em branco na frente e atrás
            linha.erase(0, linha.find_first_not_of(" \t\r\n"));
            linha.erase(linha.find_last_not_of(" \t\r\n") + 1);

            if (linha.empty()) continue;

            if (linha.back() == ':') {
                // Linha com o nome do jogador
                // Se houver estatísticas acumuladas do jogador anterior, salva
                if (!estatisticasJogador.empty()) {
                    estatisticas[jogador] = estatisticasJogador;
                }
                // Atualiza o jogador atual
                jogador = linha.substr(0, linha.size() - 1);
                // Inicializa ou limpa o mapa de estatísticas do jogador atual
                estatisticasJogador = std::unordered_map<std::string, int>();
            } else {
                // Linha com estatísticas
                std::string jogo = linha.substr(0, linha.find(':'));
                std::string quantidadeStr = linha.substr(linha.find(':') + 1);
                quantidadeStr.erase(quantidadeStr.find_last_not_of(" \n\r\t") + 1);
                try {
                    int quantidade = std::stoi(quantidadeStr);
                    estatisticasJogador[jogo] = quantidade;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Erro: Quantidade inválida na linha: " << linha << std::endl;
                }
            }
        }

        // Salva as estatísticas do último jogador
        if (!estatisticasJogador.empty()) {
            estatisticas[jogador] = estatisticasJogador;
        }

        arquivoStream.close();
        std::cout << "Estatísticas carregadas do arquivo: " << arquivo << "." << std::endl;
    } else {
        std::cerr << "Não foi possível abrir o arquivo " << arquivo << "." << std::endl;
    }
}


void Score::imprimirEstatisticasPorNome(const std::string& nome) const {
    // Verifica se as estatísticas estão carregadas
    if (estatisticas.empty()) {
        std::cerr << "Estatísticas não carregadas. Carregando agora..." << std::endl;
        const_cast<Score*>(this)->carregar();
    }

    auto it = estatisticas.find(nome);
    if (it != estatisticas.end()) {
        std::cout << nome << ":\n";
        for (const auto& [jogo, quantidade] : it->second) {
            std::cout << jogo << ": " << quantidade << "\n";
        }
    } else {
        std::cout << "Nenhuma estatística encontrada para o jogador " << nome << ".\n";
    }
}

void Score::atualizarArquivo() {
    std::ofstream out(arquivo);
    if (!out) {
        std::cerr << "Erro ao abrir o arquivo " << arquivo << " para escrita." << std::endl;
        return;
    }

    for (const auto& [jogador, jogos] : estatisticas) {
        out << jogador << ":\n";
        for (const auto& [jogo, quantidade] : jogos) {
            out << jogo << ": " << quantidade << "\n";
        }
        out << "\n";
    }
}

void Score::limparScore(const std::string& nomeJogador) {
    // Procura pelo jogador no mapa de estatísticas
    auto it = estatisticas.find(nomeJogador);

    if (it != estatisticas.end()) {
        // Se o jogador for encontrado, remove suas estatísticas
        estatisticas.erase(it);
        std::cout << "Score do jogador " << nomeJogador << " foi limpo." << std::endl;
    } else {
        std::cout << "Jogador " << nomeJogador << " não encontrado no score." << std::endl;
    }

    atualizarArquivo();
}

void Score::imprimirListadeScore() {
    std::cout <<"------SCORE------"<<std::endl;
    // Verifica se as estatísticas já foram carregadas
    if (estatisticas.empty()) {
        carregar(); // Carrega as estatísticas do arquivo se ainda não foram carregadas
    }

    // Percorre todos os jogadores no mapa de estatísticas
    for (const auto& jogadorEntry : estatisticas) {
        // Imprime o nome do jogador
        std::cout << jogadorEntry.first << ":\n";

        // Percorre todas as estatísticas associadas a este jogador
        for (const auto& statEntry : jogadorEntry.second) {
            // Imprime o tipo de estatística (vitorias, derrotas, empates) e o valor
            std::cout << statEntry.first << ": " << statEntry.second << "\n";
        }

        // Linha em branco para separar cada jogador
        std::cout << "\n";
    }
    std::cout <<"----------------"<<std::endl;
}

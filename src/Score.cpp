#include "../include/Score.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iomanip>
#include <vector>

// Construtor que carrega estatísticas do arquivo score.txt
Score::Score() : arquivo("score.txt") {  // Assume-se que "arquivo" é um membro da classe que armazena o nome do arquivo
    // Verifica se o arquivo existe
    std::ifstream fileStream(arquivo);
    if (!fileStream) {
        // O arquivo não existe, cria um novo arquivo
        std::ofstream novoArquivo(arquivo);
        if (!novoArquivo) {
            std::cerr << "Erro ao criar o arquivo " << arquivo << std::endl;
        }
        novoArquivo.close();
    } else {
        // Carregar as estatísticas do arquivo
        carregar();
    }
}

void Score::inicializarEstatisticas(const std::string& jogador) {
    // Verifica se o jogador já possui estatísticas
    if (estatisticas.find(jogador) == estatisticas.end()) {
        estatisticas[jogador] = {
                {"Lig4 vitorias", 0},
                {"Lig4 derrotas", 0},
                {"Lig4 empates", 0},
                {"Reverse vitorias", 0},
                {"Reverse derrotas", 0},
                {"Reverse empates", 0}
        };
    }
}

void Score::adicionarVitorias(const std::string& jogador, const std::string& jogo, int quantidade) {
    inicializarEstatisticas(jogador);
    estatisticas[jogador][jogo + " vitorias"] += quantidade;
    atualizarArquivo();
}

void Score::adicionarDerrotas(const std::string& jogador, const std::string& jogo, int quantidade) {
    inicializarEstatisticas(jogador);
    estatisticas[jogador][jogo + " derrotas"] += quantidade;
    atualizarArquivo();
}

void Score::adicionarEmpates(const std::string& jogador, const std::string& jogo, int quantidade) {
    inicializarEstatisticas(jogador);
    estatisticas[jogador][jogo + " empates"] += quantidade;
    atualizarArquivo();
}

void Score::imprimirEstatisticasPorNomeEJogo(const std::string& jogador, const std::string& jogo) {
    if (estatisticas.empty()) {
        carregar();
    }
    std::cout << "------SCORE------" << std::endl;
    // Verifica se o jogador está nas estatísticas carregadas
    auto it = estatisticas.find(jogador);
    if (it != estatisticas.end()) {
        // Obtém as estatísticas do jogador
        const std::unordered_map<std::string, int>& estatisticasJogador = it->second;

        // Imprime o nome do jogador
        std::cout << jogador << ":\n";

        // Construa as chaves para vitórias, derrotas e empates
        std::string jogoVitorias = jogo + " vitorias";
        std::string jogoDerrotas = jogo + " derrotas";
        std::string jogoEmpates = jogo + " empates";

        // Verifica e imprime vitórias
        auto vit = estatisticasJogador.find(jogoVitorias);
        if (vit != estatisticasJogador.end()) {
            std::cout << "Vitórias: " << vit->second << "\n";
        }

        // Verifica e imprime derrotas
        auto der = estatisticasJogador.find(jogoDerrotas);
        if (der != estatisticasJogador.end()) {
            std::cout << "Derrotas: " << der->second << "\n";
        }

        // Verifica e imprime empates
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
        for (const auto& item : it->second) {
            std::cout << item.first << ": " << item.second << "\n";
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

    for (const auto& item : estatisticas) {
        const std::string& jogador = item.first;
        const std::unordered_map<std::string, int>& jogos = item.second;
        out << jogador << ":\n";
        // Ordena as chaves para garantir a ordem desejada
        std::vector<std::string> chaves = {
                "Lig4 vitorias", "Lig4 derrotas", "Lig4 empates",
                "Reverse vitorias", "Reverse derrotas", "Reverse empates"
        };
        for (const auto& chave : chaves) {
            auto it = jogos.find(chave);
            if (it != jogos.end()) {
                out << chave << ": " << it->second << "\n";
            }
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
    std::cout << "------SCORE------" << std::endl;

    // Verifica se as estatísticas já foram carregadas
    if (estatisticas.empty()) {
        carregar(); // Carrega as estatísticas do arquivo se ainda não foram carregadas
    }

    // Lista de chaves na ordem desejada
    std::vector<std::string> ordemDesejada = {
            "Lig4 vitorias", "Lig4 derrotas", "Lig4 empates",
            "Reverse vitorias", "Reverse derrotas", "Reverse empates"
    };

    // Itera sobre os jogadores e imprime suas estatísticas
    for (const auto& item : estatisticas) {
        const std::string& jogador = item.first;
        const auto& estatisticasJogador = item.second;

        std::cout << jogador << ":\n";
        for (const auto& chave : ordemDesejada) {
            auto it = estatisticasJogador.find(chave);
            if (it != estatisticasJogador.end()) {
                std::cout << chave << ": " << it->second << "\n";
            }
        }
        std::cout << std::endl;
    }
}

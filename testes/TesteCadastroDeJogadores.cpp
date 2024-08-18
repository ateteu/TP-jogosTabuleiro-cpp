#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/CadastroDeJogadores.cpp"

// Teste para o método criarArquivoJogadores
TEST_CASE("Testar a criação do arquivo de jogadores") {
    CadastroDeJogadores cadastro;
    cadastro.criarArquivoJogadores();

    std::ifstream arquivo("jogadores.txt");
    CHECK(arquivo.is_open()); // Verifica se o arquivo foi criado com sucesso
    arquivo.close();
}

// Teste para o método adicionarJogadorNoArquivo
TEST_CASE("Testar a adição de um jogador ao arquivo") {
    CadastroDeJogadores cadastro;
    cadastro.limparArquivo(); // Limpa o arquivo antes de adicionar jogadores

    Jogador jogador1("Jogador1");
    cadastro.adicionarJogadorNoArquivo(jogador1);

    CHECK(cadastro.buscarJogadorNoArquivo("Jogador1")); // Verifica se o jogador foi adicionado corretamente
}

// Teste para o método carregarJogadoresDeArquivo
TEST_CASE("Testar o carregamento dos jogadores do arquivo") {
    CadastroDeJogadores cadastro;
    cadastro.limparArquivo();

    Jogador jogador1("Jogador1");
    Jogador jogador2("Jogador2");
    cadastro.adicionarJogadorNoArquivo(jogador1);
    cadastro.adicionarJogadorNoArquivo(jogador2);

    cadastro.carregarJogadoresDeArquivo("jogadores.txt");

    CHECK(cadastro.buscarJogadorNoArquivo("Jogador1")); // Verifica se o jogador1 foi carregado corretamente
    CHECK(cadastro.buscarJogadorNoArquivo("Jogador2")); // Verifica se o jogador2 foi carregado corretamente
}

// Teste para o método removerJogadorDoArquivo
TEST_CASE("Testar a remoção de um jogador do arquivo") {
    CadastroDeJogadores cadastro;
    cadastro.limparArquivo();

    Jogador jogador1("Jogador1");
    cadastro.adicionarJogadorNoArquivo(jogador1);

    cadastro.removerJogadorDoArquivo("Jogador1");
    CHECK_FALSE(cadastro.buscarJogadorNoArquivo("Jogador1")); // Verifica se o jogador foi removido corretamente
}

// Teste para o método atualizarNomeDoJogador
TEST_CASE("Testar a atualização do nome de um jogador") {
    CadastroDeJogadores cadastro;
    cadastro.limparArquivo();

    Jogador jogador1("Jogador1");
    cadastro.adicionarJogadorNoArquivo(jogador1);

    cadastro.atualizarNomeDoJogador("Jogador1", "JogadorAtualizado");

    CHECK(cadastro.buscarJogadorNoArquivo("JogadorAtualizado")); // Verifica se o nome foi atualizado corretamente
    CHECK_FALSE(cadastro.buscarJogadorNoArquivo("Jogador1")); // Verifica se o nome antigo não existe mais
}

// Teste para o método listarJogadoresDoArquivo
TEST_CASE("Testar a listagem dos jogadores do arquivo") {
    CadastroDeJogadores cadastro;
    cadastro.limparArquivo();

    Jogador jogador1("Jogador1");
    Jogador jogador2("Jogador2");
    cadastro.adicionarJogadorNoArquivo(jogador1);
    cadastro.adicionarJogadorNoArquivo(jogador2);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    
    cadastro.listarJogadoresDoArquivo();

    std::cout.rdbuf(old);

    std::string output = buffer.str();
    CHECK(output.find("Jogador1") != std::string::npos); // Verifica se o jogador1 está na listagem
    CHECK(output.find("Jogador2") != std::string::npos); // Verifica se o jogador2 está na listagem
}

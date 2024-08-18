#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/Jogador.cpp"

TEST_CASE("Testando a classe Jogador") {

    SUBCASE("Construtor padrão") {
        Jogador jogador;
        CHECK(jogador.getNome() == "");
        CHECK(jogador.getVitorias() == 0);
        CHECK(jogador.getEmpates() == 0);
        CHECK(jogador.getDerrotas() == 0);
    }

    SUBCASE("Construtor com nome") {
        Jogador jogador("Carlos");
        CHECK(jogador.getNome() == "Carlos");
        CHECK(jogador.getVitorias() == 0);
        CHECK(jogador.getEmpates() == 0);
        CHECK(jogador.getDerrotas() == 0);
    }

    SUBCASE("Registrar vitórias, empates e derrotas") {
        Jogador jogador("Carlos");
        jogador.registrarVitoria();
        jogador.registrarEmpate();
        jogador.registrarDerrota();

        CHECK(jogador.getVitorias() == 1);
        CHECK(jogador.getEmpates() == 1);
        CHECK(jogador.getDerrotas() == 1);

        jogador.registrarVitoria();
        CHECK(jogador.getVitorias() == 2);
    }

    SUBCASE("Alterar o nome do jogador") {
        Jogador jogador("Carlos");
        CHECK(jogador.getNome() == "Carlos");

        jogador.setNome("Roberto");
        CHECK(jogador.getNome() == "Roberto");
    }

    SUBCASE("Imprimir informações do jogador") {
        Jogador jogador("Carlos");
        jogador.registrarVitoria();
        jogador.registrarEmpate();
        jogador.registrarDerrota();

        jogador.imprimirJogador();
        // Verificar manualmente a saída do console para garantir que as informações são impressas corretamente.
    }
}

#ifndef SISTEMA_DE_JOGO_HPP
#define SISTEMA_DE_JOGO_HPP

#include "CadastroDeJogadores.hpp"
#include "../include/Jogador.hpp"
#include "../include/Jogo.hpp" //precisa criar a classe, ela não existe ainda

class SistemaDeJogo {
private:
    CadastroDeJogadores cadastro;
    Jogo jogo;
    Jogador jogador;

public:
    SistemaDeJogo();

    void inicializar();
    void executarPartida();
    void registrarVitoria(Jogador& vencedor);
    void registrarDerrota(Jogador& perdedor);
    void registrarEmpate(Jogador& jogador1, Jogador& jogador2); 
    void listarJogadores();
};

#endif

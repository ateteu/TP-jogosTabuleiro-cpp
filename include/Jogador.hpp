//
//  Jogador.hpp
//  tp
//
//  Created by Ian Godoi on 06/08/24.
//

#ifndef Jogador_hpp
#define Jogador_hpp

#include <iostream>
#include <string>

class Jogador{
private:
    std::string nome_jogador;
    int ponto;
    int id;
    
public:
    Jogador();
    Jogador( const std::string& nome_jogador= "", int ponto = 0);
    ~Jogador();
 
    std::string get_nome() const;
    void set_nome(const std:: string& nome);
    
    int get_pontos() const;
    void set_pontos(int pontos);
    
    void imprimir_jogador() const;
};

#endif // Jogador_hpp

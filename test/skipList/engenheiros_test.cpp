#include "../catch.hpp"
#include <cstdlib>
#include <chrono>
#include <memory>
#include <vector>
#include <iostream>

enum Pessoa{
    ADVOGADO = 0,
    ENGENHEIRO
};

Pessoa resposta(Pessoa a, Pessoa b){
    if(a == ENGENHEIRO){
        //retorna verdade
        if(b == ENGENHEIRO){
            return Pessoa::ENGENHEIRO;
        }else{
            return Pessoa::ADVOGADO;
        }
    }else{
        //retorna mentira ou verdade
        int val = std::rand() % 2;
        if(val == 1){
            //verdade
            if(b == ENGENHEIRO){
                return Pessoa::ENGENHEIRO;
            }else{
                return Pessoa::ADVOGADO;
            }
        }else {
            //mentira
            if(b == ENGENHEIRO){
                return Pessoa::ADVOGADO;
            }else{
                return Pessoa::ENGENHEIRO;
            }
        }
    }
}

TEST_CASE("Running engenheirtos","[eng]"){
    std::srand(std::time(0)); //initialize random

//    std::vector<Pessoa> pessoas = {
//        ADVOGADO,
//        ADVOGADO,
//        ENGENHEIRO,
//        ENGENHEIRO,
//        ENGENHEIRO
//    };

//    std::vector<Pessoa> pessoas = {
//        ADVOGADO,
//        ENGENHEIRO,
//        ENGENHEIRO,
//        ADVOGADO,
//        ENGENHEIRO,
//    };

    std::vector<Pessoa> pessoas = {
        ENGENHEIRO,
        ENGENHEIRO,
        ADVOGADO,
        ADVOGADO,
        ENGENHEIRO,
        ADVOGADO,
        ENGENHEIRO,
    };

    int numeroDePergunstasRealizadas = 0;
    int i = 0;
    int j = 1;
    int contadorDeEngenheiro = 0;
    int engenheiroIndex = 0;
    while (i <= pessoas.size()) {
        if(j > pessoas.size() -1){
            engenheiroIndex = i;
            break;
        }

        Pessoa resp = resposta(pessoas[i], pessoas[j]);
        numeroDePergunstasRealizadas++;
        if(resp == Pessoa::ENGENHEIRO){
            if(contadorDeEngenheiro == 0){
                engenheiroIndex = j;
                contadorDeEngenheiro = 2;
                i = j+1; //agora vamos perguntar o que os próximos k,1.. dizem da classe j
            }else {
                contadorDeEngenheiro ++;
                i++;
            }
        }else {
            if(contadorDeEngenheiro > 0){
                contadorDeEngenheiro --;
                i++;
            }else {
                i = i+2; //se a resposta foi A, ignora i e j e passa os indices adiante
            }
        }

        if(contadorDeEngenheiro == 0){
            j = i+1;
        }

        if(contadorDeEngenheiro > pessoas.size() - i){
            break;
        }
    }
    std::cout << "Número De Pessoas no teste = " <<  pessoas.size() << std::endl;
    std::cout << "Número De Pergunstas Realizadas = " << numeroDePergunstasRealizadas << std::endl;
    REQUIRE(numeroDePergunstasRealizadas <= pessoas.size() -1);
    std::cout << "index engenheiro = " << engenheiroIndex << std::endl;
    REQUIRE(pessoas[engenheiroIndex] == Pessoa::ENGENHEIRO); //garante que a pessoa apontada pelo index é um engenheiro
}

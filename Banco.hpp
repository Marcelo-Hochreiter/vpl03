#ifndef BANCO_HPP
#define BANCO_HPP

#include "ContaBancaria.hpp"

struct Banco
{
    ContaBancaria* vetorContas_[20];
    int numContas_ = 0;

    Banco ();

    ContaBancaria* CriaConta(int id, std::string nome);

    ContaBancaria* Pesquisa(int id);

    void ListaContas();

    ~Banco();
};

#endif
#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include <string>

struct ContaBancaria
{
    int id_ = 0;
    std::string cliente_ = "";
    float saldo_ = 0.0;


    ContaBancaria(int id, std::string cliente);

    void Deposito(float saldoDep);

    void Saque(float saldoSaque);

    void Pix(ContaBancaria* destinoPix, float valorPix);

    void Imprime();    
};

#endif
#include "ContaBancaria.hpp"
#include <iostream>
#include <iomanip>

ContaBancaria :: ContaBancaria(int id, std::string cliente)
{
    id_ = id;
    cliente_ = cliente;
    saldo_ = 0.0;
}

void ContaBancaria :: Deposito(float saldoDep)
{
    if (saldoDep > 0)
    {
        saldo_ = saldo_ + saldoDep;
    }
    
}

void ContaBancaria :: Saque(float saldoSaque)
{
    if(saldoSaque <= saldo_){
        saldo_ = saldo_ - saldoSaque;
    }
}

void ContaBancaria :: Pix(ContaBancaria* destinoPix, float valorPix)
{
    if (valorPix <= saldo_ && destinoPix != nullptr)
    {
        destinoPix->saldo_ = destinoPix->saldo_ + valorPix;
        this->saldo_ = this->saldo_ - valorPix;
    }
    
}

void ContaBancaria::Imprime()
{
    std::cout << id_ << " " << cliente_ << " " << std::fixed << std::setprecision(2) << saldo_ << std::endl;
}


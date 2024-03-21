#include "Banco.hpp"
#include <iostream>
#include <iomanip>

Banco :: Banco()
{
    numContas_ = 0;
    for (unsigned int i = 0; i < 20; i++)
    {
        vetorContas_[i] = nullptr;
    }
    
}

ContaBancaria* Banco::CriaConta(int id, std::string nome)
{      
    ContaBancaria* contaAux = this->Pesquisa(id);
    if (contaAux == nullptr)
    {   
        ContaBancaria* novaConta = new ContaBancaria(id,nome);
        vetorContas_[numContas_] = novaConta;
        numContas_++;
        return vetorContas_[numContas_-1];
    }
    return nullptr;

    
    
}

ContaBancaria* Banco::Pesquisa(int id)
{
    for (int i = 0; i < numContas_; i++)
    {
        if (id == vetorContas_[i]->id_)
        {
            return vetorContas_[i];
        }
        
    }
    
    return nullptr;
}

void Banco::ListaContas()
{
    for (int i = 0; i < numContas_; i++)
    {
        vetorContas_[i]->Imprime();
    }
    
}

Banco :: ~Banco()
{
        
    for (int i = 0; i < numContas_; i++) {
        if (vetorContas_[i] != nullptr) {
            delete vetorContas_[i];
            vetorContas_[i] = nullptr; // Marca o ponteiro como nullptr após liberar a memória
        }
    }


}
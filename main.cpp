#include "ContaBancaria.hpp"
#include "Banco.hpp"

#include <iostream>

int main()
{
    char option ;
    int id = 0;
    std::string nome = "";
    float valor = 0.0;
    Banco* banco_ = new Banco;
    int idDest = 0;
    
   while (std::cin >> option)
    {
        if (option == 'C')
        {
            std::cin >> id >> nome;
            ContaBancaria* novaConta = nullptr;
            novaConta = banco_->CriaConta(id,nome);

            if (novaConta == nullptr)
            {
                std::cout << "ERRO: conta repetida" << std::endl;
            }
            if (novaConta != nullptr)
            {
                std::cout << "conta criada" << std::endl;
            }
            

        }

        if (option == 'D')
        {
            std::cin >> id >> valor;
            ContaBancaria* ContaDeposito = banco_->Pesquisa(id);

            if (ContaDeposito == nullptr)
            {
                std::cout << "ERRO: conta inexistente" << std::endl;
            }
            if (ContaDeposito != nullptr)
            {
                ContaDeposito->Deposito(valor);
                std::cout << "deposito efetuado" << std::endl;
            }
            

        }

        if (option == 'S')
        {
            std::cin >> id >> valor;
            ContaBancaria* ContaSaque = banco_->Pesquisa(id);

            if (ContaSaque == nullptr)
            {
                std::cout << "ERRO: conta inexistente" << std::endl;
            }
            if (ContaSaque != nullptr)
            {
                ContaSaque->Saque(valor);
                std::cout << "saque efetuado" << std::endl;
            }
            
        }

        if (option == 'P')
        {
            std::cin >> id >> idDest >> valor;
            ContaBancaria* cRemetente = banco_->Pesquisa(id);
            ContaBancaria* cDestinatario = banco_->Pesquisa(idDest);

            if (cRemetente == nullptr || cDestinatario == nullptr)
            {
                std::cout << "ERRO: conta inexistente" << std::endl;
            }
            if (cRemetente != nullptr && cDestinatario != nullptr)
            {
                cRemetente->Pix(cDestinatario, valor);
                std::cout << "pix efetuado" << std::endl;
            }
            
            
        }

        if (option == 'I')
        {
            banco_->ListaContas();
        }
        
        if (option == 'T')
        {
            banco_->~Banco();
            delete banco_;
            return 0;
        }
        
        
        
        
    }

  
    
}
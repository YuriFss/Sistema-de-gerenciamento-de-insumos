#include "Local.h"

Local::Local()
{
    nomeLocal = "";
}

//SETS
void Local::setInsumo(Insumo *insu)
{
    insumos.push_back(insu);
}

void Local::setNome(string nome)
{
    nomeLocal = nome;
}

//GETS
vector<Insumo *> Local::getInsumo()
{
    return insumos;
}

string Local::getNome()
{
    return nomeLocal;
}

void Local::excluirInsumo(Insumo *insumo)
{
    for (int i = 0; i < insumos.size(); i++)
    {
        if (insumos[i]->getNomeProduto() == insumo->getNomeProduto())
        {
            delete insumos[i];
            insumos.erase(insumos.begin() + i);
            return;
        }
    }
}
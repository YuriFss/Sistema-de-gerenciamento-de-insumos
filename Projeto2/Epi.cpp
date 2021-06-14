#include "Epi.h"

Epi::Epi() {}

//CONSTRUTOR QUE INICIA O TIPO
Epi::Epi(int tipo) : Insumo(tipo)
{
    descricaoEpi = "";
    tipoEpi = "";
}

//RETORNA A DESCRICAO
string Epi::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Descricao: " + descricaoEpi + "\nTipo: " + tipoEpi + "\n\n";

    return descricao;
}

//LE OS ATRIBTOS DA ENTTRADA PADRAO
void Epi::lerAtributos()
{
    Insumo::lerAtributos();

    cout << "\nDigite o tipo do Epi: ";
    getline(cin.ignore(), tipoEpi);

    cout << "\nDigite a descricao do Epi: ";
    getline(cin, descricaoEpi);
}

//LE E SALVA NO ARQUIVO
void Epi::lerInsumos(ifstream &fp)
{
    Insumo::lerInsumos(fp);

    getline(fp.ignore(), descricaoEpi);
    getline(fp, tipoEpi);
}
void Epi::salvarInsumos(ofstream &fp)
{
    Insumo::salvarInsumos(fp);

    fp << descricaoEpi << endl
       << tipoEpi << endl
       << endl;
}

//SETS
void Epi::setDescricaoepi(string descricaoEpi)
{
    this->descricaoEpi = descricaoEpi;
}

void Epi::setTipoEpi(string tipoEpi)
{
    this->tipoEpi = tipoEpi;
}

//GETS
string Epi::getDescricaoepi()
{
    return descricaoEpi;
}

string Epi::getTipoEpi()
{
    return tipoEpi;
}
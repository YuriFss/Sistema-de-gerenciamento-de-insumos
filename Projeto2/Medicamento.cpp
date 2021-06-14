#include "Medicamento.h"

Medicamento::Medicamento() {}

//CONSTRUTOR QUE INICIA O TIPO
Medicamento::Medicamento(int tipo) : Insumo(tipo)
{
    dosagem = "";
    administracao = "";
    disponibilizacao = "";
}

//RETORNA A DESCRICAO
string Medicamento::getDescricao()
{
    string descricao = Insumo::getDescricao() + "Dosagem: " + dosagem + "\nAdministracao: " + administracao +
                       "\nDisponibilizacao: " + disponibilizacao + "\n\n";

    return descricao;
}

//LE OS ATRIBUTOS DA ENTRADA PADRAO
void Medicamento::lerAtributos()
{
    Insumo::lerAtributos();

    cout << "\nDigite a dosagem do medicamento: ";
    getline(cin.ignore(), dosagem);

    cout << "\nDigite a forma de administracao: ";
    getline(cin, administracao);

    cout << "\nDigite a forma de disponibilizacao: ";
    getline(cin, disponibilizacao);
}

//LE E SALVA NO ARQUIVO
void Medicamento::lerInsumos(ifstream &fp)
{
    Insumo::lerInsumos(fp);

    getline(fp.ignore(), dosagem);
    getline(fp, administracao);
    getline(fp, disponibilizacao);
}
void Medicamento::salvarInsumos(ofstream &fp)
{
    Insumo::salvarInsumos(fp);

    fp << dosagem << endl
       << administracao << endl
       << disponibilizacao << endl
       << endl;
}

//SETS
void Medicamento::setDosagem(string dosagem)
{
    this->dosagem = dosagem;
}
void Medicamento::setAdministracao(string administracao)
{
    this->administracao = administracao;
}
void Medicamento::setDisponibilizacao(string disponibilizacao)
{
    this->disponibilizacao = disponibilizacao;
}

//GETS
string Medicamento::getDosagem()
{
    return dosagem;
}
string Medicamento::getAdministracao()
{
    return administracao;
}
string Medicamento::getDisponibilizacao()
{
    return disponibilizacao;
}
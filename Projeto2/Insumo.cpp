#include "Insumo.h"
#include <sstream>

Insumo::Insumo() {}

//CONSTRUTOR QUE INICIA O TIPO
Insumo::Insumo(int tipo)
{
    nomeProduto = "";
    dataVencimento = "";
    nomeFabricante = "";
    quantidadeItens = 0;
    valorUnitario = 0.0;
    tipoInsumo = tipo;
}

//RETORNA A DESCRICAO
string Insumo::getDescricao()
{

    stringstream sstream;

    sstream << valorUnitario;

    string valor = sstream.str();

    string descricao = "Nome: " + nomeProduto + "\nData de vencimento: " + dataVencimento + "\nNome do fabricante: " + nomeFabricante +
                       "\nQuantidade de itens: " + to_string(quantidadeItens) + "\nValor unitario: R$" + valor + "\nTipo do insumo: " +
                       to_string(tipoInsumo) + "\n";

    return descricao;
}

//RETORNA NOME E QUANTIDADE
string Insumo::getConsulta()
{
    string consulta = "Nome: " + nomeProduto + "\nQuantidade de itens: " + to_string(quantidadeItens) + "\n\n";

    return consulta;
}

//GETS
string Insumo::getNomeProduto()
{
    return nomeProduto;
}

string Insumo::getDataVencimento()
{
    return dataVencimento;
}
string Insumo::getNomeFabricante()
{
    return nomeFabricante;
}
float Insumo::getValorUnitario()
{
    return valorUnitario;
}

int Insumo::getQuantidadeItens()
{
    return quantidadeItens;
}

int Insumo::getTipo()
{
    return tipoInsumo;
}

//SETS
void Insumo::setNomeProduto(string nome)
{
    nomeProduto = nome;
}
void Insumo::setDataVencimento(string data)
{
    dataVencimento = data;
}
void Insumo::setNomeFabricante(string nomeF)
{
    nomeFabricante = nomeF;
}
void Insumo::setValorUnitario(float valor)
{
    valorUnitario = valor;
}

void Insumo::setQuantidadeItens(int quantidade)
{
    quantidadeItens = quantidade;
}

//ADICIONA QUANTIDADE
void Insumo::addQuantidadeItens(int quantidade)
{
    quantidadeItens += quantidade;
}

//LE OS ATRIBUTOS DA ENTRADA PADRAO
void Insumo::lerAtributos()
{
    cout << "Digite o nome: ";
    getline(cin, nomeProduto);

    cout << "\nDigite o nome do fabricante: ";
    getline(cin, nomeFabricante);

    cout << "\nDigite a data de vencimento: ";
    getline(cin, dataVencimento);

    cout << "\nDigite a quantidade de itens: ";
    cin >> quantidadeItens;

    cout << "\nDigite o valor unitario: ";
    cin >> valorUnitario;
}

//LE E SALVA NO ARQUIVO
void Insumo::salvarInsumos(ofstream &fp)
{
    fp << tipoInsumo << endl
       << nomeProduto
       << endl
       << nomeFabricante << endl
       << dataVencimento << endl
       << quantidadeItens
       << endl
       << valorUnitario << endl;
}
void Insumo::lerInsumos(ifstream &fp)
{
    getline(fp, nomeProduto);
    getline(fp, nomeFabricante);
    fp >> dataVencimento >> quantidadeItens >> valorUnitario;
}
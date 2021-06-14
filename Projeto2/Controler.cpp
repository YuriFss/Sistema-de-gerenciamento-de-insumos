#include "Controler.h"
#include "Menu.h"

//CONSTRUTOR QUE INICIA OS NOME DOS LOCAIS EM ORDEM ALFABETICA
Controler::Controler()
{
    locais[0].setNome("MDS");
    locais[1].setNome("AC");
    locais[2].setNome("AL");
    locais[3].setNome("AP");
    locais[4].setNome("AM");
    locais[5].setNome("BA");
    locais[6].setNome("CE");
    locais[7].setNome("DF");
    locais[8].setNome("ES");
    locais[9].setNome("GO");
    locais[10].setNome("MA");
    locais[11].setNome("MT");
    locais[12].setNome("MS");
    locais[13].setNome("MG");
    locais[14].setNome("PA");
    locais[15].setNome("PB");
    locais[16].setNome("PR");
    locais[17].setNome("PE");
    locais[18].setNome("PI");
    locais[19].setNome("RJ");
    locais[20].setNome("RN");
    locais[21].setNome("RS");
    locais[22].setNome("RO");
    locais[23].setNome("RR");
    locais[24].setNome("SC");
    locais[25].setNome("SP");
    locais[26].setNome("SE");
    locais[27].setNome("TO");
}

//RETORNA LOCAL
Local &Controler::getLocal(int index)
{
    return locais[index];
}

//CADASTRA OS INSUMOS NO LOCAL DO INDICE [INDEX]
void Controler::cadastraInsumos(Insumo *insu, int index)
{
    if (retornaInsumos(locais[index]).size() > 0)
    {
        for (int i = 0; i < retornaInsumos(locais[index]).size(); i++)
        {
            if (insu->getNomeProduto() == retornaInsumos(locais[index])[i]->getNomeProduto())
            {
                cout << "\n***Insumo ja encontrado***\n"
                     << "Adicionando quantidade...\n";

                retornaInsumos(locais[index])[i]->addQuantidadeItens(insu->getQuantidadeItens());

                return;
            }
        }
    }

    locais[index].setInsumo(insu);
}

//CONSULTA OS INSUMOS DO LOCAL PASSADOS
void Controler::consultaInsumos(Local loc)
{
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        cout << retornaInsumos(loc)[i]->getConsulta();
    }
}

//CONSULTA A DESCRICAO DOS INSUMOS DOS LOCAIS PASSADOS
void Controler::consultaInsumosDescricao(Local loc)
{
    cout << retornaInsumos(loc).size() << endl;
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        cout << retornaInsumos(loc)[i]->getDescricao();
    }
}

//CONSULTA OS INSUMOS POR TIPO DOS LOCAIS PASSADOS
void Controler::consultaInsumosTipo(Local loc, int tipo)
{
    for (int i = 0; i < retornaInsumos(loc).size(); i++)
    {
        if (retornaInsumos(loc)[i]->getTipo() == tipo)
        {
            cout << retornaInsumos(loc)[i]->getDescricao();
        }
    }
}

//RETORNA A LISTA DE INSUMOS DO LOCAL PASSADO
vector<Insumo *> Controler::retornaInsumos(Local loc)
{
    return loc.getInsumo();
}

//DISTRIBUI INSUMOS DO MINISTERIO DA SAUDE PARA O LOCAL DO INDEX [INDEX]
void Controler::distribuiInsumos(int index, string nome)
{
    Insumo *insumo;
    Menu menu;
    int quant, estoque;
    bool flag = false;

    for (int i = 0; i < retornaInsumos(locais[0]).size(); i++)
    {
        if (retornaInsumos(locais[0])[i]->getNomeProduto() == nome)
        {
            flag = true;
            cout << "\n***Achou INSUMO***\n\n"
                 << "\nDigite a quantidade a ser distribuida: ";
            cin >> quant;

            estoque = retornaInsumos(locais[0])[i]->getQuantidadeItens();

            if (estoque < quant)
            {
                cout << "\n***Quantidade indisponivel***\n";
            }
            else
            {

                insumo = retornaInsumos(locais[0])[i];
                insumo->setQuantidadeItens(quant);

                cout << "\nDistribuindo...\n";

                cadastraInsumos(menu.criacaoInsumoES(insumo), index);

                retornaInsumos(locais[0])[i]->setQuantidadeItens(estoque - quant);

                if (retornaInsumos(locais[0])[i]->getQuantidadeItens() == 0)
                    deletaInsumo(locais[0], retornaInsumos(locais[0])[i]);

                return;
            }
        }
    }

    if (!flag)
    {
        cout << "\n***Insumo nao encontrado***\n";
        return;
    }
}

//DELETA OS INSUMOS
void Controler::deletaInsumo(Local &loc, Insumo *insumo)
{
    loc.excluirInsumo(insumo);
}
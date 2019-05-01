#include <iostream>
#include <stdlib.h>

using namespace std;

struct GR{
    int ArmacaoLateral=0;
    int ArmacaoFundo=0;
    int Teto=0;
    int Piso=01;
    int Portas=0;
    int Parafusos=0;
    int Puxadores=0;
    int Espelho=0;
    int Gavetas=0;
    int Cabideiros=0;
    float pArmacaoLateral=0;
    float pArmacaoFundo=0;
    float pTeto=0;
    float pPiso=0;
    float pPortas=0;
    float pParafusos=0;
    float pPuxadores=0;
    float pEspelho=0;
    float pGavetas=0;
    float pCabideiros=0;
};
int FuncaoQuantidade(GR &a, int resultado){
    if((a.ArmacaoLateral>=2)&&(a.ArmacaoFundo>=1)&&(a.Teto>=1)&&(a.Piso>=1)&&(a.Portas>=4)&&(a.Parafusos>=32)&&(a.Puxadores>=6)&&(a.Espelho>=1)&&(a.Gavetas>=2)&&(a.Cabideiros>=2)){
        a.ArmacaoLateral = a.ArmacaoLateral - 2;
        a.ArmacaoFundo = a.ArmacaoFundo - 1;
        a.Teto = a.Teto - 1;
        a.Piso = a.Piso -1;
        a.Portas = a.Portas - 4;
        a.Parafusos = a.Parafusos - 32;
        a.Puxadores = a.Puxadores - 6;
        a.Espelho = a.Espelho - 1;
        a.Gavetas = a.Gavetas - 2;
        a.Cabideiros = a.Cabideiros - 2;
        resultado = FuncaoQuantidade(a, resultado) +1;
    }
    return resultado;
}

float FuncaoCusto(GR a){
    return a.pArmacaoLateral+a.pArmacaoFundo+a.pCabideiros+a.pEspelho+a.pGavetas+a.pParafusos+a.pPiso+a.pPortas+a.pPuxadores+a.pTeto;
}

void FuncaoAlerta(GR a){
    if(a.ArmacaoLateral != 0)
        cout << "Sobraram " << a.ArmacaoLateral << " pecas de armacao lateral\n";
    if(a.ArmacaoFundo != 0)
        cout << "Sobraram " << a.ArmacaoFundo << " pecas de armacao de fundo\n";
    if(a.Cabideiros != 0)
        cout << "Sobraram " << a.Cabideiros << " cabideiros(s)\n";
    if(a.Espelho != 0)
        cout << "Sobraram " << a.Espelho << " espelho(s)\n";
    if(a.Gavetas != 0)
        cout << "Sobraram " << a.Gavetas << " gavetas(s)\n";
    if(a.Parafusos != 0)
        cout << "Sobraram " << a.Parafusos << " pafuso(s)\n";
    if(a.Piso != 0)
        cout << "Sobraram " << a.Piso << " piso(s)\n";
    if(a.Portas != 0)
        cout << "Sobraram " << a.Portas << " porta(s)\n";
    if(a.Puxadores != 0)
        cout << "Sobraram " << a.Puxadores << " puxadores\n";
    if(a.Teto != 0)
        cout << "Sobraram " << a.Teto << " teto(s)\n";
}

int main()
{
    int opcao;
    GR GuardaRoupa;
    GR aux;
    int NumSemana = 0;
    do{
        system("cls");
        cout << "Escolha uma opcao\n\n";
        cout << "1) Cadastrar as informacoes dos insumos utilizados\n2) Inserir o valor de cada insumo\n3) Cadastrar o numero de unidades que deverao ser fabricados em uma semana\n4) Sair";
        cout << "\n";
        cin >> opcao;
        switch(opcao){
        case 1:
            cout << "Digite a quantidade de armacao lateral\n";
            cin >> GuardaRoupa.ArmacaoLateral;
            cout << "\n";
            cout << "Digite a quantidade de armacao de fundo\n";
            cin >> GuardaRoupa.ArmacaoFundo;
            cout << "\n";
            cout << "Digite a quantidade de teto\n";
            cin >> GuardaRoupa.Teto;
            cout << "\n";
            cout << "Digite a quantidade de piso\n";
            cin >> GuardaRoupa.Piso;
            cout << "\n";
            cout << "Digite a quantidade de portas\n";
            cin >> GuardaRoupa.Portas;
            cout << "\n";
            cout << "Digite a quantidade de parafusos\n";
            cin >> GuardaRoupa.Parafusos;
            cout << "\n";
            cout << "Digite a quantidade de puxadores\n";
            cin >> GuardaRoupa.Puxadores;
            cout << "\n";
            cout << "Digite a quantidade de espelho\n";
            cin >> GuardaRoupa.Espelho;
            cout << "\n";
            cout << "Digite a quantidade de gavetas\n";
            cin >> GuardaRoupa.Gavetas;
            cout << "\n";
            cout << "Digite a quantidade de cabideiros\n";
            cin >> GuardaRoupa.Cabideiros;
            cout << "\n";
            break;
        case 2:
            cout << "Digite o preco do armacao lateral\n";
            cin >> GuardaRoupa.pArmacaoLateral;
            cout << "\n";
            cout << "Digite o preco do armacao de fundo\n";
            cin >> GuardaRoupa.pArmacaoFundo;
            cout << "\n";
            cout << "Digite o preco do teto\n";
            cin >> GuardaRoupa.pTeto;
            cout << "\n";
            cout << "Digite o preco do piso\n";
            cin >> GuardaRoupa.pPiso;
            cout << "\n";
            cout << "Digite o preco do portas\n";
            cin >> GuardaRoupa.pPortas;
            cout << "\n";
            cout << "Digite o preco do parafusos\n";
            cin >> GuardaRoupa.pParafusos;
            cout << "\n";
            cout << "Digite o preco do puxadores\n";
            cin >> GuardaRoupa.pPuxadores;
            cout << "\n";
            cout << "Digite o preco do espelho\n";
            cin >> GuardaRoupa.pEspelho;
            cout << "\n";
            cout << "Digite o preco do gavetas\n";
            cin >> GuardaRoupa.pGavetas;
            cout << "\n";
            cout << "Digite o preco do cabideiros\n";
            cin >> GuardaRoupa.pCabideiros;
            cout << "\n";
            break;
        case 3:
            cout << "Digite o numero que deverao ser fabricados em uma semana\n";
            cin >> NumSemana;
            cout << "\n";
            break;
        default :
            break;
        }
    }while(opcao != 4);
     aux = GuardaRoupa;
    float custoUnidade = FuncaoCusto(aux);
    int resultado = FuncaoQuantidade(aux, 0);
    cout << "Poderam ser feitos : " << resultado << " guarda-roupas\n\n";
    cout << "Custo de uma unidade : " << custoUnidade << "\n\n";
    cout << "Custo de todas unidades para a semana : " << custoUnidade*NumSemana << " \n\n\n";
    FuncaoAlerta(aux);
    if(resultado == NumSemana && NumSemana != 0){
        cout << "Insumos suficientes para a semana\n\n";
    }
    else if(resultado < NumSemana && NumSemana != 0){
        cout << "Insumos insuficientes\n\n";
    }

    return 0;
}

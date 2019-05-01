#include <iostream>
#include <stdio.h>

using namespace std;

void PreencherMatriz(float Matriz[][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> Matriz[i][j];
        }
    }
}

int main()
{
    float MatrizCanomica[2][2];
    float MatrizBase[2][2];
    float MatrizMudancaDeBase[2][2];
    float DeterminanteGeral;
    float Determinante1;
    float Determinante2;
    float Determinante3;
    float Determinante4;
    int opcao;
    cout << "1) Preencher matriz canonica primeiro\n2) Preencher matriz base primeiro\n";
    cin >> opcao;
    switch(opcao){
    case 1:
        cout << "Digite valores para matriz canonica\n";
        PreencherMatriz(MatrizCanomica);
        cout << "Digite valores para matriz base\n";
        PreencherMatriz(MatrizBase);
        break;
    case 2:
        cout << "Digite valores para matriz base\n";
        PreencherMatriz(MatrizBase);
        cout << "Digite valores para matriz canonica\n";
        PreencherMatriz(MatrizCanomica);
        break;
    default :
        cout << "Opcao invalida";
        return 0;
        break;
    }
    //achando o determinante geral...
    DeterminanteGeral = (MatrizBase[0][0]*MatrizBase[1][1])-(MatrizBase[1][0]*MatrizBase[0][1]);

    //achando o D1...
    Determinante1 = (MatrizCanomica[0][0]*MatrizBase[1][1])-(MatrizBase[0][1]*MatrizCanomica[1][0]);

    //achando o D2...
    Determinante2 = (MatrizBase[0][0]*MatrizCanomica[1][0])-(MatrizCanomica[0][0]*MatrizBase[1][0]);

    //achando o D3...
    Determinante3 = (MatrizCanomica[0][1]*MatrizBase[1][1])-(MatrizBase[0][1]*MatrizCanomica[1][1]);

    //achando o D4...
    Determinante4 = (MatrizBase[0][0]*MatrizCanomica[1][1])-(MatrizBase[0][1]*MatrizCanomica[1][0]);

    //calculando a matriz mudança de base...
    MatrizMudancaDeBase[0][0] = Determinante1/DeterminanteGeral;
    MatrizMudancaDeBase[0][1] = Determinante3/DeterminanteGeral;
    MatrizMudancaDeBase[1][0] = Determinante2/DeterminanteGeral;
    MatrizMudancaDeBase[1][1] = Determinante4/DeterminanteGeral;

    //imprimindo a matriz mudança de base...
    cout << "matriz mudanca de base:\n";
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%.2f  ",MatrizMudancaDeBase[i][j]);
        }
        cout << "\n";
    }

    return 0;
}

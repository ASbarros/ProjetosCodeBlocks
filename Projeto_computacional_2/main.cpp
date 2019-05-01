#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

double Funcao_cofator(double aux[][3]){

    double cof = (aux[0][0]*aux[1][1]*aux[2][2] + aux[0][1] * aux[1][2] * aux[2][0] + aux[0][2] * aux[1][0] * aux[2][1]) - (aux[0][2] * aux[1][1] * aux[2][0] + aux[1][2] * aux[2][1] * aux[0][0] + aux[2][2] * aux[0][1] * aux [1][0]);

    return cof;
}

double Preencher_cofator(int i,int j,double matriz_usuario[][4]){
    double aux[3][3];
    int a = 0, b = 0;

    for(int l=0;l<4;l++){
        for(int c=0;c<4;c++){
            if(l != i){
                if(c != j){
                    aux[a][b] = matriz_usuario[l][c];

                    if(b == 2){
                        b = 0;
                        if(a != 2)
                            a++;
                    }
                    else
                        b++;
                }
            }
        }
    }
    return Funcao_cofator(aux);
}

int main()
{
    double elemento = 0;
    double Determinante = 0;
    double matriz_inversa[4][4];

    double Matriz_usuario[4][4];
    for(int i =0;i<4;i++){//iniciando a matriz com zero para evitar possiveis erros
        for(int j=0;j<4;j++){
            Matriz_usuario[i][j]=0;
        }
    }

    double Matriz_delta[4][4];
    for(int i =0;i<4;i++){//iniciando a matriz com zero para evitar possiveis erros
        for(int j=0;j<4;j++){
            Matriz_delta[i][j]=0;
        }
    }

    double Matriz_cofator[4][4];
    for(int i =0;i<4;i++){//iniciando a matriz com zero para evitar possiveis erros
        for(int j=0;j<4;j++){
            Matriz_cofator[i][j]=0;
        }
    }

    double Matriz_adj[4][4];

    cout << "\tBEM VINDO AO SISTAMA!!\n\n\n\n\n" << endl;
    system("pause");
    system("cls");

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << "\nDigite o valor da linha " << i+1 << " e coluna " << j+1 << " :";
            cin >> elemento;
            Matriz_usuario[i][j] = elemento;
        }
    }

    //calculando a matriz cofator...
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Matriz_cofator[i][j] = Preencher_cofator(i,j,Matriz_usuario);
        }
    }


   //calculando a matriz adjacente...
   //a matriz adjacente ela é a transposta da matriz dos cofatores
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Matriz_adj[i][j] = Matriz_cofator[j][i];
        }
    }
    //calculando o delta...
    double
     x = -1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if( (i+j) %2 == 1)
            Matriz_delta[i][j] = x * Matriz_cofator[i][j];
            else
                Matriz_delta[i][j] = Matriz_cofator[i][j];
        }
    }

    //calculando o determinante...
    //fixando a segundo coluna...
    for(int i=0;i<4;i++){
        Determinante += Matriz_usuario[i][1]*Matriz_delta[i][1];
    }
    if(Determinante == 0){//se o determinante for igual a zero , então não existe matriz inversa,e o programa acaba...
        cout << "\nnao existe matriz inversa!!";
        return 0;
    }

    //calculando a matriz inversa...
    for(int i =0;i<4;i++){
        for(int j=0;j<4;j++){
            matriz_inversa[i][j] = Matriz_adj[i][j]/Determinante;
        }
    }
    //imprimindo a matriz que o usuario preencheu...
    system("pause");
    system("cls");
    cout << "\nMatriz digitada : \n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << " " << Matriz_usuario[i][j];
        }
        cout << "\n";
    }

    //imprimindo a matriz inversa...
    cout << "\nMatriz inversa : \n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << " " << matriz_inversa[i][j];
        }
        cout << "\n";
    }

    return 0;
}

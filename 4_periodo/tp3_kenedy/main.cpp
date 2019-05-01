#include <iostream>
#include <stdio.h>
#define TAM 3
using namespace std;

int main()
{
    //matriz principal...
    float MatrizPrin[TAM][TAM];
    //vetor dos termos independentes...
    float VetIndep[TAM];

    //inicializando a matriz...
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            MatrizPrin[i][j] = 0;
        }
    }

    //preenchendo a matriz...
    for(int i = 0; i < TAM; i++)
    {
        for(int j = 0; j < TAM; j++)
        {
            printf("Digite o valor na posicao %dX%d\n",i,j);
            cin >> MatrizPrin[i][j];
        }
    }

    //termos indepedentes...
    for(int j = 0; j < TAM; j++)
        {
            printf("Digite o %d° termo independete",j);
            cin >> VetIndep[j];
        }



    return 0;
}

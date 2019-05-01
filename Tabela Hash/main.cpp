#include <iostream>
#include <math.h>
using namespace std;
typedef int TipoVetor;

int Hash(int valor, int tamanho){
    int resultado;
    resultado = (pow(valor, 2)/2)%tamanho;

    return resultado;
}

int main()
{
    int tamanho;
    cin >> tamanho;
    TipoVetor Vetor[tamanho];
    Vetor = {3, 2, 1};

    return 0;
}

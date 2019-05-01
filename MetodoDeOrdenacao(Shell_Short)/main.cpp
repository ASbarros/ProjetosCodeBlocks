#include <iostream>
#include <time.h>
#define TAMANHO  10
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void ShellShort(int vetor[]){
    int gap = 1, p, a, valor;

    while(gap < TAMANHO){
        gap = (gap*3) + 1;
    }
    gap = (gap - 1)/3;
    while ( gap > 0) {
        for(p = gap; p < TAMANHO; p++) {
            valor = vetor[p];
            a = p - gap;
            while (a >= 0 && valor < vetor[a]) {
                vetor[a + gap] = vetor[a];
                a = a - gap;
            }
            vetor [a + gap] = valor;
        }
        gap = (gap - 1)/3;
    }
}

int main()
{
    srand(time(NULL));
    int vetor[TAMANHO];
    for(int i = 0;i <TAMANHO; i++){
        vetor[i] = (rand()%20);
    }

    ShellShort(vetor);

     for(int i = 0; i < TAMANHO; i++){
        cout << vetor[i] << " ";
    }

    return 0;
}

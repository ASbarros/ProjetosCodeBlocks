/*

        Programa com a implementação de uma pilha com uso
        de memória dinâmica
*/


//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

//Essa estrutura será utilizada como uma célula da Pilha
//Item armazena o valor informado pelo usuário
//Prox é um ponteiro que aponta para outra célula da Pilha
//Esse ponteiro será utilizado para apontar para a célula que contém o próximo
//valor a ser desempilhado na Pilha (a célula que está "abaixo" da atual)
struct TipoCelula
{

    int Item;
    TipoCelula *Prox;
};



TipoCelula *Topo1;
TipoCelula *Topo2;

int Contador1;
int Contador2;

void Pilha_Construtor1()
{
    Topo1 = NULL;
    Contador1 = 0;
}
void Pilha_Construtor2()
{
    Topo2 = NULL;
    Contador2 = 0;
}
void Pilha_Destrutor1()
{

    TipoCelula *Temp;

    while(Topo1 != NULL)
    {
        Temp= Topo1;
        Topo1 = Topo1 -> Prox;

        Temp->Prox = NULL;
        free(Temp);
    }

    Contador1 = 0;
}
void Pilha_Destrutor2()
{

    TipoCelula *Temp;

    while(Topo2 != NULL)
    {
        Temp = Topo2;
        Topo2 = Topo2 -> Prox;

        Temp->Prox = NULL;
        free(Temp);
    }

    Contador2 = 0;
}

bool Pilha_Vazia1()
{
    return Topo1 == NULL;
}
bool Pilha_Vazia2()
{
    return Topo2 == NULL;
}

int Pilha_Tamanho1()
{
    return Contador1;
}
int Pilha_Tamanho2()
{
    return Contador2;
}

bool Pilha_Empilhar1(int Elemento)
{
    TipoCelula *Nova;

    if((Nova = (TipoCelula *) malloc(sizeof(TipoCelula)))==NULL)
    {
        return false;
    }
    else
    {
        Nova->Item = Elemento;
        Nova->Prox = Topo1;
        Topo1 = Nova;
        Contador1++;
        return true;
    }
}
bool Pilha_Empilhar2(int Elemento)
{

    TipoCelula *Nova;

    if((Nova = (TipoCelula *) malloc(sizeof(TipoCelula)))==NULL)
    {
        return false;
    }
    else
    {
        Nova->Item = Elemento;
        Nova->Prox = Topo2;
        Topo2 = Nova;
        Contador2++;
        return true;
    }
}

bool Pilha_Desempilhar1(int &Elemento)
{

    if(!Pilha_Vazia1())
    {
        TipoCelula *Temp1 = Topo1;
        Topo1 = Topo1->Prox;
        Elemento = Temp1->Item;
        Temp1->Prox = NULL;
        free(Temp1);
        Contador1--;
        return true;
    }
    else
        return false;
}
bool Pilha_Desempilhar2(int &Elemento)
{
    if(!Pilha_Vazia2())
    {
        TipoCelula *Temp2 = Topo2;
        Topo2 = Topo2->Prox;
        Elemento = Temp2->Item;
        Temp2->Prox = NULL;
        free(Temp2);
        Contador2--;
        return true;
    }
    else
        return false;
}

bool Pilha_Get1(int &Elemento)
{
    if(!Pilha_Vazia1())
    {
        Elemento = Topo1->Item;
        return true;
    }
    else
        return false;
}
bool Pilha_Get2(int &Elemento)
{
    if(!Pilha_Vazia2())
    {
        Elemento = Topo2->Item;
        return true;
    }
    else
        return false;
}

int CharToInt(char x)
{
    switch(x)
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '0':
        return 0;
    }
}
int main()
{
    int tamanhonum;
    string numero1;
    string numero2;

    TipoCelula  pilha1;
    TipoCelula  pilha2;
    Pilha_Construtor1();
    Pilha_Construtor2();
    cout <<"digite numero de elementos que serao digitados : \n";
    cin >> tamanhonum;
    cout << "\ndigite o primeiro numero :";
    cin >> numero1;
    cout << "\ndigite o segundo numero :";
    cin >> numero2;
    if (numero1.size() > tamanhonum || numero2.size() >  tamanhonum  )
    {
        cout << "erro tamanhos diferentes o numero foi maior que o informado";
        return 0;
    }
    int posicao = 0;

    for (int i = 0 ; i < numero1.size() ; i++)
    {
        posicao = CharToInt(numero1[i]);
        Pilha_Empilhar1(posicao);
    }
    for (int i = 0 ; i < numero2.size() ; i++)
    {
        posicao = CharToInt(numero1[i]);
        Pilha_Empilhar2(posicao);
    }
    Pilha_Destrutor1();
    Pilha_Destrutor2();
    return 0;
}

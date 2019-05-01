#include <iostream>
using namespace std;

#include "TipoArvore.h"


int main()
{

    TipoArvore *A = new TipoArvore();
    TipoItem X;
    char cont;


    cout << "Digite dados para colocar na arvore";

    do{
         cout << "\n\nDigite o dado: ";
         cin >> X;

         if(!A->Inserir(X))
           cout << "Erro. Memoria insuficiente ou elemento ja existe na arvore.";

         cout << "\nMais dados? (S/N)";
         cin >> cont;
    }while(toupper(cont) != 'N');



    cout << "\n\nNumero de elementos na arvore: ";
    cout << A->Tamanho() << "\n";


    cout << "\n\nArvore em-ordem : \n\n";
    A->Mostrar (0);
    cout << "\n";


    cout << "\n\nArvore pre-ordem : \n\n";
    A->Mostrar (1);
    cout << "\n";

    cout << "\n\nArvore pos-ordem : \n\n";
    A->Mostrar (2);
    cout << "\n";

    cout << "\n\nEntre com um valor para pesquisa: ";
    cin >> X;
    if(A->Pesquisar ( X )) cout <<"\nValor encontrado\n";
    else cout << "\nValor nao encontrado\n";

    cout << "\n\nEntre com um valor para ser excluido: ";
    cin >> X;
    if(A->Remover ( X )) cout <<"\nValor excluido\n";
    else cout << "\nValor nao encontrado\n";


    cout << "Entre com um valor para pesquisa: ";
    cin >> X;
    if(A->Pesquisar ( X )) cout <<"\nValor encontrado\n";
    else cout << "\nValor nao encontrado\n";

    cout << "\n\nNumero de elementos na arvore: ";
    cout << A->Tamanho() << "\n";


    cout << "\n\nArvore pre-ordem : \n\n";
    A->Mostrar (1);
    cout << "\n";

    delete A;
    return 0;
}

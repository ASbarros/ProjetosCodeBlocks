/*nome:ANDERSON DOS SANTOS DE BARROS
*matricula:201700411685791650
*
*/


#include <iostream>
#include <stdlib.h>
using namespace std;

#include "TipoArvore.h"

int main()
{

    TipoArvore A;
    TipoItem X;
    char cont;
    int valor=0;
    TipoItem elemento;


    cout << "Digite dados para colocar na arvore";

    do{
         cout << "\n\nDigite o dado: ";
         cin >> X;

         A.InserirAVL(X);
         cout << "\nMais dados? (S/N)";
         cin >> cont;
    }while(toupper(cont) != 'N');



    system("cls");
    cout << "\n\nNumero de elementos na arvore: ";
    cout << A.Tamanho() << "\n";
    system("pause");


    system("cls");
    cout << "Arvore em-ordem : \n\n";
    A.Mostrar (0);
    cout << "\n";
    system("pause");


///funçoes que eu criei

    system("cls");//grau de cada nodo
    A.Grau_No();
    cout << "\n";
    system("pause");

    system("cls");
    A.Grau_Arvore(valor);
    cout << "\ngrau da arvore:" << valor << "\n";
    system("pause");



    system("cls");
    cout << "\naltura da arvore:" << A.Altura_Arvore()<< "\n";
    system("pause");

    system("cls");
    cout << "\nnivel de cada nodo...\n";
    A.Nivel_No();
    cout << "\n";
    system("pause");

    system("cls");//Altura de cada nodo
    cout << "\naltura de cada nodo...\n";
    A.Altura_No();
    cout << "\n";
    system("pause");

    system("cls");
    cout << "\nclassificacao da arvore...\n";
    A.Verifica();
    system("pause");


    delete &A;
    return 0;
}

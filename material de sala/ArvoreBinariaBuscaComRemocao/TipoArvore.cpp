#include <iostream>
using namespace std;


#include "TipoArvore.h"


TipoArvore::TipoArvore()
{

    Raiz = NULL;
    Contador = 0;
}

TipoArvore::~TipoArvore(){


     Destruir(Raiz);
}

void TipoArvore::Destruir(TipoCelula *&Raiz){


     if(Raiz!=NULL)
     {
         Destruir(Raiz->Esq);
         Destruir(Raiz->Dir);

         delete(Raiz);
         Raiz = NULL;
     }
}


bool TipoArvore::Vazia()
{

   return Raiz == NULL;
}

int TipoArvore::Tamanho()
{

   return Contador;
}

bool TipoArvore::Inserir(TipoItem Elemento)
{

     return Inserir(Elemento, Raiz);
}

bool TipoArvore::Inserir(TipoItem Elemento, TipoCelula *&Raiz)
{

     if(Raiz == NULL)
     {
        if((Raiz = new(TipoCelula)) == NULL)
           return false;
        else
        {
            Raiz->Valor = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Contador++;
            return true;
        }
     }
     else
     {
         if(Elemento < Raiz->Valor)
           return Inserir(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Valor)
              return Inserir(Elemento, Raiz->Dir);
            else return false;
         }
     }
}


bool TipoArvore::Pesquisar(TipoItem Elemento)
{

     return Pesquisar(Elemento, Raiz);
}

bool TipoArvore::Pesquisar(TipoItem Elemento, TipoCelula *Raiz)
{

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Valor)
           return Pesquisar(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Valor)
              return Pesquisar(Elemento, Raiz->Dir);
             else return true;
         }
     }
}

bool TipoArvore::Remover(TipoItem Elemento)
{

    int opc;

    do{

         cout << "\n\nEscolha o modo de exclusao: (1) Fusao. (2) Copia: ";
         cin >> opc;

         switch(opc)
         {
           case 1: return (RemoverFusao(Elemento, Raiz));
           case 2: return (RemoverCopia(Elemento, Raiz));
           default: cout <<"\n\nOpcao invalida";
         }
    }while(opc != 1 && opc != 2);
}

bool TipoArvore::RemoverFusao(TipoItem Elemento, TipoCelula *&Raiz)
{

     TipoCelula *Temp;

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Valor)
           return RemoverFusao(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Valor)
              return RemoverFusao(Elemento, Raiz->Dir);
             else
             {
                 Temp = Raiz;

                 if(Raiz->Esq == NULL)
                    Raiz = Raiz->Dir;
                 else{
                     if(Raiz->Dir == NULL)
                        Raiz = Raiz->Esq;
                     else   //a raiz tem ambos os filhos
                     {
                        Temp = Raiz -> Esq;

                        while(Temp->Dir != NULL)
                          Temp = Temp->Dir;

                        Temp->Dir = Raiz->Dir;

                        Temp = Raiz;
                        Raiz = Raiz->Esq;
                     }
                 }
                 Temp->Dir = Temp->Esq = NULL;
                 delete(Temp);
                 Contador--;
                 return true;
             }
         }
     }
}


bool TipoArvore::RemoverCopia(TipoItem Elemento, TipoCelula *&Raiz)
{

     TipoCelula *Temp, *Ant;

     if(Raiz == NULL) return false;
     else
     {
         if(Elemento < Raiz->Valor)
           return RemoverCopia(Elemento, Raiz->Esq);
         else
         {
            if(Elemento > Raiz->Valor)
              return RemoverCopia(Elemento, Raiz->Dir);
             else
             {

                 Temp = Raiz;

                 if(Raiz->Esq == NULL)
                    Raiz = Raiz->Dir;
                 else
                 {
                     if(Raiz->Dir == NULL)
                        Raiz = Raiz->Esq;
                     else   //a raiz tem ambos os filhos
                     {
                        Temp = Raiz -> Esq;
                        Ant = Raiz;

                        while(Temp->Dir != NULL)
                        {
                          Ant = Temp;
                          Temp = Temp->Dir;
                        }

                        Raiz->Valor = Temp->Valor;

                        if(Ant == Raiz) Ant->Esq = Temp->Esq;
                        else Ant->Dir = Temp->Esq;
                     }
                 }

                 Temp->Dir = Temp->Esq = NULL;
                 delete(Temp);
                 Contador--;
                 return true;
             }
         }
     }
}


void TipoArvore::Mostrar(int Ordem = 0)
{

     switch (Ordem)
     {
        case 0: EmOrdem(Raiz); break;
        case 1: PreOrdem(Raiz); break;
        case 2: PosOrdem(Raiz); break;
        default: cout <<"Ordem desconhecida";
     }
}

void TipoArvore::EmOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         EmOrdem(Raiz->Esq);
         cout << Raiz->Valor << " ";
         EmOrdem(Raiz->Dir);
     }
}

void TipoArvore::PreOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         cout << Raiz->Valor << " ";
         PreOrdem(Raiz->Esq);
         PreOrdem(Raiz->Dir);
     }
}

void TipoArvore::PosOrdem(TipoCelula *Raiz)
{

     if(Raiz!=NULL)
     {
         PosOrdem(Raiz->Esq);
         PosOrdem(Raiz->Dir);
         cout << Raiz->Valor << " ";
     }
}

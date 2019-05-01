#include <iostream>
using namespace std;

#include "TipoArvore.h"

TipoArvore::TipoArvore()
{

    Raiz = NULL;
    Quantos = 0;
}

TipoArvore::~TipoArvore()
{


    Destruir(Raiz);
}

void TipoArvore::Destruir(TipoCelula *&Raiz)
{


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

    return Quantos;
}

bool TipoArvore::InserirAVL(TipoItem Elemento)
{
    bool AlterarBalanceamento;

    return InserirAVL(Elemento, Raiz, AlterarBalanceamento);
}

bool TipoArvore::InserirAVL(TipoItem Elemento, TipoCelula *&Raiz, bool &AlterarBalanceamento)
{
    TipoCelula *Temp1, *Temp2;
    bool retorno;


    if(Raiz == NULL)
    {
        if((Raiz = new(TipoCelula)) == NULL)
        {
            AlterarBalanceamento = false;
            return false;
        }
        else
        {
            Raiz->Valor = Elemento;
            Raiz->Esq = Raiz->Dir = NULL;
            Raiz->Bal = 0;
            AlterarBalanceamento = true;
            Quantos++;
            return true;
        }
    }
    else
    {
        if(Elemento < Raiz->Valor)
        {
            retorno = InserirAVL(Elemento, Raiz->Esq, AlterarBalanceamento);

            if(AlterarBalanceamento)  //sub-árvore a esquerda AlterarBalanceamento
            {
                switch(Raiz->Bal)
                {
                case 0:
                    Raiz->Bal = -1;
                    break; //Continua valendo AlterarBalanceamento = true

                case 1:
                    Raiz->Bal = 0;
                    AlterarBalanceamento = false;
                    break;

                case -1:
                    Temp1 = Raiz-> Esq;

                    if(Temp1->Bal == -1)   //rotação simples a direita
                    {

                        Raiz->Esq = Temp1->Dir;
                        Temp1->Dir = Raiz;
                        Temp1->Bal = 0;
                        Raiz->Bal = 0;
                        Raiz = Temp1;
                    }
                    else //rotação dupla: esquerda/direita
                    {

                        Temp2 = Temp1->Dir;
                        Temp1->Dir = Temp2->Esq;
                        Temp2->Esq = Temp1;
                        Raiz->Esq = Temp2->Dir;
                        Temp2->Dir = Raiz;

                        if(Temp2->Bal == -1)
                            Raiz->Bal = 1;
                        else
                            Raiz->Bal = 0;

                        if(Temp2->Bal == 1)
                            Temp1->Bal = -1;
                        else
                            Temp1->Bal = 0;

                        Temp2->Bal = 0;
                        Raiz = Temp2;
                    }

                    AlterarBalanceamento = false;  //Para rotação simples e dupla
                }
            }
            return retorno;
        }
        else
        {
            if(Elemento > Raiz->Valor)
            {
                retorno = InserirAVL(Elemento, Raiz->Dir, AlterarBalanceamento);

                if(AlterarBalanceamento)  //sub-árvore a direita AlterarBalanceamento
                {
                    switch(Raiz->Bal)
                    {
                    case 0:
                        Raiz->Bal = 1;
                        break; //Continua valendo AlterarBalanceamento = true

                    case -1:
                        Raiz->Bal = 0;
                        AlterarBalanceamento = false;
                        break;

                    case 1:
                        Temp1 = Raiz-> Dir;

                        if(Temp1->Bal == 1) //rotação simples a esquerda
                        {

                            Raiz->Dir = Temp1->Esq;
                            Temp1->Esq = Raiz;
                            Temp1->Bal = 0;
                            Raiz->Bal = 0;
                            Raiz = Temp1;
                        }
                        else //rotação dupla: direita/esquerda
                        {

                            Temp2 = Temp1->Esq;
                            Temp1->Esq = Temp2->Dir;
                            Temp2->Dir = Temp1;
                            Raiz->Dir = Temp2->Esq;
                            Temp2->Esq = Raiz;


                            if(Temp2->Bal == 1)
                                Raiz->Bal = -1;
                            else
                                Raiz->Bal = 0;

                            if(Temp2->Bal == -1)
                                Temp1->Bal = 1;
                            else
                                Temp1->Bal = 0;

                            Temp2->Bal = 0;
                            Raiz = Temp2;
                        }
                        AlterarBalanceamento = false;  //Para rotação simples e dupla
                    }
                }
                return retorno;
            }
            else
                return false;
        }
    }
}


bool TipoArvore::Pesquisar(TipoItem Elemento)
{

    return (Pesquisar(Elemento, Raiz));
}

bool TipoArvore::Pesquisar(TipoItem Elemento, TipoCelula *Raiz)
{

    if(Raiz == NULL)
        return false;
    else
    {
        if(Elemento < Raiz->Valor)
            return Pesquisar(Elemento, Raiz->Esq);
        else
        {
            if(Elemento > Raiz->Valor)
                return Pesquisar(Elemento, Raiz->Dir);
            else
                return true;
        }
    }
}

bool TipoArvore::RemoverAVL(TipoItem Elemento)
{
    bool AlterarBalanceamento;

    return RemoverAVL(Elemento, Raiz, AlterarBalanceamento);
}


bool TipoArvore::RemoverAVL(TipoItem Elemento,TipoCelula *&Raiz, bool &AlterarBalanceamento)
{

    TipoCelula *Temp;
    // TipoCelula *Ant; Variável utilizada na remoção por cópia original que não será mais
    // necessária devido à correção de valores de balanceamento implementada abaixo
    bool retorno;

    if(Raiz == NULL)
    {
        //cout << "\n\nValor nao encontrado";
        AlterarBalanceamento = false;
        return false;
    }
    else
    {
        if(Elemento < Raiz->Valor)
        {
            retorno = RemoverAVL(Elemento, Raiz->Esq, AlterarBalanceamento);
            BalancearRemocaoEsquerda(Raiz, AlterarBalanceamento);

            return retorno;
        }
        else
        {
            if(Elemento > Raiz->Valor)
            {
                retorno = RemoverAVL(Elemento, Raiz->Dir, AlterarBalanceamento);
                BalancearRemocaoDireita(Raiz, AlterarBalanceamento);

                return retorno;
            }
            else
            {

                Temp  = Raiz;

                if(Raiz->Esq == NULL)
                {
                    Raiz = Raiz->Dir;
                    AlterarBalanceamento=true;
                }
                else
                {
                    if(Raiz->Dir == NULL)
                    {
                        Raiz = Raiz->Esq;
                        AlterarBalanceamento=true;

                    }
                    else   //a raiz tem ambos os filhos
                    {
                        Temp = Raiz -> Esq;

                        while(Temp->Dir != NULL)
                        {
                            Temp = Temp->Dir;
                        }

                        Raiz->Valor = Temp->Valor;

                        /* Esse codigo não é mais necessário devido à abordagem abaixo
                           que corrige os valores de balanceamento através da recursividade.
                        if(Ant == Raiz) Ant->Esq = Temp->Esq;
                        else Ant->Dir = Temp->Esq;*/

                        AlterarBalanceamento = true;
                        RemoverAVL(Raiz->Valor, Raiz->Esq, AlterarBalanceamento);
                        BalancearRemocaoEsquerda(Raiz, AlterarBalanceamento);
                        return true;
                    }
                }

                Temp->Dir = Temp->Esq = NULL;
                delete(Temp);
                Quantos--;
                return true;
            }
        }
    }
}


void TipoArvore::BalancearRemocaoEsquerda(TipoCelula *&Raiz, bool &AlterarBalanceamento)
{
    TipoCelula *Temp1, *Temp2;

    if(AlterarBalanceamento)
    {
        switch(Raiz->Bal)
        {
        case 0:
            Raiz->Bal = 1;
            AlterarBalanceamento = false;
            break;

        case -1:
            Raiz->Bal = 0;
            break; //Continua valendo AlterarBalanceamento = true

        case 1:
            Temp1 = Raiz-> Dir;


            if(Temp1->Bal == 0 || Temp1->Bal == 1)//rotação simples
            {
                //a esquerda

                Raiz->Dir = Temp1->Esq;
                Temp1->Esq = Raiz;

                if(Temp1->Bal == 0)
                {
                    Temp1->Bal = -1;
                    Raiz->Bal = 1;
                    AlterarBalanceamento = false; //para rotação simples
                }
                else // entao Temp1->Bal é igual a 1
                {
                    Temp1->Bal = 0;
                    Raiz->Bal = 0;
                    AlterarBalanceamento = true; //para rotação simples
                }

                Raiz = Temp1;
            }
            else //rotação dupla: direita/esquerda
            {

                Temp2 = Temp1->Esq;
                Temp1->Esq = Temp2->Dir;
                Temp2->Dir = Temp1;
                Raiz->Dir = Temp2->Esq;
                Temp2->Esq = Raiz;


                if(Temp2->Bal == 1)
                {
                    Temp2->Bal = 0;
                    Temp1->Bal = 0;
                    Raiz->Bal = -1;
                }
                else
                {
                    if(Temp2->Bal == -1)
                    {
                        Temp2->Bal = 0;
                        Temp1->Bal = 1;
                        Raiz->Bal =  0;
                    }
                    else  //Temp2->Bal == 0
                    {
                        Temp2->Bal = 0;
                        Temp1->Bal = 0;
                        Raiz->Bal =  0;
                    }
                }

                Raiz = Temp2;
                AlterarBalanceamento = true; //para rotação dupla
            }
        } //fim switch
    } //fim if (AlterarBalanceamento)
}


void TipoArvore::BalancearRemocaoDireita(TipoCelula *&Raiz,  bool &AlterarBalanceamento)
{

    TipoCelula *Temp1, *Temp2;


    if(AlterarBalanceamento)
    {
        switch(Raiz->Bal)
        {
        case 0:
            Raiz->Bal = -1;
            AlterarBalanceamento = false;
            break;

        case 1:
            Raiz->Bal = 0;
            break;

        case -1:
            Temp1 = Raiz-> Esq;

            if(Temp1->Bal == 0 || Temp1->Bal == -1)//rotação simples
            {
                //a esquerda

                Raiz->Esq = Temp1->Dir;
                Temp1->Dir = Raiz;

                if(Temp1->Bal == 0)
                {
                    Temp1->Bal = 1;
                    Raiz->Bal = -1;
                    AlterarBalanceamento = false; //para rotação simples
                }
                else // entao Temp1->Bal é igual a -1
                {
                    Temp1->Bal = 0;
                    Raiz->Bal = 0;
                    AlterarBalanceamento = true; //para rotação simples
                }

                Raiz = Temp1;
            }
            else //rotação dupla: direita/esquerda
            {

                Temp2 = Temp1->Dir;
                Temp1->Dir = Temp2->Esq;
                Temp2->Esq = Temp1;
                Raiz->Esq = Temp2->Dir;
                Temp2->Dir = Raiz;


                if(Temp2->Bal == 1)
                {
                    Temp2->Bal = 0;
                    Temp1->Bal = -1;
                    Raiz->Bal = 0;
                }
                else
                {
                    if(Temp2->Bal == -1)
                    {
                        Temp2->Bal = 0;
                        Temp1->Bal = 0;
                        Raiz->Bal =  1;
                    }
                    else  //Temp2->Bal == 0
                    {
                        Temp2->Bal = 0;
                        Temp1->Bal = 0;
                        Raiz->Bal =  0;
                    }
                }

                Raiz = Temp2;
                AlterarBalanceamento = true; //Para rotação dupla
            }
        } //fim switch
    } //fim if (AlterarBalanceamento)
}


void TipoArvore::Mostrar(int Ordem = 0)
{

    switch (Ordem)
    {
    case 0:
        EmOrdem(Raiz);
        break;
    case 1:
        PreOrdem(Raiz);
        break;
    case 2:
        PosOrdem(Raiz);
        break;
    default:
        cout <<"Ordem desconhecida";
    }
}

void TipoArvore::EmOrdem(TipoCelula *Raiz)
{

    if(Raiz!=NULL)
    {
        EmOrdem(Raiz->Esq);
        cout << "\nValor = " << Raiz->Valor << " Balaneamento = " << Raiz->Bal;
        EmOrdem(Raiz->Dir);
    }
}

void TipoArvore::PreOrdem(TipoCelula *Raiz)
{

    if(Raiz!=NULL)
    {
        cout << "\nValor = " << Raiz->Valor << " Balaneamento = " << Raiz->Bal;
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
        cout << "\nValor = " << Raiz->Valor << " Balaneamento = " << Raiz->Bal;
    }
}


///daqui pra baixo são as funcões que eu criei
///------------------------------------------------------------------------------------------------------------------------------------
int TipoArvore::Grau_No()
{
    return Grau_No(Raiz);
}

int TipoArvore::Grau_No(TipoCelula *Raiz)
{
    if(Raiz == NULL)
        return true;
    if(Raiz->Esq != NULL)
        Grau_No(Raiz->Esq);
    if(Raiz->Dir != NULL)
        Grau_No(Raiz->Dir);
    cout << "\nnodo: " << Raiz->Valor;
    if(Raiz->Esq != NULL && Raiz->Dir != NULL)
    {
        cout << "  grau 2";
        return 2;
    }
    if(Raiz->Esq != NULL || Raiz->Dir != NULL)
    {
        cout << "  grau 1";
        return 1;
    }
    cout << "  grau 0 ";
    return 0;

}

///-----------------------------------------------------------------------------------------------------------------

bool TipoArvore::Grau_Arvore(int &valor)
{
    return (Grau_Arvore(Raiz,valor));
}

bool TipoArvore::Grau_Arvore(TipoCelula *Raiz,int &valor ) //já que eh uma arvore AVL vou verificar apenas o primeiro nodo , pois se ela tiver 3 ou mais filhos
{
    if(Raiz == NULL) //se a arvore eh vazia
    {
        valor = 0;
        return false;
    }
    else
    {
        if(Raiz->Esq != NULL && Raiz->Dir != NULL) //se a raiz principal da arvore tem dois filhos
        {
            valor = 2;
            return true;
        }
        if(Raiz->Esq != NULL) //se a raiz principal da arvore tem um filho
        {
            valor = 1;
            return true;
        }
        else if(Raiz->Dir != NULL) //se a raiz principal da arvore tem um filho
        {
            valor = 1;
            return true;
        }
    }
}

///----------------------------------------------------------------------------------------------------------------------------

void TipoArvore::Nivel_No()
{
    int valor = 0;
    Nivel_No(Raiz,valor);
}

void TipoArvore::Nivel_No(TipoCelula *Raiz,int valor)
{

    if(Raiz != NULL)
    {
        cout << "\nelemento : " << Raiz->Valor << "   nivel: " << valor;
        valor++;
        Nivel_No(Raiz->Esq,valor);
        Nivel_No(Raiz->Dir,valor);
    }
}
///-----------------------------------------------------------------------------------------------------------------------

void TipoArvore::Altura_No()
{
    Altura_No(Raiz);
}

void TipoArvore::Altura_No(TipoCelula *Raiz)
{
    if(Raiz != NULL)
    {
        if(Raiz->Esq != NULL)
            Altura_No(Raiz->Esq);
        if(Raiz->Dir!= NULL)
            Altura_No(Raiz->Dir);
    }
    if(Raiz != NULL)
        cout << "\nelemento:" <<Raiz->Valor <<"  altura:" <<Altura_Arvore(Raiz);//todos os nodos são , por definição ,
                                                                            //uma arvore ,então eu apenas chamei a função
                                                                            //que retorna a altura de cada "arvore-nodo"
    }

///----------------------------------------------------------------------------------------------------------------

int TipoArvore::Altura_Arvore()
{
    return (Altura_Arvore(Raiz));
}
int TipoArvore::Altura_Arvore(TipoCelula *Raiz)
{
    if(Raiz == NULL || ((Raiz->Esq == NULL) && (Raiz->Dir == NULL)))
        return 0;
    else
        return (1 + Maior(Altura_Arvore(Raiz->Esq),Altura_Arvore(Raiz->Dir)));
    cout << "\naltura da arvore:" << Maior(Altura_Arvore(Raiz->Esq),Altura_Arvore(Raiz->Dir));


}
///--------------------------------------------------------------------------------------------------------------------------

int TipoArvore::Maior(int esquerdo,int direito)
{
    if(esquerdo > direito)
        return esquerdo;
    return direito;
}
///--------------------------------------------------------------------------------------------------------------------------

///--------------------------------------------------------------------------------------------------------------------------

bool TipoArvore::Arvore_cheia(TipoCelula *Raiz){
    if(Tamanho() == (pow(2,Altura_Arvore()+1)-1))
        return true;
    else
        return false;
}
///--------------------------------------------------------------------------------------------------------------------------
int TipoArvore::Grau_No2(TipoCelula *Raiz)//copiei e colei a msm funçao ,apenas retirei os prints
{
    if(Raiz == NULL)
        return true;
    if(Raiz->Esq != NULL)
        Grau_No2(Raiz->Esq);
    if(Raiz->Dir != NULL)
        Grau_No2(Raiz->Dir);
    if(Raiz->Esq != NULL && Raiz->Dir != NULL)
    {
        return 2;
    }
    if(Raiz->Esq != NULL || Raiz->Dir != NULL)
    {
        return 1;
    }
    return 0;

}
bool TipoArvore::Arvore_estritamente_binaria(TipoCelula *Raiz){
    if(Raiz!=NULL){
        if(Grau_No2(Raiz) != 1){
            Arvore_estritamente_binaria(Raiz->Esq);
            Arvore_estritamente_binaria(Raiz->Dir);
            return true;//se ela for uma arvore estritamente binaria
        }
        return
            false;//se ela não for uma arvore estritamente binaria
    }
}
///--------------------------------------------------------------------------------------------------------------------------
bool TipoArvore::Arvore_completa(TipoCelula *Raiz){
    if(Arvore_estritamente_binaria(Raiz)){//para a arvore ser completa,ela tem que ser estritemente binaria
        if(Confere_arvore_completa(Raiz))
            return true;
        else
            return false;
    }
    else
        return false;
}

bool TipoArvore::Confere_arvore_completa(TipoCelula *Raiz){
    TipoCelula *temporario;
    temporario = Raiz;
    int val = 0;

    if(temporario->Esq != NULL){
        Confere_arvore_completa(temporario->Esq);
        if(temporario->Dir != NULL)
            Confere_arvore_completa(temporario->Dir);
    }
    if(temporario->Dir != NULL)
        Confere_arvore_completa(temporario->Dir);

    for(int i =0;i<Altura_Arvore();i++){
        if((i == Altura_Arvore()-1) && (Grau_Arvore(temporario,val)&& val == 0))//confere o grau dos filhos do ultimo nivel
            return true;
        else if(i == Altura_Arvore()-2 && Grau_Arvore(temporario,val)&& val == 0)//confere o grau dos filhos do penultimo nivel
            return true;
        else
            return false;
    }
}
///--------------------------------------------------------------------------------------------------------------------------

int TipoArvore::Altura_Arvore2(TipoCelula *Raiz)
{
    if(Raiz == NULL || ((Raiz->Esq == NULL) && (Raiz->Dir == NULL)))
        return 0;
    else
        return (1 + Maior(Altura_Arvore(Raiz->Esq),Altura_Arvore(Raiz->Dir)));
}

void TipoArvore::Verifica(){
    Verifica(Raiz);
}
void TipoArvore::Verifica(TipoCelula *Raiz){
    if(Arvore_cheia(Raiz)){
        cout << "\narvore cheia...\narvore estritamente binaria...\narvore completa...\n";
    }
    else if(Arvore_completa(Raiz)){
        cout << "\narvore completa...\narvore estritamente binaria...\n";
    }
    else if(Arvore_estritamente_binaria(Raiz) && Arvore_cheia(Raiz)){
        cout << "\narvore estritamente binaria...\n";
    }
    else if(Arvore_completa(Raiz)){
        cout <<"\narvore completa...\n";
    }
    else if(Arvore_completa(Raiz) && !Arvore_cheia(Raiz)){
        cout << "\narvore completa...\n";
    }
    else
        cout << "\na arvore nao se encaixa em nem uma das classificacoes!\n";

}

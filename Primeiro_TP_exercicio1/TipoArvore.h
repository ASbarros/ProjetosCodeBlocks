#ifndef TIPOARVORE_H_INCLUDED
#define TIPOARVORE_H_INCLUDED
#include<math.h>

typedef int TipoItem;


class TipoArvore
{
  friend class Test; // CHANGE
      private:

              struct TipoCelula
              {
                     TipoItem Valor;
                     TipoCelula *Esq, *Dir;
                     int Bal;
              };

              TipoCelula *Raiz;
              int Quantos;

///-------------------------------------------------------------------------------------------------------------------------------

           bool InserirAVL(TipoItem Elemento, TipoCelula *&Raiz, bool &Cresceu);
           bool Pesquisar(TipoItem Elemento, TipoCelula *Raiz);
           bool RemoverAVL(TipoItem Elemento,TipoCelula *&Raiz, bool &Diminuiu);
           void EmOrdem(TipoCelula *Raiz);
           void PreOrdem(TipoCelula *Raiz);
           void PosOrdem(TipoCelula *Raiz);
           void BalancearRemocaoEsquerda(TipoCelula *&Raiz, bool &Diminuiu);
           void BalancearRemocaoDireita(TipoCelula *&Raiz, bool &Diminuiu);
           void Destruir(TipoCelula *&Raiz);


           ///funções que eu criei

           int Grau_No(TipoCelula *Raiz);
           int Grau_No2(TipoCelula *Raiz);
           bool Grau_Arvore(TipoCelula *Raiz,int &valor);
           void Nivel_No(TipoCelula *Raiz,int valor);
           void Altura_No(TipoCelula *Raiz);
           int Altura_Arvore(TipoCelula *Raiz);
           int Altura_Arvore2(TipoCelula *Raiz);
           int Maior(int esquerdo,int direito);
           void Verifica(TipoCelula *Raiz);
           bool Arvore_cheia(TipoCelula *Raiz);
           bool Arvore_estritamente_binaria(TipoCelula *Raiz);
           bool Arvore_completa(TipoCelula *Raiz);
           bool Confere_arvore_completa(TipoCelula *Raiz);

      public:

              TipoArvore();
              ~TipoArvore();
              bool Vazia();
              int Tamanho();
              bool InserirAVL(TipoItem Elemento);
              bool Pesquisar(TipoItem Elemento);
              bool RemoverAVL(TipoItem Elemento);
              void Mostrar(int Ordem);

              ///funções que eu criei

              int Grau_No();
              bool Grau_Arvore(int &valor);
              void Nivel_No();
              void Altura_No();
              int Altura_Arvore();
              void Verifica();

};

#endif // TIPOARVORE_H_INCLUDED

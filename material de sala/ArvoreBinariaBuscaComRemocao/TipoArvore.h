#ifndef TIPOARVORE_H_INCLUDED
#define TIPOARVORE_H_INCLUDED

typedef int TipoItem;


class TipoArvore
{

      private:

              struct TipoCelula
              {
                     TipoItem Valor;
                     TipoCelula *Esq, *Dir;
              };

              TipoCelula *Raiz;
              int Contador;

              bool Inserir(TipoItem Elemento, TipoCelula *&Raiz);
              bool Pesquisar(TipoItem Elemento, TipoCelula *Raiz);
              bool RemoverFusao(TipoItem Elemento, TipoCelula *&Raiz);
              bool RemoverCopia(TipoItem Elemento, TipoCelula *&Raiz);
              void EmOrdem(TipoCelula *Raiz);
              void PreOrdem(TipoCelula *Raiz);
              void PosOrdem(TipoCelula *Raiz);
              void Destruir(TipoCelula *&Raiz);

      public:

              TipoArvore();
              ~TipoArvore();
              bool Vazia();
              int Tamanho();
              bool Inserir(TipoItem Elemento);
              bool Pesquisar(TipoItem Elemento);
              bool Remover(TipoItem Elemento);
              void Mostrar(int Ordem);
};

#endif // TIPOARVORE_H_INCLUDED

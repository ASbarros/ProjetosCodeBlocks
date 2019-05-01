#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXNUMVERTICES 100
#define MAXNUMARESTAS 4500

// TipoValorVertice é um apelido para o tipo int
typedef int TipoValorVertice;

// TipoApontador é outro apelido para o tipo int
typedef int TipoApontador;

// TipoPeso é um apelido para o tipo float
typedef float TipoPeso;

/*
 * Tipo de dado que forma o grafo
 * Campos: Matriz de adjacência,
 *         Número de vértices,
 *         Número de arestas
 * Nome: TipoGrafo
 */
typedef struct TipoGrafo
{
    TipoPeso Mat[MAXNUMVERTICES + 1] [MAXNUMVERTICES + 1];
    int NumVertices;
    int NumArestas;
} TipoGrafo;

/*
 * Faz a matriz de adjacência receber o valor zero
 * Parâmetros: ponteiro para o Grafo
 * Retorno: vazio
 */
void FGVazio(TipoGrafo *Grafo)
{
    short i, j;
    for ( i = 0; i <= Grafo->NumVertices; i++)
    {
        for ( j = 0; j <=Grafo->NumVertices; j++)
        {
            Grafo->Mat[ i ] [ j ] = 0;
        }
    }
}

/*
 * Insere uma aresta entre um par de vértice do grafo
 * Parâmetros: ponteiros V1, V2, Peso e Grafo
 * Retorno: vazio
 */
void InsereAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoPeso *Peso,
                  TipoGrafo *Grafo)
{
    Grafo->Mat[*V1] [*V2] = *Peso;
}

/*
 * Verifica se existe aresta entre um par de vértice do grafo
 * Parâmetros: Vertice1, Vertice2, Ponteiro para o Grafo
 * Retorna 1 se existe aresta entre esse par de vértice
 */
short ExisteAresta(TipoValorVertice Vertice1,
                   TipoValorVertice Vertice2,
                   TipoGrafo *Grafo)
{
    if(Grafo->Mat[Vertice1] [Vertice2] > 0)
        return 1;
    else
        return 0;
}

/*
 * Verifica se a lista de adjacentes de vértice está vazia
 * Parâmetros: ponteiro para o vértice,
 *             ponteiro para o Grafo
 * Retorna 1 se a lista de adjacência do vértice for vazia
 */
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo)
{

    TipoApontador Aux = 0;
    while (Aux < Grafo->NumVertices)
    {
        if (Grafo->Mat[*Vertice] [Aux] > 0)
        {
            return 0;
        }
        Aux++;
    }
    return 1;
}


/*
 * Obtem o primeiro vizinho da lista de adjacentes do vértice
 * Parâmetros: ponteiro para o vértice,
 *             ponteiro para o Grafo
 * Retorna -1 se a lista de adjacentes estiver vazia
 */
TipoApontador PrimeiroListaAdj (TipoValorVertice *Vertice, TipoGrafo *Grafo)
{

    TipoApontador Aux = 0;
    while (Aux < Grafo->NumVertices)
    {
        if (Grafo->Mat[*Vertice] [Aux] > 0)
        {
            return Aux;
        }
        Aux++;
    }
    printf ( "Erro : Lista adjacencia vazia (PrimeiroListaAdj ) \n" ) ;
    return -1;
}

/*
 * Remove a aresta do par de vértice indicado
 * Parâmetros: ponteiros para os vértices de origem e destino,
 *             ponteiro para o Grafo
 * Retorno: sem retorno
 */
void RetiraAresta(TipoValorVertice *V1,
                  TipoValorVertice *V2,
                  TipoGrafo *Grafo)
{
    if (Grafo->Mat[*V1] [*V2] == 0)
        printf ( "Aresta nao existe \n" );
    else
    {
        Grafo->Mat[*V1] [*V2] = 0;
    }
}

/*
 * Libera a alocação dinâmica de memória utilizada
 * Parâmetros: ponteiro para o Grafo
 * Retorno: sem retorno
 */
void LiberaGrafo(TipoGrafo *Grafo)
{
    // Nao faz nada no caso de matrizes de adjacencia
}

/*
 * Imprime na tela a matriz de adjacência do grafo
 * Parâmetros: ponteiro para o Grafo
 * Retorno: sem retorno
 */
void ImprimeGrafo(TipoGrafo *Grafo)
{
    short i, j;
    printf("\n\t\t Matriz de adjacencia do grafo: \n\n");
    printf( " " );

    // imprime as colunas da matriz
    for ( i = 1; i <= Grafo->NumVertices; i ++)
    {
        printf ( "  %3d", i );
    }
    printf (" \n") ;
    //imprime as linhas
    for ( i = 1; i <= Grafo->NumVertices; i++)
    {
        printf ("%3d", i );
        // imprime o valor contido na matriz
        for ( j = 1; j <=Grafo->NumVertices; j++)
        {
            //imprime o valor contido na matriz
            printf ( "%5.1f", Grafo->Mat[ i ] [ j ] );
        }
        printf ( " \n" ) ;
    }
    printf ( " \n" ) ;

}

/*
 * Pega o grafo no arquivo texto: dados.txt e coloca na matriz de adjacência
 * Parâmetros: ponteiro para o Grafo
 * Retorno: sem retorno
 */
void carregaDeArquivo(TipoGrafo *grafo)
{

    FILE *arq = fopen("texte.txt", "r");
    int numVertices, numArestas;

    // testa se o arquivo foi aberto com sucesso
    if(arq != NULL)
    {
        printf("\n\t\t Arquivo aberto: \n\n");
        fscanf(arq,"%d", &numVertices);
        fscanf(arq,"%d ", &numArestas);

        //printf("%d, %d \n",numVertices, numArestas);

        grafo->NumVertices = numVertices;
        grafo->NumArestas = numArestas;
        FGVazio(grafo);
        TipoValorVertice ori, dest;
        TipoPeso peso;
        while (!feof(arq))
        {
            fscanf(arq,"%d ", &ori);
            fscanf(arq,"%f ", &peso);
            fscanf(arq,"%d ", &dest);
            InsereAresta(&ori, &dest, &peso, grafo);
            printf("%d %5.2f %d \n", ori, peso, dest);
        }
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1);
    }
}

short grau(TipoValorVertice pVertice, TipoGrafo *Grafo)
{
    short countGraus = 0;
    for(int aux = 1; aux <= Grafo->NumVertices; aux++)
    {
        if(Grafo->Mat[pVertice] [aux] > 0)
            countGraus++;
    }
    return countGraus;
}

bool verticeDesconexo(TipoValorVertice pVertice, TipoGrafo *Grafo)
{
    if(grau(pVertice, Grafo)==0)
        return true;
    else
        return false;

}

int  somaDosGrausGrafo(TipoGrafo *Grafo)
{
    int aux = 0;
    for(int i = 1; i<= Grafo->NumVertices; i++)
    {
        aux += grau(i,Grafo);
    }
    return aux;
}
bool grafoSimples(TipoGrafo *Grafo)
{

    for(int aux = 1; aux <= Grafo->NumVertices; aux++)
    {
        for(int aux2 = 1; aux<= Grafo->NumVertices; aux2++)
        {
            if(aux == aux2 && Grafo->Mat[aux][aux2] == 1)
                return false;

            else if (aux != aux2 && Grafo->Mat[aux][aux2] > 1)
                return false;

        }
    }
    return true;
}

int verticeMaisConectado(TipoGrafo *Grafo)
{
    short maior = 0;
    int aux=0;
    int aux2 = 0;
    int aux3 = 0;
    while(aux<Grafo->NumVertices)
    {
        aux2 = 	grau(aux, Grafo);

        if (aux2 > maior)
        {
            maior = aux2;
            aux3 = aux;
        }
        aux++;
    }
    return aux3;
}
bool grafoCompleto(TipoGrafo *Grafo)
{
    for(int i = 1; i<=Grafo->NumVertices; i++)
    {
        for (int j = 1; j<=Grafo->NumVertices; j++)
        {
            if(i!=j && Grafo->Mat[i][j] == 0)
                return false;

            else if (i==j && Grafo->Mat[i][j] == 1)
                return false;

        }
    }
    return true;
}
TipoGrafo complementoGrafo(TipoGrafo *grafo){
    //o complemento de um grafo eh onde existe uma aresta em um grafo
    //o seu complemento nao vai ter, e onde nao existir aresta em um grafo
    //o seu complemento vai ter...
    TipoGrafo aux;
    carregaDeArquivo(&aux);
    for(int i = 1;i<=grafo->NumVertices; i++){
        for(int j = 1; j <= grafo->NumVertices; j++){
            if(i != j && grafo->Mat[i][j] == 0){
                aux.Mat[i][j] = 1;
            }
        }
    }
    return aux;
}
int QtdeVertGrauImpar(TipoGrafo *grafo){
    int aux = 0;
    int indice = 1;
    while(indice <= grafo->NumVertices){
        if(grau(indice,grafo)%2 == 1)
            aux++;
        indice++;
    }
    return aux;
}
/*
 * Função principal do programa
 * Chamada pelo Sistema Operacional
 * Retorno: 0
 */
int main(int argc, char *argv[])
{

    TipoGrafo grafo;
    int  valor = 5;
    int *v;
    v = &valor;
    carregaDeArquivo(&grafo);
    ImprimeGrafo( &grafo );
    printf("Lista adjacencia Vazia? %d\n\n",ListaAdjVazia(v, &grafo));
    printf("Primeiro lista adjacencia do %d eh o %d\n\n",valor,PrimeiroListaAdj(v, &grafo));
    std::cout<< "Valor: "<<  grau(2,&grafo);
    //system("PAUSE");
    return 0;
}



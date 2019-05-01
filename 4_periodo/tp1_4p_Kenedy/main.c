#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *arquivo;
    float Vp = 0, valor, somatorio = 0, Eabs = 0, Erel = 0, menor_erro, valor_correspondente;
    int indice = 0;
    short inicial = 0;
    int contador = 0, cont = 0;//a posiçao do valor...

    arquivo = fopen("valores.txt", "rt");
    if(arquivo != NULL)
    {
        fscanf(arquivo,"%f", &valor);//lê a primeira linha do arquivo...
        while(!feof(arquivo)) //enquanto nao for o fim do arquivo...
        {
            indice++;
            somatorio += valor;
            fscanf(arquivo, "%f", &valor);//lê a segundo linha ate a ultima...
        }
        fclose(arquivo);
        Vp = somatorio/indice;
        arquivo = fopen("valores.txt", "rt");
        if(arquivo != NULL)
        {
            fscanf(arquivo, "%f", &valor);//lê a segundo linha ate a ultima...
            while(!feof(arquivo)) //enquanto nao for o fim do arquivo...
            {
                contador++;
                Eabs = Vp - valor;
                if(Eabs < 0)//erro absoluto eh sempre em modulo...
                    Eabs = Eabs * -1;

                Erel = Eabs/Vp;//calculo do erro relativo...
                if(inicial == 0){//se for a primeira iteraçao...
                    inicial = 1;
                    menor_erro = Erel;
                    valor_correspondente = valor;
                    cont = contador;
                }
                else if(menor_erro > Erel){
                    menor_erro = Erel;
                    valor_correspondente = valor;
                    cont = contador;
                }

                fscanf(arquivo, "%f", &valor);//lê a segundo linha ate a ultima...
            }
        }
        menor_erro = menor_erro *100;
        printf("Menor erro absoluto: %f%% \nValor correspondente: %.3f\nposicao de valor: %d", menor_erro, valor_correspondente, cont);
    }
    return 0;
}

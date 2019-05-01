#include <iostream>

using namespace std;

struct Folha
{
    float Largura;
    float Altura;
};

//derivada da fun�ao de bisses�ao...
float Derivada(float x)
{
    return 2080 - 368*x + 12*x*x;
}
//fun�ao de bissescao...
float Bissescao(float x)
{
    return 2080*x - 184*x*x +4*x*x*x;
}

int main()
{
    //variaveis...
    float valorInicial = 0, valorfinal = 20;//intervalo da fun�ao...
    float media,e = 0.001,mediaAnterior;

    media = (valorInicial + valorfinal)/2;//inicializando a media...

    //loop de intera�oes...
    for(int i = 0; ; i++)
    {

        //salvando a media anterior, para futuras compara�oes...
        mediaAnterior = media;

        //atualizando a media...
        media = (valorInicial + valorfinal)/2;

        //se a fun�ao no ponto da media for menor ou igual ao meu erro confideravel...
        if(Bissescao(media) <= e)
            break;

        //se a fun�ao de bisses�ao passando o valor incial vezes a funcao de besses�ao passando a media for menor
        //que zero, quer dizer que tem uma raiz entre esses dois valores
        //entao o valor final atualiza para a media...
        if(Bissescao(valorInicial)*Bissescao(media) < 0)
            valorfinal = media;

        //caso contrario, nao tem raiz entre esses dois pontos
        //valor inicial recebe a media...
        else
            valorInicial = media;

        //tem que ser em modulo...
        float aux = ((media - mediaAnterior)/media);
        if(aux < 0 )
            aux *= -1;

        if(aux <= e)
            break;
    }

    return 0;
}

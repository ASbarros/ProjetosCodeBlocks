#include <iostream>
#include <string>
using namespace std;

int main()
{
    int valor;
    string frase;
    char vetor_fixo[36];

    vetor_fixo[0] = 'a';vetor_fixo[1]='b';vetor_fixo[2]='c';vetor_fixo[3]='d';vetor_fixo[4]='e';vetor_fixo[5]='f';vetor_fixo[6]='g';vetor_fixo[7]='h';vetor_fixo[8]='i';vetor_fixo[9]='j';
    vetor_fixo[10]='k';vetor_fixo[11]='l';vetor_fixo[12]='m';vetor_fixo[13]='n';vetor_fixo[14]='o';vetor_fixo[15]='p';vetor_fixo[16]='q';vetor_fixo[17]='r';vetor_fixo[18]='s';
    vetor_fixo[19]='t';vetor_fixo[20]='u';vetor_fixo[21]='v';vetor_fixo[22]='w';vetor_fixo[23]='x';vetor_fixo[24]='y';vetor_fixo[25]='z';vetor_fixo[26]='0';vetor_fixo[27]='1';
    vetor_fixo[28]='2';vetor_fixo[29]='3';vetor_fixo[30]='4';vetor_fixo[31]='5';vetor_fixo[32]='6';vetor_fixo[33]='7';vetor_fixo[34]='8';vetor_fixo[35]='9';

    cin >> valor;
    getline(cin,frase);

    char vet[frase.size()];

    for(int i = 0; i<frase.size(); i++){
       vet[i] = frase[i];
       cout << vet[i];
    }

    return 0;
}

#include <iostream>

using namespace std;
const int tamanho = 100;//variavel global para o tamanho da pilha...

typedef char TipoItem;//para ajudar na manutençao do codigo...

typedef struct {//estrutura da pilha
  int topo;//toda pilha tem um topo
  TipoItem item[tamanho];//e um vetor ...
} PILHA;

void Pilha_Inicializa(PILHA *p){
    p->topo = -1;
}
bool Pilha_Cheia(PILHA *p){
    if(p->topo == tamanho - 1)
        return true;
    else
        return false;
}

bool Pilha_Vazia(PILHA *p){
    if(p->topo == - 1)
        return true;
    else
        return false;
}
//retorna o valor do topo da pilha...
TipoItem Pilha_ValorTopo(PILHA *p){
    return p->item[p->topo];
}
//para inserir elemento...
bool Pilha_Push(TipoItem valor, PILHA *p){
    if(Pilha_Cheia(p))//se a pilha estiver cheia, nao tenho como inserir...
        return false;
    else{
        p->topo++;
        p->item[p->topo] = valor;
        return true;//elemento inserido...
    }
}
//removendo elemento...
void Pilha_Pop(PILHA *p){
    if(!Pilha_Vazia(p)){
        p->topo--;//elemento removido...

    }
}
bool Verifica(string frase, int *status){
    PILHA aux;
    Pilha_Inicializa(&aux);
    if(frase.size() == 0){//se a string for vazia...
        *status = 1;
        return true;
    }
    for(int i = 0;i<frase.size(); i++){
        if(frase[i] == '(' || frase[i] == ')' || frase[i] == '[' || frase[i] == ']'){//considerando apenas parenteses e cochetes...
            if(frase[i] == '(' || frase[i] == '['){
                Pilha_Push(frase[i], &aux);
            }
            else
                if(frase[i] == ')'){
                    if(Pilha_ValorTopo(&aux) == '['){
                        *status = 2;
                        return false;
                    }
                    Pilha_Pop(&aux);
                }
                else
                    if(frase[i] == ']'){
                        if(Pilha_ValorTopo(&aux) == '('){
                            *status = 3;
                            return false;
                        }
                    Pilha_Pop(&aux);
                }
        }
    }
    if(!Pilha_Vazia(&aux)){
        *status = 4;
        return false;
    }
    else
        return true;
}

int main()
{
    string Frase;
    cin >> Frase;
    int Status = 0;
    bool aux = Verifica(Frase, &Status);

    if(aux){
        cout << "valida" << Status;
    }
    else
        cout << "invalida" << Status;

    return 0;
}

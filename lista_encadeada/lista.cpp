#include "lista.h"

Lista::Lista() {
    tamAtual = 0;
    cabeca = NULL;
}

bool Lista::vazia() {
    return tamAtual == 0;
}

int Lista::tamanho() {
    return tamAtual;
}

void Lista::modifica(int pos, int valor) {

    if(pos >= 1 && pos <=tamAtual){
        No *aux = cabeca;
        for(int i=1; i<pos;i++){
            aux = aux->proximo;
        }
        aux->conteudo = valor;
    }else{
        cout << "Modificacao de " << valor << " na posicao " << pos << "invalida" << endl;
    }
}

void Lista::insere(int pos, int valor) {

    if(pos == 1){ // Inserção no início
        No *novono = new No();
        novono->conteudo = valor;
        novono->proximo = cabeca;
        cabeca = novono;
        tamAtual++;
    }else if(pos == tamAtual+1){ // Inserção no final
        No *novono = new No();

        No*aux = cabeca;
        while (aux->proximo!= NULL){
            aux = aux->proximo;
        }
        aux->proximo = novono;
        novono->conteudo = valor;
        novono->proximo = NULL;
        tamAtual++;
    }else if(pos>1 && pos<=tamAtual){ // Inserção no meio
        No *novono = new No();
        No *aux = cabeca;
        for (int i = 1; i < pos - 1; i++) {
            aux = aux->proximo;
        }
        novono->proximo = aux->proximo;
        novono->conteudo = valor;
        aux->proximo = novono;
        tamAtual++;
    }else{
        cout << "Insercao invalida de " << valor << " na posicao " << pos << endl;
    }

}

void Lista::remove(int pos) { 
    if (pos == 1){
        No *aux = cabeca;
        cabeca = cabeca->proximo;
        delete aux;
        tamAtual--;
    }else if(pos<=tamAtual && pos > 1){

        No *ant, *atual;
        atual = cabeca;
        int cont = 1;
        while(cont < pos && atual!= NULL){
            ant = atual;
            atual = atual->proximo;
            cont ++;
        }
        ant->proximo = atual->proximo;
        delete atual;
        tamAtual--;
    }else{
        cout << "Posicao de remocao invalida: " << pos << endl;
    }
}

void Lista::imprime() {
    No *aux = cabeca;
    for (int i = 0; i < tamAtual; i++) {
        cout << aux->conteudo << " ";
        aux = aux->proximo;
    }
    cout << endl;
}


#include "lista.h"

Lista::Lista() {
    tamMax = 100;
    tamAtual = 0;
}

bool Lista::vazia() {
    return tamAtual == 0;
}

bool Lista::cheia() {
    return tamAtual == tamMax;
}

int Lista::tamanho() {
    return tamAtual;
}

void Lista::modifica(int pos, int valor) {
    int num = lista[pos-1];
    cout << "Modificando " << num << " para " << valor << " na posicao " << pos << endl;
    pos -= 1;
    if (pos >= 0 && pos < tamAtual) {
        lista[pos] = valor;
    }
}

void Lista::insere(int pos, int valor) {

    cout << "Inserindo " << valor << " na posicao " << pos << endl;

    if (pos > 0 && pos <= (tamAtual+1)) {
        for (int i = tamAtual; i >= pos; i--) {
            lista[i] = lista[i - 1];
            imprime();
        }
        lista[pos-1] = valor;
        tamAtual++;
    }
}

int Lista::remove(int pos) {
    int valor = lista[pos-1];
    cout << "Removendo " << valor <<  " da posicao " << pos << endl;
    pos -= 1;

    if (pos >= 0 && pos < tamAtual) {
        
        for (int i = pos; i < tamAtual - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamAtual--;
        return valor;
    }
    return -1;
}

void Lista::imprime() {
    for (int i = 0; i < tamAtual; i++) {
        cout << lista[i] << " ";
    }
    cout << endl;
}


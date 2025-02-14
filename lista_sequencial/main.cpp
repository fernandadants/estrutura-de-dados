#include "lista.h"

int main() {
    Lista l;
    l.insere(1, 10);
    l.insere(2, 20);
    l.insere(2, 30);
    l.insere(3, 40);
    l.insere(4, 50);
    l.imprime();
    l.remove(2);
    l.imprime();
    l.modifica(1, 25);
    l.imprime();
    return 0;
}
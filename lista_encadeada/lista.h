#include "no.h"

class Lista
{

private:
    No* cabeca;
    int tamAtual;

public:
    Lista();
    bool vazia();
    int tamanho();
    void modifica(int pos, int valor);
    void insere(int pos, int valor);
    void remove(int valor);
    void imprime();
};
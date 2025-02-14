#include <iostream>
#include <string>

using namespace std;

class Lista
{

private:
    int tamMax;
    int tamAtual;
    int lista[100];

public:
    Lista();
    bool vazia();
    bool cheia();
    int tamanho();
    void modifica(int pos, int valor);
    void insere(int pos, int valor);
    int remove(int valor);
    void imprime();
};
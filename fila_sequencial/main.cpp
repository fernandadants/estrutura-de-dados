#include "fila.h"

int main(){
    Fila f;
    f.imprime();
    f.insere(5);
    f.insere(3);
    f.imprime();
    cout << "Remove: " << f.remove() << endl;
    f.insere(8);
    f.imprime();
}
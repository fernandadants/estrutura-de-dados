#include "grafo.h"
#include <iostream>

int main() {

    int v;

    ifstream file("pcv4.txt");
    if(!file.is_open()){
        cout << "Erro ao abrir o arquivo\n";
    }

    file >> v;

    file.close();

    cout << "Numero de vertices do arquivo " << v;

    Grafo g(v); 
    
    // Carrega do arquivo
    g.carregarArquivo("pcv4.txt");
    
    cout << "BFS comecando do vertice 0:" << endl;
    g.BFS(0);
    
    cout << "\nDFS (recursivo) comecando do vertice 0:" << endl;
    g.DFS(0);
    
    cout << "\nDFS (iterative) comecando do vertice 0:" << endl;
    g.DFS_Interativo(0);
    
    cout << "\nTestando trajetos:" << endl;
    g.imprimirRota(0, 2);
    g.imprimirRota(0, 3);
    
    return 0;
}
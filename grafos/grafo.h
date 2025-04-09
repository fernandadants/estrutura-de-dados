#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Grafo{
    private:
        int vertices;
        vector<vector<int>> adjMatriz;
        vector<vector<int>> adjLista;
        vector<int> BFSUtili(int start);

    public:

        Grafo(int v);
        void addVertice(int v, int w);
        void carregarArquivo(const string &filename);
        void BFS(int start);
        void imprimirRota(int start, int end);
        void DFS(int start);
        void dfsUtil(int vertice, std::vector<bool>& visited);
        void DFS_Interativo(int start);
};

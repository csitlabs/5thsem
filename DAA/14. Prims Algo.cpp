//14. Prims algorithm

#include <iostream>

using namespace std;

// Function to find the vertex with the minimum key value
int findMinKeyVertex(int V, int* key, bool* mstSet) {
    int minKey = INT_MAX, minVertex;
    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Function to print the Minimum Spanning Tree
void printMST(int V, int* parent, int** graph) {
    cout << "Minimum Spanning Tree edges:" << endl;
    for (int v = 1; v < V; ++v)
        cout << parent[v] << " - " << v << " : " << graph[v][parent[v]] << endl;
}

// Function to find the MST using Prim's algorithm
void primMST(int V, int** graph) {
    int* parent = new int[V];
    int* key = new int[V];
    bool* mstSet = new bool[V];

    // Start with the first vertex as the root
    key[0] = 0;
    parent[0] = -1;
    for (int v = 1; v < V; ++v) {
        key[v] = INT_MAX;
        mstSet[v] = false;
    }

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKeyVertex(V, key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(V, parent, graph);

    delete[] parent;
    delete[] key;
    delete[] mstSet;
}

int main() {
    int V; // V is the number of vertices
    cout << "Prims Algorithm" << endl;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int** graph = new int*[V];
    for (int i = 0; i < V; ++i)
        graph[i] = new int[V];

    cout << "Enter the graph matrix (enter 0 for no edge, positive value for edge weight):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];
    }

    primMST(V, graph);

    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;

    return 0;
}



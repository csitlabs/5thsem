//13. Kruskals Algo

#include <iostream>

using namespace std;

const int MAX_NODES = 100;  // Adjust as needed
const int MAX_EDGES = 1000; // Adjust as needed

struct Edge {
    int src, dest, weight;
};

// Find function for Union-Find
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Union function for Union-Find
void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (xroot != yroot) {
        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }
}

void kruskal(Edge edges[], int edgeCount, int nodeCount) {
    Edge result[MAX_NODES];
    int parent[MAX_NODES];
    int rank[MAX_NODES] = {0};

    // Initialize the parent array and rank
    for (int i = 0; i < nodeCount; ++i) {
        parent[i] = i;
    }

    // Sort edges based on weight (simple bubble sort for demonstration)
    for (int i = 0; i < edgeCount - 1; ++i) {
        for (int j = 0; j < edgeCount - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int e = 0;  // Count of edges in MST
    int i = 0;  // Initial index of sorted edges

    while (e < nodeCount - 1 && i < edgeCount) {
        Edge nextEdge = edges[i++];
        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            unionSets(parent, rank, x, y);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int minimumCost = 0;
    for (int i = 0; i < e; ++i) {
        cout << result[i].src << " - " << result[i].dest << ": " << result[i].weight << endl;
        minimumCost += result[i].weight;
    }
    cout << "Minimum Cost: " << minimumCost << endl;
}

int main() {
    int nodeCount, edgeCount;
	cout << "Kruskals Algorithm" << endl;
    cout << "Enter number of nodes: ";
    cin >> nodeCount;

    cout << "Enter number of edges: ";
    cin >> edgeCount;

    Edge edges[MAX_EDGES];

    cout << "Enter edges (source, destination, weight):" << endl;
    for (int i = 0; i < edgeCount; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskal(edges, edgeCount, nodeCount);

    return 0;
}


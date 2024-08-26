//15. Dijkstras algorithm

#include <iostream>

using namespace std;

const int INF = 1e9;

// Function to find the vertex with the minimum distance value
int findMinDistVertex(int V, int* dist, bool* visited) {
    int minDist = INF, minVertex;
    for (int v = 0; v < V; ++v) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}

// Function to print the shortest path from source to all vertices
void printShortestPath(int V, int* parent, int* dist, int src) {
    cout << "Shortest Path from vertex " << src << " to all vertices:" << endl;
    for (int v = 0; v < V; ++v) {
        cout << "Vertex " << v << " - Distance: " << dist[v] << " - Path: ";
        int node = v;
        while (node != src) {
            cout << node << " <- ";
            node = parent[node];
        }
        cout << src << endl;
    }
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int V, int** graph, int src) {
    int* dist = new int[V];
    int* parent = new int[V];
    bool* visited = new bool[V];

    // Initialize distance and parent arrays
    for (int v = 0; v < V; ++v) {
        dist[v] = INF;
        parent[v] = -1;
        visited[v] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinDistVertex(V, dist, visited);
        visited[u] = true;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printShortestPath(V, parent, dist, src);

    delete[] dist;
    delete[] parent;
    delete[] visited;
}

int main() {
    int V; // V is the number of vertices
    cout << "Dijkstra's Algorithm" << endl;
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

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(V, graph, src);

    for (int i = 0; i < V; ++i)
        delete[] graph[i];
    delete[] graph;

    return 0;
}



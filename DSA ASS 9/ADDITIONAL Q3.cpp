#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

class Graph {
private:
    int V;
    vector<Edge> edges;

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back(Edge(u, v, weight));
    }

    // Find parent with path compression
    int findParent(vector<int>& parent, int i) {
        if (parent[i] != i) {
            parent[i] = findParent(parent, parent[i]);
        }
        return parent[i];
    }

    
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

    
    void kruskalMST() {
        vector<Edge> result;
        vector<int> parent(V);
        vector<int> rank(V, 0);

        // Initialize parent array
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        int e = 0;
        int i = 0;

        while (e < V - 1 && i < edges.size()) {
            Edge nextEdge = edges[i++];

            int x = findParent(parent, nextEdge.u);
            int y = findParent(parent, nextEdge.v);

            if (x != y) {
                result.push_back(nextEdge);
                unionSets(parent, rank, x, y);
                e++;
            }
        }

        cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
        int totalWeight = 0;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i].u << " - " << result[i].v << " : " << result[i].weight << endl;
            totalWeight += result[i].weight;
        }
        cout << "Total weight: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    cout << "\n";
    g.kruskalMST();

    return 0;
}
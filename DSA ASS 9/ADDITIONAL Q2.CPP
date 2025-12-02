#include <iostream>
#include <vector>
#include <list>
#include <climits>

using namespace std;

class Graph {
private:
    int V;
    vector<list<pair<int, int>>> adjList; // pair<destination, weight>

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight)); 
    }

    // Prim's Algorithm for Minimum Spanning Tree
    void primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, inMST);
            inMST[u] = true;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->first;
                int weight = it->second;

                if (!inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
            }
        }

        cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total weight: " << totalWeight << endl;
    }

    int minKey(vector<int>& key, vector<bool>& inMST) {
        int min = INT_MAX, minIndex;

        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
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
    g.primMST();

    return 0;
}
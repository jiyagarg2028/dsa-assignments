#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
private:
    int V;
    vector<list<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // DFS using recursion
    void DFSRecursive(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal (Recursive) starting from " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }

    void DFSUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    // DFS using iteration (stack)
    void DFSIterative(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);
        cout << "DFS Traversal (Iterative) starting from " << start << ": ";

        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";

                // Push all unvisited neighbors
                for (auto it = adjList[u].rbegin(); it != adjList[u].rend(); it++) {
                    int v = *it;
                    if (!visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }

    // Count connected components
    int countConnectedComponents() {
        vector<bool> visited(V, false);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
                count++;
            }
        }

        return count;
    }

    // Check for cycle in undirected graph
    bool hasCycleUndirected() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (hasCycleUtil(i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasCycleUtil(int u, int parent, vector<bool>& visited) {
        visited[u] = true;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                if (hasCycleUtil(v, u, visited)) {
                    return true;
                }
            } else if (v != parent) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    g.DFSRecursive(start);
    g.DFSIterative(start);

    cout << "\nNumber of connected components: " << g.countConnectedComponents() << endl;
    cout << "Graph has cycle: " << (g.hasCycleUndirected() ? "Yes" : "No") << endl;

    return 0;
}
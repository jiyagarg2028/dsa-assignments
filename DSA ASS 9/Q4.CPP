#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

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
        adjList[u].push_back(v); // Directed graph
    }

    // Topological Sort using DFS
    void topologicalSort() {
        stack<int> s;
        vector<bool> visited(V, false);

        // Perform DFS for all unvisited vertices
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, s);
            }
        }

        cout << "Topological Sort: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void topologicalSortUtil(int u, vector<bool>& visited, stack<int>& s) {
        visited[u] = true;

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (!visited[v]) {
                topologicalSortUtil(v, visited, s);
            }
        }

        s.push(u);
    }

    // Check if graph has cycle (for directed graph)
    bool hasCycleDirected() {
        vector<int> color(V, 0); // 0: white, 1: gray, 2: black

        for (int i = 0; i < V; i++) {
            if (color[i] == 0) {
                if (hasCycleUtil(i, color)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasCycleUtil(int u, vector<int>& color) {
        color[u] = 1; // Mark as gray (being processed)

        for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
            int v = *it;
            if (color[v] == 1) { // Back edge found
                return true;
            }
            if (color[v] == 0 && hasCycleUtil(v, color)) {
                return true;
            }
        }

        color[u] = 2; // Mark as black (processed)
        return false;
    }

    // Kahn's Algorithm for Topological Sort (using in-degree)
    void topologicalSortKahn() {
        vector<int> inDegree(V, 0);
        queue<int> q;
        vector<int> result;

        // Calculate in-degree of each vertex
        for (int u = 0; u < V; u++) {
            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                inDegree[*it]++;
            }
        }

        // Enqueue vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            count++;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = *it;
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (count != V) {
            cout << "Graph has cycle! Topological sort not possible." << endl;
        } else {
            cout << "Topological Sort (Kahn's Algorithm): ";
            for (int i = 0; i < result.size(); i++) {
                cout << result[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v) for directed graph:" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycleDirected()) {
        cout << "\nGraph contains cycle! Topological sort not possible." << endl;
    } else {
        cout << "\n";
        g.topologicalSort();
        g.topologicalSortKahn();
    }

    return 0;
}
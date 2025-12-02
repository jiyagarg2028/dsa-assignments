#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
        adjList[v].push_back(make_pair(u, weight)); // For undirected graph
    }

    // Dijkstra's Algorithm for shortest path
    void dijkstra(int start) {
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->first;
                int weight = it->second;

                if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        cout << "Shortest distances from vertex " << start << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (distance[i] == INT_MAX) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << distance[i] << endl;
            }
        }
    }

    // Shortest path with path reconstruction
    void shortestPath(int start, int end) {
        vector<int> distance(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            if (u == end) break;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); it++) {
                int v = it->first;
                int weight = it->second;

                if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        if (distance[end] == INT_MAX) {
            cout << "No path exists from " << start << " to " << end << endl;
        } else {
            cout << "Shortest distance from " << start << " to " << end << ": " << distance[end] << endl;
            cout << "Path: ";
            vector<int> path;
            int current = end;
            while (current != -1) {
                path.push_back(current);
                current = parent[current];
            }
            for (int i = path.size() - 1; i >= 0; i--) {
                cout << path[i];
                if (i > 0) cout << " -> ";
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

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int start;
    cout << "\nEnter source vertex: ";
    cin >> start;
    g.dijkstra(start);

    int end;
    cout << "\nEnter destination vertex: ";
    cin >> end;
    g.shortestPath(start, end);

    return 0;
}
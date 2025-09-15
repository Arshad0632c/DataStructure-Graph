SOURCE CODE:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, int n, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; ++i) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    vector<bool> visited(n, false);

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];

    cout << "BFS Order: ";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            BFS(i, n, adj, visited);
        }
    }

    cout << endl;
    return 0;
}


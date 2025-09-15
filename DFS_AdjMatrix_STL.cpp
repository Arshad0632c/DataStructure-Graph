
SOURCE CODE:

#include <iostream>
#include <vector>
using namespace std;

void DFS(int v, int n, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i, n, adj, visited);
        }
    }
}

void inputGraphMatrix(int n, vector<vector<int>>& adj) {
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
}

void printMatrix(int n, const vector<vector<int>>& adj) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0)); // Adjacency matrix
    vector<bool> visited(n, false);                // Visited array

    inputGraphMatrix(n, adj);
    printMatrix(n, adj);

    cout << "DFS Order: ";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, n, adj, visited);
        }
    }

    cout << endl;
    return 0;
}


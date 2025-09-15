
SOURCE CODE:

#include <iostream>
using namespace std;

int visited[100] = {0}, adj[100][100] = {0};

void DFS(int v, int n) {
    visited[v] = 1;
    cout << v << " ";
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i, n);
        }
    }
}

void Graph_Matrix(int n) {
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
}

void printMatrix(int n) {
    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

void Directed_Graph_Edges() {
    int choice, v1, v2;
    while (true) {
        cout << "Enter the adjacent vertices: ";
        cin >> v1 >> v2;
        adj[v1][v2] = 1;
        cout << "Continue? (1/0): ";
        cin >> choice;
        if (choice == 0)
            break;
    }
}

void Undirected_Graph_Edges() {
    int choice, v1, v2;
    while (true) {
        cout << "Enter the adjacent vertices: ";
        cin >> v1 >> v2;
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
        cout << "Continue? (1/0): ";
        cin >> choice;
        if (choice == 0)
            break;
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph_Matrix(n); // or use one of the below edge entry methods
    // Directed_Graph_Edges();
    // Undirected_Graph_Edges();

    printMatrix(n);

    cout << "DFS Order: ";
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0)
            DFS(i, n);
    }

    cout << endl;
    return 0;
}


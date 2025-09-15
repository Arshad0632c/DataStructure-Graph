SOURCE CODE:

#include <iostream>
using namespace std;

const int MAX = 10;
int cost[MAX][MAX];
int parent[MAX] = {0};

void Graph_Matrix(int n);
void Kruskals(int n);
int find(int i);
int uni(int i, int j);

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph_Matrix(n);
    Kruskals(n);

    return 0;
}

void Graph_Matrix(int n) {
    cout << "Enter the adjacency matrix (0 for no edge):\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Assume 999 as infinity
        }
    }
}

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void Kruskals(int n) {
    int a, b, u, v;
    int ne = 1, min, mincost = 0;

    cout << "\nThe edges of Minimum Cost Spanning Tree are:\n";
    while (ne < n) {
        min = 999;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            cout << ne << " edge (" << a << "," << b << ") = " << min << endl;
            mincost += min;
            ne++;
        }

        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    cout << "\nMinimum cost = " << mincost << endl;
}


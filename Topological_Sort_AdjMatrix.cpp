
SOURCE CODE:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void inputGraphMatrix(int n, vector<vector<int>>& adj) {
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> adj[i][j];
}

vector<int> calculateIndegree(int n, const vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (adj[i][j] == 1)
                indegree[j]++;
    return indegree;
}

void printIndegree(const vector<int>& indegree) {
    cout << "Index   Value\n";
    for (int i = 0; i < indegree.size(); ++i)
        cout << i << "\t" << indegree[i] << endl;
}

void topologicalSort(int n, vector<vector<int>> adj) {
    vector<int> indegree = calculateIndegree(n, adj);
    printIndegree(indegree);

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    cout << "Topological Order: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < n; ++i) {
            if (adj[node][i] == 1) {
                adj[node][i] = 0;
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    inputGraphMatrix(n, adj);
    topologicalSort(n, adj);

    return 0;
}


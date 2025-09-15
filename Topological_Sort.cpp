
SOURCE CODE:

#include <iostream>
using namespace std;

int front = -1, rear = -1, queueArr[100];
int visited[100] = {0}, adj[100][100] = {0}, indegree[100] = {0};

void enqueue(int ele) {
    if (rear == -1 && front == -1)
        front = rear = 0;
    else
        rear++;
    queueArr[rear] = ele;
}

int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Cannot Dequeue\n";
        return -1;
    } else {
        return queueArr[front++];
    }
}

void inputGraphMatrix(int n) {
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> adj[i][j];
}

void computeIndegree(int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (adj[i][j] == 1)
                indegree[j]++;
    
    cout << "Index   Value\n";
    for (int i = 1; i <= n; i++)
        cout << i << "\t" << indegree[i] << endl;
}

void topologicalSort(int n) {
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            enqueue(i);

    cout << "Topological Order: ";
    while (front <= rear) {
        int k = dequeue();
        cout << k << " ";

        for (int i = 1; i <= n; i++) {
            if (adj[k][i] == 1) {
                adj[k][i] = 0;
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    inputGraphMatrix(n);
    computeIndegree(n);
    topologicalSort(n);

    return 0;
}


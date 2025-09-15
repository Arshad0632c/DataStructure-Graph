SOURCE CODE:

#include <iostream>
using namespace std;

int front = -1, rear = -1, queue[100];
int visited[100] = {0}, adj[100][100] = {0};

void enqueue(int ele) {
    if (rear == -1 && front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = ele;
}

int dequeue() {
    int value;
    if (front == -1 || front > rear) {
        cout << "Cannot Dequeue\n";
        return -1;
    } else {
        value = queue[front];
        front++;
        return value;
    }
}

void BFS(int v, int n) {
    int i, k;
    visited[v] = 1;
    cout << v << " ";  // If you want characters: cout << char(v + 'a') << " ";
    enqueue(v);

    while (front <= rear) {
        k = dequeue();
        if (k == -1) break;
        for (i = 1; i <= n; i++) {
            if (adj[k][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                cout << i << " ";  // Or char(i + 'a')
                enqueue(i);
            }
        }
    }
}

void Graph_Matrix(int n) {
    int i, j;
    cout << "Enter the adjacency matrix:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> adj[i][j];
}

int main() {
    int i, n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph_Matrix(n);

    cout << "BFS Order: ";
    for (i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            BFS(i, n);
        }
    }

    cout << endl;
    return 0;
}


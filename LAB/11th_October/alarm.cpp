#include <iostream>
#include <windows.h>  // Include Windows-specific header for Sleep function

using namespace std;

void readGraph(int **graph, int n) {
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n]; // Allocate memory for each row
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
}

bool isSafe(int **graph, int n, int *color, int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColouringUtil(int **graph, int n, int *color, int v) {
    if (v == n) {
        return true;
    }
    for (int c = 0; c < 3; c++) {
        if (isSafe(graph, n, color, v, c)) {
            color[v] = c;
            if (graphColouringUtil(graph, n, color, v + 1)) {
                return true;
            }
            color[v] = -1;
        }
    }
    return false;
}

void graphColouring(int **graph, int n) {
    int *color = new int[n];
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    color[0] = 0;
    if (graphColouringUtil(graph, n, color, 1))
    {
        cout << "Vertex colors:" << endl;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
                cout << "Vertex " << i << " is colored with Red" << endl;
            else if (color[i] == 1)
                cout << "Vertex " << i << " is colored with Blue" << endl;
            else if (color[i] == 2)
                cout << "Vertex " << i << " is colored with Green" << endl;
        }
    }
    else
    {
        cout << "No valid coloring exists" << endl;
    }
}

void alarm(int seconds) {
    cout << "Alarm set for " << seconds << " seconds..." << endl;
    Beep(500,5000);  // Beeps for the specified seconds
    cout << "Alarm rang!" << endl;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int **graph = new int *[n];
    readGraph(graph, n);

    // Set an alarm for 5 seconds
    alarm(5);

    graphColouring(graph, n);
    return 0;
}

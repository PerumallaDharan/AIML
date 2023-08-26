// Develop two modules to traverse the nodes of a graph in levelwise from left-to-right and right-to-left.[10]
// Hint: use queue for memorization.

// Date: 23-Aug-2023
// Due: 26-Aug-2023 11.59 PM

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int edges, vertices;
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    cout << "Enter the number of vertices" << endl;
    cin >> vertices;
    int graph[vertices][vertices];
    cout << "Enter the adjacency matrix" << endl;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    queue<int> q;
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    int starting_node;
    cout << "Enter the starting node" << endl;
    cin >> starting_node;

    int traversalChoice;
    cout << "Enter 1 for Left-to-Right traversal"<<endl;
    cout << "Enter 2 for Right-to-Left traversal"<<endl;
    cin >> traversalChoice;

    q.push(starting_node);
    visited[starting_node] = 1;

    int minNodesVisited = 1;  
    int maxNodesVisited = 1;  

    while (!q.empty())
    {
        int level_size = q.size();
        maxNodesVisited += level_size - 1;  

        for (int i = level_size - 1; i >= 0; i--)
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int j = 0; j < vertices; j++)
            {
                if ((traversalChoice == 1 && graph[j][node] == 1))
                {
                    if (visited[j] == 0)
                    {
                        q.push(j);
                        visited[j] = 1;
                        minNodesVisited++;
                    }
                }
                else if (traversalChoice == 2 && graph[node][j] == 1)
                {
                    for (int k = vertices - 1; k >= 0; k--)
                    {
                        if (graph[node][k] == 1 && visited[k] == 0)
                        {
                            q.push(k);
                            visited[k] = 1;
                            minNodesVisited++;
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    cout << "Minimum nodes visited: " << minNodesVisited << endl;
    cout << "Maximum nodes visited: " << maxNodesVisited << endl;

    return 0;
}
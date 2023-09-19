// Implement Breadth first search and Depth first search on a particular road map of a city.
// Take road map of your own state/city. Further, improve the cost of the edges to atleast 5
// parameters as sensory inputs. [30]
// Describe the PEAS parameters of of the road map AGENT. Design an intelligent TOURIST RECOMMENDER. [30]

#include <iostream>
#include <queue>
using namespace std;

void read_matrix(int **graph, int n)
{
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n]; // Allocate memory for each row
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }
}

void print_matrix(int **graph, int n)
{
    cout << "The adjacency matrix is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

void bfs(int **graph, int s_node, int d_node, int n)
{
    bool visited[n];
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }

    queue<int> q;
    
    visited[s_node] = true;
    q.push(s_node);

    while (!q.empty())
    {
        int current_node = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            if (graph[current_node][neighbor] == 1 && !visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current_node;
                q.push(neighbor);
            }
        }
    }

    if (!visited[d_node])
    {
        cout << "No path exists "<< endl;
    }
    else
    {
        cout << "BFS traversal"<<endl;
        int shortest_path[n];
        int current = d_node;
        int path_length = 0;

        while (current != -1)
        {
            shortest_path[path_length++] = current;
            current = parent[current];
        }

        for (int i = path_length - 1; i >= 0; i--)
        {
            cout << shortest_path[i];
            if (i != 0)
                cout << " -> ";
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: " << endl;
    cin >> nodes;
    cout << "Enter the number of edges: " << endl;
    cin >> edges;

    int **graph = new int *[nodes]; 

    read_matrix(graph, nodes);
    // print_matrix(graph, nodes);
    
    int starting_node;
    cout << "Enter the starting node: " << endl;
    cin >> starting_node;

    int destination_node;
    cout << "Enter the destination node: " << endl;
    cin >> destination_node;

    bfs(graph, starting_node, destination_node, nodes);

    return 0;
}
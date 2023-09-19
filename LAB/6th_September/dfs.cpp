// Implement Breadth first search and Depth first search on a particular road map of a city.
// Take road map of your own state/city. Further, improve the cost of the edges to atleast 5
// parameters as sensory inputs. [30]
// Describe the PEAS parameters of of the road map AGENT. Design an intelligent TOURIST RECOMMENDER. [30]

#include <iostream>
#include <stack>

using namespace std;

void read_matrix(int **graph, int n)
{
    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n]; 
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

void dfs(int **graph, int s_node, int n, int d_node)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    stack<int> stack;
    stack.push(s_node);

    cout << "DFS starting from node " << s_node << ": ";

    while (!stack.empty())
    {
        int current_node = stack.top();
        stack.pop();

        if (!visited[current_node])
        {
            cout << current_node << " ";
            visited[current_node] = true;

            for (int i = 0; i < n; i++)
            {
                if (graph[current_node][i] == 1 && !visited[i])
                {
                    stack.push(i);
                }
            }
            if (current_node==d_node)
            {   
                exit(0);
            }
            
        }
    }
    cout << endl;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes" << endl;
    cin >> nodes;
    cout << "Enter the number of edges" << endl;
    cin >> edges;

    int **graph = new int *[nodes]; 
    read_matrix(graph, nodes);
    // print_matrix(graph, nodes);
    
    int starting_node;
    cout << "Enter the starting node" << endl;
    cin >> starting_node;

    int destination_node;
    cout << "Enter the destination node" << endl;
    cin >> destination_node;

    dfs(graph, starting_node, nodes, destination_node);

    return 0;
}

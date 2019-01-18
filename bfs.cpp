//Breadth First Search
//   0
//  / \\
// 1 - 2 
//     |
//   3=3
///////////
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:   
    Graph(int);
    void addEdge(int, int);
    void BFS(int);
};
    
Graph::Graph(int v) : V(v)
{
    adj = new list<int>[V];
}

void Graph::addEdge(int a, int b)
{
    adj[a].push_back(b);
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V];
    for(int i = 0; i < V; ++i)
        visited[i] = 0;

    list<int> queue;

    visited[s]=true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for(auto it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if(!visited[*it])
            {
                visited[*it] = true;
                queue.push_back(*it);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    
    int start = 2;
    cout << "Start BFS node " << start << endl;
    g.BFS(start);

    return 0;
}
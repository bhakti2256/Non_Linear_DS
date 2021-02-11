//Program to identify Cyclic Graph
/*
 For undirected graph  
 A graph contains cycle if there is more than 1 way to visit any node

 While iterating over neighbours of any node -
 node -> nrbs ... 
 any nbr should not be the parent of node
*/
#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int x, int y) //function to create graph
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool contains_cycle()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        return cycle_helper(0, visited, -1);
    }

    bool cycle_helper(int node, bool *visited, int parent)
    {
        visited[node] = true;
        for (auto nbr : l[node])
        {
            //two cases
            if (!visited[nbr])
            {
                //go and recursively visit the nbr
                bool cycle = cycle_helper(nbr, visited, node);
                if (cycle)
                {
                    return true;
                }
            }
            else if (nbr != parent)
            {
                //nbr is visited but nbr should not be equal to parent
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if(g.contains_cycle()) 
    {
        cout<<"Graph contains cycle"<<endl;
    }
    else
    {
        cout<<"Graph doesn't contain cycle"<<endl;
    }
    
    return 0;
}
/*
Graph Created:
   0 --- 1
 /       |
4        |
 \       |
  3 ---- 2
*/
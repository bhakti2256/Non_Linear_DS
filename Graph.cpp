/*Graph using adjacency list */
#include <iostream>
#include <list>

using namespace std;

class Graph
{
private:
    int V;
    list<int> *l; //Pointer pointing to an array of list

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V]; //l is a pointer to an array where each element is a list
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print()
    {
        for (int i = 1; i < V; i++)
        {
            cout << "Vertex " << i << "-> ";
            for (auto x = l[i].begin() ; x != l[i].end() ; x++)
            {
                cout << *x<<" ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 2);    // graph made: (1)----(2)
    g.addEdge(1, 3);    //              | \    |
    g.addEdge(1, 4);    //              |  \   |
    g.addEdge(3, 4);    //              |   \  |
    g.addEdge(2, 4);    //             (3)----(4)
  
    g.print();
    return 0;
}

/* 
Adjacency List:
Vertex -> Edge List
    1 -> 2 3 4
    2 -> 1 4
    3 -> 1 4
    4 -> 1 3 2
*/
//DFS- Depth First Traversal (data structure used is STACK)
//With help of recursion 
#include <iostream>
#include <map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T> > l; //create a map of T(can be int,char,etc.) and list of T(i.e connected nodes)
    public:
    void addEdge(int x, int y) //function to create graph
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src, map<T,bool> visited)
    {
        //Recursive function that will traverse the graph
        cout<<src<<" ";
        visited[src] = true; //marking src as visited
        for(T nbr: l[src]) // for every nbr in src- every neighbour node of source node
        if(!visited[nbr]) //if nbr is not visited then we recursively call this function
        {
            dfs_helper(nbr,visited);
        }
    }

    void dfs(T src)
    {
        map<T,bool> visited; //array(hash-map) to keep track of visited nodes
        //Mark all the nodes as not visited in beginning
        for(auto p: l)
        {
            T node = p.first;
            visited[node] = false;
        }
        dfs_helper(src,visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);

    return 0;
}

/*
Graph created:
2---1
|   |
3---0
|
4---5

BFS Traversal: 0 1 2 3 4 5
*/
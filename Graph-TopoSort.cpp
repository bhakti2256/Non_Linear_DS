//Topological Sorting
//Applicable only to DAG - Directed Acyclic Graph
//Sorting where for each directed edge from node A->B, node A appears before node B
//Eg: A->B->C <-D => TopoSort:  A,B,D,C
//DFS- Depth First Traversal is used

#include <iostream>
#include <map>
#include<list>
#include<stack>

using namespace std;

stack<int> s;

template<typename T>
class Graph{
    map<T, list<T> > l; //create a map of T(can be int,char,etc.) and list of T(i.e connected nodes)
    public:
    void addEdge(int x, int y, bool bidir) //function to create graph
    {
        l[x].push_back(y);
        if(bidir)
            l[y].push_back(x);
    }

    void dfs_helper(T src, map<T,bool> visited)
    {
        //Recursive function that will traverse the graph
        //cout<<src<<" ";
        
        visited[src] = true; //marking src as visited
        for(T nbr: l[src]) // for every nbr in src- every neighbour node of source node
        if(!visited[nbr]) //if nbr is not visited then we recursively call this function
        {
            dfs_helper(nbr,visited);
        }
        s.push(src);
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

    void print()
    {
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(5,2,false);
    g.addEdge(5,0,false);
    g.addEdge(2,3,false);
    g.addEdge(1,3,false);
    g.addEdge(4,0,false);
    g.addEdge(4,1,false);

    g.dfs(5);
    g.dfs(4);
    g.print();

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
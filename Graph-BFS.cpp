//BFS- Breadth First Traversal
//With help of queue
#include <iostream>
#include <map>
#include <queue>
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

    void bfs(T src)
    {
        map<T,int> visited; //array to keep track of visited nodes
        queue<T> q; //For traversal

        q.push(src); //pushing src node
        visited[src] = true; // making the node src = true for indicating that it is visited

        while(!q.empty()) 
        {
            T node = q.front(); //initialising node = front element of queue
            q.pop(); 
            cout<<node<<" "; //printing node as it is visited
            for(int nbr : l[node]) // for every neighbour node in l[node] (the node initialised earlier)
            {
                if(!visited[nbr]) //if nbr of node is not visited
                {
                    q.push(nbr); // push nbr in queue
                    visited[nbr] = true; //changing its visited value to true
                }
            }
        }
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

    g.bfs(0);

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
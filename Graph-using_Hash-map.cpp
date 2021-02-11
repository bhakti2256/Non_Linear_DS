#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>

using namespace std;

class Graph{
    private:
    unordered_map<string, list<pair<string,int>>> l;    //Creating an unordered map of list of pairs
    /* 
    A -> (B,20) (C,10) (D,50)
    key -> value  (unordered map)                                               unordered_map<string, list>
           value is a list (creation of ist)                                    unordered_map<string, list>
           of pairs(creation of pairs)                                          unordered_map<string, list <pair>>
           where 1st element is string type and 2nd element is of int type      unordered_map<string, list <pair <string,int>>>  
    */
    public:
    void addEdge(string x, string y, bool bidir, int wt)
    {
        //bidir = bidirectional edge -> true if it is bidirectional
        l[x].push_back(make_pair(y,wt));
        if(bidir) 
        {
            l[y].push_back(make_pair(x,wt));
        }
    }

    void printList()
    {
        //Iterate over all keys in the map
        for(auto p : l) //for each key in the map
        {
            string city = p.first; //getting the key 
            list<pair<string,int>> nbrs = p.second; //getting the list of pairs of connected edges and weight
            cout<<city<<": ";
            for(auto nbr: nbrs) //for every nbr in nbrs || here nbrs==list of pairs of edges and weight & nbr will iterate over nbrs(i.e. list)
            {
                string dest = nbr.first; //Connected edge
                int dist = nbr.second; //weight

                cout<<"("<<dest<<","<<dist<<") ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,30);
    g.addEdge("A","D",true,50);
        
    g.printList();
    return 0;
}
/*
Graph Created:
A--20---B
|  \    |
10  50  40
|     \ | 
C--30---D

Adjacency List:
C: (A,10) (D,30)
D: (B,40) (C,30) (A,50)
A: (B,20) (C,10) (D,50)
B: (A,20) (D,40) 

*/
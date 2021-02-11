//Single source shortest path
#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

template<typename T>
class Graph
{
private:
    unordered_map<T, list<pair<T, int>>> l;

public:
    void addEdge(T x, T y, bool bidir, int wt)
    {
        //bidir = bidirectional edge -> true if it is bidirectional
        l[x].push_back(make_pair(y, wt));
        if (bidir)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void dijkstra(T src)
    {
        unordered_map<T,int> distance; //array(map) to store distance (answer array)

        //setting all distance to infinity
        for(auto j: l)
        {
            distance[j.first] = INT32_MAX;
        }

        //make a set to find node with min distance
        set<pair<int,T>> s; //in set, sorting is according to 1st parameter, thus distance is kept first

        //setting src element as 0 --- i.e. the distance of that node to itself is 0
        distance[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            //Find the pair at front
            auto p = *(s.begin()); //gives pair 
            T node = p.second; //we store (distance,node-value) -> fisrt=distance, second = node-value

            int nodeDist = p.first; 
            s.erase(s.begin()); 

            //iterate over neighbours of current node
            for(auto childPair : l[node])
            {
                if(nodeDist + childPair.second < distance[childPair.first]) //if(present node distance + nbr node distance < (present node distane in answer array))
                {
                    //in set upadtion of node is not possible
                    //we have to remove the old pair and insert new pair to simulation update
                    T dest = childPair.first;
                    auto f = s.find(make_pair(distance[dest] , dest)); //findng old pair

                    if(f!=s.end()) //if f is not pointing to end i.e. f(old node) is found
                    {
                        s.erase(f);
                    }

                    //insert new pair
                    distance[dest] = nodeDist + childPair.second;
                    s.insert(make_pair(distance[dest],dest));
                } 
            }
        }
        //print distance to other nodes from source
        cout<<"\nDistance of other nodes from source:\n";
        for(auto d : distance)
        {
            cout<<d.first<<" is at distance "<<d.second<<endl;
        }
    }

    void printList()
    {
        //Iterate over all keys in the map
        for (auto p : l) //for each key in the map
        {
            T node = p.first;                   //getting the key
            list<pair<T, int>> nbrs = p.second; //getting the list of pairs of connected edges and weight
            cout << node << ": ";
            for (auto nbr : nbrs) //for every nbr in nbrs || here nbrs==list of pairs of edges and weight & nbr will iterate over nbrs(i.e. list)
            {
                T dest = nbr.first;  //Connected edge
                int dist = nbr.second; //weight

                cout << "(" << dest << "," << dist << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1, 2, true, 1);
    g.addEdge(1, 3, true, 4);
    g.addEdge(1, 4, true, 7);
    g.addEdge(2, 3, true, 1);
    g.addEdge(3, 4, true, 2);
    g.addEdge(4, 5, true, 3);
    g.addEdge(4, 6, true, 11);
    g.addEdge(5, 6, true, 1);
    g.printList();
    g.dijkstra(1);

    cout<<endl<<endl;
    Graph<string> india;
    india.addEdge("Amritsar", "Delhi", true,1);
    india.addEdge("Amritsar", "Jaipur", true,4);
    india.addEdge("Jaipur", "Delhi", true,2);
    india.addEdge("Jaipur", "Mumbai", true,8);
    india.addEdge("Bhopal", "Agra", true,2);
    india.addEdge("Mumbai", "Bhopal", true,3);
    india.addEdge("Agra", "Delhi", true,1);
    india.printList();
    india.dijkstra("Amritsar");

    return 0;
}
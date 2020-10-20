#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<pair<int,int>>> mp;
public:
    void addEdge(int a,int b,int w)
    {
        mp[a].push_back({b,w});
        mp[b].push_back({a,w});
    }
    void printAdj()
    {
        for(auto it:mp)
        {
            cout<<it.first<<" -> ";
            auto pl = it.second;
            for(auto it2:pl)
            {
                cout<<it2.first<<" "<<it2.second<< " ";
            }
            cout<<"\n";
        }
    }
    void dijkstra(int src)
    {
        map<int,int> dist;
        for(auto it:mp)
        {
            dist[it.first]=INT_MAX;
        }
        dist[src]=0;
        set<pair<int,int>> s;
        s.insert({dist[src],src});
        while(!s.empty())
        {
            cout<<"SDFSDF\n";
            auto n = *(s.begin());
            s.erase(s.begin());
            int dist_node=n.first;
            int node = n.second;
            cout<<dist_node<<" "<<node<<endl;
            for(auto it2:mp[node])
            {
                cout<<dist_node+it2.second<<endl;
                if(dist_node+it2.second<dist[it2.first])
                {
                    int node2 = it2.first;
                    if(s.find({dist[node2],node2})!=s.end())
                        {
                            s.erase({dist[node2],node2});
                        }
                        dist[it2.first]=dist_node+it2.second;
                        s.insert({dist[node2],node2});
                }
            }
        }
        for(auto it:dist)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }

};
int main()
{
    Graph g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(1,4,7);
    g.addEdge(4,3,2);
    g.addEdge(3,2,1);
    g.printAdj();
    g.dijkstra(1);
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
class Graph
{
    map<int,list<int>> mp;
public:
    void addEdge(int a,int b)
    {
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    void shortest_cycle(int src)
    {
        map<int,int> dist;
        for(auto it:mp)
        {
            dist[it.first]=INT_MAX;
        }
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto nbrs: mp[node])
            {
                if(dist[nbrs]==INT_MAX)
                {
                    dist[nbrs]=dist[node]+1;
                    q.push(nbrs);
                }
                else if(dist[nbrs]>=dist[node])
                {
                    ans=min(ans,dist[node]+dist[nbrs]+1);
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(1,4);
    g.addEdge(2,6);
    g.addEdge(2,3);
    g.addEdge(3,6);
    g.addEdge(5,5);
 for(int i=1;i<=6;i++)
 {
     g.shortest_cycle(i);
         cout<<ans<<" ";
 }
 cout<<"\n";

}

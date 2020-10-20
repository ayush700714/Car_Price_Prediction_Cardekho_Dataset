#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>> mp;
public:
    void addEdge(int a,int b)
    {
        mp[a].push_back(b);
    }
        void printEdge()
    {
        for(auto it:mp)
        {
            cout<<it.first<<"-> ";
            for(auto it2:it.second)
            {
                cout<<it2<<" ";
            }
            cout<<"\n";
        }
    }
    void bfs()
    {
        //calculating indegree of all nodes
        map<int,int> indegree;
                for(auto it:mp)
        {
             indegree[it.first]=0;
        }
        for(auto it:mp)
        {
            for(auto it2:it.second)
            {
                indegree[it2]++;
            }
        }
        queue<int> q;
        //finding all the nodes which have 0 indegree and push them into queue
        for(auto it:indegree)
        {
            cout<<it.first<<" "<<it.second<<endl;
            if(it.second==0)
            {
                q.push(it.first);
            }
        }
        while(!q.empty())
        {
            int fr=q.front();
            q.pop();
            for(auto it:mp[fr])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            cout<<fr<<" ";
        }
        cout<<"\n";
    }
};
int main()
{
        Graph g;
    g.addEdge(0,2);
      g.addEdge(1,2);
      g.addEdge(1,4);
      g.addEdge(2,3);
      g.addEdge(2,5);
      g.addEdge(4,5);
        g.addEdge(3,5);
      g.printEdge();
      g.bfs();
}

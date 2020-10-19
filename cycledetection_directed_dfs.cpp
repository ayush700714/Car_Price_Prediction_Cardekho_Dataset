#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int pp=-1;
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
    bool dfs_helper(int src,map<int,bool> &visited,map<int,bool> &stack)
    {
        visited[src]=true;
        stack[src]=true;
        for(auto it:mp[src])
        {
            if(stack[it]==true)
            {
                pp=it;
                return true;
            }
            else if(!visited[it])
            {
                bool po = dfs_helper(it,visited,stack);
                    if(po==true)
                    {
                        return true;
                    }
            }
        }
        stack[src]=false;
        return false;
    }
    void dfs(int src)
    {
        map<int,bool> visited;
        map<int,bool> stack;
        for(auto it:mp)
        {
            visited[it.first]=false;
            stack[it.first]=false;
        }
        bool pp=dfs_helper(src,visited,stack);
        if(pp==true)
        {
            cout<<"cycle detected\n";
        }
        else
        {
            cout<<"cycle not detected\n";
        }
    }
};
int main()
{
        Graph g;
    g.addEdge(0,1);
      g.addEdge(1,2);
      g.addEdge(2,3);
      g.addEdge(3,4);
      g.addEdge(4,5);
      g.addEdge(1,5);
         g.addEdge(5,6);
            g.addEdge(4,2);
      g.printEdge();
      g.dfs(0);
      cout<<pp<<endl;
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *arr;
public:
    void numberofVertices(int n)
    {
        v=n;
        arr=new list<int> [v];
    }
    void addEdge(int a,int b,bool c)
    {
        arr[a].push_back(b);
        if(c)
        {
            arr[b].push_back(a);
        }
    }
    void printEdge()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<"-> ";
            for(int nm:arr[i])
            {
                cout<<nm<<" ";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    Graph g;
    g.numberofVertices(4);
    g.addEdge(0,1,true);
      g.addEdge(1,2,false);
      g.addEdge(0,3,false);
      g.addEdge(2,3,true);
      g.printEdge();
}

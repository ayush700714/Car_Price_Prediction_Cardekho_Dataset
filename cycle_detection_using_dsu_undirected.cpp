#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<int> v;
public:
    void init(int n)
    {
        v.resize(n);
        for(int i=0;i<n;i++)
        {
            v[i]=i;
        }
    }
    int super_par(int a)
    {
        if(v[a]==a)
        {
            return a;
        }
        else
        {
            return v[a]=super_par(v[a]);
        }
    }
    void unite(int a,int b)
    {
        int super_a=super_par(a);
        int super_b=super_par(b);
        if(super_a!=super_b)
        {
            v[super_a]=super_b;
        }
        else
        {
            cout<<"cycle detected at nodes "<< a<<" and "<<b<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.init(5);
    g.unite(1,2);
    g.unite(2,3);
    g.unite(1,3);
}

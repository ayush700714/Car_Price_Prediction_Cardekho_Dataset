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
    void unite(int a,int b)
    {
        int super_par_a = get_suprent(a);
        int super_par_b = get_suprent(b);
        if(super_par_a!=super_par_b)
        {
            v[super_par_a]=super_par_b;

        }

    }
    int get_suprent(int c)
    {
        if(v[c]==c)
        {
            return c;
        }
        else
        {
            return v[c]=get_suprent(v[c]);
        }
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(m);
    for(int i=0;i<m;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        x--;
        y--;
        arr[i]={w,x,y};
    }
    sort(arr.begin(),arr.end());
    int sum=0;
            Graph g;
            g.init(n);
    for(int i=0;i<m;i++)
    {

        int a=arr[i][1];
        int b=arr[i][2];
        if(g.get_suprent(a)!=g.get_suprent(b))
        {
            g.unite(a,b);
            sum+=arr[i][0];
        }
    }
    cout<<sum<<endl;
}

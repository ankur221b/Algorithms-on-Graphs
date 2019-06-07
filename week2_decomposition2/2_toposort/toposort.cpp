#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MAX 100001
#define MOD 1000000007
#define mod 100000

map<int,int> vis;
vector<int> vec;
map<int,vector<int> > v;

void topologial_sort(int node)
{
    vis[node]=1;

    for(int i:v[node])
    {
        if(!vis[i])topologial_sort(i);
    }

    vec.push_back(node);
    
}


int main()
{
    fast_io;
    int n,m,a,b,c=0,node;
    cin>>n>>m;


    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a-1].push_back(b-1);
    }

    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])topologial_sort(i);
    }

    reverse(all(vec));
    for(int i:vec)cout<<i+1<<" ";



  
}
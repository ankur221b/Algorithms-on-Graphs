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

map<int,int> vis,dist;
map<int,vector<int> > v;



int main()
{
    fast_io;
    int n,m,a,b,c=0,node,x;
    cin>>n>>m;


    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    cin>>a>>b;

    queue<int> q;

    q.push(a-1);

    vis[a-1]=1;
    dist[a-1]=0;
    dist[b-1]=-1;

    while(!q.empty())
    {
      node = q.front();
      q.pop();

      for(int i:v[node])
      {
        if(!vis[i])
        {
                vis[i]=1;
          q.push(i);
          dist[i]=dist[node]+1;
        }
      }
    }

    cout<<dist[b-1];

    



  
}
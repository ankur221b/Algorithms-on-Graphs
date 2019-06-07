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

struct pt
{
  int x,y;
};

struct edge
{
  pt src,dest;
  double weight;
  
};

double distance(pt a,pt b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

int root(int v[],int a)
{
    while(v[a]!=a)
    {
        a = v[v[a]];  
    }
    return a;
}

void uni(int v[],int size[],int a , int b)
{
    int A = root(v,a);
    int B = root(v,b);
    if(A==B)return;
    
    if(size[A]<size[B])
    {
        v[A]=v[B];
        size[B]+=size[A];
        size[A]=0;
    }
    else
    {
        v[B]=v[A];
        size[A]+=size[B];
        size[B]=0;
    }
    
}

bool find(int v[],int a , int b)
{
    return root(v,a)==root(v,b);
}
 
void init(int v[],int s[],int n)
{
    for(int i=1;i<=n;i++)
    {
        v[i]=i;
        s[i]=1;
    }
}

int main()
{   
  fast_io;
    int n;
    double dist,sum;
    cin>>n;
    
    int v[n+1],s[n+1];
    init(v,s,n);
    pt a[n];
    map<pii,int> mm;

    for(int i=0;i<n;i++)
    {
      cin>>a[i].x>>a[i].y;
        mm[{a[i].x,a[i].y}]=i+1;
    }

    vector<edge> edges,res;
    edge e;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j)continue;
        dist = distance(a[i],a[j]);
        e.src=a[i];
        e.dest=a[j];
        e.weight=dist;
        edges.pb(e);
      }
    }

    sort(all(edges),[](edge a,edge b){return a.weight<b.weight;});
    

    for(int i=0;i<edges.size();i++)
    {
      if(!find(v,mm[{edges[i].src.x,edges[i].src.y}],mm[{edges[i].dest.x,edges[i].dest.y}]))
      {
        res.pb(edges[i]);
        uni(v,s,mm[{edges[i].src.x,edges[i].src.y}],mm[{edges[i].dest.x,edges[i].dest.y}]);
      }
    }

    for(int i=0;i<res.size();i++)
    {
      sum+=res[i].weight;
    }

    cout<<fixed<<setprecision(7)<<sum;



  
}
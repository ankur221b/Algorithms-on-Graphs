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

int root(int *parent,int a)
{
    while(parent[a]!=a)
    {
      a = parent[parent[a]];       
    }
    return a;
}

void merge(int *parent,int *size,int a,int b)
{
    int A = root(parent,a);
    int B = root(parent,b);
    if(A==B)return ;

    if(size[A]>size[B])
    {
      parent[B]=A;
      size[A]+=size[B];
      size[B]=0;
    }
    else
    {
      parent[A]=B;
      size[B]+=size[A];
      size[A]=0;
    }
}

int main()
{
    fast_io;
    int n,m,a,b;
    cin>>n>>m;

    int parent[n],size[n];  

    for(int i=0;i<n;i++)
    {
      size[i]=1;
      parent[i]=i;
    }

    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        merge(parent,size,a-1,b-1);
    }

    cin>>a>>b;
    
    int c=0;

    for(int i=0;i<n;i++)
    {
        if(size[i])c++;
    }
    cout<<c;

   

}
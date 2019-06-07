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

map<int,int> vis,vis1;
stack<int> st;
map<int,vector<int> > v,v1;

void topologial_sort(int node)
{
    vis[node]=1;

    for(int i:v[node])
    {
        if(!vis[i])topologial_sort(i);
    }

    st.push(node);
    
}

void topologial_sort2(int node)
{
    vis1[node]=1;

    for(int i:v1[node])
    {
        if(!vis1[i])topologial_sort2(i);
    }

}


int main()
{
    fast_io;
    int n,m,a,b,c=0,node,x;
    cin>>n>>m;


    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v1[b-1].push_back(a-1);
    }

    for(int i=0;i<n;i++)
    {
        if(!vis[i])topologial_sort(i);
    }

    

    for(int i=0;i<n;i++)
    {
        x=st.top();
        st.pop();
        if(!vis1[x])
        {
            c++;
            topologial_sort2(x);
        }
    }

    cout<<c;


    



  
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair <int,ii> iii;
#define FORW(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for (int i=a;i>=b;i--)
#define forw(i,a,b) for (ll i=a;i<=b;i++)
#define forb(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define fi first
#define se second
#define pu push
#define puf push_front
#define pb push_back
#define pof pop_front
#define pob pop_back
#define fr front
#define all(a) a.begin(),a.end()
#define endl "\n"
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m,s,t;
int vst[1001],d[1001];
vector<ii> adj[500000];
int bfs(int s)
{
    priority_queue<ii> q;
    q.push({0,s});
    vst[s]=1;
    d[s]=99999999;
    while(q.size())
    {
        int u= q.top().se;
        vst[u]=1;
        q.pop();
        for (auto v:adj[u])
        {
            if (vst[v.fi]) continue;
            d[v.fi]=min(d[u],v.se);
            q.push({v.se,v.fi});
        }
    }

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m>>s>>t;
    FORW(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    bfs(s);
    cout<<d[t];

}

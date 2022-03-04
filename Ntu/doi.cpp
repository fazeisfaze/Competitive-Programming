#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
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
#define db(val) "["#val" = "<<(val)<<"] "
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,q;
ll d[100001];
vector<ii> adj[50000];
void dfs(int u,int p)
{
    for (auto v:adj[u])
    {
        if (v.fi==p) continue;
        d[v.fi]=d[u]+v.se;
        dfs(v.fi,u);
    }
}
int main()
{
    fast;
    freopen("CHIHUY.INP","r",stdin);
    freopen("CHIHUY.OUT","w",stdout);
    cin>>n>>q;
    FORW(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,0);
    while(q--)
    {
        string s;cin>>s;
        if (s=="vanchuyen")
        {
            int x,y;
            cin>>x>>y;
            cout<<d[x]+d[y]<<endl;
        }
        else
        {
            int s;
            cin>>s;
            d[s]=0;
            dfs(s,0);
        }
    }
}



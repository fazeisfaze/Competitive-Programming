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
const ll oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m,cnt=0;
vector<ii> adj[100001];vector<int> adj1[100001];
int d[500000],Visited[500001],Low[100001],Parent[100001];
int res=0;
void dijkstra(int s)
{
    FORW(i,1,n)
     d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({d[s]=0,s});
    while(pq.size())
    {
        ii u = pq.top();
        pq.pop();
        if (u.fi!=d[u.se]) continue;
        for (auto v: adj[u.se])
            if (v.se+u.fi<d[v.fi])
                pq.push({d[v.fi]=v.se+u.fi,v.fi});
    }
}
bool build_graph(int u,ll sum, int p )
{
    if(sum > d[n]) return 0;
    if(u == n && sum == d[n]) return 1;
    else if(u == n && sum != d[n]) return 0;
    bool checkk = 0;
    for(auto v:adj[u])
    if(v.fi!=p)
    {
        bool tmp = build_graph(v.fi,sum + v.se,u);
        checkk |= tmp;
        if(tmp)
        {
            adj1[u].pb(v.fi);
            adj1[v.fi].pb(u);
        }
    }
    return checkk;
}
void visit(int u){
    Low[u]=Visited[u]=++cnt;
    for (auto v: adj1[u])
    if (v!=Parent[u]){
        if (Visited[v]) Low[u]=min(Low[u], Visited[v]);
        else {
            Parent[v]=u; visit(v); Low[u]=min(Low[u],Low[v]);
            if (Low[v]>=Visited[v]) res++;
        }
    }
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>> n >> m;
    FORW(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dijkstra(1);
    build_graph(1,0,0);
    visit(1);

    cout<<res;
}



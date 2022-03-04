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
const int oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m;
vector<ii> adj[500000];
int d[1000000];
bool vis[100000];
int s,t;
void dijkstra(int s){
    FORW(i,1,n)
     d[i]=0;
    priority_queue<ii> pq;
    pq.push({d[s]=oo,s});
    while (pq.size()){
        int du = pq.top().fi;
        int u = pq.top().se;
  //      cout<<u<<" "<<du<<endl;
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto v: adj[u])
            if (d[v.fi]<min(v.se,d[u]))
                pq.push({d[v.fi]=min(v.se,du),v.fi});

    }

}
int main()
{
    fast;
    freopen("TEST.INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m>>s>>t;
    FORW(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dijkstra(s);
    cout<<d[t];
}



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
const int mxN= 1e6;

int d[mxN],dp[mxN];
int n,m,s,t;
vector<ii> adj[mxN];
void dijkstra(int s){
    FORW(i,1,n)
     d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({d[s]=0,s});
    dp[s]=1;
    while(pq.size()){
        int du = pq.top().fi, u= pq.top().se;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto v: adj[u])
            if (v.se+du<d[v.fi]){
                pq.push({d[v.fi]=v.se+du,v.fi});
                dp[v.fi]=dp[u];
            }
            else if (v.se+du==d[v.fi])
                dp[v.fi]+=dp[u];
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
    cout<<dp[t];
}



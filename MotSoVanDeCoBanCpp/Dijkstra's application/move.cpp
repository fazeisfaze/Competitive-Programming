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
const int mxN = 1e5;
int w[mxN],trace[mxN],d[mxN],vis[mxN];
vector<int> adj[mxN];
int n,s,t;
void dijkstra(int s){
    FORW(i,1,n)
     d[i]=oo;
    priority_queue<ii,vector<ii>, greater<ii>> pq;
        pq.push({d[s]=0,s});
    while(pq.size()){
        int u= pq.top().se, du = pq.top().fi;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto v: adj[u]){
            if (max(du,abs(w[u]-w[v]))<d[v]){
                pq.push({d[v]=max(du,abs(w[u]-w[v])),v});
                trace[v]=u;
            }


        }

    }
}
int main()
{
    fast;
    freopen("MOVE.INP","r",stdin);
    freopen("MOVE.OUT","w",stdout);
    cin>>n>>s>>t;
    trace[s]=0;
    FORW(i,1,n)
     cin>>w[i];
    int u,v;
    while(cin>>u>>v){
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dijkstra(s);
    cout<<d[t]<<endl;
    vector<int> res;
    for (int i = t ;i!=0;i=trace[i])
        res.pb(i);
    reverse(all(res));
    for (auto v: res)
         cout<<v<<" ";


}



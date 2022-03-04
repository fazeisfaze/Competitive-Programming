#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
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
vector<ii> adj[100001];
int n,m,k;
ll d[100001];
void dijkstra(int s){
    FORW(i,0,n)
        d[i]=oo;
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({d[s]=0,s});
    while(pq.size()){
        ll du = pq.top().fi,u = pq.top().se;
        pq.pop();
        if (du>d[u ]) continue;
        for (auto v : adj[u])
            if (du+v.fi<d[v.se])
                pq.push({d[v.se]=du+v.fi,v.se});

    }
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m>>k;
    FORW(i,1,n){
        ll t ;
        cin>>t;
        adj[0].pb({t,i});
        adj[i].pb({t,0});
    }
    FORW(i,1,m){
        ll  u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({w,v});
        adj[v].pb({w,u});
    }
    FORW(i,1,k){
        ll b;
        cin>>b;
        dijkstra(b);
        FORW(i,1,n)
         cout<<d[i]<<" ";
         cout<<endl;
    }

}



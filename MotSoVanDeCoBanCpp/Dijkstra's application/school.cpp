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
const int mxN =1e4;
int n,m;
int d[mxN],f[mxN];
vector<ii> adj[mxN];
void dijkstra(int s){
    FORW(i,1,n)
     d[i]=oo;
     priority_queue<ii,vector<ii>,greater<ii>> pq;
     pq.push({d[s]=0,s});
     f[s]=1;

     while(pq.size()){
        int u =pq.top().se,du=pq.top().fi;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto v: adj[u])
            if (v.se+du<d[v.fi]){
                pq.push({d[v.fi]=v.se+du,v.fi});
                f[v.fi]=f[u];
            }
            else if (v.se+du==d[v.fi])
                f[v.fi]+=f[u];

     }


}
int main()
{
    fast;
    freopen("SCHOOL.INP","r",stdin);
    freopen("SCHOOL.OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,m){
        int k,u,v,l;
        cin>>k>>u>>v>>l;
        adj[u].pb({v,l});
        if (k==2)
        adj[v].pb({u,l});
    }
    dijkstra(1);
    cout<<d[n]<<" "<<f[n]<<endl;


}



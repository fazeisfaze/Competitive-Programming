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
int Low[10000],Visited[10000],Time=0;
vector<int> adj[50000];
vector<ii> Bridge;
int n,m;
void visit(int u, int p){
    Low[u]=Visited[u]= ++Time;
    for(auto v: adj[u])
    if (v!=p)
    {
        if (Visited[v]) Low[u]=min(Low[u],Visited[v]);
        else {
            visit(v,u);
            Low[u]=min(Low[u],Low[v]);
            if (Low[v]>=Visited[v]) Bridge.pb({u,v});
        }
    }

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,m){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);

    }
    visit(1,0);
    for (auto v : Bridge)
         cout<<v.fi<<" "<<v.se<<endl;
}



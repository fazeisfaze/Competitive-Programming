#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
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
int n,m;
vector<iii> adj;
struct disjoint_set{
    vector<int> par;
    disjoint_set(int n){
        par.resize(n+1);
        FORW(i,1,n)
         par[i]=i;
    }
    int get(int u ){
        if (par[u]==u) return u;
        return par[u]=get(par[u]);

     }
    void join( int u, int v){
        par[get(u)]=get(v);
    }
};
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj.pb({w,{u,v}});
    }
    sort(all(adj));
    int res=0;
    disjoint_set dsu(n);
    for (auto v: adj){
        int x= dsu.get(v.se.fi), y = dsu.get(v.se.se);
        if (x!=y){
            res=max(res,v.fi);
            dsu.join(v.se.fi,v.se.se);

        }
    }
    cout<<res<<endl;
}



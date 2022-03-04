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

struct dsu{
    int par[100000];
    void init(int n){
        FORW(i,0,n-1)
         par[i]=i;
    }
    int anc(int p) {
        if (par[p] == p)
            return p;
        else
            return par[p] = anc(par[p]);
    }
void join(int p, int q) { par[anc(p)] = anc(q); }

};
int main()
{
    fast;
  //  freopen("KRUSKAL.INP","r",stdin);
   // freopen("KRUSKAL.OUT","w",stdout);
    cin>>n>>m;
    dsu ds;
    ds.init(n);
    int u,v,w,res=0;
    FORW(i,1,m){
        int u ,v,w;
        cin>>u>>v>>w;
        adj.pb({w,{u,v}});
    }
    sort(all(adj));
    vector<ii> res_query;
    for (auto v: adj){
        if (ds.anc(v.se.fi)!=ds.anc(v.se.se)){
            ds.join(v.se.fi,v.se.se);
            res+=v.fi;
            res_query.pb({v.se.fi,v.se.se});
        }
    }
    cout<<res<<endl;
    for (auto v: res_query)
        cout<<v.fi<<" "<<v.se<<endl;
}



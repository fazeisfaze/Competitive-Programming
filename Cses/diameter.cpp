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
const int N = 2e5+1;
vector<int > adj[N];
int n,dp1[N],dp2[N],res=0;
void dfs(int u, int p)
{
    vector<int> f;
    for (int v: adj[u])
    {
        if (v== p) continue;
        dfs(v,u);
        f.pb(dp1[v]);
    }
    dp1[u]=1;
    sort(all(f));
    if (f.size()) dp1[u]+=f.back();
    if (f.size()>=2) dp2[u]=f.back()+f[f.size()-2]+1;
    res=max({res,dp1[u],dp2[u]});

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n;
    FORW(i,1,n-1)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb(y);
         adj[y].pb(x);

     }
     dfs(1,0);
     cout<<res-1;
}



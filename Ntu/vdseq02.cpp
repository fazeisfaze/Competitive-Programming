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
int n,m,s,t;
vector<ii> adj[500000];
bool vst[1001];
void bfs(int s,int mid )
{
    queue<int> q;
    q.push(s);
    vst[s]=1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v: adj[u])
          if (v.se>=mid&&!vst[v.fi])
        {
            q.push(v.fi);
            vst[v.fi]=1;
        }
    }
}
bool good(int mid)
{
    memset(vst,0,sizeof vst);
    bfs(s,mid);
    if (vst[t])
        return 1;
    return 0;
}
int main()
{
    fast;
   // freopen("TAITRONG.INP","r",stdin);
   // freopen("TAITRONG.OUT","w",stdout);
    cin>>n>>m>>s>>t;
    FORW(i,1,m){
      int u,v,w;
      cin>>u>>v>>w;
      adj[u].pb({v,w});
      adj[v].pb({u,w});
    }
    int l = 0,r =100000;
    int ans=-1;
    bool check=-1;
    while (l<=r)
    {
        int mid = (l+r)>>1;
      //  cout<<l<<" "<<r<<endl;
        if (good(mid))
        {
            l=mid+1;
            check=1;
        }
        else
            r=mid-1;
    }
   cout<<((check)?l-1:-1);
}


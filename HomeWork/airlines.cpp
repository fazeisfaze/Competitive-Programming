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
const ll oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m,c,a,s,f;
vector<ii> adj[10001][17];
int d[101][17];
void dijkstra(int s, int id){
    FORW(i,1,n)
      d[i][id]=oo;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({d[s][id]=0,s});
    while(pq.size()){
        int du= pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (du>d[u][id]) continue;
        for (auto v: adj[u][id])
            if (du + v.fi < d[v.se][id] )
                pq.push({d[v.se][id]=du+v.fi,v.se});

    }

}
int main()
{
    fast;
    freopen("AIRLINES.INP","r",stdin);
    freopen("AIRLINES.OUT","w",stdout);
    cin>>n>>m>>c>>a>>s>>f;
    int t;
    int r = 201;
    FORW(k,1,16){
        FORW(i,1,m){
            int u,v;
            cin>>u>>v;
            while(cin>>t){
                if (t==0) break;
                if (t==k){
                    adj[u][k].pb({c,v});
                    adj[v][k].pb({c,u});
                }
                else{
                    adj[u][k].pb({a,r});
                    adj[r][k].pb({a,u});
                    adj[r][k].pb({c,v});
                    adj[v][k].pb({c,r});
                    r++;
                }


            }

        }
    }
    FORW(i,1,16)
     dijkstra(s,i);
     int res=oo;
    FORW(i,1,n){
        cout<<d[i][1]<<endl;
    }

    cout<<res;
}



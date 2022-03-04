/* tóm tắt đề:
   Cho n thành phố, m con đường 2 chiều
   1 thành phố được chọn làm trung tâm nếu không sử dụng thành phố này đường đi ngắn nhất từ 1 đến N vẫn không thay đổi
*/
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

int n,m;
vector<ii> adj[mxN];
int d[mxN][2];
void dijkstra(int s, int t){
    FORW(i,1,n)
     d[i][t]=oo;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({d[s][t]=0,s});
    while(pq.size()){
        int du = pq.top().fi,u=pq.top().se;
        pq.pop();
        if (du!=d[u][t]) continue;
        for (auto v: adj[u]){
            if (v.se+du<d[v.fi][t]){
                pq.push({d[v.fi][t]=v.se+du,v.fi});
            }
        }

    }
}
int main()
{
    fast;
    freopen("CENTRE.INP","r",stdin);
    freopen("CENTRE.OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});

    }
    dijkstra(1,0);
    dijkstra(n,1);
    vector<int> res;
    FORW(i,2,n-1)
     if (d[i][0]+d[i][1]>d[n][0])
         res.pb(i);

    cout<<res.size()<<endl;
    for (auto v: res)
         cout<<v<<endl;
}



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
int n,m,k;
vector<ii> adj[10001];
int d[10000][2];
void dijkstra(int s,int type)
{
    FORW(i,1,n)
     d[i][type]=oo;
    priority_queue<ii,vector<ii>, greater<ii> > pq;
    pq.pu({d[s][type]=0,s});
    while(pq.size())
    {
        ii u = pq.top();
        pq.pop();
        if (u.fi!=d[u.se][type]) continue;
        for (auto v: adj[u.se])
            if (v.se+d[u.se][type]<d[v.fi][type])
                pq.pu({d[v.fi][type]=v.se+d[u.se][type],v.fi});

    }
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("DENTRU.INP","r",stdin);
    freopen("DENTRU.OUT","w",stdout);
#endif
    cin>>n>>m>>k;
    FORW(i,1,m)
    {
        int x,y,w1,w2;
        cin>>x>>y>>w1>>w2;
        adj[x].pb({y,w1});
        adj[y].pb({x,w2});

    }
    dijkstra(1,0);
    dijkstra(k,1);
    cout<<d[n][0];

}



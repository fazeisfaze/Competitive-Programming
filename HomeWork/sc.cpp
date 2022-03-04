#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
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
ii a[501][501],z[501][501];
int d[501][501];
int n,m;
bool check(ii v){
    return (v.fi>=1&&v.fi<=n&&v.se>=1&&v.se<=m);
}

void dijkstra(ii s){
    priority_queue<iii, vector<iii>, greater<iii> > pq;
    FORW(i,1,n)
     FORW(j,1,m)
      d[i][j]=oo;
    pq.push({d[s.fi][s.se]=min(a[s.fi][s.se].fi,a[s.fi][s.se].se),s});
    z[s.fi][s.se]=a[s.fi][s.se];
    while (pq.size()){
        ii u = pq.top().se;
        int du = pq.top().fi;
        pq.pop();
        if (du!=d[u.fi][u.se]) continue;
        FORW(k,0,3){
            ii v = {u.fi+dX[k],u.se+dY[k]};
            if (!check(v)) continue;
            int  t = min(z[u.fi][u.se].fi + a[v.fi][v.se].fi,z[u.fi][u.se].se + a[v.fi][v.se].se);
            if (t<d[v.fi][v.se]){
                z[v.fi][v.se]= {z[u.fi][u.se].fi + a[v.fi][v.se].fi,z[u.fi][u.se].se + a[v.fi][v.se].se};
                pq.push({d[v.fi][v.se]=t,v});
            }

        }
    }
}
int main()
{
    fast;
    freopen("SC.INP","r",stdin);
    freopen("SC.OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,n)
     FORW(j,1,m){
         int t,t2=0,t5=0;
         cin>>t;
         while (!(t%2)) t2++,t/=2;
         while (!(t%5)) t5++,t/=5;
         a[i][j]={t2,t5};

     }
     dijkstra({1,1});
     cout<<d[n][m];

}



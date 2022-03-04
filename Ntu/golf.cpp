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
ii start;
bool visited[501][501];
int cnt=0,  total=0,n,m,a[501][501],w[501][501];
bool check(ii u){
    return (u.fi>=1&&u.fi<=n&&u.se>=1&&u.se<=m);

}
void dfs(ii u,int x){
    visited[u.fi][u.se]=1;
    if (a[u.fi][u.se])  cnt++;
    FORW(k,0,3){
        ii v = {u.fi+dX[k],u.se+dY[k]};
        if ((check(v)&&!visited[v.fi][v.se])&& abs(w[v.fi][v.se]-w[u.fi][u.se])<=x)
            dfs(v,x);

    }
}
bool check(int x){
    cnt =0;
    memset(visited,0,sizeof visited);
    dfs(start,x);
    return (cnt == total);
}
int main()
{
    fast;
    freopen("GOLF.INP","r",stdin);
    freopen("GOLF.OUT","w",stdout);
    cin>>n>>m;
    int r =0;

    FORW(i,1,n)
     FORW(j,1,m)
      cin>>w[i][j],r=max(r,w[i][j]);


    FORW(i,1,n)
     FORW(j,1,m)
     {
      cin>>a[i][j];
      if (a[i][j])
        total++,start={i,j};

     }
    int l=0;
    while (l<=r){
        int mid = (l+r)/2;
        if (check(mid))
            r=mid-1;
        else
            l = mid+1;

    }
    cout<<r+1;

}



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
const int N = 112;
int n,a[N][N],vis[N][N];
void dfs(ii u ,int lw,int lt)
{
    vis[u.fi][u.se]=1;
    FORW(k,0,3)
    {
        ii v= {u.fi+dX[k],u.se+dY[k]};
        if (vis[v.fi][v.se]||v.fi<1||v.fi>n||v.se<1||v.se>n||a[v.fi][v.se]<lw||a[v.fi][v.se]>lt) continue;
        dfs(v,lw,lt);
    }
}
bool check(int k)
{
      FORW(i,0,111)
        {
            memset(vis,0,sizeof vis);
            dfs({1,1},i,i+k);
            if (vis[n][n])
                return 1;

        }
    return 0;
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n;
    FORW(i,1,n)
     FORW(j,1,n)
      cin>>a[i][j];
    int l=0,r=111;
    while (l<r)
    {
        int mid =(l+r)/2;
        if (check(mid))
            r=mid;
       else l=mid+1;
    }
    cout<<l;
}



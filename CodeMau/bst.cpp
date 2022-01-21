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
int n,s;
int a[251];
int ps[251];
int dp[251][251];
int solve()
{
    FORW(i,1,n)
     dp[i][i]=a[i];
    FORW(k,2,n)
     FORW(i,1,n-k+1)
      {
          int j = i+k-1;
          dp[i][j]=INT_MAX;
          FORW(r,i,j)
          {
              int cost = (r>i?dp[i][r-1]:0)+(r<j? dp[r+1][j]:0)+ ps[j]-ps[i-1];
              dp[i][j]=min(dp[i][j],cost);
          }
      }
    return dp[1][n];
}
int main()
{
    fast;
    //freopen("XEGO.INP","r",stdin);
    //freopen("XEGO.OUT","w",stdout);
    while(cin>>n)
    {
        ps[0]=0;
        FORW(i,1,n)
        {
                cin>>a[i];
                ps[i]=ps[i-1]+a[i];
        }

        cout<<solve()-ps[n]<<endl;
    }
}

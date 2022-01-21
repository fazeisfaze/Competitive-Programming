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
int n;
int a[501][501],ps[501][501];

int main()
{
    fast;
   // freopen("CHIADAT.INP","r",stdin);
//freopen("CHIADAT.OUT","w",stdout);
    cin>>n;
    FORW(i,1,n)
     FORW(j,1,n)
      cin>>a[i][j];
    FORW(i,1,n)
     FORW(j,1,n)
      ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+a[i][j];
     int res=9999999;
    FORW(i,1,n-1)
     FORW(j,1,n-1)
      {
          int x1= ps[i][j],x2=ps[i][n]-x1,x3=ps[n][j]-x1,x4=ps[n][n]-x1-x2-x3;
          res=min(res,abs(max({x1,x3,x2,x4})-min({x1,x2,x3,x4})));

      }
    cout<<res;

}



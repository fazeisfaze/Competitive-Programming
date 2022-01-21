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
const int N = 1e5+1;
int n,k;
int points[N];
ll dp[N];
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>k;
    FORW(i,1,n)
    cin>>points[i];
    FORW(i,1,n)
     dp[i]=-999999999;
    dp[0]=0;
    FORW(i,1,n)
    {
     if (i<=k) dp[i]=points[i];
     FORW(j,1,k)
     {

         if (i-j>=0)
         {
            dp[i]=max(dp[i],dp[i-j]+points[i]);
         }

     }
    }

    cout<<dp[n];
}



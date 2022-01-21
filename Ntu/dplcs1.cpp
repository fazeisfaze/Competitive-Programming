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
const ll MOD=25071987;
const ll mod=1e9+9;
string a,b;
int dp[5001][5001];
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>a>>b   ;
    FORW(i,1,a.size())
     FORW(j,1,b.size())
      {
          if (a[i-1]==b[j-1])
             (dp[i][j]=dp[i-1][j-1]+1)%=MOD;
          else
             (dp[i][j]=dp[i-1][j]+dp[i][j-1])%=MOD;

      }
//    string res="";
//    for (int i=a.size(),j=b.size();(i>=1)&&(j>=1);)
//    {
//        if (a[i-1]==b[j-1])
//             res=a[i-1]+res,i--,j--;
//         else if (dp[i][j]==dp[i-1][j])
//          i--;
//         else
//          j--;
//
//    }
    cout<<dp[a.size()][b.size()];
}



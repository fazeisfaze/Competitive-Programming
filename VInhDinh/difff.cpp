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
map<int,bool> cnt;
int n,q,a[100001],dp[100001];

int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>q;
    FORW(i,1,n)
     cin>>a[i];
    FORB(i,n,1)
     {
         if (!cnt.count(a[i]))
         {
            dp[i]=dp[i+1]+1;
            cnt[a[i]]=1;
         }

         else
            dp[i]=dp[i+1];

     }
    while(q--)
    {
        int k;
        cin>>k;
        cout<<dp[k]<<endl;
    }
}



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
const ll maxN=1e6+1;
const ll maxM=5e6;

int n,res=0,t;
int sum_div[maxM];
int main()
{
    fast;
    freopen("TRUCNHAT.INP","r",stdin);
    freopen("TRUCNHAT.OUT","w",stdout);
    FORW(i,1,maxM)
     for (int j=i;j<=maxM;j+=i)
         sum_div[j]+=i;
    cin>>n;
    FORW(i,1,n){
        cin>>t;
        if (sum_div[t]<2*t)
             res++;
    }
    cout<<res;

}



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
void solve(int t){
    int x,y,z;
    cin>>x>>y>>z;
    int max_=min({x,y,z});
    int min_=(x+y+z<=100)?0:(x+y+z-99)/2;
    if (min_<0||min_>max_)
        printf("Case #%d: The records are faulty.\n",t );
    else
        printf("Case #%d: Between %d and %d times.\n", t, min_, max_);
}
int main()
{
    fast;
    freopen("10882.INP","r",stdin);
    freopen("10882.OUT","w",stdout);
    int t;
    cin>>t;
    FORW(i,1,t)
        solve(i);
}



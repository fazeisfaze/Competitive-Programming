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
ll FindX(ll temp){
    ll delta = 1+4*temp*2;
    double x1 = (-1+sqrt(delta))/(2.0);
    return round(x1);

}

void solve(){
    int x,y;
    cin>>x>>y;
    ll temp = y-x;
    ll x1 = FindX(temp/2),x2= FindX(temp - x1*(x1+2)/2);
    ll res= x1+x2;
    if (x1*(x1+1)/2+x2*(x2+1)/2<temp)
        res++;
    cout<<res<<endl;

}
int main()
{
    fast;
//    freopen("DEMBUOC.INP","r",stdin);
//    freopen("DEMBUOC.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();
}



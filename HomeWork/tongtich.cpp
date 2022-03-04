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
map<ll,ll> save;
int n,p;
int gcdExtended(int a, int b, ll* x, ll* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int main()
{
    fast;
//    freopen(".INP","r",stdin);
//    freopen(".OUT","w",stdout);
    cin>>n>>p;
    ll res=0;
    FORW(i,1,n){
        int t;
        cin>>t;
        ll k = ((t-1)%p+p)%p;
        ll x,y;
        ll g = gcdExtended(k,p,&x,&y);
        if (g==1&&k!=0){
            ll z = (x%p+p)%p;
            if (z==0) continue;
            res+=save[z];
            save[z]++;
        }

    }

    cout<<res;
}



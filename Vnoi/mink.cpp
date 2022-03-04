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
const int mxN= 1e4+7e3;
int a[mxN];
int n,k;
void solve(){
    cin>>n>>k;
    deque<int> dq;
    FORW(i,1,n)
     cin>>a[i];
    FORW(i,1,n){
        while(dq.size()&&a[dq.back()]>=a[i]) dq.pop_back();
        dq.pb(i);
        if (dq.front()+k<=i) dq.pop_front();
        if (k<=i) cout<<a[dq.front()]<<" ";
    }
    cout<<endl;
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();
}



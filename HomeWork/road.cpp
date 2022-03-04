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
const ll oo=1e10;
const ll MOD=1e9+7;
const ll mod=1e9+9;
ll n,x;
ll psum[100001];
map<ll,ll> save;
int main()
{
    fast;
  //  freopen("ROAD.INP","r",stdin);
  //  freopen("ROAD.OUT","w",stdout);
    cin>>n>>x;
    FORW(i,1,n)
     {
         int t;
         cin>>t;
         psum[i]=psum[i-1]+t;
     }
    ii res={0,-oo};
    save[0]=0;
    FORW(i,1,n)
    {
        ll t= psum[i]-x*i;
      //  cout<<db(psum[i])<<db(t)<<endl;
        if (save.count(t))
        {
            if (i-save[t]>res.se)
              res={save[t]+1,i-save[t]};
        }

       else
        save[t]=i;
    }
    if (res.se==-oo)
        cout<<0<<endl;
else
     cout<<res.fi<<" "<<res.se<<endl;
}



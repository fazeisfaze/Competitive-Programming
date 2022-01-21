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
const int N = 1e5;
int bit[N],n,m;
void update (int u ,int v)
{
    int idx=u;
    while (idx<=n)
    {
        bit[idx]+=v;
        idx+=(idx&(-idx));
    }
}
int getSum(int u)
{
    int ans=0,idx=u;
    while (idx>0)
    {
        ans+=bit[idx];
        idx-=(idx&(-idx));

    }
    return ans;
}
void updateRange(int l , int r, int v)
{
    update(l,v);
    update(r+1,-v);
}
int main()
{
    fast;
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
    cin>>n>>m;
    memset(bit,0,sizeof bit);
    FORW(i,1,n)
    {
        int t;
        cin>>t;
        update(i,t);
    }

    FORW(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        cout<<getSum(v)-getSum(u-1)<<endl;
    }
}



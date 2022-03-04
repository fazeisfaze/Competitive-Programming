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
int n,m,d,k;
int p[10000][10000];
vector<ii> M;
int main()
{
    fast;
    freopen("HAINAM.INP","r",stdin);
    freopen("HAINAM.OUT","w",stdout);
    cin>>n>>m>>d>>k;
    FORW(i,1,n)
     FORW(j,1,m){
         char c;
         cin>>c;
         p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
         if (c=='M') M.pb({i,j});
         if (c=='S') p[i][j]++;
     }
     int res=0;
     int x1,y2,x2,y1;

    for (auto v: M){
         x2=(v.fi+d>m)?n:v.fi+d;
         y2=(v.se+d>n)?m:v.se+d;
         x1=(v.fi-d<1)?1:v.fi-d;
         y1=(v.se-d<1)?1:v.se-d;
        int val=p[x2][y2]-p[x2][y1-1]-p[x1-1][y2]+p[x1-1][y1-1];
        if (val>=k)
            res++;
    }
    cout<<res;
}



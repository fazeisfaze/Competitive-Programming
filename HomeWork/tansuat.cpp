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
int n,k;
int a[300001];
double preMin[3000001];
double b[300001];
bool check(double x){
    FORW(i,1,n)
        b[i]=b[i-1] +(a[i]-x),preMin[i]=min(preMin[i-1],b[i]);

    double res=-999999;
    FORW(i,k,n)
          res=max(res,b[i]-preMin[i-k]);
    return res>=0;

}
int main()
{
    fast;
    freopen("rate.INP","r",stdin);
    freopen("rate.OUT","w",stdout);
    cin>>n>>k;
    double r=0;
    FORW(i,1,n)
     cin>>a[i],r=max((double)a[i],r);
     double res;
    double l=0;
    const double eps= 1e-7;
    while (r-l>eps){
        double mid = (l+r+eps)/2.0;
   //     cout<<mid<<endl;
        if (check(mid)){
            res=mid;
            l=mid;
        }
        else
            r=mid-eps;
    }
 //   cout<<check(3.6);
   cout<<setprecision(6)<<fixed<<res;
}



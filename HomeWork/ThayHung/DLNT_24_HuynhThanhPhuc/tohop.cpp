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
const double bound = 100000000;
int main()
{
    fast;
    freopen("TOHOP.INP","r",stdin);
    freopen("TOHOP.OUT","w",stdout);
    int p,q,r,s;
    double res=1;
    cin>>p>>q>>r>>s;
    int n= r-s;
    int m= p-q;
    queue<double> chia;
    while(chia.size()) chia.pop();
    chia.push(q);
    chia.push(r);
    chia.push(m);
    double t=0;
    FORW(i,1,p){

        res*=i;
        if (t==0&&chia.size()) t= chia.front(),chia.pop();
        while (res>=bound&&t)
            res/=t,t--;
    }
    FORW(i,1,s){

        res*=i;
        if (t==0&&chia.size()) t= chia.front(),chia.pop();
        while (res>=bound&&t)
            res/=t,t--;
    }
    FORW(i,1,n){
        res*=i;
        if (t==0&&chia.size()) t= chia.front(),chia.pop();
        while (res>=bound&&t)
            res/=t,t--;
    }
    while(chia.size()||t){
        if(t==0&&chia.size()) t=chia.front(),chia.pop();
        while(t) res/=t,t--;
    }
    cout<<setprecision(5)<<fixed<<res;

}


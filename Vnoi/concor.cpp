#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<double,double> ii;
#define FORW(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for (int i=a;i>=b;i--)
#define forw(i,a,b) for (ll i=a;i<=b;i++)
#define forb(i,a,b) for (ll i=a;i>=b;i--)
#define fast {ios::sync_with_stdio(false); cin.tie(0); }
#define F first
#define S second
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
ii pnt[100000];
bool check[100001];
int s,n,d;
struct point{
    double r,d;
    ii pos;
    point(ii _pos,double _r,double _d){
        pos=_pos;
        r=_r;
        d=_d;
    }
};
double minDistance(ii A, ii B, ii E)
{

    // vector AB
    ii AB = {B.fi-A.fi,B.se-A.se}, AE= {E.fi-A.fi,E.se-A.se}, BE={E.fi-B.fi,E.se-B.se};
    double AB_BE, AB_AE;
    AB_BE = (AB.F * BE.F + AB.S * BE.S);
    AB_AE = (AB.F * AE.F + AB.S * AE.S);

    double reqAns = 0;

    // Case 1
    if (AB_BE > 0) {

        // Finding the magnitude
        double y = E.S - B.S;
        double x = E.F - B.F;
        reqAns = sqrt(x * x + y * y);
    }

    // Case 2
    else if (AB_AE < 0) {
        double y = E.S - A.S;
        double x = E.F - A.F;
        reqAns = sqrt(x * x + y * y);
    }

    // Case 3
    else {

        // Finding the perpendicular distance
        double x1 = AB.F;
        double y1 = AB.S;
        double x2 = AE.F;
        double y2 = AE.S;
        double dis = sqrt(x1 * x1 + y1 * y1);
        reqAns = abs(x1 * y2 - y1 * x2) / dis;
    }
    return reqAns;
}
vector<point> radar;
int main()
{
    fast;
    freopen("concor.INP","r",stdin);
    freopen("concor.OUT","w",stdout);
    cin>>s>>n>>d;
    FORW(i,1,s){
        int x,y,r,m;
        cin>>x>>y>>r>>m;
        radar.pb(point({x,y},r,m));

    }
    pnt[0]={0,0};
    pnt[n+1]={0,0};
    FORW(i,1,n){
        cin>>pnt[i].fi>>pnt[i].se;

    }
    int res=0;

    double c;
    memset(check, 0, sizeof check);
    FORW(i,0,n){
        for (int j = 0;j<radar.size();j++){
            if (check[j]) continue;
            double pntSegDis= minDistance(pnt[i],pnt[i+1],radar[j].pos)-radar[j].r;
            if (pntSegDis<=d){

                check[j]=1;
                res+=radar[j].d;
            }
        }
    }
    cout<<res<<endl;

}



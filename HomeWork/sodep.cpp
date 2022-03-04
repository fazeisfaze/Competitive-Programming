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
int p[100001];
bool check(int n){
    stringstream ss;
    ss << n;
    string s = ss.str();
    int i = s.size()-1;
    if (s[i]=='2'||s[i]=='5'||s[i]=='7'||s[i]=='9')
        return true;
    return false;


}
int main()
{
    fast;
    freopen("SODEP.INP","r",stdin);
    freopen("SODEP.OUT","w",stdout);
    FORW(i,1,100000){
        p[i]+=p[i-1];
        if (check(i))
            p[i]++;
    }
    int t;
    cin>>t;
    while(t--){
        int u,v;
        cin>>u>>v;
     cout<<p[v]-p[u]<<endl;
    }

}



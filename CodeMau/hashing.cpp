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
const int LIM = 1e6+1;
const int base = 31;
ll Pow[LIM],hashA[LIM];
string a,b;
ll getHash(int i, int j){
    return (hashA[j]-hashA[i-1]*Pow[j-i+1]+mod*mod)%mod;

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>a>>b;
    ll hashB=0;
    FORW(i,0,b.size()-1)
        hashB=(hashB *base+ b[i]-'a'+1)%mod;
    Pow[0]=1;
    hashA[0]=0;
    FORW(i,1,a.size()){
        Pow[i]=(Pow[i-1]*base)%mod;
        hashA[i]=(hashA[i-1]*base+a[i-1]-'a'+1)%mod;
    }
    FORW(i,0,a.size()-b.size())
     if (hashB==getHash(i+1,i+b.size()))
        cout<<i+1<<" ";


}



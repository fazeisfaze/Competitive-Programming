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
ll p[55][55];
void solve(int test){
    string save[4];
    string s;
    cin>>s;
    int t=0;
    FORW(i,1,s.size()-1){
        if (s[i]==')') break;
        if (s[i]!='+'&&s[i]!='-')
            save[t].pb(s[i]);
        else{
            t++;
            save[t].pb(s[i]);
            t++;
        }
    }
    save[3]=s[s.size()-1];
    cout<<"Case "<<test<<": ";
    int k=save[3][0]-'0';
    FORW(i,0,k){
            if(i)  cout<<save[1];
            if(p[k][i] != 1)
                cout<<p[k][i]<<"*";
            if(i != k) {
                cout<<save[0];
                if(k-i != 1)
                    cout<<"^"<<k-i;
                if(i)   cout<<"*";
            }
            if(i) {
                cout<<save[2];
                if(i != 1)
                    cout<<"^"<<i;
            }
        }
    cout<<endl;

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    p[0][0]=1;
    FORW(i,1,50){
        p[i][0]=1;
        FORW(j,1,i)
         p[i][j]=p[i-1][j]+p[i-1][j-1];

    }
    int t;
    cin>>t;
    FORW(i,1,t) solve(i);
}


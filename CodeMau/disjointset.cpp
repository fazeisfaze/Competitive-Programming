
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

int par[2309];
int n;
int anc(int p){

    if (par[p]==p) return p;
    else return par[p] = anc(par[p]);
}

void join(int p, int q){
    par[anc(p)] = anc(q);
}

main(){
    int i, p, q, m;
    scanf("%d", &n);
    for (i=1; i<=n; i++) par[i] = i;

    scanf("%d", &m);
    for (i=1; i<=m; i++) {
        scanf("%d%d", &p, &q);
        join(p, q);
        join(q,p);
    }
    FORW(i,1,n)
     cout<<par[i]<<" ";

}

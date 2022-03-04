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
const int oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
const int mxN = 1e3+7;
int a[mxN];
int d[50000];
int n;
void dijkstra(int s){
    FORW(i,0,a[1]-1)
     d[i]=oo;
     priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({d[s]=0,s});
    while(pq.size()){
        int du = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (du!=d[u]) continue;
        FORW(i,2,n){
            int dv = du+a[i], v = (u + a[i])%a[1];
            if (dv<d[v])
                pq.push({d[v]=dv,v});

        }
    }

}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n;
    FORW(i,1,n)
        cin>>a[i];
    dijkstra(0);
    int m;
    cin>>m;
    while(m--){
        int z ;
        cin>>z;
        cout<<((z>=d[z%a[1]])?"TAK":"NIE")<<endl;

    }
}



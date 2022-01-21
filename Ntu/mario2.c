#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int, ii> pii;
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
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const ll oo=1e9;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m;
int a[701][701],b[701][701],d[701][701];
void dijkstra(int x,int y)
{
    priority_queue<pii, vector<pii>, greater<pii> > q;
    FORW(i,1,n)
     FORW(j,1,m)
        d[i][j]=oo;
    d[x][y]=0;
    q.pu({0,{x,y}});
    while (q.size())
    {
        int val = q.top().fi;
        ii v=q.top().se;
        q.pop();
        if (val>d[v.fi][v.se]) continue;
        FORW(k,0,3)
        {

            int xx = v.fi+dX[k],yy=v.se+dY[k];
            if (xx<1||xx>n||yy<1||yy>m) continue;
            int dist= (k==0||k==2)?a[xx][yy]:b[xx][yy];
            if (d[xx][yy]>d[v.fi][v.se]+dist)
                q.pu({d[xx][yy]=d[v.fi][v.se]+dist,{xx,yy}});

        }


    }
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m;
    FORW(i,1,n)
     FORW(j,2,m)
      cin>>a[i][j];
    FORW(i,2,n)
     FORW(j,1,m)
      cin>>b[i][j];
    FORW(i,1,n)
     a[i][1]=a[i][2];
    FORW(i,1,m)
     b[1][i]=b[2][i];
    dijkstra(1,1);
    cout<<d[n][m];
}

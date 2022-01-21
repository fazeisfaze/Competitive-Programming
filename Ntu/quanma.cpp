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
int dX[] ={-2,-1,1,2,2,1,-1,-2};
int dY[]= {1,2,2,1,-1,-2,-2,-1};
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int d[1001][1001],visited[1001][1001];
int n,m,x1,y1,x2,y2;
bool check(ii u )
{
    return (u.fi>0&&u.se>0&&u.fi<=n&&u.se<=m);
}
void bfs(int s1, int s2)
{
    queue<ii> q;
    q.push({s1,s2});
    d[s1][s2]=0;
    visited[s1][s2]=1;
    while(q.size())
    {
        ii u = q.front();
        q.pop();
        FORW(k,0,7)
        {
            ii v= {u.fi+dX[k],u.se+dY[k]};
            if (check(v)&&!visited[v.fi][v.se])
            {
                q.push(v);
                visited[v.fi][v.se]=1;
                d[v.fi][v.se]=d[u.fi][u.se]+1;
            }
        }
    }
}
int main()
{
    fast;
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    cin>>n>>m>>x1>>y1>>x2>>y2;
    bfs(x1,y1);
    cout<<((visited[x2][y2])?d[x2][y2]:-1)<<endl;
}



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
const int N = 1e5;
int n,m;
ll t[4 * N];

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1]+ t[i<<1|1];
}

void modify(int p, int value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {
    ll res=0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res+= t[l++];
    if (r&1) res+= t[--r];

  }
  return res;
}
int main() {
  cin>>n>>m;
  FORW(i,1,m)
  {
    int op,u,v;
    cin>>op>>u>>v;
    if (op==1)
        modify(u-1, v);
   else
   cout<<query(u-1,v)<<endl;;
  }

  return 0;
}


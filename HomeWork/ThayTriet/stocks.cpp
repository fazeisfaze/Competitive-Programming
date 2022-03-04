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
const int mxN=5e4+7;
int n,k;
int mx[mxN],mn[mxN],a[mxN];
struct segtree{
	int size;
	vector<int> mx,mn;
	segtree(int n){
		size = 4*n;
		mx.assign(size,0);
        mn.assign(size,0);
	}

	void build(int vt , int l , int r){
		if( l == r){
			mx[vt] = a[l];
			mn[vt] = a[l];
			return;
		}
		int mid = (l + r)/2;
		build(vt*2 , l , mid);
		build(vt*2+1 , mid+1 , r);
		mx[vt] = max(mx[vt*2], mx[vt*2+1]);
		mn[vt] = min(mn[vt*2], mn[vt*2+1]);
	}

	void build(){
		build(1 , 0 , n-1);
	}
	int getMax(int vt , int l , int r , int u , int v){
		if(l > v || r < u)
			return -1e9;
		if(u <= l && r <= v)
			return mx[vt];
		int mid = (l + r) / 2;
		return max(getMax(vt*2 , l , mid , u , v) , getMax(vt*2+1 , mid+1 , r , u , v));
	}
    int getMin(int vt , int l , int r , int u , int v){
		if(l > v || r < u)
			return 1e9;
		if(u <= l && r <= v)
			return mn[vt];
		int mid = (l + r) / 2;
		return min(getMin(vt*2 , l , mid , u , v) , getMin(vt*2+1 , mid+1 , r , u , v));
	}

	int get(int u , int v){
		return getMax(1 , 0 , n-1 , u-1 , v-1)- getMin(1, 0, n-1, u-1, v-1);
	}
};

int main()
{
    fast;
    freopen("stocks.INP","r",stdin);
    freopen("stocks.OUT","w",stdout);
    cin>>n>>k;
    segtree seg(n);
    FORW(i,0,n-1){
        cin>>a[i];
    }
    seg.build();

    while(k--){
        int u,v;
        cin>>u>>v;
        cout<<seg.get(u,v)<<endl;
    }


}




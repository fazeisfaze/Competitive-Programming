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
int dX[] ={0,-1,0,1};
int dY[]= {-1,0,1,0};
const ll oo=1e18;
const ll MOD=1e9+7;
const ll mod=1e9+9;
int n,m;
struct Segtree{
    int size;
    set<int> value[10000];
    int temp[1000];
    void init (int n)
     {
         size =1;
         while(size<n)
            size*=2;

     }
    void build(vector<int> &a,int x, int lx, int rx)
    {
        if (rx-lx==1)
        {

            if (lx<(int)a.size())
            {
             value[x].insert(a[lx]);
             temp[x]=a[lx];
            }

            return;
        }
        int mid = (lx+rx)>>1;
        build (a,2*x+1,lx,mid);
        build (a,2*x+2,mid,rx);


    }
    void build(vector<int> &a)
    {
       build(a,0,0,size);
    }

    void Set(int u, int v, int x, int lx, int rx)
    {
        if (rx-lx==1)
        {
           value[x].erase(temp[x]);
           temp[x]=v;
           value[x].insert(v);
           return ;
        }
        int mid = (rx+lx)>>1;
        if (mid> u )
            Set(u,v,2*x+1,lx,mid);
        else Set(u,v,2*x+2,mid,rx);
        for (auto v: value[2*x+1])
            value[x].insert(v);
        for (auto v: value[2*x+2])
            value[x].insert(v);



    }
    void Set(int u, int v)
    {
      Set(u-1,v,0,0,size);
    }
    ll getvalue(int l,int r, int x,int k, int lx,int rx)
    {
        if (lx>=r||rx<=l)
            return INT_MAX;
        if (lx>=l&&rx<=r){
            auto it = value[x].lower_bound(k);
            return (*it);
        }

        int mid = (lx+rx)>>1;
        return min(getvalue(l,r,2*x+1,k,lx,mid),getvalue(l,r,2*x+2,k,mid,rx));

    }
    ll getvalue(int l, int r,int k)
     {
         return getvalue(l-1,r,0,k,0,size);
     }

};
int main()
{
    fast;
   // freopen("segment.INP","r",stdin);
   // freopen("segment.OUT","w",stdout);
    cin>>n>>m;
    vector<int> a(n);
    Segtree st;
  //  st.init(n);
    for (int i = 0;i<n;i++)
       cin>>a[i];
//    st.build(a);
//    FORW(i,1,m)
//    {
//        int op,u,v,k;

//        cin>>op>>u>>v;
//        if (op==1)
//        {
//            st.Set(u,v);
//
//        }
//        else{
//            int k;
//            cin>>k;
//            cout<<st.getvalue(u,v,k)<<endl;
//        }
//
//    }
}

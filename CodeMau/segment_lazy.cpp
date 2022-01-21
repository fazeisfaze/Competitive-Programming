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
const int N = 1e5+1;
struct Node
{
    ll lazy;
    ll val;
};
Node st[4*N];
ll a[N],n,m;
void down(int id,int l,int r)
{
    int t= st[id].lazy;
    if (t!=0)
    {
        st[id].val+=t;
        if (l!=r)
        {
            st[id*2].lazy+=t;
            st[id*2+1].lazy+=t;

        }
        st[id].lazy=0;
    }

}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].val=a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
void update(int id,int l, int r, int u,int v,int value )
{
    down(id,l,r);
    if (l>r||r<u||r<u)
        return ;
     if (u<=l&&r<=v)
     {
         st[id].val+=value;
         if (l!=r)
         {
                st[id*2].lazy+=value;
                st[id*2+1].lazy+=value;
         }

         return;
     }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,value);
    update(id*2+1,mid+1,r,u,v,value);
    st[id].val=max(st[id*2+1].val,st[id*2].val);

}
ll getMax(int id,int l,int r, int u ,int v)
{
    if (v<l||r<u||l>r)
         return -oo;
    down(id,l,r);
    if (u<=l&&r<=v)
    {
        return st[id].val;
    }
    int mid=(l+r)/2;

    return max(getMax(id*2,l,mid,u,v),getMax(id*2+1,mid+1,r,u,v));
}
int main()
{
    fast;
  //  freopen("SEGMENTLAZY.INP","r",stdin);
   // freopen("SEGMENTLAZY.OUT","w",stdout);
    cin>>n;
    FORW(i,1,n)
     cin>>a[i];
    build(1,1,n);
    cin>>m;
    FORW(i,1,m)
     {
        int op ;
        cin>>op;
        if (op==1)
        {
            int u,v,val;
            cin>>u>>v>>val;
            update(1,1,n,u,v,val);

        }
        else
        {
            int u,v;
            cin>>u>>v;
            cout<<getMax(1,1,n,u,v)<<endl;

        }
     }
}



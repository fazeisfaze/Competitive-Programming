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
const int N = 1e6;

string s;
int m;
struct Node {
    int open;
    int close;
    int optimal;
    Node(){};
    Node(int _open,int _close,int _optimal){
        open =_open;
        close= _close;
        optimal= _optimal;
    }

};
Node operator +(const Node& left,const  Node& right)
    {
        Node res;
        int tmp = min(left.open,right.close);
        res.optimal=left.optimal+right.optimal +tmp;
        res.open = left.open+right.open-tmp;
        res.close = left.close+right.close-tmp;
        return res;


    };
Node st[4*N];
void build(int id, int l , int r)
{
    if (l==r)
    {
        if (s[r]=='(')
                st[id]= Node (1,0,0);
        else
             st[id]=Node(0,1,0);
        return;
    }
    int mid= (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]= st[id*2]+st[id*2+1];

}
Node query(int id,int l,int r,int u, int v)
{
    if (v<l||r<u) return Node(0,0,0);
    if (u<=l&&r<=v)
        return st[id];
    int mid = (l+r)/2;
    return query(2*id,l,mid,u,v)+query(2*id+1,mid+1,r,u,v);

}
int main()
{
    fast;
   // freopen("380cSEGMENT.INP","r",stdin);
   // freopen("380csegment.OUT","w",stdout);
    cin>>s>>m;
    build(1,0,s.size()-1);
    FORW(i,1,m)
     {
         int u,v;
         cin>>u>>v;
         cout<<query(1,0,s.size()-1,u-1,v-1).optimal*2<<endl;

     }

}



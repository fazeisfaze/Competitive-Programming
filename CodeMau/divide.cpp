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
bool operator >=(const string a, const string b){
    if (a.size()!=b.size()) return a.size()>b.size();
    for (int i = 0;i<a.size();i++)
        if (a[i]-'0'>b[i]-'0')
            return 1;
        else if (a[i]-'0'<b[i]-'0')
            return 0;

    return 1;
}
string operator - ( string a, string b ){
    int carry = 0;
    while (a.size()>b.size()) b='0'+b;
    for (int j = a.size()-1;j>=0;j--){
        int temp = b[j]-'0'+carry;
        carry=0;
        if (a[j]-'0'<temp){
            a[j]=((a[j]-'0')+10-temp)+'0';
            carry=1;
        }
        else a[j]=((a[j]-'0')-temp)+'0';
    }
    return a;
}
pair<string,string>  operator /(string a, string b){
    string s3,s4;
    for (int i = 0;i<a.size();i++){
    s3.push_back(a[i]);
    int  sdu=0;
    while (s3>=b){
          s3=s3-b;
          sdu++;
          while (s3.size()!=0&&s3[0]=='0') s3.erase(0,1);
          while (b.size()!=0&&b[0]=='0') b.erase(0,1);
        }
        s4.push_back(char(sdu+48));
    }
    while (s4.size() &&s4[0]=='0') s4.erase(0,1);
    return {s4,s3};

}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<(s1/s2).fi<<endl<<(s1/s2).se<<endl;
}
int main()
{
    fast;
    freopen("DIVIDE.INP","r",stdin);
    freopen("DIVIDE.OUT","w",stdout);
    int t;
    cin>>t;
    while(t--) solve();


}



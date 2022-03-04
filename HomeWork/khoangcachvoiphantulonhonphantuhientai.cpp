#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000000],n;
stack<int> st;
const int mxN=1e5;
int lmn[mxN], lmx[mxN], rmn[mxN], rmx[mxN];
int main(){
    cin>>n;
    for (int i = 1;i<=n;i++)
     cin>>a[i];
    for (int i = 1;i<=n;i++){
        while (!st.empty()&&a[st.top()]>=a[i])
            st.pop();
        l[i]=st.empty()?0:;
        st.push(i);
    }
    while(st.size()) st.pop();
    for (int i = n;i>=1;i--){
        while (!st.empty()&&a[st.top()]>=a[i])
            st.pop();
        r[i]=st.empty()?n+1:i-st.top();
        st.push(i);
    }
    ll res=0;
    for (int i = 1 ;i<=n;i++)
        res+=1LL*a[i]*(i-l[i])*(r[i]-i);
    cout<<res;

}

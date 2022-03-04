#include <bits/stdc++.h>
using namespace std;
int a[1000000],n;
stack<int>  st;
vector<int> res;
int main(){
    cin>>n;
    for (int i = 1;i<=n;i++)
     cin>>a[i];
    res.resize(n+1);
    for (int i = n;i>=1;i--){
        while (!st.empty()&&st.top()<=a[i])
            st.pop();
        res[i]=st.empty()?0:st.top();
        st.push(a[i]);
    }


}

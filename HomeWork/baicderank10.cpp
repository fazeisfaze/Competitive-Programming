#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL);
#define PI acos(-1.0)
#define eps 1e-9
#define FF first
#define SS second
// VECTOR (6)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define uniq(v) sort(all( (v) )), (v).resize( unique(all( (v) )) - (v).begin() );
// BIT (6)
#define CNTBIT(x) __builtin_popcountll(x)
#define ODDBIT(x) __builtin_parityll(x)
#define MASK(i) (1LL<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define SUBSET(big, small) (((big)&(small))==(small))
#define MINBIT(x) (x)&(-x)
//typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, int> ii;
/* CODE BELOW */
const int N = 4e5 + 7, M = 1e9 + 7;
const int oo = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, k, t;

int l[N], r[N], a[N];

ll solveMin() { // calculate sum min of all subarray
    stack<int> st;

    a[0] = -1; st.push(0);
    for(int i=1;i<=n;i++) {
        while(sz(st)&&a[st.top()]>=a[i]) {
            st.pop();
        }
        l[i] = st.top(); st.push(i);
    }
    while(sz(st)) st.pop();

    a[n+1] = -1; st.push(n+1);
    for(int i=n;i>0;i--) {
        while(sz(st)&&a[st.top()]>a[i]) st.pop();
        r[i] = st.top(); st.push(i);
    }

    ll ans = 0;
    for(int i=1;i<=n;i++) {
        cout<< (i - l[i]) * (r[i] - i)<<endl;
    }
    return 0;

}
ll solveMax() { // calculate sum max of all subarray
    stack<int> st;

    a[0] = oo; st.push(0);
    for(int i=1;i<=n;i++) {
        while(sz(st)&&a[st.top()]<=a[i]) {
            st.pop();
        }
        l[i] = st.top(); st.push(i);
    }
    while(sz(st)) st.pop();

    a[n+1] = oo; st.push(n+1);
    for(int i=n;i>0;i--) {
        while(sz(st)&&a[st.top()]<a[i]) st.pop();
        r[i] = st.top(); st.push(i);
    }

    ll ans = 0;
    for(int i=1;i<=n;i++) {
        ans+= 1LL * a[i] * (i - l[i]) * (r[i] - i);
    }
    return ans;
}

signed main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    //fastIO;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
    }
    ll sumMax = solveMax();
    ll sumMin = solveMin();

 //   printf("%lld", sumMax - sumMin);

    return 0;
}

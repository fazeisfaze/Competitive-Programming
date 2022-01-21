#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[111][111];
bool vs[111][111];
int n;

void dfs(int i, int j, int st, int en) {
    if(i<0 || i>=n || j<0 || j>=n) return;
    if(vs[i][j]) return;
    if(a[i][j] < st || a[i][j] > en) return;
    vs[i][j] = true;
    for(int dx=-1;dx<=1;++dx) for(int dy=-1;dy<=1;++dy) if((dx==0) ^ (dy==0)) dfs(i+dx,j+dy,st,en);
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) scanf("%d", a[i]+j);
    int left = 0, right = 111;
    while(left<right) {
        int mid = (left+right) / 2;
        bool ok = false;
        for(int st=0;st<=111;++st) {
            memset( vs, 0, sizeof(vs));
            dfs(0,0,st,st+mid);
            if(vs[n-1][n-1]) {
                ok = true;
                break;
            }
        }
        if (ok) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
    return 0;
}

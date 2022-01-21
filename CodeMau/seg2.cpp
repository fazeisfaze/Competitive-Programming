#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long

void setFile(string a){
	if(a == "remu")
		return;

	freopen((a + ".inp").c_str() , "r" , stdin);
	freopen((a + ".out").c_str() , "w" , stdout);
}

int n;
vector<int> a;

struct segtree{
	int size;
	vector<int> tree;
	vector<int> lazy;

	void init(int n){
		size = 4*n;
		tree.resize(size);
		lazy.resize(size , 0);
	}

	void push(int u){
		int x = lazy[u];
		lazy[u] = 0;

		tree[u*2] += x;
		lazy[u*2] += x;
		tree[u*2+1] += x;
		lazy[u*2+1] += x;
	}

	void build(int vt , int l , int r){
		if( l == r){
			tree[vt] = a[l];
			return;
		}

		int mid = (l + r)/2;
		build(vt*2 , l , mid);
		build(vt*2+1 , mid+1 , r);
		tree[vt] = max(tree[vt*2] , tree[vt*2+1]);
	}

	void build(){
		build(1 , 0 , n-1);
	}

	void update(int vt , int l , int r , int u , int v , int x){
		//cout << vt << " " << l << " " << r << " " << tree[vt] << endl;
		if(l > v || r < u)
			return;

		if(u <= l && r <= v){
			tree[vt] += x;
			lazy[vt] += x;
			return;
		}

		push(vt);

		int mid = (l + r) / 2;
		update(vt*2 , l , mid , u , v , x);
		update(vt*2+1 , mid+1 , r , u , v , x);

		tree[vt] = max(tree[vt*2] , tree[vt*2+1]);
	}

	void update(int u , int v , int x){
		update(1 , 0 , n-1 , u , v , x);
	}

	int get(int vt , int l , int r , int u , int v){
		if(l > v || r < u)
			return -1e18;

		if(u <= l && r <= v)
			return tree[vt];

		push(vt);

		int mid = (l + r) / 2;

		return max(get(vt*2 , l , mid , u , v) , get(vt*2+1 , mid+1 , r , u , v));
	}

	int get(int u , int v){
		return get(1 , 0 , n-1 , u , v);
	}

	void print(int vt , int l , int r){
		cout << vt << " " << l << " " << r << " " << tree[vt] << " " << lazy[vt] << endl;
		if(l == r)
			return;

		int mid = (l + r) / 2;
		print(vt*2 , l , mid);
		print(vt*2+1 , mid+1 , r);
	}

	void print(){
		print(1 , 0 , n-1);
	}

};

void solve(){
	cin >> n;
	a.resize(n);
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	segtree seg;
	seg.init(n);
	seg.build();

	int q;
	cin >> q;
	int p , u , v , x;
	for(int i = 0 ; i < q ; i++){
		cin >> p >> u >> v;
		if(p == 1){
			cin >> x;
			seg.update(u-1 , v-1 , x);
			//seg.print();
		}else{
			cout << seg.get(u-1 , v-1) << endl;
			//seg.print();
		}
	}

}

int32_t main(){
	setFile("remu");
	solve();
	return 0;
}

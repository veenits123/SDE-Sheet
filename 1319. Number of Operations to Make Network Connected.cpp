// never the same!!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <iomanip>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

//const int N = 1e5 + 5;

class Solution {
public:
	const int N = 1e5 + 5;
	vector<int> par;

	int makeConnected(int n, vector<vector<int>>& connections) {
		if (n - 1 > connections.size())
			return -1;
		init();
		int connected = 0;
		for (auto x : connections) {
			int u = x[0];
			int v = x[1];
			if (findParent(u) != findParent(v)) {
				unite(u, v);
				connected++;
			}
		}
		return (n - 1) - connected;
	}

	void init() {
		par.resize(N);
		for (int i = 0; i < N; i++)
			par[i] = i;
	}

	int findParent(int n) {
		if (n == par[n])
			return n;
		return par[n] = findParent(par[n]);
	}

	void unite(int u, int v) {
		int x = findParent(u);
		int y = findParent(v);
		if (x != y) {
			if (x > y)
				swap(x, y);
			par[y] = x;
		}
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;

	for (int i = 0; i < 4; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}

	cout << Solution().makeConnected(n, edges);

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}
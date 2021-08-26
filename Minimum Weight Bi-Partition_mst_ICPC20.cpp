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

const int N = 1e5 + 5;

vector<int> par(N);

void init() {
	REP(i, 0, N)
	par[i] = i;
}

int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}

void unite(int u, int v) {
	int x = find(u);
	int y = find(v);
	if (y != x) {
		if (x > y )
			swap(x, y);
		par[y] = x;
	}
}

void solve() {

	init();
	int n, m; cin >> n >> m;

	vector<P> addEdges;
	REP(i, 1, n) {
		int val; cin >> val;
		addEdges.pb({val, i});
	}

	vector<P> edges;

	REP(i, 0, m - 1) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}

	vector<P> ansEdges;

	//given edges act as 0 weight edges;
	for (auto x : edges) {
		int u = x.F;
		int v = x.S;
		if (find(u) != find(v)) {
			unite(u, v);
			ansEdges.pb({u, v});
		}
	}
	
	sort(all(addEdges));

	vector<pair<int, P>> extraEdges;

	REP(i, 0, n - 2) {
		int u = addEdges[i].S;
		int v = addEdges[i + 1].S;
		int w = addEdges[i + 1].F - addEdges[i].F;
		extraEdges.pb({w, {u, v}});
	}

	sort(all(extraEdges));

	int sum = 0;
	for (auto x : extraEdges) {
		int u = x.S.F;
		int v = x.S.S;
		int w = x.F;
		if (find(u) != find(v)) {
			unite(u, v);
			sum += w;
			ansEdges.pb({u, v});
		}
	}

	cout << sum << " " << sz(ansEdges) << endl;

	for (auto x : ansEdges)
		cout << x.F << " " << x.S << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t; while (t--)
		solve();

	return 0;
}
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

class Solution {
public:
	vector<int> par;

	vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

		for (int i = 0; i < edges.size(); i++) {
			edges[i].pb(i);
		}
		sort(edges.begin(), edges.end(), comp);

		vector<int> critical;
		vector<int> pseudoCritical;

		int minST = minSpanTree(n, edges, -1);

		for (int i = 0; i < edges.size(); i++) {

			int discardEdge = minSpanTree(n, edges, i);

			int preTaken = minSpanTree(n, edges, -1, i);

			if (minST < discardEdge)
				critical.pb(edges[i][3]);

			else if (minST == preTaken)
				pseudoCritical.pb(edges[i][3]);
		}
		return {critical, pseudoCritical};
	}
	int minSpanTree(int n, vector<vector<int>>& edges, int discard, int foundInSome = -1) {
		init();

		int weight = 0;

		if (foundInSome != -1) {
			int u = edges[foundInSome][0];
			int v = edges[foundInSome][1];
			int w = edges[foundInSome][2];
			if (findParent(u) != findParent(v)) {
				unite(u, v);
				weight += w;
			}
		}

		for (int i = 0; i < edges.size(); i++) {
			if (i == discard)
				continue;
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			if (findParent(u) != findParent(v)) {
				unite(u, v);
				weight += w;
			}
		}
		for (int i = 0; i < n; i++) {
			if (findParent(i) != findParent(0))
				return (int)1e9;
		}
		return weight;
	}
	static bool comp(vector<int>& a, vector<int>& b) {
		return a[2] < b[2];
	}

	void init() {
		par.resize(101);
		for (int i = 0; i < 101; i++)
			par[i] = i;
	}
	int findParent(int n) {
		if (par[n] == n)
			return n;
		return par[n] = findParent(par[n]);
	}
	void unite(int x, int y) {
		int u = findParent(x);
		int v = findParent(y);
		if (u != v) {
			if (u > v)
				swap(u, v);
			par[v] = u;
		}
	}
};

void solve() {

	int n; cin >> n;

	vector<vector<int>> edges;
	for (int i = 0; i < 7; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.pb({u, v, w});
	}
	auto ans = Solution().findCriticalAndPseudoCriticalEdges(n, edges);

	//cout << ans[0].size() << endl;

	for (auto x : ans) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}

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
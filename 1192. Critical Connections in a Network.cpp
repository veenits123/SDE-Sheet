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
	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
		vector<vector<int>> graph(n);
		for (auto x : connections) {
			int u = x[0];
			int v = x[1];
			graph[u].pb(v);
			graph[v].pb(u);
		}

		vector<bool> visited(n, false);
		vector<int> low(n, -1);
		vector<int> entry(n, -1);
		vector<vector<int>> ans;
		int timer = 0;

		for (int i = 0; i < n; i++) {
			if (!visited[i])
				dfs(graph, i, -1, visited, entry, low, timer, ans);
		}

		return ans;
	}
	void dfs(vector<vector<int>>& graph, int src, int parent, vector<bool>& visited,
	         vector<int>& entry, vector<int>& low, int timer, vector<vector<int>>& ans) {

		visited[src] = true;
		entry[src] = low[src] = timer++;

		for (auto to : graph[src]) {
			if (to == parent)
				continue;

			if (!visited[to]) {

				dfs(graph, to, src, visited, entry, low, timer, ans);

				low[src] = min(low[src], low[to]);
				if (low[to] > entry[src]) {
					ans.pb({src, to});
				}
			}
			else {
				low[src] = min(low[src], entry[to]);
			}
		}
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;
	REP(i, 0, 3) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}
	auto ans = Solution().criticalConnections(n, edges);

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
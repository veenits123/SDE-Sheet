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
	bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> color(n, -1);
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				if (!dfs(graph, i, 0, color))
					return false;
			}
		}
		return true;
	}
	bool dfs(vector<vector<int>>& graph, int src, int col, vector<int>& color) {
		color[src] = col;
		for (auto to : graph[src]) {
			if (color[to] == -1) {
				//cout << col << endl;
				if (!dfs(graph, to, col ^ 1, color))
					return false;
			}
			else {
				if (color[to] == color[src])
					return false;
			}
		}
		return true;
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> graph(n);

	for (int i = 0; i < 3; i++) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	cout << (Solution().isBipartite(graph) ? "YES" : "NO") << endl;

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
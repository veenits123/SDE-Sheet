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
	int removeStones(vector<vector<int>>& stones) {
		int ans = 0;
		int n = stones.size();
		vector<bool> vis(n, false);
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				dfs(i, vis, stones);
				ans++;
			}
		}
		ans = n - ans;
		return ans;
	}

	void dfs(int src, vector<bool>& vis, vector<vector<int>>& edges) {
		int x = edges[src][0];
		int y = edges[src][1];
		vis[src] = true;
		for (int i = 0; i < edges.size(); i++) {
			if (!vis[i] &&
			        (edges[i][0] == x || edges[i][1] == y)) {
				dfs(i, vis, edges);
			}
		}
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;

	for (int i = 0; i < n; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}

	cout << Solution().removeStones(edges);

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
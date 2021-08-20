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
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		vector<int> connections(n, 0);
		map<int, vector<int>> graph;
		for (auto x : roads) {
			int u = x[0];
			int v = x[1];
			connections[u]++;
			connections[v]++;

			graph[u].pb(v);
			graph[v].pb(u);
		}
		int maximalNetworkRank = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int tempNetworkRank = connections[i] + connections[j];

				if (find(all(graph[i]), j) != graph[i].end())
					tempNetworkRank--;

				maximalNetworkRank = max(maximalNetworkRank, tempNetworkRank);
			}
		}
		return maximalNetworkRank;
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;

	for (int i = 0; i < 4; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}

	cout << Solution().maximalNetworkRank(n, edges);

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
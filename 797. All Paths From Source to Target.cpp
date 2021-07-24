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
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		return bfs(graph, 0, graph.size() - 1);
	}
	vector<vector<int>> bfs(vector<vector<int>>& graph, int src, int tgt) {
		vector<vector<int>> ans;

		queue <vector<int>> q;

		vector <int> path;
		path.pb(src);
		q.push(path);

		while (!q.empty()) {
			auto temp = q.front();
			q.pop();
			int curVertex = temp[temp.size() - 1];

			if (curVertex == tgt) {
				ans.pb(temp);
			}

			for (auto to : graph[curVertex]) {

				vector <int> newPath = temp;
				newPath.pb(to);

				q.push(newPath);
			}
		}
		return ans;
	}
	bool isVisited(vector <int>& path, int node) {
		for (int i = 0; i < path.size(); i++)
			if (node == path[i])
				return true;
		return false;
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> graph(n);

	for (int i = 0; i < 4; i++) {
		int u, v; cin >> u >> v;
		graph[u].pb(v);
	}
	auto ans = Solution().allPathsSourceTarget(graph);

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
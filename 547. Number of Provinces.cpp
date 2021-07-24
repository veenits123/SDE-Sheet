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
	int findCircleNum(vector<vector<int>>& isConnected) {
		int n = isConnected.size();
		vector<bool> vis(n, 0);

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				cnt++;
				dfs(i, vis, isConnected);
			}
		}
		return cnt;
	}

	void dfs(int src, vector<bool>& vis, vector<vector<int>>& graph) {
		vis[src] = true;

		for (int i = 0; i < graph.size(); i++) {
			if (src == i)
				continue;

			if (!vis[i] && graph[src][i] == 1)
				dfs(i, vis, graph);
		}
	}
};

void solve() {

	vector<vector<int>> graph(3, vector <int>(3, 0));

	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
			cin >> graph[i][j];

	cout << Solution().findCircleNum(graph);

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
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
	int row[4] = {0, 0, -1, 1};
	int col[4] = { -1, 1, 0, 0};

	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, false));

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1' && !vis[i][j]) {
					dfs(grid, vis, i, j);
					cnt++;
				}
			}
		}
		return cnt;
	}
	void dfs(vector<vector<char>>& graph, vector<vector<bool>>& vis, int x, int y) {
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int r = x + row[i];
			int c = y + col[i];
			if (isValid(r, c, graph.size(), graph[0].size()) && !vis[r][c] && graph[r][c] == '1')
				dfs(graph, vis, r, c);
		}
	}
	bool isValid(int i, int j, int n, int m) {
		return (i >= 0 && i < n && j >= 0 && j < m);
	}
};

void solve() {

	int n, m; cin >> n >> m;
	vector<vector<char>> graph(n, vector<char>(m));

	REP(i, 0, n - 1)
	REP(j, 0, m - 1)
	cin >> graph[i][j];

	cout << Solution().numIslands(graph) << endl;

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
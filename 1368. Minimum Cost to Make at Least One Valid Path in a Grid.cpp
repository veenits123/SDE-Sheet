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
	int row[5] = {0, 0, 0, 1, -1};
	int col[5] = {0, 1, -1, 0, 0};

	int minCost(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> dis(n, vector<int>(m, 1e9));

		bfs(0, 0, grid, dis);
		return dis[n - 1][m - 1];
	}
	void bfs(int sx, int sy, vector<vector<int>>& graph,
	         vector<vector<int>>& dis) {
		int n = graph.size();
		int m = graph[0].size();

		deque<pair<int, int>> q;
		q.push_front({sx, sy});

		dis[sx][sy] = 0;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop_front();
			int x = cur.F;
			int y = cur.S;

			int direction = graph[x][y];

			for (int i = 1; i <= 4; i++) {
				int r = x + row[i];
				int c = y + col[i];

				int cost = (direction == i) ? 0 : 1;

				if (isValid(r, c, n, m)) {
					if (dis[r][c] > dis[x][y] + cost) {
						dis[r][c] = dis[x][y] + cost;
						if (cost == 0) {
							q.push_front({r, c});
						}
						else {
							q.push_back({r, c});
						}
					}
				}
			}
		}

	}
	bool isValid(int r, int c, int n, int m) {
		return (r >= 0 && c >= 0 && r < n && c < m);
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> graph[i][j];
	}

	cout << Solution().minCost(graph);

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
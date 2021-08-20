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
	int col[4] = {1, -1, 0, 0};

	int orangesRotting(vector<vector<int>>& grid) {
		return bfs(grid);
	}
	int bfs(vector<vector<int>>& graph) {

		int n = graph.size();
		int m = graph[0].size();

		queue<pair<int, int>> q;

		int freshOrange = 0;
		int minutes = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 2) {
					q.push({i, j});
				}
				if (graph[i][j] == 1)
					freshOrange++;
			}
		}
		if (freshOrange == 0)
			return 0;

		while (!q.empty()) {
			int sz = q.size();
			while (sz--) {
				int curX = q.front().F;
				int curY = q.front().S;
				q.pop();

				bool flag = false;
				for (int i = 0; i < 4; i++) {

					int r = curX + row[i];
					int c = curY + col[i];

					if (isValid(r, c, n, m) && graph[r][c] == 1) {
						graph[r][c] = 2;
						q.push({r, c});
						freshOrange--;
					}
				}
			}
			minutes++;
		}
		if (freshOrange > 0)
			return -1;
		return minutes;
	}
	bool isValid(int x, int y, int n, int m) {
		return (x >= 0 && x < n && y >= 0 && y < m);
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	cout << Solution().orangesRotting(graph) << endl;

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
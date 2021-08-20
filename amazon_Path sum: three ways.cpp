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
#include <climits>
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

int row[3] = {0, -1, 1};
int col[3] = {1, 0, 0};

bool isValid(int i, int j, int n, int m) {
	return (i > 0 && i < n && j > 0 && j < m);
}

void dijkstra(vector<vector<int>>& graph, vector<vector<int>>& distance) {
	int n = graph.size();
	int m = graph[0].size();
	priority_queue<pair<int, P>, vector<pair<int, P>>, greater<pair<int, P> >> q;
	for (int i = 0; i < n; i++) {
		int w = graph[i][0];
		int x = i;
		int y = 0;
		q.push({w, {x, y}});
	}
	while (!q.empty()) {
		auto x = q.top();
		q.pop();
		int cost = x.F;
		int i = x.S.F;
		int j = x.S.S;
		for (int ind = 0; ind < 3; ind++) {
			int r = i + row[ind];
			int c = j + col[ind];
			if (isValid(r, c, n, m)) {
				int curWeight = graph[r][c];
				if (distance[r][c] > cost + curWeight) {
					distance[r][c] = cost + curWeight;
					q.push({distance[r][c], {r, c}});
				}
			}
		}
	}
}

int pathSum(vector<vector<int>>& graph, int n, int m) {
	vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

	dijkstra(graph, distance);

	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
		ans = min(ans, distance[i][m - 1]);
	return ans;
}

void solve() {

	vector<vector<int>> graph;

	for (int i = 0; i < 80; i++) {
		vector<int> temp;

		string str; cin >> str;
		stringstream ss(str);

		// Parse the string
		for (int i; ss >> i;) {
			temp.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}
		graph.pb(temp);
	}

	auto ans = pathSum(graph, 80, 80);

	cout << ans << endl;

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
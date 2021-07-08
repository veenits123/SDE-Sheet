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

bool isPossible(int node, bool graph[101][101], int V, int color[], int col) {
	REP(k, 0, V - 1) {
		if (k != node && graph[k][node] == 1 && color[k] == col)
			return false;
	}
	return true;
}

bool helper(bool graph[101][101], int V, int node, int m, int color[]) {
	if (node == V)
		return true;
	REP(col, 1, m) {
		if (isPossible(node, graph, V, color, col)) {
			color[node] = col;
			if (helper(graph, V, node + 1, m, color))
				return true;
			color[node] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
	// your code here
	int color[V] = {0};
	return helper(graph, V, 0, m, color);
}

void solve() {

	bool graph[101][101];

	int n, e, m; cin >> n >> e >> m;

	REP(i, 0, n - 1)
	memset(graph[i], 0, sizeof(graph[i]));

	REP(i, 0, e - 1) {
		int a, b; cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	cout << (graphColoring(graph, m, n) ? "YES" : "NO") << endl;

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
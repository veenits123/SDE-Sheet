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
//#include <priority_queue>
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

vector <int> graph[N];
vector <int> vis(N);
vector <int> dis(N);
vector <int> par(N);

void dfs(int src) {
	vis[src] = 1;
	for (auto to : graph[src]) {
		if (!vis[to])
			dfs(to);
	}
}

void bfs(int src) {
	queue <int> q;
	q.push(src);
	par[src] = -1;
	vis[src] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto to : graph[cur]) {
			if (!vis[to]) {
				vis[to] = 1;
				q.push(to);
				par[to] = cur;
				dis[to] = dis[cur] + 1;
			}
		}
	}
}

void dijkstra(int src) {
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	while (!q.empty()) {
		auto x = q.top();
		int w = x.F;
		int cur = x.S;
		for (auto to : graph[cur]) {
			int cost = to.S;
			int node = to.F;
			if (dis[node] > dis[cur] + cost) {
				dis[node] = dis[cur] + cost;
				q.push({dis[node], node});
			}
		}
	}
}

//kruskal's algorithm;
int parent[N];
void init() {
	for (int i = 0; i < N; i++)
		parent[i] = i;
}

int find(int n) {
	if (n == parent[n])
		return n;
	return parent[n] = find(parent[n]);
}
void unite(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u != v) {
		if (x < y)
			swap(x, y);
		parent[y] = x;
	}
}
int kruskal() {
	int sum = 0;
	for (auto x : edges) {
		int w = x.F;
		int u = x.S.F;
		int v = x.S.S;
		if (find(u) != find(v)) {
			unite(u, v);
			sum += w;
		}
	}
	return sum;
}

bool bipartite(int src, int col) {
	vis[src] = 1;
	color[src] = col;
	for (auto to : graph[src]) {
		if (!vis[to]) {
			if (bipartite(to, col ^ 1) == false)
				return false;
		}
		else {
			if (color[src] == color[to])
				return false;
		}
	}
	return true;
}

//cycle;
bool dfs(int src, int par) {
	color[src] = 1;
	for (auto to : graph[src]) {
		if (to == par)
			continue;
		if (color[to] == 0) {
			parent[to] = src;
			if (dfs(to, parent[to]))
				return true;
		}
		else {
			if (color[to] == 1 && to != par) {
				start = to;
				end = src;
				return true;
			}
		}
	}
	color[src] = 2;
	return false;
}

void solve() {

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
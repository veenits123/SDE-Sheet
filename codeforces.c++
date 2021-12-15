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
#include <stack>
#include <climits>
using namespace std;

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
const int N = 1e5 + 5;

vector <pair<int,int>> graph[N];
vector <int> vis(N);
vector <int> dis(N);
vector <int> par(N);


void dijkstra(int src) {
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({0, src});
	dis[src] = 0;
	par[src] = -1;
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
				par[node] = cur;
			}
		}
	}
}

bool comp(pair<int,int>& a,pair<int,int>& b){
	if(a.S>=b.S)
		return true;
	return false;
}

void solve() {

	// vis.fill

	// int n,m;cin>>n>>m;
	// vector<pair<int,int>> check(n);

	// for(int i=0;i<m;i++){
	// 	int x,y,w;cin>>x>>y>>w;
	// 	check[x].F=x;
	// 	check[x].S +=w;
	// 	check[y].F=y;
	// 	check[y].S +=(-1)*w;

	// 	graph[y].pb({x,w});
	// }
	// sort(check.begin(),check.end(),comp);

	// int source=check[check.size()-1].F;
	// int dest=check[0].F;

	// cout<<check[0].F<<" "<<check[check.size()-1].F<<endl;

	// dijkstra(source);

	// cout<<dis[dest];

	int x=__builtin_popcount(7);
	cout<<x<<endl;

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

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
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
	                            vector<vector<string>>& queries) {
		//make graph;
		map<string, map<string, double>> graph;
		for (int i = 0; i < equations.size(); i++) {
			string u = equations[i][0];
			string v = equations[i][1];
			double cost = values[i];
			graph[u].insert({v, cost});
			if (cost != 0)
				graph[v].insert({u, 1.0 / cost});
		}

		map<string, double> distance;
		map<string, bool> vis;

		vector<double> ans;

		for (auto x : queries) {
			string src = x[0];
			string tgt = x[1];
			auto temp = bfs(src, tgt, distance, vis, graph);

			if (temp != 0)
				ans.pb(temp);
			else
				ans.pb(-1.0);
			distance.clear();
			vis.clear();
		}

		return ans;
	}
	double bfs(string src, string des, map<string, double>& distance, map<string, bool>& vis,
	           map<string, map<string, double>>& graph) {
		queue <pair<string, double>> q;
		q.push({src, 1.0});
		distance[src] = 1.0;
		vis[src] = true;

		while (!q.empty()) {
			auto x = q.front();
			q.pop();
			string cur = x.F;
			double cost = x.S;

			if (graph[cur].find(des) != graph[cur].end()) {
				return graph[cur][des] * cost;
			}

			for (auto x : graph[cur]) {
				if (!vis[x.F]) {
					vis[x.F] = true;
					distance[x.F] = cost * x.S;
					q.push({x.F, distance[x.F]});

					if (x.F == des)
						return distance[x.F];
				}
			}
		}
		return 0;
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<string>> equations;
	for (int i = 0; i < n; i++) {
		string u, v; cin >> u >> v;
		equations.pb({u, v});
	}
	vector<double> values;
	for (int i = 0; i < n; i++) {
		double val; cin >> val;
		values.pb(val);
	}
	vector<vector<string>> queries;

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string u, v; cin >> u >> v;
		queries.pb({u, v});
	}
	auto ans = Solution().calcEquation(equations, values, queries);

	for (auto x : ans)
		cout << x << " ";
	cout << endl;

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
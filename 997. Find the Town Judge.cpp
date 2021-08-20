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
	int findJudge(int n, vector<vector<int>>& trust) {
		vector<int> outDegree(n + 1, 0);
		vector<int> inDegree(n + 1, 0);

		for (auto x : trust) {
			int u = x[0];
			int v = x[1];
			inDegree[v]++;
			outDegree[u]++;
		}
		for (int i = 1 ; i <= n; i++)
			if (outDegree[i] == 0 && inDegree[i] == n - 1)//everyone trust him except himself so (n-1);
				return i;
		return -1;
	}
};

void solve() {

	int n; cin >> n;
	vector<vector<int>> edges;

	for (int i = 0; i < 2; i++) {
		int u, v; cin >> u >> v;
		edges.pb({u, v});
	}

	cout << Solution().findJudge(n, edges);

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
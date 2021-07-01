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

//mera apnaa logic ;)
// class Solution {
// public:
// 	vector<vector<int>> merge(vector<vector<int>>& intervals) {
// 		return helper(intervals, sz(intervals));
// 	}
// 	vector<vector<int>> helper(vector<vector<int>>& a, int n) {
// 		vector<vector<int>> ans;
// 		ans.pb(a[0]);
// 		for (auto x : a) {
// 			auto v = x;
// 			auto temp = ans.back();
// 			if (v[0] <= temp[1] && (v[1] >= temp[1])) {
// 				vi flag;
// 				ans.pop_back();
// 				flag.pb(temp[0]), flag.pb(v[1]);
// 				ans.pb(flag);
// 			}
// 			else if (v[0] <= temp[1] && (v[1] <= temp[1])) {
// 				vi flag;
// 				ans.pop_back();
// 				flag.pb(temp[0]), flag.pb(temp[1]);
// 				ans.pb(flag);
// 			}
// 			else {
// 				ans.pb(x);
// 			}
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(all(intervals));
		int n = sz(intervals);
		vector <vi> ans;
		auto temp = intervals[0];
		for (auto x : intervals) {
			if (x[0] <= temp[1])
				temp[1] = max(x[1], temp[1]);
			else {
				ans.pb(temp);
				temp = x;
			}
		}
		ans.pb(temp);
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vector <vi> a(n, vi(2));

	REP(i, 0, n - 1) {
		cin >> a[i][0] >> a[i][1];
	}

	auto ans = Solution().merge(a);

	for (auto x : ans) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}

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
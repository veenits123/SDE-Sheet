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

// class Solution {
// public:
// 	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
// 		vector<vector<int>> ans;
// 		vector <int> temp;
// 		int n = sz(candidates);
// 		helper(candidates, n, 0, target, ans, temp);
// 		return ans;
// 	}

// 	void helper(vector<int>& candidates, int n, int index, int target, vector<vector<int>> &ans, vector <int> &temp) {
// 		if (index == n) {
// 			if (target == 0)
// 				ans.pb(temp);
// 			return ;
// 		}
// 		if (target >= candidates[index]) {
// 			temp.pb(candidates[index]);
// 			helper(candidates, n, index, target - candidates[index], ans, temp);
// 			temp.pop_back();
// 		}
// 		helper(candidates, n, index + 1, target, ans, temp);
// 	}
// };


class Solution {
public:
	vector <vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector <int> temp;
		vector <vector<int>> ans;
		int n = sz(candidates);
		sort(all(candidates));
		helper(candidates, n, 0, target, ans, temp);
		return ans;
	}

	void helper(vector<int>& candidates, int n, int index, int target, vector<vector<int>> &ans, vector <int> &temp) {
		if (target == 0) {
			ans.pb(temp);
			return ;
		}
		for (int i = index; i < n; i++) {
			if (candidates[i] > target)
				break;
			temp.pb(candidates[i]);
			helper(candidates, n, i, target - candidates[i], ans, temp);
			temp.pop_back();
		}
	}
};

void solve() {

	int n; cin >> n;
	int tgt; cin >> tgt;

	vi arr(n);
	REP(i, 0, n - 1) cin >> arr[i];

	auto ans = Solution().combinationSum(arr, tgt);

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

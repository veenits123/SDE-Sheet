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

//sc: O(n);
// class Solution {
// public:
// 	vector<vector<int>> permute(vector<int>& nums) {
// 		vector <vector<int>> ans;
// 		vector <int> temp;
// 		vector <int> freq(nums.size(), 0);
// 		helper(nums, freq, temp, ans);
// 		return ans;
// 	}

// 	void helper(vector <int>& arr, vector <int>& freq, vector <int>& temp, vector<vector<int>>& ans) {
// 		if (temp.size() == arr.size()) {
// 			ans.push_back(temp);
// 			return ;
// 		}
// 		for (int i = 0; i < arr.size(); i++) {
// 			if (!freq[i]) {
// 				freq[i] = 1;
// 				temp.push_back(arr[i]);
// 				helper(arr, freq, temp, ans);
// 				freq[i] = 0;
// 				temp.pop_back();
// 			}
// 		}
// 	}
// };

//sc: O(1);
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		generatePermutation(nums, 0, ans);
		return ans;
	}

	void generatePermutation(vector <int>& arr, int l, vector <vector <int>>& ans) {
		if (l == arr.size()) {
			ans.push_back(arr);
			return ;
		}
		for (int i = l; i < arr.size(); i++) {
			swap(arr[i], arr[l]);
			generatePermutation(arr, l + 1, ans);
			swap(arr[i], arr[l]);
		}
	}
};

void solve() {

	int n; cin >> n;

	vi arr(n);
	REP(i, 0, n - 1) cin >> arr[i];

	auto ans = Solution().permute(arr);

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
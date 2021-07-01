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
// 	int longestConsecutive(vector<int>& nums) {
// 		sort(all(nums));

// 		auto it = unique(all(nums));
// 		nums.resize(distance(nums.begin(), it));

// 		int n = sz(nums);
// 		if (n == 0)
// 			return 0;
// 		if (n == 1)
// 			return 1;
// 		int ans = 0;
// 		int temp = 1;
// 		REP(i, 0, n - 2) {
// 			if (nums[i] + 1 == nums[i + 1])
// 				temp++;
// 			else
// 				temp = 1;
// 			ans = max(ans, temp);
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		set <int> m;
		int n = sz(nums);
		for (auto x : nums)
			m.insert(x);
		int ans = 0;
		for (auto x : m) {
			if (!m.count(x - 1)) {
				int cnt = 1;
				int i = x;
				while (m.count(i + 1)) {
					i++;
					cnt++;
					//cout << cnt << " " << i << endl;
				}
				//cout << endl;
				ans = max(ans, cnt);
			}
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << Solution().longestConsecutive(a);

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
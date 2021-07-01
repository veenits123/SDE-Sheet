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

//tc: O(n^2), sc: O(1);
// class Solution {
// public:
// 	int trap(vector<int>& height) {
// 		int n = sz(height);
// 		int cnt = 0;

// 		REP(i, 0, n - 1) {
// 			int l_max = -1, r_max = -1;

// 			REV(l, i, 0)
// 			l_max = max(l_max, height[l]);

// 			REP(r, i + 1, n - 1)
// 			r_max = max(r_max, height[r]);

// 			//cout << l_max << " " << r_max << endl;

// 			int temp = min(l_max, r_max) - height[i];

// 			cnt += (temp > 0) ? temp : 0;
// 			//cout << cnt << endl;
// 		}
// 		return cnt;
// 	}
// };

//tc: O(n), sc: O(n);
// class Solution {
// public:
// 	int trap(vector<int>& height) {
// 		int n = sz(height);
// 		if (n == 0)
// 			return 0;

// 		int preMax[n], sufMax[n];

// 		preMax[0] = height[0];
// 		REP(i, 1, n - 1) preMax[i] = max(preMax[i - 1], height[i]);

// 		sufMax[n - 1] = height[n - 1];
// 		REV(i, n - 2, 0) sufMax[i] = max(sufMax[i + 1], height[i]);

// 		int cnt = 0;
// 		REP(i, 0, n - 1) {
// 			int cur = min(preMax[i], sufMax[i]) - height[i];

// 			//cout << preMax[i] << " " << sufMax[i] << endl;

// 			cnt += (cur > 0) ? cur : 0;
// 		}
// 		return cnt;
// 	}
// };

//tc: O(n), sc: O(1);
class Solution {
public:
	int trap(vector<int>& height) {
		int n = sz(height);
		if (n == 0)
			return 0;

		int ans = 0;

		int l = 0, r = n - 1;
		int leftMax = 0, rightMax = 0;

		while (l <= r) {
			if (height[l] <= height[r]) {
				if (height[l] >= leftMax)
					leftMax = height[l];
				else
					ans += leftMax - height[l];
				l++;
			}
			else {
				if (height[r] >= rightMax)
					rightMax = height[r];
				else
					ans += rightMax - height[r];
				r--;
			}
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << Solution().trap(a);

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
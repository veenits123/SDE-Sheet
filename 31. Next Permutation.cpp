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
	void nextPermutation(vector<int>& nums) {
		int n = sz(nums);
		int ind1 = -1, ind2 = -1;
		REV(i, n - 2, 0) {
			if (nums[i] < nums[i + 1]) {
				ind1 = i;
				break;
			}
		}
		if (ind1 < 0) {
			reverse(all(nums));
		}
		else {
			REV(i, n - 1, ind1) {
				if (nums[i] > nums[ind1]) {
					ind2 = i;
					break;
				}
			}
			swap(nums[ind1], nums[ind2]);
			reverse(nums.begin() + ind1 + 1, nums.end());
		}
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);

	REP(i, 0, n - 1) cin >> a[i];

	Solution().nextPermutation(a);
	for (auto x : a)
		cout << x << " ";

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
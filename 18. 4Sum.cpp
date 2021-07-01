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
// 	vector<vector<int>> fourSum(vector<int>& nums, int target) {
// 		set <vi> st;
// 		int n = sz(nums);
// 		sort(all(nums));
// 		vi temp;
// 		REP(i, 0, n - 1) {
// 			REP(j, i + 1, n - 1) {
// 				REP(k, j + 1, n - 1) {
// 					int x = target - (nums[i] + nums[j] + nums[k]);
// 					if (binary_search(nums.begin() + k + 1, nums.end(), x)) {
// 						temp.pb(nums[i]), temp.pb(nums[j]), temp.pb(nums[k]), temp.pb(x);
// 						st.insert(temp);
// 						temp.clear();
// 					}
// 				}
// 			}
// 		}
// 		vector <vi> ans;
// 		for (auto x : st)
// 			ans.pb(x);
// 		return ans;
// 	}
// };


class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(all(nums));
		int n = sz(nums);
		vector <vi> ans;

		REP(i, 0, n - 1) {
			REP(j, i + 1, n - 1) {
				int left = j + 1, right = n - 1;
				while (left < right) {
					int target_2 = target - (nums[i] + nums[j]);
					int rem_2 = nums[left] + nums[right];

					if (target_2 > rem_2)
						left++;

					else if (target_2 < rem_2)
						right--;

					else {
						vi temp;
						temp.pb(nums[i]);
						temp.pb(nums[j]);
						temp.pb(nums[left]);
						temp.pb(nums[right]);
						ans.pb(temp);

						//avoiding duplicate of no.3
						while (left < right && nums[left] == temp[2])
							left++;
						//avoiding duplicate of no.4
						while (left < right && nums[right] == temp[3])
							right--;
					}
				}
				//avoiding duplicate of no.2
				while ((j + 1) < n && nums[j + 1] == nums[j])
					j++;
			}
			//avoiding duplicate of no.1
			while ((i + 1) < n && nums[i + 1] == nums[i])
				i++;
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	int target; cin >> target;

	auto ans = Solution().fourSum(a, target);

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
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

//O(n^3); TLE :(
// class Solution {
// public:
// 	vector<vector<int>> threeSum(vector<int>& nums) {
// 		int n = sz(nums);
// 		set <vi> s;
// 		REP(i, 0, n - 1) {
// 			REP(j, i + 1, n - 1) {
// 				REP(k, j + 1, n - 1) {
// 					vi temp(3);
// 					if (nums[i] + nums[j] + nums[k] == 0) {
// 						temp[0] = nums[i], temp[1] = nums[j], temp[2] = nums[k];

// 						sort(all(temp));
// 						s.insert(temp);
// 					}
// 				}
// 			}
// 		}
// 		vector <vi> ans;
// 		for (auto x : s)
// 			ans.pb(x);
// 		return ans;
// 	}
// };

//O(n^2 logn); TLE :(
// class Solution {
// public:
// 	vector<vector<int>> threeSum(vector<int>& nums) {
// 		int n = sz(nums);
// 		map <int, int> m;
// 		for (auto x : nums)
// 			m[x]++;
// 		set <vi> s;
// 		REP(i, 0, n - 1) {
// 			m[nums[i]]--;
// 			REP(j, i + 1, n - 1) {
// 				m[nums[j]]--;

// 				int rem1 = (-1) * (nums[i] + nums[j]);
// 				if (m[rem1]) {
// 					vi temp(3);
// 					temp[0] = nums[i], temp[1] = nums[j], temp[2] = rem1;
// 					sort(all(temp));
// 					s.insert(temp);
// 				}
// 				m[nums[j]]++;
// 			}
// 			m[nums[i]]++;
// 		}
// 		vector <vi> ans;
// 		for (auto x : s)
// 			ans.pb(x);
// 		return ans;
// 	}
// };

//O(n^2);
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = sz(nums);
		sort(all(nums));

		vector <vi> ans;

		REP(i, 0, n - 1) {

			int a = nums[i];
			int target = (-1) * a;

			int left = i + 1, right = n - 1;
			while (left < right) {
				int borc = nums[left] + nums[right];

				if (borc < target)
					left++;
				else if (borc > target)
					right--;
				else {
					vi temp(3);
					temp[0] = nums[i], temp[1] = nums[left], temp[2] = nums[right];
					ans.pb(temp);

					//avoid duplicate b;
					while (left < right && nums[left + 1] == nums[left])
						left++;
					//avoid duplicate c;
					while (left < right && nums[right - 1] == nums[right])
						right--;

					//avoid taking same b && c;
					left++, right--;
				}
			}
			//avoid duplicate a;
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

	auto ans = Solution().threeSum(a);

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
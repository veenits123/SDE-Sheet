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
	vector<int> majorityElement(vector<int>& nums) {
		int n = nums.size();
		int elem1 = -1, elem2 = -1;
		int cnt1 = 0, cnt2 = 0;
		for (auto x : nums) {
			if (elem1 == x)
				cnt1++;
			else if (elem2 == x)
				cnt2++;
			else if (cnt1 == 0)
				elem1 = x, cnt1 = 1;
			else if (cnt2 == 0)
				elem2 = x, cnt2 = 1;
			else
				cnt1--, cnt2--;
		}
		vector <int> ans;
		int cnt_elem1 = 0, cnt_elem2 = 0;
		for (auto x : nums) {
			if (x == elem1)
				cnt_elem1++;
			if (x == elem2)
				cnt_elem2++;
		}
		if (cnt_elem1 > n / 3)
			ans.pb(elem1);
		if (cnt_elem2 > n / 3)
			ans.pb(elem2);
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	auto ans = Solution().majorityElement(a);
	for (int x : ans)
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
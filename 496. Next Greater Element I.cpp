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
#include <stack>
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
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();
		stack <int> s;

		map <int, int> mp;

		REV(i, m - 1, 0) {
			int temp = nums2[i];
			while (!s.empty()) {
				if (s.top() > temp) {
					mp[temp] = s.top();
					s.push(temp);
					break;
				}
				else {
					s.pop();
				}
			}
			if (s.empty()) {
				mp[temp] = -1;
				s.push(temp);
			}
		}
		vector <int> res;
		for (auto x : nums1)
			res.pb(mp[x]);

		return res;
	}
};

void solve() {

	int n; cin >> n;
	vi num1(n);
	REP(i, 0, n - 1) cin >> num1[i];

	int m; cin >> m;
	vi num2(m);
	REP(i, 0, m - 1) cin >> num2[i];

	auto ans = Solution().nextGreaterElement(num1, num2);

	for (auto x : ans)
		cout << x << " ";
	cout << endl;

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
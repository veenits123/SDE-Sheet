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
// 	int lengthOfLongestSubstring(string s) {
// 		int n = sz(s);
// 		int ans = 0;
// 		int l = 0, r = 0;
// 		map <char, int> m;
// 		while (r < n) {
// 			if (m[s[r]]) {
// 				while (m[s[r]]) {
// 					m[s[l]] = 0;
// 					l++;
// 				}
// 			}
// 			ans = max(ans, (r - l + 1));
// 			m[s[r]] = 1;
// 			r++;
// 		}
// 		return ans;
// 	}
// };

//vector :)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = sz(s);
		int ans = 0;
		int l = 0, r = 0;
		vi lastIndex(256, -1);
		while (r < n) {
			if (lastIndex[s[r]] != -1)
				l = max(l, lastIndex[s[r]] + 1);

			ans = max(ans, r - l + 1);

			lastIndex[s[r]] = r;
			r++;
		}
		return ans;
	}
};

//map ;)
// class Solution {
// public:
// 	int lengthOfLongestSubstring(string s) {
// 		int n = sz(s);
// 		int ans = 0;
// 		int l = 0, r = 0;
// 		map <char, int> m;
// 		while (r < n) {
// 			int lastIndex = (m.find(s[r]) != m.end()) ? m[s[r]] : -1;

// 			l = max(l, lastIndex + 1);

// 			ans = max(ans, r - l + 1);

// 			m[s[r]] = r;
// 			r++;
// 		}
// 		return ans;
// 	}
// };

void solve() {

	string s; cin >> s;

	cout << Solution().lengthOfLongestSubstring(s) << endl;

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
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
// 	string longestPalindrome(string s) {
// 		int n = s.size();

// 		bool dp[n][n];
// 		memset(dp, false, sizeof(dp));

// 		for (int i = 0; i < n; i++) {
// 			dp[i][i] = true;

// 			if (i == n - 1) break;

// 			dp[i][i + 1] = (s[i] == s[i + 1]);
// 		}

// 		for (int len = 3; len <= n; len++) {
// 			for (int i = 0; i < n - len + 1; i++) {
// 				int j = len + i - 1;
// 				dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
// 			}
// 		}
// 		string ans = "";
// 		int len = 0;

// 		for (int i = 0; i < n; i++) {
// 			for (int j = i; j < n; j++) {
// 				if (dp[i][j] == true && j - i + 1 > len) {
// 					len = j - i + 1;
// 					ans = s.substr(i, j - i + 1);
// 				}
// 			}
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty() || s.size() == 0)
			return "";
		if (s.size() == 1)
			return s;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++) {
			int oddLenghtPallindrome = expandFromCentre(s, i, i);
			int evenlengthPallindrome = expandFromCentre(s, i, i + 1);
			int len = max(oddLenghtPallindrome, evenlengthPallindrome);

			if (len > end - start) {
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
	int expandFromCentre(string s, int left, int right) {
		int l = left, r = right;
		while (l >= 0 && r < s.size() && s[l] == s[r]) {
			l--;
			r++;
		}
		return (r - l - 1);
	}
};

void solve() {


	string s; cin >> s;
	cout << Solution().longestPalindrome(s);


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
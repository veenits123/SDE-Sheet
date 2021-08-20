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
	int countSubstrings(string s) {
		return longestPalindrome(s);
	}
	int longestPalindrome(string s) {
		int n = s.size();

		bool dp[n][n];
		memset(dp, false, sizeof(dp));

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;

			if (i == n - 1) break;

			dp[i][i + 1] = (s[i] == s[i + 1]);
		}

		for (int len = 3; len <= n; len++) {
			for (int i = 0; i < n - len + 1; i++) {
				int j = len + i - 1;
				dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (dp[i][j] == true)
					ans++;
			}
		}
		return ans;
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
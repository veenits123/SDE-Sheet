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
// 	int uniquePaths(int m, int n) {
// 		return helper(0, 0, m, n);
// 	}
// 	int helper(int i, int j, int m, int n) {
// 		if (i >= m || j >= n)
// 			return 0;
// 		if (i == m - 1 && j == n - 1)
// 			return 1;
// 		return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
// 	}
// };

// class Solution {
// public:
// 	int uniquePaths(int m, int n) {
// 		vector <vi> dp(m, vi(n, -1));

// 		return helper(0, 0, m, n, dp);
// 	}
// 	int helper(int i, int j, int m, int n, vector <vi> &dp) {
// 		if (i >= m || j >= n)
// 			return 0;
// 		if (i == m - 1 && j == n - 1)
// 			return 1;
// 		if (dp[i][j] != -1)
// 			return dp[i][j];
// 		return dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
// 	}
// };

//combinatrics ;)
class Solution {
public:
	int uniquePaths(int m, int n) {
		int total_direction = m + n - 2; //(m-1)->down + (n-1)->right;
		//ans=(total_direction)C(any one direction (down=m-1 or right=n-1))
		//NCr, N=total_direction, r=m-1;
		int N = total_direction;
		int r = m - 1;
		double res = 1;
		REP(i, 1, r) {
			res *= (N - r + i);//numenator
			res /= i;//denominator
		}
		return (int)res;
	}
};

void solve() {

	int m, n; cin >> m >> n;

	cout << Solution().uniquePaths(m, n);

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
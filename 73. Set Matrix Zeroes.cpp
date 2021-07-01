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
#include <climits>
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

//SC : O(m*n);
// class Solution {
// public:
// 	void setZeroes(vector<vector<int>>& matrix) {
// 		auto temp = matrix;
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (matrix[i][j] == 0) {
// 					REP(x, 0, n - 1)
// 					temp[x][j] = 0;

// 					REP(y, 0, m - 1)
// 					temp[i][y] = 0;
// 				}
// 			}
// 		}
// 		matrix = temp;
// 	}
// };

//SC : O(m*n);
// class Solution {
// public:
// 	void setZeroes(vector<vector<int>>& matrix) {
// 		vector <P> index;
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (matrix[i][j] == 0)
// 					index.pb({i, j});
// 			}
// 		}
// 		for (auto x : index) {
// 			int r = x.F, c = x.S;

// 			REP(i, 0, n - 1)
// 			matrix[i][c] = 0;

// 			REP(j, 0, m - 1)
// 			matrix[r][j] = 0;
// 		}
// 	}
// };

//SC : O(m+n);
// class Solution {
// public:
// 	void setZeroes(vector<vector<int>>& matrix) {
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		vi row(n, -1), col(m, -1);
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (matrix[i][j] == 0)
// 					row[i] = 0, col[j] = 0;
// 			}
// 		}
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (row[i] == 0 || col[j] == 0)
// 					matrix[i][j] = 0;
// 			}
// 		}
// 	}
// };

//SC : O(1);
// const int inf = INT_MIN;
// if the lowest value matrix[i][j] can get is greater than INT_MIN;
// class Solution {
// public:
// 	void setZeroes(vector<vector<int>>& matrix) {
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (matrix[i][j] == 0) {
// 					REP(x, 0, n - 1) {
// 						if (matrix[x][j] != 0)
// 							matrix[x][j] = inf;
// 					}
// 					REP(y, 0, m - 1) {
// 						if (matrix[i][y] != 0)
// 							matrix[i][y] = inf;
// 					}
// 				}
// 			}
// 		}
// 		REP(i, 0, n - 1) {
// 			REP(j, 0, m - 1) {
// 				if (matrix[i][j] == inf)
// 					matrix[i][j] = 0;
// 			}
// 		}
// 	}
// };

//SC : O(1);
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int n = sz(matrix);
		int m = sz(matrix[0]);
		bool col = true;
		REP(i, 0, n - 1) {
			if (matrix[i][0] == 0)
				col = false;
			REP(j, 1, m - 1) {
				if (matrix[i][j] == 0) {

					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		REV(i, n - 1, 0) {
			REV(j, m - 1, 1) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
					matrix[i][j] = 0;
			}
			if (!col)
				matrix[i][0] = 0;
		}
	}
};

void solve() {

	int n, m; cin >> n >> m;
	vector <vi> a(n, vi(m));

	REP(i, 0, n - 1)
	REP(j, 0, m - 1)
	cin >> a[i][j];

	Solution().setZeroes(a);

	REP(i, 0, n - 1) {
		REP(j, 0, m - 1)
		cout << a[i][j] << " ";
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
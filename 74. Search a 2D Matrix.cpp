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

//O(nlog(m));
// class Solution {
// public:
// 	bool searchMatrix(vector<vector<int>>& matrix, int target) {
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		REP(i, 0, n - 1) {
// 			if (binary_search(matrix[i], 0, m - 1, target))
// 				return true;
// 		}
// 		return false;
// 	}
// 	bool binary_search(vi &a, int low, int high, int key) {
// 		while (low <= high) {
// 			int mid = (low + high) / 2;

// 			if (a[mid] == key)
// 				return true;

// 			else if (a[mid] < key)
// 				low = mid + 1;

// 			else if (a[mid] > key)
// 				high = mid - 1;
// 		}
// 		return false;
// 	}
// };

//O(m+n);
// class Solution {
// public:
// 	bool searchMatrix(vector<vector<int>>& matrix, int target) {
// 		int n = sz(matrix);
// 		int m = sz(matrix[0]);
// 		int i = 0, j = m - 1;
// 		while (i < n && j >= 0) {
// 			if (matrix[i][j] == target)
// 				return true;
// 			else if (matrix[i][j] > target)
// 				j--;
// 			else if (matrix[i][j] < target)
// 				i++;
// 		}
// 		return false;
// 	}
// };

//O(log(m*n));
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = sz(matrix);
		int m = sz(matrix[0]);
		return binary_search(matrix, 0, (m * n) - 1, target);
	}

	bool binary_search(vector<vector<int>>& a, int low, int high, int key) {
		int n = sz(a);
		int m = sz(a[0]);
		while (low <= high) {
			int mid = (low + high) / 2;

			int row = mid / m;
			int col = mid % m;

			if (a[row][col] == key)
				return true;

			else if (a[row][col] < key)
				low = mid + 1;

			else if (a[row][col] > key)
				high = mid - 1;
		}
		return false;
	}
};

void solve() {

	int n, m; cin >> n >> m;
	vector <vi> a(n, vi(m));

	REP(i, 0, n - 1)
	REP(j, 0, m - 1)
	cin >> a[i][j];

	int k; cin >> k;

	cout << ((Solution().searchMatrix(a, k)) ? "YES" : "NO") << endl;

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
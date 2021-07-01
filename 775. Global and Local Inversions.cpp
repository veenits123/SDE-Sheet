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
	bool isIdealPermutation(vector<int>& A) {
		int n = sz(A);
		int local_inv = 0;
		REP(i, 0, n - 2) {
			if (A[i] > A[i + 1])
				local_inv++;
		}
		int global_inv = mergeSort(A, n);
		return (local_inv == global_inv);
	}
	
	int merge(vi &a, vi &temp, int left, int mid, int right) {
		int i = left, j = mid, k = left;
		int inv_cnt = 0;
		while (i < mid && j <= right) {
			if (a[i] <= a[j])
				temp[k++] = a[i++];
			else {
				inv_cnt += (mid - i);
				temp[k++] = a[j++];
			}
		}
		while (i < mid)
			temp[k++] = a[i++];
		while (j <= right)
			temp[k++] = a[j++];
		REP(i, left, right)
		a[i] = temp[i];

		return inv_cnt;
	}

	int merge_sort(vi &a, vi &temp, int left, int right) {
		int inv_cnt = 0;
		if (right > left) {
			int mid = (left + right) / 2;

			inv_cnt += merge_sort(a, temp, left, mid);
			inv_cnt += merge_sort(a, temp, mid + 1, right);

			inv_cnt += merge(a, temp, left, mid + 1, right);
		}
		return inv_cnt;
	}

	int mergeSort(vi &a, int n) {
		vi temp(n);
		return merge_sort(a, temp, 0, n - 1);
	}
};

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << Solution().isIdealPermutation(a);

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
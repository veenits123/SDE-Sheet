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
	int reversePairs(vector<int>& nums) {
		int n = sz(nums);
		return mergeSort(nums, n);
	}

	int merge(vi &a, vi &temp, int left, int mid, int right) {
		int i = left, j = mid + 1, k = left;
		int inv_cnt = 0;
		REP(x, left, mid) {
			while (j <= right && a[x] > 2LL * a[j])
				j++;
			inv_cnt += (j - (mid + 1));
		}
		i = left, j = mid + 1;
		while (i <= mid && j <= right) {
			if (a[i] <= a[j])
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
		}
		while (i <= mid)
			temp[k++] = a[i++];
		while (j <= right)
			temp[k++] = a[j++];
		REP(x, left, right)
		a[x] = temp[x];

		return inv_cnt;
	}

	int merge_sort(vi &a, vi &temp, int left, int right) {
		if (left >= right)
			return 0;
		int inv_cnt = 0;
		if (right > left) {
			int mid = (left + right) / 2;

			inv_cnt += merge_sort(a, temp, left, mid);
			inv_cnt += merge_sort(a, temp, mid + 1, right);

			inv_cnt += merge(a, temp, left, mid, right);
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

	cout << Solution().reversePairs(a);

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
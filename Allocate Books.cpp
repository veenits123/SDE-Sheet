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

bool isPossible(vector <int> &arr, int barrier, int k) {
	int pages = 0;
	int students = 1;
	int n = sz(arr);
	REP(i, 0, n - 1) {
		if (arr[i] > barrier)
			return false;
		if (pages + arr[i] > barrier) {
			students++;
			pages = arr[i];
		}
		else
			pages += arr[i];
	}
	if (students > k)
		return false;
	return true;
}

int allocateBook(vector <int> &a, int k) {
	if (sz(a) < k)
		return -1;
	int low = a[0];
	int high = 0;
	for (auto x : a) {
		high += x;
		low = min(low, x);
	}

	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (isPossible(a, mid, k)) {
			ans = mid;

			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return ans;
}

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	int k; cin >> k;

	cout << allocateBook(a, k);

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
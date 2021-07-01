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

bool canPlace(vi &a, int c, int mid) {
	int n = sz(a);
	int co_ordinate = a[0];
	int cow = 1;
	REP(i, 1, n - 1) {
		if (a[i] - co_ordinate >= mid) {
			cow++;
			co_ordinate = a[i];
		}
		if (cow == c)
			return true;
	}
	return false;
}

int aggCow(vi &a, int c) {
	int n = sz(a);
	sort(all(a));
	int ans = -1;
	int low = 0, high = a[n - 1] - a[0];
	while (low <= high) {
		int mid = (low + high) / 2;
		if (canPlace(a, c, mid)) {
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}

void solve() {

	int n, c; cin >> n >> c;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << aggCow(a, c) << endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t; while (t--)
		solve();

	return 0;
}
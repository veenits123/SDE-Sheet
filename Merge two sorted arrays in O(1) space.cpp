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

void merge(vi &a, vi &b, int n, int m) {
	REV(i, m - 1, 0) {
		int j, last = a[n - 1];
		for (j = n - 2; j >= 0 && a[j] > b[i]; j--) {
			a[j + 1] = a[j];
		}
		if (last > b[i] || j != n - 2) {
			a[j + 1] = b[i];
			b[i] = last;
		}
	}
}

void merge_2(vi &a, vi &b, int n, int m) {
	int k = n - 1, i = 0, j = 0;
	while (i <= k && j < m) {
		if (a[i] < b[j])
			i++;
		else {
			swap(a[k], b[j]);
			k--, j++;
		}
	}
	sort(all(a));
	sort(all(b));
}

int calc_gap(int gap) {
	if (gap <= 1)
		return 0;
	return (gap / 2) + (gap % 2);
}

void merge_3(vi &a, vi &b, int n, int m) {
	int gap_global = m + n;
	int i, j;
	for (int gap = calc_gap(gap_global); gap > 0; gap = calc_gap(gap)) {
		//comparison in 1st array;
		for (i = 0; i + gap < n; i++) {
			if (a[i] > a[i + gap])
				swap(a[i], a[i + gap]);
		}
		//comparison in both array at the same time;
		for (j = (gap > n) ? gap - n : 0; j < m && i < n; j++, i++) {
			if (a[i] > b[j])
				swap(a[i], b[j]);
		}
		//comparison in 2nd array;
		if (j < m) {
			for (j = 0; j + gap < m; j++) {
				if (b[j] > b[j + gap])
					swap(b[j], b[j + gap]);
			}
		}
	}
}

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	int m; cin >> m;
	vi b(m);
	REP(i, 0, m - 1) cin >> b[i];

	merge_3(a, b, n, m);

	REP(i, 0, n - 1) cout << a[i] << " ";
	cout << endl;
	REP(i, 0, m - 1) cout << b[i] << " ";

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
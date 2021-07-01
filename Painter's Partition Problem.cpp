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
const int mod = 10000003;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

const int mod = 10000003;
#define ll long long int

bool check(vi &a, int p, int mid) {
	int n = sz(a);
	int painter = 1;
	ll area = 0;
	REP(i, 0, n - 1) {
		area += a[i];
		if (area > mid) {
			area = a[i];
			painter++;
		}
		if (painter > p)
			return false;
	}
	return (painter <= p);
}

int painterPartition(vi &a, int p, int k) {
	int low = 0;
	int high = 0;
	for (auto x : a) {
		high += x;
		low = max(low, x);
	}

	if (sz(a) <= p)
		return (low * k) % mod;

	ll ans = low;
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		if (check(a, p, mid)) {
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return (ans * k) % mod;
}


void solve() {

	int p, k; cin >> p >> k;
	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	cout << painterPartition(a, p, k) % mod;

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
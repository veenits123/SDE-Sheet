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

int left_most_bit(int n) {
	return (int)log2(n);
}

pair <int, int> find_rep_mis(int a[], int n) {	
	int xor_a = 0;
	REP(i, 0, n - 1)
	xor_a ^= a[i];

	REP(i, 1, n)
	xor_a ^= i;

	int pos = left_most_bit(xor_a);

	vi lmb_one;
	vi lmb_zero;

	REP(i, 1, n) {
		if ((1 << pos)&i)
			lmb_one.pb(i);
		else
			lmb_zero.pb(i);
	}
	REP(i, 0, n - 1) {
		if ((1 << pos)&a[i])
			lmb_one.pb(a[i]);
		else
			lmb_zero.pb(a[i]);
	}
	int mis = 0, rep = 0;
	for (auto x : lmb_one)
		mis ^= x;
	for (auto x : lmb_zero)
		rep ^= x;

	bool miss = true;
	REP(i, 0, n - 1) {
		if (mis == a[i]) {
			miss = false;
			break;
		}
	}
	if (!miss)
		swap(mis, rep);
	return {rep, mis};
}

void solve() {

	int n; cin >> n;
	int a[n];
	REP(i, 0, n - 1) {
		cin >> a[i];
	}

	P ans=find_rep_mis(a,n);

	cout << ans.F << " " << ans.S << endl;


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
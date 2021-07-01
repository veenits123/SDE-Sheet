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

// int subarrayXor(vi & a, int x) {
// 	int n = sz(a);
// 	int ans = 0;
// 	REP(i, 0, n - 1) {
// 		int temp = 0;
// 		REP(j, i, n - 1) {
// 			temp ^= a[j];
// 			if (temp == x)
// 				ans++;
// 		}
// 	}
// 	return ans;
// }

int subarrayXor(vi & a, int x) {
	map <int, int> m;
	int n = sz(a);

	vi prefixXor(n);
	prefixXor[0] = a[0];
	REP(i, 1, n - 1)
	prefixXor[i] = prefixXor[i - 1] ^ a[i];

	int ans = 0;
	REP(i, 0, n - 1) {
		if (prefixXor[i] == x)
			ans++;
		int temp = prefixXor[i] ^ x;
		if (m[temp])
			ans += m[temp];
		m[prefixXor[i]]++;
	}
	return ans;
}

void solve() {

	int n; cin >> n;
	vi a(n);
	REP(i, 0, n - 1) cin >> a[i];

	int x; cin >> x;

	cout << subarrayXor(a, x);

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
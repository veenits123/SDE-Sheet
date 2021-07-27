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

void solve() {

	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(5, 0));

	REP(i, 0, n - 1) {
		REP(j, 0, 4)
		cin >> a[i][j];
	}
	if (n == 1) {
		cout << 1 << endl;
		return ;
	}

	REP(i, 0, n - 1)
	sort(all(a[i]));

	vector <int> temp;

	REP(i, 0, n - 1) {
		int sum = 0;
		REP(j, 0, 2)
		sum += a[i][j];
		temp.pb(sum);
	}
	int ans = -1;

	int min = 1e18;
	map <int, int> mp;
	REP(i, 0, n - 1) {
		mp[temp[i]]++;
		if (min > temp[i]) {
			min = temp[i];
			ans = i;
		}
	}
	if (mp[min] > 1) {
		cout << -1 << endl;
		return ;
	}

	if (ans == -1)
		cout << ans << endl;
	else
		cout << ans + 1 << endl;

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
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
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	vector<int> prefixProduct(n + 2, 1);
	vector<int> suffixProduct(n + 2, 1);

	for (int i = 1; i <= n; i++)
		prefixProduct[i] = prefixProduct[i - 1] * arr[i];

	for (int i = n; i >= 1; i--)
		suffixProduct[i] = suffixProduct[i + 1] * arr[i];

	vector<int> ans(n + 1);

	for (int i = 1; i <= n; i++) {
		ans[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";


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
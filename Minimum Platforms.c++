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
	//Function to find the minimum number of platforms required at the
	//railway station such that no train waits.
	int findPlatform(int arr[], int dep[], int n) {
		// Your code here
		sort(arr, arr + n);
		sort(dep, dep + n);

		int i = 1, j = 0;
		int ans = 1;
		int mx = 1;
		int prev = dep[0];
		while (i < n && j < n) {
			int temp = arr[i];
			prev = dep[j];
			if (temp <= prev) {
				mx++;
				i++;
			}
			else {
				mx--;
				j++;
			}
			ans = max(ans, mx);
		}
		return ans;
	}
};


void solve() {

	int n; cin >> n;
	int a[n], d[n];
	REP(i, 0, n - 1) cin >> a[i];
	REP(i, 0, n - 1) cin >> d[i];

	cout << Solution().findPlatform(a, d, n) << endl;

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
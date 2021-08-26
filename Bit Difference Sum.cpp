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

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

class Solution {
	const int mod = 1e9 + 7;
public:

	int countBits(int N,  int A[])
	{
		// code here
		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				if (A[j] & (1 << i))
					cnt++;//no. of set bits at i'th index of every elements;
				//(N-cnt) = no. of 0 bits at i'th index of every elements;
			}
			ans += 2 * cnt * (N - cnt) % mod;
		}
		return ans;
	}
};

void solve() {

	int n; cin >> n;
	int a[n];
	REP(i, 0, n - 1) cin >> a[i];

	cout << Solution().countBits(n, a) << endl;

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
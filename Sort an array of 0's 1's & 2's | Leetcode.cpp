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

void dutch_nat_flag(int a[], int n, int &low, int &mid, int &high) {
	while (mid <= high) {
		if (a[mid] == 0) {
			swap(a[mid], a[low]);
			mid++, low++;
		}
		else if (a[mid] == 1) {
			mid++;
		}
		else if (a[mid] == 2) {
			swap(a[mid], a[high]);
			high--;
		}
	}
}

void solve() {

	int n; cin >> n;
	int a[n];
	REP(i, 0, n - 1)
	cin >> a[i];

	int low = 0, high = n - 1, mid = 0;

	dutch_nat_flag(a, n, low, mid, high);

	// presence of 0, 1 & 2:
	// 0 -> [0,...,low-1]
	// 1 -> [high+1,...,n]
	// 2 -> [low,...,mid-1]

	cout << low << " " << mid << " " << high << endl;

	REP(i, 0, n - 1)
	cout << a[i] << " ";

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
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
#include <stack>
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

//tc: O(n^2);
// vector<int> nextGreaterElement(vector<int>& arr) {
// 	int n = arr.size();
// 	vector<int> ans(n, 0);
// 	for (int i = 0; i < n; i++) {
// 		for (int j = i + 1; j < n; j++) {
// 			if (arr[j] > arr[i]) {
// 				ans[i] = j - i;
// 				break;
// 			}
// 		}
// 	}
// 	return ans;
// }

//tc: O(n);
vector<int> nextGreaterElement(vector<int>& arr) {
	int n = arr.size();
	vector<int> ans(n, 0);
	stack<pair<int, int>> s;
	for (int i = n; i >= 0; i--) {
		while (!s.empty() && s.top().F <= arr[i]) {
			s.pop();
		}
		if (!s.empty()) {
			ans[i] = s.top().S - i;
		}
		s.push({arr[i], i});
	}
	return ans;
}

void solve() {

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	auto ans = nextGreaterElement(a);

	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;

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
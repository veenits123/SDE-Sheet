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
	vector<vector<string>> partition(string s) {
		vector <string> temp;
		vector <vector<string>> ans;
		helper(s, 0, ans, temp);
		return ans;
	}

	void helper(string s, int index, vector <vector<string>>& ans, vector <string>& temp) {
		if (index == sz(s)) {
			ans.pb(temp);
			return ;
		}
		for (int i = index; i < sz(s); i++) {
			if (isPallindrome(s, index, i)) {
				temp.pb(s.substr(index, i - index + 1));
				helper(s, i + 1, ans, temp);
				temp.pop_back();
			}
		}
	}

	bool isPallindrome(string s, int i, int j) {
		while (i <= j) {
			if (s[i++] != s[j--])
				return false;
		}
		return true;
	}
};

void solve() {

	string s; cin >> s;

	auto ans = Solution().partition(s);

	for (auto x : ans) {
		for (auto y : x)
			cout << y << " ";
		cout << endl;
	}

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
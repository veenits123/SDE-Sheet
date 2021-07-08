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

//tle :(
// class Solution {
// public:
// 	string getPermutation(int n, int k) {
// 		string s = "";
// 		for (int i = 1; i <= n; i++)
// 			s += (i + '0');
// 		vector <string> data;
// 		generatePermutation(s, 0, n - 1, data);
// 		sort(all(data));
// 		string ans = data[k - 1];
// 		return ans;
// 	}
// 	void generatePermutation(string s, int l, int r, vector <string>& data) {
// 		if (l == r) {
// 			data.pb(s);
// 			return ;
// 		}
// 		for (int i = l; i <= r; i++) {
// 			swap(s[i], s[l]);
// 			generatePermutation(s, l + 1, r, data);
// 			swap(s[i], s[l]);
// 		}
// 	}
// };

class Solution {
public:
	string getPermutation(int n, int k) {
		vector <int> numbers;
		int fact = 1;
		for (int i = 1; i < n; i++) {
			fact *= i;
			numbers.push_back(i);
		}
		numbers.push_back(n);
		string ans = "";
		k--;
		while (true) {
			ans += to_string(numbers[k / fact]);
			numbers.erase(numbers.begin() + (k / fact));
			if (numbers.size() == 0)
				break;
			k %= fact;
			fact /= numbers.size();
		}
		return ans;
	}
};

void solve() {

	int n, k; cin >> n >> k;

	cout << Solution().getPermutation(n, k) << endl;

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
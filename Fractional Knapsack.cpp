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

struct Item {
	int value;
	int weight;
};

class Solution {
public:
	//Function to get the maximum total value in the knapsack.
	double fractionalKnapsack(int W, Item arr[], int n) {
		// Your code here
		sort(arr, arr + n, comp);

		// REP(i, 0, n - 1)
		// cout << arr[i].weight << " " << arr[i].value << endl;

		double ans = 0;
		int w = W;
		REP(i, 0, n - 1) {
			if (w >= arr[i].weight) {
				w -= arr[i].weight;
				ans += arr[i].value;
			}
			else {
				ans += (double)(arr[i].value / (double)arr[i].weight) * (double)w;
				break;
			}
		}
		return ans;
	}
	
	static bool comp(Item a, Item b) {
		double vwrA = (double)a.value / (double)a.weight;
		double vwrB = (double)b.value / (double)b.weight;
		return vwrA > vwrB;
	}
};

void solve() {

	int n, w; cin >> n >> w;

	Item arr[n];
	REP(i, 0, n - 1) cin >> arr[i].value >> arr[i].weight;

	cout << sp(Solution().fractionalKnapsack(w, arr, n), 2) << endl;

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
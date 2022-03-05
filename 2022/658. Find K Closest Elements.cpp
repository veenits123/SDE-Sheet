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
#include <climits>
#include <functional>
using namespace std;

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
const int N = 1e5 + 5;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    	priority_queue<P> q;
    	for(auto &num: arr){
    		q.push({abs(num-x), num});
    		if(q.size()>k)
    			q.pop();
    	}
    	vector<int> ans;
    	while(!q.empty()){
    		ans.push_back(q.top().second);
    		q.pop();
    	}
    	sort(all(ans));
    	return ans;
    }
};

void solve() {

	int n;cin>>n;
	vector<int> arr(n);
	REP(i,0,n-1) cin>>arr[i];

	int k,x;cin>>k>>x;

	auto ans = Solution().findClosestElements(arr, k, x);

	for(auto x:ans)
		cout<<x<<" ";

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

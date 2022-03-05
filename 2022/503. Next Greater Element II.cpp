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
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int n=nums.size();
    	stack<int> s;
    	vector<int> ans(n,-1);
    	for(int i=2*n-1; i>=0; i--){
    		while(!s.empty() && s.top() <= nums[i%n]){
    			s.pop();
    		}
    		// m-I -> less computation;
    		// if(i<n){
	    	// 	if(!s.empty()){
	    	// 		ans[i] = s.top();	
	    	// 	}
	    	// }
	    	// m-II -> more computation;
	    	if(!s.empty()){
	    			ans[i%n] = s.top();	
	    	}
    		s.push(nums[i%n]);
    	}
    	return ans;
    }
};

void solve() {

	int n;cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];

	auto ans = Solution().nextGreaterElements(arr);

	for(auto &x: ans)
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

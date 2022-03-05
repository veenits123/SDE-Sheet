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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> frequency;
        for(auto &x: nums)
        	frequency[x]++;
        priority_queue<P, vector<P>, greater<P>> q;
        for(auto &x: frequency){
        	q.push({x.second, x.first});
        	if(q.size()>k)
        		q.pop();
        }
        vector<int> ans;
        while(!q.empty()){
        	ans.push_back(q.top().second);
        	q.pop();
        }
        return ans;
    }
};

void solve() {

	int n;cin>>n;
	vector<int> arr(n);
	REP(i,0,n-1) cin>>arr[i];

	int k;cin>>k;

	auto ans = Solution().topKFrequent(arr, k);

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

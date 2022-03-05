/**
 * तस्मात्सर्वेषु कालेषु मामनुस्मर युध्य च ।
 * मय्यर्पितमनोबुद्धिर्मामेवैष्यस्यसंशय: ॥
 * 
 * Hare Kṛṣṇa Hare Kṛṣṇa
 * Kṛṣṇa Kṛṣṇa Hare Hare
 * Hare Rāma Hare Rāma
 * Rāma Rāma Hare Hare
**/

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

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define rev(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(all(candidates));
        
        helper(candidates, target, 0, temp, ans);

        return ans;
    }
    void helper(vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& ans){
    	if(index >= candidates.size() || target <= 0){
    		if(target == 0)
    			ans.push_back(temp);
    		return ;
    	}
    	for(int i=index; i<candidates.size(); i++){
    		
    		if(i > index && candidates[i] == candidates[i-1])
    			continue;
    		
	    	temp.push_back(candidates[i]);
	    	helper(candidates, target - candidates[i], i + 1, temp, ans);
	    	temp.pop_back();
	    }
    }
};

void solve() {
	
	int n, k; cin>>n>>k;
	vector<int> arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	auto ans = Solution().combinationSum2(arr, k);
	
	for(auto x: ans){
		for(auto y: x)
			cout<<y<<" ";
		cout<<endl;
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

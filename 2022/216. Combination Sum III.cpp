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
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        generateCombination(n, k, 1, temp, ans);
        return ans;
    }
    void generateCombination(int n, int k, int index, vector<int>& temp, vector<vector<int>>& ans){
    	if(temp.size() >= k || n <= 0){
    		if(temp.size() == k && n == 0)
    			ans.push_back(temp);
    		return ;
    	}
    	for(int i=index; i <= 9; i++){
	    	temp.push_back(i);
	    	generateCombination(n - i, k, i + 1, temp, ans);
	    	temp.pop_back();
	    }
    }
};

void solve() {
	
	int n,k;cin>>n>>k;
	
	auto ans = Solution().combinationSum3(k, n);
	
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

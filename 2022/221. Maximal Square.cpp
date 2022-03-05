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
    int maximalSquare(vector<vector<char>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	vector<vector<int>> dp(n, vector<int>(m));
    	
    	int maxArea = 0;
    	
    	for(int i=0; i<n; i++){
    		dp[i][0] = matrix[i][0]-'0';
    		maxArea = max(maxArea, dp[i][0]);
    	}
    	for(int j=0; j<m; j++){
    		dp[0][j] = matrix[0][j]-'0';
    		maxArea = max(maxArea, dp[0][j]);
    	}
    	
    	for(int i=1; i<n; i++){
    		for(int j=1; j<m; j++){
    			if(matrix[i][j] == '1'){
    				int minOfThreeQuadrant = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
    				
    				dp[i][j] = 1 + minOfThreeQuadrant;
    				//cout<<dp[i][j]<<" ";
    			}
    			else
    				dp[i][j] = 0;
    			//cout<<dp[i][j]<<" ";
    			maxArea = max(maxArea, dp[i][j]);
    		}
    		//cout<<endl;
    	}
    	return maxArea * maxArea;
    }
};

void solve() {
	
	int n, m;cin>>n>>m;
	vector<vector<char>> arr(n, vector<char>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>arr[i][j];
	
	cout<<Solution().maximalSquare(arr);

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

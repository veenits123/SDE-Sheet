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

// DP:
// class Solution {
// public:
//     int minCut(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
        
//         return minCutHelper(s, 0, n-1, dp);
//     }
//     int minCutHelper(string &s, int left, int right, vector<vector<int>>& dp){
//     	if(left >= right){ // (left == right) -> same character and (left > right) -> empty string;
//     		return 0;
//     	}
    	
//     	if(isPalindrome(s, left, right)){
//     		return 0;
//     	}
    	
//     	if(dp[left][right] != -1)
//     		return dp[left][right];
    	
//     	int ans = INT_MAX;
//     	for(int index = left; index <= right - 1; index++){
//     		if(isPalindrome(s, left, index)){
//     			int minCutRightPart = minCutHelper(s, index + 1, right, dp) + 1;
    			
//     			ans = min(ans, minCutRightPart);
//     		}
//     	}
//     	return dp[left][right] = ans;
//     }
//     bool isPalindrome(string &s, int left, int right){
//     	while(left <= right){
//     		if(s[left] != s[right]){
//     			return false;
//     		}
//     		left++, right--;
//     	}
//     	return true;
//     }
// };

// Graph:
class Solution {
public:
    int minCut(string s) {
    	int n = s.size();
    	
    	if(n <=0)
    		return 0;
    	
    	vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
    	for(int right=0; right<n; right++){
    		
    		isPalindrome[right][right] = true;
    		
    		for(int left=0; left <= right; left++){
    			if(s[right] == s[left] && ((right-left) <= 1 || isPalindrome[left+1][right-1])){
    				isPalindrome[left][right] = true;
    			}
    		}
    	}
    	
        vector<set<int>> graph(n + 1);
        vector<int> distance(n + 1, -1);
        
        // making graph;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		if(isPalindrome[i][j]){
        			graph[i].insert(j + 1);
        		}
        	}
        }
        return bfs(graph, n, distance); 
    }
    int bfs(vector<set<int>>& graph, int &n, vector<int>& distance){
    	queue<int> q;
    	q.push(0);
    	distance[0] = 0;
    	while(!q.empty()){
    		int cur = q.front();
    		q.pop();
    		
    		if(cur == n)
    			return distance[n] - 1;
    		
    		for(auto to: graph[cur]){
    			if(distance[to] == -1){
    				distance[to] = distance[cur] + 1;
    				q.push(to);
    			}
    		}
    	}
    	return distance[n] - 1;
    }
};

void solve() {
	
	string s;cin>>s;
	cout<<Solution().minCut(s);

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

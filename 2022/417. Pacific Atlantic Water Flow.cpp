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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    	int n = heights.size();
    	int m = heights[0].size(); 
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        
        vector<vector<int>> ans;
        
        // col-boundary;
        for(int i=0; i<n; i++){
        	bfs(heights, i, 0, atlantic);
        	bfs(heights, i, m-1, pacific);
        }
        
        // row-boundary;
        for(int j=0; j<m; j++){
        	bfs(heights, 0, j, atlantic);
        	bfs(heights, n-1, j, pacific);
        }
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(atlantic[i][j] && pacific[i][j])
        			ans.push_back({i, j});
        	}
        }
        return ans;
    }
    
    bool isValid(int row, int col, int n, int m){
    	return (row >= 0 && row < n && col >= 0 && col < m);
    }
    
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void bfs(vector<vector<int>>& heights, int sx, int sy, vector<vector<bool>>& visited){
    	int n = heights.size();
    	int m = heights[0].size();
    	
    	queue<pair<int, int>> q;
    	q.push({sx, sy});
    	visited[sx][sy] = true;
    	while(!q.empty()){
    		int row = q.front().first;
    		int col = q.front().second;
    		q.pop();
    		
    		for(int i=0; i<4; i++){
    			int r = row + directions[i].first;
    			int c = col + directions[i].second;
    			
    			if(isValid(r, c, n, m) && !visited[r][c] && heights[r][c] >= heights[row][col]){
    				visited[r][c] = true;
    				q.push({r, c});
    			}
    		}
    	}
    }
};

void solve() {
	
	int n,m;cin>>n>>m;
	vector<vector<int>> heights(n, vector<int>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>heights[i][j];
	
	auto ans = Solution().pacificAtlantic(heights);
	
	for(auto x: ans)
		cout<<x[0]<<" "<<x[1]<<endl;

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

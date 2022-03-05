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
	vector<pair<int,int>> dir = {{-1, -1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
    int minCost(vector<vector<int>>& grid) {
    	int n = grid.size();
    	int m = grid[0].size();
   
    	vector<vector<int>> dis(n, vector<int>(m, 1e9));
        return bfs(0, 0, grid, dis);
    }
    
    bool isValid(int r, int c, int n, int m){
    	return (r>=0 && r<n && c>=0 && c<m);
    }
    int bfs(int sx, int sy, vector<vector<int>>& grid, vector<vector<int>>& dis){
    	int n = grid.size();
    	int m = grid[0].size();
    	
    	dis[sx][sy] = 0;
    	
    	deque<pair<int,int>> q;
    	q.push_front({sx, sy});
    	
    	while(!q.empty()){
    		int row = q.front().first;
    		int col = q.front().second;
    		q.pop_front();
    		
    		int curDirection = grid[row][col];
    		
    		for(int i=1; i<=4; i++){
    			int r = row + dir[i].first;
    			int c = col	+ dir[i].second;
    			
    			int w = (i == curDirection)? 0 : 1;
    			
    			if(isValid(r, c, n, m) && dis[r][c] > dis[row][col] + w){
    				dis[r][c] = dis[row][col] + w;
    				
    				if(w == 0)
    					q.push_front({r, c});
    				else
    					q.push_back({r, c});
    			}
    		}
    	}
    	return dis[n-1][m-1];
    }
};

void solve() {
	
	int n,m;cin>>n>>m;
	vector<vi> grid(n, vector<int>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>grid[i][j];
	
	cout<<Solution().minCost(grid);

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

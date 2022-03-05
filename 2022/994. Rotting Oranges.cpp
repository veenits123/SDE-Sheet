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
	vector<pair<int,int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
	
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
    bool isValid(int r, int c, int n, int m){
    	return (r>=0 && r<n && c>=0 && c<m);
    }
    int bfs(vector<vector<int>>& grid){
    	int n = grid.size();
    	int m = grid[0].size();
        
        int freshOrange = 0;
    	
    	queue<pair<int,int>> q;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
    			if(grid[i][j] == 2){
    				q.push({i, j});
    			}
                if(grid[i][j] == 1)
                    freshOrange += 1;
    		}
    	}
    	int ans = -1;
        
        if(freshOrange == 0)
            return 0;
        
    	while(!q.empty()){
    		ans++;
    		
    		int currentRottenCells = q.size();
    		
    		for(int i=0; i<currentRottenCells; i++){
    			
	    		int row = q.front().first;
	    		int col = q.front().second;
	    		q.pop();
	    		
	    		for(int d=0; d<4; d++){
	    			int r = row + dir[d].first;
	    			int c = col + dir[d].second;
	    			
	    			if(isValid(r, c, n, m) && grid[r][c] == 1){
	    				grid[r][c] = 2;
	    				q.push({r, c});
                        freshOrange--;
	    				//cout<<"Ans:"<<ans<<" "<<r<<" "<<c<<endl;
	    			}
	    		}
	    	}
    	}
    	if(freshOrange > 0){
            return -1;
        }
    	return ans;
    }
};

void solve() {
	
	int n,m;cin>>n>>m;
	vector<vector<int>> grid(n, vector<int>(m));
	
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>grid[i][j];
	
	cout<<Solution().orangesRotting(grid);
	

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

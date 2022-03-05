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
    void solve(vector<vector<char>>& board) {
    	int n = board.size();
    	int m = board[0].size();
    	
    	// border-col;
    	for(int i=0; i<n; i++){
    		if(board[i][0] == 'O')
    			bfs(board, i, 0);
    		if(board[i][m-1] == 'O')
    			bfs(board, i, m-1);
    	}
    	
    	// border-row;
    	for(int j=0; j<m; j++){
    		if(board[0][j] == 'O')
    			bfs(board, 0, j);
    		if(board[n-1][j] == 'O')
    			bfs(board, n-1, j);
    	}
        for(int i=0; i<n; i++){
        	for(int j=0; j<m; j++){
        		if(board[i][j] == 'O')
        			board[i][j] = 'X';
        		else if(board[i][j] == '#')
        			board[i][j] = 'O';
        	}
        }
    }
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void bfs(vector<vector<char>>& board, int sx, int sy){
    	board[sx][sy] = '#';
    	queue<pair<int, int>> q;
    	q.push({sx, sy});
    	while(!q.empty()){
    		int r = q.front().first;
    		int c = q.front().second;
    		q.pop();
    		
    		for(int i=0; i<4; i++){
    			int row = directions[i].first + r;
    			int col	= directions[i].second + c;
    			
    			if(isValid(row, col, board.size(), board[0].size()) && board[row][col] == 'O'){
    				board[row][col] = '#';
    				q.push({row, col});
    			}
    		}
    	}
    }
    bool isValid(int row, int col, int n, int m){
    	return (row >= 0 && row < n && col >= 0 && col < m);
    }
};

void fun() {
	
	int n,m;cin>>n>>m;
	vector<vector<char>> board(n, vector<char>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>board[i][j];
	
	Solution().solve(board);
	
	rep(i,0,n-1){
		rep(j,0,m-1)
			cout<<board[i][j]<<" ";
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
	fun();

	return 0;
}

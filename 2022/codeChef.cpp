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
    void solveSudoku(vector<vector<char>>& board) {
        sudokuHelper(board);
    }
    
    bool canPlaceNum(vector<vector<char>>& board, int row, int col, char num){
    	// row-check
    	for(int j=0; j<9; j++){
    		if(board[row][j] == num)
    			return false;
    	}
    	// col-check
    	for(int i=0; i<9; i++){
    		if(board[i][col] == num)
    			return false;
    	}
    	// 3x3 board-check
    	row = row - (row % 3);
    	col = col - (col % 3);
    	for(int i=0; i<3; i++){
    		for(int j=0; j<3; j++){
    			if(board[i + row][j + col] == num)
    				return false;
    		}
    	}
    	return true;
    }
    bool hasEmptySpaces(vector<vector<char>>& board, int &row, int &col){
    	for(int i=0; i<9; i++){
    		for(int j=0; j<9; j++){
    			if(board[i][j] == '0'){
    				row = i;
    				col	= j;
    				return true;
    			}
    		}
    	}
    	return false;
    }
    bool sudokuHelper(vector<vector<char>>& board){
  		int row, col;
    	if(hasEmptySpaces(board, row, col) == false)
    		return true;
    	
		for(char c = '1'; c<='9'; c++){
			if(canPlaceNum(board, row, col, c)){
				board[row][col] = c;
				if(sudokuHelper(board)){
					return true;
				}
				board[row][col] = '0';
			}
		}
    	return false;
    }
};

void solve() {
	
	int n = 9;
	
	vector<vector<char>> board(n, vector<char>(n));
	
	rep(i,0,n-1)
	rep(j,0,n-1)
	cin>>board[i][j];
	
	Solution().solveSudoku(board);
	
	rep(i,0,n-1){
		rep(j,0,n-1)
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
	solve();

	return 0;
}

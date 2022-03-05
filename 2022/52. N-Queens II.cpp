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
    int totalNQueens(int n) {
    	vector<vector<string>> ans;
        
        vector<string> board(n);
        string temp(n, '.');
        
        fill(board.begin(), board.end(), temp);
        
        helper(n, 0, board, ans);
        
        return ans.size();
        
    }

    bool isValid(int n, int row, int col){
    	return (row>=0 && row<n && col>=0 && col<n);
    }
    bool canPlace(int row, int col, int n, vector<string>& board){
    	for(int i=0; i<n; i++){
    		if(board[i][col] == 'Q')
    			return false;
    	}
    	int i = row, j = col;
    	while(isValid(n, i, j)){
    		if(board[i][j] == 'Q')
    			return false;
    		i--,j--;
    	}
    	i = row, j = col;   
    	while(isValid(n, i, j)){
    		if(board[i][j] == 'Q')
    			return false;
    		i--, j++;
    	}
    	return true;
    }
    void helper(int n, int row, vector<string>& board, vector<vector<string>>& ans){
    	if(row >= n){
    		ans.push_back(board);
    		return ;
    	}
    	for(int j=0; j<n; j++){
    		if(canPlace(row, j, n, board)){
    			board[row][j] = 'Q';
    			helper(n, row + 1, board, ans);
    			board[row][j] = '.';
    		}
    	}
    	return ;
    }
};

void solve() {
	
	int n;cin>>n;
	
	auto ans = Solution().totalNQueens(n);
	
	cout<<ans<<endl;

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

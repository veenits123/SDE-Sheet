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
    bool exist(vector<vector<char>>& board, string word) {
    	int n = board.size();
    	int m = board[0].size();
    	if(n*m < word.size())
    		return false;
    	vector<vector<bool>> visited(n, vector<bool>(m, false));
    	for(int i=0; i<n; i++){
    		for(int j=0; j<m; j++){
                if(word[0] == board[i][j]){
    				if(wordSearch(board, i, j, word, 0, visited)){
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }
    
    bool isValid(int r, int c, int n, int m){
    	return (r >= 0 && r < n && c >= 0 && c < m);
    }
    
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool wordSearch(vector<vector<char>>& board, int row, int col, string &word, int index, vector<vector<bool>>& visited){
    	if(index >= word.size()){
    		return true;
    	}
    	
    	if(!isValid(row, col, board.size(), board[0].size()))
    		return false;
    	
    	if(board[row][col] != word[index])
    		return false;
        
        if(visited[row][col])
            return false;
    	
    	visited[row][col] = true;
    	bool flag = false;
    	for(int i=0; i<4; i++){
    		int r = row + directions[i].first;
    		int c = col + directions[i].second;
    		
			flag |= wordSearch(board, r, c, word, index + 1, visited);
    	}
        visited[row][col] = false;
    	return flag;
    }
};

void solve() {
	
	int n, m; cin>>n>>m;
	vector<vector<char>> board(n, vector<char>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>board[i][j];
	
	string word; cin>>word;
	
	cout<<Solution().exist(board, word);

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

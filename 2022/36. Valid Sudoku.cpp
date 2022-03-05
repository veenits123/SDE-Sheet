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
    bool isValidSudoku(vector<vector<char>>& board) {
    	int n = board.size();
        vector<set<int>> rowCheck(n+1), colCheck(n+1), boxCheck(n+1);
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		
        		if(board[i][j] == '.')
        			continue;
        		
        		int curNum = board[i][j] - '0';
        		
        		if(rowCheck[i].count(curNum))
        			return false;
        		if(colCheck[j].count(curNum))
        			return false;
        		
        		int boxNum = i/3 * 3 + j/3 + 1;
        		if(boxCheck[boxNum].count(curNum))
        			return false;
        		
        		rowCheck[i].insert(curNum);
        		colCheck[j].insert(curNum);
        		boxCheck[boxNum].insert(curNum);
        	}
        }
        return true;
    }
};

void solve() {
	
	int n =9;
	vector<vector<char>> grid(n, vector<char>(n));
	rep(i,0,n-1)
	rep(j,0,n-1)
	cin>>grid[i][j];
	
	cout<<Solution().isValidSudoku(grid);

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

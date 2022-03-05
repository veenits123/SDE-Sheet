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

void printMaze(vector<vector<int>>& maze){
	int n = maze.size();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<maze[i][j]<<" ";
		cout<<endl;
	}
}

vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
vector<char> way = {'D', 'L', 'R', 'U'};

bool isValid(int r, int c, int n){
	return (r >= 0 && r < n && c >= 0 && c < n);
}

void ratInMazeHelper(vector<vector<int>>& maze, vector<vector<bool>>& visited, string path, vector<string>& ans, int row, int col){
	if(row == maze.size()-1 && col == maze.size()-1){
		ans.push_back(path);
		return ;
	}
	visited[row][col] = true;
	for(int i=0; i<4; i++){
		int r = row + directions[i].first;
		int c = col + directions[i].second;
		
	
		if(isValid(r, c, maze.size()) && maze[r][c] == 1 && visited[r][c] == false){
			visited[r][c] = true;
						
			ratInMazeHelper(maze, visited, path + way[i], ans, r, c);
			
			visited[r][c] = false;
		}
	}
}

vector<string> solveRatInMaze(vector<vector<int>>& maze){
	int n = maze.size();
	vector<string> ans;
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	
	if(maze[0][0] == 0 || maze[n-1][n-1] == 0)
		return ans;
		
	ratInMazeHelper(maze, visited, "", ans, 0, 0);
	
	return ans;
}

void solve() {
	
	int n;cin>>n;
	vector<vector<int>> maze(n, vector<int>(n));
	rep(i,0,n-1)
	rep(j,0,n-1)
	cin>>maze[i][j];
	
	auto ans = solveRatInMaze(maze);
	
	for(auto x: ans)
		cout<<x<<endl;

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

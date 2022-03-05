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
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
vector<vector<int>> graph(n);
	vector<vector<int>> ans;
	vector<bool> visited(n, false);
	vector<int> inTime(n, 0), lowTime(n, 0);
	int timer = 0;
	
	for(auto x: connections){
		graph[x[0]].push_back(x[1]);
		graph[x[1]].push_back(x[0]);
	}
 
	for(int i=0; i<n; i++){
		if(!visited[i]){
			dfs(i, -1, graph, visited, inTime, lowTime, timer, ans);
		}
	}
	return ans;
}
void dfs(int src, int parent, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& inTime, vector<int>& lowTime, int &timer, vector<vector<int>>& bridges){
	lowTime[src] = inTime[src] = timer++;
	visited[src] = true;
	for(auto to: graph[src]){
		if(to == parent)
			continue;
		if(visited[to]){
			lowTime[src] = min(lowTime[src], inTime[to]);
		}
		else{
			dfs(to, src, graph, visited, inTime, lowTime, timer, bridges);
			lowTime[src] = min(lowTime[to], lowTime[src]);
			if(lowTime[to] > inTime[src]){
				bridges.push_back({src, to});
			}
		}			
}
}

};

void solve() {
	
	int n;cin>>n;
	vector<vector<int>> connections;
	rep(i, 0, n-1){
		int u,v;cin>>u>>v;
		connections.pb({u, v});
	}
	auto ans = Solution().criticalConnections(n, connections);
	
	for(auto x: ans){
		for(auto y: x)
			cout<<y<<" ";
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

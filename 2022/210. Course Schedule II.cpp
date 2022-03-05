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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<vector<int>> graph(numCourses);
    	for(auto x: prerequisites){
    		graph[x[1]].push_back(x[0]);
    	}
    	vector<int> ans;
    	
    	vector<int> color(numCourses, 0);
    	for(int i=0; i<numCourses; i++){
    		if(color[i] == 0){
    			if(hasCycle(i, graph, color))
    				return ans;
    		}
    	}
    	
    	vector<bool> visited(numCourses, false);
    	stack<int> ordering;

    	for(int i=0; i<numCourses; i++){
    		if(!visited[i]){
    			dfs(i, graph, visited, ordering);
    		}
    	}
    	
    	while(!ordering.empty()){
    		ans.push_back(ordering.top());
    		ordering.pop();
    	}
    	return ans;
    }
    
    void dfs(int src, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& ordering){
    	visited[src] = true;
    	for(auto to: graph[src]){
    		if(!visited[to]){
    			dfs(to, graph, visited, ordering);
    		}
    	}
    	ordering.push(src);
    }
    
    bool hasCycle(int src, vector<vector<int>>& graph, vector<int>& color){
    	color[src] = 1;
    	for(auto to: graph[src]){
    		if(color[to] == 0){
    			if(hasCycle(to, graph, color)){
    				return true;
    			}
    		}
    		else{
    			if(color[to] == 1){
    				return true;
    			}
    		}
    	}
    	color[src] = 2;
    	return false;
    }
};

void solve() {
	
	int n;cin>>n;
	vector<vector<int>> pre;
	rep(i,1,n){
		int u,v;cin>>u>>v;
		pre.pb({u, v});
	}
	
	auto ans = Solution().findOrder(n, pre);
	for(auto x: ans)
		cout<<x<<" ";

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

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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<int> dis(n, 0);
        vector<vector<int>> graph(n);
        for(auto x: edges){
        	graph[x[0]].push_back(x[1]);
        	graph[x[1]].push_back(x[0]);
        }
        int start = bfs(0, graph, dis, vis);
        
        vis.assign(n, false);
        dis.assign(n, 0);
        
        int end = bfs(start, graph, dis, vis);
        
        vector<int> parent(n, -1);
        vis.assign(n, false);
        queue<int> q;
        q.push(start);
        dis[start] = 0;
        vis[start] = true;
        while(!q.empty()){
        	int cur = q.front();
        	q.pop();
        	for(auto to: graph[cur]){
        		if(!vis[to]){
        			parent[to] = cur;
        			vis[to] = true;
        			q.push(to);
        		}
        	}
        }
        vector<int> path;
        while(end != -1){
        	path.push_back(end);
        	end = parent[end];
        }
        if(path.size()%2){
        	return {path[path.size()/2]};
        }
        return {path[path.size()/2 - 1], path[path.size()/2]};
    }
    int bfs(int src, vector<vector<int>>& graph, vector<int>& dis, vector<bool>& vis){
    	vis[src] = true;
    	queue<int> q;
    	q.push(src);
    	while(!q.empty()){
    		int cur = q.front();
    		q.pop();
    		for(auto to: graph[cur]){
    			if(!vis[to]){
    				q.push(to);
    				vis[to] = true;
    				dis[to] = dis[cur] + 1;
     			}
    		}
    	}
    	int farthestVertex = -1;
    	int maxDis = INT_MIN;
    	for(int i=0; i<dis.size(); i++){
    		if(dis[i] > maxDis){
    			maxDis = dis[i];
    			farthestVertex = i;
    		}
    	}
    	return farthestVertex;
    }
};

void solve() {
	
	int n;cin>>n;
	vector<vector<int>> edges;
	rep(i,0,n-1){
		int u,v;cin>>u>>v;
		edges.pb({u, v});
	}
	
	auto ans = Solution().findMinHeightTrees(n, edges);
	
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

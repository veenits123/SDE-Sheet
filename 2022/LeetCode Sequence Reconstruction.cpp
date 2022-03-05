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
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        // write your code here
        int n = org.size();
        
        vector<int> inDegree(n+1, 0);
        vector<vector<int>> graph(n+1);
        
        int count = 0;
        for(auto x: seqs){
        	vector<int> edges = x;
        	count += x.size();
        	
        	if(edges.size() >=1 && (edges[0]<=0 || edges[0]>n))
        		return false;
        	
        	for(int i=1; i<edges.size(); i++){
        		
        		if(edges[i]<=0 || edges[i]>n)
        			return false;
        		
        		graph[edges[i-1]].push_back(edges[i]);
        		inDegree[edges[i]]++;
        	}
        }
        if(count < n)
        	return false;
        
        vector<int> topoOrder;
        
        auto ans = kahn(n, graph, inDegree, topoOrder, org);
        
        return ans;
    }
    bool kahn(int n, vector<vector<int>>& graph, vector<int>& inDegree, vector<int>& topoOrder, vector<int>& org){
    	queue<int> q;
    	for(int i=1; i<=n; i++){
    		if(inDegree[i] == 0){
    			q.push(i);
    		}
    	}
    	int cnt = 0;
    	while(q.size() == 1){
    		
    		int cur = q.front();
    		q.pop();
    		
    		topoOrder.push_back(cur);
    		
    		for(auto to: graph[cur]){
    			inDegree[to]--;
    			if(inDegree[to] == 0)
    				q.push(to);
    		}
    		cnt++;
    	}
    	return topoOrder == org;
    }
};

void solve() {
	
	int n;cin>>n;
	vector<int> org(n);
	rep(i,0,n-1) cin>>org[i];
	
	int e;cin>>e;
	vector<vector<int>> seqs(e);
	
	rep(i,0,e-1){
		int x;cin>>x;
		while(x--){
			int u;cin>>u;
			seqs[i].pb(u);
		}	
	}
	
	cout<<Solution().sequenceReconstruction(org, seqs);

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

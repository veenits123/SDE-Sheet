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
const int inf = 1e9;

vector<pair<int, double>> graph[N];
vector<bool> visited(N);
vector<double> dis(N);

double bfs(int src, int des){
	queue<pair<int, double>> q;
	q.push({src, 1.0});
	visited[src] = true;
	dis[src] = 1.0;
	while(!q.empty()){
		int cur = q.front().first;
		double curCost = q.front().second;
		q.pop();
		
		for(auto x: graph[cur]){
			int to = x.first;
			double w = x.second;
			
			if(!visited[to]){
				double curRatio = w * curCost;
				q.push({to, curRatio});
				dis[to] = curRatio;
				visited[to] = true;
			}
		}
	}
	if(dis[des] != inf)
		return dis[des];
	return inf;
}

void solve() {
	
	int n,e;cin>>n>>e;
	visited.assign(n+1, false);
	dis.assign(n+1, inf);
	
	while(e--){
		int u,v;cin>>u>>v;
		double w;cin>>w;
		
		graph[u].pb({v, w});
		graph[v].pb({u, 1.0/w});	
	}
	int s, d;cin>>s>>d;
	cout<<bfs(s, d);
	

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

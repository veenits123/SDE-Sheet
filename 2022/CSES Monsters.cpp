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
 
char graph[1001][1001];
int dis[1001][1001];
int monsterTime[1001][1001];
pair<P, char> parent[1001][1001];
 
vector<P> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> path = {'L', 'R', 'U', 'D'};
 
int n,m;
 
bool isValid(int r, int c){
	return (r>=0 && r<n && c>=0 && c<m);
}
 
void bfsMonster(vector<P>& coordM){
	queue<pair<P, int>> q;
	for(auto x: coordM)
		q.push({x, 0});
	
	while(!q.empty()){
		int x = q.front().F.F;
		int y = q.front().F.S;
		int curTime = q.front().S;
		
		monsterTime[x][y] = curTime;
		q.pop();
		
		for(int i=0; i<4; i++){
			int r = x + dir[i].F;
			int c = y + dir[i].S;
			
			if(isValid(r, c) && graph[r][c] == '.' && monsterTime[r][c] == -1){
				monsterTime[r][c] = curTime + 1;
				q.push({{r, c}, monsterTime[r][c]});
			}
		}
	}
}
 
void bfs(int sx, int sy){
	queue<P> q;
	q.push({sx, sy});
	dis[sx][sy] = 0;
	while(!q.empty()){
		int x = q.front().F;
		int y = q.front().S;
		q.pop();
		
		for(int i=0; i<4; i++){
			int r = x + dir[i].F;
			int c = y + dir[i].S;
			
			if(isValid(r, c) && graph[r][c] == '.' && 
				(dis[x][y] + 1 < monsterTime[r][c] || monsterTime[r][c] == -1) && dis[r][c] == -1){
				
				q.push({r, c});
				parent[r][c] = {{x, y}, path[i]};
				dis[r][c] = dis[x][y] + 1;
			}
		}
		
	}
}
 
void solve() {
	
	cin>>n>>m;
	
	P src;
	set<P> des;
	vector<P> coordM;
	
	rep(i,0,n-1){
		rep(j,0,m-1){
			cin>>graph[i][j];
			if(graph[i][j] == 'A')
				src = {i, j};
			if(i==0 || i==n-1 || j==0 || j==m-1){
				if(graph[i][j] == '.'){
					des.insert({i, j});
				}
			}
			if(graph[i][j] == 'M')
				coordM.pb({i, j});
		}
	}
	
	if(src.F == 0 || src.F == n-1 || src.S == 0 || src.S == m-1){
		cout<<"YES"<<endl;
		cout<<0;
		return ;
	}
	
	memset(monsterTime, -1, sizeof(monsterTime));
	
	bfsMonster(coordM);
	
	// rep(i,0,n-1){
	// 	rep(j,0,m-1){
	// 		cout<<monsterTime[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	
	memset(dis, -1, sizeof(dis));
	
	bfs(src.F, src.S);
	
	// rep(i,0,n-1){
	// 	rep(j,0,m-1){
	// 		cout<<dis[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	P end;
	bool flag = false;
	for(auto x: des){
		if(dis[x.F][x.S] != -1){
			end = {x.F, x.S};
			flag = true;
			break;
		}
	}
	if(!flag){
		cout<<"NO";
		return ;
	}
	cout<<"YES"<<endl;
	
	string ans = "";
	while(end != src){
		ans += parent[end.F][end.S].S;
		end = parent[end.F][end.S].F;
	}
	reverse(all(ans));
	
	cout<<ans.size()<<endl;
	cout<<ans;
 
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

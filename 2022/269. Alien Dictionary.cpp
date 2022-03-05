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
    * @param words: a list of words
    * @return: a string which is correct order
    */
string alienOrder(vector<string>& words) {
       // Write your code here
		int n = words.size();
		vector<vector<int>> graph(26);
		vector<bool> vis(26, false);
		stack<int> ordering;
		
		map<int, int> occur;
		for(auto word: words){
			for(auto x: word)
				occur[x-'a']= 1;
		}
		
		for(int i=0; i<words.size()-1; i++){
			string w1 = words[i];
			string w2 = words[i+1];
			
			for(int j=0; j<min(w1.size(), w2.size()); j++){
				if(w1[j] != w2[j]){
					graph[w1[j] - 'a'].push_back(w2[j] - 'a');
					break;
				}
			}
		}
		
		for(int i=0; i<26; i++){
			if(!vis[i] && graph[i].size()>=1){
				dfs(i, graph, vis, ordering);
			}
		}
		string ans="";
		while(!ordering.empty()){
			char ch = ordering.top() + 'a';
			occur[ch-'a'] = 0;
			ans += ch;
			ordering.pop();
		}
		for(auto x: occur){
			if(x.second >= 1){
				ans += x.first + 'a';
			}
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
		//cout<<src<<" ";
		ordering.push(src);
}
};


void solve() {
	
	int n;cin>>n;
	vector<string> arr(n);
	rep(i,0,n-1)
	cin>>arr[i];
	
	cout<<Solution().alienOrder(arr);

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

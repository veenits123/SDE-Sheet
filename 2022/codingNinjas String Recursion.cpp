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

int length(string s){
	if(s == "")
		return 0;
	return 1 + length(s.substr(1));
}

string removeX(string s, char x){
	if(s == "")
		return s;
	if(s[0] != x)
		return s[0] + removeX(s.substr(1), x);
	// if(s[0] == x)
	return removeX(s.substr(1), x);
}

string replaceX(string s, char a, char b){
	if(s == "")
		return s;
	if(s[0] != a)
		return s[0] + replaceX(s.substr(1), a, b);
	return b + replaceX(s.substr(1), a, b);
}

void removeDuplicates(char* s){
	if(s[0] == '\0')
		return ;
	if(s[0] == s[1]){
		int i=0;
		while(s[i] != '\0'){
			s[i] = s[i+1];
			i++;
		}
		removeDuplicates(s);
	}
	removeDuplicates(s + 1);
}

void solve() {
	
	char s[100001];
	cin>>s;
	
	// cout<<length(s)<<endl;
	
	// s = removeX(s, 'x');
	
	// cout<<s<<endl;
	
	// cout<<length(s)<<endl;
	
	//cout<<replaceX(s, 'a', 'x');
	
	removeDuplicates(s);
	
	cout<<s<<endl;

	return ;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;cin>>t;while(t--)
	solve();

	return 0;
}

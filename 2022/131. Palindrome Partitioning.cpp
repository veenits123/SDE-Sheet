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
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        generatePallindrome(s, 0, temp, ans);
        return ans;
    }
    void generatePallindrome(string s, int index, vector<string>& temp, vector<vector<string>>& ans){
    	if(index >= s.size()){
    		ans.push_back(temp);
    		return ;
    	}
    	for(int i=index; i<s.size(); i++){
    		if(isPallindrome(s, index, i)){
    			temp.push_back(s.substr(index, i - index + 1));
    			generatePallindrome(s, i + 1, temp, ans);
    			temp.pop_back();
    		}
    	}
    }
    bool isPallindrome(string s, int i, int j){
    	while(i <= j){
    		if(s[i] != s[j]){
    			return false;
    		}
    		i++, j--;
    	}
    	return true;
    }
};

void solve() {
	
	string s;cin>>s;
	auto ans = Solution().partition(s);
	
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

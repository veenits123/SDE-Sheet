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

// generate all strings;
// class Solution {
// public:
//     vector<string> numDecodings(string s) {
//         vector<string> ans;
//         helper(s, 0, "", ans);
//         return ans;
        
//     }
//     void helper(string s, int index, string temp, vector<string>& ans){
//     	if(index >= s.size()){
//     		ans.push_back(temp);
//     		return ;
//     	}
//     	for(int i=1; i<=2; i++){
    		
//     		if(index + i > s.size())
//     			break;
    		
//     		string cur = s.substr(index, i);
    		
//     		int curNumber = stoi(cur);
  
//     		if(curNumber >= 1 && curNumber <=26){
//     			char curChar = 'a' + (curNumber - 1);
//     			temp.push_back(curChar);
//     			helper(s, index + i, temp, ans);
//     			temp.pop_back();
//     		}
//     		else{ // curNumber == 0 || curNumber > 26;
//     			break;
//     		}
//     	}
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
    	int n= s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        if(s[0] - '0' > 0)
        	dp[1] = 1;
        for(int i=2; i<=n; i++){
        	int oneDigit = s[i-1] - '0';
        	int twoDigit = (s[i-2] - '0') * 10 + s[i-1] - '0';
        	
        	if(oneDigit >= 1 && oneDigit <= 9){
        		dp[i] += dp[i-1];
        	}
        	if(twoDigit >= 10 && twoDigit <= 26){
        		dp[i] += dp[i-2];
        	}
        }
        return dp[n];
    }
};

void solve() {
	
	string s;cin>>s;
	auto ans = Solution().numDecodings(s);
	
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

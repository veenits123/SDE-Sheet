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

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> ans;
//         if(digits.empty())
//         	return ans;
//         int num = stoi(digits);
//         ans = keypadComb(num);
//         return ans;
//     }
    
//     vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", 
// 									"mno", "pqrs", "tuv", "wxyz"};

// 	vector<string> keypadComb(int num){
// 		if(num == 0){
// 			vector<string> output = {""};
// 			return output;
// 		}
		
// 		int lastDigit = num%10;
// 		int remainingNum = num/10;
		
// 		vector<string> curComb = keypadComb(remainingNum);
		
// 		vector<string> output;
		
// 		int nextChar = 0;
// 		while(nextChar < keys[lastDigit].size()){
			
// 			for(int i=0; i<curComb.size(); i++){
// 				string temp = curComb[i] + keys[lastDigit][nextChar];
// 				output.push_back(temp);
// 			}
			
// 			nextChar++;
// 		}
// 		return output;
// 	}
// };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
            return ans;
        int num = stoi(digits);
        keypadComb(num, "", ans);
        return ans;
    }
    
    vector<string> keys = {"", "", "abc", "def", "ghi", "jkl", 
								"mno", "pqrs", "tuv", "wxyz"};
	
	void keypadComb(int num, string temp, vector<string>& ans){
		if(num == 0){
			ans.push_back(temp);
			return ;
		}
		int lastDigit = num%10;
		int remNum = num/10;
		
		for(int i=0; i<keys[lastDigit].size(); i++){
			keypadComb(remNum, keys[lastDigit][i] + temp, ans);
		}
	}
};



void solve() {
	
	string s;cin>>s;
	
	auto ans = Solution().letterCombinations(s);
	
	for(auto &x: ans)
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

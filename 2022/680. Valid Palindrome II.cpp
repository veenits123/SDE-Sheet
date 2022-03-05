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
//     bool validPalindrome(string s) {
//         int n=s.size();
//         return helper(s, 0, n-1, 0);
//     }
//     bool helper(string &s, int start, int end, int extra){
//     	if(extra > 1)
//     		return false;
//     	if(start>=end)
//     		return true;
//     	if(s[start] == s[end]){
//     		return helper(s, start+1, end-1, extra);
//     	}
//     	return helper(s, start+1, end, extra+1) || helper(s, start, end-1, extra+1);
//     }
// };

// class Solution {
// public:
//     bool validPalindrome(string s) {
//     	int i=0;
//         int j=s.size()-1;
//         while(i<j){
//         	if(s[i] != s[j]){

//         		int skipLeft = i+1, jLeft=j;
//         		while(skipLeft < jLeft && s[skipLeft] == s[jLeft]){
//         				skipLeft++;
//         				jLeft--;
//         		}

//         		int iRight = i, skipRight = j-1;
//         		while(iRight < skipRight && s[iRight] == s[skipRight]){
//         				iRight++, skipRight--;
//         		}
//         		return skipLeft>=jLeft || iRight>=skipRight;
//         	}
//         	else
//         		i++, j--;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool validPalindrome(string s) {
    	int i=0;
        int j=s.size()-1;
        while(i < j){
        	if(s[i] == s[j]){
        		i++;
        		j--;
        	}
        	else{
        		// skip 1 character from left or skip 1 character from right;
        		return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
        	}
        }
        return true;
    }
    bool isPalindrome(string &s, int i, int j){
    	while(i < j && s[i] == s[j])
    		i++, j--;
    	return i>=j;
    }
};

void solve() {

	string s;cin>>s;
	cout<<Solution().validPalindrome(s);

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

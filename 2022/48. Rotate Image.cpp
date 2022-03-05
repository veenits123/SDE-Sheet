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
//     void rotate(vector<vector<int>>& matrix) {
//     	int n = matrix.size();
//         for(int i=0;i<n;i++){
//         	for(int j=i;j<n;j++){
//         		int temp = matrix[i][j];
//         		matrix[i][j] = matrix[j][i];
//         		matrix[j][i] = temp;	
//         	}
//         }
//         for(int i=0;i<n;i++){
//         	reverse(all(matrix[i]));
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
    	vector<vector<int>> ans(n, vector<int>(n,-1));
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		ans[j][n-i-1] = matrix[i][j];
        	}
        }
     matrix = ans;	 
    }
};

void solve() {

	int n;cin>>n;
	vector<vector<int>> mat(n, vector<int>(n));
	rep(i, 0, n-1)
	rep(j, 0, n-1)
	cin>>mat[i][j];

	Solution().rotate(mat);

	rep(i, 0, n-1){
	rep(j, 0, n-1)
	cout<<mat[i][j]<<" ";
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

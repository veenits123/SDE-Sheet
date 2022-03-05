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
//     int maximalRectangle(vector<vector<char>>& matrix) {
//     	int n = matrix.size();
//     	int m = matrix[0].size();
//         vector<int> heights(m);
        
//         int maxArea = 0;
        
//         for(int j=0; j<m; j++){
//         	heights[j] = (matrix[0][j] == '1' ? 1 : 0);
//         }
//         // for(int i=0; i<m; i++)
//         // 	cout<<heights[i]<<" ";
//         // cout<<endl;
//         maxArea = max(maxArea, maxAreaHistogram(heights));
        
//         for(int i=1; i<n; i++){
//         	for(int j=0; j<m; j++){
//         		heights[j] = (matrix[i][j] == '1' ? 1 + heights[j] : 0);
//         	}
        	
//         	// for(int i=0; i<m; i++)
//         	// 	cout<<heights[i]<<" ";
//         	// cout<<endl;
        	
//         	maxArea = max(maxArea, maxAreaHistogram(heights));
//         }
//         return maxArea;
//     }
//     int maxAreaHistogram(vector<int>& heights){
//     	int n = heights.size();
//     	vector<int> leftSmaller(n);
//     	vector<int> rightSmaller(n);
//     	stack<int> index;
    	
//     	int maxArea = 0;
    	
//     	for(int i=0; i<n; i++){
//     		while(!index.empty() && heights[index.top()] >= heights[i]){
//     			index.pop();
//     		}
//     		if(index.empty())
//     			leftSmaller[i] = 0;
//     		else
//     			leftSmaller[i] = index.top() + 1;
    		
//     		index.push(i);
//     	}
    	
//     	index = stack<int>();
    	
//     	for(int i=n-1; i>=0; i--){
//     		while(!index.empty() && heights[index.top()] >= heights[i]){
//     			index.pop();
//     		}
//     		if(index.empty())
//     			rightSmaller[i] = n-1;
//     		else
//     			rightSmaller[i] = index.top() - 1;
    		
//     		index.push(i);
    		
//     		if((rightSmaller[i] - leftSmaller[i] + 1) == heights[i])
//     			maxArea = max(maxArea, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
//     	}
//     	return maxArea;
//     }
// };

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	int n = matrix.size();
    	int m = matrix[0].size();
    	
    	vector<int> heights(m, 0);
    	vector<int> leftSmaller(m, 0);
    	vector<int> rightSmaller(m, m-1);
    	
    	int maxArea = 0;
    	for(int i=0; i<n; i++){
    		
    		int curLeft = 0, curRight = m-1;
    		
    		for(int j=0; j<m; j++){
    			if(matrix[i][j] == '1')
    				heights[j]++;
    			else
    				heights[j] = 0;
    		}
    		
    		for(int j=0; j<m; j++){
    			if(matrix[i][j] == '1')
    				leftSmaller[j] = max(leftSmaller[j], curLeft);
    			else
    				leftSmaller[j] = 0, curLeft = j + 1;
    		}
    		
    		for(int j=m-1; j>=0; j--){
    			if(matrix[i][j] == '1')
    				rightSmaller[j] = min(rightSmaller[j], curRight);
    			else
    				rightSmaller[j] = m-1, curRight = j - 1;
    		}
    		
    		// for(int j=0; j<m; j++)
    		// 	cout<<rightSmaller[j]<<" ";
    		// cout<<endl;
    		
    		for(int j=0; j<m; j++){
    			maxArea = max(maxArea, (rightSmaller[j] - leftSmaller[j] + 1) * heights[j]);
    		}
    	}
        return maxArea;
    }
};

void solve() {
	
	int n, m;cin>>n>>m;
	vector<vector<char>> arr(n, vector<char>(m));
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>arr[i][j];
	
	cout<<Solution().maximalRectangle(arr);

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

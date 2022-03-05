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

// O(N^2)
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//     	int n = heights.size();
//     	int ans = 0;
//         for(int i=0; i<n; i++){
//         	int curArea = 0;
//         	int leftSmaller = 0, rightSmaller = n - 1;
        	
//         	for(int l=i; l>=0; l--){
//         		if(heights[l] < heights[i]){
//         			leftSmaller = l + 1;
//         			break;
//         		}
//         	}
//         	for(int r=i+1; r<n; r++){
//         		if(heights[r] < heights[i]){
//         			rightSmaller = r - 1;
//         			break;
//         		}
//         	}
//         	curArea = heights[i] * (rightSmaller - leftSmaller + 1);
        	
//         	ans = max(ans, curArea);
//         }
//         return ans;
//     }
// };

// O(5*N)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int n = heights.size();
    	vector<int> leftSmaller(n);
    	vector<int> righSmaller(n);
    	
    	stack<int> index;
    	for(int i=0; i<n; i++){
			while(!index.empty()){
				int top = index.top();
				if(heights[top] >= heights[i]){
					index.pop();
				}
				else{
					break;
				}
			}
			if(index.empty()){
				leftSmaller[i] = 0;
			}
			else{
				leftSmaller[i] = index.top() + 1;
			}
    		index.push(i);
    	}
    	
    	index = stack<int>();
    	
    	for(int i=n-1; i>=0; i--){
			while(!index.empty()){
				int top = index.top();
				if(heights[top] >= heights[i]){
					index.pop();
				}
				else{
					break;
				}
			}
			if(index.empty()){
				righSmaller[i] = n - 1;
			}
			else{
				righSmaller[i] = index.top() - 1;
			}
			index.push(i);
		}
    	int ans = 0;
    	for(int i=0; i<n; i++){
    		//cout<<righSmaller[i]<<" "<<leftSmaller[i]<<endl;
    		ans = max(ans, (righSmaller[i] - leftSmaller[i] + 1) * heights[i]);
    	}
    	return ans;
    }
};

void solve() {
	
	int n;cin>>n;
	vector<int> arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	cout<<Solution().largestRectangleArea(arr);

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

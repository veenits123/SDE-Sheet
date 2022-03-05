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
    int minimumMountainRemovals(vector<int>& nums) {
    	int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> lds(n, 1);
        
        for(int i=1; i<n; i++){
        	for(int j=0; j<i; j++){
        		if(nums[j] < nums[i]){
        			lis[i] = max(lis[i], lis[j] + 1);
        		}
        	}
        }
        for(int i=n-2; i>=0; i--){
        	for(int j=n-1; j>i; j--){
        		if(nums[j] < nums[i]){
        			lds[i] = max(lds[i], lds[j] + 1);
        		}
        	}
        }
        int longestBitonicArray = 0;
        for(int i=0; i<n; i++){
        	if(lis[i] > 1 && lds[i] > 1)
        		longestBitonicArray = max(longestBitonicArray, lis[i] + lds[i] - 1);
        }
        return n - longestBitonicArray;
    }
};

void solve() {
	
	int n;cin>>n;
	vector<int> arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	cout<<Solution().minimumMountainRemovals(arr);

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

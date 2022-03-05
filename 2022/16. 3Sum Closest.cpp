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
    vector<int> threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int closet = 100000;
        for(int i=0; i<n-2; i++){
        	
        	int left = i+1, right = n-1;
        	while(left < right){
        		int curSum = nums[i] + nums[left] + nums[right];
        		
        		if(curSum == target){
        			ans = {nums[i], nums[left], nums[right]};
        			return ans;
        		}
        		
        		if(abs(target - curSum) < abs(target - closet)){
        			closet = curSum;
        			ans = {nums[i], nums[left], nums[right]};
        		}
        		
        		if(curSum > target){
        			right--;
        		}
        		else{
        			left++;
        		}
        	}
        }
        return ans;
    }
};

void solve() {
	
	int n;cin>>n;
	vi arr(n);
	rep(i,0,n-1) cin>>arr[i];
	int k;cin>>k;
	
	auto ans = Solution().threeSumClosest(arr, k);
	
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

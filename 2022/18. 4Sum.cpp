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
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//     	int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;
//         vector<vector<int>> ans;
//         if(n <= 3)
//         	return ans;
//         for(int i=0; i<n; i++){
//         	for(int j=i+1; j<n; j++){
//         		for(int k=j+1; k<n; k++){
//         			int remainingSum = target - (nums[i] + nums[j] + nums[k]);
//         			if(binary_search(nums.begin() + k + 1, nums.end(), remainingSum)){
//         				vector<int> temp = {nums[i], nums[j], nums[k], remainingSum};
//         				s.insert(temp);
//         			}
//         		}
//         	}
//         }
//         for(auto x: s)
//         	ans.push_back(x);
//         return ans;
//     }   
// };

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	int n = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
        if(n <= 3)
        	return ans;
        for(int i=0; i<n; i++){
        	for(int j=i+1; j<n; j++){
        		int left = j + 1, right = n - 1;
        		while(left < right){
        			int sumLeft = nums[i] + nums[j];
        			int remainingSum = target - sumLeft;
        			int sumMiddleEnd = nums[left] + nums[right];
        			
        			if(sumMiddleEnd > remainingSum)
        				right--;
        			else if(sumMiddleEnd < remainingSum)
        				left++;
        			else{
        				vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
        				ans.push_back(temp);
        				
        				//left++, right--;
        				
        				while(left < right && nums[left] == temp[2])
        					left++;
        				while(left < right && nums[right] == temp[3])
        					right--;		 
        			}
        		}
        		while((j+1) < n && nums[j] == nums[j+1])
        			j++;
        	}
        	while((i+1) < n && nums[i] == nums[i+1])
        		i++;
        }
        return ans;  		
    }
};

void solve() {
	
	int n, k;cin>>n>>k;
	vector<int> arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	auto ans = Solution().fourSum(arr, k);
	
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

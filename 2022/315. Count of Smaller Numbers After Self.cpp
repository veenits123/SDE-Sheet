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
    vector<int> countSmaller(vector<int>& nums) {
    	int n=nums.size();
    	if(n==0)
    		return {};
    	if(n==1)
    		return {0};
    	
    	vector<int> count(n, 0);
    	vector<P> arr, temp;
    	for(int i=0;i<n;i++){
    		arr.push_back({nums[i], i});
    		temp.push_back({nums[i], i});
    	}
    		
        mergeSort(arr, temp, count, 0, n-1);
        
        return count;
    }
    
    void mergeSort(vector<P> &arr, vector<P> &temp, vector<int> &count, int left, int right){
    	if(left>=right)
    		return ;
    	
    	if(left < right){
    		int mid = left + (right - left)/2;
    		    		
    		mergeSort(arr, temp, count, left, mid);
    		mergeSort(arr, temp, count, mid+1, right);
    		
    		merge(arr, temp, count, left, mid, right);	
    	}
    }
    
    void merge(vector<P> &arr, vector<P> &temp, vector<int> &count, int left, int mid, int right){
    	int n=arr.size();
    	
    	int i=left, j=mid+1, k=left;
    	int smallerNumberAfter = 0;
    	
    	while(i<=mid && j<=right){
    		if(arr[i] <= arr[j]){
    			temp[k] = arr[i];
    			count[arr[i].second] += smallerNumberAfter;
    			i++, k++;
    		}
    		else{
    			temp[k] = arr[j];
    			smallerNumberAfter++;
    			j++, k++;
    		}
      	}
    	while(i<=mid){
    		temp[k] = arr[i];
    		count[arr[i].second] += smallerNumberAfter;
    		i++, k++;
    	}
    	while(j<=right){
    		temp[k] = arr[j];
    		j++, k++;
    	}
    	for(int i=left;i<=right;i++)
    		arr[i] = temp[i];
    }
};

void solve() {
	
	int n;cin>>n;
	vector<int> arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	auto ans = Solution().countSmaller(arr);
		
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

// never the same!!
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

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         map<int,int> frequency;
//         for(auto &x: nums)
//         	frequency[x]++;
//         vector<P> arr;
//         for(auto &x: frequency)
//         	arr.push_back({x.first, x.second});

//         sort(arr.begin(), arr.end(), comp);

//         vector<int> ans;
//         for(auto &x: arr){
//         	while(x.second--){
//         		ans.push_back(x.first);
//         	}
//         }
//         return ans;
//     }
//     bool static comp(P &a, P &b){
//     	if(a.second == b.second)
//     		return a.first > b.first;
//     	return a.second < b.second;
//     }
// };

// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         map<int,int> frequency;
//         for(auto &x: nums)
//         	frequency[x]++;

//         auto comp = [&](int &a, int &b){
//         	if(frequency[a] == frequency[b])
//         		return a>b;
//         	return frequency[a] < frequency[b];
//         };

//         sort(nums.begin(), nums.end(), comp);

//         return nums;
//     }
// };

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> frequency;
        for(auto &x: nums)
        	frequency[x]++;

        auto comp = [&](P &a, P &b){
        	if(a.F == b.F)
        		return a.S > b.S;
        	return a.F > b.F;
        };

        priority_queue<P, vector<P>, decltype(comp)> q(comp);

        for(auto &x: frequency)
        	q.push({x.second, x.first});

        vector<int> ans;
        while(!q.empty()){
        	int num = q.top().second;
        	int count = q.top().first;
        	q.pop();

        	while(count--)
        		ans.push_back(num);
        }
        return ans;
    }
};


void solve() {

	int n;cin>>n;
	vector<int> arr(n);
	REP(i,0,n-1) cin>>arr[i];

	auto ans = Solution().frequencySort(arr);

	for(auto x:ans)
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

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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	vector<vector<int>> ans;
    	if(k<=0 || nums1.size()==0 || nums2.size()==0)
    		return ans;

    	auto comp = [&](P &a, P &b){
    		return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    	};

        priority_queue<P, vector<P>, decltype(comp)> q(comp);
        q.push({0,0});

        while(k-- && !q.empty()){
        	auto indices = q.top();
        	q.pop();

        	int idx1 = indices.first, idx2 = indices.second;
        	ans.push_back({nums1[idx1], nums2[idx2]});

        	if((idx1 + 1) < nums1.size())
        		q.push({idx1 + 1, idx2});
        	if(idx1 == 0 && (idx2 + 1) < nums2.size())
        		q.push({idx1, idx2 + 1});
        }
        return ans;
    }
};

void solve() {

	int n,m;cin>>n>>m;
	vi arr1(n), arr2(m);
	rep(i, 0, n-1) cin>>arr1[i];
	rep(i, 0, n-1) cin>>arr2[i];

	int k;cin>>k;

	auto ans = Solution().kSmallestPairs(arr1, arr2, k);

	for(auto &x: ans)
		cout<<x[0]<<" "<<x[1]<<endl;

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

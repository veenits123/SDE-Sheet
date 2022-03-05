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

#define psi pair<string, int>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> count;
        for(auto &x: words)
        	count[x]++;

        auto comp = [&](psi &a, psi &b){
        	if(a.second == b.second)
        		return a.first < b.first;
        	return a.second > b.second;
        };

        priority_queue<psi, vector<psi>, decltype(comp)> q(comp);

        for(auto &x: count){
        	q.push({x.first, x.second});
        	if(q.size() > k)
        		q.pop();
        }
        vector<string> ans;
        while(!q.empty()){
        	ans.insert(ans.begin(), q.top().first);
        	q.pop();
        }
        return ans;
    }
};

void solve() {

	int n;cin>>n;
	vector<string> arr(n);
	rep(i, 0, n-1) cin>>arr[i];

	int k;cin>>k;

	auto ans = Solution().topKFrequent(arr, k);

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

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

#define pip pair<int, pair<int,int>> 

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> q;
        for(auto &x: points){
        	int distance = x[0]*x[0] + x[1]*x[1];
        	q.push({distance, x[0], x[1]});
        	if(q.size()>k)
        		q.pop();
        }
        vector<vector<int>> ans;
        while(!q.empty()){
        	int xCoord = q.top()[1];
        	int yCoord = q.top()[2];
        	ans.push_back({xCoord, yCoord});
        	q.pop();
        }
        return ans;
    }
};

void solve() {

	int n;cin>>n;
	vector<vector<int>> points(n,vector<int>(2));
	REP(i, 0, n-1){
		cin>>points[i][0]>>points[i][1];
	}
	int k;cin>>k;

	auto ans = Solution().kClosest(points, k);

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

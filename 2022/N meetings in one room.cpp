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

#define dataType pair<P,int>

class Solution{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n){
        // Your code here
        vector<dataType> arr;
        for(int i=0;i<n;i++){
        	arr.push_back({{start[i], end[i]}, i});
        }
        sort(arr.begin(), arr.end(), comp);
        
        int ans=1;
        int prev=arr[0].F.S;
        for(auto &x: arr){
        	int cur = x.F.F;
        	if(cur > prev){
        		ans++;
        		prev=x.F.S;
        	}
        }
        return ans;
    }
    static bool comp(dataType &a, dataType &b){
    	if(a.F.S==b.F.S)
    		return a.S<b.S;
    	return a.F.S < b.F.S;
    }
};

void solve() {
	
	int n;cin>>n;
	int st[n], en[n];
	rep(i,0,n-1) cin>>st[i];
	rep(i,0,n-1) cin>>en[i];
	
	cout<<Solution().maxMeetings(st, en, n);

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

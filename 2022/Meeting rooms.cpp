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

bool comp(vector<int> &a, vector<int> &b){
	return a[0] < b[0];
}

int minRooms(vector<vector<int>> &A){
    int n=A.size();
    sort(A.begin(), A.end(), comp);
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(A[0][1]);
    for(int i=1;i<n;i++){
    	int curEnding = q.top();
    	if(A[i][0] >= curEnding){
    		q.pop();
    		q.push(A[i][1]);
    	}
    	else
    		q.push(A[i][1]);
    }
    return q.size();
}

int func(vector<vector<int>> &A) {
	return minRooms(A);
}


void solve() {
	
	int n;cin>>n;
	int m=2;
	
	vector<vector<int>> arr(n, vector<int>(m));
	
	rep(i,0,n-1)
	rep(j,0,m-1)
	cin>>arr[i][j];
	
	cout<<func(arr);

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

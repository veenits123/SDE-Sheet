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
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
        	return n;
        int ans = 0;
        for(int i=0; i<n; i++){
        	
        	map<pair<int, int>, int> slopes; // to avoid parallel lines;
        	
        	int samePoint = 1;
        	
        	for(int j=i+1; j<n; j++){
        		
        		int x1 = points[i][0];
        		int y1 = points[i][1];
        		
        		int x2 = points[j][0];
        		int y2 = points[j][1];
        		
        		if(x1 == x2 && y1 == y2){
        			samePoint++;
        			continue;
        		}
        		
        		else{
        			// slope = dy/dx;
        			// this double may give error bcz while dividing dx -> (x2 - x1) may be 0;
        			
        			int dx = (x2 - x1);
        			int dy = (y2 - y1);
        			
        			// dy = 4, dx = 2 and dy = 8, dx = 4 represents the same slope that's why divide by gcd;
        			int gcdXY = gcd(dx, dy); // gcd(0, 3) = 3;
        			
        			//cout<<dx/gcdXY<<" "<<dy/gcdXY<<endl;
        			
	        		pair<int, int> slope = {dx/gcdXY, dy/gcdXY}; 
	        		slopes[slope]++;
	        	}
        	}
        	//cout<<endl;
        	ans = max(ans, samePoint); // in case all given points are same;
	        for(auto x: slopes){
	        	ans = max(ans, x.second + samePoint);	
	        }
        }
        return ans;
    }
    int gcd(int a, int b){
    	return b == 0 ? a : gcd(b, a % b);
    }
};

void solve() {
	
	int n;cin>>n;
	vector<vector<int>> points(n, vector<int>(2));
	rep(i,0,n-1) cin>>points[i][0]>>points[i][1];
	
	cout<<Solution().maxPoints(points);
	
	
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

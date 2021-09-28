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

const int inf=1e9;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    int n=asteroids.size();
    stack<int> s;
s.push(asteroids[n-1]);

for(int i=n-2;i>=0;i--){
	int tp=inf;
	while(!s.empty()){
		tp=s.top();
		//s.pop();
		break;
	}
if(tp>0){
//s.push(tp);
 s.push(asteroids[i]);
 }
else{
int absTp=abs(tp);

if(absTp>asteroids[i] && (asteroids[i]>0)){
//s.push(tp);
}
else if(absTp<asteroids[i] && asteroids[i]>0){
	if(tp!=inf)
	   s.pop();
	while(!s.empty() && s.top()<0){
		if(abs(s.top())>asteroids[i])
			break;
		else if(abs(s.top())==asteroids[i])
			s.pop();
		// else if(abs(s.top())<asteroids[i]){
		// 	s.pop();
		// 	s.push(asteroids[i]);
		// }
	}
}
else if(absTp==asteroids[i]){
	if(tp!=inf)
		s.pop();
	//continue;
}
else{
//s.push(tp);
s.push(asteroids[i]);
}
}
}
vector<int> ans;
while(!s.empty()){
ans.push_back(s.top());
s.pop();
}
return ans;
    }
};

void solve(){

int n;cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
cin>>a[i];

vector<int> ans=Solution().asteroidCollision(a);

for(int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";

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

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

void solve() {

	int n;cin>>n;
	vector<string> vs(n);
	//vector<pair<int,int>> ind;
	for(int i=0;i<n;i++)
		cin>>vs[i];
	int q;cin>>q;
	for(int i=0;i<q;i++){
		int l,r,k;cin>>l>>r>>k;
		l--;
		r--;
		k--;
	
		string temp="";
		for(int j=l;j<=r;j++){
			temp+=vs[j];
		}
		sort(temp.begin(),temp.end());
		cout<<temp[k]<<endl;
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

	
		solve();
	

	return 0;
}

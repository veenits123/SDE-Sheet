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
using namespace std;

/*ϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕϕ*/

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

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;

class Stack {
private:
	int stack[N];
	int itr;
public:
	Stack() {
		itr = -1;
	}
	void push(int val) {
		if (itr == N)
			return ;
		itr++;
		stack[itr] = val;
	}
	int top() {
		if (itr == -1)
			return -1;
		return stack[itr];
	}
	int pop() {
		if (itr == -1)
			return -1;
		int temp = stack[itr];
		itr--;
		return temp;
	}
	int size() {
		return (itr + 1);
	}
	bool empty() {
		return (itr == -1);
	}
};

void solve() {

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.size() << endl;
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	s.pop();

	s.pop();

	cout << s.top() << endl;
	cout << s.size() << endl;


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
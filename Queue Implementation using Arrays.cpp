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

class Queue {
private:
	int queue[N];
	int forward;
	int rear;
	int cnt;
public:
	Queue() {
		forward = rear = 0;
		cnt = 0;
	}
	void push(int val) {
		if (cnt == N)
			return ;
		cnt++;
		queue[rear % N] = val;
		rear++;
	}
	int front() {
		if (cnt == 0)
			return -1;
		return queue[forward % N];
	}
	int pop() {
		if (cnt == 0)
			return -1;
		cnt--;
		int temp = queue[forward % N];
		forward++;
		return temp;
	}
	bool empty() {
		return (cnt == 0);
	}
	int size() {
		return cnt;
	}
};

void solve() {

	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.size() << endl;
	cout << q.empty() << endl;
	cout << q.front() << endl;

	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();



	cout << q.size() << endl;
	cout << q.front() << endl;

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
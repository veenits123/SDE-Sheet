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

struct Node {
	int data;
	struct Node *next;
	struct Node *bottom;

	Node(int val) {
		data = val;
		next = NULL;
		bottom = NULL;
	}
};

Node *merge(Node *a, Node *b) {

	Node *temp = new Node(0);
	Node *res = temp;

	while (a && b) {
		if (a->data < b->data) {
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else {
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom;
		}
	}
	if (a->bottom)
		temp->bottom = a;
	else
		temp->bottom = b;
	return res->bottom;
}

Node *flatten(Node *root) {
	if (!root || root->next)
		return root;

	root->next = flatten(root->next);

	root = merge(root, root->next);

	return root;
}


void solve() {

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
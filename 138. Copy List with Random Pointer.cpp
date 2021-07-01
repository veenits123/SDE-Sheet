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


// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

//tc: O(n), sc: O(n);
// class Solution {
// public:
// 	Node* copyRandomList(Node* head) {
// 		map <Node*, Node*> m;
// 		Node *cur = head;
// 		while (cur) {
// 			m[cur] = new Node(cur->val);
// 			cur = cur->next;
// 		}
// 		cur = head;

// 		while (cur) {
// 			Node *temp = m[cur];

// 			if (cur->next)
// 				temp->next = m[cur->next];
// 			if (cur->random)
// 				temp->random = m[cur->random];

// 			cur = cur->next;
// 		}
// 		Node *ans = m[head];
// 		return ans;
// 	}
// };

//tc: O(n), sc: O(1);
class Solution {
public:
	Node* copyRandomList(Node* head) {
		//step I;
		Node *it = head;
		Node *fwd = head;

		while (it) {
			fwd = it->next;

			Node *copy = new Node(it->val);
			it->next = copy;
			copy->next = fwd;

			it = fwd;
		}
		//step II;
		it = head;
		while (it) {
			if (it->random)
				it->next->random = it->random->next;
			else
				it->next->random = it->random;
			it = it->next->next;
		}
		//step III;
		it = head;
		Node *dummy = new Node(0);
		Node *copyAns = dummy;

		while (it) {
			fwd = it->next->next;

			copyAns->next = it->next;//copied list;

			it->next = fwd;//original list;

			copyAns = copyAns->next;

			it = it->next;
		}
		return dummy->next;
	}
};

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
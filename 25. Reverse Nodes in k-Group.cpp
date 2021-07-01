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

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Create Linked List.
ListNode* createll() {
	int n; cin >> n;
	ListNode *head = NULL, *tail = NULL;
	while (n--) {
		int x; cin >> x;
		if (head == NULL) {
			ListNode *cur = new ListNode(x);
			head = cur;
			tail = cur;
		}
		else {
			ListNode *cur = new ListNode(x);
			tail->next = cur;
			tail = cur;
		}
	}
	return head;
}

//Print Linked List.
void print(ListNode* head) {
	ListNode *cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {

		if (head == nullptr || k == 1)
			return head;

		int len = 0;
		ListNode *temp = head;
		while (temp) {
			len++;
			temp = temp->next;
		}

		ListNode *dummy = new ListNode();
		dummy->next = head;

		ListNode *prev = dummy;
		ListNode *cur = dummy;
		ListNode *nex = dummy;

		while (len >= k) {
			cur = prev->next;//first node of any block;
			nex = cur->next;//2nd node of any block;

			REP(i, 1, k - 1) {//break one less link than block size;
				cur->next = nex->next;
				nex->next = prev->next;//not = cur bcz in 1st itrn it's fine, but after this it escapes node in between "nex" and "cur";
				prev->next = nex;
				nex = cur->next;
			}

			prev = cur;
			len -= k;
		}
		return dummy->next;
	}
};

//method 2;
// class Solution {
// public:
// 	ListNode* reverseKGroup(ListNode* head, int k) {
// 		ListNode *cur = head;
// 		while (cur) {
// 			vector <int> data;
// 			ListNode *temp = cur;

// 			while (cur && data.size() < k) {
// 				data.push_back(cur->val);
// 				cur = cur->next;
// 			}
// 			if (data.size() != k)
// 				break;

// 			while (temp && data.size()) {
// 				temp->val = data.back();
// 				data.pop_back();
// 				temp = temp->next;
// 			}
// 		}
// 		return head;
// 	}
// };

void solve() {

	ListNode *head = createll();

	head = Solution().reverseKGroup(head, 3);

	print(head);

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
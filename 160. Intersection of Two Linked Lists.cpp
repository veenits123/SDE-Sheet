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
	if (head == nullptr) {
		cout << "null" << endl;
		return ;
	}
	ListNode *cur = head;
	while (cur != NULL) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void intersect(ListNode *l1, ListNode *l2, int pos) {
	if (pos == 0)
		return ;
	ListNode *temp1 = l1;
	pos--;
	while (pos--) {
		temp1 = temp1->next;
	}
	ListNode *temp2 = l2;
	while (temp2->next != nullptr)
		temp2 = temp2->next;
	temp2->next = temp1;
}

//tc: O(m*n), sc: O(1);
// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		ListNode *temp1 = headA;
// 		ListNode *temp2 = headB;

// 		while (temp1) {
// 			temp2 = headB;
// 			while (temp2) {
// 				if (temp1 == temp2) {
// 					return temp1;
// 				}
// 				temp2 = temp2->next;
// 			}
// 			temp1 = temp1->next;
// 		}
// 		return nullptr;
// 	}
// };

//tc: O(m+n), sc: O(m or n depends which list is stored in map);
// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		ListNode *temp1 = headA;
// 		ListNode *temp2 = headB;
// 		map <ListNode*, int> m;
// 		while (temp1) {
// 			m[temp1] = 1;
// 			temp1 = temp1->next;
// 		}
// 		while (temp2) {
// 			if (m[temp2] == 1)
// 				return temp2;
// 			temp2 = temp2->next;
// 		}
// 		return nullptr;
// 	}
// };

//tc: O(m+n), sc: O(1);
// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		ListNode *temp1 = headA;
// 		ListNode *temp2 = headB;
// 		int l1 = 0, l2 = 0;
// 		while (temp1) {
// 			l1++;
// 			temp1 = temp1->next;
// 		}
// 		while (temp2) {
// 			l2++;
// 			temp2 = temp2->next;
// 		}
// 		int pos;
// 		if (l1 > l2) {
// 			pos = l1 - l2;
// 			temp1 = headA;
// 			temp2 = headB;
// 		}
// 		else {
// 			pos = l2 - l1;
// 			temp1 = headB;
// 			temp2 = headA;
// 		}
// 		while (pos--)
// 			temp1 = temp1->next;
// 		while (temp1 && temp2) {
// 			if (temp1 == temp2)
// 				return temp1;
// 			temp1 = temp1->next;
// 			temp2 = temp2->next;
// 		}
// 		return nullptr;
// 	}
// };

//tc: O(m+n), sc: O(1) but consice & crispy;
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *temp1 = headA;
		ListNode *temp2 = headB;

		while (temp2 != temp1) {
			temp1 = (temp1 == nullptr) ? headB : temp1->next;

			temp2 = (temp2 == nullptr) ? headA : temp2->next;
		}
		return temp1;
	}
};

void solve() {

	ListNode *head1 = createll();
	ListNode *head2 = createll();

	intersect(head1, head2, 3);

	// print(head1);
	// print(head2);

	auto head = Solution().getIntersectionNode(head1, head2);

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
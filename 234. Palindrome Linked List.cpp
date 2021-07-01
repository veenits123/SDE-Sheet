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

//sc: O(n);
// class Solution {
// public:
// 	bool isPalindrome(ListNode* head) {
// 		vector <int> a;
// 		while (head)
// 			a.push_back(head->val), head = head->next;
// 		int n = a.size();
// 		REP(i, 0, n - 1) {
// 			if (a[i] != a[n - i - 1])
// 				return false;
// 		}
// 		return true;
// 	}
// };

//sc: O(1);
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		ListNode *slow = middle(head);
		slow = slow->next;

		//print(slow);

		ListNode *revHalf = reverse(slow);
		slow = revHalf;

		ListNode *dummy = head;

		//print(dummy);

		while (slow) {
			if (dummy->val != slow->val)
				return false;
			slow = slow->next;
			dummy = dummy->next;
		}
		//print(head);
		return true;
	}

	ListNode *middle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {//bcz we need to return 1st node in case of even lenth linkedList :/
			slow = slow->next;
			fast = fast->next->next;
		}
		//print(head);
		return slow;
	}

	ListNode *reverse(ListNode *head) {
		ListNode *cur = head;
		ListNode *prev = nullptr;
		while (cur) {
			ListNode *ahead = cur->next;
			cur->next = prev;
			prev = cur;
			cur = ahead;
		}
		//print(head);
		return prev;
	}
};

void solve() {

	ListNode *head = createll();

	cout << Solution().isPalindrome(head);

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
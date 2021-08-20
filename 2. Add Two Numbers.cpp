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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummy = new ListNode();
		ListNode *cur = dummy;
		int carry = 0;
		while (l1 || l2 || carry) {
			int sum = 0;
			if (l1) {
				sum += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				sum += l2->val;
				l2 = l2->next;
			}
			sum += carry;
			int base = sum % 10;
			carry = sum / 10;

			ListNode *temp = new ListNode(base);
			cur->next = temp;
			cur = temp;
		}
		return dummy->next;
	}
};

void solve() {

	ListNode *l1 = createll();
	ListNode *l2 = createll();

	auto ans = Solution().addTwoNumbers(l1, l2);

	print(ans);

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
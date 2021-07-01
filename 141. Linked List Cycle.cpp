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

void makeCycle(ListNode *head, int pos) {
	if (pos == -1)
		return ;
	ListNode *tail = head;
	ListNode *attach = head;
	while (pos--)
		attach = attach->next;
	while (tail->next)
		tail = tail->next;
	tail->next = attach;
}

//tc: O(n), sc: O(n);
class Solution {
public:
	ListNode *hasCycle(ListNode *head) {
		map <ListNode*, int> m;
		ListNode *temp = head;
		while (temp) {
			if (m[temp])
				return temp;
			m[temp] = 1;
			temp = temp->next;
		}
		return nullptr;
	}
};

//sc: O(1);
// class Solution {
// public:
// 	bool hasCycle(ListNode *head) {
// 		if (head == nullptr || head->next == nullptr)
// 			return false;

// 		ListNode *slow = head, *fast = head;
// 		while (fast->next && fast->next->next) {
// 			slow = slow->next;

// 			fast = fast->next->next;
// 			if (slow == fast)
// 				return true;
// 		}
// 		return false;
// 	}
// };

void solve() {

	ListNode *head = createll();

	//print(head);

	makeCycle(head, 2);

	//cout << Solution().hasCycle(head);


	//return node from where cycle started :)
	auto ans = Solution().hasCycle(head);
	map <ListNode*, int> m;
	while (ans) {
		if (m[ans]) {
			cout << ans->val << " ";
			break;
		}
		m[ans] = 1;
		cout << ans->val << " ";
		ans = ans->next;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}
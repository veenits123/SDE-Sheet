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
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur) {
            ListNode* ahead = cur->next;
            cur->next = prev;
            prev = cur;
            cur = ahead;
        }
        //print(head);
        return prev;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         return revRecursive(head);
//     }
//     ListNode* revRecursive(ListNode* head) {

//         if (head == NULL || head->next == NULL)
//             return head;

//         ListNode *cur = revRecursive(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return cur;
//     }
// };

void solve() {

    ListNode *node = createll();

    node = Solution().reverseList(node);

    while (node) {
        cout << node->val << " ";
        node = node->next;
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
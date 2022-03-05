/**
 * तस्मात्सर्वेषु कालेषु मामनुस्मर युध्य च ।
 * मय्यर्पितमनोबुद्धिर्मामेवैष्यस्यसंशय: ॥
 * 
 * Hare Kṛṣṇa Hare Kṛṣṇa
 * Kṛṣṇa Kṛṣṇa Hare Hare
 * Hare Rāma Hare Rāma
 * Rāma Rāma Hare Hare
**/

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
#include <stack>
#include <climits>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define rev(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e5 + 5;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildLL(){
	int n;cin>>n;
	ListNode* ans = new ListNode();
	ListNode* res = ans;
	while(n--){
		int x;cin>>x;
		ListNode* temp = new ListNode(x);
		while(ans->next){
			ans = ans->next;	
		}
		ans->next = temp;
	}
	return res->next;
}

void print(ListNode* head){
	while(head){
		cout<<head->val<<" ";
		head = head->next;
	}
}
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* ans = new ListNode();
    	ListNode* dummy = ans;
    	int carry = 0;
    	while(l1 && l2){
    		int num  = l1->val + l2->val + carry;
    		carry = num/10;
    		int base = num%10;
    		dummy->next = new ListNode(base);	
  
    		l1 = l1->next;
    		l2 = l2->next;
    		dummy = dummy->next;
    	}
    	while(l1){
    		int num = l1->val + carry;
    		carry = num/10;
    		int base = num%10;
    		dummy->next = new ListNode(base);
    		
    		l1 = l1->next;
    		dummy = dummy->next;
    	}
    	while(l2){
    		int num = l2->val + carry;
    		carry = num/10;
    		int base = num%10;
    		dummy->next = new ListNode(base);
    		
    		l2 = l2->next;
    		dummy = dummy->next;
    	}
    	if(carry > 0){
    		dummy->next = new ListNode(carry);
    		dummy = dummy->next;
    	}
    	return ans->next;
    }
};

void solve() {
	
	ListNode* l1 = buildLL();	
	ListNode* l2 = buildLL();
	
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

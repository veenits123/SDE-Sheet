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


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//     	bubbleSort(head);
//         return head;
//     }
//     void bubbleSort(ListNode* head){
//     	 for(ListNode* i=head;i!=nullptr;i=i->next){
//         	for(ListNode* j = i->next; j!=nullptr; j=j->next){
//         		if(i->val > j->val){
//         			int temp = i->val;
//         			i->val = j->val;
//         			j->val = temp;
//         		}
//         	}
//         }
//     }
// };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next)
    		return head;
    	return mergeSort(head);
    }
    ListNode* mergeSort(ListNode* &head){
    	if(!head || !head->next)
    		return head;
    	ListNode* mid = middleNode(head);
    	ListNode* left = mergeSort(head);
    	ListNode* right = mergeSort(mid);
    	ListNode* ans = merge(left, right);
    	return ans;	
    }
    
    ListNode* middleNode(ListNode* &head){
		ListNode* slow=head;
		ListNode* fast=head->next;
		while(fast && fast->next){
			slow=slow->next;
			fast=fast->next->next;
		}
		ListNode* ans = slow->next;
		slow->next=nullptr; // dividing ll in two parts;
		return ans;
	}
    
    ListNode* merge(ListNode* &a, ListNode* &b){
    	ListNode* ans = new ListNode();
    	ListNode* dummy = ans;
    	while(a && b){
    		if(a->val < b->val){
    			dummy->next = a;
    			a=a->next;
    		}
    		else{
    			dummy->next = b;
    			b=b->next;
    		}
    		dummy=dummy->next;
    	}
    	if(a)
    		dummy->next=a;
    	else
    	    dummy->next=b;
    	return ans->next;
    }
};

void solve() {

	ListNode* head = buildLL();

	print(head);

	cout<<endl;

	ListNode* ans = Solution().sortList(head);

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

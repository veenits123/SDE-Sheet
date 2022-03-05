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


//Definition for a binary tree node.
struct Node{
	int data;
	Node *left, *right;
	Node(int _d){
		data = _d;
	}
};

// 1 2 -1 -1 4 5 -1 3 -1 -1 -1
Node* build_btree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	Node *cur = new Node(x);
	// build left subtree
	cur->left = build_btree();
	// build right subtree
	cur->right = build_btree();
	return cur;
}

void preOrder(Node *root) {
	if (!root)
		return ;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root) {
	if (!root)
		return ;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(Node *root) {
	if (!root)
		return ;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

Node *helper(int post[], int &index, int min, int max){
	if(index < 0)
		return nullptr;
	
	int cur = post[index];
	if(cur < min || cur > max)
		return nullptr;
	Node* root = new Node(cur);
	index--;
	
	root->right = helper(post, index, cur, max);
	root->left = helper(post, index, min, cur);
	
	return root;	
}

Node *constructTree (int post[], int size){
	//code here	
	int index = size -1;
	return helper(post, index, INT_MIN, INT_MAX);
}

void solve() {
	
	int n;cin>>n;
	int arr[n];
	rep(i, 0, n-1) cin>>arr[i];
	
	auto ans = constructTree(arr, n);
	
	inOrder(ans);

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

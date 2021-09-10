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

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1 2 -1 -1 4 5 -1 3 -1 -1 -1
TreeNode* build_btree() {
	int x;
	cin >> x;
	if (x == -1) {
		return NULL;
	}
	TreeNode *cur = new TreeNode(x);
	// build left subtree
	cur->left = build_btree();
	// build right subtree
	cur->right = build_btree();
	return cur;
}

void preOrder(TreeNode *root) {
	if (!root)
		return ;
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode *root) {
	if (!root)
		return ;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

void postOrder(TreeNode *root) {
	if (!root)
		return ;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}

//sc: O(1), tc: O(n^2);
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if(root==NULL)
			return true;
		if(root->left!=NULL && maxValue(root->left)>=root->val)
			return false;
		if(root->right!=NULL && minValue(root->right)<=root->val)
			return false;
		if(isValidBST(root->left)==false || isValidBST(root->right)==false)
			return false;
		return true;
	}
	int minValue(TreeNode* root){
		if(root==nullptr)
			return INT_MAX;
		int ans=min(root->val,min(minValue(root->left),minValue(root->right)));
		return ans;
	}
	int maxValue(TreeNode* root){
		if(root==nullptr)
			return INT_MIN;
		int ans=max(root->val,max(maxValue(root->left),maxValue(root->right)));
		return ans;
	}
};

//sc: O(n), tc: O(n);
// class Solution {
// public:
// 	bool isValidBST(TreeNode* root) {
// 		if (!root)
// 			return true;
// 		vector<int> in;
// 		inorder(root,in);
// 		for(int i=0;i<in.size()-1;i++){
// 			if(in[i]>=in[i+1])
// 				return false;
// 		}
// 		return true;
// 	}
// 	void inorder(TreeNode* root,vector<int>& in){
// 		if(root==NULL)
// 			return ;
// 		inorder(root->left,in);
// 		in.push_back(root->val);
// 		inorder(root->right,in);
// 	}
// };

#if 0
//sc: O(1), tc: O(n);
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* prev=nullptr;
		return isBST(root,prev);
	}
	bool isBST(TreeNode* root,TreeNode* &prev){
		if(!root)
			return true;

		if(!isBST(root->left,prev))
			return false;

		if(prev && prev->val>=root->val)
			return false;

		prev=root;

		return isBST(root->right,prev);	
	}
};
#endif

void solve() {

	TreeNode* root = build_btree();

	cout << Solution().maxValue(root) << endl;
	//preOrder(root);

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

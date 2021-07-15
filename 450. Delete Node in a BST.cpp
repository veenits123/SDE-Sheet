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

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key) {
		return helper(root, key);
	}
	TreeNode* helper(TreeNode* root, int key) {
		if (!root)
			return nullptr;
		if (root->val > key)
			root->left = helper(root->left, key);
		else if (root->val < key)
			root->right = helper(root->right, key);
		else {//root itself ;)
			if (!root->left && !root->right)
				return nullptr;
			else if (root->left && !root->right)
				return root->left;
			else if (!root->left && root->right)
				return root->right;
			else {
				auto leftSubTree = root->left;
				auto rightSubTree = root->right;

				//both may gives diifferent tree;

				// auto temp = leftSubTree;
				// while (temp->right) {
				// 	temp = temp->right;
				// }
				// temp->right = rightSubTree;
				// return leftSubTree;

				auto temp = rightSubTree;
				while (temp->left) {
					temp = temp->left;
				}
				temp->left = leftSubTree;
				return rightSubTree;
			}
		}
		return root;
	}
};

int height(TreeNode* root) {
	if (!root)
		return 0;
	return max(height(root->left), height(root->right)) + 1;
}

void solve() {

	TreeNode* root = build_btree();

	root = Solution().deleteNode(root, 5);

	cout << height(root) << endl;

	preOrder(root);

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

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	int i=0;
    	return helper(preorder, i, INT_MAX);
    }
    TreeNode* helper(vector<int> &preorder, int &index, int maxVal){
    	if(index >= preorder.size() || preorder[index] > maxVal)
    		return nullptr;
    	
    	int curVal = preorder[index++];
    	TreeNode* root = new TreeNode(curVal);
    	
    	root->left = helper(preorder, index, curVal);
    	root->right = helper(preorder, index, maxVal);
    	
    	return root;
    }
};


// insert method ;)
// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//     	int n = preorder.size();
//     	if(n==0)
//     		return NULL;
//         TreeNode* root = new TreeNode(preorder[0]);
//         for(int i=1; i<n; i++)
//         	root = insert(root, preorder[i]);
//         return root;      	
//     }
//     TreeNode* insert(TreeNode* &root, int x){
//     	if(!root)
//     		return new TreeNode(x);
//     	if(root->val > x)
//     		root->left = insert(root->left, x);
//     	else
//     		root->right = insert(root->right, x);
//     	return root;
//     }
// };

void solve() {
	
	int n;cin>>n;
	vector<int> pre(n);
	for(int i=0;i<n;i++)
		cin>>pre[i];
	
	auto ans = Solution().bstFromPreorder(pre);
	
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

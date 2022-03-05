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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        map<string,int> mp;
        serialize(root, mp);
        string serializedSubRoot = serialize(subRoot);

        if(mp[serializedSubRoot])
        	return true;
        return false;
    }
    string serialize(TreeNode* root, map<string,int>& treeMap){
    	if(!root)
    		return "";
    	string leftSubtree = serialize(root->left, treeMap);
    	string rightSubtree = serialize(root->right, treeMap);

    	string curSubtree = "(" + leftSubtree + to_string(root->val) + rightSubtree + ")";

    	treeMap[curSubtree]++;

    	return curSubtree;
    }
    string serialize(TreeNode* root){
		if(!root)
			return "";
		string leftSubtree = serialize(root->left);
		string rightSubtree = serialize(root->right);

		string curSubtree = "(" + leftSubtree + to_string(root->val) + rightSubtree + ")";

		return curSubtree;
	}
};

void solve() {

	TreeNode* root = build_btree();
	TreeNode* subRoot = build_btree();

	cout<<Solution().isSubtree(root, subRoot);

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

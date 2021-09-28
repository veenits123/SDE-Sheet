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

#if 0
//bfs;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
    	if(!root)
    		return -1;
    	queue<TreeNode*> q;
    	q.push(root);
    	int ans=-1;
    	while(!q.empty()){
    		int n=q.size();
    		ans=q.front()->val;
    		while(n--){
    			TreeNode* cur=q.front();
    			q.pop();
    			if(cur->left)
    				q.push(cur->left);
    			if(cur->right)
    				q.push(cur->right);
    		}
    	}
    	return ans; 
    }
};
#endif

//dfs;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
    	int maxmDepth=0;
    	int ans;
    	dfs(root,1,ans,maxmDepth);
    	return ans;
    }
    void dfs(TreeNode* root,int level,int &ans,int &maxmDepth){
    	if(!root)
    		return ;
    	if(level>maxmDepth){
    		maxmDepth=level;
    		ans=root->val;
    	}
    	dfs(root->left,level+1,ans,maxmDepth);
    	dfs(root->right,level+1,ans,maxmDepth);
    }
};

void solve() {

	auto root=build_btree();

	cout<<Solution().findBottomLeftValue(root);

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

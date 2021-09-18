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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    	map<TreeNode*,TreeNode*> parent;
    	findParent(root,parent);

    	map<TreeNode*,bool> visited;

    	queue<TreeNode*> q;
    	q.push(target);
    	int curLevel=0;

    	visited[target]=true;

    	while(!q.empty()){	
    		if(curLevel==k)
    			break;
    		curLevel++;

    		int n=q.size();
    		while(n--){
    			TreeNode* cur=q.front();
    			q.pop();
    			if(cur->left && !visited[cur->left]){
    				q.push(cur->left);
    				visited[cur->left]=true;
    			}
    			if(cur->right && !visited[cur->right]){
    				q.push(cur->right);
    				visited[cur->right]=true;
    			}

    			if(parent[cur] && !visited[parent[cur]]){
    				q.push(parent[cur]);
    				visited[parent[cur]]=true;
    			}
    		}
    	}
    	vector<int> ans;
    	while(!q.empty()){
    		ans.push_back(q.front()->val);
    		q.pop();
    	}
    	return ans; 
    }
    void findParent(TreeNode* root,map<TreeNode*,TreeNode*>& parent){
    	if(root==nullptr)
    		return ;

    	//dfs;
    	if(root->left)
    		parent[root->left]=root;
    	if(root->right)
    		parent[root->right]=root;
    	findParent(root->left,parent);
    	findParent(root->right,parent);

    	//dfs;
    	// queue<TreeNode*> q;
    	// q.push(root);
    	// while(!q.empty()){
    	// 	TreeNode* cur=q.front();
    	// 	q.pop();
    	// 	if(cur->left){
    	// 		q.push(cur->left);
    	// 		parent[cur->left]=cur;
    	// 	}
    	// 	if(cur->right){
    	// 		q.push(cur->right);
    	// 		parent[cur->right]=cur;
    	// 	}
    	// }
    }
};

void solve() {

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

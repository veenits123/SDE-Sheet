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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int index=0;
       map<int,int> findIndex;
       for(int i=0;i<inorder.size();i++)
       		findIndex[inorder[i]]=i;
       auto ans=constructBT(preorder,inorder,0,preorder.size()-1,index,findIndex);
       return ans;
    }
    TreeNode* constructBT(vector<int>& pre,vector<int>& in,int start,int end,int &index,map<int,int>& findIndex){
    	if(start>end)
    		return nullptr;

    	int cur=pre[index];
    	index++;

    	TreeNode* root=new TreeNode(cur);

    	if(start==end)
    		return root;

    	int posCurNode=-1;
    	if(findIndex.find(cur)!=findIndex.end())
    		posCurNode=findIndex[cur];

    	if(posCurNode!=-1){
    		root->left=constructBT(pre,in,start,posCurNode-1,index,findIndex);
    		root->right=constructBT(pre,in,posCurNode+1,end,index,findIndex);
   		}
    	return root;
    }
};

void solve() {

	vector<int> pre,in;
	int n;cin>>n;
	int x;
	for(int i=0;i<n;i++)
		cin>>x,pre.pb(x);
	for(int i=0;i<n;i++)
		cin>>x,in.pb(x);

	auto ans=Solution().buildTree(pre,in);

	postOrder(ans);

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

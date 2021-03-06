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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	int n=inorder.size();
    	map<int,int> findIndex;
    	for(int i=0;i<inorder.size();i++){
    		findIndex[inorder[i]]=i;
    	}
    	int i=n-1;
        return constructBT(inorder,postorder,0,n-1,i,findIndex);
    }
    TreeNode* constructBT(vector<int>& in,vector<int>& post,int start,int end,int &index,map<int,int>& findIndex){
    	if(start>end)
    		return nullptr;
    	int cur=post[index];
    	index--;

    	TreeNode* root=new TreeNode(cur);

    	if(start==end)
    		return root;

    	int posInOrder=-1;
    	if(findIndex.find(cur)!=findIndex.end())
    		posInOrder=findIndex[cur];

    	if(posInOrder!=-1){
    		//root->right is made first bcz we traverse in reverse order in posorder(left right root) 
    		//so in reverse it should be root>right>left;
    		root->right=constructBT(in,post,posInOrder+1,end,index,findIndex);
    		root->left=constructBT(in,post,start,posInOrder-1,index,findIndex);   		
    	}
    	return root;
    }
};

void solve() {

	vector<int> in,post;
	int n;cin>>n;
	int x;
	REP(i,0,n-1)
	cin>>x,in.pb(x);

	REP(i,0,n-1)
	cin>>x,post.pb(x);

	auto ans=Solution().buildTree(in,post);

	preOrder(ans);

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

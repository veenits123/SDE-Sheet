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
struct Node {
	int data;
	Node *left;
	Node *right;
	Node() : data(0), left(nullptr), right(nullptr) {}
	Node(int x) : data(x), left(nullptr), right(nullptr) {}
	Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
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

class Solution {
public:
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;

        if(root==nullptr)
        	return ans;

        ans.push_back(root->data);

        //left boundary;
        vector<int> leftBoundary;
        leftTraversal(root->left,leftBoundary);
        for(auto x:leftBoundary)
        	ans.push_back(x);

        //leaves;
        vector<int> leftLeafNodes;
        leafNodeTraversal(root,leftLeafNodes);
        for(auto x:leftLeafNodes)
        	ans.push_back(x);

        //right boundary;
        vector<int> rightBoundary;
        rightTraversal(root->right,rightBoundary);
        for(auto x:rightBoundary)
        	ans.push_back(x);

        return ans;
    }

    void leftTraversal(Node* root,vector<int>& leftBoundary){
    	if(root==nullptr)
    		return ;
    	if(root->left || root->right)
    		leftBoundary.push_back(root->data);
    	if(root->left)   		
    		leftTraversal(root->left,leftBoundary);	
    	else if(root->right)
    		leftTraversal(root->right,leftBoundary);
    }

    void leafNodeTraversal(Node* root,vector<int>& leafNodes){
    	if(root==nullptr)
    		return ;
    	leafNodeTraversal(root->left,leafNodes);
    	if(root->left==nullptr && root->right==nullptr)
    		leafNodes.push_back(root->data);
    	leafNodeTraversal(root->right,leafNodes);
    }

    void rightTraversal(Node* root,vector<int>& rightBoundary){
    	if(root==nullptr)
    		return ;	
    	if(root->right)
    		rightTraversal(root->right,rightBoundary);
    	else if(root->left)
    		rightTraversal(root->left,rightBoundary);
    	if(root->left || root->right)
    	rightBoundary.push_back(root->data);
    }
};

void solve() {

	Node* root=build_btree();
	auto ans=Solution().printBoundary(root);
	for(auto x:ans)
		cout<<x<<" ";

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

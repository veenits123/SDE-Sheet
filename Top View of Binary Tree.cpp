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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
    	vector<int> ans;
    	if(!root)
    		return ans;
    	map<int,int> firstVerticalElement;
    	queue<pair<Node*,int>> q;
    	q.push({root,0});
    	while(!q.empty()){
    		Node* cur=q.front().first;
    		int curRow=q.front().second;
    		q.pop();
    		if(!firstVerticalElement[curRow])
    			firstVerticalElement[curRow]=cur->data;
    		if(cur->left)
    			q.push({cur->left,curRow-1});
    		if(cur->right)
    			q.push({cur->right,curRow+1});
    	}
    	for(auto x:firstVerticalElement)
    		ans.push_back(x.second);
    	return ans;
    }

};

void solve() {

	Node* root=build_btree();
	auto ans=Solution().topView(root);

	for(auto x:ans)
		cout<<x<<" ";
	cout<<endl;

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

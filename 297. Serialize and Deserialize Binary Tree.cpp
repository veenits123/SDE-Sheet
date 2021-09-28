// never the same!!
#include "bits/stdc++.h"
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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	string ans="";
    	if(!root)
    		return ans;
    	queue<TreeNode*> q;
    	q.push(root);
    	while(!q.empty()){
    		TreeNode* cur=q.front();
    		q.pop();
    		if(cur==nullptr)
    			ans+="#,";
    		else
    			ans+=to_string(cur->val)+",";
    		if(cur){
    			q.push(cur->left);
    			q.push(cur->right);
    		}
    	}
    	//cout<<ans;
    	return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	int n=data.size();
        if(n==0)
        	return nullptr;

        stringstream s(data);

        string str;
        getline(s, str, ',');

        int val=stoi(str);

        TreeNode* root=new TreeNode(val);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
        	TreeNode* cur=q.front();
        	q.pop();

        	string str;
        	getline(s, str, ',');

        	if(str=="#")
        		cur->left=nullptr;	
        	else{
        		TreeNode* leftNode=new TreeNode(stoi(str));
        		cur->left=leftNode;
        		q.push(leftNode);
        	}
        	//string str;
        	getline(s, str, ',');

        	if(str=="#")
        		cur->right=nullptr;
        	else{
        		TreeNode* rightNode=new TreeNode(stoi(str));
        		cur->right=rightNode;
        		q.push(rightNode);
        	}
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

void solve() {

	auto root=build_btree();

	Codec ser, deser;
	TreeNode* ans = deser.deserialize(ser.serialize(root));

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

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

class Solution {
public:
    string alpha = "abcdefghijklmnopqrstuvwxyz";

    vector <string> numDecodings(string s) {
        vector <string> ans;
        generateStringToo(s, 0, "", ans);
        return ans;
    }

    void generateStringToo(string& str, int pos, string currStr, vector<string>& ans) {
        if (pos >= str.size()) {
            ans.push_back(currStr);
            return;
        }
        for (int i = 1; i <= 2; ++i) {
            if (pos + i > str.size()) break;

            string substr(str.begin() + pos, str.begin() + pos + i);

            int num = stoi(substr);

            if ((num == 0) || (num > 26)) break;

            generateStringToo(str, pos + i, currStr + alpha[num - 1], ans);
        }
    }
};

void solve() {

    string s; cin >> s;
    auto ans = Solution().numDecodings(s);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;

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
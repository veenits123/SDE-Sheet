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

// bool comp(pair<P, int> a, pair<P, int> b) {
//     if (a.F.S != b.F.S)
//         return (a.F.S < b.F.S);
//     else
//         return (a.S < b.S);
//     return false;
// }

class Solution {
public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n) {
        // Your code here
        vector <pair<P, int>> data;
        REP(i, 0, n - 1) {
            data.pb({{start[i], end[i]}, i});
        }
        sort(data.begin(), data.end(), comp);

        // for (auto x : data)
        //     cout << x.F.F << " " << x.F.S << " " << x.S << endl;

        int ans = 1;
        int prev = data[0].F.S;
        REP(i, 1, n - 1) {
            int cur = data[i].F.F;
            if (cur > prev) {
                ans++;
                prev = data[i].F.S;
            }
        }
        return ans;
    }
    static bool comp(pair<P, int> a, pair<P, int> b) {
        if (a.F.S != b.F.S)
            return (a.F.S < b.F.S);
        else
            return (a.S < b.S);
        return false;
    }
};

void solve() {

    int n; cin >> n;
    int s[n], e[n];
    REP(i, 0, n - 1) cin >> s[i];
    REP(i, 0, n - 1) cin >> e[i];

    cout << Solution().maxMeetings(s, e, n) << endl;

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
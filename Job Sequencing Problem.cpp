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

struct Job {
    int id;  // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution {
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // your code here
        sort(arr, arr + n, comp);

        int max_size = 0;
        REP(i, 0, n - 1) {
            max_size = max(max_size, arr[i].dead);
        }
        int map[max_size + 1];
        memset(map, -1, sizeof(map));

        int ans = 0;
        int cnt = 0;
        REP(i, 0, n - 1) {
            int index = arr[i].id;
            int deadline = arr[i].dead;
            int p = arr[i].profit;

            REV(j, deadline, 1) {
                if (map[j] == -1) {
                    map[j] = index;
                    ans += p;
                    cnt++;
                    break;
                }
            }
        }
        vector <int> res;
        res.push_back(ans);
        res.push_back(cnt);
        return res;
    }
    static bool comp(Job a, Job b) {
        return a.profit > b.profit;
    }
};

void solve() {

    int n; cin >> n;
    Job a[n];

    REP(x, 0, n - 1) {
        int i, d, p; cin >> i >> d >> p;
        a[x].id = i;
        a[x].dead = d;
        a[x].profit = p;
    }

    auto ans = Solution().JobScheduling(a, n);

    cout << ans[0] << " " << ans[1] << endl;

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
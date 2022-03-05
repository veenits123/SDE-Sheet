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

vector<int> parent(N,-1);
vector<bool> MST(N,false);
vector<int> dis(N,INT_MAX);

void Prims(){
    priority_queue<P,vector<P>,greater<P>> q;
    q.push({0,0});
    parent[0]=-1;
    dis[0]=0;
    while(!q.empty()){
        int u=q.top().S;
        q.pop();
        MST[u]=true;

        for(auto to:graph[u]){
            int cost=to.S;
            int v=to.F;

            if(MST[v]==false && cost<dis[v]){
                dis[v]=cost;
                q.push({dis[v],v});
                parent[v]=u;
            }
        }
    }
}

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

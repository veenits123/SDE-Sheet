/**
 * तस्मात्सर्वेषु कालेषु मामनुस्मर युध्य च ।
 * मय्यर्पितमनोबुद्धिर्मामेवैष्यस्यसंशय: ॥
 * 
 * Hare Kṛṣṇa Hare Kṛṣṇa
 * Kṛṣṇa Kṛṣṇa Hare Hare
 * Hare Rāma Hare Rāma
 * Rāma Rāma Hare Hare
**/

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

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define rev(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e5 + 5;

void merge(vi &arr, vi &temp, int start, int mid, int end){
	int left = start, right = mid + 1;
	int i = start;
	
	while(left <= mid && right<=end){
		if(arr[left] <= arr[right]){
			temp[i] = arr[left];
			i++;
			left++;
		}
		else{
			temp[i] = arr[right];
			right++;
			i++;
		}
	}
	while(left <= mid){
		temp[i] = arr[left];
		left++;
		i++;
	}
	while(right <= end){
		temp[i] = arr[right];
		right++;
		i++;
	}
	rep(i, start, end)
		arr[i] = temp[i];
}

void merge_sort(vi &arr, vi &temp, int start, int end){
	if(start >= end)
		return ;
	int mid = start + (end - start)/2;
	merge_sort(arr, temp, start, mid);
	merge_sort(arr, temp, mid + 1, end);
	merge(arr, temp, start, mid, end);
}

void mergeSort(vi &arr){
	vi temp(arr.size());
	merge_sort(arr, temp, 0, arr.size() - 1);
}

void solve() {
	
	int n;cin>>n;
	vi arr(n);
	rep(i,0,n-1) cin>>arr[i];
	
	mergeSort(arr);
	
	rep(i,0,n-1)
	cout<<arr[i]<<" ";
	
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

	int t;cin>>t;while(t--)
	solve();

	return 0;
}

/*https://codeforces.com/contest/2057/problem/A*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        if(m >= n) {cout << m + 1 << endl;}
        else cout << n + 1 << endl;
    }
    return 0;
}
/*
n行m列的表格 
排列 0 ~ n * m-1
要求行和列上的 MEX 的和最大
MEX 是该行/列上的没出现的最小非负整数
Input: 
t cases
n m (1e9)
Output: 
sum of mex
*/
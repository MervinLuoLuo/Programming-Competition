/*https://codeforces.com/contest/2056/problem/0*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        vector<int> x(n), y(n);
        for(int i  = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        int sum = 4 * m;
        if(n == 1) {
            cout << sum << endl;
            continue;
        }
        for(int i  = 1; i < n; i++){
            sum += (x[i] + y[i]) * 2;
        }
        cout << sum << endl;
    }
    return 0;
}
/*
m * m 的正方形
初始时与纸张左下角对齐
给定两个长度为 n 的
开始的不算
Input: 
n 操作数 m 正方形边长
x[i] y[i] 邮票的移动
Output: 
图形周长
*/
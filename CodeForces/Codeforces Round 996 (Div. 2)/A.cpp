/*https://codeforces.com/contest/2055/problem/0*/
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
        int n, a, b;cin >>n >>  a>> b;
        if(abs(a- b) % 2 == 0) yes;
        else no;
    }
    return 0;
}
/*
A B 跳蛙
路程长度为 n
A 从 a 开始
B 从 b 开始
A 先手 轮流跳
可以往左跳或者往右跳一格
一定要跳
不能同时在一个位置
如果这个回合 A/B 无法合法的移动测输
问 A 能赢吗
Input:
n a b
Output: 
yes or no
*/
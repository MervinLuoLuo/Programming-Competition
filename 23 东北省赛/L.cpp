#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e17;
const int maxn = 1e7;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0;
}
/*
从 "()" 开始可以有两种操作
1. ()()
2. 取一个区间[l, r] 
   要求这个括号内的 '(' 和 ')' 数量相等
    在这个合法括号外再加一层括号
    e.g. (())
给定一个串 A 
问最少几次操作能使得()变成A
Input:
串A
Output: 
操作数 %998244353

*/
/**/
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
        int l, r;cin >> l >> r;
         int a = 0, b = 0, c = 0;
         for(int i = 29; i  >= 0; i--){
            if((l ^ r) >> i & 1){
                b |= 1 << i;
                a |= ( 1 << i) - 1;
            }
            else{
                a |= l & (1 << i);
                b |= l &(1 << i);
            }
         }
         c = l;
         while( c == a || c == b) c++;
         cout << a << ' '<<b << ' ' <<c << endl;
    }
    return 0;
}
/*
给定 l r 
从 [l,r] 中找出三个数字 a b c 使得运算值最大
Input: 
l r
Output 
a b c
转化为二进制后同位上数字不同的最多
*/
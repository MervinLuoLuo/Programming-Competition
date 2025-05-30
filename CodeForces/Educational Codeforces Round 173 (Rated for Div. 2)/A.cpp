/*https://codeforces.com/contests/2043/problem/A*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n;cin >> n;
        if(n < 4) {cout << 1 << endl;continue;}
        int cnt = 0,layer = 1;
        while(n > 3){
            n /= 4;
            layer++;
            cnt++;
        }
        cnt = pow(2,cnt);
        cout << cnt << endl;
    }
    return 0;
}
/*
价值为 n 的硬币
进行 m 次操作:
    把硬币换成两枚价值 x / 4硬币 x > 3
多次操作后有多少得到枚硬币
Input: 
t cases
n
Output: 
cnt
*/
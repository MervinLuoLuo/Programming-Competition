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
        vector<int> a(n + 5), b(n + 5);
        for(int i = 0 ; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < n; i++){
            cin >> b[i];
        }
        int m = a[n -1] , s = 0;
        if(n == 1){cout << a[0] << endl;continue;}
        for(int i = 0; i < n - 1; i++){
            if(a[i] > b[i + 1]){m += a[i];s +=b[i + 1];}
        }
        cout << m - s << endl;
    }
    return 0;
}
/*
n天
第 i 天练习: M 会解决 a[i] 个问题 S会解决b[i]个问题
M 在第 i 天练 则 S 在第 i+1 天练
M 可以选任意某天练习 且不限次数
求 M 解决的问题数 m 和 S解决的问题数 s 的差的最大值
Input:
t cases
n
a[i]
b[i]
Output: 
max(m - s)

Idea: 
最后一天必选
如果a[i] > b[i + 1] 选
如果没有就直接输出最后一天
*/
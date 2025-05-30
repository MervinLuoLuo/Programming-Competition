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
        int n, a , b ,c;cin >> n >> a >> b >> c;
        int cy = a + b + c;
        int h = n / cy, moved = cy * h;
        int res = n - moved, day = 3 * h;
        if(res > 0){res -=a; day++;}
        if(res > 0){res -=b; day++;}
        if(res > 0){res -=c; day++;}
        cout << day << endl;
    }
    return 0;
}
/*
第一天走 a km 第二天走 b km 
第三天走 c km 第四天走 a km
往下循环
至少走 n km后完成
求第几天完成
Input: 
t cases
n a b c
Output: 
天数
Idea: 

*/
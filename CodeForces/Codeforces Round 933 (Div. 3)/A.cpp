#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e17;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >>t;
    while(t--){
        int n, m , k;cin >> n >> m >> k;
        vector<int> l(n);
        vector<int> r(m);
        for(int i = 0 ; i <n; i++){
            cin >> l[i];
        }
        for(int i = 0; i < m; i++){
            cin >> r[i];
        }
        sort(l.begin(),l.end());
        sort(r.begin(),r.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(l[i] + r[j] <= k) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
一次得投两个硬币 面额总数不能超过 k
左口袋 n 个面额为 b[i] 的币
右口袋 m 个面额为 c[i] 的币
他想从左口袋拿一个币 右口袋拿一个币
求 b[f] + c[s] <= k 可以有几种选择
Input: 
t cases
n m k 1 <= n,m <= 100 1 <= k <= 2000
b[i]
c[i]
Output: 
方式数


暴力就完了
*/
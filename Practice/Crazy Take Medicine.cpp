//https://www.luogu.com.cn/problem/P1616
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t, m;
    cin >>  t >> m;
    vector<int> dp(10000005), ti(m + 5), val(m + 5);
    for(int i = 1; i <= m; i++){
        cin >> ti[i] >> val[i];
    } 
    for(int i = 1; i <= m; i ++){
        for(int j = ti[i]; j <= t; j++){
            dp[j] = max(dp[j - ti[i]] + val[i], dp[j]);
        }
    }
    cout << dp[t];
    return 0;
}
/*
我是dp大师()
*/
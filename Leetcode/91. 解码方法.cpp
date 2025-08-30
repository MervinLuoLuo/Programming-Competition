#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
string s;
int sum = 0;
int n;
vector<int> dp;

//暴力递归 TLE
int f1(int x){
    if(x == s.size()) return 1;

    int ans = 0;
    if(s[x] == '0') ans = 0;
    else {
        ans = f1(x + 1);
        if(x + 1 < s.size() && ((s[x] - '0') * 10 + (s[x + 1] - '0')) <= 26) 
            ans += f1(x + 2);
    }

    return ans;
}

//记忆化搜索
int f2(int x){
    if(x == n) return 1;

    if(dp[x] != -1) return dp[x];

    int ans = 0;
    if(s[x] == '0') ans = 0;
    else {
        ans = f2(x + 1);
        if(x + 1 < s.size() && ((s[x] - '0') * 10 + (s[x + 1] - '0')) <= 26)
            ans += f2(x + 2);
    }
    dp[x] = ans;

    return ans;
}

//线性dp

void f3(){
    dp[n] = 1;
    for(int i = n - 1;i >= 0; i--){
        if(s[i] == '0') dp[i] = 0;
        else {
            dp[i] = dp[i + 1];
            if(i + 1 < n && ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26))
                dp[i] += dp[i + 2];
        }
    }
}

void solve(){
    cin >> s;
    // cout << f1(0) << endl;
    n = s.size();
    dp.assign(n + 1,-1);
    // cout << f2(0) << endl;
    f3();
    cout << dp[0] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
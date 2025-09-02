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

void solve(){
    string S;cin >> S;
    int n = S.size();
    vector<int> s(n);
    for(int i = 0; i < n; i++) s[i] = S[i] - 'a';
    vector<int> dp(26,0);
    dp[s[0]] = 1;
    int len = 1;
    for(int i = 1; i < n; i++){
        if((s[i - 1] == 25 && s[i] == 0) || s[i - 1] == s[i] - 1) len++;
        else len = 1;
        dp[s[i]] = max(dp[s[i]],len);
    } 
    int ans = accumulate(dp.begin(),dp.end(),0LL);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
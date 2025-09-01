#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int dp[maxn];
string s;
int n;

//记忆化搜索 36ms
int memserch(int i){
    if(i == n + 1) return 1;
    if(dp[i] != -1) return dp[i];

    int ans;
    if(s[i] == '0') ans = 0;
    else {
        if(s[i] != '0') ans = memserch(i + 1) % MOD;
        if(s[i] == '*') ans = (ans * 9) % MOD;
        if(i < n){
            if(isdigit(s[i]) && isdigit(s[i + 1]) && 
            (s[i] - '0') * 10 + (s[i] - '0') <= 26) ans = (ans + memserch(i + 2)) % MOD; 
            else if(isdigit(s[i]) && s[i + 1] == '*'){
                if(s[i] == '1') ans = (ans + 9 * memserch(i + 2)) % MOD;
                else if(s[i] == '2') ans = (ans + 6 * memserch(i + 2)) % MOD;
            }
            else if(s[i] == '*' && isdigit(s[i + 1])){
                if(s[i + 1] - '0' <= 6) ans = (ans + 2 * memserch(i + 2)) % MOD;
                else ans = (ans + memserch(i + 2)) % MOD;
            }
            else if(s[i] == '*' && s[i + 1] == '*')ans = (ans + memserch(i + 2) * 15) % MOD;
        }
    } 
    dp[i] = ans;
    return ans;
}

//dp
void func(){
    dp[n] = 1;
    for(int i = n - 1;i >= 0; i--){
        if(s[i] != '0'){
            dp[i] = (dp[i + 1] * (s[i] == '*' ? 9 : 1)) % MOD;
            if(i + 1 < n){
                if(isdigit(s[i]) && isdigit(s[i + 1]) && 
                ((s[i] - '0') * 10 + (s[i + 1] - '0') <= 26)) dp[i] = (dp[i] + dp[i + 2] + dp[i]) % MOD;
                else if(isdigit(s[i]) && s[i + 1] == '*'){
                    if(s[i] == '1') dp[i] = (dp[i] + dp[i + 2] * 9) % MOD;
                    else if(s[i] == '2') dp[i] = (dp[i] + dp[i + 2] * 6) % MOD;
                }
                else if(s[i] == '*' && isdigit(s[i + 1])){
                    if(s[i + 1] - '0' <= 6) dp[i] = (dp[i] + dp[i + 2] * 2) % MOD;
                    else dp[i] = dp[i + 2];
                }
                else if(s[i] == '*' && s[i + 1] == '*') dp[i] = (dp[i] + dp[i + 2] * 15) % MOD;
            }
        }
    }
}

void solve(){
    cin >> s;
    n = s.size();
    fill(dp,dp + n + 1, 0);

    // cout << memserch(1);
    func();
    cout << dp[0] << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
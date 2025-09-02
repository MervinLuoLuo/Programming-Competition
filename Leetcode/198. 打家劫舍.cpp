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
const int MOD = 1e9 + 7;
int n;
vector<int> a;
int dp[105];

int func1(int i){
    if(i == 0) return a[0];
    if(i == 1) return max(a[0],a[1]);

    if(dp[i] != -1) return dp[i];

    int ans = max(func1(i - 2) + a[i],func1(i - 1));
    dp[i] = ans;
    return ans;
}

void func2(){
    dp[0] = a[0];
    for(int i = 1; i < n; i++){
        if(i == 1) dp[i] = max(a[0],a[1]);
        else dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
    }
}
void solve(){
    cin >> n;
    a.assign(n,0);
    for(int &x : a) cin >> x;
    fill(dp,dp + n + 1, -1);
    cout << func1(n - 1) << endl;
    // func2();
    // cout << dp[n - 1] << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
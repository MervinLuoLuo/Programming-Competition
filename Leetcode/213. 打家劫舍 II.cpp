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
int n;
vector<int> a;
// vii dp;

// int func(int i){
//     if(i == 0) return a[0];

// }

int dpf(int start,int end){
    int leng = end - start + 1;
    vii dp(leng,vector<int>(2,0));
    dp[0][0] = 0;
    dp[0][1] = a[start];
    for(int i = 1; i < leng; i++){
        dp[i][0] = max(dp[i - 1][0],dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + a[start + i];
    }
    return max(dp[leng - 1][0],dp[leng - 1][1]);
} 

void solve(){
    cin >> n;
    a.assign(n,0);
    for(int &x : a) cin >> x;
    // dp.assign(n + 1,vector<int>(2,0));
    if(n == 1){cout << a[0] << endl;return;}
    cout << max(dpf(0,n - 2),dpf(1, n - 1)) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
// int n,s = 1;
// vector<int> a;
// int ans = -1;

// void dfs(int x,int cur,int cnt){
//     if(x == n){
//         ans = max(ans,cnt);
//         return;
//     }
//     int curr = cur + a[x + 1];
//     int curl = cur - a[x + 1];
//     dfs(x + 1,curr,cnt + ((cur > 0 && curr < 0) || (cur < 0 && curr > 0)));
//     dfs(x + 1,curl,cnt + ((cur < 0 && curl > 0) || (cur > 0 && curl < 0)));
// }

// void solve(){
//     cin >> n;
//     a.assign(n + 1, 0);
//     for(int i = 1; i <= n; i++){
//         int x;cin >> x;
//         a[i] = x * 2;
//     }

//     dfs(0,1,0);

//     cout << ans << endl;
// }

void solve1(){
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    unordered_map<int,int> dp,ndp;
    dp[1] = 0;
    for(int i = 1; i <= n; i++){
        ndp.clear();
        int d = 2 * a[i];
        for(auto [p,cnt] : dp){
            int p1 = p + d,p2 = p - d;
            int cnt1 = cnt + ((p > 0 && p1 < 0) || (p < 0 && p1 > 0));
            int cnt2 = cnt + ((p > 0 && p2 < 0) || (p < 0 && p1 > 0));
            if(ndp.count(p1) == 0 || ndp[p1] < cnt1) ndp[p1] = cnt1;
            if(ndp.count(p2) == 0 || ndp[p2] < cnt2) ndp[p2] = cnt2;
        }
        dp.swap(ndp);
    }
    int ans = 0;
    for(auto [p,cnt] : dp) ans = max(ans,cnt);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve1();
    return 0;
}

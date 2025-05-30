/*https://codeforces.com/contest/1992/problem/D*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m,k;cin >> n >> m >> k;
    string a;cin >> a;
    vector<int> dp(n + 5,INF);
    dp[0] = 0;
    a = 'L' + a + 'L';
    for(int i = 0; i < a.size();i++){
        if(dp[n + 2] != INF) break;
        if(a[i] == 'L'){
            for(int j = 1; j <= m; j++){
                if(i + j > a.size()) continue;
                if(a[i + j] == 'C') continue;
                dp[i + j] = dp[i];
            }
        }
        if(a[i] == 'C') continue;
        else{
            if(i + 1 >= a.size()) continue;
            if(a[i + 1] =='C') continue;
            if(dp[i] >= k) continue;
            dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
        }
    }
    if(dp[n + 2] <= k) yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
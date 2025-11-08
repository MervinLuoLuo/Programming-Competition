#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int MOD = 998244353;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0);
    for(int i =  1; i <= n; i++) cin >> a[i];
    vii ans(n + 1,vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            if(i == j) ans[i][j] = (a[i] + 1) % MOD;
            else ans[i][j] = a[j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << ans[i][j] << " ";
        cout << endl; 
    }
    // cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
/*https://codeforces.com/problemset/problem/2025/A*/
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
    string s,t;cin >> s >> t;
    int n = s.size(), m = t.size();
    int i = 0;
    for(i = 0; i < min(n,m); i++){
        if(s[i] != t[i]) break;
    }
    // cout << i << endl;
    int ans = n + m;
    if(i != 0) ans = ans - i + 1;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
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
    string s;cin >> s;
    int n = s.size();
    vector<int> dp(n + 1,0);
    for(int i = 1; i < n; i++){
        if(s[i] == ')'){
            int pos = i - 1 - dp[i - 1];
            if(pos >= 0 && s[pos] == '(') dp[i] = dp[i - 1] + 2 + (pos > 0 ? dp[pos -1] : 0);
        }
    }
    cout << *max_element(dp.begin(),dp.end());
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
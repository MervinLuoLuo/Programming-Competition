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
    int n;cin >> n;
    vector<int> pre(n + 1),suf(n + 1);
    for(int i =1; i <= n; i++) cin >> pre[i];
    for(int i = 1; i <= n; i++) cin >> suf[i];
    
    vector<int> ans(n + 1);
    for(int i = n; i >= 1; i--) ans[i] = lcm(pre[i],suf[i]);

    if(ans[1] != pre[1] || ans[n] != suf[n]){no;return;} 
    for(int i = 2; i <= n; i++){
        if(gcd(pre[i - 1],ans[i]) != pre[i]){no;return;}
    }
    for(int i = n - 1; i >= 1; i--){
        if(gcd(suf[i + 1],ans[i]) != suf[i]){no;return;}
    }
    
    yes;
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
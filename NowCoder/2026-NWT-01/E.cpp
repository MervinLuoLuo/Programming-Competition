#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> a(n + 2);
    a[1] = k;
    for(int i = 2; i <= n + 1; i++) cin >> a[i];
    
    int ans = a[2] + a[1];
    ans = max(ans,a[1] + a[n + 1]);
    for(int i = 3; i <= n + 1; i++) ans = max(ans,a[i] + a[i - 1]);
    cout << ans << endl; 
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
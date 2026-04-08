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
    vector<int> ans(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 2; j * i <= n; j++){
            ans[i]++;
            ans[j * i]++;
        }
    }
    // for(int i  = 1; i <= n; i++) cout << ans[i] << " ";
    sort(ans.begin() + 1,ans.end(),greater<int>());
    cout << ans[k] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
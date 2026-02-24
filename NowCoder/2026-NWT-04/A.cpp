#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(j == i) continue;
            if(a[j] <= a[i]) cnt++;
        }
        if(cnt * 10 >= (n - 1) * 8) ans += a[i];
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
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
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 1; i < n; i++) sum += abs(a[i] - a[i + 1]);

    int ans = min(sum - abs(a[2] - a[1]), sum - abs(a[n] - a[n - 1]));

    for(int i = 2; i < n; i++){
        ans = min(ans, sum - abs(a[i] - a[i - 1]) - abs(a[i + 1]- a[i]) + abs(a[i + 1] - a[i - 1]));
    }

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
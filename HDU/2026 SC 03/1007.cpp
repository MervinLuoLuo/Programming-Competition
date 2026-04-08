#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<int> a(3 * n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i + n] = a[i],a[i + 2 * n] = a[i];
    vector<int> sum(3 * n + 1 ,0);
    for(int i = 1; i <= 3 * n; i++){
        if(i <= m) sum[i] = a[i];
        else sum[i] = sum[i - m] + a[i];
    }
    int x = n / m;
    if(n % m >= k) x++;
    int ans = -INF;
    for(int i = 1; i <= n; i++){
        int res = sum[m * x + i - 1] - sum[i - 1];
        ans = max(res,ans);
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

/* 交换在: x - k + 1*/
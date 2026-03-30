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
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int w,t;cin >> w >> t;
        int e = k - w + t;
        a[i] = e;
    }
    sort(a.begin() + 1,a.end());
    for(int i = 1; i <= n; i++) a[i] = max(a[i],a[i - 1] + 1);
    cout << a[n] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
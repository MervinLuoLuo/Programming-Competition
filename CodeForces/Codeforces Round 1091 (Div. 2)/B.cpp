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
    vector<int> a(n + 2, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int p;cin >> p;
    a[0] = a[n + 1] = a[p];
    int cntl = 0,cntr = 0;
    for(int i = 0; i < p;i ++){
        if(a[i] != a[i + 1]) cntl++;
    }
    for(int i = p; i < n + 1; i++){
        if(a[i] != a[i + 1]) cntr++;
    }
    cout << max(cntl,cntr) << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*https://qoj.ac/contest/1280/problem/6691*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<PII> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1,a.end());
    // for(auto [x,y] : a) cout << x << " " << y << endl;
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].second;
    // for(int i = 1; i <= n; i++) cerr << pre[i] << " ";
    for(int i = 1; i <= n; i++){
        int sum = a[i].first * k;
        sum -= pre[i - 1];
        if(sum < a[i].second){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
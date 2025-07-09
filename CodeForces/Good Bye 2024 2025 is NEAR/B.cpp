#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<pii> a(n);
    vector<int> flag(2 * n + 5, 0), pre(2 * n + 5, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        if(a[i].first == a[i].second) {flag[a[i].first] = 1;pre[a[i].first]++;}
    }
    
    for(int i = 2; i <= 2 * n; i++) flag[i] += flag[i - 1];
    
    string ans = "";
    for(int i = 0; i < n;i++){
        if(a[i].first == a[i].second && pre[a[i].first] <= 1) ans += '1';
        else if(flag[a[i].second] - flag[a[i].first - 1] < a[i].second - a[i].first + 1) ans += '1';
        else ans += '0';
    }
    cout << ans << endl;
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
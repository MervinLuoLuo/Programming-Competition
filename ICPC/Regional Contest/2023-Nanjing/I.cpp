#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<pii> a(m + 1,{0,0});
    for(int i = 1; i <= m; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1,a.end());

    if(n < m) {no;return;}
    for(int i = 1; i <= m; i++){
        if(a[i].first - a[i - 1].first == a[i].second - a[i - 1].second || a[i].first - a[i - 1].first > a[i].second) continue;
        else {no;return;}
    }
    yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
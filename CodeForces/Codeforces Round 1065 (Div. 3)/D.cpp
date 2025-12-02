#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 0),premin(n + 2, maxn), sufmax(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        premin[i] = min(premin[i - 1], a[i]);
    }

    for(int i = n; i >= 1; i--){
        sufmax[i] = max(sufmax[i + 1], a[i]);
    }

    for(int i = 1; i < n; i++){
        if(premin[i] > sufmax[i + 1]){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
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
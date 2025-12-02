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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int ans = 0;
    if(a[0] != -1 && a[n - 1] != -1) ans = abs(a[n - 1] - a[0]);
    cout << ans << endl;

    if(a[0] == -1 && a[n - 1] == -1) a[0] = a[n - 1] = 0;
    else if(a[0] == -1 && a[n - 1] != -1) a[0] = a[n - 1];
    else if(a[0] != -1 && a[n - 1] == -1) a[n - 1] = a[0];
    cout << a[0] << " ";
    for(int i = 1; i < n - 1; i++){
        if(a[i] == - 1) cout << 0 << " ";
        else cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;
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
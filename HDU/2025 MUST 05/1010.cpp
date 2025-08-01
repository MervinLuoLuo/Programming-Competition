#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    signed n;cin >> n;
    vector<double> p(n + 1);
    for(int i = 1; i <= n; i++){
        signed x;cin >> x;
        p[i] = x / 1000.0;
    }
    vector<double> a(n + 2);
    a[n] = n;
    for(signed i = n - 1; i >= 1; i--){
        double skip = a[i + 1];
        double sub = (1.0 - p[i]) * i + p[i] * (a[i + 1] + 20.0);
        a[i] = min(skip,sub); 
    }
    cout << fixed << setprecision(10) << a[1] << endl;

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
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
    int n;cin >> n;
    vector<int> a(2 * n + 2,0);
    a[1] = n;
    for(int i = 2; i <= n; i++) a[i] = n - i + 1;
    a[n + 1] = n;
    for(int i = n + 2; i <= 2 * n; i++) a[i] = i - n - 1;
    for(int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
    cout << endl;
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
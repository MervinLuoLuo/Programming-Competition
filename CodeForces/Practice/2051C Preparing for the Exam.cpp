/*https://codeforces.com/problemset/problem/2051/C*/
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
    int n,m,k;cin >> n >> m >> k;
    vector<int> a(m),q(k),vis(n + 1, 0);
    for(int &x : a) cin >> x;
    for(int &x : q) cin >> x;
    for(int i : q) vis[i] = 1;
    int l = q.size();
    for(int i = 0; i < m; i++){
        if (l == n || (l == n - 1 && !vis[a[i]])) cout << 1;
        else cout << 0;
    }
    cout << endl;
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
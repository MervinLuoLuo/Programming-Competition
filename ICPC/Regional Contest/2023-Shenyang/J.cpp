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
    if(n == 2) {cout << "Bob" << endl;return;}
    vector<int> deg(n + 1, 0);
    for(int i = 1; i <= n - 1; i++){
        int u,v;cin >> u >> v;
        deg[u]++;deg[v]++;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 1) cnt++;
    }

    int base = (n - 1) & 1;
    if(cnt % 2 == base) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
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
    vector<int> a(n + 1,0),b(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    int pos = 0;
    int ansa = 0,ansb = 0;
    for(int i = 1; i <= n; i++){
        ansa ^= a[i];
        ansb ^= b[i];
        if(a[i] != b[i]) pos = i;
    }

    if(ansa == ansb){cout << "Tie" << endl;return;}

    if(pos & 1) cout << "Ajisai" << endl;
    else cout << "Mai" << endl;
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
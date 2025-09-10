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
    string s;cin >> s;
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0;i < n;i++){
        a[i] = s[i] - '0';
        if(a[i] == 0) cnt++;
    }

    int ans = 0;
    for(int i = 0; i < cnt; i++){
        if(a[i] == 1) ans++;
    }
    cout << ans << endl;
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
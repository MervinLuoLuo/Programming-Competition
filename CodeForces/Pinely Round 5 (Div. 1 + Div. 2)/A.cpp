#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int r,x,d,n;cin >> r >> x >> d >> n;
    string s;cin >> s;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '2' && r >= x) continue;
        ans++;
        r = max(r - d, 0LL);
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
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
    int cnt = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(x >= 1) cnt++,sum += x;
    }

    int sub = n - 1 - (sum - cnt);

    int ans = cnt - max(0LL,sub);
    cout << ans << endl;
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
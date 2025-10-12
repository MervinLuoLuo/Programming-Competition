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

int f(int x){
    int res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve(){
    int n;cin >> n;
    int ans  = 1;
    for(int i = 1 ; i < n; i++){
        ans += f(ans);
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    cout << (1LL << n) - 1 << " ";
    for(int i = 1 ; i <= n; i++){
        int r = 1 << i;
        int cur = 1 << (n - i);
        for(int j = 0; j < r; j += 2){
            int res = j * cur + cur - 1;
            cout << res << " ";
        }
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
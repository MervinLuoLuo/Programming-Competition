/*https://codeforces.com/contest/2222*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    bool flag = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 100) flag = 1;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
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
using ull = unsigned long long;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vii k(11);

    for(int i = 0; i < n; i++){
        int K = to_string(a[i]).size();
        k[K].push_back(a[i] % m);
    }

    for(auto &it : k){
        sort(it.begin(),it.end());
    }

    int ans = 0;

    for(int i = 0 ; i < n; i++){
        for(int kk = 1; kk <= 10; kk++){
            a[i] = (a[i] * 10) % m;
            int need = (m - a[i]) % m;

            ans += lower_bound(k[kk].begin(),k[kk].end(), need + 1) - lower_bound(k[kk].begin(),k[kk].end(),need);
        }
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

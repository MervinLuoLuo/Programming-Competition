#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e6;
vector<int> spf;
vector<char> par;
vector<int> good;

void init() {
    spf.assign(maxn + 1, 0);
    vector<int> prime;
    spf[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (!spf[i]) {
            spf[i] = i;
            prime.push_back(i);
        }
        for (int p : prime) {
            if (p > spf[i] || i * p > maxn) break;
            spf[i * p] = p;
        }
    }
    par.assign(maxn + 1, 0);
    par[1] = 0;
    for (int i = 2; i <= maxn; i++) {
        par[i] = par[i / spf[i]] ^ 1;
    }
    good.reserve(maxn / 2 + 5);
    for (int i = 1; i <= maxn; i++) {
        if (par[i]) good.push_back(i);
    }
}

void solve(){
    int n;
    cin >> n;
    int need = n / 2;
    for(int i = 0; i < need; i++) cout << good[i] << " ";
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}

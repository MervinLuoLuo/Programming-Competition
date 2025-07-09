/*https://codeforces.com/problemset/problem/2049/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x :a) cin >> x;
    while (!a.empty() && a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    while (!a.empty() && a.back() == 0) a.pop_back();
    reverse(a.begin(), a.end());
    if (a.empty()){cout << 0 << endl;return;}
    bool hasZero = 0;
    for (const auto x : a) hasZero |= x == 0;
    if (hasZero) cout << 2 << endl;
    else cout << 1 << endl;
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
/*https://codeforces.com/problemset/problem/2019/B*/
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
    int n,q;cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int,int> mp;
    for(int i = 1; i < n; i++){
        mp[(n - i) + (i - 1) * (n - i + 1)]++;
        if(a[i + 1] - a[i] > 1){
            mp[i *(n - i)] += (a[i + 1] - a[i] - 1);
        }
    }
    mp[n - 1]++;
    while(q--){
        int k;cin >> k;
        cout << mp[k] << " ";
    }
    cout << endl;
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
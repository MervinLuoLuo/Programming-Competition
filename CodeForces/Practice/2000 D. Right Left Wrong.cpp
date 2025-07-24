/*https://codeforces.com/problemset/problem/2000/D*/
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
    vector<int> pre(n + 2,0);
    for(int i = 1;i <= n; i++){
        int x;cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    string s;cin >> s;

    int ans = 0;
    int l = 0, r = n - 1;
    while(r > l){
        while(l < n && s[l] == 'R') l++;
        while(r >= 0 && s[r] == 'L') r--;
        if(l < r){
            ans += pre[r + 1]- pre[l];
            l++;r--;
        }
    }
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

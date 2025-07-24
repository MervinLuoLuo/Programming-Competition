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
    int n,k,c;cin >> n >> k >> c;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 0) {cout << 0 << endl;return;}
    vector<int> v(n);
    for(int i = 1; i <= n; i++){
        v[i-1] = a[i] - c * i;
    }
    nth_element(v.begin(),v.begin() + k,v.end(),greater<int>());
    int sum = 0;
    for(int i = 0; i < k; i++) sum += v[i];
    int ans = sum + (c * k * (k + 1) / 2);
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
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

void solve(){
    int n ,s;cin >> n >> s;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int sum = accumulate(a.begin(),a.end(), 0LL);
    if(sum == s) {cout << -1 << endl;return;}
    if(sum > s) {
        for(auto it : a) cout << it << ' ';
        cout << endl;
        return;
    }
    int d = s - sum;
    if(d != 1){cout << -1 << endl;return;}
    int cnt0 = 0,cnt1 = 0,cnt2 = 0;
    for(int x : a){
        if(x == 1) cnt1++;
        if(x == 0) cnt0++;
        if(x == 2) cnt2++;
    }
    for(int i = 0; i < cnt0 ; i++) cout << 0 << " ";    
    for(int i = 0; i < cnt2 ; i++) cout << 2 << " ";    
    for(int i = 0; i < cnt1 ; i++) cout << 1 << " ";
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
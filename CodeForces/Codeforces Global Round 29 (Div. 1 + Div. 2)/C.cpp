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
    int n;cin >> n;
    string s;cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = s[i] - '0';

    int cnt = 0,stat = (a[0] == 1);
    for(int i = 0; i < n; i++){
        if(a[i] == 0) cnt++;
        if(i == 0) continue;
        if(a[i] == 0 && a[i - 1] == 0) stat = 0;
        if(a[i] == 1 && a[i - 1] == 1){
            if(stat && (cnt & 1)){no;return;}
            stat = 1;
            cnt = 0;
        }
    }

    if(stat && (cnt & 1) && a[n - 1] == 1) no;
    else yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
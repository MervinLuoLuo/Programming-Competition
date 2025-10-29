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
    s = " " + s;
    if(s[1] != s[n]) {cout << "empty" << endl;return;}
    int ans = maxn, last = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] != s[1]){
            ans = min(ans,i - last - 1);
            last = i;
        }
    }
    ans = min(ans,n - last);
    if(ans == 0) cout << "empty" << endl;
    else{
        for(int i = 1; i <= ans; i++) cout << s[1];
        cout << endl;
    }
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
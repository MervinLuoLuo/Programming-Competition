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
    int n,q;cin >> n >> q;
    string s;cin >> s;
    // vector<int> a(n);
    // for(int &x : a) cin >> x;
    int cnta = 0,cntb = 0;
    for(char c : s) {
        if(c == 'A') cnta++;
        else cntb++;
    }

    while(q--){
        int x;cin >> x;
        if(cntb == 0) cout << x << endl;
        else{
            int ans = 0;
            while(x){
                for(int j = 0; j < n; j++){
                    if(x == 0) break;
                    ans++;
                    if(s[j] == 'A') x--;
                    else x /= 2;
                }
            }
            cout << ans << endl;
        }
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
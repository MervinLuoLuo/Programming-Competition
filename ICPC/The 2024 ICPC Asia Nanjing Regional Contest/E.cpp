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
    int n,k;cin >> n >> k;
    string s;cin >> s;
    string base = "nanjing";

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'n'){
            string cur = s.substr(i,7);
            if(cur == base) ans++;
            if(cur.size() < 7){
                int need = 7 - cur.size();
                string l = s.substr(0,need);
                cur = cur + l;
                if(cur == base && need <= k) ans++;
            } 
        }
    }
    cout << ans << endl;
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
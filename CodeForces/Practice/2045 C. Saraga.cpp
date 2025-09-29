/*https://codeforces.com/problemset/problem/2045/C*/
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
    string s,t;cin >> s >> t;
    int n = s.size(),m = t.size();
    int best = maxn;
    string ans = "";

    for(char c  = 'a'; c <= 'z'; c++){
        int prelen = maxn;
        for(int i = 1; i < n; i++){
            if(s[i] == c){prelen = i + 1;break;}
        }

        int suflen = maxn;
        for(int i = m  - 2;i >= 0; i--){
            if(t[i] == c){suflen = m - i;break;}
        }
        
        if(prelen != maxn && suflen != maxn){
            int tot = prelen + suflen - 1;
            if(tot < best){
                best = tot;
                string pre = s.substr(0,prelen);
                string suf = t.substr(m - suflen);
                ans = pre + suf.substr(1);
            }
        }
    }

    if(best == maxn) cout << -1 << endl;
    else cout << ans << endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
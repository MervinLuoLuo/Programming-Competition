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
    int n,m;cin >> n >> m;
    string s,t;cin >> s >> t;
    int N = n - m + 1;
    vector<int> S(n),T(m);
    for(int i = 0; i < n; i++) S[i] = s[i] - '0';
    for(int i = 0; i < m; i++) T[i] = t[i] - '0';
    int pos = -1;
    for(int i = 0; i < m; i++){
        if(T[i]){pos = i;break;}
    }
    if(pos == -1){
        for(int i = 0; i < n; i++){
            if(S[i]){cout << -1 << endl;return;}
        }
        cout << 0 << endl;
        return;
    }
    int w = m - pos;
    int len = max(0LL,w - 1);
    int mask = (len ? ((1LL << len) - 1LL) : 0LL);
    int sub = 0;
    for(int b = 0;b < len;b++){
        if(T[pos + 1 + b]) sub |= (1LL << b);
    }
    int last = 0;
    int ans = 0;
    bool flag = 1;
    for(int i  =0; i < n; i++){
        int known = __builtin_popcountll(last & sub) & 1;
        int idx = i - pos;
        if(0 <= idx && idx <= N - 1){
            int xi = S[i] ^ known;
            ans += xi;
            if(len) last = (((last << 1) | xi) & mask);
            else last = 0;
        }
        else{
            if((S[i] ^ known) != 0) {flag = 0;break;}
            if(len) last = ((last << 1) & mask);
            else last = 0;
        }
    }
    if(flag) cout << ans << endl;
    else cout << -1 << endl;
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
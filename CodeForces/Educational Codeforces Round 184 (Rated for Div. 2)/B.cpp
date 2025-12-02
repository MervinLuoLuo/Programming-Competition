#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> prel(n + 2, 0),prer(n + 2, 0);
    vector<int> sufl(n + 2, 0),sufr(n + 2, 0);

    bool flag = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] != '*'){
            flag = 1;break;
        }
    }

    if(!flag){
        if(n != 1) cout << -1 << endl;
        else cout << 1 << endl;
        return;
    }

    for(int i = 1; i <= n; i++){
        prer[i] = prer[i - 1] + (s[i] == '>');
        prel[i] = prel[i - 1] + (s[i] == '<');
    }

    for(int i = n; i >= 1; i--){
        sufr[i] = sufr[i + 1] + (s[i] == '>');
        sufl[i] = sufl[i + 1] + (s[i] == '<');
    }

    int maxl = 0,maxr = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(prer[i] != 0 && sufl[i] != 0){cout << -1 << endl;return;}
        if(s[i] == '*'){
            if(prer[i] != 0 || sufl[i] != 0){cout << -1 << endl;return;}
            else if(s[i + 1] == '*' || s[i - 1] == '*' ){cout << -1 << endl;return;}
            else ans++;
        }
        maxl = max(maxl, prel[i]);
        maxr = max(maxr, sufr[i]);
    }

    ans += max(maxl,maxr);
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
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<int,int>
#define PII pair<int,int>
// #define DBG
#ifdef DDEBUG
    #define dbg(x) cerr << #x << ": " << x << endl;
#else
    #define dbg(x)
#endif
using namespace std;

void solve(){
    string s;cin >> s;
    string sa = s,sb = s;
    sa[0] = 'W',sb[0] = 'B';
    int n = s.size();
    for(int i = 1; i < n; i++){
        if(sa[i - 1] == 'W') sa[i] = 'B';
        else sa[i] = 'W';

        if(sb[i - 1] == 'W') sb[i] = 'B';
        else sb[i] = 'W';
    }

    int l = 0,r = n - 1;
    while(l < n && s[l] == sa[l]) l++;
    if(l == n){
        cout << 0 << endl;
        return;
    }

    while(r >= 0 && s[r] == sa[r]) r--;
    int ans = r - l + 1;

    l = 0,r = n - 1;
    while(l < n && s[l] == sb[l]) l++;
    if(l == n){
        cout << 0 << endl;
        return;
    }

    while(r >= 0 && s[r] == sb[r]) r--;
    ans = min(ans, r - l + 1);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
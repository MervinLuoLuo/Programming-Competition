#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<int,int>
#define PII pair<int,int>
// #define DBG
#ifdef DBG
    #define dbg(x) cerr << #x << ": " << x << endl;
#else
    #define dbg(x)
#endif
using namespace std;

void solve(){
    int d,t;cin >> d >> t;
    int T = (t + d) % 24;

    if((T >= 18 || T <= 5) && t >= 6 && t < 18){
        cout << 0 << endl;
        return;
    }
    dbg(T);
    int ans = -1;
    for(int i = T; i < 48; i++){
        int tmp = (i - d + 24) % 24;
        int cur = i % 24;
        dbg(tmp);dbg(cur);
        if((cur >= 18 || cur <= 5) && tmp >= 6 && tmp < 18){
            ans = i - T;
            break;
        }
    }

    cout << ans << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
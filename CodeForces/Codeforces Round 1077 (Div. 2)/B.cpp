#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int ans = 0;
    vector<int> pos;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') {
            ans++;
            pos.push_back(i);
        }
    }

    if(pos.empty()){
        cout << (n + 2) / 3 << endl;
        return;
    }

    // 前缀
    int cnt = pos[0];
    if(cnt > 1) ans += (cnt + 1) / 3;

    //中间
    for(int i = 1; i < pos.size(); i++){
        cnt = pos[i] - pos[i - 1] - 1;
        if(cnt > 2) ans += cnt / 3;
    }

    // 后缀
    cnt = n - 1 - pos.back();
    if(cnt > 1) ans += (cnt + 1) / 3;

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
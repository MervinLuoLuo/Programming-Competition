#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int calc(string s){
    int maxx = 0,minx = 0,cur = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') cur++;
        else cur--;
        if(cur < 0) cur = 0;
        maxx = max(maxx,cur);
    }
    cur = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1') cur++;
        else cur--;
        if(cur > 0) cur = 0;
        minx = min(minx,cur);
    }

    int res = max(maxx,abs(minx));
    return res;
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    string ss = "";
    for(int i = 0; i < n; i++){
        if((i % 2 == 1) && s[i] == '1') ss += s[i];
        else if((i % 2 == 0) && s[i] == '0') ss += s[i];
    }
    int ans = calc(ss);
    ss = "";
        for(int i = 0; i < n; i++){
        if((i % 2 == 0) && s[i] == '1') ss += s[i];
        else if((i % 2 == 1) && s[i] == '0') ss += s[i];
    }
    ans = min(ans ,calc(ss));

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
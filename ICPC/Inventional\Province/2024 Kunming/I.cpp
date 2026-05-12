#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();

    vector<PII> res;
    char pre = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != pre){
            res.push_back({pre,cnt});
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.push_back({pre,cnt});

    if(res.size() == 1){
        cout << res[0].second / 2 << endl;
        return;
    }
    
    if(res[0].first == res.back().first){
        res[0].second += res.back().second;
        res.pop_back();
    }

    int ans = 0;
    int flag = 0;
    for(auto &[ch,count] : res){
        ans += count / 2;
        if(count % 2 == 0) flag = 1;
    }

    cout << ans - flag << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
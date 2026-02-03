#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int l,r;cin >> l >> r;
    int ans = 0;
    for(int i = l; i <= r; i++){
        string s = to_string(i);
        reverse(s.begin(),s.end());
        int p = 0;
        while(p < s.size() && s[p] == '0') p++;
        string str = s.substr(p,(int)s.size());
        int res = stoll(str);
        ans = max(ans,res);
    }

    cout << ans << endl;
    // 113999
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
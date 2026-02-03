#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int Get(int x){
    string s = to_string(x);
    reverse(s.begin(),s.end());
    int res = stoll(s);
    return res;
}

void solve(){
    int l,r;cin >> l >> r;
    int ans = Get(r);
    string L = to_string(l),R = to_string(r);

    int p = 1;
    for(int i = 0; i < R.size(); i++){
        int cur = p * 10;
        int tar = (r / cur) * cur - 1;
        if(tar >= l) ans = max(ans,Get(tar));

        if(i < 15) p *= 10;
        else break;
    }
    ans = max(ans,Get(l));
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
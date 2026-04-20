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
    string tar = "isallyouneed";
    int m = tar.size();
    string cur = s.substr(n - m);
    if(cur != tar) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for(int i = 0; i < n - m; i++) cout << s[i];
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
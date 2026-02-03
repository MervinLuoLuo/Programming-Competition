/*https://codeforces.com/contest/2182*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >>n;
    string s;cin >> s;
    bool flag1 = 0,flag2 = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '2'){
            string str = s.substr(i,4);
            if(str == "2025") flag2 = 0;
            if(str == "2026") flag1 = 1;
        }
    }

    bool ans = flag1 || flag2;
    if(ans) cout << 0 << endl;
    else cout << 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
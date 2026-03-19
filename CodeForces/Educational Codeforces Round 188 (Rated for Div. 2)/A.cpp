/*https://codeforces.com/contest/2204*/
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
    int i = 0;
    for(;i < n; i++){
        if(s[i] == 'L') break;
    }
    cout << i + 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
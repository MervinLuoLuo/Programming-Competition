/*https://atcoder.jp/contests/abc453*/
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
    int n;cin >> n;
    string s;cin >> s;
    int i = 0;
    while(s[i] == 'o') i++;
    for(; i < n; i++) cout << s[i];
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
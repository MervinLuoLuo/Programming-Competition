/*https://codeforces.com/problemset/problem/2049/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    bool flagp = 0,flags = 0;
    if(s[0] == 's') s[0] = '.';
    if(s[n - 1] == 'p') s[n - 1] = '.';
    for(char c : s){
        if(c == 'p') flagp = 1;
        if(c == 's') flags = 1;
    }

    if(flagp && flags) no;
    else yes;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
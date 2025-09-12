/*https://codeforces.com/problemset/problem/2127/B*/
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
    int n,x;cin >> n >> x;
    string s;cin >> s;
    if(x == 1 || x == n){cout << 1 << endl;return;}
    x--;
    int lf = -maxn,rf = maxn;
    for(int i = x- 1; i >= 0; i--){
        if(s[i] == '#') {lf = i;break;}
    }

    for(int i = x + 1; i < n; i++){
        if(s[i] == '#') {rf = i;break;}
    }

    if(lf == -maxn && rf == maxn){cout << 1 << endl;return;}

    cout << max(min(x + 1, n - rf + 1), min(lf + 2, n - x)) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
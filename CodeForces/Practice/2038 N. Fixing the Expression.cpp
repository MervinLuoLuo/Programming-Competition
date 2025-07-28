/*https://codeforces.com/problemset/problem/2038/N*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    string s;cin >> s;
    int a = s[0] - '0', b = s[2] - '0';
    if(a < b) cout << a << "<" << b;
    else if(a == b) cout << a << "=" << b;
    else cout << a << ">" << b;
    cout << endl;
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
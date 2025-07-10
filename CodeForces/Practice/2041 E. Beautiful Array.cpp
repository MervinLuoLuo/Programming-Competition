/*https://codeforces.com/problemset/problem/2041/E*/
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
    int a,b;cin >> a >> b;
    cout << 3 << endl;
    cout << b << " " << b << " " << 3 * a - 2 * b << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
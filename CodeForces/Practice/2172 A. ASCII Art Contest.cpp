/*https://codeforces.com/problemset/problem/2172/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    vector<int> a(3);
    for(int &x : a) cin >> x;
    sort(a.begin(),a.end());
    if(a[2] - a[0] >= 10) cout << "check again" << endl;
    else cout << "final " << a[1] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
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
    int a,b,c;cin >> a >> b >> c;
    cout << 100 << endl;
    for(int i = 1; i <= 50; i++) cout << a << " ";
    for(int i = 1; i <= 45; i++) cout << b << " ";
    for(int i  = 1; i <= 4; i++) cout << c << " ";
    cout << maxn << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
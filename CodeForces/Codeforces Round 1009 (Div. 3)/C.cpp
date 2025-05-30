/*https://codeforces.com/contest/2074/problem/C*/
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
    int x;cin >> x;
    if ((x & (x - 1)) == 0 or ((x + 1) & x) == 0) {
        cout << -1 << endl;
        return;
    }
    int a = __lg(x);
    std::cout << (1 << a) - 1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
/*https://codeforces.com/problemset/problem/2056/C*/
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
    int n;cin >> n;
    if(n == 6) cout << "1 1 2 3 1 2" << endl;
    else{
        for(int i = 1; i <= n - 2; i++) cout << i << " ";
        cout << "1 2" << endl;
    }
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

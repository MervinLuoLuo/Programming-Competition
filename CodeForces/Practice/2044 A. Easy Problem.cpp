/*https://codeforces.com/problemset/problem/2044/A*/
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
    int cnt = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 100; j++){
            if(n - i == j) cnt++;
        }
    }
    cout << cnt << endl;
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
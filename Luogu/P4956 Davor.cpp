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
    int x = 100;
    int k = 0;
    for( x = 100; x >= 0; x--){
        if((n / 52 - 7 * x) % 21 == 0){
            k = (n / 52 - 7 * x) / 21;
            if(k <= 0) continue;
            break;
        }
    }
    cout << x << endl << k << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
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
    int area = n * (n + 1) / 2;
    int ans = INF;
    for(int i = 1; i * i <= area; i++){
        if(area % i == 0){
            int b = area / i;
            if(b >= n) ans = min(ans,2 *(i + b));
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
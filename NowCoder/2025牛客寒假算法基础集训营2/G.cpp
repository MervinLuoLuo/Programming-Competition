#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;cin >> n >> m;
        int minx = INF;
        int ans, now = 1;
        for(int i = 1 ; i <= 30 ; i++){
            if(now >= INF / m) break;
            now *= m;
            if(abs(n - now) < minx){
                minx = abs(n - now);
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

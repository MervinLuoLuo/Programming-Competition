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
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> pos(n ,0);
    int ans = 0;
    for(int k = 0; k < 30; k++){
        int c00 = 0,c01 = 0, c10 = 0,c11 = 0;
        for(int i = 0; i < n; i++){
            int bit = (a[i] >> k) & 1;
            if(pos[i] == 0){
                if(bit == 0) c00++;
                else c01++;
            }
            else{
                if(bit == 0) c10++;
                else c11++;
            }
        }
        int pairs = c00 * c01 + c10 * c11;
        ans += pairs * (1LL << k);
        for(int i = 0; i < n; i++) pos[i] ^= (a[i] >> k) & 1;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
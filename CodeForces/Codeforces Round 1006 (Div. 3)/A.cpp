/*https://codeforces.com/contests/2072*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int n,k,p;cin >> n >> k >> p;
    if(k < 0) k = abs(k);
    if(n * p < k) {no;return;}
    int ans = k / p;
    if(k % p != 0) ans++;
    cout << ans << endl;
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
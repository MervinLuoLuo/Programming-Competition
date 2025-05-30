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
    int n; cin >> n;
    for(int i = 0; i < (1 << n); i++) {
       int cnt = 0;
       int num = i;
       while(num) {
          if(num & 1) cnt ++;
          num >>= 1;
       }
       if(cnt % 2 == 1) cout << 1;
       else cout << 0;
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
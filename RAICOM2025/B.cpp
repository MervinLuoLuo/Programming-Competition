#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int maxn = 1e8;
// const int INF = 1e18;

void solve(){
    int n,s;cin >> n >> s;
    int cnt = 0, sum = 0; 
    for(int i = 0; i < n; i++){
        int r,c;cin >> r >> c;
        if(r == 1) cnt++;
        sum += c;
    }
    if(cnt * 2 >= n) cout << 1 << " ";
    else cout << 0 << " ";
    if(sum >= s + 50) cout << 1;
    else cout << 0;
}

signed main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        if(t >= 1) cout << endl;
    }
    return 0;
}
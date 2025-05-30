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
    int n,x;cin >> n >> x;
    int cnt = __builtin_popcountll(x);

    if(x > 1){
        if(n <= cnt) cout << x << endl;
        else {
            if((n - cnt) & 1) cout << x + n - cnt + 1 << endl;
            else cout << x + n - cnt << endl;
        }
        return;
    }

    else if(x ==1){
        if(n & 1) cout << n << endl;
        else cout << n + 3 << endl;
        return;
    }

    else{
        if(n == 1) {cout << -1 << endl;return;}
        if(n & 1)cout << n + 3 <<endl;
        else cout << n << endl;
    }
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
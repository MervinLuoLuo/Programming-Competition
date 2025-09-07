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

int calc(int x){
    int res = 0;
    for(int i = 1; i * i <= x; i++){
        if(x % i == 0){
            int f1 =i,f2 = x / i;
            if(f1 % 2 == 0 && (x / f1) % 2 == 0) res = max(res,f1);
            if(f2 % 2 == 0 && (x / f2) % 2 == 0) res = max(res,f2);
        }
    }
    return res;
}

void solve(){
    int a,b;cin >> a >> b;
    if(b == 1) {cout << -1 << endl;return;}
    if(!(a & 1) && !(b & 1)) cout << a * b / 2 + 2 << endl;
    else if((a & 1) && (b & 1)) cout << a * b + 1 << endl;
    else if((a & 1) && !(b & 1)){
        int x = calc(b);
        if(x == 0) cout << -1 << endl;
        else cout << a * x + b / x << endl;
    }
    else if(!(a & 1) && (b & 1)) cout << -1 << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
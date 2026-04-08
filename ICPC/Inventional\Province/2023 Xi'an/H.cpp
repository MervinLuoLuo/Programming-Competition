#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1,0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int d = (a[2] - a[1] + n) % n;
    for(int i = 3; i <= n; i++){
        if(a[i] != (a[i - 1] + d) % n){
            cout << -1 << endl;
            return;
        }
    }

    if(d == 0){
        if(a[1] == 0) cout << 0 << endl;
        else cout << n + 1 << endl;
    }
    else{
        if(a[1] == 0) cout << d << endl;
        else cout << d + 1 << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
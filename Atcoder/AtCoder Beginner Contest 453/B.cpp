#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,x;cin >> n >> x;
    vector<int> a(n + 1, 0);
    for(int i = 0; i <= n; i++) cin >> a[i];
    cout << 0 << " " << a[0] << endl;
    int cur = a[0];
    for(int i = 1;  i <= n; i++){
        if(abs(a[i] - cur) >= x){
            cout << i << " " << a[i] << endl;
            cur = a[i];
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
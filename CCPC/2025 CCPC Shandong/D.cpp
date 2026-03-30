#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,q;cin >> n >> q;
    vector<int> d(n + 1,0);
    int sum = 0;
    for(int i = 1; i <= q; i++){
        int a,b;cin >> a >> b;
        sum += a / n;
        int res = a % n;
        if(res == 0) continue;
        int l = b,r = (b + res - 1) % n;
        if(r >= l){
            d[l]++;
            d[r + 1]--;
        }
        else{
            d[l]++;
            d[n]--;
            d[0]++;
            d[r + 1]--;
        }
    }

    cout << d[0] + sum << " ";
    int cur = d[0];
    for(int i = 1; i < n ;i++){
        cur += d[i];
        cout << cur + sum << " ";
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
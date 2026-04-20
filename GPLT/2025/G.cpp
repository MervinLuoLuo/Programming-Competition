#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;

int qpow(int a,int e){
    int res = 1;
    while(e){
        if(e & 1) res *= a;
        a *= a;
        e >>= 1;
    }
    return res;
}

void solve(){
    int n;cin >> n;
    for(int i = 31; i >= 1; i--){
        int ans = 0;
        bool flag = 1;
        for(int j = 1; j <= n; j++){
            ans += qpow(j,i);
            if(ans > n){
                flag = 0;
                break;
            }
            if(ans == n) break;
        }
        ans = 0;
        if(flag){
            for(int j = 1; j <= n; j++){
                ans += qpow(j,i);
                if(ans != n) cout << j <<"^" << i << "+";
                else {cout << j << "^" << i;return;}
            }
        }
    }
    cout << "Impossible for " << n << ".";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
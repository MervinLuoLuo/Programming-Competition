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

long long calc(long long a) {
    long long ans = 0;
    for(long long i = 1; i * i <= a; i++) {
        if(a % i == 0) {
            long long f1 = i, f2 = a / i;

            // f1 是否满足条件
            if(f1 % 2 == 0 && (a / f1) % 2 == 0) ans = max(ans, f1);
            // f2 是否满足条件
            if(f2 % 2 == 0 && (a / f2) % 2 == 0) ans = max(ans, f2);
        }
    }
    return ans;
}


void solve(){
    cout << calc(6);
}   
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
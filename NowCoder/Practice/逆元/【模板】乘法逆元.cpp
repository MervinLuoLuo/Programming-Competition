/*https://ac.nowcoder.com/acm/problem/229004*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,p;cin >> n >> p;
    vector<int> inv(n + 1,1);
    for(int i = 2; i <= n; i++) inv[i] = (p - p / i) * inv[p % i] % p;

    for(int i = 1; i <= n; i++) cout << inv[i] << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 2e14;
constexpr int MOD = 998244353;
using i128 = __int128_t;
int P[63];

int qpow(int a,int e){
    int res = 1;
    a %= MOD;
    while(e){
        if(e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<int> num;
    for(int i = 0; i < n; i++) num.push_back(b[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());

    auto getid = [&](int x) -> int{
        int res = lower_bound(num.begin(),num.end(), x) - num.begin();
        return res;
    };

    vector<int> c(num.size());
    for(int i = 0; i < n; i++) c[getid(b[i])] += a[i];

    i128 res = 0;
    int ans = 0;
    for(int i = num.size() - 1; i >= 0; i--){
        if(res >= c[i]){
            res -= c[i];
            if(res == 0) continue;

            if(i == 0) break;
            if(res >= INF) break;
            if(num[i] - num[i - 1] > 62) break;
            if((i128)res * P[num[i] - num[i - 1]] >= 2 * INF) break;
            res *= P[num[i] - num[i - 1]];
        }
        else{
            c[i] -= res;
            res = 0;
            int sum = ((c[i] + m - 1) / m) % MOD;
            ans = (ans + (sum * qpow(2,num[i]) % MOD) % MOD) % MOD;
            if(c[i] % m != 0) res = m - (c[i] % m);
            if(res == 0) continue;

            if(res >= INF) break;
            if(i == 0) break;
            if(num[i] - num[i -1] > 62) break;
            if((i128)res * P[num[i] - num[i  - 1]] >= 2 * INF) break;
            res *= P[num[i] - num[i - 1]]; 
        }
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    P[0] = 1;
    for(int i = 1; i <= 62; i++) P[i] = P[i - 1] * 2;

    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}
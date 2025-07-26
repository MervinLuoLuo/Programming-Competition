#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int mod = 998244353;

void solve(){
    string s;cin >> s;
    int n = s.size();
    vector<int> sum(n + 5), lp(n + 5), rp(n + 5),f(n + 5);
                //数组化    左括号计数 右括号计数 2幂次
    f[0] = 1;

    //数组化处理
    for(int i = 0;i < n; i++){
        sum[i + 1] = sum[i] + (s[i] == '(' ? 1 : -1);
    }
    
    for(int i = 1; i <= n; i++){
        lp[i] = lp[i - 1] + (s[i - 1] == '(');
    }

    for(int i = n; i >= 1; i--){
        rp[i] = rp[i + 1] + (s[i - 1] == ')');
    }

    for(int i = 1; i <= n; i++) f[i] = f[i - 1] * 2 % mod;

    int r = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        r = max(r,i);
        while(r <= n && sum[r] > 1) r++;
        if(s[i - 1] == '(') ans = (ans + f[rp[r + 1]] * f[lp[i - 1]]) % mod;
    }
    ans = (ans + f[n / 2]) % mod;
    for(int i = 1; i <= n; i++) ans = ans * ((mod + 1) / 2) % mod;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
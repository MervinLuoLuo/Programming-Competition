#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
int n;
void solve(){
    string s;cin >> s;
    s = " " + s;
    vector<int> f(n + 1, 0);
    for(int i = 1; i <= n; i++){
        f[i] = f[i - 1];
        if(i >= 4 && s[i] == '0' && s[i - 1] == '2' && s[i - 2] == '0' && s[i - 3] == '2') f[i] = max(f[i],f[i - 4] + 1);
    }
    cout << f[n] << endl;
}   

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n)
    solve();
    return 0;
}
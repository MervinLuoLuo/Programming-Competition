#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
const int mod = 1e9 + 7;
int n;
string s;
int ans = 0;
void dfs(int x){
    int cnt01 = 0,cnt10 = 0;
    if(x == n + 1){
        for(int i = 1; i <= n; i++){
            s[i] ^= 1;
            cnt01 = 0;cnt10 = 1;
            for(int j = 2; j <= n; j++){
                if(s[j - 1] == '0' and s[j] == '1')cnt01++;
                else if(s[j - 1] == '1' and s[j] == '0') cnt10++;
            }
            if(cnt01 == cnt10) ans++;
            s[i] ^= 1;
        }
    }
    if(s[x] == '?'){
        s[x] = '0';dfs(x + 1);
        s[x] = '1';dfs(x + 1);
        s[x] = '?';
    }
    else dfs(x + 1);
}
void solve(){
    cin >> n;
    cin >> s;
    s += ' ';
    ans = 0;
    dfs(1);
    cout << ans % mod << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}

/*https://codeforces.com/contest/2173*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<int,int>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            int add = 1;
            for(int j = i; j >= max(0LL,i - k); j--){
                if(s[j] == '1'){add = 0;break;}
            }
            ans += add;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
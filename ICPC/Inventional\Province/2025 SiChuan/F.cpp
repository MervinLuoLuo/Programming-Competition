#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = " " + s;
    vector<int> cnt0(n + 1, 0),cnt1(n + 1, 0);
    int sum = 0,pre1 = 0,suf0 = 0;
    for(int i = 1 ; i<= n; i++){
        if(s[i] != '1') sum += pre1;
        else pre1++;
    }
    pre1 = 0;
    for(int i = 1; i <= n; i++){
        cnt1[i] = pre1;
        if(s[i] != '0') pre1++;
    }

    for(int i = n; i >= 1; i--){
        cnt0[i] = suf0;
        if(s[i] != '1') suf0++;
    }

    int ans = sum;
    for(int i = 1; i <= n; i++){
        if(s[i] == '?'){
            sum -= cnt1[i];sum += cnt0[i];
            ans = max(ans,sum);
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
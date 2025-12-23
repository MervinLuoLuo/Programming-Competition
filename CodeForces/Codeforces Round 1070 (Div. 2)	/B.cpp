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
    s = s + s;
    int cnt = 0,max0 = 0;
    for(char c : s){
        if(c == '0') cnt++;
        else {
            max0 = max(max0,cnt);
            cnt = 0;
        }
    }

    cout << max0 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
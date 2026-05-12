#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<tuple<int,int,int>> cnt(n);

    int cnt1 = 0,cnt2 = 0,cnt0 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt1++;
        else if(s[i] == '2') cnt2++;
        else cnt0++;
        
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
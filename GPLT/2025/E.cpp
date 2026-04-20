#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define VII vector<vector<int>>
#define PII pair<int,int>
using namespace std;
using i128 = __int128;
constexpr int MAXN = 1e9;
constexpr int INF = 1e18;

void solve(){
    string s;cin >> s;
    vector<int> a(26,0);
    for(int &x : a) cin >> x;
    map<char,int> mp;
    int ans = 0;
    for(char c : s){
        mp[c]++;
        int score = a[c - 'a'];
        ans += score;
    }

    for(char i = 'a'; i <= 'y'; i++){
        cout << mp[i] << " ";
    }
    cout << mp['z'] << endl;
    cout << ans;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
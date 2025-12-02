#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    map<int,int> freq;
    for(int i = 1 ; i <= 2 * n; i++){
        int x;cin >> x;
        freq[x]++;
    }

    int x = 0,y = 0,z = 0;
    for(auto &[u,v] : freq){
        if(v & 1) x++;
        else if(v % 4) y++;
        else z++;
    }

    int ans = x + 2 * y + 2 * z;
    if((z & 1) && x == 0)ans -=2;
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
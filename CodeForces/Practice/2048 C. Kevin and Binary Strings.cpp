/*https://codeforces.com/problemset/problem/2048/C*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();
    cout << "1 " << n << " ";
    int pos = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != '1'){
            pos = i;
            break;
        }
    }

    if(pos == -1) {cout << "1 " << 1 << endl;return;}

    for(int i = 0; i < n; i++){
        s[i] -= '0';
    }

    string maxs = "";
    int ans = 0;
    for(int i = 0; i < pos; i++){
        string tmp = s;
        for(int j  =0; j + pos < n; j++){
            tmp[pos + j] ^= s[i + j]; 
        }
        if(tmp > maxs){ans = i;maxs = tmp;}
    }
    cout << ans + 1 << " " << ans + n- pos << endl;
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
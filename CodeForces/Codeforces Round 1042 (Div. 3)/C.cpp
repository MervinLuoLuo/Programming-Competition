#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,k;cin >> n >> k;
    vector<int> S(n),T(n);
    for(int i = 0; i < n; i++){
        cin >> S[i];
        S[i] = min(S[i] % k,(k - S[i] % k) % k);
    }
    for(int i = 0; i < n; i++){
        cin >> T[i];
        T[i] = min(T[i] % k, (k - T[i] % k) % k);
    }
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    for(int i = 0; i < n; i++){
        if(S[i] != T[i]){no;return;}
    }
    yes;

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
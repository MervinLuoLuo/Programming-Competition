/*https://codeforces.com/problemset/problem/1996/C*/
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
    int n,q;cin >> n >> q;
    vector<vector<int>> prea(n + 1,vector<int>(26,0));
    vector<vector<int>> preb(n + 1,vector<int>(26,0));
    for(int i = 1; i <= n; i++){
        char c;cin >> c;
        prea[i][c - 'a']++;
        for(int j = 0;j < 26;j++){
            prea[i][j] += prea[i - 1][j];
        }
    }

    for(int i = 1; i <= n; i++){
        char c;cin >> c;
        preb[i][c - 'a']++;
        for(int j = 0; j < 26; j++){
            preb[i][j] += preb[i - 1][j];
        }
    }

    while(q--){
        int l,r;cin >> l >> r;
        int dif  = 0;

        for(int i = 0; i < 26; i++){
            int c1 = prea[r][i] - prea[l - 1][i];
            int c2 = preb[r][i] - preb[l - 1][i];

            dif += abs(c1 - c2);
        }
        cout << dif / 2 <<endl;
    }
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
/*https://codeforces.com/problemset/problem/1983/B*/
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
    int n,m;cin >> n >> m;
    vector<string> A(n,string(m,'0')),B(n,string(m,'0'));
    for(int i = 0; i < n;i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++){
        int suma = 0,sumb = 0;
        for(int j = 0; j < m; j++){
            int ax = A[i][j] - '0';
            int bx = B[i][j] - '0';
            suma += ax, sumb += bx;
        }
        suma %= 3;sumb %= 3;
        if(suma != sumb){no;return;}
    }
    for(int j = 0; j < m; j++){
        int suma = 0,sumb = 0;
        for(int i = 0; i < n; i++){
            int ax = A[i][j] - '0';
            int bx = B[i][j] - '0';
            suma += ax, sumb += bx;
        }
        suma %= 3;sumb %= 3;
        if(suma != sumb){no;return;}
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
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e3;
int n,m;

void solve(){
    vector<bitset<MAXN + 5>> b(n + 1);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int x;cin >> x;
            b[i][j] = (x & 1);
        }
    }
    if(n == 1) cout << "Yes" << endl;
    else if(n == 2){
        bitset<MAXN + 5> k = b[1] ^ b[2];
        if(k.count() % 2 == 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin >> n >> m)
    solve();
    return 0;
}
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
    int p = n % 10;
    if(p == 0) cout << 1 << endl;
    else if(p == 1 || p == 3 || p == 7 || p == 9) cout << 10 << endl;
    else if(p == 2 || p == 4 || p == 6 || p == 8) cout << 5 << endl;
    else if(p == 5) cout << 2 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
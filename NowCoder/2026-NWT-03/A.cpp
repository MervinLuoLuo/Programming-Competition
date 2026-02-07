#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int x;cin >> x;
    for(int i = 1; i * i <= x; i++){
        if(i * (i + 1) == x) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO";
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
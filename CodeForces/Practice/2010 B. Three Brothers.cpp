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
    vector<bool> a(3,0);
    int x,y;cin >> x >> y;
    a[x - 1] = 1, a[y - 1] = 1;
    for(int i = 0 ; i < 3; i++){
        if(a[i] == 0) {cout << i + 1 << endl;return;}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
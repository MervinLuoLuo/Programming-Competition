#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int a,b,r;cin >> a >> b >> r;
    int d = 2 * r;
    if(a >= d && b >= d) cout << "Alice" << endl;
    else cout << "Bob" << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
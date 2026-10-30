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
    if(n == 1){
        cout << 3 << "\nyyc" << endl;
        return;
    }
    int k = sqrt(n) + 1;
    if((k - 1) * k > n) k--;

    int x = k - 2;
    int m = n - (k * k - k);
    string s = "yy";
    for(int i = 1; i <= m; i++) s += 'c';
    for(int i = 1; i <= x; i++) s += 'y';
    s += "cc";
    cout << s.size() << endl << s << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
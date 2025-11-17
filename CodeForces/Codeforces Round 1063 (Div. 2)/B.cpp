#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1, 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    string x;cin >> x;
    x = " " + x;
    //边界不行
    if(x[1] == '1' || x[n] == '1'){
        cout << -1 << endl;
        return;
    }

    //最大值不行
    for(int i = 1; i <= n; i++){
        if(x[i] == '1'){
            if(a[i] == 1 || a[i] == n) {cout << -1 << endl;return;} 
        }
    }

    int posmin = min_element(a.begin() + 1,a.end()) - a.begin();
    int posmax = max_element(a.begin() + 1, a.end()) - a.begin();

    cout << 5 << endl;
    cout << 1 << " " << posmin << endl;
    cout << 1 << " " << posmax << endl;
    cout << posmin << " " << n << endl;
    cout << posmax << " " << n << endl;
    cout << min(posmin,posmax) << " " << max(posmin, posmax) << endl;

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
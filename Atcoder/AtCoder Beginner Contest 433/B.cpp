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
    vector<int> a(n + 1, 0),pre(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = max(pre[i - 1] ,a[i]);
    }

    for(int i = 1; i <= n; i++){
        if(pre[i] > a[i]){
            for(int j = i; j >= 1; j--){
                if(a[j] > a[i]) {cout << j << endl;break;}
            }
        }
        else cout << -1  << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
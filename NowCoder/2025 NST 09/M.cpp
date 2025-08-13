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

int dsum(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
void solve(){
    int n;cin >> n;
    int ans = -1;
    for(int k = 1; k <= 12; k++){
        int a = 1;
        for(int i = 0; i < k;i++) a = a * 10 + 9;
        a /= 10;
        if(n * dsum(a) == dsum(n * a)){ans = a;break;}
    }
    cout << ans << endl;
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
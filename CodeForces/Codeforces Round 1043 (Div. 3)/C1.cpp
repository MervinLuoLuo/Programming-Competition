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

vector<int> p3(21);
int calc(int x){
    if(x == 0)  return 3;
    return p3[x + 1] + x * p3[x - 1];
}

void solve(){
    int n;cin >> n;
    int k = 0;
    int ans = 0;
    while(n > 0){
        int d = n % 3;
        if(d) ans += d * calc(k);
        n /= 3;
        k++;
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    p3[0] = 1;
    for (int i = 1; i <= 20; ++i) p3[i] = p3[i - 1] * 3;
    
    while(t--){
        solve();
    }
    return 0;
}
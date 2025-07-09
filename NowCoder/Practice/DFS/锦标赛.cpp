/*https://ac.nowcoder.com/acm/problem/13223*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    int a;cin >> a;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        int x;cin >> x;
        if(x <= a) cnt++;
    }
    cout << (int)log2(cnt) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int cnt = 0;
        while(n >= 30){
            n = n - 30;
            cnt++;
        }
        if(n) cnt++;
        cout << 4*cnt << endl;
    }
    return 0;
}